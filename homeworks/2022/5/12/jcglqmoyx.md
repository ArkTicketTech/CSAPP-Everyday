The following example illustrates how different data movement instructions either do or do not change the high-order
bytes of the destination. Observe that the three byte-movement instructions movb, movsbq, and movzbq differ from each
other in subtle ways. Here is an example:

```asm
1 movabsq $0x0011223344556677, %rax %rax = 0011223344556677
2 movb $0xAA, %dl %dl = AA
3 movb %dl,%al %rax = 00112233445566AA
4 movsbq %dl,%rax %rax = FFFFFFFFFFFFFFAA
5 movzbq %dl,%rax %rax = 00000000000000AA
```

In the following discussion, we use hexadecimal notation for all of the values. The first two lines of the code
initialize registers %rax and %dl to 0011223344556677 and AA, respectively. The remaining instructions all copy the
low-order byte of %rdx to the low-order byte of %rax. The movb instruction
(line 3) does not change the other bytes. The movsbq instruction (line 4) sets the other 7 bytes to either all ones or
all zeros depending on the high-order bit of the source byte. Since hexadecimal A represents binary value 1010, sign
extension causes the higher-order bytes to each be set to FF. The movzbq instruction (line 5) always sets the other 7
bytes to zero.