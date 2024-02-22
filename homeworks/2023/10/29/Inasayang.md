动态连接共享库

共享库在运行或加载时，被加载到任意内存地址，和一个在内存中的程序链接起来，这个过程称为动态链接dynamic linking，由动态链接器dynamic linker执行

-   .so
-   .dll

不复制代码和数据节到可执行文件中，只复制一些重定位和符号表信息，运行时可以解析堆共享库中代码和数据的引用



从应用程序中加载和链接共享库

在运行时要求动态链接器加载和链接某个共享库，无需再编译时链接



Java本地接口Java native Interface，使用java调用本地c/c++函数

将本地函数编译到共享库中.so，java解释器利用dlopen接口动态链接和加载so文件，再调用函数



Pp. 485-489