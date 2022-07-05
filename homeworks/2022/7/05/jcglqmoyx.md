# Practice Problem 3.21

Starting with C code of the form

```c
short test(short x, short y) {
    short val = y + 12;
    if (x < 0) {
        if (x < y)
            val = x * y;
        else
            val = x | y;
    } else if (y > 10)
        val = x / y;
    return val;
}
```

gcc generates the following assembly code:

```assembly
  short test(short x, short y)
  x in %rdi, y in %rsi
test:
  leaq    12(%rsi), %rbx
  testq   %rdi, %rdi
  jge     .L2
  movq    %rdi, %rbx
    imulq   %rsi, %rbx
    movq    %rdi, %rdx
    orq     %rsi, %rdx
    cmpq    %rsi, %rdi
    cmovge  %rdx, %rbx
    ret
  .L2:
    idivq   %rsi, %rdi
    cmpq    $10, %rsi
    cmovge  %rdi, %rbx
    ret
```

Fill in the missing expressions in the C code.

***

(答案已经填在了上面的C代码中)