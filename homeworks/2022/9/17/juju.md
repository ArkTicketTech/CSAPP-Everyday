### 创建进程1 fork()- 一次fork;

fork函数是有趣的（也常常令人迷惑），因为它只被调用一次，却返回2次：一次是在调用进程（父进程）中，一次是在新创建的子进程中。

           在父进程中，fork返回子进程的PID（>0）。  在子进程中，fork返回0。

           因为子进程的PID总是为非零，返回值就提供一个明确的方法来分辨程序是在父进程还是在子进程中执行。  下面代码展示了创建子进程的示例。

> #include "csapp.h"
> 
> /\* $begin fork \*/
> 
> int main()
> 
>    pid_t pid;
> 
>    int x = 1;
> 
>    pid = fork(); //line:ecf:forkreturn
> 
>    if (pid == 0) {  /\* Child \*/
> 
>        printf("child : x=%d\n", ++x); //line:ecf:childprint
> 
>        exit(0);
> 
>    }
> 
>    printf("pid: pid=%d\n", pid);
> 
>    /\* Parent \*/
> 
>    printf("parent: x=%d\n", --x); //line:ecf:parentprint
> 
>    exit(0);
> 
> }

下面这个例子，更有助理解。

> int main()
> 
>    pid_t pid;
> 
>    int x = 1;
> 
>    pid = fork(); //line:ecf:forkreturn
> 
>    if (pid == 0) {  /\* Child \*/
> 
>        printf("child : x=%d\n", ++x); //line:ecf:childprint
> 
>    }
> 
>    printf("pid: pid=%d\n", pid);
> 
>    /\* Parent \*/
> 
>    printf("parent: x=%d\n", --x); //line:ecf:parentprint
> 
> }

结果为：

“parent: x=0

child : x=2

parent: x=1 ”   没有了exit.第一次在父进程中执行的结果：parent: x=0 。  第二次在子进程的结果 child : x=2  parent: x=1

