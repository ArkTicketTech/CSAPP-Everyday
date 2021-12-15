CSAPP_12_15 虚拟内存

虚拟内存属于 **操作系统 + 硬件** 范畴，首先，并非所有系统都使用虚拟内存，简单的（或内存受限的）系统就有可能使用单一物理内存地址空间。

物理内存面临的问题：1.内存空间不够 2.产生内存碎片 3.没有内存保护

虚拟内存的优点？1.可以使用磁盘交换空间 2.虚拟地址到物理地址映射灵活 3.进程地址空间隔离

虚拟地址到物理地址的转换涉及哪些硬件/软件/过程？ （MMU & TLB & Page Fault & Lazy allocation）

Lazy allocation：当程序向操作系统申请动态内存时，系统会调用相应的函数分配内存，但是这种分配并不是实时的，内核会去修改页表 Page Table，但是只有当用户真的开始使用这块内存时，才会分配物理页面（通过Page Fault 来触发）。

**Linux Kernel Space** (kmalloc, vmalloc) **& User Space** (malloc)

动态内存管理是很重要的功能，内存一直都是很宝贵的资源，一个好的内存管理策略可以极大地提升系统性能，就用户空间的动态内存管理而言，主要的实现有：ptmalloc，tcmalloc，jemalloc ...

 `GLIBC malloc` 内部通过 [`brk`](http://man7.org/linux/man-pages/man2/sbrk.2.html) 或 [`mmap`](http://man7.org/linux/man-pages/man2/mmap.2.html) 系统调用向内核申请堆内存 

目前glibc的实现是ptmalloc2，它使用 chunk 作为内存管理的基本单元（Allocated chunk，Free chunk，Top chunk，Last Remainder chunk），采用边界标记法，用户 free 掉的内存并不是都会马上归还给系统，ptmalloc 会统一管理空闲的 chunk，当用户进行下一次分配请求时，ptmalloc 会首先试图在空闲的 chunk 中挑选一块给用户，这样就避免了频繁的系统调用，降低了内存分配的开销，ptmalloc 将相似大小的 chunk 用链表链接起来，这样的一个链表被称为一个 bin，ptmalloc 按照大小维护了多个类型的bin（fast bin，small bin，large bin，unsorted bin，除了fast bin是单向链表之外，其他的都是双向链表）... 另外我们还可以通过mallopt()来改变相关的内存分配行为的参数。 