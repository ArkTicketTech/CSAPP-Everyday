IP地址
一个IPv4地址是一个32位无符号整数。网络程序将IP地址存放在以下结构中

```c
/* IP address structure */
struct in_addr{
  uint32_t s_addr; /* Address in network byte order (Big-endian) */
};
```

因为因特网主机中可以有不同的主机字节序列，TCP/IP为任意整数数据项定义了一个统一的网络字节顺序(network byte order) —— 大端字节顺序。
IP地址通常是以一种称为点分十进制表示法来表示的。
例如128.2.194.242就是地址0x8002c2f2的点分十进制表示。
