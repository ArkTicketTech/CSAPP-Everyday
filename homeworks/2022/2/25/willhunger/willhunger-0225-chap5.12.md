# Ch5 Optimizing Program Performance

## 5.12 Understanding Memory Performance

指令执行过程中产生的数据操作和内存子系统紧密相关，本节分析了功能单元中的 load 和 store 操作的性能

**5.12.1 Load Performance**

Load 操作的性能取决于以下因素：

1. 流水线的能力
2. load unit 的延迟

**5.12.2 Store Performance**

一系列单独连续的 store 操作不会产生数据相关，当特定 store 和 load 操作结合在一起时，会产生写/读相关（write /read dependency），书中例举了一个先 store 地址，后 load 同样地址产生的数据相关对性能的影响。



综上，在寄存器操作中，当寄存器之间存在数据相关时，处理器在译码阶段就能检测到；在内存操作中，处理器无法预测到。内存子系统页存在很有优化，例如并行化。

