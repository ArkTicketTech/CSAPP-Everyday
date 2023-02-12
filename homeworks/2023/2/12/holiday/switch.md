switch

![image-20230213011412836](image/image-20230213011412836.png)

jump statement的汇编代码

![image-20230213011431943](image/image-20230213011431943.png)

![image-20230213011447949](image/image-20230213011447949.png)

汇编代码逐行翻译：

1.复制参数z

2.比表x和6（6是这些case里面最大的数字）

3.使用跳转指令跳转到.L8（ja：jump above）

4.goto到表（跳转表，汇编程序填写）索引得到的地址，跳转到该地址