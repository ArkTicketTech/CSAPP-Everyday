- Index {{embed ((61e2459f-871d-4994-b981-9e57fd1423fa)) }}
  id:: 61ecd4ca-81d3-4bd0-b078-2ba9eee1e770
-
- 现代编译器使用很成熟的算法来优化程序， 编译器决定什么值被计算， 他们怎么被使用。编译器探索机会，简化表达式，在不同的地方使用更简单的计算，减少一个给定的计算的计算次数。 像gcc 这种编译器提供多种编译优化选项。-Og, -O1, -O2.
- 使用更高的优化选项，可以极大的提高程序性能， 可能会让程序体积变大，同时变得难以调适。 课程中，我们大多数使用-O1 选项，目的是想探索，在相同的优化级别下， 使用不同的c代码写出来，性能差别非常大。我们可以做到，-O1优化级别下写的c代码，性能轻松打败最高编译优化级别的程序。
- 编译器必须非常小心， 尽量做一些安全的优化。意思是优化过的程序，必须在所有情况下和未优化过的程序表现一样。
	- 有个常见的问题叫 [[Memory Aliasing]]
	- Practice Problem 5.1
		- The following problem illustrates the way memory aliasing can cause unexpected program behavior. Consider the following procedure to swap two values:
		- ```c
		  /* Swap value x at xp with value y at yp */
		  2 void swap(long *xp, long *yp)
		  3{
		  4 *xp=*xp+*yp;/*x+y */
		  5 *yp=*xp-*yp;/*x+y-y=x*/
		  6 *xp=*xp-*yp;/*x+y-x=y*/
		  7}
		  ```
		- 如果 *xp == *yp , 那么交换的结果将会导致*xp = 0, *yp = 0
	- id:: 61ecd492-d5d0-45a3-bede-b3fd9d6fb9f2
-
-