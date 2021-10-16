# CSAPP 10/15 Notes
## Chapter 3. Representing and Manipulating Information
* Computers execute machine codes, which are sequences bytes encoding low-level intructions.
* GCC compiler compiles C code to assembly, then the assembler and linker generate the executable machine code from assembly.
* Most of time, it's more productive and reliable to work at higher level of abstraction.
  * Type checking to detect bugs and errors.
  * Code Optimization.

* Reasons why we want to learn about assembly languages:
  1. Understand the optimization capabilities of the compiler and analyze the underlying inefficiencies in the code.
  2. Know about the run-time behaviors of the program.
    * Such as how data are shared or keep private between threads.
  3. Understanding how security vulnerabilities arise and how to guard against them.
