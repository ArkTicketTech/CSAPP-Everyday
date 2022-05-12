# Ch6 The Memory Hierarchy

## 6.5 Writing Cache-Friendly Code

确保代码 cache friendly ：

1. Make the common case go fast.

    程序大部分时间都在执行核心的几个函数，应该关注这些核心函数的内部循环，并进行优化。

2. Minimize the number of cache misses in each inner loop.

    缩小这些核心函数的 cache miss，使其更加符合程序代码的局部性（例如，局部变量应该存在寄存器中，多维数组的访问符合其在内存中的存储顺序）。

