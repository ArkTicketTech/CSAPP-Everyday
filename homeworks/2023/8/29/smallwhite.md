## fixed size allocator

`fixed size allocator`顾名思议，只能分配和释放固定大小的内存，其用途要比`linear allocator`广得多，它的核心思想是预创建内存块，然后将内存块切割成多个固定大小的小块，并将它们链接起来形成一个`freelist`；分配的时候从 freelist 取出小块返回；释放的时候将小块重新链接回 freelist；如果 freelist 没有多余内存就再创建一个内存大块；如此重复，最终的内存布局像下面这样：