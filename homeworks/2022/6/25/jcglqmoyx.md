In the following excerpts from a disassembled binary, some of the information has been replaced by X’s. Answer the following questions about these instructions.

1. What is the target of the je instruction below? (You do not need to know anything about the callq instruction here.)

   ```assembly
          4003fa: 74 02                 je     XXXXXX
          4003fc: ff d0                 callq  *%rax
   ```

2. What is the target of the je instruction below? 40042f: 74 f4 je XXXXXX

   ```assembly
          400431: 5d                    pop    %rbp
   ```

3. What is the address of the ja and pop instructions?

   ```assembly
          XXXXXX: 77 02                 ja     400547
          XXXXXX: 5d                    pop    %rbp
   ```

4. Inthecodethatfollows,thejumptargetisencodedinPC-relativeformasa4- byte two’s-complement number. The bytes are listed from least significant to most, reflecting the little-endian byte ordering of x86-64. What is the address of the jump target?

```assembly
       4005e8: e9 73 ff ff ff        jmpq   XXXXXXX
       4005ed: 90                    nop
```

***

A. The je instruction has as its target 0x4003fc + 0x02. As the original disas- sembled code shows, this is 0x4003fe:

```assembly
         4003fa: 74 02                 je     4003fe
         4003fc: ff d0                 callq  *%rax
```

B. The je instruction has as its target 0x0x400431 − 12 (since 0xf4 is the 1- byte two’s-complement representation of −12). As the original disassembled code shows, this is 0x400425:

```assembly
       40042f: 74 f4                 je     400425
       400431: 5d                    pop    %rbp
```

C. According to the annotation produced by the disassembler, the jump target is at absolute address 0x400547. According to the byte encoding, this must be at an address 0x2 bytes beyond that of the pop instruction. Subtracting these gives address 0x400545. Noting that the encoding of the ja instruction requires 2 bytes, it must be located at address 0x400543. These are confirmed by examining the original disassembly:

```assembly
       400543: 77 02                 ja     400547
       400545: 5d                    pop    %rbp
```

D. Reading the bytes in reverse order, we can see that the target offset is 0xffffff73, or decimal −141. Adding this to 0x0x4005ed (the address of the nop instruction) gives address 0x400560:

```assembly
       4005e8: e9 73 ff ff ff        jmpq   400560
       4005ed: 90                    nop
```