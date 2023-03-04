# 阅读记录

## 11.1 C-S编程模型

模型特点：

每个网络应用都是基于客户端—服务器模型的。釆用这个模型，一个应用是由一个服务器进程和一个或者多个**客户端**进程组成。服务器管理某种资源，并且通过操作这种资源来为它的客户端提供某种服务。例如，一个 Web 服务器管理着一组磁盘文件，它会代表客户端进行检索和执行。一个 FTP 服务器管理着一组磁盘文件，它会为客户端进行存储和检索。相似地，一个电子邮件服务器管理着一些文件，它为客户端进行读和更新。

客户端—服务器模型中的基本操作是**事务**（transaction）（见图 11-1）。

![img](https://1087580735-files.gitbook.io/~/files/v0/b/gitbook-legacy-files/o/assets%2F-MHt_spaxGgCbp2POnfq%2F-MIcEDmtR-tqJ-C9Mr2d%2F-MIcFLCPfWxblhRZ7AP_%2F11-01%20%E4%B8%80%E4%B8%AA%E5%AE%A2%E6%88%B7%E7%AB%AF%E6%9C%8D%E5%8A%A1%E5%99%A8%E4%BA%8B%E5%8A%A1.png?alt=media&token=78c8799d-c6de-4407-8770-609fff26bf02)

图 11-1 一个客户端—服务器事务

一个事务的组成：

一个客户端—服务器事务由以下四步组成。

1. 当一个客户端需要服务时，它向服务器发送一个请求，发起一个事务。例如，当 Web 浏览器需要一个文件时，它就发送一个请求给 Web 服务器。
2. 服务器收到请求后，解释它，并以适当的方式操作它的资源。例如，当 Web 服务器收到浏览器发出的请求后，它就读一个磁盘文件。
3. 服务器给客户端发送一个**响应**，并等待下一个请求。例如，Web 服务器将文件发送回客户端。
4. 客户端收到响应并处理它。例如，当 Web 浏览器收到来自服务器的一页后，就在屏幕上显示此页。

认识到客户端和服务器是进程，而不是常提到的机器或者**主机**，这是很重要的。一台主机可以同时运行许多不同的客户端和服务器，而且一个客户端和服务器的事务可以在同一台或是不同的主机上。无论客户端和服务器是怎样映射到主机上的，客户端—服务器模型都是相同的。

## 11.2 网络

网络主机硬件组成：

<img src="https://1087580735-files.gitbook.io/~/files/v0/b/gitbook-legacy-files/o/assets%2F-MHt_spaxGgCbp2POnfq%2F-MIcFl23F3mZVEkEbplX%2F-MIcFnVWynYxtK3NJ2f-%2F11-02%20%E4%B8%80%E4%B8%AA%E7%BD%91%E7%BB%9C%E4%B8%BB%E6%9C%BA%E7%9A%84%E7%A1%AC%E4%BB%B6%E7%BB%84%E6%88%90.png?alt=media&token=3b44a186-e4d9-4249-be30-51873d1fbe14" alt="img" style="zoom:50%;" />

主机之间的通信。

使用一些电缆和叫做**网桥**（bridge）的小盒子，多个以太网段可以连接成较大的局域网，称为**桥接以太网**（bridged Ethernet）。

桥接以太网模型：

<img src="https://1087580735-files.gitbook.io/~/files/v0/b/gitbook-legacy-files/o/assets%2F-MHt_spaxGgCbp2POnfq%2F-MIcFl23F3mZVEkEbplX%2F-MIcGBwQgcFq_cQ41BB3%2F11-04%20%E6%A1%A5%E6%8E%A5%E4%BB%A5%E5%A4%AA%E7%BD%91.png?alt=media&token=be280145-d387-4296-bc60-2d05e2a78e02" alt="img" style="zoom:50%;" />

网桥比集线器更充分地利用了电缆带宽。利用一种聪明的分配算法，它们随着时间自动学习哪个主机可以通过哪个端口可达，然后只在有必要时，有选择地将帧从一个端口复制到另一个端口。

在层次的更高级别中，多个不兼容的局域网可以通过叫做**路由器**（router）的特殊计算机连接起来，组成一个 internet（互联网络）。每台路由器对于它所连接到的每个网络都有一个适配器（端口）。路由器也能连接高速点到点电话连接，这是称为 WAN（Wide-Area Network，广域网）的网络示例，之所以这么叫是因为它们覆盖的地理范围比局域网的大。一般而言，路由器可以用来由各种局域网和广域网构建互联网络。例如，图 11-6 展示了一个互联网络的示例，3 台路由器连接了一对局域网和一对广域网。

<img src="https://1087580735-files.gitbook.io/~/files/v0/b/gitbook-legacy-files/o/assets%2F-MHt_spaxGgCbp2POnfq%2F-MIcFl23F3mZVEkEbplX%2F-MIcGwrig9daBai1FRYF%2F11-06%20%E4%B8%80%E4%B8%AA%E5%B0%8F%E5%9E%8B%E7%9A%84%E4%BA%92%E8%81%94%E7%BD%91%E7%BB%9C.png?alt=media&token=5bcd8467-c2bb-470e-bed0-fac5b929f4e1" alt="img" style="zoom:50%;" />

图 11-6 一个小型的互联网络。三台路由器连接起两个局域网和两个广域网

通过协议互相通信：命名机制和传送机制。

图 11-7 展示了主机和路由器如何使用互联网络协议在不兼容的局域网间传送数据的一个示例。这个互联网络示例由两个局域网通过一台路由器连接而成。一个客户端运行在主机 A 上，主机 A 与 LAN1 相连，它发送一串数据字节到运行在主机 B 上的服务器端，主机 B 则连接在 LAN2 上。

<img src="https://1087580735-files.gitbook.io/~/files/v0/b/gitbook-legacy-files/o/assets%2F-MHt_spaxGgCbp2POnfq%2F-MIcFl23F3mZVEkEbplX%2F-MIcHP1NeaIedAWbfoVx%2F11-07%20%E4%BA%92%E8%81%94%E7%BD%91%E6%95%B0%E6%8D%AE%E4%BB%8E%E4%B8%80%E5%8F%B0%E4%B8%BB%E6%9C%BA%E4%BC%A0%E9%80%81%E5%88%B0%E5%8F%A6%E4%B8%80%E5%8F%B0%E4%B8%BB%E6%9C%BA.png?alt=media&token=581d6613-fcdc-4710-b94f-23b375c3423f" alt="img" style="zoom:50%;" />

过程（8个步骤）

















