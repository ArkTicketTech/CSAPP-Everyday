# Ch6 The Memory Hierarchy

## 6.4 Cache Memories

### 6.4.4 Issues with Writes

当对 cache 进行写时，有两种方法：

* write-through：直写，立即将 w 的 cache 块写回下一层存储中。方法简单，但每次写都会有总线传输流量。
* write-back：写回，尽可能推迟更新，当 cache 替换算法要替换 cache 块时，才写回下一层存储中。该方法能减少总线流量，但是增加了复杂性，cache 块需要维护一个脏位（dirty bit）

如何处理写不命中：

* write-allocate：写分配，加载相应的第一层的块到 cache 中，然后更新该 cache 块。该方法每次不命中都需要从下一层存储中读取并送入 cache 中。
* non-write-allocate：避开 cache，直接将该字写回低一层 cache 中。

> 通常来说，write-through 方法用 non-write-allocate，write-back 方法用 write-allocate 

> 编写程序时，一般采用写回和写分配的模型，其原因如下：
>
> 1. 逻辑电路密度提高，写回的高复杂性已不是阻碍
> 2. 写回方法和处理读的方式对称

