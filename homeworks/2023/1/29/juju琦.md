## 网络编程 :tiny web (4)

```
/**
 * @details 将缓冲区rp中的字符写入到buf中
 * @param rp rp是已连接描述符写入的，接受到的数据
 * @author 琦
*/
void read_requesthdrs(rio_t *rp){

    char buf[MAXLINE];
    
    Rio_readlineb(rp, buf, MAXLINE);

    //遇到空文本行则打印出buf
    while (strcmp(buf, "\r\n"))
    {
      Rio_readlineb(rp, buf, MAXLINE);
      printf("%s", buf);
    }
    
    return;

}

/**
 * @details 处理静态请求
 * 
*/
void serve_static(int fd, char *filename, int filesize)
{
   int srcfd;
   char *srcp, filetype[MAXLINE], buf[MAXBUF];
   
   //根据文件名确定文件类型
   get_filetype(filename, filetype);

   //响应内容
   sprintf(buf, "HTTP/1.0 200 OK \r\n");
   sprintf(buf, "%s Server: Tiny web Server \r\n", buf);
   sprintf(buf, "%s Content-length: %d \r\n", buf, filesize);
   sprintf(buf, "%s Content-type: %s \r\n\r\n", buf, filetype);
   Rio_writen(fd, buf, strlen(buf));
  
   srcfd = Open(filename , O_RDONLY, 0);
   srcp = mmap(0 , filesize, PROT_READ, MAP_PRIVATE, srcfd, 0);
   close(srcfd);

   //将srcp内容写入到fd描述符
   rio_writen(fd, srcp, filesize);
   //取消映射到内存
   munmap(srcp, filesize);
   
}
```
