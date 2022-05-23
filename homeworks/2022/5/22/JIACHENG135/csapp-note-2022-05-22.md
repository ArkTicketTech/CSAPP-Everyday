---
title: csapp-note-2022-05-22
tags:
  - csapp
  - 操作系统
  - 编译原理
  - CS基础知识
  - 读书笔记
cover: 'https://source.unsplash.com/random'
date: 2022-05-22 20:43:17
---
Chapter 5.11 Limiting Factors

We have seen that the critical path in a data-flow graph representation of a
program indicates a fundamental lower bound on the time required to execute a
program. That is, if there is some chain of data dependencies in a program where
the sum of all of the latencies along that chain equals $T$ , then the program will
require at least $T$ cycles to execute. 

assume that a program requires a total of $N$ computations of some operation, that the
microprocessor has $C$ functional units capable of performing that operation, and
that these units have an issue time of $I$ . Then the program will require at least
$N \times \frac{I}{C}$ cycles to execute. 

- Register splitting

  If a program has a degree of parallelism $P$ that exceeds
  the number of available registers, then the compiler will resort to spilling, storting some of the temporary values in memory, typically by allocating space on the
  run-time stack. Once a compiler must resort to register spilling, any advantage of maintaining
  multiple accumulators will most likely be lost.

- Branch prediction and misprediction penalties

  a conditional branch can
incur a significant misprediction penalty when the branch prediction logic does
not correctly anticipate whether or not a branch will be taken. 

  For inherently unpredictable cases, program performance can
be greatly enhanced if the compiler is able to generate code using **conditional data transfers** rather than **conditional control transfers**. This cannot be controlled
directly by the C programmer, but some ways of expressing conditional behavior
can be more directly translated into conditional moves than others.