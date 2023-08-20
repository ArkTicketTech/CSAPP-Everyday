## 9.3.3 Page Hits
在上面的例子中，访问 VP 2 的时候就会命中 cache ； address translation hardware 用虚拟地址作为索引访问到 PTE 2 并从内存中读取，由于 valid bit 被 set ，因此他直接使用PTE中的物理地址获取数据
## 9.3.4 Page Faults
DRAM cache miss 就是所谓的 page fault
书中给的例子里， 试图获取VP3，但是在内存里没有缓存，因此触发了缺页中断，根据缓存淘汰算法选择了VP4的物理内存进行替换，如果VP4被修改过了，替换之前会把内容先写入磁盘；缺页中断返回后回重新出发 fault 指令，不过这次VP3已经被缓存了，所以会执行前述 hit 的流程