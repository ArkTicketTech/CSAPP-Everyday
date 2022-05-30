#### p45 - p49

1.4
* 如果命令行指令的第一个单词不是内置shell指令，shell会把它看做可执行文件的名称并且执行
* 1.4.1 系统硬件架构
  * Buses：总线以字为基本单元传输信息 word sizes ：32bits or 64bits
  * I/O Devices：每一个IO设备通过adapter or controller 连接到IO总线
  * Main Memory：临时存储设备，存储运行时操作的数据和程序
  * Processor：CPU中央处理器，用于处理存储在memory中的指令，核心是一个字单位大小的program counter，在任何时候指向需要执行的机器语言指令的地址。执行的简单操作例子：load(memory to register), store(register to memory),operate(2 registers to ALU, result to register), jump(extract a word from instruction, to PC)
  * DMA: the data travel directly from disk to main memory, without passing through the processor.