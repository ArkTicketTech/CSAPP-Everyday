_concurrently_ - the instructions of one process are interleaved with the instructions of another process
_context switching_ - a mechanism the OS performs the interleaving
_context_ - state information (current values of PC, register file, contents of amin memory) the process needs in order to run
_kernal_
- manages transition from one process ot another
- A collection of code and data structures that the system uses to manage all the processes
_threads_
- multiple execution units in a process
- running in the context of process, sharing the same code and global data
_virtual memroy_ - an abstraction that provides each process with illusion that it has exclusive use of the main memory

Virtual address space
- Program code and data
  - code begins at the same fixed address
  - initialized directly from the contents of an executable object file
- heap
  - run-time heap
  - code and data areas fixed in size once the process begins running
  - heap expands and contracts dynamically at run time
- shared libraries
  - e.g. C standard library, math library
- stack
  - user stack - compiler uses to implement function calls
  - expands and contracts dynamically
- kernel virtual memory
  - application programs can't read/write the contents of this area or call functions defined in kernel code