ELF executables are designed to be easy to load into memory, with contiguous chunks of the executable file mapped to contiguous memory segments. This mapping is described by the program header table.  From the program header table, we see that two memory segments will be initialized with the contents of the executable object file. 


Every running Linux program has a run-time memory image similar to the one in Figure 7.15. On Linux x86-64 systems, the code segment starts at address 0x400000, followed by the data segment.
