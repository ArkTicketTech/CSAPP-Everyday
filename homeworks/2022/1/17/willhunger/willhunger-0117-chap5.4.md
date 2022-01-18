# Ch5 Optimizing Program Performance

## 5.4 Eliminating Loop Inefficiencies

循环条件中进行额外的函数调用往往导致额外开销。

本节通过 code motion 的方式将循环中进行多次计算但计算结果不变的函数移到循环前来消除额外开销。

但编译器对上述优化难以探测，不能确定是否会发生副作用。因此，为了辅助提升编译器的效率，程序员必须显示的做 code motion 的优化。

