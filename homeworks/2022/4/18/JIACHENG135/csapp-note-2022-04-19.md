---
title: csapp-note-2022-04-19
tags:
  - csapp
  - 操作系统
  - 编译原理
  - CS基础知识
  - 读书笔记
image: 'https://source.unsplash.com/random'
date: 2022-04-18 20:27:52
---
## Chapter 1。 计算机系统漫游
- Hardware organization of a system
  - PC: program count
    - 32-bit: 1 word = 4 Byte
    - 64-bit: 1 word = 8 Byte
    - repeatly update this memory to execute some commands. 
  - Register file
    - ex. How to compute A + B?

    ![1-4-Hardware-io](assets/1-4-Hardware-io.png)

    ![1-4-Hardware-io](assets/1-4-hardware-io.gif)

- Why operating system is designed like this?
  - prevent hardward abusement by applications
  - provide uniform machanism to control complicated hardwares

  ![1-4-Hardware-design](assets/1-4-Hardware-design.png)



![1-6-os-abstractions](assets/1-6-os-abstractions.png)

![1-7-memory-struc](assets/1-7-memory-struc.png)


- How the context is switched?

  ![1-7-switch-context](assets/1-7-switch-context.gif)

- Linux: everything is file. Simple but powerful
  - ex 1: same program can run at different disk/os, will learn Unix IO
![1-8-everything-is-file](assets/1-8-everything-is-file.png)