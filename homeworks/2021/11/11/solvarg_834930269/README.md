# Chapter.8 异常控制流

pre Chapter 3.7

--------------

## 同步流以避免讨厌的并发错误

看一段代码

```cpp
void handler(int sig){
    int olderrno = errno;
    sigset_t mask_all,prev_all;
    pid_t pid;

    Sigfillset(&mask_all);
    while((pid==waitpid(-1,NULL,0))>0){//读到一个僵尸进程
        Sigprocmask(SIG_BLOCK,&mask_all,&prev_all);
        deletejob(pid);//回收进程,错误处理程序
        Sigprocmask(SIG_SETMASK,&prev_all,NULL);
    }
    if(errno !=ECHILD)
        Sio_error("waitpid error");
    errno = olderrno;
}

int main(int argc,char **argv){
    int pid;
    sigset_t mask_all,prev_all;
    Sigfillset(&mask_all);
    Signal(SIGCHILD,handler);
    initjobs();

    while(1){
        if((pid == Fork()==)0){
            //子进程
            Execve("/bin/date",argv,NULL);
        }
        Sigprocmask(SIG_BLCK,&mask_all,&prev_all);
        addjob(pid);//创建完毕,添加到进程列表
        Sigprocmask(SIG_SETMASK,&prev_all,NULL);
    }
    exit(0);
}
```

上段代码是一段BUg代码,这是因为出现了`同步并发流`的问题,

这段代码主要想做的是如下   
    父进程创建一个子进程并添加到进程列表,当接到SIGCHILD信号时会回收僵尸进程,并从列表中删除这个子进程.  

但是有可能会出现如下问题  
    - 1. fork出一个子进程,内核进入子进程
    - 2. 下一次进入父进程继续执行之前,子进程终止,触发SIGCHILD信号,进入到父进程的信号处理程序
    - 3. 处理程序调用deleteJob函数,但是函数列表里还没有子进程,所以什么都不做
    - 4. 继续执行父进程,addJob添加了一个不存在的子进程

上面这种情况,被称为**竞争**

解决这种问题的一个方法是在子进程加入到列表之前,**阻塞SIGCHILD信号**,加入之后再释放



## 显示的等待信号

比如一个业务场景,父进程需要等待一个前台作业执行完毕再继续执行.

一个方法是创建一个无限循环,等待SIGCHILD信号。**但这种方法是一种浪费**    
还有两证方法,一种是执行`pause()`,一种是执行`sleep(1)`  
但是前者会出现永远休眠的情况,后者会很慢

合适的解决方法是使用`sigsuspend(mask)`  

sigsuspend函数暂时用mask替换当前的阻塞集合,然后挂起进程,直到收到一个信号,其行为要么是运行一个处理程序,要么是终止该进程,如果行为时终止,name该进程直接终止.如果是处理程序,则处理完后恢复sigsuspend之前的阻塞集合.

## 操作进程的工具

LINUX上
```
STRACE
PS
TOP
PMAP
```




--------------


> Latex转Svg

https://www.latexlive.com/