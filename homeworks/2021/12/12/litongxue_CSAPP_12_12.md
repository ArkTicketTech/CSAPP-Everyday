# **CSAPP_12_12** 存储器

**Cache 不命中的场景有哪些？** 三种场景：1. Compulsory miss（强制性不命中）， 例如首次访问，空的缓存必定会造成不命中，2. Capacity miss（容量原因的不命中）， 即缓存行的太小，不足以存储内存的内容 3. Conflict miss（冲突原因不命中）

由于会发生冲突，某些时候就需要把一部分缓存行驱逐出去缓存，那么到底选哪个倒霉蛋呢？最常见的Cache替换算法有：随机（Random），先进先出（FIFO），最近最少使用（LRU）

需要考虑缓存行的大小，现代CPU的缓存行一般是64个字节（也有使用128个字节的），在Cache的总容量固定且使用组关联的的情况下，缓存行越大，那么能够存放的组就越少，这里需要做一个权衡。

**Cache 的写策略有哪些？** 

Cache命中时的写策略 ① 写穿透（Write Through）：数据同时写入Cache和主存 ② 写返回（Write Back）：数据只写入Cache（标记为dirty），仅当该数据块被替换时才将数据写回主存

Cache不命中时的写策略 ① 写不分配（Write Non-Allocate）：直接将数据写入主存 ② 写分配（Write Allocate）：将该数据所在的块读入Cache后，再将数据写入Cache

**典型情况：**① Write-­‐through + No-­‐write-­‐allocate ② Write-­‐back + Write-­‐allocate

