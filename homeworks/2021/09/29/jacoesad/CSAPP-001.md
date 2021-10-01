# Chapter 1 A Tour of Computer Systems

Start from here.

```c
#include <stdio.h>

int main()
{
		printf("hello, world\\n");
		return 0;
}
```

## 1.1 Information Is Bits + Context

**hello.c** 是源程序，是由0、1组成的位序列，8位为一组，成为字节。大多数时候，使用ASCII标准来表示文本字符，只有ASCII字符构成的文件被称为文本文件，其他文件称为二进制文件。

系统中的所有信息都是由比特表示的，而区分不同数据对象的方法就是这些对象所在的上下文。

## 1.2 Programs Are Translated by Other Programs into Different Froms

Unix系统上，通过编译将源文件转化为目标文件，由编译驱动器完成，命令为：

```bash
> gcc -o hello hello.c
```

过程可以分为四个阶段，分别是预处理阶段、编译阶段、汇编阶段、链接阶段，对应执行的程序为预处理器、编译器、汇编器、链接器。

- 预处理

  预处理器（cpp），处理头文件stdio.h，将其内容放入程序文本中，hello.c(文本) → hello.i(文本)；

- 编译

  编译器（ccl），hello.i(文本) → hello.s(文本)，hello.s中为汇编语言程序；

- 汇编

  汇编器（as），hello.s(文本)→hello.o(二进制)，hello.o为重定位目标程序（relocatable object program）

- 链接

  链接器（ld），hello.o(二进制)→hello(可执行文件)，将程序使用的预编译的.o文件合并到二进制文件中，生成可执行文件

## 1.3 It Pays to Understand How Compilation Systems Work

为什么要了解编译是如何工作的：

- 优化程序性能
- 理解链接时出现的错误
- 避免安全漏洞——通过理解堆栈原理以及溢出