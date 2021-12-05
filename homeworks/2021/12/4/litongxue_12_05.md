# CSAPP_12_05

## Bits, Bytes,Integer

（1）循环异常的情况:

<img src="C:\Users\ASUS\Desktop\csapp\微信图片_20211205110929.png" style="zoom:60%;" />

`#include<iostream>

using namespace std;

int a[6] = {1,2,3,4,5};

int main() {
	unsigned i = 0;
	for (i = 5; i >= 0; i--) {
		printf("%d ", a[i]);
	}
}`

循环远远超出了内存界限，因为i总时大于等于零的。

(2) 无符号整数

![](C:\Users\ASUS\Desktop\csapp\微信图片_20211205113106.png)

无符号整数的截断，当相加超过了位数限制会进行截断，没有提示信息。



