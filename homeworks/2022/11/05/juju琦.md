### \## 10-11  综合
Unix I/O模型是在操作系统内核中实现的。
应用程序可以通过open ,close,lseek, read,write 和stat这样的函数来访问Unix I/O。 较高级别的RIO和标准I/O函数都是基于 Unix I/O函数来实现的。   RIO函数是会自动处理不足值，并且为读文本行提供一种高效的带缓冲的方法。 标准I/o函数提供了Unix I/O函数的一个更加完整的带缓冲的替代品。
