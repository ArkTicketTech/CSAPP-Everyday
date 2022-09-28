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
![image](https://user-images.githubusercontent.com/18367460/192668147-052e9517-8285-4ac0-92d5-3125720b83c1.png)

像上面的程序，最终会fork()出几个进程呢？   2的n次方,n是fork出现的次数。
