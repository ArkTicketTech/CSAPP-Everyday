### 9.14

_____

1.虚拟内存？为什么需要设计

VM 系统中的进程与其他进程共享CPU和主内存。然而，共享主内存会带来一些特殊的挑战。随着对CPU的需求增加，进程以一种相对平滑的方式减速。但如果有太多的进程需要太多的内存，那么其中一些将无法运行。当程序内存不足时，它就没有运行的机会。内存还容易受到损坏。

2.虚拟内存（VM）的主内存抽象。虚拟内存是硬件异常、硬件地址转换、主内存、磁盘文件和内核软件的精妙交互，为每个进程提供了一个大、统一和私有的地址空间。虚拟内存通过一个清晰的机制提供了三个重要的功能：(1) 它有效地使用主内存，将其视为存储在磁盘上的地址空间的高速缓存，仅在主内存中保留活动区域，并根据需要在磁盘和内存之间传输数据。(2) 它通过为每个进程提供统一的地址空间简化了内存管理。(3) 它保护了每个进程的地址空间免受其他进程的损坏。