# \## 基于线程的并发服务器

### **关键点：1. 如何将已连接描述符传递给对等线程。**

#### 方案：传递一个指向这个描述符的指针，如下

connfd = Accept(listenfd , (SA \*) &clientaddr, &clientlen);

Pthread_create(&tid, NULL, thread, &connfd);

**然后，对等线程间接引用这个指针，并将它赋值给一个局部变量，如下**

void *thread(void  \**vargp){

   int connfd = *((int \**) vargp);

}

