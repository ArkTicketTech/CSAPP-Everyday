---
title: csapp-note-2022-05-06
tags:
  - csapp
  - 操作系统
  - 编译原理
  - CS基础知识
  - 读书笔记
cover: 'https://source.unsplash.com/random'
date: 2022-05-06 23:46:37
---



![3-19-jump-instructions](assets/3-19-jump-instructions.png)


- Why condition move instruction is more efficient than jump instruction?
  - Branch predictor fail may cause memory clean and time consuming. 

![3-20-condition-move-instruction](assets/3-20-condition-move-instruction.png)

- How three types of loop is implemented in C?
  - Combination of conditional test and jump instructions

![3-21-loop-implementation](assets/3-21-loop-implementation.png)


- Why switch is more efficient than multiple if-else?
  - Since switch time is not related to the number of case.

![3-22-why-switch-more-efficient](assets/3-22-why-switch-more-efficient.png)


