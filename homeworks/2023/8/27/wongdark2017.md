# CSAPP 读书笔记 day5

阅读页数：P73 - P83

## 第二章： Representing and Manipulating Information

### 进制转换

除基取余

对于一个w位的机器而言，虚拟地址的范围是 $0\sim 2^w − 1$ ,程序最多访问 $2^w$字节。

大端法和小端法：**最低有效字节在最前面的方式称为小端法，最高有效字节在最前面的方式叫大端法。**

展示大小端的程序

```c
#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
	printf(" %.2x", start[i]);    //line:data:show_bytes_printf
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int)); //line:data:show_bytes_amp1
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float)); //line:data:show_bytes_amp2
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *)); //line:data:show_bytes_amp3
}

void test_show_bytes(int val) {
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

int main(int argc, char const *argv[])
{
    test_show_bytes(1);
    return 0;
}
```
