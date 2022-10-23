练习题10.2
假设磁盘文件 foobar.txt 由6个ASCII码字符“foobar”组成。 那么，下列程序的输出是什么？
```
#include "csapp.h"
int main(){
  int fd1, fd2;
 char c;

 fd1 = open("foobar.txt", O_RDONLY, 0);
 fd2 = open("foobar.txt", O_RDONLY, 0);

 read(fd1, &c, 1);
 read(fd2, &c, 1);

 printf("c = %c\n", c);
 exit(0);

}
```

实验结果：![image](https://user-images.githubusercontent.com/18367460/197399720-afb85df8-93de-48ec-88bf-f14e30d2e966.png)

考察点： fd1,fd2是不同的描述符，都有自己的位置。
