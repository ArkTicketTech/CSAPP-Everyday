ELF可重定位目标文件格式：以一个16字节的序列开始，这个序列描述了生成该文件的系统的字的大小和字节顺序。ELF投和节头部表之间的都是节。一个典型的ELF可重定位目标文件包含：
.text:已编译程序的机器代码
.rodata:只读数据
.data:已初始化的全局和静态C变量。
:bss:未初始化的全局和静态C变量，以及所有被初始化为0的全局或静态变量。在目标文件中这个节不占据实际空间，仅仅是一个占位符。
.symtab:符号表，存放程序中定义和引用的函数和全局变量
.rel.text:一个.text节中位置列表，当链接器把这个目标文件和其他文件组合时，需要修改这些位置。
.rel.data:被模块引用或定义的所有全局变量重定位信息。
.debug:调试符号表
.line:原始C源程序中的行号和.text节中机器指令之间的映射。
.strtab:字符串表

假设链接器读取一组可重定位目标文件，并把它们链接起来，形成一个输出的可执行文件。实际上，所有编译系统都提供一种机制，将所有相关的目标模块打包为一个单独文件，静态库，作为链接器的输入。

若不使用静态库，编译器开发人员会使用什么方法向用户提供这些函数呢 1让编译器辨认出对标准函数的调用，直接生成相应的代码。Pascal就是这样。C标准定义了大量标准函数，这种方法将给编译器增加显著复杂性。每添加、删除、修改一个标准函数时，需要一个新的编译器版本。2将所有标准C函数放在一个单独的可重定位目标模块中（libc.o）把这个模块链接到他们的可执行文件中。
优点是将编译器实现和标准函数的实现分离。缺点是系统中每个可执行文献都包含着一份标准函数集合的完全副本，对磁盘空间是很大浪费。每个运行的程序都将自己的这些函数副本放在内存中，对内存极度浪费。对任何标准函数的任何改变，都需要重新编译整个源文件，耗时且开发、维护复杂。