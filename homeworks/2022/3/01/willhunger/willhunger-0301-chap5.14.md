# Ch5 Optimizing Program Performance

## 5.14 Identifying and Eliminating Performance Bottlenecks

使用 program profiling（程序剖析）程序来收集程序性能数据，unix 下有一个 gprof，可以产生每个函数花费的 CPU 时间，以及计算函数的调用次数，根据 gprof 的性能数据来调整程序及性能。

使用 gprof 需要注意：计时可能不准确，存在内联函数时无法准确统计函数调用此函数，无法展示库函数性能信息。

> 工程实践中，更多使用 perf 来统计分析程序性能，perf 可以统计指令级别的程序性能。



