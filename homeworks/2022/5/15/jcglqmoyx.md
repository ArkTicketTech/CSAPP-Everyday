# push and popping stack data

As we will see, the stack plays a vital role in the handling of procedure calls. By way of background, a stack is a data
structure where values can be added or deleted, but only according to a “last-in, first-out” discipline. We add data to
a stack via a push operation and remove it via a pop operation, with the property that the value popped will always be
the value that was most recently pushed and is still on the stack. A stack can be implemented as an array, where we
always insert and remove elements from oneend of the array. This end is called the top of the stack. With x86-64, the
program stack is stored in some region of memory. The stack grows downward such that the
top element of the stack has the lowest address of all stack elements. The stack pointer %rsp holds the address of the top stack element.
The pushq instruction provides the ability to push data onto the stack, while the popq instruction pops it. Each of
these instructions takes a single operand—the data source for pushing and the data destination for popping. Pushing a
quad word value onto the stack involves first decrementing the stack pointer by 8 and then writing the value at the new
top-of-stack address.
![image](https://s3.bmp.ovh/imgs/2022/05/14/cc06c08c5dba3e7f.png)