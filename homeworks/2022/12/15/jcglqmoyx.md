## Cache Hits

When a program needs a particular data object d from level k + 1, it first looks for d in one of the blocks currently stored at level k. If d happens to be cached at level k, then we have what is called a cache hit. The program reads d directly from level k, which by the nature of the memory hierarchy is faster than reading d from level k + 1. For example, a program with good temporal locality might read a data object from block 14, resulting in a cache hit from level k.

## Cache Misses

If, on the other hand, the data object d is not cached at level k, then we have what is called a cache miss. When there is a miss, the cache at level k fetches the block containing d from the cache at level k + 1, possibly overwriting an existing block if the level k cache is already full.
This process of overwriting an existing block is known as replacing or evicting the block. The block that is evicted is sometimes referred to as a victim block. The decision about which block to replace is governed by the cache’s replacement policy. For example, a cache with a random replacement policy would choose a random victim block. A cache with a least recently used (LRU) replacement policy would choose the block that was last accessed the furthest in the past. After the cache at level k has fetched the block from level k + 1, the program can read d from level k as before.
