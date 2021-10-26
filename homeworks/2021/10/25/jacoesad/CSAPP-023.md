> ***2021.10.25\***

------

## 3.3 Data Formats

- 字 word
- 双字 double words
- 四字 quad words

[C语言在x86-64中的大小](https://www.notion.so/9e94535a96ee466fb265ad283b00efce)

## 3.4 Accessing Information

一个x86-64的CPU包含一组16个存储64位值的通用目的寄存器，这些寄存器用来存储整形数据和指针。

![img](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/1b5617e4-e43d-4ed4-b7e7-2ba5086be553/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20211026%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20211026T031443Z&X-Amz-Expires=86400&X-Amz-Signature=321db7404a22f828d6b41a7725eb7be8c1be7cb03accc6afc0088c9c21c9ef11&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22)

指定可以对这些寄存器的低位字节存放的不同大小的数据进行操作，最低位、最低2字节、最低四字节、整个寄存器。

对于小于8字节的指令，有如下规则：

- 1字节和2字节数字的指令会保持其他字节不变；
- 4字节的指令会把高4字节置为。

栈指针%rsp用来指明运行时栈的结束位置。

