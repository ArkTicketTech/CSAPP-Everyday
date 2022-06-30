# Practice problem

In the following C function, we have left the definition of operation OP incomplete: #define OP  					/* Unknown operator */

```
short arith(short x) {
    return x OP 16;
```

}

When compiled, gcc generates the following assembly code:

```
  short arith(short x)
```

*x in %rdi*

```
arith:
  leaq    15(%rdi), %rbx
  testq   %rdi, %rdi
  cmovns  %rdi, %rbx
  sarq    $4, %rbx
  ret
```

A. What operation is OP?
B. Annotate the code to explain how it works.

***

# Answer

1. The operator is ‘/’. We see this is an example of dividing by a power of 4 by right shifting. Before shifting by k = 4, we must add a bias of 2^k − 1 = 15 when the dividend is negative.
2. Here is an annotated version of the assembly code:

```
  short arith(short x)
```

*x in %rdi*

```
arith:
  leaq    15(%rdi), %rbx
  testq   %rdi, %rdi
  cmovns  %rdi, %rbx
  sarq    $4, %rbx
  ret
temp =
Text x
If x>=
result
```

*x+15*

```
0, temp = x
= temp >> 4 (= x/16)
```

The program creates a temporary value equal to x + 15, in anticipation of x being negative and therefore requiring biasing. The cmovns instruction conditionally changes this number to x when x ≥ 0, and then it is shifted by 4 to generate x/16.