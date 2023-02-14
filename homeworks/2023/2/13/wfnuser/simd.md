- ## Web Aside OPT: SIMD  
	- Achieving greater parallelism with vector instructions  
	- SIMD 是 single instruction, multiple data 的缩写 sim-dee  
		- SSE "streaming SIMD extensions" 1999 由 intel 引入  
		- AVX advanced vector extensions  
	- 一条指令可以处理整个 vectors of data  向量被一组特殊的向量寄存器存储 %ymm0-%ymm15  
	-  
	  > Current AVX vector registers are 32 bytes long, and therefore each can hold eight 32-bit numbers or four 64-bit numbers, where the numbers can be either integer or floating-point values.  

	- 举一个例子： 如果要计算 a0 .. a7 和 b0 .. b7 的乘积 单精度浮点数  
		- 只需要  `vmulps  (%rcs), %ymm0, %ymm1` 就可以了  
	- ![image.png](../assets/image_1676343637448_0.png)  
		-  
		  > We can see that the vector code achieves almost an eightfold improvement on the four 32-bit cases, and a fourfold improvement on three of the four 64-bit cases.  