异常
在现代处理器中，当某些代码发生了某种类型的异常(exception)，此时处理器会执行异常处理程序。如果程序员没有手动设置异常处理程序，则CPU会执行默认的处理程序。
大多数情况下默认的处理程序只会简单的关闭程序。

将流水线技术引入一个待反馈的系统，当相邻指令间存在相关时会导致问题。

这里的相关有两种形式：
1.数据相关。下一条指令会用到当前指令计算出的结果。
2.控制相关。一条指令要确定下一条指令的位置。

这些相关可能会导致流水线产生计算错误，称为冒险(hazard)。其中也分为数据冒险和控制冒险。

避免冒险的方式

暂停(stalling)。暂停技术阻塞一组指令在它们所处的阶段，而允许其他指令继续通过流水线，直到冒险条件不再满足。其处理方法为：每次要阻塞一条指令在译码阶段，就在指令阶段插入一个气泡（bubble）。气泡类似nop指令，不会更改寄存器、内存、条件码与程序状态。

转发(formarding)。将结果值直接从一个流水线阶段传到较早阶段的技术称为数据转发，也称旁路(bypassing)。

为了提高CPU的运行速度，应尽量避免流水线冒险