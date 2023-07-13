## 8.2.2 Concurrent FLows
logical flow 有多种不同的形式 - exception handler \ processes \ signal handlers \ threads \ java processed
并发 - 多个进程执行的过程有交错 - flows X and Y are concurrent with respect to each other if and only if X begins after Y begins and before Y finishes, or Y begins after X begins and before X finishes.
并行是并发中的一种特定类型 - 并行的进程“同时”进行并且在不同的处理器上执行任务