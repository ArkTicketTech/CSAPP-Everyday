# Ch2 Representing and Manipulating Information

## 2.3 Integer Arithmetic

无符号数的乘法运算：

无符号整数 $x$ 和  $y$ 有 $0 \leq x, y \leq 2^{w} - 1$  ，但其乘积范围在 $ 0 \leq x* y \leq 2^{2w} - 2^{w + 1} + 1$ ，结果需要 $2w$ 位来表示，在 C 中仅用低 $w$ 来表示溢出结果。

For $x$ and $y$ such that $0 \leq x, y \leq U M a x_{w}:$
$$
x *_{w}^{\mathrm{u}} y=(x \cdot y) \bmod 2^{w}
$$
有符号数的乘法运算：

有符号整数 $x$ 和 $y$ 有 $-2^{w - 1} \leq x, y \leq 2^{w - 1} - 1$ ，但其乘积的范围在 $-2^{w - 1} + 2^{w - 1} \leq 2^{2w - 2}$ ，发生溢出，截断到低 $w$ 位表示结果。

For $x$ and $y$ such that $\operatorname{TMin}_{w} \leq x, y \leq \operatorname{TMax}_{w}$ :
$$
x *_{w}^{\mathrm{t}} y=U 2 T_{w}\left((x \cdot y) \bmod 2^{w}\right)
$$


乘以常数：

* 整数乘法指令速度慢，需要的时钟周期常与其他整数运算（加法、减法、位运算、移位），因此，编译器常常用加法、减法、移位等运算组合来代替常数因子的乘法；
*  因此，对于 $x * K$，可用下面的方法来代替乘法运算：
    * Form A: $(x<<n)+(x<<(n-1))+\cdots+(x<<m)$
    * Form B: $(x<<(n+1))-(x<<m)$
* 例如，$ 14 = 2^3 + 2^2 + 2^1$，那么 $x * 14$ 可化简位如下：
    * $(x << 3) + (x << 2) + (x << 1)$
    * $(x << 4) - (x << 1)$



除以 2 的幂次：

* 除法指令需要的时钟周期比整数除法指令更长，因此，编译器会使用右移运算来优化除以 2 的幂次运算；

* 在除法运算中，存在两种取整方法：

    * 对于 $x >=0, y >0$，$x/y = \lfloor x/y \rfloor $； 对于 $x < 0, y > 0$ ，$x/y = \lceil x/y \rceil $；
    * 即结果为正数时，向下取整；结果为负数时，向上取整；

* 无符号数除以 2 的幂次：

    For C variables $x$ and $k$ with unsigned values $x$ and $k$, such that $0 \leq k<w$, the $\mathrm{C}$ expression $\mathrm{x}>>\mathrm{k}$ yields the value $\left\lfloor x / 2^{k} \rfloor \right.$ .

* 有符号数除以 2 的幂次，向下取整：

    Let $\mathrm{C}$ variables $\mathrm{x}$ and $\mathrm{k}$ have two's-complement value $x$ and unsigned value $k$, respectively, such that $0 \leq k<w$. The $\mathrm{C}$ expression $\mathrm{x}>>\mathrm{k}$, when the shift is performed arithmetically, yields the value $\left\lfloor x / 2^{k}\right\rfloor$.

* 有符号数除以 2 的幂次，向上取整：

    Let $\mathrm{C}$ variables $\mathrm{x}$ and $\mathrm{k}$ have two's-complement value $x$ and unsigned value $k$, respectively, such that $0 \leq k<w$. The $\mathrm{C}$ expression $(\mathrm{x}+(1<<\mathrm{k})-1)>>\mathrm{k}$, when the shift is performed arithmetically, yields the value $\left\lceil x / 2^{k}\right\rceil$.

* 此外，向上取整和向下取整之间可以相互转换：

    $\lceil x / y\rceil=\lfloor(x+y-1) / y\rfloor$

* 在 C 中的表示为：`(x < 0 ? x + (1 << k) - 1 : x) >> k`

 

小结：

* 计算机的整数运算实质上是模运算形式。无论是有符号数还是无符号数，运算规则都相差不大；
* 使用整数常数和库函数时，需要注意数据类型。

