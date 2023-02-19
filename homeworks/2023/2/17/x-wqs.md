在任何使用虚拟内存又使用SRAM高速缓存的系统中，都有应该使用虚拟地址还是使用物理地址来访问SRAM高速缓存的问题。尽管关于这个折中的详细讨论已经超出了我们的讨论范围，但大多数系统是选择物理寻址的。使用物理寻址，多个进程同时在高速缓存中有存储块和共享来自相同虚拟页面的块成为很简单的事情。

每次CPU产生一个虚拟地址，MMU就必须查阅一个PTE，以便将虚拟地址翻译成物理地址。在最槽糕的情况下，会要求从内存多取一次数据，代价是几十到几百个周期。如果PTE碰巧缓存在L1中，那么开销就下降到1个或者2个周期。翻译后备缓冲器TLB.

所有的地址翻译步骤都是在芯片上的MMU中执行，因此非常快。
· 第一步：CPU产生一个虚拟地址。
· 第二步、第三步：MMU从TLB中取出相应的PTE。
· 第四步：MMU将虚拟地址翻译成一个物理地址，发送到高速缓存/主存
· 第五步：高速缓存/主存将所请求的数据字返回给CPU。

当TLB不命中，MMU必须从L1缓存中取出相应的PTE。新取出的PTE放在TLB中，可能会覆盖一个已存在的条目。