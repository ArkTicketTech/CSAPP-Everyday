练习题10.4
如何用dup2 将标准输入重定向到描述符5？

```
dup2(5,0);
```

考察点：重定向得的基本使用


练习题10.5
假设磁盘文件 foobar.txt由6个ASCII码字符“foobar”组成， 那么下列程序的输出是什么？

```
#include "csapp.h"

int main()
{
  int fd1, fd2;
  char c;

  fd1 = open("foobar.txt", O_RDONLY, 0);
  fd2 = open("foobar.txt", O_RDONLY, 0);
  //读取fd2的第一个字符到 内存的c所在位置
   read(fd2, &c, 1);

//fd1描述符 重定向到描述符fd2
  dup2(fd2, fd1);

  //读取fd1的第一个字符到 内存的c所在位置
  read(fd1, &c, 1);

  printf("c = %c\n", c);
  exit(0);

}


```

结果：指向第二个o![image](https://user-images.githubusercontent.com/18367460/198215100-206010e3-c256-4035-923d-0faf8a8ad48a.png)

考察点：read读取数据后描述符位置的变化， dup2重定向fd2,fd1
