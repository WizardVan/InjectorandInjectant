ThreadInjector is ah.. an injector XD.It uses CreateRemoteThread to run a piece of code which has been write into target process memory.The code self is kinda complicated because you have to consider it will run in different address space.If injection is successful,a message box will appear.

ThreadInjector是一个线程注入器，用来将一段程序注入进程并且创建一个线程去执行它，它有很多的功能，当然，也有很多限制。其中最大的限制就是无法正确的使用各种变量和局部函数。
