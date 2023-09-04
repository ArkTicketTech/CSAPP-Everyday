# CSAPP读书笔记

## 数字的截断

$$
B2U_w([x_{w-1},x_{w-2},\cdots,x_0]) \mod{2^k}\\=B2U_k([x_{k-1},x_{k-2},\cdots,x_0])
$$

$$
B2T_k([x_{k-1},x_{k-2},\cdots,x_0]) \\=U2T_k(B2U_k([x_{k-1},x_{k-2},\cdots,x_0])\mod{2^k})
$$

## 编程建议

为了避免bug,不建议使用unsigned类型。
