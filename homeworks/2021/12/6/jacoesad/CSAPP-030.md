> ***2021.12.06\***

------

### 3.6.5 Implementing Conditional Branches with Conditional Control

将条件表达式转从C语言翻译器为机器语言，常用方法是结合无条件跳转和有条件跳转。

C语言中的`if-else`语句的通用形式如下：

```c
if (test-expr)
		then-statement
else 
		else-statement
```

这里，`test-expr`是一个整数表达式，取值为0（True）或者非0（False）。这个两个分支只有一个会执行。

对于这种，汇编通常会使用如下形式，此处用C语法描述控制流：

```c
		t = test-expr
		if (!t)
				goto false;
		then-statement
		goto done;
false:
		else-statement;
done:
```

也就是汇编器为then-statement和else-statement产生各自的代码块，插入无条件和条件分支，以保证执行正确的代码块。