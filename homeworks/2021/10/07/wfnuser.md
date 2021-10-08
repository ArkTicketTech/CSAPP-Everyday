# Ch. 2 Representing and Manipulating Information

### 2.1.4 Representing Strings
C string : 连续的ASCII码数组，以\0结尾。

### 2.1.5 Representing Code
代码在不同的机器上编译出来的结果不同，因为指令集和编码不同。
即使是同样的处理器上运行不同的操作系统时，代码编译出来也是不同的，因此不是二进制兼容的。

### 2.1.6 Introduction to Boolean Algebra
bitmask 可用于控制不同的 signals
或与非

### 2.1.7 Bit-Level Operations in C

### 2.1.8 Logical Operations in C
|| && !

### 2.1.9 Shift Operations in C
x << j << k  --- (x << j) << k

Logical 逻辑右移 左侧留0
Arithmetic 算数右移 左侧保留最高位 这可以帮助我们处理有符号整数

C语言不在语言层面区分右移的类型。大部分编译器都会将有符号的右移处理成算数右移动，而无符号数处理为逻辑右移。

## 2.2 Integer Representations

### 2.2.1 Integral Data Types
signed \ unsigned
char \ short \ int \ long \ int64_t