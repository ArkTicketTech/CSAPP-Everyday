# Ch5 Optimizing Program Performance

## 5.11 Some Limiting Factors

**5.11.2 Branch Prediction and Misprediction Penalties**

如何衡量分支预测是否阻碍了程序的效率？

1. 不要过分关系可预测的分支

    现代处理器的分支预测逻辑能识别不同分支指令的规律模式和长期趋势。

    > 例如，在某循环中，通常预测为选择分支，仅仅在循环条件打破时会导致一次分支预测错误。

2. 写适合用条件传送指令实现的代码

    使用条件数据传送比条件控制转移的性能更高。

    C 程序员不能直接控制汇编指令，但 GCC 偏向于将函数式风格代码编译成条件数据传送指令。