---
title: csapp-note-2022-05-07
tags:
  - csapp
  - 操作系统
  - 编译原理
  - CS基础知识
  - 读书笔记
cover: assets-note-2022-05-07.JPG
date: 2022-05-07 18:39:18
---


- Struct data alignment

  ![3-23-data-alignment](assets/3-23-data-alignment.png)

- An example for data alignment for struct

  ![3-23-data-alignment-example](assets/3-23-data-alignment-example.png)

- Example of union struct to save space

  ![3-24-union-example](assets/3-24-union-example.png)


- How to resist buffer overflow attack?
  - Stack Randomization
    - Each runtime on different/random addr
  - Stack corruption detection
    - check Canary value is modified or not
  - Limiting executable code regions

  ![3-25-how-to-resist-buffer-overflow-attack](assets/3-25-how-to-resist-buffer-overflow-attack.png)

