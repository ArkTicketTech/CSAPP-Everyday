# Ch9 VM as a Tool for Caching

## 9.3 Address Spaces

### 9.3.2 Page Tables

虚拟内存必须有某种方法来判定一个虚拟页是否缓存在 DRAM 的哪个地方，其方法同 Cache 一样。

虚拟内存的页面管理由 OS、MMU 和 位于物理内存中的 Page Table 共同管理，页表负责将虚拟页映射到物理页，每次地址翻译硬件会利用页表将虚拟地址转换为物理地址。操作系统负责维护页表的内容，以及在磁盘与 DRAM 之间来回传送页。