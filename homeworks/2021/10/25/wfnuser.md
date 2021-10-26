### 2.3.6 Multiplying by Constants
乘法的优化方式之一就是 用 shift 和 addition 组合来实现。
乘 2^k 等价于 直接右移 k 位 signed 和 unsigned 都是正确的

优化可以有两种表示：
FormA: (x<<n)+(x<<(n−1))+...+(x<<m) 
Form B: (x<<(n + 1)) - (x<<m)

具体和硬件有关；compiler一般只在shift的位数不多时之行这种优化。

### 2.3.7 Dividing by Powers of 2
除法比乘法更慢。
逻辑右移 -> 高位补0 unsigned
算数右移 -> 高位补最高位 signed 

x/y < 0
x/y 向上取整 = (x+y-1)/y 向下取整

取整都是往0的方向取