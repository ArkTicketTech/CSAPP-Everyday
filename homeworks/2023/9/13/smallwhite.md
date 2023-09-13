- 在Linux/Unix中，对于一次读取IO的操作，数据并不会直接拷贝到应用程序的缓冲区(用户空间)，它首先会被拷贝到操作系统内核的缓冲区(内核空间)中，然后才会从操作系统内核的缓冲区拷贝到应用程序的缓冲区

- 可以看做是两个过程：1. Waiting for the data to be ready(等待数据到达内核缓冲区)；2. Copying the data from the kernel to the process(从内核缓冲区拷贝数据到应用程序缓冲区)