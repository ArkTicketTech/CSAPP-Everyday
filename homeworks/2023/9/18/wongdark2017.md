# CSAPP 读书笔记

对于机器级别的程序重要的两种抽象：

- instruction set architecture , or ISA
- 虚拟内存

程序计数器（通常称为PC，在x86-64架构中称为%rip）指示下一条将被执行的指令在内存中的地址。整数寄存器文件包含16个命名位置，用于存储64位的值。这些寄存器可以保存地址（对应于C指针）或整数数据。一些寄存器用于跟踪程序状态的关键部分，而其他寄存器用于保存临时数据，例如过程的参数和局部变量，以及函数返回的值。
条件码寄存器保存有关最近执行的算术或逻辑指令的状态信息。这些寄存器用于实现对控制或数据流的条件性更改，例如实现if和while语句所需的更改。
一组矢量寄存器可以分别保存一个或多个整数或浮点值。
