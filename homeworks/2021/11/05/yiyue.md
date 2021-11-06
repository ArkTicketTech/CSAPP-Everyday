features of machine code and its disassembled representations
- x86-64 instructions length 1-15 bytes. commonly used instructions & fewer operands -> smaller number of bytes
- unique decoding
- disassembler determines purely on the byte sequence
- slightly different naming convention from GCC

An x86-64 central processing unit (CPU) contains a set of 16 general-purpose registers storing 64-bit values

_operands_ - specify the source values to use in performing an operation and the destination location into which to place the result

operand types
- immediate - constant values
- register - contents of a register
- memory - access memory location according to a computed address