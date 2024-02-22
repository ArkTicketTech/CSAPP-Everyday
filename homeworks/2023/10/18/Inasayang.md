运行可执行文件的过程，shell调用加载器loader的函数，将可执行文件的代码和数据复制到内存中，让后将控制转移到程序的开头



构造可执行文件，链接器的两个主要任务

-   符号解析symbol resolution
    -   目标文件定义和引用符号
    -   每个符号对应一个函数，一个全局变量或一个静态变量
    -   符号解析的目的时将每个符号引用和一个符号定义关联起来
-   重定位relocation
    -   编译器和汇编器生成从地址0开始的代码和数据节
    -   链接器通过把每个符号定义与一个内存位置关联起来，重定位这些节，修改对这些符号的引用



目标文件纯粹是字节快的集合，这些块中有的包含代码，有的包含程序数据，有的包含引导链接器和加载器的数据结构



目标文件

-   可重定位目标文件
-   可执行目标文件
-   共享目标文件



Pp. 450-467