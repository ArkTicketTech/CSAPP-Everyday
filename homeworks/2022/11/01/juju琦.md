### 11-02-03-01  ( getaddrinfo和***getnameinfo***)实验

> int main(){
> 
>  struct addrinfo \*p, \*listp, hints;
> 
>  char buf[MAXLINE];
> 
>  int flags;
> 
>   memset(&hints, 0, sizeof(struct addrinfo));
> 
>  //puts("adfkaj");
> 
>  hints.ai_family = AF_INET;
> 
>  hints.ai_socktype = SOCK_STREAM;
> 
>  getaddrinfo("baidu.com", NULL, &hints, &listp);
> 
>  flags = NI_NUMERICHOST;
> 
>  for(p = listp; p; p= p->ai_next){
> 
>    getnameinfo(p->ai_addr, p->ai_addrlen, buf, MAXLINE, NULL, 0, flags);
> 
>    printf("%s\n", buf);
> 
>  }
> 
> }


