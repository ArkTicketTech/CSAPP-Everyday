- # 8.7 Tools for Manipulating Processes  
	- Linux 提供了一系列监控和操作进程的工具  
		- STRACE - print trace of each system call  
		- PS - 列出系统中存在的进程  
		- TOP - 打印出进程使用的资源  
		- PMAP - 展示进程的 memory map  
		- /proc - virtual filesystem 暴露出多个不同的内核数据结构  
- # 8.8 Summary  
	- ECF 出现在计算机系统的各个层面，也是提供并行的基本机制  
	- 硬件层面，处理器的信号触发，由软件处理，然后返回原本的 control flow  
	- 四种不同的异常 - interrupts, faults, aborts, and traps  
	-  
	  > process provides applications with two important abstractions: (1) logical control flows that give each program the illusion that it has exclusive use of the processor, and (2) private address spaces that provide the illusion that each program has exclusive use of the main memory.  

	-  