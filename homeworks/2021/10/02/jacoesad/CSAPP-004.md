> ***2021.10.02\***

------

## 1.8 Systems Communicate with Other Systems Using Networks

网络可以看作一个I/O设备。当系统从主存复制淄川字节到网络适配器时，数据通过网络流到另一台机器。系统也可以读取其他机器发过来的数据到自己的主存。

## 1.9 Important Themes

### 1.9.1 Amdahl’s Law

阿姆达尔定律：当我们加速系统的某一部分，其在整个系统上的效果取决于该部分的重要性以及其提升了多少。

假设某系统，其中：

- $T_{old}$ —— 某系统执行应用的时间
- $\alpha$ —— 某部分系统执行时间与总时间$T_{old}$的比例
- $k$ —— 该部分性能提升的比例

则新的总执行时间$T_{new}$为：

$$T_{new}=(1-\alpha)T_{old}+\alpha T_{old}/k=T_{old}[(1-\alpha)+\alpha/k]$$

计算加速比$S$：

$$S=\frac{1}{(1-\alpha)+\alpha/k}$$

阿姆达尔定律的主要观点为，想要显著提升整个系统，必须提升全系统中大多数部分。

### 1.9.2 Concurrency and Parallelism

并发（concurrency）一般指一个系统同时具有多个活动。

并行（parallelism）是指使用并发让系统运行更快。

**Thread-Level Concurrency**

处理器分类：

- 单处理器

- 多处理器

  - 多核处理器——将多个CPU集成到一个芯片上

    每个核都有自己的L1和L2。而L1分成两部分，分别处理数据和指令。

  - 超线程处理器——允许CPU执行多个控制流

**Instruction-Level Parallelism**

- 流水线 —— 将执行一条指令分为不同的步骤，处理器硬件被分为一些系列层次，每个处理不同的步骤
- 超标量 —— 一条指令执行的速度快于一个始终周期

**Single-Instruction, Multiple-Data (SIMD) Parallelism**

SIMD，允许一条只能产生多个可以并行执行的操作。

编译器会尝试从程序中自动抽取SIMD特性，但使用编译器支持的向量数据类型更可靠，例如GCC支持向量数据。

### 1.9.3 The Importance of Abstractions in Computer Systems

- 文件是对I/O设备的抽象；
- 虚拟内存是对程序存储器（主存+文件）的抽象；
- 进程是对正在运行程序的抽象（处理器+虚拟内存）；
- 虚拟机是对整个计算机的（操作系统+处理器+程序）抽象。

## 1.10 Summary

略。