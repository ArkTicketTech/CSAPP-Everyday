# Jumping

- Jx Instructions
    
    jump to different part of code depending on condition codes
    
    [Untitled](https://www.notion.so/b6b1b86da73f430eadbdfc270bd16ca8)
    
    绝对值比较  control.c
    
    ```c
    long absdiff(long x, long y){
    	long result;
     	if (x > y)
    		result = x - y;
    	else
    		result = y -x ;
    
    	return result;
    }
    ```
    
    编译成汇编，禁用cmov 指令，查看是如何使用cmpq 和 跳转指令来做到的
    
    ```c
    gcc -Og -S -fno-if-conversion control.c
    ```
    
    汇编代码如下:
    
    ```wasm
    .file	"control.c"
    	.text
    	.globl	absdiff
    	.type	absdiff, @function
    absdiff:
    .LFB0:
    	.cfi_startproc
    	cmpq	%rsi, %rdi    # y in %rsi, x in %rdi
    	jle	.L2    # 如果 x < y, 就跳转到.L2 
    	movq	%rdi, %rax
    	subq	%rsi, %rax  
    	ret
    .L2:
    	movq	%rsi, %rax
    	subq	%rdi, %rax  
    	ret
    	.cfi_endproc
    .LFE0:
    	.size	absdiff, .-absdiff
    	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-4)"
    	.section	.note.GNU-stack,"",@progbits
    ```