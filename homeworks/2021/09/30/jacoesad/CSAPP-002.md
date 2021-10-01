## 1.4 Processors Read and Interpret Instructions Stored in Memory

shell，命令解释器。命令行的第一个单词为内置shell命令或者可执行文件名。

### 1.4.1 Hardware Organization of a System

1. 总线（Buses）—— 传递信息，传送定长字节块，被称为字。32位系统字长为4字节，64位系统字长位8字节。

2. I/O设备（I/O Devices）—— I /O设备通过控制器（在主板上）或适配器（插在主板插槽上）与总线相连。

3. 主存（Main Memory）—— 动态随机存储器（DRAM）。

4. 处理器（Processor）—— 中央处理单元（CPU），核心位一个大小为一个字的存储设备，称为程序计数器（PC）。PC指向主存中的指令。

   寄存器文件（register file）以及算数/逻辑单元（ALU）。

   CPU指令：

   - 加载
   - 存储
   - 操作
   - 跳转

### 1.4.2 Running the hello Program

1. shell将输入字符读入寄存器，放到内存中；
2. shell加载可执行hello文件，将文件中的代码和数据复制到主存；—— 直接存储器存取（DMA）可以将数据不通过处理器而直接从磁盘到达主存。
3. 处理器开始执行hello程序的main中的机器语言指令；
4. 指令将字符串从主存复制到寄存器文件，然后复制到显示设备，最终显示。

## 1.5 Caches Matter

较大的存储设备要比要比较小的存储设备运行慢。

高速缓存（cache memory）作为暂时的集结区域，存放处理器近期可能会需要的信息。L1、L2缓存使用静态随机访问存储器（SRAM）。

## 1.6 Storage Devices Form a Hierarchy

存储器结构层次：

- L0：寄存器
- L1：L1高速缓存（SRAM）
- L2：L2高速缓存（SRAM）
- L3：L3高速缓存（SRAM）
- L4：主存（DRAM）
- L5：本地二级存储（本地磁盘）
- L6：远程二级存粗（分布式文件系统、web服务器）

存储器结构层次的主要思想是上一层的存储存储作为低一层存储器的高速缓存。

