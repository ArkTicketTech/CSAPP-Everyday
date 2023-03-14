显式转换
```c
int tx, ty;
unsigned ux, uy;

tx = (int) ux;
uy = (unsigned) uy;
```
隐式转换

```c
int tx, ty;
unsigned ux, uy;

tx = ux; // 转换为有符号
uy = ty; // 转换为无符号
```

当执行一个运算时，如果它的一个运算数是有符号的而另一个是无符号的，那么C语言会隐式地将有符号参数强制类型转换为无符号数，并假设这两个数都是非负的，来执行这个运算。

对于算术运算符来说比较直观，但是对于关系运算发来说并没有那么直观。