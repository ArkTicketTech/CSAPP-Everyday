- # 8.5 Signals  
	- 本章介绍 higher-level 异常控制流 - signal - 通过信号，我们可以让进程和内核打断其他进程  
	- ## 8.5.1 Signal Terminology  
		- sending a signal - two reasons 1) system event 发生，比如除零错误 2) kill function requested  
		- receiving a signal - 通过用户级别的函数 signal handler 来忽视、终止、捕获信号  
		- pending signal 只能有一条，当进程在等待 type k 的 signal 时，其他信号会被丢弃  
	- ## 8.5.2 Sending Signals  
		- process group  
			- 每个进程属于唯一一个 process group ; process group ID 唯一标识  
			- 默认情况下，子进程和父进程同属一个 process group ; 通过 segpgid 可以设置 group组  
		- sending signals with the /bin/kill program  
		- sending signals from the keyboard  
			- 同一时间 我们可能在运行最多一个 foreground job 和 0以上个 background job  
			- ctrl-c send SIGINT  
			- ctrl-z send SIGTSTP  
		- sending signals with kill function  
			-  
			  ``` c
			  			  int kill(pid_t pid, int sig);
			  			  return 0 if OK, -1 on error
			  ```
		- sending signals with alarm function  
			-  
			  ``` c
			  			  #include <unistd.h>
			  			  unsigned int alarm(unsigned int secs);
			  			  	Returns: remaining seconds of previous alarm, or 0 if no previous alarm
			  ```
			- send SIGALRM ; 调用 alarm 的时候会取消任何 pending 的 alarm  
		-  