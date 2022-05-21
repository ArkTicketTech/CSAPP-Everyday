---
title: csapp-note-2022-05-20
tags:
  - csapp
  - 操作系统
  - 编译原理
  - CS基础知识
  - 读书笔记
cover: 'https://source.unsplash.com/random'
date: 2022-05-20 21:47:04
---
##
Chapter 5

### 
Loop unrolling

Loop unrolling is a program transformation that reduces the number of iterations
for a loop by increasing the number of elements computed on each iteration. 

We can generalize this idea to unroll a loop by any factor k, yielding k × 1
loop unrolling.

###
Enhancing Parallelism

- Multiple accumulators

  For a combining operation that is associative and commutative, such as integer
  addition or multiplication, we can improve performance by splitting the set of
  combining operations into two or more parts and combining the results at the
  end.

- Reassociation Transformation

  By a very small change in the
code, however, we can fundamentally change the way the combining is performed,
and also greatly increase the program performance