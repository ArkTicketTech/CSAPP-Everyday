## practice problem

Suppose we want to generate assembly code for the following C function:

```c
long shift_left4_rightn(long x, long n)
{
    x <<= 4;
    x >>= n;
    return x;
}
```

The code that follows is a portion of the assembly code that performs the actual shifts and leaves the final value in register %rax. Two key instructions have been omitted. Parameters x and n are stored in registers %rdi and %rsi, respectively.

```c
long shift_left4_rightn(long x, long n)
x in %rdi, n in %rsi

shift_left4_rightn:
  movq    %rdi, %rax
  salq    $4, %rax
  movl    %esi, %ecx
  sarq    %cl, %rax
```