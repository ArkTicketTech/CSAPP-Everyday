# Ch8 Exceptional Control Flow

## 8.5 Signals

### 8.5.6 Synchronizing Flows to Avoid Nasty Concurrency Bugs

并发流程序交错的数量与指令的数量呈指数关系。

可行的解决方法是以某种方式同步并发流，从而得到最大的可行的交错的集合，每个可行的交错都能得到正确的结果。

### 8.5.7 Explicitly Waiting for Signals

`sigsuspend` 函数暂时用 mask 替换当前的阻塞集合，然后挂起该进程，直至收到一个信号。其行为有如下两种情况：

* 运行一个处理程序，从 `sigsuspend` 处理程序返回，恢复调用原阻塞集合。
* 终止该进程。