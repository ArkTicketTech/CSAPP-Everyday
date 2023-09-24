**异步I/O(asynchronous I/O)**

![img](https://pic2.zhimg.com/80/v2-c2f71242b60ce6e9cb3709a18dd8e9c9_1440w.webp)



- 用户进程发起aio_read操作之后，立刻就可以开始去做其它的事，从kernel的角度，当它受到一个asynchronous read之后，首先它会立刻返回，所以不会对用户进程产生任何阻塞，然后，kernel会等待数据准备完成，然后将数据拷贝到用户内存，当这一切都完成之后，kernel会给用户进程发送一个signal，告诉它read操作完成了