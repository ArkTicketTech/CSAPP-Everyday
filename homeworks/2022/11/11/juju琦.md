#### 11.2 编写程序hex2dd.c,将它的十六进制参数转换为点分十进制串并打印出结果。 例如

```

#include "csapp.h"

int main(int argc, char **argv){
   struct in_addr inaddr; //定义ip地址
   uint32_t addr;         //定义主机地址
       
   char buf[MAXBUF];

   sscanf(argv[1], "%x", &addr);
             
   //将主机字节转换为网络字节
   inaddr.s_addr = htonl(addr);
   //                           
   //将16进制ip地址转换为点分十进制
   inet_ntop(AF_INET, &inaddr, buf, MAXBUF);
   printf("%s\n", buf);
}


```
