## 2.3.2 Two's-Complement Addition

-2^(w-1) <= x+y <= 2^w - 2
-->

x+y = x+y-2^w when x+y >= 2^z(w-1)
x+y = x+y+2^w when x+y < -2^(w-1)

unsigned 加法 和 two's-complement 加法 在二进制表示上其实是一样的

直接 U2T((x+y)mod2^w) 即可

x>0 && y>0 && (x+y) <= 0 正溢出
x<0 && y<0 && (x+y) >= 0 负溢出