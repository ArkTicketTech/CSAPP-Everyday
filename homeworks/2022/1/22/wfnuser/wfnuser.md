### 3.7.4 local storage on the stack
有时 local storage 必须存储在 memory中， 最常见的情况：
1. 没有足够的寄存器存放变量
2. & 需要产生地址
3. 数组 或者 结构体 需要存储

```
long caller()
1 caller:
2 subq $16, %rsp
3 movq $534, (%rsp)
4 movq $1057, 8(%rsp)
5 leaq 8(%rsp), %rsi
6 movq %rsp, %rdi
7 call swap_add
8 movq (%rsp), %rdx
9 subq 8(%rsp), %rdx
10 imulq %rdx, %rax
11 addq $16, %rsp
12 ret
```