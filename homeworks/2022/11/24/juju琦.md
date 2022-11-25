## cgi demo
```
#include "csapp.h"

int main(void){
  char *buf, *p;
  char arg1[MAXLINE], arg2[MAXLINE],content[MAXLINE];
  int n1 = 0, n2 = 0;
  
  //获取传参
  if((buf = getenv("QUERY_STRING")) != NULL){
    p = strchr(buf, '&'); //分割&字符，获取参数
    *p = '\0';
    strcpy(arg1, buf); 
    strcpy(arg2, p+1);
    n1 = atoi(arg1);
    n2 = atoi(arg2);
  }
  
  //打印欢迎信息
  sprintf(content, "welcome to add.com: ");
  sprintf(content, "%s The Internet addition portal .\r\n<p>", content);
  sprintf(content, "%s The answer is: %d + %d = %d\r\n<p>", content, n1, n2, n1 + n2);
  sprintf(content, "%s Thanks for visiting!\r\n",content);
  
  //打印http头部信息
  printf("Content-length: %d\r\n", (int)strlen(content));
  printf("Content-type: text/html\r\n\r\n");
  printf("s%", content);
  fflush(stdout);
  exit(0);


}

```
