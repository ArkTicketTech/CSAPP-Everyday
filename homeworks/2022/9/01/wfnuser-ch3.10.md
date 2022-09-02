### 3.10.4 Thwarting Buffer Overflow Attacks

Limiting Executable Code Regions

最后一种方式是阻止攻击者插入可执行的异常代码。通常的做法就是限制内存区域的可执行性。过去很长一段时间里，只有 readable 和 writable 两种。 readable 和 executable 共用同一位标志位，从而，stack里的区域都是可执行的。 
后来amd和intel都引入了 non-executable 的标志位，我们可以利用这种技术，限制只有刚开始由编译器和操作系统生成的可执行代码的内存部分为可执行的，进而避免缓冲区攻击。

一些类似于JIT的技术，会在运行期间动态生成二进制的可执行代码，这样的代码是否可被限制取决于编译器的实现。

总结一下，随机化、栈检查和限制可执行性是三种最常见的防止攻击的手段。