---
title: csapp-note-2022-05-28
tags:
  - csapp
  - 操作系统
  - 编译原理
  - CS基础知识
  - 读书笔记
cover: 'https://source.unsplash.com/random'
date: 2022-05-28 18:40:38
---
Chapter 5. Life in the Real World: Performance Improvement
Techniques

- High-level design 
  - Choose appropriate algorithms and data structures for the problem at hand. Be especially vigilant to avoid algorithms or coding techniques that yield asymptotically poor performance

- Basic coding principles
  - Eliminate excessive function calls. Move computations out of loops when possible. Consider selective compromises of program modularity to gain greater efficiency.
  - Eliminate unnecessary memory references. Introduce temporary variables to hold intermediate results. Store a result in an array or global variable only when the final value has been computed

- Low-level optimizations

  - Structure code to take advantage of the hardware capabilities. Unroll loops to reduce overhead and to enable further optimizations. Find ways to increase instruction-level parallelism by techniques such as multiple accumulators and reassociation. Rewrite conditional operations in a functional style to enable compilation via conditional data transfers.