#  Ch7 Linking

## 7.6 Symbol Resolution

链接器在解析符号时将每个引用与它输入的可重定位目标文件中的符号表中的一个明确的符号定义相关联。对局部符号解析是简单的，因为其仅需在其符号表中找即可；但是对于全局符号的解析就更加困难。

> C++ 和 Java 中的函数重载的编码策略使用 mangling 和 demangling 来解决。

### 7.6.1 How Linkers Resolve Duplicate Symbol Names

编译器在解析多重定义的全局符号时，会将所有全局符号在符号表中加入 strong symbol 或 weak symbol 标记。其中，函数和已初始化的全局变量是  strong symbol ，未初始化的全局变量是 weak symbol。

Linux 链接器使用如下规则来处理多重定义的符号名：

1. 不允许有多个同名的 strong symbol 。

    > 例如，两个编译单元中各自存在 main 函数，链接器会直接生成错误信息。

2. 如果有一个  strong symbol 和多个 weak symbol 同名，选择  strong symbol 。

3. 如果有多个  weak symbol 同名，任意选择一个  weak symbol 。

如果两个编译单元中存在同名的 int 和 double 变量，随机选择是容易造成 bug，这类 bug 很难修正，可以使用 `gcc -fno-common`  选项，链接器在遇到多重定义的全局符号时，会触发错误；或者使用 `-Werror` 选项，会将所有的警告变为错误。

上节分配 `COMMON` 和 `.bss` 的规则太过绝对，实际上：

* 当链接器翻译某个模块时，遇到弱全局符号，比如说 x，并不知道其它模块是否定义了 x，如果是，其无法预测链接器该使用 x 的多重定义中的哪一个，所以编译器会将 x 分配为 `COMMON`。
* 如果 x 初始化为 0，那么 x 是强符号，因此编译器可以将其分配为 `.bss`。

