运行时栈

运行时栈，主要用于存储程序的过程或函数调用信息。

这包括局部变量、函数参数、返回地址和其他函数调用相关的数据。

每当一个函数被调用时，都会为该函数在栈上分配一个新的栈帧。这个栈帧存储了函数需要的所有信息，包括函数的参数、局部变量和返回地址。一旦函数执行完毕并返回，它的栈帧就会被从栈中弹出，释放相应的内存。