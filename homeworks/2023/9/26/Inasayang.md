高速缓存是否命中，抽取字的过程

-   组选择
-   行匹配
-   字抽取

如果缓存不命中，则直接用新取出的行替换当前的行

冲突不命中指在x和y的块之间抖动，高速缓存反复地加载和驱逐相同地高速缓存块地组



为什么用中间地位做索引？

高位做索引，连续地内存块会映射到相同地高速缓存块，使用效率低

中间为做索引，相邻地块总是映射到不同地高速缓存行



Pp. 427-433