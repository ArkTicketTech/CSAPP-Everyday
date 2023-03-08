#### 11.4 套接字接口

含义：**套接字接口**（socket interface）是一组函数，它们和 Unix I/O 函数结合起来，用以创建网络应用。大多数现代系统上都实现套接字接口，包括所有的 Unix 变种、Windows 和 Macintosh 系统。图 11-12 给岀了一个典型的客户端—服务器事务的上下文中的套接字接口概述。当讨论各个函数时，你可以使用这张图来作为向导图。

<img src="https://1087580735-files.gitbook.io/~/files/v0/b/gitbook-legacy-files/o/assets%2F-MHt_spaxGgCbp2POnfq%2F-MIcIVA8Oa5oAQmnqcsA%2F-MIcIpAw0dyTG0YUwyFW%2F11-12%20%E5%9F%BA%E4%BA%8E%E5%A5%97%E6%8E%A5%E5%AD%97%E6%8E%A5%E5%8F%A3%E7%9A%84%E7%BD%91%E7%BB%9C%E5%BA%94%E7%94%A8%E6%A6%82%E8%BF%B0.png?alt=media&token=74a1bb56-bc88-4cd7-afe6-0f209890a137" alt="img" style="zoom:50%;" />

> 图 11-12 基于套接字接口的网络应用概述

> ###### 旁注 - 套接字接口的起源
>
> 套接字接口是加州大学伯克利分校的研究人员在 20 世纪 80 年代早期提出的。因为这个原因，它也经常被叫做伯克利套接字。伯克利的研究者使得套接字接口适用于任何底层的协议。第一个实现的就是针对 TCP/IP 协议的，他们把它包括在 Unix 4.2 BSD 的内核里，并且分发给许多学校和实验室。这在因特网的历史上是一个重大事件。几乎一夜之间，成千上万的人们接触到了 TCP/IP 和它的源代码。它引起了巨大的轰动，并激发了新的网络和网络互联研究的浪潮。







