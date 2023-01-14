# helloworld.c 是怎么被编译器处理的
```c
#include <stdio.h>

int main()
{
	printf("Hello, world\n");
	return 0;
}
```
1. 预处理阶段：文本文件 helloworld.c $\to$ 文本文件 helloworld.i，预处理器把`#include<库.h>`的内容插到程序里
```bash
gcc -E helloworld.c -o helloworld.i
```
2. 编译阶段：文本文件 helloworld.i $\to$ 文本文件 helloworld.s，把c语言翻译成了汇编程序
```bash
gcc -S helloworld.i -o helloworld.s 
```
3. 汇编阶段：文本文件 helloworld.s $\to$ 可重定位目标程序 helloworld.o，把汇编语言编译成包含了机器指令的可重定位目标程序，后者的意思是可以跟其他的可重定位目标程序一起链接成可执行文件
```bash
gcc -c helloworld.s -o helloworld.o
```

4. 链接阶段：可重定位目标程序 helloworld.o $\to$ 可执行目标文件 helloworld，把helloworld.o 和其他需要被合并的可重定位目标程序一起打包成可执行目标文件
```bash
gcc helloworld.o -o helloworld
```
