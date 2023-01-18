## 网络编程tiny-web 1

#include "csapp.h"

void doit(int fd);
void read_requesthdrs(rio_t *rp);
int parse_uri(char *uri, char *filename, char *cgiargs);
void serve_static(int fd, char *filename, int filesize);
void get_filetype(char *filename, char *filetype);
void serve_dynamic(int fd, char *filename, char *cgiargs);
void clienterror(int fd, char *cause, char *errnum, char *shortmsg, char *longmsg);

int main(int argc, char **argv){
   int listenfd, connfd, port, clientlen;
   struct sockaddr_in clientaddr;

   if(argc != 2){
     fprintf(stderr, "usage: %s <port>\n", argv[0]);
     exit(1);
   }

   port = atoi(argv[1]);
   
   //创建一个服务端的监听描述符
   listenfd = Open_listenfd(port);

    /**
     * 等待与客户端的连接请求
    */
   while(1) {

        clientlen = sizeof(clientaddr);
        //等待与客户端连接， 建立连接成功后，返回一个已连接描述符connfd
        connfd  = Accept(listenfd, (SA *)&clientaddr, &clientlen);
        doit(connfd);
        close(connfd);

   }

}
