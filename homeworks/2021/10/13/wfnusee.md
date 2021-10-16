### 2.2.4 signed <-> unsigned
```
short int v = -12345;
unsigned short uv = (unsigned short) v;
printf("v = %d, uv = %u \n", v, uv);

v = -12345;
vn = 53191;

usigned u = 4294967295u;
int tu = (int) u;

u = 4294967295u;
tu = -1;
```

强制转换；数值变化但bit表示不变

### 2.2.5 signed versus unsigned in C
12345U -> unsigned

```
显示转换
tx = (int) ux;
uy = (unsigned) ty;

隐式转换
int tx, ty;
unsigned ux, uy;
tx=ux;/*Cast to signed */ 
uy=ty;/*Cast to unsigned */
```

signed 和 unsigned 一起运算时 默认转换为 unsigned 一起运算
所以 -1 < 0U 返回 false
