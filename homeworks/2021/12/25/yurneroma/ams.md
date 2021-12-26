# asm

Web Aside Asm: Easm  Combining assembly code with C programs

Although a C compiler  does a good job of converting the computations expressed in a program into machine code, there are some features of machine that cannot be accessed by a C program. For example , every time an x86-64 processor executes an arithmetic or logical operation, it sets a 1-bit condition code flag, named PF(for parity flag), to 1 when the lower 8 bits in the resulting computation have an even number of ones and to 0 otherwise. 

Computing this information in C requires at least seven shifting, masking, and EXCLUSIVE-OR operations (problem 2.65). Even though the hardware performs this computation as part of every arithmetic or logical operation, there if no way for C program to determine the value of PF condition code flag. this Task can readily be performed by incorporatiing a small number of assembly-code instructions into the program