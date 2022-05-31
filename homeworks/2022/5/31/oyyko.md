进程组：

每一个进程都只属于一个进程组。进程组由一个正整数ID标识。

`getpgrp`返回当前进程的进程组ID

`setpgid`设置进程的进程组。

kill可以发送信号给进程使得其终止。

Ctrl+C导致内核发送一个SIGINT信号到前台进程组中的每一个进程。

Ctrl+Z发送SIGTSTP信号使得其挂起

alarm函数安排内核在secs秒之后发送一个SIGALRM信号到调用进程。