## 8.1.1 Exception Handling
应该厘清硬件和软件在异常处理中的分界线

每个可能的异常都会标识一个唯一的 exception number ; 有些由程序设计者定义，有些由操作系统内核定义；前者包括除零错误、page faults、 memory access violation、break points 等等；后者包括系统调用和外部IO设备的信号
系统启动时，会分配并出示话一个 exceptional table 如图8.2所示
在运行时，处理器会检测是否有事件产生，有的话则根据 exception number 来跳转到对应的异常处理逻辑 如图8.3所示
exception 和 procedure call 很像，但是有一些显著的区别：
procedure call 总是返回栈上的地址，也就是再 branching 之前的地址；但是 exception 可能返回下一条指令
处理器也会推一些额外的状态到栈上，比如 EFLAGS
控制权交回到kernel时，所有的项都会被推到 kernel 的栈，而不是用户态的栈
exception handler 是在内核态运行的
当硬件触发一场后，剩下的工作都是由软件完成的，由 exception handler 完成。异常处理完成后，通过 "return from interrupt" 指令返回用户态的被打断的程序。