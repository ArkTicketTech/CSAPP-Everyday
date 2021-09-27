# A tour of computer system

## 1.1 Information is Bits + Context
系统中的任何信息都是一串二进制序列；不同的上下文对同样的序列有不同的解释。

## 1.2 Programs Are Translated by Other Programs into Different Forms

source program -> Executable object program
- preprocessing phase 预处理 将投文件注入
- compilation phase 编译成汇编语言
- assembly phase 编译成机器语言
- linking phase 合并引用的目标文件

## 1.3 It Pays to Understand How Compilation Systems Work
why we need to understand detail of compilation?

- optimizing performance: Help us to know whether `switch` more efficient or `if-else` does. 
- understaing link time error
- avoiding security holes

## 1.4 Processor Read and Interpret Instructions Stored in Memory
`hello.c` -> binary execurable file `hello`
we run `hello` by shell; it will load it in to memory and execute

### 1.4.1 hardware organization
- Buses
- I/O Devices
- Main Memory
- Processor
### 1.4.2 running hello program
`hello` -> load hello to memory (DMA) -> begin to execute
copy `hello world` from memory to register then display on screen


