#### 11.4函数getaddrinfo 和 getnameinfo 分别包含了inet_pton和inet_ntop的功能，提供了更高级别的、独立于任何特殊地址格式的抽象。 想看看这到底有多方便，编写HOSTINFO的一个版本（图11-17），用inet_pton而不是getnameinfo将每个套接字地址转换为点分十进制地址的字符串.
```
#include "csapp.h"

int main(int argc, char **argv){
   struct addrinfo *p, *listp , hints;
   struct sockaddr_in *sockp;
   char buf[MAXLINE];
   int rc;
   
   if(argc != 2) {
   }
   
   memset(&hints, 0, sizeof(struct addrinfo));
   hints.ai_family = AF_INET;
   hints.ai_socktype = SOCK_STREAM;
   if((rc = getaddrinfo(argv[1], NULL, &hints, &listp)) != 0){
     fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(rc));
     exit(1);
   }
   
   for(p=listp; p; p=p->ai_next){
      sockp = (struct sockaddr_in *)p->ai_addr;
      inet_ntop(AF_INET, &(sockp->sin_addr), buf, MAXLINE);
      printf("%s\n, buf");
   }
   
   Freeaddrinfo(listp);
   exit(0);
}

```
