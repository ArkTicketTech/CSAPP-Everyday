- ## 9.9.1 The `malloc` and `free` Functions  
	-  
	  ``` c
	  	  #include <stdlib.h>
	  	  void *malloc(size_t size);
	  	  	Returns: pointer to allocated block if OK, NULL on error
	  	      
	  	  返回一个指针，指向一个至少有size大小的block
	  	  在32位模式下，指针地址是8的倍数；64位模式下则是16的倍数
	  	  
	  	  #include <stdlib.h>
	  	  void free(void *ptr);
	  	  	Returns: nothing
	  	  free的ptr必须指向block开始的位置；free异常不会显式报错；但可能会在后面导致运行时错误
	  ```