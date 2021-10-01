# A tour of computer system

## 1.5 caches matter
系统会花很多的时间把数据在不同的地方进行移动。
比如 `hello` 程序 硬盘 -> 主存 -> 处理器

越大的存储读写速度越慢
一个减少 processor-memory gap 影响的方式 就是 提供缓存； 用于临时存储处理器可能需要用到的信息。
L1 和 L2 缓存 通过 SRAM 实现。

## 1.6 Storage Devices From a Hierarchy
通过多级缓存加速数据读写。

## 1.7 The Operating System Manages the Hardware
应用层代码本身不会直接和外设、硬盘、内存打交道，而是依赖于操作系统进行系统调用。
操作系统的两个目标： 1. 保护硬件不被软件误用 2. 给应用提供统一简单的硬件操作接口

### 进程 和 线程
运行程序时，操作系统通过进程提供了一个抽象，使得用户觉得只有自己的代码正在运行。
线程共享进程上下文、全局数据和代码（段？）。

### 虚拟内存
通过提供虚拟地址空间，提供了抽象，使得进程觉得自己独占了整个主存。

### 文件
是对IO的统一抽象。

### 1.8 System Communicate with Other SYstems Using Networks
通过网络进行通信。