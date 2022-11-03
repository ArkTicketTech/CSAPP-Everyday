##10.7 修改图 10-5 中所示的 cpfile 程序 ，使得它用 RIO 函数从标准 输入复制到标准输出，一次 MAXBUF 个字节
```
#include "csapp.h"

int main(int argc, char **argv)
{
    int n;
    rio_t rio;
    char buf[MAXBUF];

    rio_readinitb(&rio, STDIN_FILENO);
    while((n = rio_readnb(&rio, buf, MAXBUF)) != 0)
            rio_writen(STDOUT_FILENO, buf, n);
    exit(0);
}


```
