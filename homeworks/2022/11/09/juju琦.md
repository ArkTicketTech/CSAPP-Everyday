#### 练习题 inet_ntop,inet_pton

```
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define INADDR  "10.1.0.29"
#define IN6ADDR "DEAD:BEEF:7654:3210:FEDC:3210:7654:BA98"

int main()
{
   struct in_addr inaddr;
   struct in6_addr in6addr;
   char buf[INET_ADDRSTRLEN], buf6[INET6_ADDRSTRLEN];
   int rval;

   if ( (rval = inet_pton(AF_INET, INADDR, &inaddr)) == 0) {
      printf("Invalid address: %s\n", INADDR);
      exit(EXIT_FAILURE);
   } else if (rval == -1) {
      perror("inet_pton");
      exit(EXIT_FAILURE);
   }

   if (inet_ntop(AF_INET, &inaddr, buf, sizeof(buf)) != NULL)
      printf("inet addr: %s\n", buf);
   else {
      perror("inet_ntop");
      exit(EXIT_FAILURE);
   }

 /**  if ( (rval = inet_pton(AF_INET6, IN6ADDR, &in6addr)) == 0) {
      printf("Invalid address: %s\n", IN6ADDR);
      exit(EXIT_FAILURE);
   } else if (rval == -1) {
      perror("inet_pton");
      exit(EXIT_FAILURE);
   }
   
   if (inet_ntop(AF_INET6, &in6addr, buf6, sizeof(buf6)) != NULL)
      printf("inet6 addr: %s\n", buf6);
   else {
      perror("inet_ntop");
      exit(EXIT_FAILURE);
   }**/

   return(EXIT_SUCCESS);
}

```
![image](https://user-images.githubusercontent.com/18367460/200980044-f95d8165-429e-46b2-9a76-30721e1682c8.png)

