# Practice Problem 3.37

Suppose Xp, the address of short integer array P, and long integer index i are stored in registers %rdx and %rcx, respectively. For each of the following expressions, give its type, a formula for its value, and an assembly-code implementation. The result should be stored in register %rax if it is a pointer and register element %ax if it has data type short.

| Expression   |  Type  | Value            | Assembly code              |
| ------------ | :----: | ---------------- | -------------------------- |
| P[1]         | short  | M[Xp + 2]        | movw 2(%rdx),%ax           |
| P + 3 + i    | short* | Xp + 6 + 2i      | leaq 6(%rdx,%rcx,2),%rax   |
| P[i * 6 - 5] | short  | M[Xp + 12i - 10] | movw -10(%rdx,%rcx,12),%ax |
| P[2]         | short  | M[Xp + 4]        | movw 4(%rdx),%ax           |
| &P[i + 2]    | short* | Xp + 2i + 4      | leaq 4(%rdx,%rcx,2),%rax   |

