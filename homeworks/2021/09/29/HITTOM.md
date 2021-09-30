C1: Tour of Computer System
P37 ~ P43
Aside: C由个人而非组织设计,具有简洁一致的设计,学C可以看K&R 261页教材
1.2 
hello.c --> hello.i (pre-processor, cpp) modified source program
hello.i --> hello.s (compiler, cc1) assembly program
hello.s --> hello.o (assembler, as) relocatable binary object program
hello.o + printf.o --> hello (linker, ld) executable binary object program
gcc -o hello hello.c

Aside: GNU产出了GCC编译器,GDB,assembler,linker等工具.目前已支持Fortran,java,pascal等多种语言
1.3 It pays to understand how compilation work
优化性能: a)为何累加到局部变量比累加到函数的引用参数快? b)switch始终比if-else快吗
理解链接错误: a)全局变量和静态变量区别 b)为何一些链接错误直到运行时才暴露
避免安全漏洞


vulnerability 脆弱性
gibberish 胡言乱语
