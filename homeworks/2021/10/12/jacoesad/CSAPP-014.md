> ***2021.10.12\***

------

### 2.3.2 Two’s-Complement Addition

补码加法：

对于满足$-2^{w-1}\leqslant x,y \leqslant 2^{w-1}-1$的整数x、y，有：

$$x+_w^ty=\begin{cases} x+y-2^w, &  2^{w-1}\leqslant x+y &正溢出\\ x+y, &  -2^{w-1}\leqslant x+y<2^{w-1} &正常\\ x+y+2^w, & x+y<-2^{w-1}& 负溢出 \end{cases}$$

- 当x+y超过$TMax_w$时，我们说发生了正溢出，截断结果是从和数中减去$2^w$。
- 当x+y超过$TMin_w$时，我们说发生了负溢出，截断结果是把和数加上$2^w$。

$$x+_w^ty=U2T_w[(x+y)\text{ mod }2^w]$$

检测补码加法溢出：

对于满足$TMin_w\leqslant x,y \leqslant TMax_w$的x、y，令$s\dot=x+_w^ty$。

- 当且仅当$x>0,y>0$，但$s\leqslant 0$时，计算s发生了正溢出。
- 当且仅当$x<0,y<0$，但$s\geqslant 0$时，计算s发生了负溢出。

### 2.3.3 Two’s-Complement Negation

补码的非

对于满足$TMin_w\leqslant x,y \leqslant TMax_w$的x，其补码的非$-_w^tx$为：

$$-_w^tx=\begin{cases} TMin_w,&x=TMin_w\\ -x,&x>TMin_w \end{cases}$$

> 对补码求反的一种方法是，对于从右往左的第一个1的位置，对右面（不包括这个1以及左面的0）所有位取反。

