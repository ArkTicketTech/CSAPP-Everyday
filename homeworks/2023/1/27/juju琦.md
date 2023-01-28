## 网络编程 :tiny web (3)

int parse_uri(char *uri, char *filename, char *cgiargs)
{
    char *ptr;

    //uri中包含cgi-bin的字符判断为请求动态内容，否则为静态
    if(!strstr(uri, "cgi-bin")){
        strcpy(cgiargs, "");
        strcpy(filename, ".");
        strcat(filename, uri);
        if(uri[strlen(uri-1)] == '/')
          strcat(filename, "home.html");
        return 1;
    }else{
       ptr = index(uri, '?');
       if(ptr){
        strcpy(cgiargs, ptr+1);
        *ptr = '\0';
       }else
        strcpy(cgiargs, "");

      strcpy(filename, ".");
      strcat(filename, uri);
      return 0;
    }

}
