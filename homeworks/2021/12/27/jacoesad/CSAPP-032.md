> ***2021.12.27\***

------

### 3.6.7 Loops

C语言实现循环的方式有：`do-while`，`while`，`for`。汇编语言中，用条件测试和条件跳转来实现循环的效果。

1. **do-while循环**

do-while通用格式如下：

```c
do
		*body-statement*
		while(*test-expr*);
```

此循环效果为，重复执行*`body-statement`*，对*`test-expr`*求值，如果求值结果非零则继续执行循环。其中，*`body-statement`至少被执行一次。*

翻译成条件和goto语句，如下：

```c
loop：
		*body-statement*
		t = *test-expr；*
		if (t)
				goto loop;
```

一个例子：

C语言：

```c
//原始版本
long fact_do(long n):
{
		long result = 1;
		do {
				result *= n
				n = n-1;
		} while (n > 1);
		return result;
}

//等价goto版本
long fact_do_goto(long n):
{
		long result = 1;
loop:
		result *= n
		n = n-1;
		if (n > 1)
				goto loop;
		return result;
}
```

汇编版本

```assembly
fact_do:
	movl    $1,   %eax
.L2:
	imulq   %rdi, %rax
	subq    $1,   %rdi
	cmpq    $1,   %rdi
	jg      .L2
	rep; ret
```

