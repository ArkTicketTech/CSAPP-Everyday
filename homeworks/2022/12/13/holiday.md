2个C语言有符号和无符号数字，运行具体代码出错的例子

1. 

```c
unsigned i
for(i = n-1;i>=0;i--){ // 这里会出问题，因为i是unsigned，一旦变成负数-1，他在比较的时候将会是UMAX，将会得不到结果的同时，导致循环次数爆表最后内存溢出
	f(a[i])
}
```

1. 

```c
int i
for(i = n-1;i-sizeof(char)>=0;i--){ // 这里会出问题，因为sizeof返回的是unsigned，表达式里面有unsigned的值，整个表达式将都会变成unsigned的值，将会出类似上面那样的问题
	f(a[i])
}
```

