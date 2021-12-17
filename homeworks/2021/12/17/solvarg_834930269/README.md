# Chapter.9 虚拟内存

---------------

## C程序中常见的与存储器相关的错误

### 1. 间接引用指针

尝试访问非虚拟内存区的地址,就会报错

```cpp
scanf("%d",val);
```

### 2. 读未初始化的存储器

全局变量的初始化是为0的,但是堆区的变量初始化并不为0(比如下面代码中的malloc)

```cpp
int *matvec(int **A,int *x,int n){
    int i,j;
    int *y = (int*)malloc(n*sizeof(int));

    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            y[i]+=A[i][j]*x[j];
        }
    }
    return y;
}
```


### 3. 栈缓冲区溢出

比如gets函数

    该函数从标准输入读入用户输入的一行文本，在遇到EOF字符或换行字符前，不会停止读入文本。即该函数不执行越界检查，故几乎总有可能使任何缓冲区溢出(应禁用)。

```cpp
void bufoverflow(){
    char buf[64];
    gets(buf);//这里会触发缓冲区溢出错误
}
```

### 4. 假设指针和它们指向的对象是相同大小的

```cpp
int **makeArray1(int n,int m){
    int i;
    int **A = (int**)malloc(n*sizeof(int));
    for(i=0;i<n;++i){
        A[i] = (int*)malloc(m*sizeof(int));
    }
    return A;
}
```

目的: 想要创建n个数组,每个元素是m个int组成的数组指针

如果`int`和`int*`的大小不同,那么上述代码将会出现错误

如果使用上面那种方式进行内存的分配,可能会写到超出A分配的内存的末端的地方,释放的时候就有可能触发`在远处其作用`而导致`区块合并失败`

### 5. 造成错位错误

就是数组越界时继续分配,就有可能覆盖掉后面的存储器(C++中不允许越界)


### 6. 引用指针,而不是它所指向的对象

```cpp
int *binheapDelete(int **binheap,int *size){
    int *packet = binheap[0];
    binheap[0] = binheap[*size-1];
    *size--;
    heapify(binheap,*size,0);
    return packet;
}
```

比如上述代码,目的是删除一个有\*size项的二叉堆的第一项.然后对剩下的\*size-1项重建堆

`--`运算符和`*`运算符优先级相同,所以实际上`*size--`是指针本身的值自减  
这就一定会导致错误

### 7. 误解指针运算

**指针的算术操作是按照对象的大小来操作的,具体例子如下**

```cpp
int *search(int *p,int val){
    while(*p && *p!=val){
        p+=sizeof(int);//错误,这样的话,就等价于p往后移了4个int的大小
    }

    return p;
}
```

实际上应该写`p++`

### 8. 引用不存在的变量

```cpp
int *stackref(){
    int val;
    return &val;
}
```

上面返回了一个栈帧的引用,但是在离开这个函数后,val所在的栈内存就被释放了.  
如果后面再次引用,存储器会重新启用栈帧,**而如果在这之前,这部分区域被重新分配了,就会导致令人疑惑/毁灭性的错误**


### 9. 引用空闲堆块中的数据

这个意思是,如果我们释放了某个堆块,但是后面仍然调用到了他.  
就有可能触发多种错误,比如指向空闲块,或者指向了其他已分配堆块

### 10. 存储器泄露

就是垃圾,没有被回收,且引用不到的内存





--------------


> Latex转Svg

https://www.latexlive.com/