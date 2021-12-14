CSAPP_12_14

**库函数 vs 系统调用**

像是**fork**这样的系统调用（fork没有参数，一切都继承自父进程【懒惰】，更加诡异的是，它返回两次）早在Unix第1版就已经存在，你看： [Unix第1版的手册（第2章：系统调用）](http://man.cat-v.org/unix-1st/) ，这样算下来这个系统调用已经存在长达50年了，最终fork的思想也被 Linux 继承和发扬光大。在Linux中fork()是一个封装了底层**clone**()系统调用的库函数（man 2 fork），你可以使用**ltrace**来追踪库函数调用，使用**strace**命令来追踪系统调用。

```c
#include <stdio.h>
int main(void) {
    printf("hello, world!\n");
    return 0;
}

// 用gcc编译之后，通过ltrace来追踪库函数调用，strace来追踪系统调用

// 稍微改写一下，让我们更加接近底层一些：man syscall
#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
int main() {
    return syscall(__NR_write, 1, "Hello, world!\n", 14);
}
```

