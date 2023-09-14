![img](https://typra-pictures.oss-cn-beijing.aliyuncs.com/imgs/v2-493043f6862cf03dee558d30dcc2b57a_1440w.webp)

阻塞`io` 模型

- 当用户进程调用了recvfrom这个系统调用，kernel就开始了IO的第一个阶段：准备数据，对于network IO来说，一般数据在一开始还没有到达，kernel会等待足够的数据到来，而在用户进程这边，整个进程会被阻塞挂起，当kernel等到数据准备好，它就会将数据从内核缓冲区拷贝到用户进程缓冲区，然后kernel返回结果，用户进程才进入就绪状态，重新运行起来