### 10.20

___

1. Rio无缓冲输入和输出函数

   ```c++
   ssize_t rio_readn(int fd, void *usrbuf, size_t n);
   ssize_t rio_writen(int fd, void *usrbuf, size_t n);
   ```

   返回：如果OK，则返回传输的字节数，如果EOF（仅rio_readn），则返回0，如果出错，则返回−1。rio_readn函数从描述符fd的当前文件位置传输最多n个字节到内存位置usrbuf。同样，rio_writen函数从位置usrbuf传输n个字节到描述符fd。rio_readn函数只有在遇到EOF时才能返回短计数。rio_writen函数永远不会返回短计数。可以在同一个描述符上任意交错调用rio_readn和rio_writen。

 

