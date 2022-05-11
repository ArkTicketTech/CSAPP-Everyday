---
title: csapp-note-2022-05-10
tags:
  - csapp
  - 操作系统
  - 编译原理
  - CS基础知识
  - 读书笔记
cover: 'https://source.unsplash.com/random'
date: 2022-05-10 20:38:44
---

- The basic idea of pipelining

![4-11-pipline-basic-idea](assets/4-11-pipline-basic-idea.png)


- The details of rising clock

![4-11-pipline-basic-idea-2](assets/4-11-pipline-basic-idea-2.png)

- The actual pipline and why there will be performance drop?
  - Since hard to schedule instructions and make them consume exact same time
  - So there will be idling

![4-12-actual-pipeline-lag](assets/4-12-actual-pipeline-lag.png)


- Why can't make pipeline too deep?
  - Data dependency: some instructions need data from previous instruction result
  - Control dependency: some instructions' behavior depends on the if condition.
    - Usually it's implemented by feedback. But it's very dangerous to have feedback machenism in pipeline

![4-13-why-cant-have-deep-pipline](assets/4-13-why-cant-have-deep-pipline.png)


![4-13-why-cant-have-deep-pipline-2](assets/4-13-why-cant-have-deep-pipline-2.png)
