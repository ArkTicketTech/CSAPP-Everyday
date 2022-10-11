# Ch9 VM as a Tool for Caching

## 9.9 Dynamic Memory Allocation

### 9.9.8 Splitting Free Blocks

分割空闲块时，如果使用整个空闲块，会造成内部碎片。如果空闲块匹配不太好，分配器会将该空闲块分割为两部分，第一部分变为分配块，剩下的变为一个新的空闲块。

![image-20221012005040380](assets/image-20221012005040380.png)