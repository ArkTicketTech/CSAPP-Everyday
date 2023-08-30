# CSAPP 读书笔记

阅读页数：P96 - P100

## 第二章： Representing and Manipulating Information

### 无符号整数的编码

将整数表示成由 $w$ 个比特组成的位向量$[x_{w-1},x_{w-2},\cdots,x_1,x_0]$

定义函数$B2U_w(x)\doteq \sum\limits_{i=0}^{w-1}x_i2^i$

可以发现，这个函数是一个双射。逆函数记为$U2B_w$

### 有符号整数的编码

将整数表示成由 $w$ 个比特组成的位向量$[x_{w-1},x_{w-2},\cdots,x_1,x_0]$

定义函数$B2T_w(x)\doteq -x_{w-1}\cdot 2^{w-1}+\sum\limits_{i=0}^{w-2}x_i2^i$

可以发现，这个函数是一个双射。逆函数记为$T2B_w$
