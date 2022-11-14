#### 11.3 编写程序 dd2hex.c,将它的点分十进制参数转换为十六进制数，并打印出结果

```
#include "csapp.h"

int main(int argc, char **argv){
  struct in_addr inaddr; //定义ip地址
  int addr;

  char buf[MAXBUF];
 // sscanf(argv[1], "%u", &addr);

  //将十进制ip转换为二进制的网络字节
  inet_pton(AF_INET, argv[1], &inaddr);
  //    
  //将网络字节转换为主机字节
  addr = ntohl(inaddr.s_addr);
  //inet_ntop(AF_INET, in_addr, addr, 16);
  printf("ox%x\n", addr);
}

```
![image](https://user-images.githubusercontent.com/18367460/201469780-b097313a-e52d-43fc-a3de-7a1b178ed86f.png)
