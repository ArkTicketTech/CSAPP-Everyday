每个网络应用都是基千客户端-服务器模型的。根据这个模型， 一 个应用是由一个服务器和一个或多 个客户端组成的。服务器管理资源，以某种方式操作资源，为它的客户端提供服务。客户端-服务器模型 中的基本操作是客户端-服务器事务，它是由客户端请求和跟随其后的服务器响应组成的 。

客户端和服务器通过因特网这个全球网络来通信。从程序员的观点来看，我们可以把因特网看成是一个全 球范围的主机集合，具有以下几个属性: 1)每个因特网主机都有一个唯一的 32位名字，称为它的 IP地址。 2) IP 地址的集合被映射为一个因特网域名的集合 。 3)不同因特网主机上的进程能够通过连接互相通信 。

客户端和服务器通过使用套接字接口建立连接。一个套接字是连接的一个端点，连接以文件描述符

的形式提供给应用程序 。套接字接 口提供了打开和关闭套接字描述符的函数 。 客户端和服务器通过读写 这些描述符来实现彼此间的通信。