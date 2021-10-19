2.1 information storage
most computer use block of 8 bits as smallest addressable unit of memory, rather than 1 bit.
virtual address space use a combination of DRAM(dynamic random access memory), flash memory, disk storage, special hardware and operating system software.
C compiler generate different machine-level code of virtual address by pointer type.
backward compitable: old version can be compiled in new standards.

2.1.2
gcc -m32 prog.c   can run on either 32-bits machine or 64-bits machine
number of bits of data depend on how the program is compiled, not the running machine type.
long: 4 bytes in 32-bit machine, 8 bytes in 64-bit machine
T \*: 4 bytes ..., 8 bytes ...
int, int32\_t: 4 bytes = 4 bytes
int64\_t: 8 bytes = 8 bytes
unsigned long = unsigned long int = long unsigned = long unsigned int
