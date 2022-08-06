# Ch8 Exceptional Control Flow

## 8.5 Signals

### 8.5.5 Writing Signal Handlers

信号处理的难点：

1. 处理程序与主程序并发运行，共享同样的全局变量，可能和其它主程序互相干扰。
2. 如何即使接受信号的规则。
3. 不同系统有不同的信号处理语义。