可重定位目标文件

ELF头（ELF header）以一个16字节的序列开始，描述生成该文件的系统的字的大小和字节顺序

剩下的部分包含帮助链接器语法分析和解释目标文件的信息

-   ELF头的大小
-   目标文件的类型
-   机器类型
-   节头部表的文件便宜
-   节头部表中条目的大小和数量，不同节的位置和大小由节头部表描述，目标文件中每个节都有一个固定大小的条目entry



在ELF头和节头部表之间的都是节，包括

-   .text 已编译程序的机器代码
-   .rodata 只读数据，如printf中的格式串和开关语句的跳转表
-   .data 已初始化的全局和静态变量，局部变量不在.data或.bss中
-   .bss 未初始化的全局和静态变量，以及所有被初始化为0的全局和静态变量，在目标文件中，这个节不占实际空间，只是占位符
-   .symtab 符号表，存放在程序中定义和引用的函数和全局变量的信息
-   .rel.text 一个.text节中位置的列表，当链接器把目标文件和其他文件组合时，需要修改这些位置
-   .rel.data 被模块引用或定义的所有全局变量和重定位信息
-   .debug 调式符号表
-   .line 原始源程序中的行号和.text节中机器指令之间的映射
-   .strtab 字符串表，内容包括.symtab和.debug节中的符号表



符号和符号表

每个可重定位目标模块都有一个符号表，包含此模块定义和引用的符号的信息

三种符号

-   此模块定义并被其他模块引用的全局符号
    -   全局链接器符号，非静态的C函数和全局变量
-   其他模块定义并被此模块引用的全局符号
    -   外部符号，其他模块中的非静态C函数和全局变量
-   只被此模块定义和引用的局部符号
    -   带static属性的C函数和全局变量



符号表是由汇编器构造，使用编译器输出到汇编语言.s文件中的符号



Pp. 467-470