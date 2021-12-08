# CS_APP_12_08 程序的机器级表示

C程序的编译过程：源代码->编译->汇编->链接->可执行文件->装载->执行

## （1）intel x86-64的寄存器组

<img src="C:\Users\ASUS\Desktop\csapp\寄存器.PNG"  />

## (2) 编译器的优化

编译器比你想象的要聪明，例如，你写的switch语句可能会被优化为 jump table，还会消除无用的语句(Dead code elimination)等，汇编代码有时候不仅仅是C代码的直译，也就是说：编译器可以执行不同程度的优化

## (3)函数调用的过程 ：控制权转移 (含返回地址的保存)，参数传递，内存管理 (栈)，控制权返回

无论何种 ISA，函数调用过程大同小异，只是在具体的指令或者在ABI (Application Binary Interface) 层面略有不同而已，比如不同的ISA会有不同的 Calling Convention，也就是调用规则，它是调用者 Caller 和被调者 Callee 之间的某种合约，比如哪些寄存器用来传递参数，哪些寄存器用来存放返回值，哪些寄存器调用者/被调者可以放心使用等 (Caller Saved & Callee Saved)，理解Prologue & Epilogue！

![](C:\Users\ASUS\Desktop\csapp\函数调用.PNG)

## (4)数据

理解C语言中的数组和指针在机器级是如何表示的，理解字节对齐的作用 （有些指令集架构是强制要求字节对齐的，即使不要求也应该做到字节对齐，不仅能节省空间，更重要的是会影响访问性能

![](C:\Users\ASUS\Desktop\csapp\数据.PNG)