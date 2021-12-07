# CH3 Machine-Level Represenstation of Programs

c++ -> assembly code -> (invoke assembler and linker) -> executable machine code
现代的编译器让我们编译出来的汇编代码一般不会比一个资深的汇编工程师写的代码低效
了解机器码和汇编语言帮助我们优化关键代码的性能；高层语言抽象的内涵也需要通过了解低层语言才能更好的被理解，比如理解线程就需要理解数据是如何存储和被线程共享的。

* understand transformations from c into machine code
* rearrange execution order
* eliminate unneeded computation
* replace slow operation
* change recursive computation

x86-64 ; subset of the features used by GCC and Linux

* relation between C, assembly code and machine code
* representations and manipulation of data and implementation of control; `if` `while` `switch`
* run-time stack | storage for local variables
* data stuctures | arrays, structures, unions ...

## 3.1 A Historical Perspective
处理器都是向前兼容的
Intel IA-32 - 32bits; x86-64 - 64bits