> ***2022.01.05***

------

3. for**循环**

`for`通用格式如下：

```c
for (*init-expr*; *test-expr*; *update-expr*)
		*body-statement*
```

根据C语言标准一般情况，上面的代码与下面的`while`循环行为一致：

```c
*init-expr*;
while (*test-expr*) {
		*body-statement
		update-expr*;
}
```

程序首先会对*`init-expr`*求值，然后进入循环；在循环中会对*`test-expr`*进行求值判断，如果为假则跳出循环，否则执行*`body-statement`*；然后更新*`update-expr`*。

GCC为for循环产生的代码是while循环的两种方式之一，取决于优化等级。

```c
//跳转到中间策略
		*init-expr*;
		goto test;
loop:
		*body-statement
		update-expr*;
**test:
		t = *test-expr*;
		**if (t)
				goto loop;

//guarded-do策略
		*init-expr*;
		t = *test-expr*;
		if (!t)
				goto done;
loop:
		*body-statement
		update-expr*;
		t = *test-expr*;
		**if (t)
				goto loop;
done:
```