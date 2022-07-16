# Ch8 Exceptional Control Flow

## 8.4 Process Control

### 8.4.2 Creating and Terminating Processes

进程的三种状态：

* 运行：进程在 CPU 上执行，或者等待内核调度；
* 停止：进程的执行被挂起，且不会被调度。进程收到`SIGSTOP`、`SIGTSTP`、`SIGINT`、`SIGTTOU` 时，进程停止，收到 `SIGCONT`信号时再次开始运行。
* 终止：进程终止的三种原因：
    1. 收到终止进程的信号
    2. 从主程序返回
    3. 调用 exit 函数

进程使用 fork 系统调用创建子进程，子进程得到父进程用户级虚拟地址空间的一份副本，包括代码、数据段、堆、共享库及用户栈，还将获得父进程中打开文件描述符相同的副本。