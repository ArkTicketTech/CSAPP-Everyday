# Ch3 Machine-Level Representation of Programs

## 3.6 Control

**switch语句** 

switch 语句根据一个整形索引值进行多重分支。

* 提高了 C 语言的可读性；
* 使用跳转表（jump table），更加高效。

跳转表：

* 本质上是一个数组结构；

* 针对 switch 语句的每个 case，在跳转表中生成对应 case 的代码段的地址，程序依据 case 值查找跳转表来确定跳转目的地址。

* 相比于使用 if-else 分支，有如下优势：

    * 执行 switch-case 语句的时间与 case 数量无关；
    * 如果 case 值的比较多，且值的分布范围比较小时，编译器使用跳转表来优化 switch-case 语句；相反，如果 case 的值的分布较为稀疏，则会使用 if-else 分支进行优化；
    * 如果 case 出现负值，编译器会将其加上一个偏移量，然后再生成跳转表。

    

