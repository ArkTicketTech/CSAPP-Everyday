### stat函数

int stat(const char *filename, struct stat \**buf);

以一个文件名作为输入。 在web服务器相关联内容时， 需要stat数据结构中的st_mode和st_size成员。

st_size 成员包含了文件的字节数大小。

st_mode成员则编码了文件访问许可位和文件类型。

    S_ISREG: 这是一个普通文件吗？

    S_ISDIR:这是一个目录文件吗？

    S_ISSOCK:这是一个网络套接字吗？
