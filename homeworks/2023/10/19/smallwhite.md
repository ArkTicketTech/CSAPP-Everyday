使用应用级并发的应用程序称为并发程序 (concurrent program) 。现代操作系统提供 了三种基本的构造并发程序的方法:

·进程。用这种方法，每个逻辑控制流都是一个进程，由内核来调度和维护。因为进 程有独立的虚拟地址空间，想要和其他流通信，控制流必须使用某种显式的进程间 通信 (interprocess communication, IPC)机制。

• 1/0 多路复用。在这种形式的并发编程中，应用程序在一个进程的上下文中显式地 调度它们自己的逻辑流。逻辑流被模型化为状态机，数据到达文件描述符后，主程 序显式地从一个状态转换到另一个状态。因为程序是一个单独的进程，所以所有的 流都共享同一个地址空间。

线程。线程是运行在一个单一进程上下文中的逻辑流，由内核进行调度。你可以把 线程看成是其他两种方式的混合体，像进程流一样由内核进行调度，而像 I/0 多路 复用流一样共享同一个虚拟地址空间。