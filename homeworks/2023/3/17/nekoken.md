## 11.4.2 socket 函数

客户端和服务器使用 socket 函数来创建一个**套接字描述符**（socket descriptor）。

\#include <sys/types.h>

\#include <sys/socket.h>



int socket(int domain, int type, int protocol);



// 返回：若成功则为非负描述符，若出错则为 -1。



如果想要使套接字成为连接的一个端点，就用如下硬编码的参数来调用 socket 函数：

clientfd = Socket(AF_INET, SOCK_STREAM, 0);



其中，AF_INET 表明我们正在使用 32 位 IP 地址，而 SOCK_STREAM 表示这个套接字是连接的一个端点。不过最好的方法是用 getaddrinfo 函数（11.4.7 节）来自动生成这些参数，这样代码就与协议无关了。我们会在 11.4.8 节中向你展示如何配合 socket 函数来使用 getaddrinfo。

socket 返回的 clientfd 描述符仅是部分打开的，还不能用于读写。如何完成打开套接字的工作，取决于我们是客户端还是服务器。下一节描述当我们是客户端时如何完成打开套接字的工作。

## 11.4.3 connect 函数

客户端通过调用 connect 函数来建立和服务器的连接。

\#include <sys/socket.h>



int connect(int clientfd, const struct sockaddr *addr,

​            socklen_t addrlen);



// 返回：若成功则为 0，若出错则为 -1。



connect 函数试图与套接字地址为 addr 的服务器建立一个因特网连接，其中 addrlen 是 **sizeof(sockaddr_in)**。connect 函数会阻塞，一直到连接成功建立或是发生错误。如果成功，clientfd 描述符现在就准备好可以读写了，并且得到的连接是由套接字对

**(x:y, addr.sin_addr:addr.sin_port)**

刻画的，其中 x 表示客户端的 IP 地址，而 y 表示临时端口，它唯一地确定了客户端主机上的客户端进程。对于 socket，最好的方法是用 getaddrinfo 来为 connect 提供参数（见 11.4.8 节）。

## 11.4.4 bind 函数

剩下的套接字函数——bind、listen 和 accept，服务器用它们来和客户端建立连接。

\#include <sys/socket.h>



int bind(int sockfd, const struct sockaddr *addr,

​         socklen_t addrlen);



// 返回：若成功则为 0，若出错则为 -1。



bind 函数告诉内核将 addr 中的服务器套接字地址和套接字描述符 sockfd 联系起来。参数 addrlen 就是 **sizeof(sockaddr_in)**。对于 socket 和 connect，最好的方法是用 getaddrinfo 来为 bind 提供参数（见 11.4.8 节）。

## 11.4.5 listen 函数

客户端是发起连接请求的主动实体。服务器是等待来自客户端的连接请求的被动实体。默认情况下，内核会认为 socket 函数创建的描述符对应于**主动套接字**（active socket），它存在于一个连接的客户端。服务器调用 listen 函数告诉内核，描述符是被服务器而不是客户端使用的。

\#include <sys/socket.h>



int listen(int sockfd, int backlog);



// 返回：若成功则为 0，若出错则为 -1。



listen 函数将 sockfd 从一个主动套接字转化为一个**监听套接字**（listening socket），该套接字可以接受来自客户端的连接请求。backlog 参数暗示了内核在开始拒绝连接请求之前，队列中要排队的未完成的连接请求的数量。backlog 参数的确切含义要求对 TCP/IP 协议的理解，这超出了我们讨论的范围。通常我们会把它设置为一个较大的值，比如 1024。

## 11.4.6 accept 函数

服务器通过调用 accept 函数来等待来自客户端的连接请求。

\#include <sys/socket.h>



int accept(int listenfd, struct sockaddr *addr, int *addrlen);



// 返回：若成功则为非负连接描述符，若出错则为 -1。



accept 函数等待来自客户端的连接请求到达侦听描述符 listenfd，然后在 addr 中填写客户端的套接字地址，并返回一个**已连接描述符**（connected descriptor），这个描述符可被用来利用 Unix I/O 函数与客户端通信。

监听描述符和已连接描述符之间的区别使很多人感到迷惑。监听描述符是作为客户端连接请求的一个端点。它通常被创建一次，并存在于服务器的整个生命周期。已连接描述符是客户端和服务器之间已经建立起来了的连接的一个端点。服务器每次接受连接请求时都会创建一次，它只存在于服务器为一个客户端服务的过程中。

图 11-14 描绘了监听描述符和已连接描述符的角色。

![img](https://1087580735-files.gitbook.io/~/files/v0/b/gitbook-legacy-files/o/assets%2F-MHt_spaxGgCbp2POnfq%2F-MIcIVA8Oa5oAQmnqcsA%2F-MIcJ4OomcM5yziiKQoR%2F11-14%20%E7%9B%91%E5%90%AC%E6%8F%8F%E8%BF%B0%E7%AC%A6%E5%92%8C%E5%B7%B2%E8%BF%9E%E6%8E%A5%E6%8F%8F%E8%BF%B0%E7%AC%A6%E7%9A%84%E8%A7%92%E8%89%B2.png?alt=media&token=da343219-c801-4a60-bdbe-d6ef74511cec)

图 11-14 监听描述符和已连接描述符的角色

在第一步中，服务器调用 accept，等待连接请求到达监听描述符，具体地我们设定为描述符 3。回忆一下，描述符 0 ~ 2 是预留给了标准文件的。

在第二步中，客户端调用 connect 函数，发送一个连接请求到 listenfd。第三步，accept 函数打开了一个新的已连接描述符 connfd（我们假设是描述符 4），在 clientfd 和 connfd 之间建立连接，并且随后返回 connfd 给应用程序。客户端也从 connect 返回，在这一点以后，客户端和服务器就可以分别通过读和写 clientfd 和 connfd 来回传送数据了。



#### 旁注 - 为何要有监听描述符和已连接描述符之间的区别？

你可能很想知道为什么套接字接口要区别监听描述符和已连接描述符。乍一看，这像是不必要的复杂化。然而，区分这两者被证明是很有用的，因为它使得我们可以. 建立并发服务器，它能够同时处理许多客户端连接。例如，每次一个连接请求到达监听描述符时，我们可以派生（fork）—个新的进程，它通过已连接描述符与客户端通信。在第 12 章中将介绍更多关于并发服务器的内容。

## 11.4.7 主机和服务的转换

Linux 提供了一些强大的函数（称为 getaddrinfo 和 getnameinfo）实现二进制套接字地址结构和主机名、主机地址、服务名和端口号的字符串表示之间的相互转化。当和套接字接口一起使用时，这些函数能使我们编写独立于任何特定版本的 IP 协议的网络程序。

### 1. getaddrinfo 函数

getaddrinfo 函数将主机名、主机地址、服务名和端口号的字符串表示转化成套接字地址结构。它是已弃用的 gethostbyname 和 getservbyname 函数的新的替代品。和以前的那些函数不同，这个函数是可重入的（见 12.7.2 节），适用于任何协议。

\#include <sys/types.h>

\#include <sys/socket.h>

\#include <netdb.h>



int getaddrinfo(const char *host, const char *service,

​                const struct addrinfo *hints,

​                struct addrinfo **result);

// 返回：如果成功则为 0，如果错误则为非零的错误代码。



void freeaddrinfo(struct addrinfo *result);

// 返回：无。



const char *gai_strerror(int errcode);

// 返回：错误消息。



给定 host 和 service（套接字地址的两个组成部分），getaddrinfo 返回 result，result 一个指向 addrinfo 结构的链表，其中每个结构指向一个对应于 host 和 service 的套接字地址结构（图 11-15）。

![img](https://1087580735-files.gitbook.io/~/files/v0/b/gitbook-legacy-files/o/assets%2F-MHt_spaxGgCbp2POnfq%2F-MIcIVA8Oa5oAQmnqcsA%2F-MIcJMMTidPi7RGtFpUs%2F11-15%20getaddrinfo%E8%BF%94%E5%9B%9E%E7%9A%84%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84.png?alt=media&token=c46bc609-da0f-40ba-ace2-825dd9230d80)

图 11-15 getaddrinfo 返回的数据结构

在客户端调用了 getaddrinfo 之后，会遍历这个列表，依次尝试每个套接字地址，直到调用 socket 和 connect 成功，建立起连接。类似地，服务器会尝试遍历列表中的每个套接字地址，直到调用 socket 和 bind 成功，描述符会被绑定到一个合法的套接字地址。为了避免内存泄漏，应用程序必须在最后调用 freeaddrinfo，释放该链表。如果 getaddrinfo 返回非零的错误代码，应用程序可以调用 gai_streeror，将该代码转换成消息字符串。

getaddrinfo 的 host 参数可以是域名，也可以是数字地址（如点分十进制 IP 地址）。service 参数可以是服务名（如 http），也可以是十进制端口号。如果不想把主机名转换成地址，可以把 host 设置为 NULL。对 service 来说也是一样。但是必须指定两者中至少一个。

可选的参数 hints 是一个 addrinfo 结构（见图 11-16），它提供对 getaddrinfo 返回的套接字地址列表的更好的控制。

code/netp/netfragments.c

struct addrinfo {

​    int             ai_flags;      /* Hints argument flags */

​    int             ai_family;     /* First arg to socket function */

​    int             ai_socktype;   /* Second arg to socket function */

​    int             ai_protocol;   /* Third arg to socket function */

​    char            *ai_canonname; /* Canonical hostname */

​    size_t          ai_addrlen;    /* Size of ai_addr struct */

​    struct sockaddr *ai_addr;      /* Ptr to socket address structure */

​    struct addrinfo *ai_next;      /* Ptr to next item in linked list */

};



> 图 11-16 getaddrinfo 使用的 addrinfo 结构

如果要传递 hints 参数，只能设置下列字段：ai_family、ai_socktype、ai_protocol 和 ai_flags 字段。其他字段必须设置为 0（或 NULL）。实际中，我们用 memset 将整个结而清零，然后有选择地设置一些字段：

+ 

  getaddrinfo 默认可以返回 IPv4 和 IPv6 套接字地址。ai_family 设置为 AF_INET 会将列表限制为 IPv4 地址；设置为 AF_INET6 则限制为 IPv6 地址。

+ 

  对于 host 关联的每个地址，getaddrinfo 函数默认最多返回三个 addrinfo 结构，每个的 ai_socktype 字段不同：一个是连接，一个是数据报（本书未讲述），一个是原始套接字（本书未讲述）。ai_socktype 设置为 SOCK_STREAM 将列表限制为对每个地址最多一个 addrinfo 结构，该结构的套接字地址可以作为连接的一个端点。这是所有示例程序所期望的行为。

+ 

  ai_flags 字段是一个位掩码，可以进一步修改默认行为。可以把各种值用 OR 组合起来得到该掩码。下面是一些我们认为有用的值：

  + 

    **AI_ADDRCONFIG。**如果在使用连接，就推荐使用这个标志【34】。它要求只有当本地主机被配置为 IPv4 时，getaddrinfo 返回 IPv4 地址。对 IPv6 也是类似。

  + 

    **AI_CANONNAME。**ai_canonname 字段默认为 NULL。如果设置了该标志，就是告诉 getaddrinfo 将列表中第一个 addrinfo 结构的 ai_canonname 字段指向 host 的权威（官方）名字（见图 11-15）。

  + 

    **AI_NUMERICSERV。**参数 service 默认可以是服务名或端口号。这个标志强制参数 service 为端口号。

  + 

    **AI_PASSIVE。**getaddrinfo 默认返回套接字地址，客户端可以在调用 connect 时用作主动套接字。这个标志告诉该函数，返回的套接字地址可能被服务器用作监听套接字。在这种情况中，参数 host 应该为 NULL。得到的套接字地址结构中的地址字段会是通配符地址（wildcard address），告诉内核这个服务器会接受发送到该主机所有 IP 地址的请求。这是所有示例服务器所期望的行为。

当 getaddrinfo 创建输出列表中的 addrinfo 结构时，会填写每个字段，除了 ai_flags。ai_addr 字段指向一个套接字地址结构，ai_addrlen 字段给出这个套接字地址结构的大小，而 ai_next 字段指向列表中下一个 addrinfo 结构。其他字段描述这个套接字地址的各种属性。

getaddrinfo 一个很好的方面是 addrinfo 结构中的字段是不透明的，即它们可以直接传递给套接字接口中的函数，应用程序代码无需再做任何处理。例如，ai_family、ai_socktype 和 ai_protocol 可以直接传递给 socket。类似地，ai_addr 和 ai_addrlen 可以直接传递给 connect 和 bind。这个强大的属性使得我们编写的客户端和服务器能够独立于某个特殊版本的 IP 协议。

### 2. getnameinfo 函数

getnameinfo 函数和 getaddrinfo 是相反的，将一个套接字地址结构转换成相应的主机和服务名字符串。它是已弃用的 gethostbyaddr 和 getservbyport 函数的新的替代品，和以前的那些函数不同，它是可重入和与协议无关的。

\#include <sys/socket.h>

\#include <netdb.h>



int getnameinfo(const struct sockaddr *sa, socklen_t salen,

​                char *host, size_t hostlen,

​                char *service, size_t servlen, int flags);



// 返回：如果成功则为 0，如果错误则为非零的错误代码。 



参数 sa 指向大小为 salen 字节的套接字地址结构，host 指向大小为 hostlen 字节的缓冲区，service 指向大小为 servlen 字节的缓冲区。getnameinfo 函数将套接字地址结构 sa 转换成对应的主机和服务名字符串，并将它们复制到 host 和 serveice 缓冲区。如果 getnameinfo 返回非零的错误代码，应用程序可以调用 gai_strerror 把它转化成字符串。

如果不想要主机名，可以把 host 设置为 NULL，hostlen 设置为 0。对服务字段来说也是一样。不过，两者必须设置其中之一。

参数 flags 是一个位掩码，能够修改默认的行为。可以把各种值用 OR 组合起来得到该掩码。下面是两个有用的值：

+ 

  **NI_NUMERICHOST。**getnameinfo 默认试图返回 host 中的域名。设置该标志会使该函数返回一个数字地址字符串。

+ 

  **NI_NUMERICSERV。**getnameinfo 默认会检查 **/etc/services**，如果可能，会返回服务名而不是端口号。设置该标志会使该函数跳过査找，简单地返回端口号。

图 11-17 给出了一个简单的程序，称为 HOSTINFO，它使用 getaddrinfo 和 getnameinfo 展示出域名到和它相关联的 IP 地址之间的映射。该程序类似于 11.3.2 节中的 NSLOOKUP 程序。

code/netp/hostinfo.c

\#include "csapp.h"



int main(int argc, char **argv)

{

​    struct addrinfo *p, *listp, hints;

​    char buf[MAXLINE];

​    int rc, flags;



​    if (argc != 2) {

​        fprintf(stderr, "usage: %s <domain name>\n", argv[0]);

​        exit(0);

​    }



​    /* Get a list of addrinfo records */

​    memset(&hints, 0, sizeof(struct addrinfo));

​    hints.ai_family = AF_INET;       /* IPv4 only */

​    hints.ai_socktype = SOCK_STREAM; /* Connections only */

​    if ((rc = getaddrinfo(argv[1], NULL, &hints, &listp)) != 0) {

​        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(rc));

​        exit(1);

​    }



​    /* Walk the list and display each IP address */

​    flags = NI_NUMERICHOST; /* Display address string instead of domain name */

​    for (p = listp; p; p = p->ai_next) {

​        Getnameinfo(p->ai_addr, p->ai_addrlen, buf, MAXLINE, NULL, 0, flags);

​        printf("%s\n", buf);

​    }



​    /* Clean up */

​    Freeaddrinfo(listp);



​    exit(0);

}



> 图 11-17 HOSTINFO 展示出域名到和它相关联的 IP 地址之间的映射

首先，初始化 hints 结构，使 getaddrinfo 返回我们想要的地址。在这里，我们想查找 32 位的 IP 地址（第 16 行），用作连接的端点（第 17 行）。因为只想 getaddrinfo 转换域名，所以用 service 参数为 NULL 来调用它。

调用 getaddrinfo 之后，会遍历 addrinfo 结构，用 getnameinfo 将每个套接字地址转换成点分十进制地址字符串。遍历完列表之后，我们调用 freeaddrinf。小心地释放这个列表（虽然对于这个简单的程序来说，并不是严格需要这样做的）。

运行 HOSTINFO 时，我们看到 twitter.com 映射到了四个 IP 地址，和 11.3.2 节用 NSLOOKUP 的结果一样。

linux> ./hostinfo twitter.com

199.16.156.102

199.16.156.230

199.16.156.6

199.16.156.70



#### 练习题 11.4

练习题 11.4

函数 getaddrinfo 和 getnameinfo 分别包含了 inet_pton 和 inet_ntop 的功能，提供了更高级别的、独立于任何特殊地址格式的抽象。想看看这到底有多方便，编写 HOSTINFO（图 11-17）的一个版本，用 inet_pton 而不是 getnameinfo 将毎个套接字地址转换成点分十进制地址字符串。

答案

下面是解决方案。注意，使用 inet_ntop 要困难多少，它要求很麻烦的强制类型转换和深层嵌套结构引用。getnameinfo 函数要简单许多，因为它为我们完成了这些工作。

code/netp/hostinfo-ntop.c

\#include "csapp.h"



int main(int argc, char **argv)

{

​    struct addrinfo *p, *listp, hints;

​    struct sockaddr_in *sockp;

​    char buf[MAXLINE];

​    int rc;



​    if (argc != 2) {

​        fprintf(stderr, "usage: %s <domain name>\n", argv[0]);

​        exit(0);

​    }



​    /* Get a list of addrinfo records */

​    memset(&hints, 0, sizeof(struct addrinfo));

​    hints.ai_family = AF_INET;       /* IPv4 only */

​    hints.ai_socktype = SOCK_STREAM; /* Connections only */

​    if ((rc = getaddrinfo(argv[1], NULL, &hints, &listp)) != 0) {

​        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(rc));

​        exit(1);

​    }



​    /* Walk the list and display each associated IP address */

​    for (p = listp; p; p = p->ai_next) {

​        sockp = (struct sockaddr_in *)p->ai_addr;

​        Inet_ntop(AF_INET, &(sockp->sin_addr), buf, MAXLINE);

​        printf("%s\n", buf);

​    }



​    /* Clean up */

​    Freeaddrinfo(listp);



​    exit(0);

}



## 11.4.8 套接字接口的辅助函数

初学时，getnameinfo 函数和套接字接口看上去有些可怕。用高级的辅助函数包装一下会方便很多，称为 open_clientfd 和 open_listenfd，客户端和服务器互相通信时可以使用这些函数。

### 1. open_clientfd 函数

客户端调用 open_clientfd 建立与服务器的连接。

\#include "csapp.h"



int open_clientfd(char *hostname, char *port);



// 返回：若成功则为描述符，若出错则为 -1。



open_clientfd 函数建立与服务器的连接，该服务器运行在主机 hostname 上，并在端口号 port 上监听连接请求。它返回一个打开的套接字描述符，该描述符准备好了，可以用 Unix I/O 函数做输入和输出。图 11-18 给出了 open_clientfd 的代码。

code/src/csapp.c

int open_clientfd(char *hostname, char *port) {

​    int clientfd;

​    struct addrinfo hints, *listp, *p;



​    /* Get a list of potential server addresses */

​    memset(&hints, 0, sizeof(struct addrinfo));

​    hints.ai_socktype = SOCK_STREAM;  /* Open a connection */

​    hints.ai_flags = AI_NUMERICSERV;  /* ... using a numeric port arg. */

​    hints.ai_flags |= AI_ADDRCONFIG;  /* Recommended for connections */

​    Getaddrinfo(hostname, port, &hints, &listp);



​    /* Walk the list for one that we can successfully connect to */

​    for (p = listp; p; p = p->ai_next) {

​        /* Create a socket descriptor */

​        if ((clientfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0)

​            continue; /* Socket failed, try the next */



​        /* Connect to the server */

​        if (connect(clientfd, p->ai_addr, p->ai_addrlen) != -1)

​            break; /* Success */

​        Close(clientfd); /* Connect failed, try another */

​    }



​    /* Clean up */

​    Freeaddrinfo(listp);

​    if (!p) /* All connects failed */

​        return -1;

​    else    /* The last connect succeeded */

​        return clientfd;

}



> 图 11-18 open_clientfd：和服务器建立连接的辅助函数。它是可重入和与协议无关的

我们调用 getaddrinfo，它返回 addrinf。结构的列表，每个结构指向一个套接字地址结构，可用于建立与服务器的连接，该服务器运行在 hostname 上并监听 port 端口。然后遍历该列表，依次尝试列表中的每个条目，直到调用 socket 和 connect 成功。如果 connect 失败，在尝试下一个条目之前，要小心地关闭套接字描述符。如果 connect 成功，我们会释放列表内存，并把套接字描述符返回给客户端，客户端可以立即开始用 Unix I/O 与服务器通信了。

注意，所有的代码都与任何版本的 IP 无关。socket 和 connect 的参数都是用 getaddrinfo 自动产生的，这使得我们的代码干净可移植。

### 2. open_listenfd 函数

调用 open_listenfd 函数，服务器创建一个监听描述符，准备好接收连接请求。

\#include "csapp.h"



int open_listenfd(char *port);



// 返回：若成功则为描述符，若出错则为 -1。



open_listenfd 函数打开和返回一个监听描述符，这个描述符准备好在端口 port_h 接收连接请求。图 11-19 展示了 open_listenfd 的代码。

code/src/csapp.c

int open_listenfd(char *port)

{

​    struct addrinfo hints, *listp, *p;

​    int listenfd, optval = 1;



​    /* Get a list of potential server addresses */

​    memset(&hints, 0, sizeof(struct addrinfo));

​    hints.ai_socktype = SOCK_STREAM;             /* Accept connections */

​    hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG; /* ... on any IP address */

​    hints.ai_flags |= AI_NUMERICSERV;            /* ... using port number */

​    Getaddrinfo(NULL, port, &hints, &listp);



​    /* Walk the list for one that we can bind to */

​    for (p = listp; p; p = p->ai_next) {

​        /* Create a socket descriptor */

​        if ((listenfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0)

​            continue; /* Socket failed, try the next */



​        /* Eliminates "Address already in use" error from bind */

​        Setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR,

​                   (const void *)&optval , sizeof(int));



​        /* Bind the descriptor to the address */

​        if (bind(listenfd, p->ai_addr, p->ai_addrlen) == 0)

​            break; /* Success */

​        Close(listenfd); /* Bind failed, try the next */

​    }



​    /* Clean up */

​    Freeaddrinfo(listp);

​    if (!p) /* No address worked */

​        return -1;



​    /* Make it a listening socket ready to accept connection requests */

​    if (listen(listenfd, LISTENQ) < 0) {

​        Close(listenfd);

​        return -1;

​    }

​    return listenfd;

}



> 图 11-19 open_listenfd：打开并返回监听描述符的辅助函数。它是可重入和与协议无关的

open_listenfd 的风格类似于 open_clientfd。调用 getaddrinfo，然后遍历结果列表，直到调用 socket 和 bind 成功。注意，在第 20 行，我们使用 setsockopt 函数（本书中没有讲述）来配置服务器，使得服务器能够被终止、重启和立即开始接收连接请求。一个重启的服务器默认将在大约 30 秒内拒绝客户端的连接请求，这严重地阻碍了调试。

因为我们调用 getaddrinfo 时，使用了 AI_PASSIVE 标志并将 host 参数设置为 NULL，每个套接字地址结构中的地址字段会被设置为通配符地址，这告诉内核这个服务器会接收发送到本主机所有 IP 地址的请求。

最后，我们调用 listen 函数，将 listenfd 转换为一个监听描述符，并返回给调用者。如果 listen 失败，我们要小心地避免内存泄漏，在返回前关闭描述符。

## 11.4.9 echo 客户端和服务器的示例

学习套接字接口的最好方法是研究示例代码。图 11-20 展示了一个 echo 客户端的代码。

code/netp/echoclient.c

\#include "csapp.h"



int main(int argc, char **argv)

{

​    int clientfd;

​    char *host, *port, buf[MAXLINE];

​    rio_t rio;



​    if (argc != 3) {

​        fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);

​        exit(0);

​    }

​    host = argv[1];

​    port = argv[2];



​    clientfd = Open_clientfd(host, port);

​    Rio_readinitb(&rio, clientfd);



​    while (Fgets(buf, MAXLINE, stdin) != NULL) {

​        Rio_writen(clientfd, buf, strlen(buf));

​        Rio_readlineb(&rio, buf, MAXLINE);

​        Fputs(buf, stdout);

​    }

​    Close(clientfd);

​    exit(0);

}



> 图 11-20 echo 客户端的主程序

在和服务器建立连接之后，客户端进入一个循环，反复从标准输入读取文本行，发送文本行给服务器，从服务器读取回送的行，并输出结果到标准输出。当 fgets 在标准输入上遇到 EOF 时，或者因为用户在键盘上键入 Ctrl+D，或者因为在一个重定向的输入文件中用尽了所有的文本行时，循环就终止。

循环终止之后，客户端关闭描述符。这会导致发送一个 EOF 通知到服务器，当服务器从它的 reo_readlineb 函数收到一个为零的返回码时，就会检测到这个结果。在关闭它的描述符后，客户端就终止了。既然客户端内核在一个进程终止时会自动关闭所有打开的描述符，第 24 行的 close 就没有必要了。不过，显式地关闭已经打开的任何描述符是一个良好的编程习惯。

图 11-21 展示了 echo 服务器的主程序。

code/netp/echoserveri.c

\#include "csapp.h"



void echo(int connfd);



int main(int argc, char **argv)

{

​    int listenfd, connfd;

​    socklen_t clientlen;

​    struct sockaddr_storage clientaddr; /* Enough space for any address */

​    char client_hostname[MAXLINE], client_port[MAXLINE];



​    if (argc != 2) {

​        fprintf(stderr, "usage: %s <port>\n", argv[0]);

​        exit(0);

​    }

​    

​    listenfd = Open_listenfd(argv[1]);

​    while (1) {

​        clientlen = sizeof(struct sockaddr_storage);

​        connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);

​        Getnameinfo((SA *) &clientaddr, clientlen, client_hostname, MAXLINE,

​                    client_port, MAXLINE, 0);

​        printf("Connected to (%s, %s)\n", client_hostname, client_port);

​        echo(connfd);

​        Close(connfd);

​    }

​    exit(0);

}



> 图 11-21 迭代 echo 服务器的主程序

在打开监听描述符后，它进入一个无限循环。每次循环都等待一个来自客户端的连接请求，输出已连接客户端的域名和 IP 地址，并调用 echo 函数为这些客户端服务。在 echo 程序返回后，主程序关闭已连接描述符。一旦客户端和服务器关闭了它们各自的描述符，连接也就终止了。

第 9 行的 clientaddr 变量是一个套接字地址结构，被传递给 accept。在 accept 返回之前，会在 clientaddr 中填上连接另一端客户端的套接字地址。注意，我们将 clientaddr 声明为 **struct sockaddr_storage** 类型，而不是 **struct sockaddr_in** 类型。根据定义，sockaddr_storage 结构足够大能够装下任何类型的套接字地址，以保持代码的协议无关性。

注意，简单的 echo 服务器一次只能处理一个客户端。这种类型的服务器一次一个地在客户端间迭代，称为**迭代服务器**（iterative server）。在第 12 章中，我们将学习如何建立更加复杂的**并发服务器**（concurrent server），它能够同时处理多个客户端。

最后，图 11-22 展示了 echo 程序的代码，该程序反复读写文本行，直到 rio_readlineb 函数在第 10 行遇到 EOF。

code/netp/echo.c

\#include "csapp.h"



void echo(int connfd)

{

​    size_t n;

​    char buf[MAXLINE];

​    rio_t rio;



​    Rio_readinitb(&rio, connfd);

​    while ((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) {

​        printf("server received %d bytes\n", (int)n);

​        Rio_writen(connfd, buf, n);

​    }

}



> 图 11-22 读和回送文本行的 echo 函数



#### 旁注 - 在连接中 EOF 意味什么？

EOF 的概念常常使人们感到迷惑，尤其是在因特网连接的上下文中。首先，我们需要理解其实并没有像 EOF 字符这样的一个东西。进一步来说，EOF 是由内核检测到的一种条件。应用程序在它接收到一个由 read 函数返回的零返回码时，它就会发现出 EOF 条件。对于磁盘文件，当前文件位置超出文件长度时，会发生 EOF。对于因特网连接，当一个进程关闭连接它的那一端时，会发生 EOF。连接另一端的进程在试图读取流中最后一个字节之后的字节时，会检测到 EOF。
