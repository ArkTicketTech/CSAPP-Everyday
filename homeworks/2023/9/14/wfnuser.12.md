- # 12.1 基于进程的并发编程  
	- 使用 forkexecwaitpid 等函数创建并控制进程进行并发，一个简单的例子是，并发服务器父进程接受客户端连接，随后创建子进程为客户端提供服务  
	- 因为父、子进程中的已连接描述符都指向同一个文件表表项，所以父进程关闭它的已连接描述符的副本是至关重要的  
	-  
	  ``` c
	  	  #include "csapp.h"
	  	  void echo(int connfd);
	  	  
	  	  void sigchld_handler(int sig)
	  	  {
	  	      while (waitpid(-1, 0, WNOHANG) > 0)
	  	          ;
	  	      return;
	  	  }
	  	  
	  	  int main(int argc, char **argv)
	  	  {
	  	      int listenfd, connfd;
	  	      socklen_t clientlen;
	  	      struct sockaddr_storage clientaddr;
	  	  
	  	      if (argc != 2) {
	  	          fprintf(stderr, "usage: %s <port>\n", argv[0]);
	  	          exit(0);
	  	      }
	  	  
	  	      Signal(SIGCHLD, sigchld_handler);
	  	      listenfd = Open_listenfd(argv[1]);
	  	      while (1) {
	  	          clientlen = sizeof(struct sockaddr_storage);
	  	          connfd = Accept(listenfd, (SA *) &clientaddr, &clientlen);
	  	          if (Fork() == 0) {
	  	              Close(listenfd); /* Child closes its listening socket */
	  	              echo(connfd);    /* Child services client */
	  	              Close(connfd);   /* Child closes connection with client */
	  	              exit(0);         /* Child exits */
	  	          }
	  	          Close(connfd); /* Parent closes connected socket (important!) */
	  	      }
	  	  }
	  ```
- # 12.2 基于 I/O 多路复用的并发编程  
	- 困境  
		-  
		  > 假设要求你编写一个 echo 服务器，它也能对用户从标准输入键入的交互命令做出响应。在这种情况下，服务器必须响应两个互相独立的 I/O 事件：1）网络客户端发起连接请求，2）用户在键盘上键入命令行。我们先等待哪个事件呢？没有哪个选择是理想的。如果在 accept 中等待一个连接请求，我们就不能响应输入的命令。类似地，如果在 read 中等待一个输入命令，我们就不能响应任何连接请求。  

	- 解决方案就是 I/O 多路复用技术  
		- 使用 select 函数，要求内核挂起进程，只有在一个或多个I/O 事件发生后，才将控制返回给应用程序。 select 函数会一直阻塞，直到读集合中至少有一个描述符准备好可以读。  
		-  
		  ``` c
		  		  #include <sys/select.h>
		  		  
		  		  int select(int n, fd_set *fdset, NULL, NULL, NULL);
		  		  // 返回已准备好的描述符的非零的个数，若出错则为 -1。
		  		  
		  		  FD_ZERO(fd_set *fdset);           /* Clear all bits in fdset */
		  		  FD_CLR(int fd, fd_set *fdset);    /* Clear bit fd in fdset */
		  		  FD_SET(int fd, fd_set *fdset);    /* Turn on bit fd in fdset */
		  		  FD_ISSET(int fd, fd_set *fdset);  /* Is bit fd in fdset on? */
		  		  // 处理描述符集合的宏。
		  ```
	-  
	  ``` c
	  	  // select 实现 echo 服务器
	  	  
	  	  #include "csapp.h"
	  	  void echo(int connfd);
	  	  void command(void);
	  	  
	  	  int main(int argc, char **argv)
	  	  {
	  	      int listenfd, connfd;
	  	      socklen_t clientlen;
	  	      struct sockaddr_storage clientaddr;
	  	      fd_set read_set, ready_set;
	  	      
	  	      if (argc != 2) {
	  	          fprintf(stderr, "usage: %s <port>\n", argv[0]);
	  	          exit(0);
	  	      }
	  	      listenfd = Open_listenfd(argv[1]);
	  	      
	  	      FD_ZERO(&read_set);              /* Clear read set */
	  	      FD_SET(STDIN_FILENO, &read_set); /* Add stdin to read set */
	  	      FD_SET(listenfd, &read_set);     /* Add listenfd to read set */
	  	  
	  	      while (1) {
	  	          ready_set = read_set;
	  	          Select(listenfd + 1, &ready_set, NULL, NULL, NULL);
	  	          if (FD_ISSET(STDIN_FILENO, &ready_set))
	  	              command(); /* Read command line from stdin */
	  	          if (FD_ISSET(listenfd, &ready_set)) {
	  	              clientlen = sizeof(struct sockaddr_storage);
	  	              connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
	  	              echo(connfd); /* Echo client input until EOF */
	  	              Close(connfd);
	  	          }
	  	      }
	  	  }
	  	  
	  	  void command(void) {
	  	      char buf[MAXLINE];
	  	      if (!Fgets(buf, MAXLINE, stdin))
	  	          exit(0); /* EOF */
	  	      printf("%s", buf); /* Process the input command */
	  	  }
	  ```
	- 基于 I/O 多路复用的并发事件驱动服务器  
		-  
		  ``` c
		  		  #include "csapp.h"
		  		  
		  		  typedef struct { /* Represents a pool of connected descriptors */
		  		      int maxfd;        /* Largest descriptor in read_set */
		  		      fd_set read_set;  /* Set of all active descriptors */
		  		      fd_set ready_set; /* Subset of descriptors ready for reading */
		  		      int nready;       /* Number of ready descriptors from select */
		  		      int maxi;         /* High water index into client array */
		  		      int clientfd[FD_SETSIZE];    /* Set of active descriptors */
		  		      rio_t clientrio[FD_SETSIZE]; /* Set of active read buffers */
		  		  } pool;
		  		  
		  		  int byte_cnt = 0; /* Counts total bytes received by server */
		  		  
		  		  int main(int argc, char **argv)
		  		  {
		  		      int listenfd, connfd;
		  		      socklen_t clientlen;
		  		      struct sockaddr_storage clientaddr;
		  		      static pool pool;
		  		  
		  		      if (argc != 2) {
		  		          fprintf(stderr, "usage: %s <port>\n", argv[0]);
		  		          exit(0);
		  		      }
		  		      listenfd = Open_listenfd(argv[1]);
		  		      init_pool(listenfd, &pool);
		  		  
		  		      while (1) {
		  		          /* Wait for listening/connected descriptor(s) to become ready */
		  		          pool.ready_set = pool.read_set;
		  		          pool.nready = Select(pool.maxfd + 1, &pool.ready_set, NULL, NULL, NULL);
		  		          
		  		          /* If listening descriptor ready, add new client to pool */
		  		          if (FD_ISSET(listenfd, &pool.ready_set)) {
		  		              clientlen = sizeof(struct sockaddr_storage);
		  		              connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
		  		              add_client(connfd, &pool);
		  		          }
		  		          
		  		          /* Echo a text line from each ready connected descriptor */
		  		          check_clients(&pool);
		  		      }
		  		  }
		  		  
		  		  void init_pool(int listenfd, pool *p)
		  		  {
		  		      /* Initially, there are no connected descriptors */
		  		      int i;
		  		      p->maxi = -1;
		  		      for (i = 0; i < FD_SETSIZE; i++)
		  		          p->clientfd[i] = -1;
		  		      
		  		      /* Initially, listenfd is only member of select read set */
		  		      p->maxfd = listenfd;
		  		      FD_ZERO(&p->read_set);
		  		      FD_SET(listenfd, &p->read_set);
		  		  }
		  		  
		  		  void add_client(int connfd, pool *p)
		  		  {
		  		      int i;
		  		      p->nready--;
		  		      for (i = 0; i < FD_SETSIZE; i++) /* Find an available slot */
		  		          if (p->clientfd[i] < 0) {
		  		              /* Add connected descriptor to the pool */
		  		              p->clientfd[i] = connfd;
		  		              Rio_readinitb(&p->clientrio[i], connfd);
		  		  
		  		              /* Add the descriptor to descriptor set */
		  		              FD_SET(connfd, &p->read_set);
		  		  
		  		              /* Update max descriptor and pool high water mark */
		  		              if (connfd > p->maxfd)
		  		                  p->maxfd = connfd;
		  		              if (i > p->maxi)
		  		                  p->maxi = i;
		  		              break;
		  		          }
		  		      if (i == FD_SETSIZE) /* Couldn’t find an empty slot */
		  		          app_error("add_client error: Too many clients");
		  		  }
		  		  
		  		  void check_clients(pool *p)
		  		  {
		  		      int i, connfd, n;
		  		      char buf[MAXLINE];
		  		      rio_t rio;
		  		  
		  		      for (i = 0; (i <= p->maxi) && (p->nready > 0); i++) {
		  		          connfd = p->clientfd[i];
		  		          rio = p->clientrio[i];
		  		  
		  		          /* If the descriptor is ready, echo a text line from it */
		  		          if ((connfd > 0) && (FD_ISSET(connfd, &p->ready_set))) {
		  		              p->nready--;
		  		              if ((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) {
		  		                  byte_cnt += n;
		  		                  printf("Server received %d (%d total) bytes on fd %d\n",
		  		                         n, byte_cnt, connfd);
		  		                  Rio_writen(connfd, buf, n);
		  		              }
		  		  
		  		              /* EOF detected, remove descriptor from pool */
		  		              else {
		  		                  Close(connfd);
		  		                  FD_CLR(connfd, &p->read_set);
		  		                  p->clientfd[i] = -1;
		  		              }
		  		          }
		  		      }
		  		  }
		  ```
- # 12.3 基于线程的并发模型  
	- 基于进程的并发模型，每个进程有自己的私有地址空间，流数据共享变得困难；基于事件的并发模型创建了逻辑流，利用 I/O 多路复用机制来调度流，因为只有一个进程，所有流共享地址空间。本节介绍的机遇线程的方法则是两种方式的混合。  
	- 线程 thread  
		- 线程由内核自动调度  
		- 每个线程都有它自己的**线程上下文**（thread context），包括一个唯一的整数**线程 ID**（Thread ID，TID）、栈、栈指针、程序计数器、通用目的寄存器和条件码  
		- 所有的运行在一个进程里的线程共享该进程的整个虚拟地址空间  
			- 因此共享这个进程虚拟地址空间的所有内容，包括它的代码、数据、堆、共享库和打开的文件  
	- ## 12.3.1 线程执行模型  
		- 线程是如何切换的？ #card #[[computer science]]  
			- 每个进程开始生命周期时都是单一线程，这个线程称为**主线程**（main thread）。在某一时刻，主线程创建一个**对等线程**（peer thread），从这个时间点开始，两个线程就并发地运行。最后，因为主线程执行一个慢速系统调用，例如 read 或者 sleep，或者因为被系统的间隔计时器中断，控制就会通过上下文切换传递到对等线程。对等线程会执行一段时间，然后控制传递回主线程，依次类推。  
		- ![image.png](../assets/image_1694769130314_0.png)  
		- 线程的上下文比进程小的多，因此切换也快的多。  
	- ## 12.3.2 Posix 线程  
		- pthread - posix thread  
			-  
			  ``` c
			  			  // 例子
			  			  #include "csapp.h"
			  			  void *thread(void *vargp);
			  			  
			  			  int main()
			  			  {
			  			      pthread_t tid;
			  			      Pthread_create(&tid, NULL, thread, NULL);
			  			      Pthread_join(tid, NULL);
			  			      exit(0);
			  			  }
			  			  
			  			  void *thread(void *vargp) /* Thread routine */
			  			  {
			  			      printf("Hello, world!\n");
			  			      return NULL;
			  			  }
			  ```
	- ## 12.3.3 创建线程  
		-  
		  ``` c
		  		  #include <pthread.h>
		  		  typedef void *(func)(void *);
		  		  
		  		  int pthread_create(pthread_t *tid, pthread_attr_t *attr,
		  		                     func *f, void *arg);
		  		  // 若成功则返回 0，若出错则为非零。
		  		  
		  		  pthread_t pthread_self(void);
		  		  // 返回调用者的线程 ID。
		  ```
		- arg 表示传入参数； attr 参数改变新创建线程的默认属性；新线程上下文中运行线程例程 f  
	- ## 12.3.4 终止线程  
		- 线程终止的方式  
			- 顶层线程实例返回时，线程会隐式终止  
			- 通过调用 pthread_exit 函数，线程会**显式地**终止。如果主线程调用 pthread_exit，它会等待所有其他对等线程终止，然后再终止主线程和整个进程，返回值为 thread_return  
				-  
				  ``` c
				  				  #include <pthread.h>
				  				  
				  				  void pthread_exit(void *thread_return);
				  				  
				  				  // 从不返回。
				  ```
			- 某个对等线程调用 Linux 的 exit 函数，该函数终止进程以及所有与该进程相关的线程。  
			- 另一个对等线程通过以当前线程 ID 作为参数调用 pthread_Cancel 函数来终止当前线程。  
				-  
				  ``` c
				  				  #include <pthread.h>
				  				  
				  				  int pthread_cancel(pthread_t tid);
				  				  
				  				  // 若成功则返回 0，若出错则为非零。
				  ```
	- ## 12.3.5 回收已终止线程的资源  
		- 线程通过调用 pthread_join 函数等待其他线程终止  
		- pthread_join 函数会阻塞，直到线程 tid 终止，将线程例程返回的通用** (void*) **指针赋值为 thread_return 指向的位置，然后回收已终止线程占用的所有内存资源  
		-  
		  ``` c
		  		  #include <pthread.h>
		  		  
		  		  int pthread_join(pthread_t tid, void **thread_return);
		  		  
		  		  // 若成功则返回 0，若出错则为非零。
		  ```
	- ## 12.3.6 分离线程  
		- 在任何一个时间点上，线程是可结合的（joinable），或者是分离的（detached）。  
		- 一个 joinable 线程在被其他进程回收之前(比如调用join)，是不会释放资源的（如栈）。而分离的线程不会被其他进程回收或者杀死，他的资源在该线程终止时自动由系统释放。  
		- 很多场景下手动调用 pthread_join 回收是麻烦的，比如 web 服务器每个连接可能开一个线程处理，那么用 detached 的线程是更合适的  
		-  
		  ``` c
		  		  #include <pthread.h>
		  		  
		  		  int pthread_detach(pthread_t tid);
		  		  
		  		  // 若成功则返回 0，若出错则为非零。
		  ```
	- ## 12.3.7 初始化线程  
		-  
		  ``` c
		  		  #include <pthread.h>
		  		  
		  		  pthread_once_t once_control = PTHREAD_ONCE_INIT;
		  		  
		  		  int pthread_once(pthread_once_t *once_control,
		  		                   void (*init_routine)(void));
		  		  
		  		  // 总是返回 0。
		  		  
		  		  // once_control 变量是一个全局或者静态变量，总是被初始化为 PTHREAD_ONCE_INIT。
		  		  // 当你第一次用参数 once_control 调用 pthread_once 时，它调用 init_routine，
		  		  // 这是一个没有输入参数、也不返回什么的函数。接下来的以 once_control 为参数的 
		  		  // pthread_once 调用不做任何事情。无论何时，当你需要动态初始化多个线程共享的全局
		  		  // 变量时，pthread_once 函数是很有用的
		  ```
	- ## 12.3.8 基于线程的并发服务器  
		-  
		  ``` c
		  		  #include "csapp.h"
		  		  
		  		  void echo(int connfd);
		  		  void *thread(void *vargp);
		  		  
		  		  int main(int argc, char **argv)
		  		  {
		  		      int listenfd, *connfdp;
		  		      socklen_t clientlen;
		  		      struct sockaddr_storage clientaddr;
		  		      pthread_t tid;
		  		  
		  		      if (argc != 2) {
		  		          fprintf(stderr, "usage: %s <port>\n", argv[0]);
		  		          exit(0);
		  		      }
		  		      listenfd = Open_listenfd(argv[1]);
		  		      
		  		      // 通过传 connfdp 参数给线程，可能造成和主线程的竞争
		  		      // 主线程如果下一次accept 比执行 thread 时间早的话， connfdp就指向下一个连接了
		  		      while (1) {
		  		          clientlen = sizeof(struct sockaddr_storage);
		  		          connfdp = Malloc(sizeof(int)); // 所以必须将 accept 返回的每个已连接描述符分配到它自己的动态分配的内存块
		  		          *connfdp = Accept(listenfd, (SA *) &clientaddr, &clientlen);
		  		          Pthread_create(&tid, NULL, thread, connfdp);
		  		      }
		  		  }
		  		  
		  		  /* Thread routine */
		  		  void *thread(void *vargp)
		  		  {
		  		      int connfd = *((int *)vargp);
		  		      Pthread_detach(pthread_self()); // 不显示回收，一定要分离线程
		  		      Free(vargp); // 这里一定要处理释放内存资源
		  		      echo(connfd);
		  		      Close(connfd);
		  		      return NULL;
		  		  }
		  ```
- # 12.4 多线程程序中的共享变量  
	- 线程很有吸引力的一个方面是多个线程很容易共享相同的程序变量。然而，这种共享也是很棘手的  
	- 为了理解 C 程序中的一个变量是否是共享的，有一些基本的问题要解答：  
		- 1. 线程的基础内存模型是什么？  
		- 2. 根据这个模型，变量实例是如何映射到内存的？  
		- 3. 最后，有多少线程引用这些实例？一个变量是**共享的**，当且仅当多个线程引用这个变量的某个实例。  
	- 来观察以下例子：  
		-  
		  ``` c
		  		  #include "csapp.h"
		  		  #define N 2
		  		  void *thread(void *vargp);
		  		  
		  		  char **ptr; /* Global variable */
		  		  
		  		  int main()
		  		  {
		  		      int i;
		  		      pthread_t tid;
		  		      char *msgs[N] = {
		  		          "Hello from foo",
		  		          "Hello from bar"
		  		      };
		  		  
		  		      ptr = msgs;
		  		      for (i = 0; i < N; i++)
		  		          Pthread_create(&tid, NULL, thread, (void *)i);
		  		      Pthread_exit(NULL);
		  		  }
		  		  
		  		  void *thread(void *vargp)
		  		  {
		  		      int myid = (int)vargp;
		  		      static int cnt = 0;
		  		      // 通过 ptr[myid] 当前线程实际上引用了主线程的变量
		  		      printf("[%d]: %s (cnt=%d)\n", myid, ptr[myid], ++cnt); 
		  		      return NULL;
		  		  }
		  ```
	- ## 12.4.1 线程内存模型  
		- 一组并发线程运行在一个进程的上下文中。  
			- 每个线程都有它自己独立的线程上下文，包括线程 ID、栈、栈指针、程序计数器、条件码和通用目的寄存器值。  
			- 每个线程和其他线程一起共享进程上下文的剩余部分。这包括整个用户虚拟地址空间，它是由只读文本（代码）、读/写数据、堆以及所有的共享库代码和数据区域组成的。线程也共享相同的打开文件的集合。  
		- 这些栈被保存在虚拟地址空间的栈区域中，并且通常是被相应的线程独立地访问的。我们说通常而不是总是，是因为**不同的线程栈是不对其他线程设防的**。所以，如果一个线程以某种方式得到一个指向其他线程栈的指针，那么它就可以读写这个栈的任何部分。  
	- ## 12.4.2 将变量映射到内存  
		- **全局变量。**全局变量是定义在函数之外的变量。在运行时，虚拟内存的读/写区域只包含每个全局变量的一个实例，任何线程都可以引用。例如，第 5 行声明的全局变量 ptr 在虚拟内存的读/写区域中有一个运行时实例。当一个变量只有一个实例时，我们只用变量名（在这里就是 ptr）来表示这个实例。  
		- **本地自动变量。**本地自动变量就是定义在函数内部但是没有 static 属性的变量。在运行时，每个线程的栈都包含它自己的所有本地自动变量的实例。即使多个线程执行同一个线程例程时也是如此。例如，有一个本地变量 tid 的实例，它保存在主线程的栈中。我们用 **tid.m** 来表示这个实例。再来看一个例子，本地变量 myid 有两个实例，一个在对等线程 0 的栈内，另一个在对等线程 1 的栈内。我们将这两个实例分别表示为 **myid.p0** 和 **myid.p1**。  
		- **本地静态变量。**本地静态变量是定义在函数内部并有 static 属性的变量。和全局变量一样，虚拟内存的读/写区域只包含在程序中声明的每个本地静态变量的一个实例。例如，即使示例程序中的每个对等线程都在第 25 行声明了 cnt，在运行时，虚拟内存的读/写区域中也只有一个 cnt 的实例。每个对等线程都读和写这个实例。  
	- ## 12.4.3 共享变量  
		- 我们说一个变量 v 是共享的，当且仅当它的一个实例被一个以上的线程引用。  
		- 在前述的例子中 cnt \ msgs 都是共享的，而 myid 不是共享的  
- # 12.5 用信号量同步线程  
	- 共享变量是十分方便，但是它们也引入了**同步错误**（synchronization error）的可能性。  
	- 下面是一个错误的例子  
		-  
		  ``` c
		  		  /* WARNING: This code is buggy! */
		  		  #include "csapp.h"
		  		  
		  		  void *thread(void *vargp); /* Thread routine prototype */
		  		  
		  		  /* Global shared variable */
		  		  volatile long cnt = 0; /* Counter */
		  		  
		  		  int main(int argc, char **argv)
		  		  {
		  		      long niters;
		  		      pthread_t tid1, tid2;
		  		  
		  		      /* Check input argument */
		  		      if (argc != 2) {
		  		          printf("usage: %s <niters>\n", argv[0]);
		  		          exit(0);
		  		      }
		  		      niters = atoi(argv[1]);
		  		  
		  		      /* Create threads and wait for them to finish */
		  		      Pthread_create(&tid1, NULL, thread, &niters);
		  		      Pthread_create(&tid2, NULL, thread, &niters);
		  		      Pthread_join(tid1, NULL);
		  		      Pthread_join(tid2, NULL);
		  		  
		  		      /* Check result */
		  		      if (cnt != (2 * niters))
		  		          printf("BOOM! cnt=%ld\n", cnt);
		  		      else
		  		          printf("OK cnt=%ld\n", cnt);
		  		      exit(0);
		  		  }
		  		  
		  		  /* Thread routine */
		  		  void *thread(void *vargp)
		  		  {
		  		      long i, niters = *((long *)vargp);
		  		  
		  		      for (i = 0; i < niters; i++)
		  		          cnt++;
		  		  
		  		      return NULL;
		  		  }
		  		  
		  ```
	- ![image.png](../assets/image_1694774848604_0.png)  
	- LUS的操作如果交错，则会产生错误  
	- ![image.png](../assets/image_1694774935803_0.png)  
	- ## 12.5.1 进度图  
		- **进度图**（progress graph）将 n 个并发线程的执行模型化为一条 n 维笛卡儿空间中的轨迹线。每条轴 k 对应于线程 k 的进度。每个点代表 k 已经成了 $$I_k$$ 这一状态。原点表示没有任何线程完成一条指令的初始状态。  
		- ![image.png](../assets/image_1694775110464_0.png)  
		- 对于线程 i，操作共享变量 cnt 内容的指令 $$ (L_i,U_i,S_i)$$ 构成了一个（关于共享变量 cnt 的）**临界区**（critical section），这个临界区不应该和其他进程的临界区交替执行。换句话说，我们想要确保每个线程在执行它的临界区中的指令时，拥有对共享变量的**互斥的访问**（mutually exclusive access）。通常这种现象称为**互斥**（mutual exclusion）。  
		- 在进度图中，两个临界区的交集形成的状态空间区域称为**不安全区**（unsafe region）。  
			- ![image.png](../assets/image_1694775297443_0.png)  
		- 为了保证线程化程序示例的正确执行（实际上任何共享全局数据结构的并发程序的正确执行）我们必须以某种方式**同步**线程，使它们总是有一条安全轨迹线。一个经典的方法是基于信号量的思想。  
	- ## 12.5.2 信号量 - semaphore  
		- Edsger Dijkstra 提出的解决同步不同执行线程问题的方法  
		- 信号量 s 是具有非负整数值的全局变量，只能由两种特殊的操作来处理，这两种操作称为 P 和 V：  
			- P(s)：如果 s 是非零的，那么 P 将 s 减 1，并且立即返回。如果 s 为零，那么就挂起这个线程，直到 s 变为非零，而一个 V 操作会重启这个线程。在重启之后，P 操作将 s 减 1，并将控制返回给调用者。  
			- V(s)：V 操作将 s 加 1。如果有任何线程阻塞在 P 操作等待 s 变成非零，那么 V 操作会重启这些线程中的一个，然后该线程将 s 减 1，完成它的 P 操作。  
		- P 和 V 的定义确保了一个正在运行的程序绝不可能进入这样一种状态，也就是一个正确初始化了的信号量有一个负值。这个属性称为**信号量不变性**（semaphore invariant）。  
		-  
		  ``` c
		  		  #include <semaphore.h>
		  		  
		  		  int sem_init(sem_t *sem, 0, unsigned int value);
		  		  int sem_wait(sem_t *s); /* P(s) */
		  		  int sem_post(sem_t *s); /* V(s) */
		  		  
		  		  // 返回：若成功则为 0，若出错则为 -1。
		  		  
		  		  #include "csapp.h"
		  		  
		  		  void P(sem_t *s); /* Wrapper function for sem_wait */
		  		  void V(sem_t *s); /* Wrapper function for sem_post */
		  		  
		  		  // 返回：无。
		  ```
	- ## 12.5.3 使用信号量实现互斥  
		- 二元信号量 - 互斥锁  
		- 在一个互斥锁上执行 P 操作称为对互斥锁加锁。类似地，执行 V 操作称为对互斥锁解锁。  
		- ![image.png](../assets/image_1694775684472_0.png)  
	- ## 12.5.4 利用信号量来调度共享资源  
		- 生产者消费者问题  
			-  
			  ``` c
			  			  // seminit(&slots, n);
			  			  // seminit(&items, 0);
			  			  
			  			  // provide() -> p(slots); insert(); v(items);
			  			  // consume() -> p(items); pop(); v(slots);
			  			  
			  			  typedef struct {
			  			      int *buf;       /* Buffer array */
			  			      int n;          /* Maximum number of slots */
			  			      int front;      /* buf[(front+1)%n] is first item */
			  			      int rear;       /* buf[rear%n] is last item */
			  			      sem_t mutex;    /* Protects accesses to buf */
			  			      sem_t slots;    /* Counts available slots */
			  			      sem_t items;    /* Counts available items */
			  			  } sbuf_t;
			  			  
			  			  /* Create an empty, bounded, shared FIFO buffer with n slots */
			  			  void sbuf_init(sbuf_t *sp, int n)
			  			  {
			  			      sp->buf = Calloc(n, sizeof(int));
			  			      sp->n = n;                       /* Buffer holds max of n items */
			  			      sp->front = sp->rear = 0;        /* Empty buffer iff front == rear */
			  			      Sem_init(&sp->mutex, 0, 1);      /* Binary semaphore for locking */
			  			      Sem_init(&sp->slots, 0, n);      /* Initially, buf has n empty slots */
			  			      Sem_init(&sp->items, 0, 0);      /* Initially, buf has zero data items */
			  			  }
			  			  
			  			  /* Clean up buffer sp */
			  			  void sbuf_deinit(sbuf_t *sp)
			  			  {
			  			      Free(sp->buf);
			  			  }
			  			  
			  			  /* Insert item onto the rear of shared buffer sp */
			  			  void sbuf_insert(sbuf_t *sp, int item)
			  			  {
			  			      P(&sp->slots);                           /* Wait for available slot */
			  			      P(&sp->mutex);                           /* Lock the buffer */
			  			      sp->buf[(++sp->rear) % (sp->n)] = item;  /* Insert the item */
			  			      V(&sp->mutex);                           /* Unlock the buffer */
			  			      V(&sp->items);                           /* Announce available item */
			  			  }
			  			  
			  			  /* Remove and return the first item from buffer sp */
			  			  int sbuf_remove(sbuf_t *sp)
			  			  {
			  			      int item;
			  			      P(&sp->items);                           /* Wait for available item */
			  			      P(&sp->mutex);                           /* Lock the buffer */
			  			      item = sp->buf[(++sp->front) % (sp->n)]; /* Remove the item */
			  			      V(&sp->mutex);                           /* Unlock the buffer */
			  			      V(&sp->slots);                           /* Announce available slot */
			  			      return item;
			  			  }
			  ```
		- 读者-写者 问题  
			- 可以共享读、必须互斥写  
			-  
			  ``` c
			  			  /* Global variables */
			  			  int readcnt;    /* Initially = 0 */
			  			  sem_t mutex, w; /* Both initially = 1 */
			  			  
			  			  void reader(void)
			  			  {
			  			      while (1) {
			  			          P(&mutex);
			  			          readcnt++;
			  			          if (readcnt == 1) /* First in */
			  			              P(&w);
			  			          V(&mutex);
			  			  
			  			          /* Critical section */
			  			          /* Reading happens  */
			  			  
			  			          P(&mutex);
			  			          readcnt--;
			  			          if (readcnt == 0) /* Last out */
			  			              V(&w);
			  			          V(&mutex);
			  			      }
			  			  }
			  			  
			  			  void writer(void)
			  			  {
			  			      while (1) {
			  			          P(&w);
			  			          
			  			          /* Critical section */
			  			          /* Writing happens  */
			  			  
			  			          V(&w);
			  			      }
			  			  }
			  ```
- # 12.6 使用线程提高并行性  
	-  
	  ``` c
	  	  #include "csapp.h"
	  	  #define MAXTHREADS 32
	  	  
	  	  void *sum_mutex(void *vargp); /* Thread routine */
	  	  
	  	  /* Global shared variables */
	  	  long gsum = 0;          /* Global sum */
	  	  long nelems_per_thread; /* Number of elements to sum */
	  	  sem_t mutex;            /* Mutex to protect global sum */
	  	  
	  	  int main(int argc, char **argv)
	  	  {
	  	      long i, nelems, log_nelems, nthreads, myid[MAXTHREADS];
	  	      pthread_t tid[MAXTHREADS];
	  	  
	  	      /* Get input arguments */
	  	      if (argc != 3) {
	  	          printf("Usage: %s <nthreads> <log_nelems>\n", argv[0]);
	  	          exit(0);
	  	      }
	  	      nthreads = atoi(argv[1]);
	  	      log_nelems = atoi(argv[2]);
	  	      nelems = (1L << log_nelems);
	  	      nelems_per_thread = nelems / nthreads;
	  	      sem_init(&mutex, 0, 1);
	  	  
	  	      /* Create peer threads and wait for them to finish */
	  	      for (i = 0; i < nthreads; i++) {
	  	          myid[i] = i;
	  	          Pthread_create(&tid[i], NULL, sum_mutex, &myid[i]);
	  	      }
	  	      for (i = 0; i < nthreads; i++)
	  	          Pthread_join(tid[i], NULL);
	  	  
	  	      /* Check final answer */
	  	      if (gsum != (nelems * (nelems - 1)) / 2)
	  	          printf("Error: result=%ld\n", gsum);
	  	  
	  	      exit(0);
	  	  }
	  	  
	  	  /* Thread routine for psum-mutex.c */
	  	  void *sum_mutex(void *vargp)
	  	  {
	  	      long myid = *((long *)vargp);          /* Extract the thread ID */
	  	      long start = myid * nelems_per_thread; /* Start element index */
	  	      long end = start + nelems_per_thread;  /* End element index */
	  	      long i;
	  	      
	  	      for (i = start; i < end; i++) {
	  	          P(&mutex);
	  	          gsum += i;
	  	          V(&mutex);
	  	      }
	  	      return NULL;
	  	  }
	  	  
	  	  // 优化1: 不用锁
	  	  /* Thread routine for psum-array.c */
	  	  void *sum_array(void *vargp)
	  	  {
	  	      long myid = *((long *)vargp);          /* Extract the thread ID */
	  	      long start = myid * nelems_per_thread; /* Start element index */
	  	      long end = start + nelems_per_thread;  /* End element index */
	  	      long i;
	  	  
	  	      for (i = start; i < end; i++) {
	  	          psum[myid] += i;
	  	      }
	  	      return NULL;
	  	  }
	  	  
	  	  // 优化2: 避免内存引用
	  	  /* Thread routine for psum-local.c */
	  	  void *sum_local(void *vargp)
	  	  {
	  	      long myid = *((long *)vargp);          /* Extract the thread ID */
	  	      long start = myid * nelems_per_thread; /* Start element index */
	  	      long end = start + nelems_per_thread;  /* End element index */
	  	      long i, sum = 0;
	  	  
	  	      for (i = start; i < end; i++) {
	  	          sum += i;
	  	      }
	  	      psum[myid] = sum;
	  	      return NULL;
	  	  }
	  	  
	  	  
	  ```
	- ![image.png](../assets/image_1694787041959_0.png){:height 401, :width 606}  
	- 在理想的情况中，我们会期望运行时间随着核数的增加线性下降。 直到到达 t > 4 的时候，此时四个核中的每一个都忙于运行至少一个线程。随着线程数量的增加，一个核上多个线程上下文切换的开销增大。 因此，并行程序常常写成每个核上运行一个线程。  
- # 12.7 其他并发问题  
	- ## 12.7.1 线程安全  
		- 我们能够定义出四个（不相交的）线程不安全函数类：  
			- 第 1 类：不保护共享变量的函数。  
			- 第 2 类：保持跨越多个调用的状态的函数。  
				- 伪随机数生成器是一个例子。 当调用 srand 为 rand 设置了一个种子后，我们从一个单线程中反复地调用 rand，能够预期得到一个可重复的随机数字序列。然而，如果多线程调用 rand 函数，这种假设就不再成立了。  
				-  
				  ``` c
				  				  unsigned next_seed = 1;
				  				  
				  				  /* rand - return pseudorandom integer in the range 0..32767 */
				  				  unsigned rand(void)
				  				  {
				  				      next_seed = next_seed * 1103515245 + 12543;
				  				      return (unsigned)(next_seed >> 16) % 32768;
				  				  }
				  				  
				  				  /* srand - set the initial seed for rand() */
				  				  void srand(unsigned new_seed)
				  				  {
				  				      next_seed = new_seed;
				  				  }
				  ```
			- 第 3 类：返回指向静态变量的指针的函数。  
				- 有些函数会将计算结果存在 static 变量中，然后返回一个指向这个变量的指针。但在多线程的环境中使用，可能结果会被另一个线程覆盖了。  
				- lock-and-copy 是一种解决方案  
				-  
				  ``` c
				  				  char *ctime_ts(const time_t *timep, char *privatep)
				  				  {
				  				      char *sharedp;
				  				      
				  				      P(&mutex);
				  				      sharedp = ctime(timep);
				  				      strcpy(privatep, sharedp); /* Copy string from shared to private */
				  				      V(&mutex);
				  				      return privatep;
				  				  }
				  ```
			- 第 4 类：调用线程不安全函数的函数。  
				- 如果函数 f 调用线程不安全函数 g，那么 f 就是线程不安全的吗？ #card #[[computer science]]  
					- 不一定。 如果g是第二类函数，那么f也是不安全的。否则，只需要在调用g前后加锁保护，f仍然可能是安全的。  
		- ## 12.7.2 可重入性  
			- 有一类重要的线程安全函数，叫做**可重入函数**（reentrant function），其特点在于它们具有这样一种属性：当它们被多个线程调用时，不会引用任何共享数据。  
			- ![image.png](../assets/image_1694788019754_0.png)  
		- ## 12.7.3 在线程化的程序中使用已存在的库函数  
			- ![image.png](../assets/image_1694788156012_0.png)  
		- ## 12.7.4 竞争  
			- 当一个程序的正确性依赖于一个线程要在另一个线程到达 y 点之前到达它的控制流中的 x 点时，就会发生**竞争**（race）。  
		- ## 12.7.5 死锁  
			- ![image.png](../assets/image_1694788407294_0.png)  
			- 轨迹线可以进入死锁区域，但是它们不可能离开。  
			- **互斥锁加锁顺序规则：给定所有互斥操作的一个全序，如果每个线程都是以一种顺序获得互斥锁并以相反的顺序释放，那么这个程序就是无死锁的。**  
			-  
			-  
			-  
		-  
	-  