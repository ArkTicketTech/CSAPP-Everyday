> ***2021.10.11\***

------

## 2.3 Integer Arithmetic

### 2.3.1 Unsigned Addition

对于参数x、y定义运算$+_w^u$，其中$0\leqslant x,y \leqslant 2^w$，该操作把x+y截断为w位的结果，并看作是无符号数。这也可以看作是一种模运算。

$$x+_w^uy=\begin{cases} x+y, &  x+y<2^w &正常\\ x+y-2^w, & 2^w\leqslant x+y<2^{w+1}& 溢出 \end{cases}$$

算数运算溢出，是指完整的结果不能存放到数据类型的字长限制中去。

C不会将溢出作为错误而发送信号。如果需要检测无符号加法溢出：

对在范围$0\leqslant x,y\leqslant UMax_w$中的x和y，令$s\dot=x+_w^uy$。当且仅当s<x或者s<y时，发生了溢出。

> 模数加法形成了一种称为阿贝尔群的数学结构。它是可交换以及可结合的。它有一个单位元0，并且每个元素有一个加法逆元。

无符号数求反，对满足$0\leqslant x \leqslant 2^w$的任意x，其w位的无符号逆元$-_w^ux$：

$$-_w^ux=\begin{cases} x,&x=0\\ 2^w-x,&x>0 \end{cases}$$

