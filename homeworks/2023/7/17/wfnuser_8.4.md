## 8.2.5 Context Switches
操作系统通过 context switch 的异常控制流来实现多任务
每个进程都维护了一个上下文，提供恢复被抢占进程的信息；包括 general-purpose registers \ floating-point registers \ the program counter \ user's stack \ status registers \ kernel's stack \ kernel structures (page table \ process table \ file table)
内核会定时决定暂停当前的进程并恢复之前被抢占的进程，这个过程称为调度；切换进程的过程中我们会进行上下文切换，包括三个步骤： 保存当前进程上下文、恢复被抢占进程上下文、将控制权交给新的进程
# 8.3 System Call Error Handling
``` c
	  
	  pid_t Fork(void)
	  {
	    pid_t pid;
	  
	    if ((pid = fork()) < 0)
	      unix_error("Fork error");
	    return pid;
	  }
```
上面这样的 error handling wrapper 是一种常见的做法
# 8.4 Process Control
本节介绍一些常见的进程控制系统调用
## 8.4.1 Obtaining Process IDs
getpid 获取当前进程pid
getppid 获取当前进程父进程pid