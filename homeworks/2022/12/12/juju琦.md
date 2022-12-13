# \## Posix 线程（Pthreads）

      Posix线程是在C程序中处理线程的一个标准接口。   Pthreads定义了大约60个函数， 允许程序创建、杀死和回收线程， 与对等线程安全地共享数据， 还可以通知对等线程系统状态的变化。

      例如：

```
#include "csapp.h"

void *thread(void *vargp);

int main()
{
   pthread_t tid;
   pthread_create(&tid, NULL, thread, NULL);
   Pthread_join(tid, NULL);
   exit(0);
}

void *thread(void *vargp){
   printf("Hello, world!\n");
    return NULL;
}
```

Posix线程是C的一个操作线程接口， 可以理解为C操作线程库。 做一些创建、杀死、回收线程的操作。
