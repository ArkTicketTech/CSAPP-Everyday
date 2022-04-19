# ch1

## the compilation system

hello.c(source program)

**pre-processor(cpp) - modifies the file with #**

hello.i(modified source program)

**compiler(cc1) - translate to text contains assembly code**

hello.s(assembly language)

**assembler(as) - translate into machine-language**

hello.o(object code, binary) + printf.o

**linker(ld) - handle the merging**

hello

## hardware organization

- buses - collection of electrical conduits, carry bytes of information back and forth between components
- I/O devices - input and output
- main memory - temporary storage holds both program and data, DRAM(dynamic random access memory)
- processor - central processing unit:
  - _load_: copy byte from main memory into a register
  - _store_: copy byte from register into main memory
  - _operate_: copy contents of registers to the ALU, store the result in a register
  - _jump_: copy the word into the program counter(PC)
