# 编译基础

## GCC

- gcc -Og   调试编译选项，不进行优化，编译出来的代码适合阅读调试
- gcc -c   编译、汇编到目标代码，不进行链接.

 如果声明了一个函数，并没有实现，后面的函数调用这个函数，可以使用-c 选项， 不链接的话就不报错。 如果使用 -o 输出到目标文件， 会进行链接过程， 会报错

- gcc -o   <文件> 输出到 <文件>

```go
long mult2(long, long);

void multstore(long x, long y, long *dest) {
    long t = mult2(x, y);
    *dest = t;
}
```

上面的代码如果想输出目标文件， 可以使用 gcc -c 选项， 不能使用 -o , 因为mul2 没实现， -o  会报错

## GDB

如果有一个 mulstore.o 文件， 想反汇编代码， 可以使用 gdb ./multstore.o 

```go
[root@VM-218-35-centos /home/lorrainema/cc/compile]# gdb ./mulstore.o
GNU gdb (GDB) Red Hat Enterprise Linux 7.6.1-80.el7
Copyright (C) 2013 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-redhat-linux-gnu".
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>...
Reading symbols from /home/lorrainema/cc/compile/mulstore.o...(no debugging symbols found)...done.
(gdb) x /8i multstore
   0x0 <multstore>:	push   %rbx
   0x1 <multstore+1>:	mov    %rdx,%rbx
   0x4 <multstore+4>:	callq  0x9 <multstore+9>
   0x9 <multstore+9>:	mov    %rax,(%rbx)
   0xc <multstore+12>:	pop    %rbx
   0xd <multstore+13>:	retq
   0xe:	Cannot access memory at address 0xe
(gdb)
```

x 指令是打印内存数据， 格式如下：

```go
Examine memory: x/FMT ADDRESS.
ADDRESS is an expression for the memory address to examine.
FMT is a repeat count followed by a format letter and a size letter.
Format letters are o(octal), x(hex), d(decimal), u(unsigned decimal),
  t(binary), f(float), a(address), i(instruction), c(char) and s(string).
Size letters are b(byte), h(halfword), w(word), g(giant, 8 bytes).
The specified number of objects of the specified size are printed
according to the format.

Defaults for format and size letters are those previously used.
Default count is 1.  Default address is following last thing printed
with this command or "print".
```

注意FMT 是一个长度 + Format格式 +  size letter 

## objdump

```go
-a  print the header of object file
-d disassemble the object file to assemble file， 把16进制的文件转成汇编代码
```

```go
objdump -d mulstore.o

mulstore.o：     文件格式 elf64-x86-64

Disassembly of section .text:

0000000000000000 <multstore>:
   0:	53                   	push   %rbx
   1:	48 89 d3             	mov    %rdx,%rbx
   4:	e8 00 00 00 00       	callq  9 <multstore+0x9>
   9:	48 89 03             	mov    %rax,(%rbx)
   c:	5b                   	pop    %rbx
   d:	c3                   	retq
```

## Machine code feature and its disassembled representation

- x86-64 指令大小（占内存大小） 1-15个字节不等。 常用指令和操作数少的指令被设计成占的字节数较少。
- 每个指令都有唯一的数值序号对应。  比如  push %rbx,    起始的bytes对应值是53