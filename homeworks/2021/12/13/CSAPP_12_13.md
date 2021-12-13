**CSAPP_12_13 链接**

**LD_PRELOAD**是Linux系统的一个环境变量，它可以影响程序的运行时的链接（Runtime linker），它允许你定义在程序运行前优先加载的动态链接库，一方面，我们可以以此功能来使用自己的或是更好的函数（比如，你可以使用Google开发的tcmalloc来提升效率），而另一方面，我们也可以向别人的程序注入程序，从而达到特定的目的。

![](C:\Users\ASUS\Desktop\csapp\链接.png)