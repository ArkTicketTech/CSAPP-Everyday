---
title: csapp-note-2022-05-24
tags:
  - csapp
  - 操作系统
  - 编译原理
  - CS基础知识
  - 读书笔记
cover: 'https://source.unsplash.com/random'
date: 2022-05-24 20:25:55
---
Chapter 5.12

## Load performance

The performance of a program containing load operations depends on both the
pipelining capability and the latency of the load unit.

## Store performance

In all of our examples thus far, we analyzed only functions that reference memeory mostly with load operations, reading from a memory location into a register.
Its counterpart, the store operation, writes a register value to memory. The performance of this operation, particularly in relation to its interactions with load
operations, involves several subtle issues.


Only a load operation is affected by
the result of a store operation, since only a load can read back the memory value
that has been written by the store.

With operations on registers, the processor can determine
which instructions will affect which others as they are being decoded into operations. With memory operations, on the other hand, the processor cannot predict
which will affect which others until the load and store addresses have been computed. Efficient handling of memory operations is critical to the performance of
many programs.
