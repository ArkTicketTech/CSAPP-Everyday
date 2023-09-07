# CSAPP读书笔记


二进制补码的取反：
For  $x$  in the range  $\operatorname{TMin}_{w} \leq x \leq \operatorname{TMax}_{w}$ , its two's-complement negation  ${ -}^{\mathrm{t}}_{w} x$  is given by the formula

$$
-_{w}^{\mathrm{t}} x=\left\{\begin{array}{ll}
\operatorname{TMin}_{w}, & x=\operatorname{TMin}_{w} \\
-x, & x>\operatorname{TMin}_{w}
\end{array}\right.
$$

二进制补码的乘法：

$$
x*_w^t y= U2T((x\cdot y)\mod{2^w})
$$
