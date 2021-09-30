# CSAPP 9/29 Notes
## 1.5 Caches Matter
* It takes time for the system to move information from one place to another, which is considered as overhead that slow down the program.
* Larger storage devices are slower than smaller storage devices.
  * For example, it's faster to read from memory than disk, faster to read from register than memory.
* To speed up the process of reading from memory to CPU, we build **cache** which temporarily holds the information the CPU is likely need in the near future.
  * Cache exploits locality, which means the tendency for programs to access data and code in localized regions. For example, if you access `a[0]` of an array, you are likely to access `a[1]`.
* The `L1` and `L2` cache are implemented with **static random access memory(SRAM)**.
## 1.6 Storage Devices Form a Hierarchy
* Memory Hierarchy: storage at one level serves as a cache for storage at the next lower level.
  ![Screen Shot 2021-09-29 at 7 10 21 PM](https://user-images.githubusercontent.com/26990923/135374128-4dee2d3a-16a6-41e0-8692-5b6280c285a3.png)
## 1.7 The Operating System Manages the Hardware
