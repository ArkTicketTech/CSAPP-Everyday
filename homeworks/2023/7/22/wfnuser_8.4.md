fork 相关

- parent process 通过 fork 创建新的子进程； fork函数调用一次，返回两次  
- 父子进程并发执行，顺序不确定  
- 地址空间被拷贝但是是独立的；也就是 stacklocal variableheapglobal variable 都是一样的；但是地址是不一样的  
- 文件是被共享的  
