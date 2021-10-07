# Ch. 2 Representing and Manipulating Information

### 2.1.3 Addressing and Byte Ordering
跨多个bytes的数据类型存储的时候需要考虑字节排列顺序。
least significant 先出现 -> 小端
most significant  先出现 -> 大端

大多数时候对程序员来说是透明的，一些场景下会产生一些问题，比如网络传输。
对byte级操作的代码或者一些类型强制转换的函数在不同的机器上运行结果可能也不太一样。
floating表示和int就区别很大。

