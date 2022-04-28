---
title: csapp-note-2022-04-27
tags:
  - csapp
  - 操作系统
  - 编译原理
  - CS基础知识
  - 读书笔记
cover: 'https://source.unsplash.com/random'
date: 2022-04-27 21:03:55
---

- Q1: 如何检测无符号数溢出？
- Q2: 为什么可以这样？

![2-20-unsign-addition-overflow.png](assets/2-20-unsign-addition-overflow.png)


- 如何检测有符号数溢出？

![2-21-signed-addition-overflow-positive-neg.png](assets/2-21-signed-addition-overflow-positive-neg.png)


![2-22-detect-signed-overflow.png](assets/2-22-detect-signed-overflow.png)

- 无符号数加法逆元

![2-23-unsign-addition-inverse.png](assets/2-23-unsign-addition-inverse.png)

- 有符号数加法逆元
  - $T_{min}$ 加法逆元 $x=T_{min}$

![2-24-signed-addition-inverse.png](assets/2-24-signed-addition-inverse.png)

- 为什么两个相同位数，用二进制表示的无符号数和有符号数的乘积依然相同？
  - 怎么证明？

![2-25-prove-of-signed-unsigned-same-binary-results.png](assets/2-25-prove-of-signed-unsigned-same-binary-results.png)

- 如何证明乘法可以用左移运算代替
  - 2的整数次幂
  - 如何推广到任意数？

![2-26-why-unsign-multiply-equal-shift.png](assets/2-26-why-unsign-multiply-equal-shift.png)


![2-26-why-unsign-multiply-equal-shift-2.png](assets/2-26-why-unsign-multiply-equal-shift-2.png)

- 除法取整的规则

![2-27-devide-round.png](assets/2-27-devide-round.png)

- 二进制浮点数

![2-28-binary-floating-repre.png](assets/2-28-binary-floating-repre.png)

- IEEE的浮点数表示规则

![2-29-IEEE-floating-point-repre.png](assets/2-29-IEEE-floating-point-repre.png)

- 四种浮点数
  - 正规化
  - 非正规化
  - 无穷大
  - not a number, NaN

![2-30-four-types-of-floating-point.png](assets/2-30-four-types-of-floating-point.png)



![2-31-normalized-floating-point.png](assets/2-31-normalized-floating-point.png)


![2-32-denormalized-floating-point-2-useful-cases.png](assets/2-31-normalized-floating-point.png)


![2-33-inf-floating-point-2-useful-cases.png](assets/2-33-inf-floating-point-2-useful-cases.png)


![2-34-not-a-num-floating-point.png](assets/2-34-not-a-num-floating-point.png)

- 一个八位非正规化浮点数例子

![2-35-8-bits-denormalized-floating-point-example.png](assets/2-35-8-bits-denormalized-floating-point-example.png)

- 一个八位正规化浮点数例子

![2-36-8-bits-normalized-floating-point-example.png](assets/2-36-8-bits-normalized-floating-point-example.png)