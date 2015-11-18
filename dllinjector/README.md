dllinjector is a dll injector.It is different with thread injector.It also use createRemoteThread as well,but the thread only call LoadLibrary to load a DLL and the thread will disappear.It is easier than thread injection because you don't need to consider how to store the value in remote process.

dllinjector 是一个dll 注入器，虽然与线程注入器一样它需要使用createRemoteThread，但是当LoadLibrary成功载入DLL后就可以不需要考虑地址转换的问题。
