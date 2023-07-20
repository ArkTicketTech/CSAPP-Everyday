8.4.2 creating and terminating processes

process state
running - 包括运行和挂起的状态
stopped - 挂起并且不会被 schedule ； 收到 IGSTOP SIGTSTP SIGTTIN SITTOU 信号会进入该状态，直到收到 SIGCONT 再恢复执行
terminated - 永久的stop - 收到需要执行 terminate 的信号； return 主进程； call exit



