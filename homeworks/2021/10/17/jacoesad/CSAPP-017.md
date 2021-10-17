> ***2021.10.17\***

------

## 2.4 Floating Point

浮点数表示对形如$V=x \times 2^y$的有理数进编码。

### 2.4.1 Fractional Binary Numbers

对于十进制表示法数字表示如下：

$$d_md_{m-1}\cdots d_{1}d_{0}.d_{-1}d_{-2}\cdots d_{-n}$$

即

$$d=\sum_{i=-n}^m 10^i\times d_{i}$$

对于二进制，类似的表示为：

$$b=\sum_{i=-n}^m 2^i\times b_{i}$$

小数的二进制只能精确表示能被写成$x\times 2^y$的数。

### 2.4.2 IEEE Floating-Point Representation

IEEE浮点数标准，$V=(-1)^s\times M \times 2^E$表示浮点数：

- 符号（sign）s决定这个是正数（s=0）还是负数（s=1），对于0的符号位特殊处理。
- 尾数（significand）M是一个二进制小数，范围为$1～2-\varepsilon$，或者$0～1-\varepsilon$。
- 阶码（exponent）E的作用是对浮点数加权，权重是2的E次幂。

将浮点数的位表示划分为三个字段，分别对这些值编码：

- s：一个单独的符号位直接编码
- E： k位的阶码字段$\text{exp}=e_{k-1}\cdots e_1e_0$
- M：n位小数字$段frac=f_{n-1}\cdots f_1f_0$

对于单精度float，k=8，n=23；对于双精度double，k=11，n=52。

根据exp的值，被编码的值可以分为三种不同情况：

1. 规格化的值

   当exp的位既不全为0也不全为1，属于这种情况。

   码阶被解释为以偏置形式（biased）表示的有符号整数。阶码的值是$E=e-Bias$，其中e为无符号数exp，Bias为$2^{k-1}-1$（float为127，double为1023）。

   frac被描述为小数值f，其中$0 \leqslant f<1$，二进制表示为$0.f_{n-1}\cdots f_1f_0$。尾数定义为$M=1+f$

2. 非规格化的值

   当阶码域全为0是，表示非规格化形式。

   这种情况下阶码为$E=1-bias$，而尾数$M=f$。

   非规格化数用来表示0或者是非常接近0.0的数。

3. 特殊值

   当阶码全为1是表示特殊值。

   - 当小数域全为0是，表示无穷，当s=0是正无穷，当s=1是负无穷。
   - 当小数域非全0，表示NaN。