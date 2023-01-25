## 网络编程 :tiny web (2)

void doit(int fd)
{
  int is_static;
  struct stat sbuf;
  char buf[MAXLINE], method[MAXLINE],uri[MAXLINE],version[MAXLINE];
  char filename[MAXLINE],cgiargs[MAXLINE];
  rio_t rio;

   //将描述符与缓冲区关联起来
  Rio_readinitb(&rio, fd);  
  Rio_readlineb(&rio, buf, MAXLINE);
  sscanf(buf, "%s %s %s", method, uri, version);

  //只支持get请求， 非get请求，报501
  if(strcasecmp(method, "GET")) {
     clienterror(fd, method, "501", "Not Implemented", "Tiny does not implement this method");
     return;   
  }  

  //将缓冲区rp中的字符写入到buf中
  read_requesthdrs(&rio);
  
  is_static = parse_uri(uri, filename, cgiargs);
  if(stat(filename, &sbuf) < 0) {
      clienterror(fd, filename, "404", "Not found", "Tiny couldn't find this file");
      return;  
  }

  if(is_static){
    if (!S_ISREG(sbuf.st_mode) || !(S_IRUSR & sbuf.st_mode)){
        clienterror(fd, filename, "403", "Forbidden", "Tiny couldn't read the file");
        return;
    }

    serve_static(fd, filename, sbuf.st_size);
  }else{

    if(!(S_ISREG(sbuf.st_mode)) || !(S_IXUSR & sbuf.st_mode)){
        clienterror(fd, filename, "403", "Forbidden", "Tiny couldn't run the CGI program");
        return;
    }

    serve_dynamic(fd, filename, cgiargs);
  }

}
