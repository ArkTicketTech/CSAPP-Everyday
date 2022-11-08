### 11.17 demo
```
#include "csapp.h"

int main(int argc, char **argv)
{
   struct addrinfo *p, *listp, hints;
   char buf[MAXLINE];
   int rc,flags;
   
   if(argc != 2){
     fprintf(stderr, "");
     exit(0);
   }
   
   memset(&hints, 0, sizeof(struct addrinfo));
   hints.ai_family = AF_INET;
   hints.ai_socktype = SOCK_STREAM;
   
   
   

}

```
