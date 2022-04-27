---
title: csapp-note-2022-04-21
tags:
  - csapp
  - 操作系统
  - 编译原理
  - CS基础知识
  - 读书笔记
image: /images/csapp-note-2022-04-21.JPG
date: 2022-04-19 20:41:53
---
# Chapter 2 信息的存储


- 一些进制转换方式
  ![2-1-dec-hex](assets/2-1-dec-hex.png)

  ![2-2-dec-with-hex](assets/2-2-dec-with-hex.png)

  ![2-3-word-size-virtual-address-space](assets/2-3-word-size-virtual-address-space.png)

  ![2-4-type-size](assets/2-4-type-size.png)

- Big Little Endian
  
  ![2-5-Big-Little-Endian](assets/2-5-Big-Smaller-Order.png)

  - Android and IOS
    - Little Endian
  
- A C program to print byte and their address

  ![2-6-byte-print](assets/2-6-byte-print.png)
  
  - Results for same  `integer` value but different endian in different machine
  
    ![2-6-byte-print-res-1](assets/2-6-byte-print-res-1.png)

  - Results for same  `float` value but different endian in different machine
    
    ![2-6-byte-print-res-2](assets/2-6-byte-print-res-2.png)


  - Results for same  `integer` address but different endian in different machine

    ![2-6-byte-print-res-3](assets/2-6-byte-print-res-3.png)

  - Same value of `int` and `float`, hex representation has some overlap, is this a coincidence?

    ![2-7-int-and-float-overlap](assets/2-7-int-and-float-overlap.png)