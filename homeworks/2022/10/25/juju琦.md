练习题10.3
假设磁盘文件 foobar.txt 由6个ASCII码字符“foobar”组成。 那么，下列程序的输出是什么？
```
#include "csapp.h"

int main(){

 int fd;
 char c;

 fd = open("foobar.txt", O_RDONLY, 0);
 if(fork() == 0){
  read(fd, &c, 1);
  exit(0);
 }

 wait(NULL);
 read(fd, &c, 1);

 printf("c = %c\n", c);
 exit(0);

}

```

实验结果：![image](https://user-images.githubusercontent.com/18367460/197401260-d2be390d-c329-4e56-860d-d2fc8dc0dc2c.png)

考察点： 子进程会调用父进程的描述符表，所以在描述符fd被调用了2次，第二次读取的是第二次字节o
