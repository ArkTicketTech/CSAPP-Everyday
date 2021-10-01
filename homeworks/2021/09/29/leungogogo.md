# CSAPP 9/29 Notes
## 1.5 Caches Matter
* It takes time for the system to move information from one place to another, which is considered as overhead that slow down the program.
* Larger storage devices are slower than smaller storage devices.
  * For example, it's faster to read from memory than disk, faster to read from register than memory.
* To speed up the process of reading from memory to CPU, we build **cache** which temporarily holds the information the CPU is likely need in the near future.
  * Cache exploits locality, which means the tendency for programs to access data and code in localized regions. For example, if you access `a[0]` of an array, you are likely to access `a[1]`.
* The `L1` and `L2` cache are implemented with **static random access memory(SRAM)**.
## 1.6 Storage Devices Form a Hierarchy
* Memory Hierarchy: storage at one level serves as a cache for storage at the next lower level.
  ![Screen Shot 2021-09-29 at 7 10 21 PM](https://user-images.githubusercontent.com/26990923/135374128-4dee2d3a-16a6-41e0-8692-5b6280c285a3.png)
## 1.7 The Operating System Manages the Hardware
### The Purposes of OS
1. Protects the hardware from malicious applications.
2. Provides a uniform mechanisms/interfaces for us to manipulate different hardware devices.
![Screen Shot 2021-09-29 at 7 13 32 PM](https://user-images.githubusercontent.com/26990923/135374404-3b76f320-0adf-45a8-b051-b0301b063335.png)

### Fundamental Abstrations of OS
### Processes
* A process is the operating system’s abstraction for a running program, different processes can run concurrently, each with the illusion that it is the only program running on the system.
* Execution of one program interleaves with other programs with **context switching**.
 * Context means information like `PC`, values of register files, and contents in the main memory.
 * Steps of context swtiching:
   1. Save the context of the current process.
   2. Restore the context of the new process.
   3. pass control to the new process.
    ![Screen Shot 2021-09-29 at 7 18 46 PM](https://user-images.githubusercontent.com/26990923/135374899-a636cbbc-99ea-494d-860a-a9daa7a60d26.png)
* The transition from one process to another is managed by **kernel**, which is a portion of the OS code always resident in the memory. 
* System call interrupts processes and transfer control to the kernel.

### Threads
* A process consists of multiple threads, different threads in the same process share the same code and global data.
  * Threads are more efficient than processes since it's easier to share data between multiple threads.
### Virtual Memory
* Virtual memory is an abstraction that provides each process with the illusion that it has exclusive use of the main memory.
* Each process has the same view of memory, which is called its own **virtual address space**, and it consists of the following sections:
  * Program code and data
  * Heap
  * Shared libraries
  * Stack
  * Kernel memory (not accessible by application program)
    ![Screen Shot 2021-09-29 at 8 32 47 PM](https://user-images.githubusercontent.com/26990923/135382687-720e02a4-acbb-4c41-b12a-6d62fbdfbba7.png)

### File
* A file is a sequence of bytes, and every I/O device such as disks, keyboard, display and even network can be modeled using the file API.
