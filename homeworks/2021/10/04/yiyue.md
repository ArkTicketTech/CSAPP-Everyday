How compilation systems work
- Optimizing program performance
- Understanding link-time errors
- Avoiding security holes

Buses
- A collection of electrical conduits running throughout the system carrying bytes of information between components
- transfer fixed-size chunks of bytes - words. word sizes 4 bytes (32 bits) or 8 bytes (64 bits)

I/O devices
- system's connection to the external world
- e.g. keyboard & mouse (user input), display (user output), disk drive (long-term storage)
- I/O device connected to I/O buss by controller / adapter

Main memory
- temporary storage device holds a program and the data it manipulates
- consists of a collection of dynamic random access memory (DRAM)

Processor
- Central processing unit (CPU), the engine interprrets instructions stored in main memory
- core: word-size storage device (register) - program counter (PC)
- PC points at machine-language instruction in main memory

Instructions
- Load: copy byte/word from main memory -> register
- Store: copy byte/word from register -> main memory
- Operate: copy contents of two registers to ALU(arithmetic/logic unit), perform arithmetic operation, store the result > register
- Jump: word -> PC

Running the `hello` program
- shell program waits for command
- reads `./hello` and into register and store in memory
- `enter` key on keyboard. Shell loads the executable `hello`, copies the code and data from disk to main memory
- processor executes instructions in `hello` `main` routine

