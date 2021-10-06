# CSAPP 10/5 Notes
## Chapter 2. Representing and Manipulating Information
### 2.1.2 Data Size
* **Word Size**: indicates the size of the pointer data, each virtual address is encoded by a word.
* The word size determines the maximum size of virtual address space, if the word size is `w` bits, then the maximum virtual adrress will be `2^w - 1`.
  * A 32-bit word size limits the virtual address space to 4 gigabytes.
* We refer to programs as being either “32-bit programs” or “64-bit programs", depending on how they compile.
  * Most 64-bit computers can run 32-bit programs, but not the other way around.
* Size of different data types in C:

  ![Screen Shot 2021-10-05 at 7 32 48 PM](https://user-images.githubusercontent.com/26990923/136131555-b8ff6716-c54f-4be7-aa96-fa59a395073f.png)
* Program Portability: make the program insensitive to the exact sizes of the different data types.
  * Many program was written assuming the 32-bit data sizes, so many bugs popped up when migrating these programs to 64-bit machines because of the word size dependencies.
