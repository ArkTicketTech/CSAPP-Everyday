# Ch2 Representing and Manipulating Information

### 2.1 Information Storage

本节介绍了数据在计算机中如何存储及表示。

* 机器码中并不含有数据类型的信息。C 编译器会将指针和类型信息联系起来，根据指针类型的不同，来生成不同的机器码解析存储地址的数据信息。

其次谈了二进制、十进制、十六进制之间如何快速转换；以及 C 中相关数据类型。



字节序问题，对于某个具体的数据对象，需要关注两个点：

1. 对象地址。对象的地址为所使用字节的最小地址，

2. 内存中如何排列这个字节。大端序、小端序。

    * 大端序：内存低地址存高字节信息；
    * 小端序：内存低地址存低字节信息；

现代处理器有 双端法 （bi-endian）类型的，同时兼容小端序和大端序；当机器字节序往往还和操作系统类型有关。

处理机器字节序时需要注意以下三点：

* 涉及到网络 I/O 时，双方的主机字节序可能不一样，因此需要做出字节序的规则（TCP/IP 中默认使用大端序作为网络字节序）；
* 阅读汇编代码时；
* 使用强制类型转换和共用体（Union）时。



书中列出了以下代码用来检验字节的表示方式：

```c
#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++)
    printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x) {
	show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

```



C-style 字符串的表示为：

* 用字符数组来表示，每个字符用特定编码表示（例如 ACSII）；
* 以 NULL 结尾。



机器代码的表示：

* 不同的机器类型，不同的指令集，不同的操作系统，最后产生的机器码不同；因此二进制代码很少能过在不同的机器和操作系统组合之间移植；
* 因此，计算机系统中，程序和数据都是字节序列。

