_instruction classes_ - the instructions in a class perform the same operation but with different operand sizes


*Practice Problem 3.2*

movl     %eax, (%rsp)

movw     (%rax), %dx

movb    $0xFF, %bl

movb    (%rsp,%rdx,4), %dl

movq     (%rdx), %rax

movw     %dx, (%rax)