# 4 Processor Architecture

* 本章我们会介绍一个简化的指令集，用于我们的处理器实现，称为 Y86-64， 有更少的 data type，instruction，addressing modes。 不过依旧足够用来支持可以操纵整型数据的程序。

* 之后会提供关于数字硬件设计的背景知识。 介绍 HCL （hardware control language）
* Y86-64 处理器会先用 sequential 执行指令的方式实现
* 随后介绍如何通过一系列变化转化为流水线的处理器；每个指令都被拆分为5个阶段
* 为了完成这些，我们设计了一系列工具。 包括 assembler simulator 等。


