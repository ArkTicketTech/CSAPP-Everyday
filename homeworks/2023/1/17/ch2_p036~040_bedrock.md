# 表示字符串
```c
const char *s = "abcdef";
show_bytes((byte_pointer) s, strelen(s));
```
结果
```bash
andy@DESKTOP-KGG10L6:~/csapp/2$ ./2_1_1
61 62 63 64 65 66
```
# 表示代码
不同的机器类型使用不同且不兼容的指令和编码方式。二进制代码很少能在不同机器和操作系统间移植。
从机器角度来看，程序仅仅是字节序列。
