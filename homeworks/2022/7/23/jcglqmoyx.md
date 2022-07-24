Consider the following source code, where M and N are constants declared with #define:

```c
long P[M][N];
long Q[N][M];
long sum_element(long i, long j) {
    return P[i][j] + Q[j][i];
}
```

In compiling this program, gcc generates the following assembly code:

```
long sum_element(long i, long j)
       i in %rdi, j in %rsi
1 sum_element:
2 leaq 0(,%rdi,8), %rdx
3 subq %rdi, %rdx
4 addq %rsi, %rdx
5 leaq (%rsi,%rsi,4), %rax
6 addq %rax, %rdi
7 movq Q(,%rdi,8), %rax
8 addq P(,%rdx,8), %rax
9 ret
```

Use your reverse engineering skills to determine the values of M and N based on this assembly code.

***

M = 5, N = 7