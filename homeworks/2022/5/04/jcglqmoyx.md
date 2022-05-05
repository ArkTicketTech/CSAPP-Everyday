The machine code for x86-64 differs greatly from the original C code. Parts of the processor state are visible that
normally are hidden from the C programmer:

The program counter (commonly referred to as the PC, and called %rip in x86-64) indicates the address in memory of the
next instruction to be executed.

The integer register file contains 16 named locations storing 64-bit values. These registers can hold addresses (
corresponding to C pointers) or integer data. Some registers are used to keep track of critical parts of the program
state, while others are used to hold temporary data, such as the arguments and local variables of a procedure, as well
as the value to be returned by a function.

The condition code registers hold status information about the most recently executed arithmetic or logical instruction.
These are used to implement conditional changes in the control or data flow, such as is required to implement if and
while statements.

A set of vector registers can each hold one or more integer or floating-point values.

*** 

x86-64 virtual addresses are represented by 64-bit words. In current implementations of these machines, the upper 16
bits must be set to zero, and so an address can potentially specify a byte over a range of 248, or 64 terabytes.