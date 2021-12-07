# CSAPP_12_07

## Floating Point

### 1.浮点数的表示方法：

浮点数是用二进制的科学计数法表示的 , 双精度64位为例：

​                   **value = (-1)^sign × fraction × 2^exponent**

![image-20211207110411363](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20211207110411363.png)

其中exponent和 fraction并不是直接存储。exponent = c-1023,fraction=1+m;

实际上62位到52位存的是**c**，长度为11位，所以**c**可以表示十进制数的范围是[0,2047]，0和2047有特殊的含义。1023是，32位浮点数的偏移量是127。在这里 c-1023可以表示 [-1023,1024] 区间里的整数。不考虑**c**=0和2047的情况，指数exponent的取值范围是 [2^(-1022),2^(1023)]。

关于 fraction，由于小数点前总是1所以可以不用存储，51到0位直接存储尾数m,其取值范围是[0,1-2^(-52)],所以fraction=1+m的取值范围是[1,2-2^(-52)]。

当![[公式]](https://www.zhihu.com/equation?tex=c%3D2046%EF%BC%8Cm%3D+1-2%5E%7B-52%7D) 时，双精度浮点数达到可以表示的最大正数 ![[公式]](https://www.zhihu.com/equation?tex=%5Capprox2+%5Ctimes10%5E%7B308%7D)

当 ![[公式]](https://www.zhihu.com/equation?tex=c%3D1%EF%BC%8Cm%3D+0) 时，双精度浮点数达到可以表示的最小正数 ![[公式]](https://www.zhihu.com/equation?tex=%5Capprox2+%5Ctimes10%5E%7B-308%7D)

负数的情况相同。只能近似存储，双精度的精确表示为15位有效数字，16位部分精确，单精度的只能保证6位有效数字，第七位部分精确。

两个双精度数之间的[最小相对误差](https://www.zhihu.com/search?q=最小相对误差&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"article"%2C"sourceId"%3A58731780})是 ![[公式]](https://www.zhihu.com/equation?tex=2%5E%7B-52%7D%5Capprox2.22%5Ctimes10%5E%7B-16%7D) ，所以只能保证15位有效数字，第16位只是部分精确。单精度则只能保证6位有效数字，第7位部分精确。所以在**例2**中 ![[公式]](https://www.zhihu.com/equation?tex=4.0%2B1e16%3D1.0000000000000004e16) ，恰巧第16位有效数字是部分精确的，4可以被精确表示，但是 ![[公式]](https://www.zhihu.com/equation?tex=5.0%2B1e16%3D1.0000000000000004e16) ，因为最后一位并不能表示5，所以出现了浮点数误差。 ![[公式]](https://www.zhihu.com/equation?tex=4.0%2B1e17) 的结果中的4已经在第17位，超出了双精度浮点数的最大有效位数，就被忽略了，所以有![[公式]](https://www.zhihu.com/equation?tex=4.0%2B1e17%3D1e17+%5CRightarrow+4.0%2B1e17-1e17%3D0.0) 。

部分参考来源：[详解二进制浮点数 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/58731780)