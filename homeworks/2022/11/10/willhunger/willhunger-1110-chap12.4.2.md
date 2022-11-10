# Ch12 Concurrent Programming

## 12.4 Shared Variables in Threaded Programs

### 12.4.2 Mapping Variables to Memory

全局变量：定义在函数之外的变量，虚拟内存仅包含了每个全局变量的一个实例，任何线程都可以引用。

本地自动变量：每个线程的线程栈都包含了自己的所有本地自动变量的实例。

本地静态变量：定义在函数内部并有 static 属性的变量，和全局变量一样。