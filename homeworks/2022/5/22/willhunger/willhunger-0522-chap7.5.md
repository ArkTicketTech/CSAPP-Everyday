# Ch7 Linking

## 7.5 Symbols and Symbol Tables

每个可重定位目标模块 `m` 都有一个符号表 ，其包含了 `m` 定义和引用符号的信息。链接器上下文有三种不同符号：

* 由模块`m` 定义的能被其他模块引用的全局符号。对应了 nonstatic C function,  global variable
* 由其它模块定义并被模块 `m` 引用的全局符号，这些符号称为外部符号，对应其它模块中定义的 nonstatic C function,  global variable
* 只被模块 `m` 定义和引用的局部符号，其对应于 static C function 和 static C variable。这些符号在 `m`  中任何位置都可见，但不能被其他模块引用。

本地链接器符号和 `.symtab` 中的符号是不同的。`.symtab` 中的符号表不包含**对应于本地非静态程序变量中的任何符号**。这些本地非静态程序变量中的符号在运行时栈中被管理。