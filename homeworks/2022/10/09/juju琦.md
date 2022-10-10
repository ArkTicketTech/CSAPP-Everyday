## \## 什么是socket

socket是网络通信的2个端点，是系统i/o知识的一部分。 unix/linux程序在执行任何形式的i/o操作时，都是跟文件生成的描述符打交道。 而这些文件，可能是终端（标准输入：键盘，标准输出：显示器）/硬盘上的文件/或者是网络连接。 注意：网络连接也是一个文件，也有描述符。 而网络连接对应的文件就是socket。

我们可以通过socket（）函数来创建一个网络连接，或者说打开一个网络文件， socket()的返回值就是文件描述符。 有了文件描述符，就可以使用普通的文件操作函数来传输数据了，例如： read()读取从远程计算机传来的数据； write()向远程计算机写入数据。

一个套接字由三部分组成：协议，本地地址，本地端口。

出处：[http://c.biancheng.net/view/2123.html](http://c.biancheng.net/view/2123.html)

     [https://www.ibm.com/docs/en/zos/2.2.0?topic=concepts-understanding-sockets](https://www.ibm.com/docs/en/zos/2.2.0?topic=concepts-understanding-sockets)

