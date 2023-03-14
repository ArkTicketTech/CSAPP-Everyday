**保证程序能在所有可能的情况下都能正确工作非常重要！！！**

编写高效程序需要的条件：

1. 选择适当的算法和数据结构
2. 理解优化编译器的能力和局限性，编写容易优化的代码
3. 任务并行化，多核并行计算

C 语言中如指针运算和强制类型转换的特性使得 C 语言很难被编译器优化

妨碍优化的因素主要是程序中那些严重依赖执行环境的方面。

程序优化首先要消除不必要的工作，让代码尽可能有效地执行所期望的任务。包括不必要的函数调用、条件测试和内存引用