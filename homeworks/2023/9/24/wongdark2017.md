# CSAPP 读书笔记


前六个寄存器(%rax, %rbx, %rcx, %rdx, %rsi, %rdi)称为通用寄存器，有其『特定』的用途：

* %rax(%eax) 用于做累加
* %rcx(%ecx) 用于计数
* %rdx(%edx) 用于保存数据
* %rbx(%ebx) 用于做内存查找的基础地址
* %rsi(%esi) 用于保存源索引值
* %rdi(%edi) 用于保存目标索引值

而 %rsp(%esp) 和 %rbp(%ebp) 则是作为栈指针和基指针来使用的。下面我们通过 `movq` 这个指令来了解操作数的三种基本类型：立即数(Imm)、寄存器值(Reg)和内存值(Mem)。

对于 `movq` 指令来说，需要源操作数和目标操作数，源操作数可以是立即数、寄存器值或内存值的任意一种，但目标操作数只能是寄存器值或内存值。指令的具体格式可以这样写 `movq [Imm|Reg|Mem], [Reg|Mem]`，第一个是源操作数，第二个是目标操作数，例如：

* `movq Imm, Reg` -> `mov $0x5, %rax` -> `temp = 0x5;`
* `movq Imm, Mem` -> `mov $0x5, (%rax)` -> `*p = 0x5;`
* `movq Reg, Reg` -> `mov %rax, %rdx` -> `temp2 = temp1;`
* `movq Reg, Mem` -> `mov %rax, (%rdx)` -> `*p = temp;`
* `movq Mem, Reg` -> `mov (%rax), %rdx` -> `temp = *p;`

这里有一种情况是不存在的，没有 `movq Mem, Mem` 这个方式，也就是说，我们没有办法用一条指令完成内存间的数据交换。

上面的例子中有些操作数是带括号的，括号的意思就是寻址，这也分两种情况：

* 普通模式，(R)，相当于 `Mem[Reg[R]]`，也就是说寄存器 R 指定内存地址，类似于 C 语言中的指针，语法为：`movq (%rcx), %rax` 也就是说以 %rcx 寄存器中存储的地址去内存里找对应的数据，存到寄存器 %rax 中
* 移位模式，D(R)，相当于 `Mem[Reg[R]+D]`，寄存器 R 给出起始的内存地址，然后 D 是偏移量，语法为：`movq 8(%rbp),%rdx` 也就是说以 %rbp 寄存器中存储的地址再加上 8 个偏移量去内存里找对应的数据，存到寄存器 %rdx 中
