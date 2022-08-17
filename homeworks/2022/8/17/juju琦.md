### \##  套接字接口的结构地址

\- **原文**：从linux内核的角度来看，一个套接字就是通信的一个端点。 从linux程序的角度来看，套接字就是一个有相应描述符的打开文件。

            因特网的套接字地址存放在如图所示的类型为sockaddr_in的16字节结构中。 对于因特网应用， sin_family成员是AF_INET,sin_port成员是一个16位的端口号， 而sin_addr成员就是一个32位的ip地址。

>  struct sockaddr_in {
> 
>       uint16_t    sin_family;
> 
>       uint16_t    sin_port;
> 
>       struct  in_addr  sin_addr;
> 
>       unsigned    char  sin_zero\[8\]; 
> 
> }
> 
> struct sockaddr {
> 
>        unit16_t  sa_family;
> 
>        char        sa_data\[14\];
> 
> }

\- **出处**：深入理解计算机系统-p655 -chapter11.4