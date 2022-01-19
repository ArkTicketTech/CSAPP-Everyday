## 3.7 Procedures
过程是软件的一个关键抽象。 在软件中以很多种不同的形式展现：funcitons subroutines handlers 等等。

P calls procedure Q; Q executes and returns back to P

Passing control 需要提供代码入口和返回的地方
Passing data 传递参数；返回值
Allocating and deallocating memory Q需要分配内存和释放

### 3.7.1 The Run-Time Stack
各个语言实现函数调用的时候都会采用LIFO的stack作为底层的存储。
Q只会申请空间用作自己本地变量的存储和Q调用其他函数所需；Q return 的时候 这些空间就会被释放掉。
![](2022-01-19-11-32-45.png)