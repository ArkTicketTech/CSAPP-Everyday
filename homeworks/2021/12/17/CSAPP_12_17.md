CSAPP_12_17 第一章计算机系统漫游（1）

```c
#include<stdio.h>

int main()
{
    printf("hello, world\n");
    return 0;
}
```

源程序是一个由0和1组成的比特序列：

![image-20211217104103155](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20211217104103155.png)

为了在系统上运行hello.c并把它翻译成一个可执行目标文件hello,这个翻译过程分为四步完成：

![image-20211217104329104](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20211217104329104.png)

（1）预处理阶段。预处理器根据字符#开头的命令，修改原始的c程序。如#include<stdio.h>告诉预处理器读取系统头文件stdio.h中的内容，并把它直接插入到程序文本中。得到了另外一个c程序以.i文件作为扩展名。

（2）编译阶段。编译器将hello.i->hello.s包含一个汇编语言程序，包含main函数的定义。

（3）汇编阶段。汇编器将hello.s翻译成机器语言指令，并将这些指令打包成一种可重定位目标程序，并将结果保存在hello.o中，hello.o文件是一个二进制文件。

（4）链接阶段。hello程序调用了printf函数，printf函数存在于一个名为printf.o的单独的预编译好了的目标文件中，而这个文件必须以某种方式合并到我们的hello.o的程序中，链接器就负责处理这种合并。结果得到hello文件，它是一个可执行文件，被加载到内存中，由系统执行。

