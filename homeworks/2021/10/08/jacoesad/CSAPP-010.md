> ***2021.10.08\***

------

### 2.2.3 Two’s-Complement Encodings

有符号数的计算表示方式是补码。其中最高有效为解释位负权（negative weight）。

使用$B2T_w$（Binary to Two‘s-complement，长度$w$）表示补码，定义为：

$$B2T_w(\vec{x})\dot=-x_{w-1}2^{w-1}+\sum_{i=0}^{w-2}x_i2^i$$

最高有效位$x_{w-1}$称为符号位，权重为$-2^{w-1}$。当符号为1时，表示负数。

w位补码能表示的最小值向量为$[100\cdots0]$，$TMin_w\dot=-2^{w-1}$。

w位补码能表示的最大值向量为$[011\cdots1]$，$TMax_w\dot=\sum_{i=0}^{w-2}2^i=2^{w-1}-1$。

1. 补码范围不对称：$|TMin|=|TMax|+1$，原因补码表示是负数与非负数的数量相同，0是非负数，所以正数比负数少一个
2. $UMax_w=2TMax_w+1$

