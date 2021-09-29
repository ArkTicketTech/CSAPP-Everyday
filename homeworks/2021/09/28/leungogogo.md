# CSAPP 9/28 Notes
## 1.4 Processors Read and Interpret Instructions Stored in Memory
### Hardware Architecture of Computer System
![Screen Shot 2021-09-28 at 7 27 20 PM](https://user-images.githubusercontent.com/26990923/135192743-3dadc247-3e4c-494e-840d-8bf825e2a082.png)
#### Buses 
* Conduits that run throughout the system, which carries information between components.
* Designed to transfer fixed-size chunks of bytes known as words.
  * The size of words depends on different systems, most machines have word size of `4` bytes (`32` bits) or `8` bytes (`64` bits).

#### I/O Devices
* Examples of I/O devices: Mouse, keyboard, display, and disk drive(for long-term storage of data and programs).
* Each I/O device connects to the I/O bus by either an adapter or a controller.

#### Main Memory
* The main memory temporarily store the program and its data while the CPU is executing the program.
* Consists of a bunch of Dynamic Random Access Memory(DRAM).
* The memory is organized as an array of bytes, each byte has its own address.
* Each instruction in the program consists of some number of bytes.
* The size of variables in the program varies according to type:
  * `short`: 2 bytes
  * `int`, `float`: 4 bytes
  * `long`, `double`: 8 bytes

#### CPU
* Executes instructions stored in memory.
* Program Counter (PC): A word-size(4-byte) register that points to the machine instruction we are going to execute in the memory.
* Steps involved executing a machine instruction:
  1. CPU reads the instruction pointed by PC from memory.
  2. Interprets the instruction.
  3. Excute the instruction.
  4. Update the PC.
* Register file: A small storage device that consists of many word-size(4-byte) registers, each with its own unique name.
* Arithmetic Logic Unit (ALU): computation of data and address:
  * Load: load data from memory to a register, which overwrites the original data in the register.
  * Store: store data from a register to memory.
  * Operate: arithmetic operations such as `+`, `-`, `*`, `/`.
  * Jump: update the PC with new values (`if-else` branching).

### Running the `hello` Program
* First we need to type the command `./hello` in the terminal, as we tyep the command, the shell program **reads the characters into a register** and **store it in memory**.
 ![Screen Shot 2021-09-28 at 7 53 47 PM](https://user-images.githubusercontent.com/26990923/135195165-e721318c-0e51-4ba4-a344-e37d24916b68.png)

* Once we hit `enter`, we are done typing the command, and the shell program loads the executable file `hello` from **disk** to **memory** via DMA (which means data travel from disk directly to memory without passing through resiter file).
 ![Screen Shot 2021-09-28 at 7 56 43 PM](https://user-images.githubusercontent.com/26990923/135195426-b526e98e-4b6d-4e3b-9e50-c24048dc5b63.png)
* Once the program is loaded to memory, the CPU executes the instructions it contains. In this particular program `hello`, the CPU loads the string `"hello"` from memory to the output register file, which displays it on screen.
 ![Screen Shot 2021-09-28 at 7 59 11 PM](https://user-images.githubusercontent.com/26990923/135195646-8fdce31f-cf18-4cff-bdc6-e6825c80d540.png)
