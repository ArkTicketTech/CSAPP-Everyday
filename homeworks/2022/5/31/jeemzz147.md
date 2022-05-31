1.5 缓存cache问题
&emsp;The idea behind caching is that a system can get the effect of both a very large memory and a very fast one by exploiting locality, the tendency for programs to access data and code in localized regions

* Regs > L1 cache > L2 > L2 > Main memory > Local secondary storage > Remote secondary storage (distributed file systems, Web servers) : Larger, slower, andcheaper (per byte) storage devices

* 存储设备的分层结构：上层的存储设备作为下层设备的caches缓存， L3 caches作为main memory的缓存

1.7 OS
* 保护硬件防止失控的应用对其误操作
* 为应用程序提供简单统一的操作方式，来操作底层硬件设备
