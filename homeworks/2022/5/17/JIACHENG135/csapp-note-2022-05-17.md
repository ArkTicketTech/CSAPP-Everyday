---
title: csapp-note-2022-05-17
tags:
  - csapp
  - 操作系统
  - 编译原理
  - CS基础知识
  - 读书笔记
cover: 'https://source.unsplash.com/random'
date: 2022-05-17 20:49:29
---

##
Chapter 5.

### 5.2 Expressing Program Performance
Cycles per element **CPE** ro express program performance.

- Some examples of performance improvement
  - Code motion
    - $C$ `strlen` takes linear time. calculate the length of string in advance can help save time
  - Reducing procedure calls
    - Rather than initializing procedures to use function retrieve each element. Keep increasing pointers.
    - May not be able to improve performance but able for further optimization
  - Eliminatin unneeded Memory References
  - unroll loop

