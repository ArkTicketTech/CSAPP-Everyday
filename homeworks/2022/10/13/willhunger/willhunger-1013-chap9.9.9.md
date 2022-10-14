# Ch9 VM as a Tool for Caching

## 9.9 Dynamic Memory Allocation

### 9.9.9 Getting Additional Heap Memory

分配器找不到空闲块的操作：

1. 合并在内存中物理上相邻的空闲块以创建一个更大的空闲块。
2. 如果合并后仍无法达到需求，则分配器会通过调用 sbrk 向内核请求额外的堆内存，将分配的内存转换为空闲块，并插入空闲链表中，然后用于后续的内存分配。

### 9.9.10 Coalescing Free Blocks

合并碎片策略：

* 立即合并：简单明了。但在某些请求模式下，易导致抖动，块反复合并分割。
* 推迟合并