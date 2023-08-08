- ## 8.5.7 Explicitly Waiting for Signals  
	- 有时候主程序需要明确的等待信号 - 比如 shell 执行前台任务时，只有该任务结束并被 reaped 之后，shell 才会接受下一条指令  
	- 在书中的例子里，基本的想法是 fork 进程之后进入一个死循环，重复检查全局变量 pid 的值，直到 handler 修改之退出  
		- 但这样的 spin loop 效率很低，浪费了 CPU  
	- 下面两个修正也都有问题：  
		-  
		  ``` cpp
		  		  // 竞争条件在于 如果子进程在进入 while 之后， pause 之前退出，则父进程将永远等待下去
		  		  while (!pid)  /* Race! */
		  		  	pause();
		  		  
		  		  while (!pid) /* Too slow! */
		  		  	sleep(1);
		  ```
	- 正确的做法是采用  sigsuspend  
		- 其本质上等价于原子化的下述操作  
		-  
		  ``` cpp
		  		  1 sigprocmask(SIG_BLOCK, &mask, &prev);
		  		  2 pause();
		  		  3 sigprocmask(SIG_SETMASK, &prev, NULL);
		  ```
		- 这样，在循环开始之前 信号一定是被 block 的；直到sigsuspend，会暂时把信号 unblock，并进入等待；如果不是原子化的操作，则可能 unblock 之后 pause 之前收到信号；而原子化的操作则不会有这个问题  