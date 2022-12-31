# \##  回收已终止线程的资源

  线程通过调用pthread_join函数等待其他线程终止。

pthread_join函数会阻塞，直到线程tid终止，将线程例程返回的通用指针赋值为thread_return指向的位置，然后回收已终止线程占用的所有内存资源。

```
int pthread_join(pthread_t tid, void **thread_return);
```
