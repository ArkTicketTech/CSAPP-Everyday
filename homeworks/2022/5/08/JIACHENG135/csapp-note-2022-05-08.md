---
title: csapp-note-2022-05-08
tags:
  - csapp
  - 操作系统
  - 编译原理
  - CS基础知识
  - 读书笔记
cover: assets-note-2022-05-08.JPG
date: 2022-05-08 13:18:33
---
- Different instructions with length
  ![4-1-different-instructions-with-length](assets/4-1-different-instructions-with-length.png)

- Six sequential stages of Y86 CPU
![4-2-six-stages-of-Y86-cpu](assets/4-2-six-stages-of-Y86-cpu.png)

- What's fetch stage?
  - Determine the length of instruction
    - Determine instruction has register input
    - Determine instruction has constant input

![4-3-fetch-stage-functions](assets/4-3-fetch-stage-functions.png)

- What's decode stage?
  - Has two reading port
  - Can read two input parallely

![4-4-decode-stage](assets/4-4-decode-stage.png)

- What's execute stage?
  - Three types of action
    - Logic calculation
    - Compute an effective address
    - `push` and `pop` action

![4-5-execute-stage](assets/4-5-execute-stage.png)

- What's memory stage?
  - Write to memory
  - Read from memory
  
![4-6-memory-stage](assets/4-6-memory-stage.png)


- What's write back stage?
  - Write back to register file
 
![4-7-write-back-stage](assets/4-7-write-back-stage.png)

- update PC stage

- An example of what subq instruction is doing
  - Fetch stage
    - Determine `subq` has two registers `%rdx` and `%rbx`
    - Then determine the length of instruction is 2, so `valP = PC + 2`
  - Decode stage
    - Read register value
  - Execute stage
    - output result
    - write CC value
  - Memory stage
    - nothing
  - Write back stage
    - write ALU result back to `%rbx`
  - Update PC
    - `PC = valP`

![4-8-subq-instruction-example](assets/4-8-subq-instruction-example.png)

- An example of what data transfer instruction `irmoveq`
  - Fetch stage
    - Determine `irmoveq` has one registers `%rsp`
    - Determine `irmoveq` has one immediate number `8`
    - Then determine the length of instruction is 10, so `valP = PC + 10`
  - Decode stage
    - Don't need to read data from register so do nothing in this stage
  - Execute stage
    - It looks like don't have to do calculation for data transfer
    - Acutally ALU will compute `8 + 0` and write to register
  - Memory stage
    - nothing
  - Write back stage
    - write ALU result back to `%rsp`
  - Update PC
    - `PC = valP`

![4-8-irmoveq-instruction-example](assets/4-8-irmoveq-instruction-example.png)

![4-9-rmmoveq-instruction-example](assets/4-9-rmmoveq-instruction-example.png)

![4-10-pushq-instruction-example](assets/4-10-pushq-instruction-example.png)

