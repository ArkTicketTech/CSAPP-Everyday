# Ch9 VM as a Tool for Caching

## 9.11 Common Memory-Related Bugs in C Programs

### 9.11.1 Dereferencing Bad Pointers

常见例子：

scanf 将把 val 的内容当作一个地址，并试图写一个字到这个位置，最好情况下，程序立即以异常终止；最差情况下，val 被成功写入，导致内存污染。

```c
scanf("%d", &val);
scanf("%d", val);
```



### 9.11.2 Dereferencing Bad Pointers

bss 内存位置会被加载器初始化为零，但是堆内存并不会这样做，错误例子：

```c
/* Return y = Ax */
int *matvec(int **A, int *x, int n)
{
	int i, j;

	int *y = (int *)Malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
             y[i] += A[i][j] * x[j];
    return y;
}
```



### 9.11.3 Allowing Stack Buffer Overflows

例子：

```c
void bufoverflow()
{
 char buf[64];

 gets(buf); /* Here is the stack buffer overflow bug */
 return;
}
```



### 9.11.4 Assuming That Pointers and the Objects They Point to Are the Same Size

```c
/* Create an nxm array */
int **makeArray1(int n, int m)
{
	int i;
	int **A = (int **)Malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		A[i] = (int *)Malloc(m * sizeof(int));
	return A;
 }
```



### 9.11.5 Making Off-by-One Errors

```c
/* Create an nxm array */
int **makeArray2(int n, int m)
{
	int i;
	int **A = (int **)Malloc(n * sizeof(int *));
	for (i = 0; i <= n; i++)
		A[i] = (int *)Malloc(m * sizeof(int));
	return A;
}
```

