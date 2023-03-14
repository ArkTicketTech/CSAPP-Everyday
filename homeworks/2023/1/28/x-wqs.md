异常是允许操作系统内核提供进程process概念的基本构造块，进程是计算机科学中最深刻、最成功的概念之一。
进程：一个执行中程序的实例。系统中每个程序都运行在某个进程的上下文中。
上下文是由程序正确运行所需的状态组成，这个状态包括存放在内存中的程序的代码和数据，它的栈、通用目的寄存器的内容、程序计数器、环境变量以及打开文件描述符的集合。每次用户通过向shell输入一个可执行目标文件的名字，运行程序时，shell就会创建一个新的进程，在新进程的上下文中运行可执行目标文件。
一个进程执行它的控制流的一部分的每一个时间段叫时间片，多任务也叫时间分片。
