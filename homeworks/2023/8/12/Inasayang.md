#### 整数表示

整数的数据与算数操作术语。下标w表示位数

![](https://inasa.dev/image/csapp/02/9.png)

##### 整型数据类型

-   负数的取值范围币整数的范围大1

##### 无符号数的编码

一个整数类型有w位，则写成向量$\vec{x}$，或者[x~w-1~,x~w-2~,...,x~0~]，表示向量中的每一位

![](https://inasa.dev/image/csapp/02/10.png)

![](https://inasa.dev/image/csapp/02/11.png)

无符号数的二进制中，每一个数值都有唯一一个w位的值编码。

-   如，十进制11作为无符号数，只有一个4位的表示，[1011]

无符号数编码的唯一性，函数B2U~w~是一个双射。

-   双射指函数有两面
-   每一个x有唯一的y与之对应
-   每一个y都有唯一的x与之对应（即U2B~w~）



##### 补码编码

最常见的有符号数的计算机表示方式就是补码(`two‘s-complement`)形式

将字的最高有效位解释为负权（`negative-weight`）

![](https://inasa.dev/image/csapp/02/12.png)

最高有效位x~w-1~也称符号位

-   为1时，表示负值
-   为0时，表示非负

![](https://inasa.dev/image/csapp/02/13.png)

![](https://inasa.dev/image/csapp/02/14.png)

补码所能表示的范围

![](https://inasa.dev/image/csapp/02/15.png)

B2T~w~也是一个双射函数



有符号数的其他表示方法

-   反码（`ones' Complement`）
    -   除了最高有效位的权是$-(2^{w-1}-1)$不是$-2^{w-1}$，其余一样
    -   ![](https://inasa.dev/image/csapp/02/16.png)
-   原码（`Sign-Magnitude`）
    -   最高有效位是符号位
    -   ![](https://inasa.dev/image/csapp/02/17.png)

-   这两种方法都有一种奇怪的属性，对0有两种不同的编码方式
    -   +0表示为[00...0]
    -   -0
        -   原码表示为[10...0]
        -   反码表示为[11...1]



Pp. 41-49