利用时间局部性，使频繁使用的字从L1中取出

利用空间局部性，使尽可能多的字从一个L1高速缓存行中访问到



使用分块来提高时间局部性

将一个程序中的数据结构组织成的大的片（chunk），称为块（block）

这样构造的程序能够将一个片加载到L1高速缓存中，并在这个片中进行所有的读和写，然后丢到这个片，加载下一个片

适合于优化编译器或者频繁执行的库函数



Pp. 443-450