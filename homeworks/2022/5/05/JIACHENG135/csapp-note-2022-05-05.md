---
title: csapp-note-2022-05-05
tags:
  - csapp
  - 操作系统
  - 编译原理
  - CS基础知识
  - 读书笔记
cover: 'https://source.unsplash.com/random'
date: 2022-05-05 20:44:07
---

- Several condition code register
  - Carry flag: CF
  - Zero Flag: ZF
  - Sign flag: SF
  - Overflow flag: OF
  
![3-17-condition-code](assets/3-17-condition-code.png)

- How the if condition work when condition is equal from assemble instructions level?

![3-18-condition-code-example-equal](assets/3-18-condition-code-example-equal.png)

- How the if condition work when condition is less from assemble instructions level?
  - it depends on xOr of SF ^ OF

![3-18-condition-code-example-less](assets/3-18-condition-code-example-less.png)

- The set instruction summary for different conditions for signed numbers

![3-18-condition-code-example-set-summary](assets/3-18-condition-code-example-set-summary.png)

- The set instruction summary for different conditions for unsigned numbers

![3-18-condition-code-example-set-summary-unsigned](assets/3-18-condition-code-example-set-summary-unsigned.png)

