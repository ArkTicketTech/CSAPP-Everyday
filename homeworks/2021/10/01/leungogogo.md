# CSAPP 10/1 Notes
## 1.9 Important Themes
### Amdahl’s Law
* When we optimize one part of the system, the effect of on the overall system performance depends on:
   1. how significant is this part
   2. how fast did we speed it up.
* **Amdahl's law**: Say we improve a fraction of `alpha` of the system by a factor `k`, we have:

  ![Screen Shot 2021-10-01 at 6 57 01 PM](https://user-images.githubusercontent.com/26990923/135700321-c1148115-9a33-4c51-86d7-433b6c4c88f2.png)
  
  So the speedup `S = T_old / T_new`:
  
  ![Screen Shot 2021-10-01 at 6 57 47 PM](https://user-images.githubusercontent.com/26990923/135700339-f799ebf0-af44-4bb0-89df-5b0da9542cab.png)

* Interesting point, if we increase `k` to infinity, , then `S = 1 / (1 - alpla)`.

* Concurrency: A system with multiple simultaneous activities.
* Parallelism: Taking advantages of concurrency to speed up the system.

### Thread-Level Concurrency
* With threads, we can have multiple control flows executing within a single process by letting the computer switching among them.
* Uniprocessor system: single-core processor switching among different tasks.
* Multiprocessor system: A system consists of multiple processors under a single OS kernel.
  * Multi-core processor: multiple CPUs ntegrated onto a single integrated-circuit chip.
    ![Screen Shot 2021-10-01 at 7 35 12 PM](https://user-images.githubusercontent.com/26990923/135701153-65af21fc-5bff-42f1-9fc2-1d2c3332c37d.png)
  * Hyperthreading: Allows a single CPU to execute multiple flows of control.
    * Having more than one copies of some parts of the CPU, such as PC, and register files, while having one copy of other parts.
    * Swtiching between threads on a cycle-by- cycle basis. 
    ![Screen Shot 2021-10-01 at 7 38 26 PM](https://user-images.githubusercontent.com/26990923/135701224-d093ddd2-2e0e-49ff-a738-5d99a5408520.png)
### Instruction-Level Parallelism
* Pipelining: Split the execution of instructions into different steps, and organize the processor hardware as a series of stages, each performing one step.

### SIMD
* Build special hardware that allows a single instruction to cause multiple operations to be performed in parallel.
* For example, we can add 8 pairs of numbers in parallel.
