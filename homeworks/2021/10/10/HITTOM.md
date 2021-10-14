1.7
abstraction relationship
files --> i/o devices
virtual memory --> main memory, i/o devices
processes --> processor, main memory, i/o devices

multiprocess: user code A --> kernel code(context switch) --> user code B --> kernel code(context switch) --> user code A
e.g. shell --> context switch --> hello --> context switch --> shell
kernel is portion of system code always inside memory
kernel is collection of code and data structures but not seperate process

vitual address space
a) program code and data
b) heap: expands and contracts when malloc and free
c) shared libraries
d) stack: expands and contracts when call function and function return
e) kernel virtual memory: application cann't read/write contents or call function directly, must invoke kernel to operate.

every i/o device, such as disk, keyboard, network, is modeled as a file


portion 部分
