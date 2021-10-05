# Ch. 2 Representing and Manipulating Information
二值是信息在计算机中的基本表示方式。
* Unsigned
* Two's-Component
* Floating-point

由于数字位数限制，计算机的数字表示存在溢出。
浮点数只能做到小数的近似，而不是精确的。

## 2.1 Information Storage
本章讲解虚拟内存中数据是如何存储的。程序、指令、控制信息等。
一般计算机最小的存储单元为一个byte。
每个计算机都有 word size。 决定了虚拟地址空间的大小。
32-bits -> 64-bits

  | | 最小值 | 最大值 |
  |----------------+----------------------------+----------------------------|
  | short | -32768 | 32767 |
  | unsigned short | 0 | 65535 |
  | int | -2,147,483,648 | 2,147,483,647 |

不要用 int 存储 pointer。 这会导致软件的可移植性变差。