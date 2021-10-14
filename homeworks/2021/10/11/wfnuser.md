### 2.2.2 unsigned encoding
B2U binary -> unsigned

1*2^3+1*2^2+1*2^1+1*2^0

### 2.2.3 Two’s-Complement Encodings
B2T binary -> two’s complement

−1*2^3+1*2^2+1*2^1+1*2^0 = 1111(4)
首位补码 -2^(w-1)

|TMin| = |TMax| + 1
C标准并没有要求所有的有符号整型采用 Two's Complement 编码；但所有的机器都是这样做的。

其他的编码方式包括：
1. one's complement ： 第一位为 -2^(w-1)+1
2. sign magnitude ： 第一位只是用来标记正负

