### \## 主机和服务的转换( getaddrinfo和***getnameinfo***)

\- **原文**：

getaddinfo函数 将主机名、主机地址、服务名和端口号的字符串表示转化为套接字接口地址结构。

           getaddinfo(const char \*host,  const char\*service,  const struct addrinfo \*hints, struct addrinfo \*\*result);   返回一个result, result一个指向 adrinfo 结构的链表，其中每个结构指向一个对应于host和service的套接字地址结构。 

           host可以是域名，也可以是ip。 service是服务名，也可是端口号。

        getnameinfo 和getnameinfo是相反的，将一个套接字地址结构转换为响应的主机和服务名字符串。  

           getnameinfo(const struct sockaddr \*sa, socklen_t salen, char \*host, size_t hostlen, char \*service, size_t servlen, int flags),  参数sa指向大小为salen字节的套接字地址结构，host指向大小为hostlen字节的缓冲区，service指向大小为servlen字节的缓冲区。 将套接字地址结构sa转换成对应的主机和服务名字符串，并将他们复制到host和service缓冲区。

\- **出处**：深入理解计算机系统-p656 -chapter11.4.7

          [https://zhuanlan.zhihu.com/p/109826876](https://zhuanlan.zhihu.com/p/109826876)

\- **日期**：2021-12-09