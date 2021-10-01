# 1.4-1.5

构成

- 总线

&ensp;&ensp;&ensp;&ensp;- 传输**固定** 大小字节，32位系统4字节，64位系统8字节

- I/O

&ensp;&ensp;&ensp;&ensp;- 每个I/O设备通过controller / adapter方式与I/O总线连接

- 主存储器Main Memory

&ensp;&ensp;&ensp;&ensp;- 物理上：dynamic random access memory (DRAM)芯片组成

&ensp;&ensp;&ensp;&ensp;- 逻辑上：线性字节数组，数组索引从0开始

&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;- x86-64系统上，short类型2字节，int / float 类型4字节，long / double 类型8字节

- 中央处理器CPU

&ensp;&ensp;&ensp;&ensp;- 解释/存储 Main Memory 中存储的指令，核心是寄存器进行计数program counter (PC).

&ensp;&ensp;&ensp;&ensp;- 从系统通电到断电，处理器重复执行程序计数器指向的指令，并更新程序计数器以指向下一条指令。处理器根据一个简单的指令执行模型运行，该模型由其指令集架构定义。在这个模型中，指令以严格的顺序执行，执行一条指令需要执行一系列步骤。

&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;- 处理器从PC指向的内存中读取指令，解释指令中的bits，执行指令指示的一些简单操作，然后更新PC以指向下一条指令，该指令在内存中可能与刚刚执行的指令相邻，也可能不相邻。

&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;- 这些操作围绕主存、寄存器文件register ﬁle和算术/逻辑单元arithmetic/logic unit（ALU）展开。

&ensp;&ensp;&ensp;&ensp;- 操作流程

&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;- 加载：将一byte或一个word从主存复制到寄存器中，覆盖寄存器先前的内容。

&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;- 存储：将一个byte or word从寄存器复制到主存中的某个位置，覆盖该位置以前的内容

&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;- 操作：将两个寄存器的内容复制到ALU，对两个字执行算术运算，并将结果存储在寄存器中，覆盖该寄存器以前的内容。

&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;- 跳转：从指令本身提取一个byte，并将该字复制到PC中，覆盖PC先前的值。

&ensp;&ensp;&ensp;&ensp;

&ensp;&ensp;&ensp;&ensp;### 运行hello word程序流程

&ensp;&ensp;&ensp;&ensp;- shell程序执行命令等待input

&ensp;&ensp;&ensp;&ensp;- shell接收到input为./hello,将每个字符读入寄存器 → 存储到内存

&ensp;&ensp;&ensp;&ensp;- shell收到enter key，执行一系列指令将hello文件中的代码和数据从磁盘复制到主存储器，加载可执行文件

&ensp;&ensp;&ensp;&ensp;- 使用内存直接访问direct memory access （DMA），将数据直接从磁盘传输到主存，不经过处理器

&ensp;&ensp;&ensp;&ensp;- hello文件加载到内存中后，处理器执行hello程序中main的机器指令，这些指令将hello world字符串从内存复制到register ﬁle → 复制到显示设备 → 显示

