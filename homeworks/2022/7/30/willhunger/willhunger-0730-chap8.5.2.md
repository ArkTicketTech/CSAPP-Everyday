# Ch8 Exceptional Control Flow

## 8.5 Signals

### 8.5.2 Sending Signals

1. 进程组。每个进程都只属于一个进程组，进程组由一个正整数进程组来标识。

    `getpgrp` 系统调用返回当前进程组 ID，`setpgid` 系统调用改变进程的进程组。

2. `/bin/kill` 发送信号。

3. 键盘快捷键可向前台进程组发送信号。

4. 程序中的 `kill` 函数系统调用发送信号。

    * 如果 pid 大于 0，kill 函数发送信号给进程 pid；
    * 如果 pid 等于 0，kill 函数发送信号给调用进程所在进程组中的每个进程；
    * 如果 pid 小于 0，kill 发送信号给（进程组 | pid | pid 绝对值）中的每个进程

5. alarm 函数发送 SIGALRM 信号。

