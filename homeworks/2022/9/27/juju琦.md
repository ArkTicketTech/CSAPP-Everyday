###  08-02-03 -创建进程2 fork()- 多次fork;
**代码出现一次fork是比较简单的情况， 有些程序中会出现多次fork。

> #include "csapp.h"
> 
> /\* $begin fork \*/
> 
> int main()
> 
>   fork();
> 
>  fork();
> 
>  exit(0);
> 
> }

像上面的程序，最终会fork()出几个进程呢？   2的n次方,n是fork出现的次数。
