> ***2021.10.09\***

------

### 2.2.4 Conversions between Signed and Unsigned

定义函数$U2B_w$和$T2B_w$，分别表示将数映射成无符号数和补码的位表示。

给定一个$TMin_w～TMax_w$的数字，得到$0～UMax_w$一个数字，函数定义为：

$$T2U_w(x)\dot=B2U_w(T2B_w(x))$$

类似，给定一个$0～UMax_w$数字：

$$U2T_w(x)\dot=B2T_w(U2B_w(x))$$

对于满足$TMin_w\leqslant x\leqslant TMax_w$的$x$有：

$$T2U_w(x)= \begin{cases} x+2^w, &  x<0\\ x, & x\geqslant0 \end{cases}$$

也有，其中位$w-1$决定了$x$是否为负：

$$B2U_w(T2B_w(x))=T2U_w(x)=x+x_{w-1}2^w$$

对于满足$0\leqslant x\leqslant UMax_w$的$u$有：

$$U2T_w(u)= \begin{cases} u, &  u\leqslant TMax_w\\ u-2^w, & u>TMax_w \end{cases}$$

也有，其中位$w-1$决定了$u$是否为大于$TMax_w=2^{w-1}-1$：

$$U2T_w(u)=-u_{w-1}2^w+u$$

无符号数与补码的互相转换：

- 对于$0\leqslant x\leqslant TMax_w$，无符号数与补码相同
- 对于其他，需要加上或者减去$2^w$

### 2.2.5 Signed versus Unsigned in C

几乎所有机器都使用补码表示数字。

要定义一个无符号常量，必须加上后缀字符‘U’或者‘u‘。

- 当无符号数转换为有符号数时，效果就是$U2T_w$
- 当有符号数转换为无符号数时，效果就是$T2U_w$

当执行一个运算时，如果一个是有符号数另一个是无符号数，C语言或隐式的将有符号数强制转换为无符号数，然后执行运算。

> C语言定义 `INT_MIN`为`-INT_MAX-1`

