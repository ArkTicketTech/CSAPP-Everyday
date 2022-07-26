# Practive  problem 3.40

The following C code sets the diagonal elements of one of our fixed-size arrays to val:

```c
/* Set all diagonal elements to val */
void fix_set_diag(fix_matrix A, int val) {
    long i;
    for (i = 0; i < N; i++)
        A[i][i] = val;

```

When compiled with optimization level -O1, gcc generates the following assembly code:

```assembly
1 fix_set_diag:
	void fix_set_diag(fix_matrix A, int val)
	A in %rdi, val in %rsi

2   movl $0, %eax
3 .L13:
4   movl    %esi, (%rdi,%rax)
5   addq    $68, %rax
6   cmpq    $1088, %rax
7   jne     .L13
8   rep; ret
```

Create a C code program ```fix_set_diag_opt``` that uses optimizations similar to those in the assembly code. Use expressions involving the parameter ```N``` rather than integer constants, so that your code will work correctly if ```N``` is redefined.

***

```c
 void fix_set_diag_opt(fix_matrix A, int val) {
      int *Abase = &A[0][0];
      long i = 0;
      long iend = N*(N+1);
      do {
          Abase[i] = val;
          i += (N+1);
      } while (i != iend);
}
```

