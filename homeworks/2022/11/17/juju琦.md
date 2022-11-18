## 11-02-05 套接字的结构

**//ip socket 地址结构**

struct sockaddr_in {

       uint16_t sin_family;   //协议族。默认为AF_INET

       uint16_t sin_port;   //端口

       struct in_addr  sin_addr;  //ip地址

       unsigned char   sin_zero[8];

}

**//通用 socket地址结构**

struct sockaddr{}{

  uint16_t sa_family;  

  char sa_data[14];

}

