# Ch4 Processor Architecture

## 4.5 Pipelined Y86-64 Implementations

**4.5.8 Pipeline Control Logic**

上一节中重新设计了 PIPE 的流水线控制逻辑，这个设计逻辑必须考虑好以下四种情况：

* Load / Use  hazards. 写后读的数据冒险，这种情况下，流水线必须在指令访存阶段和使用该值之间，阻塞一个周期。
* Processing ret. 流水线必须阻塞，直到`ret` 指令到达写回阶段。
* Mispredicted branches. 如果分治逻辑检测不能进行 `jump`，已经进入流水线的预测错误指令必须取消，然后将原 `jump` 后的指令重新送入流水线。
* Exceptions. 当一条指令出现异常时，必须禁止其后的指令更改编程可见状态，而且，该异常指令到达写回阶段时，必须 `halt` 中断执行。

