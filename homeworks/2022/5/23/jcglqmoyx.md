## the run-time stack

A key feature of the procedure-calling mechanism of C, and of most other lan- guages, is that it can make use of the
last-in, first-out memory management disci- pline provided by a stack data structure. Using our example of procedure P
calling procedure Q, we can see that while Q is executing, P, along with any of the proce- dures in the chain of calls
up to P, is temporarily suspended. While Q is running, only it will need the ability to allocate new storage for its
local variables or to set up a call to another procedure. On the other hand, when Q returns, any local storage it has
allocated can be freed. Therefore, a program can manage the storage required by its procedures using a stack, where the
stack and the program registers store the information required for passing control and data, and for allocating memory.
As P calls Q, control and data information are added to the end of the stack. This information gets deallocated when P
returns.