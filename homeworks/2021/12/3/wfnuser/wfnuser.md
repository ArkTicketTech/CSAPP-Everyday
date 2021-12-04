## 2.4.6 Floating Point in C
int to float : 不会溢出；会rounded
int or float to double : 数据可以完整保留
double to float: 会溢出 也会rounded
float or double to int： 往0的方向取整

# 2.5 总结
- signed - unsigned 转化不会比变化数字
- 计算因为溢出等原因会有奇怪的结果 比如 x*x 可能是负数； 但整型类型都是满足交换律和结合律的，所以编译器可以做很多优化。
- 浮点表达式不符合结合律 不能随意优化
