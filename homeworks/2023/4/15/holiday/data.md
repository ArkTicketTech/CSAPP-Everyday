多维数组获取元素

二维数组获取元素的汇编代码

![image-20230416000150711](image/image-20230416000150711.png)

左移%rsi两位，这相当于digit乘上4

读univ得到的值，将索引放大8倍来做实际的内存引用

![image-20230416000208864](image/image-20230416000208864.png)

n乘n数组访问的汇编代码

![image-20230416000223714](image/image-20230416000223714.png)