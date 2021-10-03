# CSAPP 10/3 Notes
## Chapter 2. Representing and Manipulating Information
## 2.1 Information Storage
* The smallest addressable unit of memory for most machines is a byte (8 bits).
* The virtual memory can be viewed as a large array of bytes, and the index of each byte is its address, and set of all possible addresses is called address space.
* The value of a pointer in C is the virtual address of the first byte of a block.
## 2.1.1 Hexadecimal Notation
* Binary numbers are too verbose, so we can write bit pattern as base-16, or hexadecimal to make it more readable.
* Hexadecimal uses digits `0` through `9` along with characters `A` through `F` to represent 16 possible values.
* Notation: `0x1234ABCE`
* Conversions: Numbers from 0 to 15:
  ![Screen Shot 2021-10-03 at 10 46 07 AM](https://user-images.githubusercontent.com/26990923/135765431-a379974f-f28c-4af5-9e10-08cb80e9eb25.png)
