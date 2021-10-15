> ***2021.10.15\***

------

### 2.3.6 Multiplying by Constants

- 与2的幂相乘的无符号乘法：

  C变量x和k有服务号数值x和k，且$0\leqslant k < w$，则表达式x<<k产生数值$x*_w^u2^k$。

- 与2的幂相乘的补码乘法：

  C变量x和k有补码值x和无符号数值k，且$0\leqslant k < w$，则表达式x<<k产生数值$x*_w^t2^k$。

对于某个常数K的表达式x*K生成代码。Kde二进制表示为$[(0\cdots0)(1\cdots1)(0\cdots0)\cdots(1\cdots1)]$，考虑从位置n到位置m的连续1（$n\geqslant m$）。有两种不同形式来计算这些位对于乘积的影响。

- (x<<n)+(x<<(n-1))+...+(x<<m)
- (x<<(n+1))-(x<<m)

### 2.3.7 Dividing by Powers of 2

- 除以2的幂的无符号除法：

  C变量x和k有无符号数值x和k，且$0\leqslant k < w$，则C表达式x>>k产生数值$\lfloor x/2^k\rfloor$。

- 除以2的幂的补码除法，向下舍入：

  C变量x和k有补码值x和无符号数值k，且$0\leqslant k < w$，则当执行算数位移时，C表达式x>>k产生数值$\lfloor x/2^k\rfloor$。

- 除以2的幂的补码除法，向上舍入：

  C变量x和k有补码值x和无符号数值k，且$0\leqslant k < w$，则当执行算数位移时，C表达式(x+(1<<k)-1)>>k产生数值$\lceil  x/2^k \rceil$ 。

计算$x/2^k$的C表达式：`(x<0 ? x+(1<<k)-1 : x >> k`

### 2.3.8 Final Thoughts on Integer Arithmetic

无

