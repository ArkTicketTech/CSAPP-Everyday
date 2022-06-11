---
title: csapp-note-2022-06-10
tags:
  - csapp
  - 操作系统
  - 编译原理
  - CS基础知识
  - 读书笔记
cover: 'https://source.unsplash.com/random'
date: 2022-06-10 20:25:40
---

Chapter 6. Summary

In general, faster storage technologies are more expensive per bit and have
smaller capacities. The price and performance properties of these technologies
are changing at dramatically different rates. In particular, DRAM and disk access
times are much larger than CPU cycle times. Systems bridge these gaps by organizing memory as a hierarchy of storage devices, with smaller, faster devices at
the top and larger, slower devices at the bottom. Because well-written programs
have good locality, most data are served from the higher levels, and the effect is
a memory system that runs at the rate of the higher levels, but at the cost and
capacity of the lower levels.

Programmers can dramatically improve the running times of their programs
by writing programs with good spatial and temporal locality. Exploiting SRAMbased cache memories is especially important. Programs that fetch data primarily
from cache memories can run much faster than programs that fetch data primarily
from memory