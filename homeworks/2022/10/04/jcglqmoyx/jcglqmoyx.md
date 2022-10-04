 AVX2 provides two instructions for comparing floating-point values: 

 Instruction Based on Description 

``` assembly
ucomiss   S1, S2 S2 − S1 Compare single precision
ucomisd   S1, S2 S2 − S1 Compare double precision 
```

 These instructions are similar to the cmp instructions (see Section 3.6), in that 

 they compare operands   S1   and   S2   (but in the opposite order one might expect) and 

 set the condition codes to indicate their relative values. As with   cmpq  , they follow 

 the ATT-format convention of listing the operands in reverse order. Argument 

 S2 must be in an XMM register, while S1 can be either in an XMM register or in 

 memory. 

 The floating-point comparison instructions set three condition codes: the zero 

 flag   ZF, the carry flag   CF, and the parity flag   PF. We did not document the parity 

 flag in Section 3.6.1, because it is not commonly found in gcc-generated x86 code. 

 For integer operations, this flag is set when the most recent arithmetic or logical 

 operation yielded a value where the least significant byte has even parity (i.e., 

 an even number of ones in the byte). For floating-point comparisons, however, 

 the flag is set when either operand is NaN. By convention, any comparison in C 

 is considered to fail when one of the arguments is NaN, and this flag is used to 

 detect such a condition. For example, even the comparison x == x yields 0 when x 

 is NaN. 
