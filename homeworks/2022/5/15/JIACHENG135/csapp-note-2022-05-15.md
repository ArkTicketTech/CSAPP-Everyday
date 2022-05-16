---
title: csapp-note-2022-05-15
tags:
  - csapp
  - 操作系统
  - 编译原理
  - CS基础知识
  - 读书笔记
cover: 'https://source.unsplash.com/random'
date: 2022-05-15 21:30:45
---

##
Chapter 5. Optimization Program performance

- Memory aliasing

  Two pointers may designated the same memory location.

For this function
```c
void twiddle(long *xp, long *yp){
  *xp += *yp;
  *xp += *yp;
}
```
And this 
```c
void twiddle2(long *xp, long *yp){
  *xp += 2* *yp;
}
```

If there is memory alias of `xp` and `yp`, twiddle and twiddle2 may not be able to be optimized to same version. Since compiler know nothing of twiddle, it must assume there may exist memory aliasing of two pointers. And limit the set of possible optimization.