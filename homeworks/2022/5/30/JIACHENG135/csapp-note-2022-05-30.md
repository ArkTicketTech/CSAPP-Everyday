---
title: csapp-note-2022-05-30
tags:
  - csapp
  - 操作系统
  - 编译原理
  - CS基础知识
  - 读书笔记
cover: 'https://source.unsplash.com/random'
date: 2022-05-30 20:14:38
---
Chapter 5 Identifying and Eliminating Performance Bottleneck

- Program Profiling
  Program profiling involves running a version of a program in which instrumentation code has been incorporated to determine how much time the different parts of the program require. It can be very useful for identifying the parts of a program we should focus on in our optimization efforts. One strength of profiling is that it can be performed while running the actual program on realistic benchmark data.

  - determines how much CPU time was spent for each of the functions in the program.
  - computes a count of how many times each function gets called, categorized by which function performs the call

- Using a Profiler to Guide Optimization

  ![5-1-program-profile](/images/csapp/5-1-program-profile.png)