# CSAPP_12_09 汇编代码

## 数据格式

字节：byte，8位；字：word，16位；双字：double words，32位；四字：quad words，64位。

对应的指令后缀：movb, movw, movl, movq。

## 数据传送指令

**mov类**

mov 只会更新目的操作数指定的寄存器字节或内存位置。

mov 类是最简单的数据传送指令，mov 类有 5 种：

1. movb, movw, movl：传送字节、字、双字
2. movq：传送四字。如果源操作数是立即数，只能是双字，然后符号扩展到四字（假的四字）
3. movabsq：传送绝对的四字。只能以立即数作为源操作数，以寄存器为目的。可以传送任意 64 位立即数。

movq 用来传送**寄存器和内存引用中的四字**，movabsq 用来传送**四字的立即数**

mov 类的源操作数和目的操作数不能同时为内存，即不能将值从内存复制到内存。

mov 指令中寄存器的大小必须与 mov 的后缀字符大小匹配。

**movz类**

movz 系列和 movs 系列可以把较小的源值复制到较大的目的，**目的都是寄存器**。

movz 将目的寄存器剩余字节做**零扩展**，movs 做**符号扩展**

movz类：movzbw, movzbl, movzbq, movzwl, movzwq（movzbw 即从字节复制到字，其他类似）

movs类：movsbw, movsbl, movsbq, movswl, movswq, movslq, cltq

cltq：没有操作数，将 eax 符号扩展到 rax，等价于 movslq %eax,%rax

**数据传送**

局部变量通常保存在寄存器中。

函数返回指令 ret 返回的值为**寄存器 rax** 中的值

**强制类型转换**是通过 mov 指令实现的。

当指针存在寄存器中时，a = *p 的汇编指令为： mov (rdi), rax

**压入和弹出栈数据**

**栈向下增长**，栈顶的地址是栈中元素地址中最低的。栈指针 rsp 保存栈顶元素的地址。

出入栈指令：

- pushq rax：压栈，**栈指针减 8** 并将 rax 中的值写入新的栈顶地址，等价于：subq $8, (rsp) ; movq rax,(rsp)。
- popq rax：出栈，**栈指针加 8** 并将出栈的值写入 rax 中，等价于：movq (rsp),rax ; add $8,(rasp)

使用 mov 指令和标准的内存寻址方法可以访问**栈内的任意位置**，而非仅限于栈顶。