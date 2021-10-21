> ***2021.10.20\***

------

### 2.4.6 Floating Point in C

C语言浮点数有两种：

- float单精度浮点数
- double双精度浮点数

整形与浮点形强制转换会有以下情况：

- int到float：数字不会溢出，但是可能被舍入
- int、float到double：能够保留精确值
- double到float：可能溢出到正无穷或者负无穷，精度也可能被舍入
- float、double到int：值向0舍入

## 2.5 Summary

多数机器使用补码编码。

多数C语言在有符号数和无符号数转换时遵循底层位模式不变的原则。