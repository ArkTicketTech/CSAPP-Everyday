# Ch7 Linking

## 7.14 Tools for Manipulating Object Files

GNU binutils 包中的用于处理目标文件的工具：

* `ar`：创建静态库，插入、删除、列出和提取成员
* `strings` ：列出一个目标文件中所有可打印的字符串
* `strip`：从目标文件中删除符号信息表
* `nm`：列出一个目标文件的符号表中定义的符号
* `size`：列出目标文件中节的名字和大小
* `readelf`：显示目标文件的完整结构，包括 ELF 头重编码的所有信息，包含了 `size` 和 `nm` 的功能
* `objdump`：反汇编

另外，`ldd` 命令可以列出可执行文件时所需的共享库。

