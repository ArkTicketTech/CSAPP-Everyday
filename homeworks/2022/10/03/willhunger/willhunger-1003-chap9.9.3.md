# Ch9 VM as a Tool for Caching

## 9.9 Dynamic Memory Allocation

### 9.9.3 Allocator Requirements and Goals

显式分配器的约束条件：

1. 处理任何请求序列。只要满足约束条件，每个释放请求必须对应一个当前已分配块。
2. 立即响应请求。不能对请求重新排列或缓冲请求。
3. 只使用堆。
4. 对齐块。
5. 不修改已分配的块。

