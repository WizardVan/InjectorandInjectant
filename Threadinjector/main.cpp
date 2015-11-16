
#pragma check_stack(off)
#include <Windows.h>
#include <conio.h>
#include <iostream>

__declspec(naked) void lala()
{
	MessageBox(0, 0, 0, 0);
}


static void after_lala()
{
}

int main()
{
	DWORD dwPid = GetCurrentProcessId(); //just for testing

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, dwPid);

	DWORD sizeOfFunc = (PBYTE)&after_lala - (PBYTE)&lala;

	LPVOID pThread = VirtualAllocEx(hProcess, 0, sizeOfFunc, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

	if (pThread == NULL)
		printf("VirtualAllocEx failed! Error: %d\n", GetLastError());

	WriteProcessMemory(hProcess, pThread, &lala, sizeOfFunc, 0);

	//getchar();

	CreateRemoteThread(hProcess, NULL, NULL, (LPTHREAD_START_ROUTINE)pThread, NULL, NULL, NULL);



	CloseHandle(hProcess);

	getchar();
	return 0;
}