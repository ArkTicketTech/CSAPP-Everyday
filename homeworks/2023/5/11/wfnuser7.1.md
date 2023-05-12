- # Compiler Drivers  
	- ![image.png](../assets/image_1683861976702_0.png)  
	- 通过这个例子我们可以观测 linkers 是如何工作的。  
	- 编译系统通常提供一个 compiler driver 调用语言的 preprocessor \ compiler \ assembler \ linker  
	- 以 GNU 系统为例：  
	- `linux> gcc -Og -o prog main.c sum.c`  
	- 通过这行命令就可以触发编译的过程；通过 `gcc -v` 参数，可以看到具体的过程。  
	- ![image.png](../assets/image_1683862181134_0.png)  
	- 包括以下几个步骤：  
		-  
		  ```
		  		  cpp [other arguments] main.c /tmp/main.i
		  		  as [other arguments] -o /tmp/main.o /tmp/main.s
		  		  # do the same thing to sum.c
		  		  
		  		  ld -o prog [system object files and args] /tmp/main.o /tmp/sum.o
		  ```