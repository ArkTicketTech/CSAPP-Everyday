Pp. 121-331 略过

### Ch5 优化程序性能

研究程序的汇编代码是理解编译器及产生的代码如何运行的最有效手段之一



#### 优化编译器的能力和局限性

![](https://inasa.dev/image/csapp/05/1.png)

twiddle2效率更高一些，只需要三次内存引用

-   读`*xp`, 读`*yp`，写`*xp`

twiddle1需要6次

-   2次读`*xp`, 2次读`*yp`, 2次写`*xp`



如果xp等于yp

![](https://inasa.dev/image/csapp/05/2.png)

twiddle1的结果是增加4倍



![](https://inasa.dev/image/csapp/05/3.png)

twiddle2的结果是增加3倍



编译器不知道twiddle1如何调用，所以必须假设`xp`和`yp`可能相等

所以不能产生twiddle2的风格的代码



两个指针指向同一个内存的情况称为内存别名使用（`memory aliasing`）

在执行安全的优化中，编译器必须假设不同的指针可能会指向内存中的同一个位置



![](https://inasa.dev/image/csapp/05/4.png)

t1依赖于`*p`和`*q`是否指向同一内存



Pp. 341-345