> ***2021.10.13\***

------

### 2.3.4 Unsigned Multiplication

无符号数乘法：

对$0\leqslant x,y\leqslant UMax_w$的x和y：

$$x*^u_wy=(x\cdot y)\text{ mod }2^w$$

### 2.3.5 Two’s-Complement Multiplication

补码乘法

对$TMin_w\leqslant x,y \leqslant TMax_w$的x和y：

$$x*^t_wy=U2T_w((x\cdot y)\text{ mod }2^w)$$

无符号和补码乘法的位级等价性：

给定长度为w的位向量$\vec{x}、\vec{y}$，用补码形式表示的整数$x=B2T_w(\vec{x})$，$y=B2T_w(\vec{y})$，用无符号形式表示的非负整数$x^{'}=B2U_w(\vec{x})$，$y^{'}=B2U_w(\vec{y})$：

$$T2B_w(x*^t_wy)=U2B_w(x^{'}*^u_wy^{'})$$

虽然服务号和补码乘法完整的乘积表示不同，但是截断后的位级表示相同。

