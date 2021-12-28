## 3.5 Arithmetic and Logical Operations
大部分操作都有针对不同大小操作数的版本 比如 ASS 就有 addb addw addl 和 addq
一共有四类：
1. load effective address
2. unary
3. binary 
4. shifts

### 3.5.1 load effective address
leaq 其实是 movq 地变体
reads from memory to register
和 C语言的 &S 差不多

leaq 7(%rdx,%rdx,4), %rax 如果%rdx包含值x, %rax 会设置为5x+7
编译器经常用leaq执行一些和effective address无关的操作优化效率

### 3.5.2 Unary and Binary Operations
unary 一元运算符 binary 二元元算符
unary: inc (%rsp) === ++
binary: subq %rax, %rdx === %rdx -= %rax ; subq操作的两个运算符不能同事为内存地址

### 3.5.3 Shift Operations
shift amount is given first and the value to shift is given second
