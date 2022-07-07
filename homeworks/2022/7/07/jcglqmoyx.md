# Practice Problem 3.30

In the C function that follows, we have omitted the body of the switch statement. In the C code, the case labels did not span a contiguous range, and some cases had multiple labels.

```c
void switch2(short x, short *dest) {
      short val = 0;
			switch (x) { .
					. Body of switch statement omitted
			}
			*dest = val; 
}
```

In compiling the function, gcc generates the assembly code that follows for the initial part of the procedure, with variable x in %rdi:```

```assembly
void switch2(short x, short *dest) 
x in %rdi

switch2:
  addq $2, %rdi
  cmpq $8, %rdi
  ja   .L2
  jmp  *.L4(,%rdi, 8)
```

It generates the following code for the jump table:

```assembly
.L4:
  .quad .L9
  .quad .L5
  .quad .L6
  .quad .L7
  .quad .L2
  .quad .L7
  .quad .L8
  .quad .L2
  .quad .L5
```

Based on this information, answer the following questions:

A. What were the values of the case labels in the switch statement?

B. What cases had multiple labels in the C code?

***

A. The case labels in the switch statement body have values −2, −1, 0, 1, 3, 4, and 6.

B. The case with destination .L5 has labels −1 and 6.

C. The case with destination .L7 has labels 1 and 3.