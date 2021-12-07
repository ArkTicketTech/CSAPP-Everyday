# struct

```wasm
#include <stdio.h>
struct rec {
    int i;  // 4
    int j;  // 4 
    int a[2]; // 8
    int *p; // 8
}rec;

int fun(struct rec *r1)
{
    /* data */
    return (*r1).i;
};
```

c 语言结构体内部会给每种类型做alignment,  为了方便cpu 读取。 数据读取时是按照字长的倍数来做读取的。如果  首地址+内部变量offset 不满足字长倍数，编译器会做补齐。

```wasm
struct stu {
    char c;  // 1 
    int i; // 4
};
```

stu 会占  1 + 3  + 4   == 8 个字节

- SSE
- AVX

16组 16bytes 寄存器  XMM0—XMM15

每个寄存器16个字节， 可以根据不同需要划分成 8个2bytes, 4个4bytes（int, float）, 2个8bytes（double float）做运算