# Practice Problem 3.8

Assume the following values are stored at the indicated memory addresses and
registers:

| Address | Value | Register | Value |
| ------- | ----- | -------- | ----- |
| 0x100   | 0xFF  | %rax     | 0x100 |
| 0x108   | 0xAB  | %rcx     | 0x1   |
| 0x110   | 0x13  | %rdx     | 0x3   |
| 0x118   | 0x11  |          |       |

Fill in the following table showing the effects of the following instructions,
in terms of both the register or memory location that will be updated and the
resulting value:

| Instruction             | Destination | Value |
| ----------------------- | ----------- | ----- |
| addq %rcx,(%rax)        | 0x100       | 0x100 |
| subq %rdx,8(%rax)       | 0x108       | 0xA8  |
| imulq $16,(%rax,%rdx,8) | 0x118       | 0x110 |
| incq 16(%rax)           | 0x110       | 0x14  |
| decq %rcx               | %rcx        | 0x0   |
| subq %rdx,%rax          | %rax        | 0xFD  |

