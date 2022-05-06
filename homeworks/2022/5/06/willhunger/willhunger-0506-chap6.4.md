# Ch6 The Memory Hierarchy

## 6.4 Cache Memories

### 6.4.3 Set Associative Caches

由于每个 cache set 中仅有一个 cache line，直接映射 cache 易产生 conflict miss 的问题。为减少 conflict miss，可以增加每个 cache set 中的 cache line 数量来解决问题。

> 一般的，cache line 的数量 E，需要满足 $1 < S < C / B$。

组相连 cache 的过程和直接映射 cache 类似，首先需要根据 set index bits 找到组，然后再组中根据  tag bits 和 valid bit 进行行匹配。

如果找到了确定的行，则 cache hit，否则 cache miss。cache miss 后需要在组内进行行替换，优先选择空行，如果行满了，可以选择随机替换，LRU，LFU 等置换算法。

### 6.4.4 Fully Associative Caches

全相连映射仅有一个 cache set 组成，该 cache set 中包含了所有的 cache lines。因此，全相连映射中的内存地址仅有 tag 和 block offset 的组成。每次进行 cache 行匹配时，直接进行通过 tag bits 和 valid bit 行匹配。

全相连映射 cache 的缺点是进行行匹配时，由于 cache 行多，无法做到快速的匹配速度。因此，全相连映射 cahce 仅仅适合较少的 cache 存储。