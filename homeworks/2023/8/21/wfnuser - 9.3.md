## 9.3.5 Allocating Pages
allocate 新的虚拟页会让 page table 发生变化，书中给的例子是申请 VP5 的例子，从磁盘上创建空间，并 update PTE 5 指向这个新创建的空间
## 9.3.6 Locality to Rescue Again
通常程序在运行的任何时间点都只会工作在少量的 active pages 中，我们称为 working set 或 resident set
thrashing 是指 working set 超过物理内存大小的情况，那么页面将会被持续的换入换出。如果程序性能很差，需要考虑这样的可能性。