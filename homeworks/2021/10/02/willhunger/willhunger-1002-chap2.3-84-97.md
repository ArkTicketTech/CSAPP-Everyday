# Ch2 Representing and Manipulating Information

## 2.3 Integer Arithmetic

本节介绍有符号整数和无符号整数的算术运算，主要有加法、取反、乘法 以及 除 2 ^x^ 等。

  

无符号数的加法运算：

For $x$ and $y$ such that $0 \leq x, y<2^{w}$ :
$$
x+{ }_{w}^{\mathrm{u}} y= \begin{cases}x+y, & x+y<2^{w} \quad \text { Normal } \\ x+y-2^{w}, & 2^{w} \leq x+y<2^{w+1} \quad \text { Overflow }\end{cases}
$$

* 判断是否发生溢出：

    对于 $0 \leq x, y<UMax_{w}$ ，相加的结果为 $s = x + y$，如果 $ s < x $ 或者 $ s < y$，则发生了溢出。



无符号数的取反运算：
$$
-{ }_{w}^{\mathrm{u}} x= \begin{cases}x, & x=0 \\ 2^{w}-x, & x>0\end{cases}
$$


有符号数的加法运算：

For integer values $x$ and $y$ in the range $-2^{w-1} \leq x, y \leq 2^{w-1}-1:$ 
$$
x+{ }_{w}^{\mathrm{t}} y=\left\{\begin{array}{lll}
x+y-2^{w}, & 2^{w-1} \leq x+y \quad \text { Positive overflow } \\
x+y, & -2^{w-1} \leq x+y<2^{w-1} \quad \text { Normal } \\
x+y+2^{w}, & x+y<-2^{w-1} \quad \text { Negative overflow }
\end{array}\right.
$$


* 判断是否发生溢出：

    对于任意 $x$ 和 $y$ ，且 $TMin_{w} \leq x, y<TMax_{w}$，相加的结果为 $s = x + y$ ；

    * 如果 $ x > 0 $   和 $y > 0$ ，但 $ s \leq 0$ ，则发生了正溢出；
    * 如果 $ x < 0 $   和 $y < 0$ ，但 $ s \geq 0$ ，则发生了负溢出。



有符号数的取反运算：
$$
-{ }_{w}^{\mathrm{t}} x= \begin{cases}T \operatorname{Min}_{w}, & x=\operatorname{TMin}_{w} \\ -x, & x>\operatorname{TMin}_{w}\end{cases}
$$
取反运算的两个小技巧：

* C 中，用 `-x` 或者 `~x + 1`，树状数组中的 lowbit 操作经常用到这个手法；
* 从右到左，找到第一个 1 的位置 pos 后，从 pos + 1 开始反转所有位。





