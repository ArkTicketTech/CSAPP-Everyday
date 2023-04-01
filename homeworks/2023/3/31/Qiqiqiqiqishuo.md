# Chapter 1 A tour of Computer Systems

## 1.2 Programs Are Translated by Other Programs into Different Forms

### Aside The GNU project

Gcc 是 GNU 项目开发出的众多有用的工具之一（GNU short for GNU's Not Unix，类 Linux，类 Vim 等有趣的名字） GNU 项目 是 1984年 理查德·斯托曼（与 Linus 有不少故事）发起的有着 开付出一整套 源代码不受 修改或分发 限制的 类Unix 系统 的宏大目标的 免税慈善组织。GNU 项目已经开发除了 Linux 项目单独开发出的内核外的 有 Unix 操作系统主要部件（功能）的一套环境。GNU 环境包括 EMACS 编辑器、GCC 编译器、GDB 调试器、汇编器、链接器、操作（管理）二进制文件的工具（设施）及一些其他部件。GCC 编译器已经成长为支持多种语言，有为众多不同机器生成代码的能力，支持语言包括 C、C++、Fortran、Java、Pascal、Objective-C 和 Ada 语言

GNU 项目是一个 令人惊叹的成就（过于重要也常常被忽视掉，当先进的东西大家不再自发觉得它有多么令人惊叹时，他就已经走到人们的生活中，成为人们日常生活中的一部分了。比如 硬盘 ，上周 微扰酱 刚惊叹过它及相关技术的精妙）现代开源运动（普遍与 Linux 相关）智慧源泉 得益于 GNU 计划的 "free software" 的理念。Linux 如此流行 也很大程度上得益于 为 Linux 内核 提供环境的 GNU 工具

### Digression "free speech" --- "free beer"

#### Free as in beer

Free as in beer 免费的着重点在于 没有花销，对于被给予者没有期望，被给予者也不能参与到 "beer" 的工作中（无源代码，无法做修改、分发或修正bug及作出改进）

beerware license 并不是 "free as in beer"，而是 free speech，兼容 GPL license，请开发者或自己开心地喝一杯吧😄

#### Free as in Speech

Free as in Speech 着重点在 自由、开放，可以自由地得到软件使用（含源代码），一般来说是可以任意使用的。开放源代码也即可以了解软件是如何工作的，也可以去改进程序，自由分发软件。代表性的 License  有 General Public License(GPL)

有时 会称 "free as in speech" 这种软件为 "free software" 而不是 "open source software" 来强调 软件的 自由性

