# CSAPP_12_11 编译器优化

GCC实现的时候做了两层的中间码，分别是GIMPLE中间码，RTL中间码。代码生成阶段要考虑对应的指令集架构的寄存器使用，以及考虑流水线的调度

编译器阻止程序进行优化的例子

![](C:\Users\ASUS\Desktop\csapp\编译器.png)

```C
int fn (int *a, int *b)
{
    *a = 3;
    *b = 4;
    return (*a + 5);
}
//编译器不会帮助你进行优化
int fn (int *a, int *b)
{
    *a = 3;
    *b = 4;
    return (3 + 5);
}

// 但是你可以帮助编译器，使用C99的restrict类型限定符，但还是需要开发者确保两个指针不指向同一数据// https://gcc.gnu.org/onlinedocs/gcc/Restricted-Pointers.html
int fn (int *__restrict__ a, int *__restrict__ b)
{
    *a = 3;
    *b = 4;
    return (*a + 5); // 这里会被优化为 return (3 + 5)
}
```

