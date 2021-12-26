> ***2021.12.26\***

------

### 3.6.6 Implementing Conditional Branches with Conditional Moves

条件转移，计算一个条件操作的两种结果，然后根据条件是否满足从中选取一个。可以用一条简单的条件传送指令来是实现它，其更符合现代处理器的性能特性。

每条指令都有两个操作数：源寄存器或内存地址S和目的寄存器R，这些指令的结果取决与于条件码的值。源值可以从内存或者源寄存器中读取，但是只有在指定条件满足时，才会被复制到目的寄存器中。

| 指令        | 同义名  | 传送条件       | 描述                   |
| ----------- | ------- | -------------- | ---------------------- |
| cmove   S,R | cmovz   | ZF             | 相等/零                |
| cmovne  S,R | cmovnz  | ~ZF            | 不相等/非零            |
| cmovs   S,R |         | SF             | 负数                   |
| cmovns  S,R |         | ~SF            | 非负数                 |
| cmovg   S,R | cmovnle | ~(SF^OF) & ~ZF | 大于（有符号>）        |
| cmovge  S,R | cmovnl  | ~(SF^OF)       | 大于或等于（有符号>=） |
| cmovl   S,R | cmovnge | SF^OF          | 小于（有符号<）        |
| cmovle  S,R | cmovng  | (SF^OF)        | ZF                     |
| cmova   S,R | cmovnbe | ~CF & ~ZF      | 超过（无符号>）        |
| cmovae  S,R | cmovnb  | ~CF            | 超过或相等（无符号>=） |
| cmovb   S,R | cmovnae | CF             | 低于（无符号<）        |
| cmovbe  S,R | cmovna  | CF             | ZF                     |

处理器无需预测测试结果就可以就可以执行条件传送。处理器只是读取源值，检查条件码，然后要么更新目的寄存器，要么保持不变。

当两个表达式中的任意一个可能产生错误的条件或者副作用，就会导致非法行为。无法使用条件传送。