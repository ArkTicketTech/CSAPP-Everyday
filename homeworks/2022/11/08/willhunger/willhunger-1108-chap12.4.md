# Ch12 Concurrent Programming

## 12.4 Shared Variables in Threaded Programs

### 12.4.1 Threads Memory Model

每个线程独有的线程上下文，包括了：

* 线程 ID
* 线程栈
* 栈指针
* 程序计数器
* 条件码
* 通用目的寄存器

线程一起共享进程上下文的剩余部分：

* 用户虚拟地址空间：由代码、读/写数据、堆以及所有的共享库代码和数据区组成的。

* 打开文件的集合