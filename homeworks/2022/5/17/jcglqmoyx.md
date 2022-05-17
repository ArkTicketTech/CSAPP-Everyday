Most of the operations are given as instruction classes, as they can have different variants with different operand
sizes. (Only leaq has no other size variants.) For example, the instruction class add consists of four addition
instructions: addb, addw, addl, and addq, adding bytes, words, double words, and quad words, respectively. Indeed, each
of the instruction classes shown has instructions for operating on these four different sizes of data. The operations
are divided into four groups: load effective address, unary, binary, and shifts. Binary operations have two operands,
while unary operations have one operand.