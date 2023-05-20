`union`

C 语言中的 union（联合）结构是一种特殊的数据结构

- 允许在相同的内存位置存储不同类型的数据。
- union 的主要目的是节省内存，因为它只为最大成员分配内存
- union 中的所有成员共享相同的内存空间，因此在同一时间只能使用其中一个成员。

数据对齐

将数据存储在内存中，为了让处理器访问数据更高效处理数据，需要将一个结构的存储空间扩展到 2 4 8 的倍数字节。

如何对齐取决于数据类型的大小和处理器的体系结构