## 2.2.6 Expanding the Bit Representation of a Number
小类型到大类型转换
零扩展：unsigned 类型转向更大的类型 前面加零即可
如果 two's-complement 类型转向更大的类型；扩展方式为该数字首位的数字添加n次至需扩展的每一位
这是因为 11111[1] ... = [1] ... & 00000[0] ... = [0] ...


unsigned -> signed 和 short -> larger size 转化的顺序对转化结果有影响

## 2.2.7 Truncating Numbers
w-bit -> k-bit drop掉高位 w - k 位数字