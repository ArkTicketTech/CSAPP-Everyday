## 10.5.2demo
```
void rio_readinitb (rio_t *rp, int fd);

ssize_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen);
ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n);

ssize_t rio_readn(int fd,void *usrbuf, size_t n)
{
   size_t nleft = n;
   ssize_t nread;
   char *bufp = usrbuf;
    
   while (nleft > 0) {
      if((nread = read(fd, bufp, nleft)) < 0){
        if(errno == EINTR)
           nread = 0;
         else
           return -1;
      
      }
      else if(nread == 0)
         break;
       
       nleft -= nread;
       bufp += nread;
   }
   
   return (n - nleft);
}
```
