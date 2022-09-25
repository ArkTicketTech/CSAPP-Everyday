# \## 11-05-03 cgi将它的输出发送到哪里

      cgi程序将它的动态内容**发送到标准输出**。在子进程加载并运行CGI程序之前，它**使用linux dup2函数将标准输出重定向到和客户端关联的已连接描述符**。 因此，任何cgi程序写到标准输出的东西都会**直接到达客户端**。

       注意，因为父进程不知道子进程生成的内容的类型和大小，所以子进程就要负责生成Content-type和 Content-length响应报头，以及终止报头的空行。

    我理解的是web服务器fork一个子进程调用cgi程序前， 先用linux dup2函数将标准输出关联到已连接描述。 所以cgi程序写到标准输出的内容会直接返回给客户端。   因为子进程不知道生成的内容类项和大小，所以cgi程序需要负责生成Content-type和Content-length响应报头， 以及终止报头的空行。

   **以下cgi程序举例：**

```
int main()

{

   char \*buf, \*p;

   char arg1[MAXLINE], arg2[MAXLINE], content[MAXLINE];

   int n1 = 0, n2 = 0;

   if ((buf = getenv("QUERY_STRING")) != NULL) {

       p = strchr(buf, '&');

       \*p = '\0';

       strcpy(arg1, buf);

       strcpy(arg2, p+1);

       n1 = atoi(arg1);

       n2 = atoi(arg2);

   }

   sprintf(content, "Welcome to add.com: ");

   sprintf(content, "%s The Internet addition portal .\r\n<p>", content);

   sprintf(content, "%s The answer is: %d + %d = %d\r\n<p>", content, n1, n2, n1 + n2);

   sprintf(content, "%s Thanks for visiting!\r\n", content);

   printf("Content-length: %d\r\n", (int)strlen(content));

   printf("Content-type: text/html\r\n\r\n");

   printf("%s", content);

   fflush(stdout);

   exit(0);

}
```

**出处**：[E.Bryant Randal,O'Hallaron David《深入理解计算机系统（原书第3版）》(2016) P](zotero://select/library/items/B8AHZTAU)669-670
