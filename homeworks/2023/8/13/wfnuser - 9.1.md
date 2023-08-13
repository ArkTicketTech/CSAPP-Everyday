本章从两个方面介绍虚拟内存
虚拟内存工作原理
虚拟内存如何使用、如何被应用管理
# 9.1 Physical and Virtual Addressing
主存在计算机中被组织成长度M的连续 byte-size 的单元，每个单元由一个独特的 physical address
早期的计算机是直接使用物理地址寻址的 - DSP、嵌入式微处理器、Cray supercomputers 仍然在这么做
现代的计算机则采用虚拟地址 将物理地址转化为虚拟地址的过程称为 address translation ； 这个过程也需要操作系统和硬件的紧密合作； 相关的硬件称为 MMU (memory management unit) ； 其转换的依据是存在内存中的一张表，其内容由操作系统管理