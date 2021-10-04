`hello` program
- source program (`hello.c`). a sequence of bits, organized in 8-bit chunks _bytes_. Each byte -> text character

Files consist exclusively of ASCII characters - text files
others - binary files

High-level C program -> low-level machine-language instructions -> packaged in a form of executable object program - stored as binary disk file (executable object files)
UNIX, Compiler driver (gcc) translates source file to object file

The compilation system:
source program (hello.c) -> preprocessor -> modified source program (hello.i) -> compiler -> assembly program (hello.s) -> assembler -> relocatable object programs (hello.o) -> linker -> executable object program (hello)

- *Preprocessing phase*
  - preprocessor modifies according to directives begin with #
  - e.g. `#include<stdio.h>` header file `stdio.h` is inserted into program text
- *Compilation phase*
  - compiler translates text file `hello.i` into assembly-language program `hello.s`
- *Assembly phase*
  - assembler translates `hello.s` into machine-language instructions, packages them into relocatable object program `hello.o`
  - a binary file 
- *Linking phase*
  - function `printf` is standard C library provided by C compiler
  - it resides in precompiled object file `printf.o`
  - linker merge `printf.o` with `hello.o`
  - result is `hello` executable object file