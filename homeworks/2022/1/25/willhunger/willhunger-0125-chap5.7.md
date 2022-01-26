# Ch5 Optimizing Program Performance

## 5.7 Understanding Modern Processors

**5.7.1 Overall Operation**

EU 单元接受来自于 ICU fetch unit 的指令（一个周期往往能接受多条指令），然后将指令发送到不同的 functional unit ，处理不同类型的操作。

读写内存通过 the load and store units 处理，load unit 和 store unit 都有一个加法器 adder 用于计算操作地址，以及一个 data cache 用于存储最近访问的数据。

由于超标量处理器的投机执行技术，指令执行的最终结果知道处理器能确定指令实际执行后（分支预测正确），才会将指令的执行结果写入寄存器和内存。

