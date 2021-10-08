# CSAPP 10/7 Notes
## Chapter 2. Representing and Manipulating Information
### 2.1.3 Addressing and Byte Ordering
* Objects are stored as a consecutive sequence of bytes, with the smallest address of the bytes used as its address.
* We have two conventions to order the bytes representing an object:
  1. Little Endian:

      ![Screen Shot 2021-10-07 at 7 51 05 PM](https://user-images.githubusercontent.com/26990923/136490710-af0616ff-3ae0-44a1-8d31-aaab195bc89e.png)
  
  2. Big Endian:

      ![Screen Shot 2021-10-07 at 7 51 30 PM](https://user-images.githubusercontent.com/26990923/136490755-0671c854-0308-4410-948a-425a13caad88.png)
* Many recent microprocessor chips are bi-endian, which means they support both little and big endians.
* Byte orderings are invisible for our applications, but at times it become an issue:
  1. When different machines communicate over a network, they must follow conventions for byte ordering.
  2. We need to know the bytes ordering to interprete machine code.
    * For example, the instruction `add %eax,0x200b43(%rip)` can be interpreted as `01 05 43 0b 20 00`.
  3. Byte ordering becomes visible when we want to circumvent the normal type system.
