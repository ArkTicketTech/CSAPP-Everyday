# 3.10 Combining Control and Data in Machine-Level Programs
本章会揭示计算机数据表示和控制流程的交互作用。让我们先从指针讲起。

## 3.10.1 Understanding Pointer
指针有类型 这是C语言提供的抽象 在汇编层面并不存在 在计算地址的时候，会和类型有关 *p+i
指针都有值 值为所指对象的地址 空指针值为零 
&用于产生指针 取地址操作 汇编层面上的leaq做的事情就是这个 左值都可以取地址
*用于解引用 取指向对象的值
数组和指针 a[3]  <-> *(a+3)
指针可以做类型转换 对地址算术运算有影响 对于 char* p 来说 (int*)p+7 -> p+28 | (int*)(p+7) -> p+7
指针可以指向函数
```
int fun(int x, int *p);

int (*fp)(int, int *);
fp = fun;

int y = 1;
int res = fp(2, &y);
```