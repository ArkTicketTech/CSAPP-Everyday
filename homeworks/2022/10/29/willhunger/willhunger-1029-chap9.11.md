# Ch9 VM as a Tool for Caching

## 9.11 Common Memory-Related Bugs in C Programs

### 9.11.6 Referencing a Pointer Instead of the Object It Points To

例子：

```C
int *binheapDelete(int **binheap, int *size)
{
	int *packet = binheap[0];
	binheap[0] = binheap[*size - 1];
	*size--; /* This should be (*size)-- */
	heapify(binheap, *size, 0);
	return(packet);
}
```



### 9.11.7 Misunderstanding Pointer Arithmetic

指针的算数操作是以它们指向的对象的大小为单位来进行的，而这种大小单位并不一定是字节。

```C
int *search(int *p, int val)
{
    while (*p && *p != val)
    p += sizeof(int); /* Should be p++ */
    return p;
}
```



### 9.11.8 Referencing Nonexistent Variables

```C
int *stackref ()
{
	int val;
	return &val;
}
```



### 9.11.9 Referencing Data in Free Heap Blocks

```C
 int *heapref(int n, int m)
 {
 int i;
 int *x, *y;

 x = (int *)Malloc(n * sizeof(int));


  ...
 // Other calls to malloc and free go here

 free(x);

 y = (int *)Malloc(m * sizeof(int));
 for (i = 0; i < m; i++)
 y[i] = x[i]++; /* Oops! x[i] is a word in a free block */

 return y;
 }
```



### 9.11.10 Introducing Memory Leaks

```
void leak(int n)
{
int *x = (int *)Malloc(n * sizeof(int));
return; /* x is garbage at this point */
}
```

