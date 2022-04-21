---
title: csapp-note-2022-04-20
tags:
  - csapp
  - 操作系统
  - 编译原理
  - CS基础知识
  - 读书笔记
image: /images/csapp-note-2022-04-20.JPG
date: 2022-04-19 20:18:44
---
## Chapter 1。 计算机系统漫游
- Amdahl's Law
  - $k$ 为加速比， $\alpha$ 为可加速部分占比

  ![1-9-Amdahls-Law](assets/1-9-Amdahls-Law.png)

- How to speed up?
  
  ![1-10-concurrency-parallelsim](assets/1-10-concurrency-parallelsim.png)
  
  - Threading level concurrency
    - Mordern processor can have multiple CPUs. And different CPU can share same L3 cache. So multiple threads can enhance efficiency.
    - Q1: What's `hyperthreading` processor ?
      - Inner CPU has multiple PCs and register files, but single FA(浮点运算部件)，so we need to switch between threads to finish each calculation. Normal single thread processor takes ~`20000` periods to switch between threads, but `hyperthreading` processor can decide which thread to be executed within one period, switching thread takes significant cost and then utilize CPU resources efficiently. 
    

  
  - Instruction level parallelsim

    ![1-11-instruction-level-parallelsim](assets/1-11-instruction-level-parallelsim.png)
  
    - Q1: What is `SIMD`?
      - Single Instruction Multiple Data
      
      ![1-12-SIMD](assets/1-12-SIMD.png)





