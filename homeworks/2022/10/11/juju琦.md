### \## RIO的无缓冲的输入输出函数

**rio_readn 函数**

   rio_readn(int fd, void \*usrbuf, size_t n);  

   rio_readn函数从描述符fd的当前文件位置最多传送n个字节到内存位置usrbuf。

**rio_writen 函数**

  rio_writen(int fd, void \*usrbuf, sieze_t n);

  rio_writen函数从位置usrbuf传送n个字节到描述符fd。

**通过调用rio_readn 和 rio_writen函数，应用程序可以在内存和文件之间直接传送数据。**

rio_readn，rio_writen是 无缓冲的输入输出函数。

\-出处：《深入理解计算机系统》 P626 chapter 10.5
