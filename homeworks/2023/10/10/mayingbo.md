### 10.10

___

1. - 一个典型的编译系统包括预处理器、编译器、汇编器和链接器。
   - 源代码文件（`.c`）首先被预处理器处理，然后被编译器编译成汇编程序（`.s`），接着被汇编器转换为可重定位的目标程序（`.o`），最后由链接器与其他目标程序文件一起链接形成一个可执行目标文件。
2. **静态链接**:
   - 链接器将各种代码和数据模块组合成一个完整的可执行文件。
   - 解析符号引用，确保每个符号都有一个明确的定义。
3. **加载器**:
   - 加载器将可执行文件从磁盘加载到内存中，并开始执行程序。
4. **动态链接与共享库**:
   - 与静态库不同，动态库在运行时被加载到内存并链接。
   - 允许多个程序共享单个库副本，节省内存。