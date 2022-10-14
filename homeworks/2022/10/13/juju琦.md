##  RIO的带缓冲的输入函数

rio_readlineb

        从一个内部读缓冲区复制一个文本行，当缓冲区变空时，会自动调用read重新填满缓冲区。

rio_readnb

       对于既包含文本行也包含二进制数据的文件，rio_readnb和 rio_readlineb一样读缓冲区中传送原始字节。是rio_readn函数的带缓冲的版本。

-出处：《深入理解计算机系统》 P626 chapter 10.5
