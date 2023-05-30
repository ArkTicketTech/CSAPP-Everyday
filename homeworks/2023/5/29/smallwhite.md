- **值传递**：在值传递中，函数或方法接收的是参数值的一个副本。这意味着函数内部对参数的任何修改都不会影响到外部原始数据。在 C 和 C++ 中，所有的基本类型（如 `int`、`float`、`char` 等）和结构体默认都是通过值传递的。

	> 注意：返回值也是会返回副本的

- **引用传递**：在引用传递中，函数或方法接收的是参数值的一个引用（或者说指针），这意味着函数内部对参数的任何修改都会影响到外部原始数据。在 C 和 C++ 中，你可以通过使用指针或引用参数来实现引用传递。