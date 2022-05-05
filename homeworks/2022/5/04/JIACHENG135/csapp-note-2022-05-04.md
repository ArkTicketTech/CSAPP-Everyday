---
title: csapp-note-2022-05-04
tags:
  - csapp
  - 操作系统
  - 编译原理
  - CS基础知识
  - 读书笔记
cover: 'https://source.unsplash.com/random'
date: 2022-05-04 20:36:31
---

- An example comparison of how exchange is implemented by pure instructions

  ![3-12-exchange-with-move-command](assets/3-12-exchange-with-move-command.png)


- How the parameter is saving in registers?
  - `%rdi`, `%rsi`, `%rdx`

- Why can't calculate `12*z` directly?
  - Since amplifier should be only `1` `2` or `4` and `8` 

    ![3-13-leaq-command](assets/3-13-leaq-command.png)


- Though it looks like a memory reference, it's direcly adding the results of operation

  ![3-14-leaq-command-policy](assets/3-14-leaq-command-policy.png)


- Some shifts instruction examples

  ![3-15-shift-instructions](assets/3-15-shift-instructions.png)


- Mutiple takes more time than shift so compiler may choose the optimal shift instruction first than multiply

  ![3-16-compiler-optimal-example1-shift-subs-mutiply](assets/3-16-compiler-optimal-example1-shift-subs-mutiply.png)

