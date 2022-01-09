> ***2022.01.09***

------

### 3.6.8 Switch Statements

`switch`可以根据一个整数索引值进行多重分支（multiway branching）。通过使用跳转表（jump table）使得实现更加高效。跳转表是一个数组，表项i是一个代码段的地址，这个代码段实现当开关索引值等于i时程序应该采取的动作。用开关索引值来执行一个跳转表内的数组引用，确定跳转的目标指令。与很长的`if-else`相比，跳转表的优点时执行开关语句的时间与开关情况的数量无关。

一个C语言switch的示例：

```c
void switch_eg(long x, long n, long *dest)
{
		long val = x;

		switch (n) {
		
		case 100:
				val *= 13;
				break;

		case 102:
				val += 10;
				/* Fall through */

		case 103:
				val += 11;
				break;

		case 104:
		case 106:
				val *= val;
				break;

		default:
				val = 0;
		}

		*dest = val;
}
```

翻译到扩展的C语言版本：

```c
void switch_eg_impl(long x, long n, long *dest)
{
		/* Table of code pointers */
		static void *jt[7] = {
				&&loc_A, &&loc_def, &&loc_B, &&loc_C, &&loc_D, &&loc_def, &&loc_D
		};
		unsigned long index = n - 100;
		long val;

		if (index > 6)
				goto loc_def;
		/* Multiway branch */
		goto *jt[index];
		
loc_A:/* Case 100 */
		val = x * 13;
		goto done;
loc_B:/* Case 102 */
		x = x + 10;
		/* Fall through*/
loc_C:/* Case 103 */
		val = x + 11;
		goto done;
loc_D:/* Cases 104, 106 */
		val = x * x;
		goto done;
loc_def:/* Default case */
		val = 0;
done:
		*dest = val;
}
```

汇编语言版本：

```assembly
switch_eg:
	subq    $100, %rsi
	cmpq    $6, %rsi
	ja      .L8
	jmp     *.L4(%rsi,8)
.L3:
	leaq    (%rdi,%rdi,2), %rax
	leaq    (%rdi,%rax,4), %rdi
	jmp     .L2
.L5:
  addq    $10, %rdi
.L6:
	addq    $11, %rdi
	jmp     .L2
.L7:
	imulq   %rdi, %rdi
	jmp     .L2
.L8:
  movl    $0, %rdi
.L2:
	movq    %rdi, (%rdx)
  ret
```

执行`switch`语句的关键步骤是通过跳转表来访问代码位置。汇编中跳转表表示如下：

```assembly
	.section    .rodata
	.align 8
.L4:
	.quad    .L3
	.quad    .L8
	.quad    .L5
	.quad    .L6
	.quad    .L7
	.quad    .L8
	.quad    .L7
```

`.rodata`表示只读数据，Read-Only Data。