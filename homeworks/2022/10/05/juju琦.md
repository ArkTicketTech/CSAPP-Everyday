
//open,close实验

int main(){

  int fd1, fd2;

  fd1 = open("foo.txt", O_RDONLY, 0);
  close(fd1);
  fd2 = open("baz.txt", O_RDONLY, 0);
  printf("fd2 = %d\n", fd2);
  exit(0);

}



//read,write实验
#include "csapp.h"

int main(void){

    char c;

    //从标准输入读取的数据不为0，则写入标准输出
    while(read(STDIN_FILENO, &c, 1) != 0)
        write(STDOUT_FILENO, &c, 1);

    exit(0);
}
