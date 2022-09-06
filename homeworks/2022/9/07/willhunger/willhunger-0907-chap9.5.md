# Ch9 VM as a Tool for Caching

## 9.5 VM as a Tool for Memory Protection

操作系统需要提供手段来控制对内存系统的访问，不允许用户进程修改它的只读代码段，也不允许其读取或者修改内核代码和数据结构，不允许其访问其它进程的私有内存等。

因此，在虚拟内存机制中，页表项会有类似项：进程必须在内核模式下才能访问该页、Read 位 及 Write 位；如果非法访问，CPU 会触发一个保护故障，例如，SEGMENTATION FAULT。

