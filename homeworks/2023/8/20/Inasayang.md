##### 补码加法

对于$-2^{w-1}\leq x,y \leq 2^{w-1}-1$，和在范围$-2^w \leq x+y \leq 2^w-2$之内

可能需要$w+1$位，通过截断到$w$位来避免数据扩张

![](https://inasa.dev/image/csapp/02/21.png)

![](https://inasa.dev/image/csapp/02/22.png)

##### 

补码的非

![](https://inasa.dev/image/csapp/02/23.png)



##### 无符号乘法

对于$0\leq x,y \leq 2^{w-1}$，乘积$x*y$的取值范围$0 - ({2^w-1})^2$

可能需要$2w$位，通过截断使用低$w$位表示（计算该值模$2^w$）

![](https://inasa.dev/image/csapp/02/24.png)



Pp. 62-67