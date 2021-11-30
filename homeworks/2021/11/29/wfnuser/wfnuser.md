# 2.4 Floating Point
浮点类型 有理数编码成 $V = x * 2^y$ 
可以帮助我们处理带有很大和很小的数字的计算；但得到的是一个近似精确的结果。
1980年前 计算机对浮点都有自己的处理 并不是很在意准确度；更在意计算速度和易于实现。
IEEE Standard 754 是 1985 年提出的对浮点数编码的规范。

### 2.4.1 Fractional Binary Numbers 
常规的数字小数表示： $d_md_{m-1}d_{m-2}...d_0d_{-1}d_{-2}...d_{-n}$

对应的值为 $\sum_{i=-n}^{m}2^i*b_i$

但二进制下的表示中，有限位的表示中，我们无法精确的表示 1/3 或者 5/7 这样的数字。

### 2.4.2 IEEE Floating-Point Representation
$V = (-1)^s*M*2^E$
其中 s是符号位；M用于表示具体的数值；E用来移动小数点的位置。
float  31 ｜ 30-23 ｜ 22-0
double 63 ｜ 62-52 ｜ 51-0

1. Normalized Values
2. Denormalized Values
3. Special Values: Infinity & NaN