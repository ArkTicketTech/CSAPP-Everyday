## Static Library

a mechanism for packaging related object modules into a single file 

**alternatives**

- let the compiler recognize standard function calls and to generate responding code

	- limitation: complexity of compiler (need new compiler version each time a function changes)

- put all the standard funtions into a monolithic relocatable file

	- limitation: waste of space, and every time a small change of functions need the relocatable file to be recompiled

- create seperate relocatable files for standard functions
	
	- limitation: it's hard for programmers to link

**advantages of static libraries**
	
	- space economic

	- easy to link

the order of libraries and object file matters!

general rule: put libraries to the end of the command line

