# Ch9 VM as a Tool for Caching

## 9.3 Address Spaces

### 9.3.1 DRAM Cache Organization

DRAM 比 SRAM 慢 10 倍，磁盘比 DRAM 慢 100000 多倍，DRAM 不命中的开销更加昂贵，而且，从磁盘的第一个扇区读取一个字节的时间开销比读这个扇区中连续的字节要慢 100000 倍，DRAM 缓存的组织结构是由巨大的不命中开销所驱动的。

因此，为了减少不命中开销，虚拟页一般设置的较大。