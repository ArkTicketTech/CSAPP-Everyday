### \## 11-03-02 

### **服务器如何将参数传递给子进程？**

           服务器接收到如下一个请求后 ， 例如 Get /cgi-bin/adder?15000&213  HTTP/1.1, fork一个子进程，子进程调用execve执行CGI程序。 在调用execve之前，子进程将CGI环境变量设置为“15000&213”， cgi程序运行时，可以使用getenv函数来引用它。

### **服务器如何将其他信息传递给子进程？**

          CGI定义了大量的其他环境变量。 

            QUERY_STRING  程序参数

           SERVER_PORT     父进程监听的端口

           REMOTE_HOST     客户端的域名

         REMOTE_ADDR    客户端的点分十进制ip地址