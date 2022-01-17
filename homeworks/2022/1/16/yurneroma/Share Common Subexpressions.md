- Reuse portions of expressions
- GCC will do this with -O1
- Sum neighbors of i, j
	- ```
	  up = val[(i-1)*n + j] --> long inj = i * n + j; 
	  up = val[inj - n];
	  ```