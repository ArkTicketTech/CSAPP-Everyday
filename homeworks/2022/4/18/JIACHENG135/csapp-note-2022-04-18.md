---
title: csapp-note-2022-04-18
tags:
  - csapp
  - 操作系统
  - 编译原理
  - CS基础知识
  - 读书笔记
image: /images/csapp-note-2022-04-18.JPG
date: 2022-04-17 20:16:16
---
## Chaptor 1. 计算机系统漫游
- What is the Lifetime of Hello Program

  ![1](assets/1-1-Life-Time-of-Hello-Program.png)

- How compilation system work?

  ![2](assets/1-2-How-compilation-system-work.png)

- Why a programmer needs to know how compilation system work?

    - Optimize the performance of a program
      - Q1: Is `switch` much more efficient then multiple `if-else`?
      - Q2: What's the cost of a function call?
      - Q3: Is `while` much more efficient then multiple `for-loop`?
      > Will be answered after studying Chapter 3 and Chapter 5
    - Understanding link-time errors
      - Q1: What's the difference between global variable and local variable?
      - Q2: What's the difference between static lib and dynamic lib?
      > Will be answered after studying Chapter 7
    - Avoiding security issues
      - buffer overflow
        - how to avoid?
          - understand how data and information flow stored based on stack
    
    ![3](assets/1-3-Why-a-programmer-needs-to-know-how-compilation-system-work.png)