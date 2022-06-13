---
title: csapp-note-2022-06-12
tags:
  - csapp
  - 操作系统
  - 编译原理
  - CS基础知识
  - 读书笔记
cover: 'https://source.unsplash.com/random'
date: 2022-06-12 20:22:01
---

Chapter 7. Linking

Linking is the process of collecting and combining various pieces of code and data into a single file that can be loaded (copied) into memory and executed. Linking can be performed at compile time, when the source code is translated into machine code; at load time, when the program is loaded into memory and executed by the loader; and even at run time, by application programs. On early computer systems, linking was performed manually. On modern systems, linking is performed automatically by programs called linkers.

Why we need learn linking?

- Understanding linkers will help you build large programs

- Understanding linkers will help you avoid dangerous programming errors

- Understanding linking will help you understand how language scoping rules are implemented

- Understanding linking will help you understand other important systems concepts

- Understanding linking will enable you to exploit shared libraries

## Static Linking

- Step 1. Symbol resolution.

- Step 2. Relocation.

