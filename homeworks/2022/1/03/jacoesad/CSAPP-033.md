> ***2022.01.03\***

------

1. **while循环**

`while`通用格式如下：

```c
while (*test-expr*)
		*body-statement*
```

在第一次执行*`body-statement`*之前，会对*`test-expr`*进行求值判断。

翻译成机器代码，有两种方式。

第一种为jump to middle，执行一个无条件跳转到循环结尾的测试处来执行初始测试。模版如下：

```c
		goto test;
loop:
		*body-statement*
test:
		t = *test-expr*;
		if (t)
				goto loop;
```

第二种为guarded-do，首先使用条件分之，如果初始条件不成立就跳过循环，代码变为`do-while`循环，模版如下。（当使用较高优化等级编译时，例如使用命令行`-O1`，GCC会采用这种策略）

```c
t = *test-expr*;
if (!t)
		goto done;
do
		*body-statement*
		while (*test-expr*);
**done:
```

goto代码：

```c
t = *test-expr*;
if (!t)
		goto done;
loop:
		*body-statement*
		t = *test-expr*;
		**if (t)
				goto loop;
**done:
```