### 9.21

___

1. 在运行时，操作系统通过一组叫做系统调用的接口向应用程序提供服务。应用程序通过调用系统调用来请求操作系统执行 I/O 操作、获取系统时间、创建新进程等任务。系统调用是操作系统提供的一种安全而受控制的机制，用于限制应用程序对系统资源的访问，并确保多个应用程序之间的隔离。
2. 操作系统基本抽象实现了这两个目标：进程、虚拟内存和文件。正如该图所示，文件是I/O设备的抽象，虚拟内存是主存和磁盘I/O设备的抽象，进程是处理器、主存和I/O设备的抽象。
