# CSAPP 10/9 Notes
## Chapter 2. Representing and Manipulating Information
### 2.2 Integer Representations
* In this chapter, we will introduce two ways to encode integers with bits:
  1. One can only represent non-negative integers.
  2. One can represent negative, zero and positive integers.

* Terminology

![Screen Shot 2021-10-09 at 5 58 42 PM](https://user-images.githubusercontent.com/26990923/136677477-374ba0a8-98c1-4cef-ae42-487ee02a1cdc.png)

### 2.2.1 Integral Data Types
* The C language supports different integral data types, which can be specified by keyword (`char`, `short`, `int` and etc.) as well as whether the numbers they represent are all nonnegative (`unsigned`).
* The number of bytes allocated for different data types is machine-dependent (32 or 64 bit machine). And base on the bytes allocated for each type, they can represent different ranges.
  * Typical ranges of data types for 32 bit machine

    ![Screen Shot 2021-10-09 at 6 17 24 PM](https://user-images.githubusercontent.com/26990923/136677791-1bbb28d9-30f5-4b03-adbd-d151d71c980b.png)

  * Typical ranges of data types for 64 bit machine

    ![Screen Shot 2021-10-09 at 6 17 39 PM](https://user-images.githubusercontent.com/26990923/136677795-e5a4adf2-6173-4a90-89a8-a7d796bcfafc.png)
