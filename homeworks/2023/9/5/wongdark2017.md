# CSAPP 读书笔记

二进制补码加法

For integer values  $x$  and  $y$  in the range  $-2^{w-1} \leq x, y \leq 2^{w-1}-1 $ :

$$
x+_{w}^{\mathrm{t}} y=\left\{\begin{array}{llr}
x+y-2^{w}, & 2^{w-1} \leq x+y \quad \text { Positive overflow } \\
x+y, & -2^{w-1} \leq x+y<2^{w-1} \quad \text { Normal } \\
x+y+2^{w}, & x+y<-2^{w-1} \quad \text { Negative overflow }
\end{array}\right.
$$

计算过程：

$$
\begin{aligned}
x++_{w}^{\mathrm{t}} y & =U 2 T_{w}\left(T 2 U_{w}(x)+{ }_{w}^{\mathrm{u}} T 2 U_{w}(y)\right) \\
& =U 2 T_{w}\left[\left(x_{w-1} 2^{w}+x+y_{w-1} 2^{w}+y\right) \bmod 2^{w}\right] \\
& =U 2 T_{w}\left[(x+y) \bmod 2^{w}\right]
\end{aligned}
$$
