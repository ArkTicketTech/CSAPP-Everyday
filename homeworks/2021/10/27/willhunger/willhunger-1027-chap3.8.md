# Ch3 Machine-Level Representation of Programs

## 3.8 Array Allocation and Access

**基本原则**

给定数据类型 T 和 整形常数 N，有数组 `T A[N]`：

* 内存中分配 $sizeof(L) \cdot N$ 字节的连续内存区域；
* $A$ 指向数组的开头的指针，数组元素 $i$ 会被存放在 $A + sizeof(L) \cdot i$ ；
* 数组项通过 $mov$ 类指令来访问，例如 $A$ 的地址存放在 `%rdx` 中，$i$ 存放在`%rcx`中；
    * `movl (%rdx, %rcx, 4), %eax` 会计算第四个元素的内存地址，访问内存地址，且将结果存放到 `%eax` 中。



