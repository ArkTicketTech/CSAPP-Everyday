## 网络编程 :tiny web (4)

```
/**
 * @details 根据文件名确定类型
 * 
*/
void get_filetype(char *filename, char *filetype)
{
   if (strstr(filename, ".html"))
   {
    strcpy(filetype, "text/html");
   }
   else if (strstr(filename , ".gif"))
   {
    strcpy(filetype, "image/gif");
   }
   else if(strstr(filename, ".jpg"))
    strcpy(filetype, "image/jpeg");
   else  
     strcpy(filetype, "text/plain");

}

/**
 * @details 处理动态请求
 * @param fd 已连接描述符
 * 
*/
void serve_dynamic(int fd, char *filename, char *cgiargs)
{
  char buf[MAXLINE], *emptylist[] = {  NULL };
  
  sprintf(buf, "HTTP/1.0 200 OK\r\n");
  Rio_writen(fd, buf, strlen(buf));
  sprintf(buf, "Server: Tiny web server \r\n");
  Rio_writen(fd, buf, strlen(buf));
  
  //在子进程中设置环境变量， 重定向输出到标准输出，执行可执行文件
  if(fork() == 0){
      setenv("QUERY_STRING", cgiargs, 1);
      dup2(fd, STDOUT_FILENO);
      execve(filename, emptylist, environ);
  }

  //保证子进程优先执行
  wait(NULL);

}
```
