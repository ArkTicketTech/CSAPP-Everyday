# CSAPP读书笔记

## 整数运算

无符号整数加法：

对于 $0\leq x,y<2^w$

$$
x+{ }_{w}^{\mathrm{u}} y=\left\{\begin{array}{ll}
x+y, & x+y<2^{w} \quad \text { Normal } \\
x+y-2^{w}, & 2^{w} \leq x+y<2^{w+1} \quad \text { Overflow }
\end{array}\right.
$$

无符号整数的相反数：

对于 $0\leq x<2^w$：

$$
-{ }_{w}^{\mathrm{u}} x=\left\{\begin{array}{ll}
x, & x=0 \\
2^{w}-x, & x>0
\end{array}\right.
$$

无符号整数检测溢出(overflow):

For  $x$  and  $y$  in the range  $0 \leq x, y \leq \operatorname{UMax}_{w}$ , let  $s \doteq x+_{w}^{\mathrm{u}} y$ . Then the computation of  s  overflowed if and only if  $s<x$  (or equivalently,  $s<y$  ).
