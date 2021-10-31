# Procedure

Stack Structure

1. %rsp  store the top of stack 
2.  when the stack grow,  the adress  decrease
3. the address of the Bottom of stack  is greater than the top

Pushq src 

1.  fetch the src  data 
2.  descrease the %rsp (%rsp -8 )
3. store the data to the address (%rsp)

Popq  Dest

1. Dest must be a register
2. fetch the data from %rsp 
3. add %rsp
4. store the data to Dest 

Calling Conventions

- Passing Control
- Passing Data
- Managing local data

Passing Control

Call  and Retq

- Call addr <func sign>

 call + 地址 + 函数签名， 跳转到某个函数执行

内部隐含做了三件事情

1.   %rsp—
2. 将当前指令地址的下一个地址压入栈中，   pushq  $next_address , 
3.  rip 被设置成 被调函数地址

Retq 返回指令

函数功能执行完成之后，  调用ret 返回。 实际是返回上次执行的指令的下一个指令。 内部隐含两件事情

1. Popq  弹栈， 将栈中数据弹出， 栈中其实存的就是恢复现场后的要执行的指令地址
2. 将next 指令地址 设置给rip 寄存器
3. rsp—

Passing Data Flow

Registers 

First 6 arguments   

- %rdi
- %rsi
- %rdx
- %rcx
- %r8
- %r9

Return Value

- %rax

Stack   多于6个，会把参数放在stack上

```wasm
--------
...
--------
Arg n
--------
...

--------
Arg 8
--------
Arg 7
--------
```