# CSAPP 读书笔记

阅读页数：P106 - P110

## 第二章： Representing and Manipulating Information

定义函数：

- $U2B_w$ 将整数 $x$ 转换成其二进制的形式
- $T2B_w$ 将整数 $x$ 转换成其二进制补码的形式
- $T2U_w(x)\doteq B2U_w(T2B_w(x))$
- $U2T_w(x)\doteq B2T_w(U2B_w(x))$

### $T2U_w$计算方法
对于 $TMin_w\leq x\leq TMax_w$:
$$
T 2 U_{w}(x)=\left\{\begin{array}{ll}
x+2^{w}, & x<0 \\
x, & x \geq 0
\end{array}\right.
$$

### $U2T_w$计算方法
对于 $0\leq x\leq UMax_w$:
$$
U 2 T_{w}(x)=\left\{\begin{array}{ll}
x, & x\leq TMax_w \\
x-2^{w}, & x > TMax_w
\end{array}\right.
$$
