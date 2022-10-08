details about the Y86-64 instructions

* The x86-64 movq instruction is split into four different instructions: irmovq,
rrmovq, mrmovq, and rmmovq, explicitly indicating the form of the source and
destination.

* There are four integer operation instructions, shown in Figure 4.2 as OPq.
These are addq, subq, andq, and xorq.

* The seven jump instructions are jmp, jle, jl, je, jne, jge, and jg.

* There are six conditional move instructions: cmovle, cmovl, cmove, cmovne, cmovge, and cmovg.

* The call instruction pushes the return address on the stack and jumps to the destination address.

* The pushq and popq instructions implement push and pop, just as they do in
x86-64.

* The halt instruction stops instruction execution.
