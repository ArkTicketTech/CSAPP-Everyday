`linux` 的进程是一个树形结构，系统启动时会创建`init`进程，`init` 进程是 `linux` 进程树的根进程，其他所有进程都是`init` 进程的子进程。在不同的发行版的 `linux` 中，根进程的名字可能不同，但是进程结构都是类似的。

 <img src="https://typra-pictures.oss-cn-beijing.aliyuncs.com/imgs/image-20230715102946564.png" alt="image-20230715102946564" style="zoom:25%;" />

通过这种进程树的结构，

1. 可以实现资源继承资源共享
2. 通过父进程管理和控制进程更容易
3. 并行计算和分布式计算时，非常优雅