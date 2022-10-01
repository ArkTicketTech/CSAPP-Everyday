# Ch9 VM as a Tool for Caching

## 9.9 Dynamic Memory Allocation

### 9.9.1 The malloc and free Functions

malloc 函数返回一个指针，指向大小为至少 size 字节的内存块，这个内存块可能会做内存对齐。如果 malloc 分配内存时出现问题，那么就直接返回 NULL，并设置好 errno。calloc 在 malloc 上将内存初始化为零。

显示分配和释放堆内存，还可以使用 sbrk 函数，sbrk 函数通过将内核的 brk 指针增加来扩展和收缩堆。

调用 free 函数用户释放内存，free 的参数必须说 malloc、calloc、realloc 中所分配的，否则会导致未定义行为。

