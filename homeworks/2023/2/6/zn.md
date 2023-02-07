#### 10.5 用RIO包健壮地读写

RIO(Robust I/O) ：健壮的`I/O`包。

功能：

1. 自动处理上文中的不足值。
2. 在容易出现不足值的应用中，RIO包提供方便、健壮和高效的`I/O`。

RIO提供了两类函数：

- 无缓冲的输入输出函数
  - 函数直接在内存和文件中传送数据，没有应用级缓冲。
  - 对将**二进制数据**读写到网络和从网络读写**二进制数据**尤其有用。
- 带缓冲的输入函数
  - 高效地从文件中读取**文本行**和**二进制数据**。
  - 这些文件的内容缓存在**应用级缓冲区**中，类似于为 `printf` 这样的标准I/O函数提供的缓冲区。
  - 是**线程安全**的（见 Chapter 12.7.1 节）。
  - 在同一个描述符上可以被交错地调用。
  - 可以从一个描述符中读一些文本行，然后读取一些二进制数据，接着再多读取一些文本行。

##### 10.5.1 RIP的无缓冲的输入输出函数

调用`rio_readn`和`rio_writen`函数，应用程序可以在内存和文件之间直接传送数据。

```c
#include <unistd.h>
// fd 文件描述符       *usrbuf 内存位置	 n 大小
ssize_t rio_readn(int fd, void *usrbuf, size_t n);
ssize_t rio_writen(int fd, void *usrbuf, size_t n);
// 返回:若成功则为写传送的字节数,若EOF则为0(只对rio_readn而言)，若出错则为-1
```

`rio_readn`函数：

+ 从描述符`fd`的当前文件位置最多传送$n$个字节到内存位置`usrbuf`。
+ 遇到EOF时只能返回一个不足值。

`rio_writen`函数：

+ 从描述符`fd`的当前文件位置最多传送$n$个字节到描述符`fd`。
+ 不会返回不足值。
+ 对同一个描述符，可以任意交错地调用`rio_readn`和`rio_writen`。

`rio_readn`函数：

```c
/*
 * rio_readn - Robustly read n bytes (unbuffered)
 */
/* $begin rio_readn */
ssize_t rio_readn(int fd, void *usrbuf, size_t n) 
{
    size_t nleft = n;
    ssize_t nread;
    char *bufp = usrbuf;

    while (nleft > 0) {
		if ((nread = read(fd, bufp, nleft)) < 0) {
	    	if (errno == EINTR) /* Interrupted by sig handler return */
				nread = 0;      /* and call read() again */
	    	else
				return -1;      /* errno set by read() */ 
			} 
		else if (nread == 0)
	    	break;              /* EOF */
		nleft -= nread;
		bufp += nread;
    	}
    	return (n - nleft);         /* Return >= 0 */
}
/* $end rio_readn */
```

`rio_writen`函数：

```c
/*
 * rio_readn - Robustly read n bytes (unbuffered)
 */
/* $begin rio_readn */
ssize_t rio_readn(int fd, void *usrbuf, size_t n) 
{
    size_t nleft = n;
    ssize_t nread;
    char *bufp = usrbuf;

    while (nleft > 0) {
		if ((nread = read(fd, bufp, nleft)) < 0) {
	    	if (errno == EINTR) /* Interrupted by sig handler return */
				nread = 0;      /* and call read() again */
	    	else
				return -1;      /* errno set by read() */ 
			} 
		else if (nread == 0)
	   		break;              /* EOF */
		nleft -= nread;
		bufp += nread;
    	}
    	return (n - nleft);         /* Return >= 0 */
}
/* $end rio_readn */
```

> 如果`rio_readn`和`rio_writen`函数被一个从应用信号处理程序的返回中断，那么每个函数会手动地重启`read`或`write`。为了尽可能有较好的可移植性，我们允许被中断的系统调用，且在必要时重启它们。

##### 10.5.2 RIO的带缓冲的输入函数

背景：假设我们要编写一个程序来计算文本文件中文本行的数量，该如何来实现呢？一种方法就是用read函数来一次一个字节地从文件传送到用户内存，检查每个字节来查找换行符。这个方法的缺点是效率不是很高，每读取文件中的一个字节都要求陷入内核。

一种更好的方法是调用一个包装函数（`rio_readlineb`），它从一个内部**读缓冲区**复制一个文本行，当缓冲区变空时，会自动地调用 read 重新填满缓冲区。对于既包含文本行也包含二进制数据的文件（例如 11.5.3 节中描述的 HTTP 响应），我们也提供了一个 rio_readn 带缓冲区的版本，叫做 `rio_readnb`，它从和 rio_readlineb 一样的读缓冲区中传送原始字节。

```c
#include "csapp.h"

void rio_readinitb(rio_t *rp, int fd);
// 返回：无。

ssize_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen);
ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n);
// 返回：若成功则为读的字节数，若 EOF 则为 0，若出错则为 -1。 
```

```c
//code/src/csapp.c
/*
 * rio_readn - Robustly read n bytes (unbuffered)
 */
/* $begin rio_readn */
ssize_t rio_readn(int fd, void *usrbuf, size_t n) 
{
    size_t nleft = n;
    ssize_t nread;
    char *bufp = usrbuf;

    while (nleft > 0) {
      if ((nread = read(fd, bufp, nleft)) < 0) {
        if (errno == EINTR) /* Interrupted by sig handler return */
          nread = 0;      /* and call read() again */
        else
          return -1;      /* errno set by read() */ 
      } 
			else if (nread == 0)
        break;              /* EOF */
			nleft -= nread;
			bufp += nread;
    }
    return (n - nleft);         /* Return >= 0 */
}
/* $end rio_readn */
```

```c
/*
 * rio_writen - Robustly write n bytes (unbuffered)
 */
/* $begin rio_writen */
ssize_t rio_writen(int fd, void *usrbuf, size_t n) 
{
    size_t nleft = n;
    ssize_t nwritten;
    char *bufp = usrbuf;

    while (nleft > 0) {
      if ((nwritten = write(fd, bufp, nleft)) <= 0) {
        if (errno == EINTR)  /* Interrupted by sig handler return */
          nwritten = 0;    /* and call write() again */
	    	else
          return -1;       /* errno set by write() */
			}
      nleft -= nwritten;
      bufp += nwritten;
    }
    return n;
}
/* $end rio_writen */
```

每打开一个描述符，都会调用一次 rio_readinitb 函数。它将描述符 fd 和地址 rp 处的一个类型为 rio_t 的读缓冲区联系起来。

rio_readlineb 函数从文件rp读出下一个文本行（包括结尾的换行符），将它复制到内存位置 usrbuf，并且用NULL（零）字符来结束这个文本行。rio_readlineb 函数最多读 **maxlen-1** 个字节，余下的一个字符留给结尾的 NULL 字符。超过 **maxlen-1** 字节的文本行被截断，并用一个 NULL 字符结束。

rio_readnb 函数从文件 rp 最多读 n 个字节到内存位置 usrbuf。对同一描述符，对 rio_readlineb 和 rio_readnb 的调用可以任意交叉进行。然而，对这些带缓冲的函数的调用却不应和无缓冲的 rio_readn 函数交叉使用。

在本书剩下的部分中将给出大量的 RIO 函数的示例。图 10-5 展示了如何使用 RIO 函数来一次一行地从标准输入复制一个文本文件到标准输出。

```c
//code/io/cpfile.c
#include "csapp.h"

int main(int argc, char **argv)
{
    int n;
    rio_t rio;
    char buf[MAXLINE];

    Rio_readinitb(&rio, STDIN_FILENO);
    while ((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0)
        Rio_writen(STDOUT_FILENO, buf, n);
}
```

下面的代码展示了一个读缓冲区的格式，以及初始化它的 rio_readinitb 函数的代码。rio_readinitb 函数创建了一个空的读缓冲区，并且将一个打开的文件描述符和这个缓冲区联系起来。

```c
#define RIO_BUFSIZE 8192
typedef struct {
    int rio_fd;                /* Descriptor for this internal buf */
    int rio_cnt;               /* Unread bytes in internal buf */
    char *rio_bufptr;          /* Next unread byte in internal buf */
    char rio_buf[RIO_BUFSIZE]; /* Internal buffer */
} rio_t;
```

```c
void rio_readinitb(rio_t *rp, int fd)
{
    rp->rio_fd = fd;
    rp->rio_cnt = 0;
    rp->rio_bufptr = rp->rio_buf;
}
```

> 一个类型为 rio_t 的读缓冲区和初始化它的 rio_readinitb 函数

RIO 读程序的核心是图 10-7 所示的 rio_read 函数。rio_read 函数是 Linux read 函数的带缓冲的版本。当调用 rio_read 要求读 n 个字节时，读缓冲区内有 **rp->rio_cnt** 个未读字节。如果缓冲区为空，那么会通过调用 read 再填满它。这个 read 调用收到一个不足值并不是错误，只不过读缓冲区是填充了一部分。一旦缓冲区非空，rio_read 就从读缓冲区复制 n 和 **rp->rio_cnt** 中较小值个字节到用户缓冲区，并返回复制的字节数。

```c
static ssize_t rio_read(rio_t *rp, char *usrbuf, size_t n)
{
    int cnt;

    while (rp->rio_cnt <= 0) {  /* Refill if buf is empty */
        rp->rio_cnt = read(rp->rio_fd, rp->rio_buf,
                           sizeof(rp->rio_buf));
        if (rp->rio_cnt < 0) {
            if (errno != EINTR) /* Interrupted by sig handler return */
                return -1;
        }
        else if (rp->rio_cnt == 0)  /* EOF */
            return 0;
        else
            rp->rio_bufptr = rp->rio_buf; /* Reset buffer ptr */
    }

    /* Copy min(n, rp->rio_cnt) bytes from internal buf to user buf */
    cnt = n;
    if (rp->rio_cnt < n)
        cnt = rp->rio_cnt;
    memcpy(usrbuf, rp->rio_bufptr, cnt);
    rp->rio_bufptr += cnt;
    rp->rio_cnt -= cnt;
    return cnt;
}
```

对于一个应用程序，rio_read 函数和 Linuxread 函数有同样的语义。在出错时，它返回值 -1，并且适当地设置 errno。在 EOF 时，它返回值 0。如果要求的字节数超过了读缓冲区内未读的字节的数量，它会返回一个不足值。两个函数的相似性使得很容易通过用 rio_read 代替 read 来创建不同类型的带缓冲的读函数。例如，用 rio_read 代替 read，图 10-8 中的 rio_readnb 函数和 rio_readn 有相同的结构。相似地，图 10-8 中的 rio_readlineb 程序最多调用 **maxlen-1** 次 rio_read。每次调用都从读缓冲区返回一个字正然后检查这个字节是否是结尾的换行符。

> RIO包的起源
>
> rio_readn和rio_written函数。

```c
ssize_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen)
{
    int n, rc;
    char c, *bufp = usrbuf;

    for (n = 1; n < maxlen; n++) {
        if ((rc = rio_read(rp, &c, 1)) == 1) {
            *bufp++ = c;
            if (c == ’\n’) {
                n++;
                break;
            }
        } else if (rc == 0) {
            if (n == 1)
                return 0; /* EOF, no data read */
            else
                break;    /* EOF, some data was read */
        } else
            return -1;    /* Error */
    }
    *bufp = 0;
    return n - 1;
}
```

```c
ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n)
{
    size_t nleft = n;
    ssize_t nread;
    char *bufp = usrbuf;

    while (nleft > 0) {
        if ((nread = rio_read(rp, bufp, nleft)) < 0)
            return -1;          /* errno set by read() */
        else if (nread == 0)
            break;              /* EOF */
        nleft -= nread;
        bufp += nread;
    }
    return (n - nleft);         /* Return >= 0 */
}
```

#### 