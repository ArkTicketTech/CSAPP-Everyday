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

Manage Data

yoo() — > who()—> amI() 

amI() { amI() } 

![Untitled](Procedure%20185f445e0f524228b6afacb6e57e8f52/Untitled.png)

Stack Frame 意思是正在执行中的函数的状态， 里面保存了函数的实际参数， 局部变量等数据。

rsp 寄存器指示当前栈顶，  rbp 不常用， 在IA32的机器上指示栈底。

没当函数发生call 调用，  系统就会为被调的函数分配栈空间， 以满足执行需要的空间以及准备数据。

针对递归， 系统有最大调用深度， 防止栈空间无限制的扩张

## Example: incr

```c
long incr(long *p, long val) {
	long x = *p;
	long y = x + val;
	*p = y;
	return x;
}
```

assemble

```wasm
pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	(%rdi), %rax   // x = *p
	addq	%rax, %rsi  // y += x
	movq	%rsi, (%rdi)   // *p = y
	popq	%rbp
	retq
	.cfi_endproc
```

## Example: call_incr

clang -Og -S call_incr.c

```c
long incr(long *p, long val) {
	long x = *p;
	long y = x + val;
	*p = y;
	return x;
}

long call_incr(){
    long v1 = 1521;
    long v2 = incr(&v1, 3000);
    return v1 + v2;
}
```

```wasm
.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 0
	.globl	_incr                           ## -- Begin function incr
	.p2align	4, 0x90
_incr:                                  ## @incr
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	(%rdi), %rax
	addq	%rax, %rsi
	movq	%rsi, (%rdi)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_call_incr                      ## -- Begin function call_incr
	.p2align	4, 0x90
_call_incr:                             ## @call_incr
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp   ## 分配栈空间
	movq	$1521, -8(%rbp)        ## 有意思， 这个地方使用了%rbp寄存器，来标定栈底，然后把1521 copy到了栈空间         ## imm = 0x5F1
	leaq	-8(%rbp), %rdi # leaq 计算地址， & 把地址复制到了%rdi上
	movl	$3000, %esi                     ## imm = 0xBB8
	callq	_incr
	addq	-8(%rbp), %rax   # v1的值在 -8(%rbp), v2 在%rax
	addq	$16, %rsp  栈空间释放
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
```