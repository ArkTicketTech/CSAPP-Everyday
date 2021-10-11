> ***2021.10.10\***

------

### 2.2.6 Expanding the Bit Representation of a Number

无符号数的零扩展：

宽度为$w$的位向量$\vec{u}=[u_{w-1},u_{w-2},\cdots,u_0]$和宽度为$w^{'}$的位向量$\vec u^{'}=[0,\cdots,0,u_{w-1},u_{w-2},\cdots,u_0]$，其中$w^{'}>w$。则$B2T_w(\vec u)=B2T_{w^{'}}(\vec u^{'})$。

补码输的符号扩展

宽度为$w$的位向量$\vec{x}=[x_{w-1},x_{w-2},\cdots,x_0]$和宽度为$w^{'}$的位向量$\vec x^{'}=x_{w-1},\cdots,x_{w-1},x_{w-1},x_{w-2},\cdots,x_0]$，其中$w^{'}>w$。则$B2T_w(\vec x)=B2T_{w^{'}}(\vec x^{'})$。

### 2.2.7 Truncating Numbers

截断无符号数：

位向量$\vec{x}=[x_{w-1},x_{w-2},\cdots,x_0]$，$\vec x^{'}$是其截断$k$位的结果$\vec x^{'}=[x_{k-1},x_{k-2},\cdots,x_0]$。令$x=B2U_w(\vec x)$，$x^{'}=B2U_{k}(\vec x^{'})$，则$x^{'}=x\text{ mod }2^k$。

截断补码数值：

位向量$\vec{x}=[x_{w-1},x_{w-2},\cdots,x_0]$，$\vec x^{'}$是其截断$k$位的结果$\vec x^{'}=[x_{k-1},x_{k-2},\cdots,x_0]$。令$x=B2U_w(\vec x)$，$x^{'}=B2T_{k}(\vec x^{'})$，则$x^{'}=U2T_k(x\text{ mod }2^k)$。

总结也就是对于补码，需要将阶段结果转为补码数。

### 2.2.8 Advice on Signed versus Unsigned

有符号数到无符号数数的隐式转换，会导致错误的方式。避免的方式就是不使用无符号数。

当需要把字仅看作是位的集合不使用数字意义得时候，无符号数值是很有用的。

- 比如将各种布尔条件的标记放到一个字中的时候
- 地址也是无符号的
- 模运算
- 多精度运算的数学包

