### 3.10.4 Thwarting Buffer Overflow Attacks
编译器和操作系统为了避免缓冲区溢出攻击 做了许多努力

#### Stack Randomization
曾经，stack的地址是很好预测的，许多机器分配的地址是非常固定的。在一台机器上运行下面的代码，就可以得到许多不同机器的栈的地址。

```cpp
int main() {
    long local;
    printf("local at %p\n", &local);
    return 0; 
}
```
而攻击者进行缓冲区溢出攻击的核心之一就是要准确的预测栈的地址，从而注入期望的return地址。
所以一种防御方式就是让栈的地址随机化。一种实现时，程序开始时会分配一段随机大小的内存不使用，这就会导致不同机器不同程序的栈的地址都不一样。从而给攻击者造成了困难。
但是，攻击者仍然可以通过一定的技巧辅以暴力破解进行攻击。具体做法是让 exploit code 开头有一段很长的 no-op 指令，这样只要 return 到 no-op 的地址，最终都会执行到 exploit code 。 从概率上来说，对于有决心的攻击者，这是可以接受的。 比如开一段 256-bytes 的 no-op 指令，在 $2^23$ 的随机范围内， 攻击者只要尝试 $2^15$ 次初始地址即可。