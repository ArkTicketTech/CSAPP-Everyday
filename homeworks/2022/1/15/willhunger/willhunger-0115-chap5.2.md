# Ch5 Optimizing Program Performance

## 5.2 Expressing Program Performance

用 CPE (Cycles Per Element，每个元素的时钟周期数量) 来衡量程序的性能，主要用来衡量循环执行的性能。

处理器的时钟频率通常用千兆赫兹（GHz）来表示，十亿周期每秒。

书上对比了一个前缀和的计算的优化前和使用循环展开优化后的例子，程序优化的中心是为了减少 CPE。

## 5.3 Program Example

本节例举了一个整形和浮点型进行加法和乘法的例子，对比了为优化和开启 O1 优化的 CPE。

很多优化变换带来的性能提高很小，仅仅有一部分才会有显著提升。探索最好的方法需要多实验，多尝试不同的方法，检查汇编代码来确定底层的性能瓶颈。

