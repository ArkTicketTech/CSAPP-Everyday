# Chapter.11 网络编程

pre Chapter 3.7

--------------

## 主机和服务器的转换


getaddrinfo()完成主机名到域名的解析

套接字地址结构

```cpp
struct addrinfo{
    int ai_flags;   //提示数组标记
    int ai_family;  //socket函数第一个参数
    int ai_socktype;    //socket函数第二个参数
    int ai_protocal;    //第三个参数
    char *ai_canonname; //主机的规范名称
    size_t ai_addrlen;  //ai_addr结构的大小，缓冲区的长度
    struct sockaddr *ai_addr;   //指向 sockaddr 结构的指针。每个返回的addrinfo结构中的ai_addr成员指向一个填充的套接字地址结构。
    struct addrinfo *ai_next;   //addrinfo链表的下一个节点
};
```  
可以看到这个结构体的目的是`直接传递给socket函数`

getaddrinfo()会返回一个addrinfo的链表`注意最后一个指针是链表指针`,返回这个链表以后,客户端会遍历这个链表,依次调用socket和connect,直到成功,建立起连接,类似的,服务端则是调用socket和bind成功

## 套接字接口的辅助函数

> 1. open_clientfd函数

客户端调用open_clientfd函数建立与服务器的连接

```cpp
#include"csapp.h"
int open_clientfd(char *hostname,char *port);
```

上述代码向<hostname:port>的服务器请求连接,返回一个套接字描述符.如果成功,则可以用I/O函数做输入输出

open_clientfd函数的原型如下:

```cpp
int open_clientfd(char *hostname, int port) 
{
    int clientfd;
    struct hostent *hp;
    struct sockaddr_in serveraddr;

    if ((clientfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	return -1; /* check errno for cause of error */

    /* Fill in the server's IP address and port */
    if ((hp = gethostbyname(hostname)) == NULL)
	return -2; /* check h_errno for cause of error */
    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)hp->h_addr_list[0], 
	  (char *)&serveraddr.sin_addr.s_addr, hp->h_length);
    serveraddr.sin_port = htons(port);

    /* Establish a connection with the server */
    if (connect(clientfd, (SA *) &serveraddr, sizeof(serveraddr)) < 0)
	return -1;
    return clientfd;
}
```

相比于原书,他这部分代码改动很大,总而言之,他的思想就是  
- 把获取socket信息的部分封装起来
- 然后连接客户端/服务器的部分封装起来
- 外部只需要调用 open_clientfd即可

新版里直接把getaddrinfo函数给干掉了
= =


--------------


> Latex转Svg

https://www.latexlive.com/