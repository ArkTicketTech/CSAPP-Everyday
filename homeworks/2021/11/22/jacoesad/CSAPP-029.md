> ***2021.11.22\***

------

### 3.6.3 Jump Instructions

正常执行情况下，指令按顺序一条条执行。跳转（jump）指令会导致程序切换到程序中一个新位置。在汇编代码中，这些跳转的目的地通常用一个标号（label）指明。

jmp指令是无条件跳转。可以直接跳转，也可以是间接跳转。

- `jmp %rax` ：用寄存器%rax中的值作为跳转目标；
- `jmp *(%rax)`：以%rax中的值为读地址，从内存中读取跳转目标。

| 指令         | 同义词 | 跳转条件     | 描述                  |
| ------------ | ------ | ------------ | --------------------- |
| jmp Lable    |        | 1            | 直接跳转              |
| jmp *Operand |        | 1            | 间接跳转              |
| je  Lable    | jz     | ZF           | 相等/零               |
| jne Lable    | jnz    | ~ZF          | 不相等/非零           |
| js  Lable    |        | SF           | 负数                  |
| jns Lable    |        | ~SF          | 非负数                |
| jg  Lable    | jnle   | ~(SF^OF)&~ZF | 大于（有符号>）       |
| jge Lable    | jnl    | ~(SF^OF)     | 大于等于（有符号≥）   |
| jl  Lable    | jnge   | SF^OF        | 小与（有符号<）       |
| jle Lable    | jng    | (SF^OF)      | ZF                    |
| ja  Lable    | jnbe   | ~CF&~ZF      | 超过（无符号>）       |
| jae Lable    | jnb    | ~CF          | 超过或相等（无符号≥） |
| jb  Lable    | jnae   | CF           | 低于（无符号<）       |
| jbe Lable    | jna    | CF           | ZF                    |

### 3.6.4 Jump Instruction Encodings

跳转指令有几种不同的编码，最常用为PC-relative，也就是将目标指令的地址与紧跟在跳转指令后的那条指令的地址之差作为编码。另一种是给出绝对地址，用四字节指定目标。