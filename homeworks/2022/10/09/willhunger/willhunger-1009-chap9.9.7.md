# Ch9 VM as a Tool for Caching

## 9.9 Dynamic Memory Allocation

### 9.9.7 Placing Allocated Blocks

分配器的搜索策略是由放置策略确定的，常见的策略有：

* first fit：从头开始搜索空闲链表，选择第一个合适的空闲块；
    * 优点：趋向于将大的空闲块保留在链表的后面
    * 缺点：趋向于在靠近链表起始处留下小空闲块的碎片，增加了较大块的搜索时间
* next fit：从上一次查询结束的地方开始搜索空闲链表；
    * 优点：比 first fit 运行快，在链表前面的小碎片较多时更为明显
* best fit：选择合适所请求大小的最小空闲块。
    * 优点：内存利用率高
    * 缺点：需要进行彻底搜索

