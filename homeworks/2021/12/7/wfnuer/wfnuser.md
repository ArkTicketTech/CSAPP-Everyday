## 3.2 Program Encodings
`linux> gcc -Og -o p p1.c p2.c`
-Og 应用简答的优化使得编译器生成机器码 高层的优化会让机器码和源代码之间的关系更难看出来

1. 扩展源码 引入#include 展开#define宏
2. 生成汇编码 p1.s and p2.s
3. 汇编器 汇编 p1.s -> p1.o object-code ; 拥有所有指令，但是全局变量的地址还没有填入
4. 链接器 merge object-code files with code implementing libarary functions and generates the final executable code file

### 3.2.1 Machine-Level code
抽象
1. 机器码和 指令集ISA 相关；指令集看起来都是线性执行的，但硬件其实是并发执行指令的，但有相应的机制保证语意的正确。
2. 机器码级别的代码采用的是虚拟地址；硬件和操作系统提供了一套内存管理系统处理和物理地址的映射

汇编码和机器码非常相似，主要的目的只是为了更好的可读性。可以理解汇编码和c代码的关系就足以让我们理解计算机是如何运行c程序的了。

处理器的一部分细节在汇编码层面会暴露出来，包括：
1. 程序计数器 PC %rip 指向下一条指令
2. register file 寄存器 ｜ 局部变量，参数，返回值都用到了寄存器
3. condition code registers
4. vector registers