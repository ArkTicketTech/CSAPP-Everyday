_addressing modes_ - different forms of memory references

Imm($r_{b}$, $r_{i}$, s)
- Imm - immediate offset
- $r_{b}$, base register
- $r_{i}$, index register
- s, scale factor, must be 1, 2, 4, 8
- computed as Imm + R[$r_{b}$] + R[$r_{i}$]*s

*Practice problem 3.1*
Operand | value
--------|-------
%rax | 0x100
0x104 | 0xAB
$0x108 | 0x108
(%rax) | 0xFF
4(%rax) | 0xAB
9(%rax, %rdx) | 0x11
260(%rcx, %rdx) | 0x13
0xFC(,%rcx, 4)| 0xFF
(%rax, %rdx, 4) | 0x11
