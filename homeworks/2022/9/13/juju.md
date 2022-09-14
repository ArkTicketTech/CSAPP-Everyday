## 11.4.8 实验

/**
open_clientfd 函数建立与服务端的连接，返回一个连接描述符
**/

#include "csapp.h"


int open_clientfd(char *hostname, char *port)
{
 int clientfd;
 struct addrinfo hints, *listp ,*p;
 
 //将hints赋值, 大小为sizeof,值为0。
 memset(&hints, 0, sizeof(struct addrinfo));
 
 hints.ai_socktype = SOCK_STREAM;               //打开一个连接
 hints.ai_flags    = AI_NUMERICSERV;            //使用数字端口
 hints.ai_flags   != AI_ADDRCONFIG;             //
 
 
 Getaddrinfo(hostname, port, &hints, &listp);
 
 for(p =listp; p;p=p->ai_next){
    /**创建一个socket描述符**/
    //socket创建失败， 再次尝试
    if((clientfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol )) < 0) continue;
   
    /**连接服务端**/
    //连接成功
    if(connect(clientfd, p->ai_addr, p->ai_addrlen) != -1) break; 
    //连接失败，再次尝试连接
    close(clientfd); 
 }
 //释放listp,以免内存泄漏。
 Freeaddrinfo(listp);
 //全部连接失败，返回-1。 连接成功的，返回描述符。
 if(!p) 
  return -1;
 else
  return clientfd;
 

}
