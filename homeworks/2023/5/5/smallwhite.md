减少不必要的内存引用

1. 减少不必要的内存引用，减少中间临时变量的赋值`temp`
2. 为了增加程序的可读性，需要增加一些中间变量
3. 要在二者之间取得一个均衡的效果，编译器会帮助我们进行优化，编译为汇编语言时，会减少一些中间变量的引用

编译器无法优化，地址的引用，中间变量不要使用指针来进行存储，要使用临时值

前者 `*dest` 在编译时，不是中间变量，所以在编译时，无法被优化

<img src="https://typra-pictures.oss-cn-beijing.aliyuncs.com/imgs/image-20230505233927999.png" alt="饿" style="zoom:33%;" />

这里使用 `acc`做为中间变量，可以被优化

<img src="https://typra-pictures.oss-cn-beijing.aliyuncs.com/imgs/75891683300814_.pic.jpg" alt="75841683300783_.pic" style="zoom:33%;" />

后者速度更快，所以使用中间变量时是非常巧妙的
