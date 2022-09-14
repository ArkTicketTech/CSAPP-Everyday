# Ch9 VM as a Tool for Caching

## 9.6 Address Translation

### 9.6.2 Speeding Up Address Translation with a TLB

如果每个虚拟地址进行地址翻译时都需要查询 PTE ，在最糟糕的情况下需要从内存多取一次数据，代价是几十到几百个时钟周期；为了减轻这些开销，在 MMU 中包含了一个关于 PTE 的缓存，被称为 TLB。

TLB 中的每一行都保存了一个由单个 PTE 组成的块，相联度较高；每次进行地址翻译之前，会从 TLB 中取相应的 PTE，如果 TLB 不命中，则 MMU 需要从 L1 cache 中取出相应的 PTE 并加入到 TLB 中。

