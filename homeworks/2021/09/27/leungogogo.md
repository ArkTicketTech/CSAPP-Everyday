# CSAPP 9/27 Notes
## 1.1 Information Is Bits + Context
* Every file is a sequence of bits, with values of 0 or 1. And there are two types of files:
    1. **Text file**: the bits of text file are organized in 8-bit chunks called bytes, each byte represents some text character in the program. Note that a text file contains only ASCII characters.
    2. **Binary file**: All other files are binary files.

* All information in computer systems are just bits, but the way we interpret them distinguishes different data objects.
    * For example, the same sequence of bits might represent an integer or a character.
## 1.2 Programs Are Translated by Other Programs into Different Forms
* C programs have to be translated into machine code in order to be run on the system, and the compiler driver will do this work in Unix system:
  ![Screen Shot 2021-09-27 at 8 02 14 PM](https://user-images.githubusercontent.com/26990923/135015872-bb18a8c7-1f75-417b-aeee-e91013337e93.png)
* Preprocessing phase: The preprocessor replaces the directives (which begins with `#`), and the resulting file is still a c file, but with the suffix `.i`.
* Compilation phase: The compiler translates the c code into assembly, with suffix `.s`.
* Assembly phase: The assembler translates the assembly code into machine code, which is not human-readable. And packages them in the object file with suffix `.o`.
* Linking phase: The linker merges different libaries stored in different object files, and produce the executable object file (`hello`), which is ready to be executed in the system.

## 1.3 It Pays to Understand How Compilation Systems Work
### Why do we need to learn about compilation systems?
* Knowing how the compilation systems work help us optimize program performance.
  * `if-else` vs `switch`
  * `while` loop vs `for` loop
  * Why the program runs faster if we switch the orders of parentheses in an arithmetic expression?
* Help us understand linked-time errors.
  * Difference between `global` and `static` variables.
  * `static` vs `dynamic` library.
  * Why do some linker errors pop up in runtime?
* Avoiding security vulnerability
  * Call stack and buffer overflow.
