- ## 9.8.4 User-Level Memory Mapping with the `mmap` Function  
	- 用户可以通过调用 mmap 方法，将 objects 映射到一段虚拟内存中  
	- prot 变量代表 virtual memory area 的访问权限  
		- PROT_EXEC. Pages in the area consist of instructions that may be executed by the CPU.  
		  PROT_READ. Pages in the area may be read.  
		- PROT_WRITE. Pages in the area may be written.  
		- PROT_NONE. Pages in the area cannot be accessed.  
	- flag 代表 mapped object 是共享还是私有的  
		- MAP_ANON MAP_PRIVATE MAP_SHARED  
	- munmap用于取消映射  