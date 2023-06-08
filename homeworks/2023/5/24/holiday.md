# The Memory Hierarchy

1. 存储体系结构: 计算机存储体系结构呈现层次结构,包括CPU寄存器、高速缓存(L1/L2/L3)、主内存、闪存/硬盘等。各层储存空间越来越大但存取时间越来越长。通过这种层次结构,可以在成本与性能之间取得平衡。
2. 空间局部性与时间局部性: 程序中的数据/指令呈现空间局部性与时间局部性,即短时间内会反复访问相近位置的存储单元。高速缓存利用这一特征,将最近使用的数据/指令存储于缓存中,加速后续访问。
3. 缓存组织: 高速缓存采用集体关联、直接映射与n路组相结合的方式管理存储单元。其中,每一块都以缓存行为单位存储,需要确保一定的位宽与行宽匹配以发挥最佳性能。
4. 缓存性能: 缓存性能主要由命中率与命中时间决定。其中,命中率取决于程序地址分布与缓存块大小;命中时间由缓存访问时间与主存响应时间共同决定。所以,提高缓存性能的关键是使更高的命中率与更小的命中惩罚时间。
5. 优化方法: 主要的优化方法有: (1) 调整数据结构以增强空间局部性 (2) 编写连续性代码与数据访问循环 (3) 通过块化操作提高时间局部性 (4) 避免在内循环中访问大数组 (5) 将频繁使用的数据保存在寄存器中 (6) 避免非连续访问大数组