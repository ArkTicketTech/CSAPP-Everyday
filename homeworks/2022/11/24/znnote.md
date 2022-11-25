#### 3.2.2 代码示例

```c
long mult2(long,long)
    
void multstore(long x,long y,long *dest)
{
    long t = mult2(x,y);
    *dest = t;
}
```

在命令行上使用`-S`选项，就能看到C语言编译器产生的汇编代码：

```shell
linux > gcc -0g -S mstore.c
```

含义：产生一个汇编文件`mstore.s`，但是不做其他进一步工作(调用汇编器产生目标代码文件)。

汇编代码包含的声明：

```c
multstore:
   pushq %rbx
   movq  %rbx,%rbx
   call  mult2
   movq  %rax,(%rbx)
   popq  %rbx
   ret
```

代码中每个缩进去的行都对应了一条机器指令。

`pushq`：表示应该将寄存器`%rbx`的内容压入程序栈中。这段代码中已经除去了所有关于局部变量名或数据类型的信息。

使用了`-c`后，GCC会编译并汇编该代码：

`linux > gcc -0g -c mstore.c`

产生了目标代码文件`mstore.o`，是二进制格式的。

例：1368字节的文件`mstore.o`中有一段14字节的序列，它的十六进制表示是：

`53 48 89 d3 e8 00 00 00 00 48 89 03 5b c3`

这就是上面列出的汇编指令对应的目标代码。从中得到一个重要信息：机器执行的程序只是一个字节序列，是对一系列指令的编码。机器对产生这些指令的源代码几乎一无所知。

> 旁注：如何展示程序的字节表示
>
> 展示程序的二进制目标代码，用反汇编器确定该过程代码长度是14字节。