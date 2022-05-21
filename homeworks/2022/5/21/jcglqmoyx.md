The load effective address instruction leaq is actually a variant of the movq in- struction. It has the form of an
instruction that reads from memory to a register,but it does not reference memory at all. Its first operand appears to
be a mem- ory reference, but instead of reading from the designated location, the instruction copies the effective
address to the destination. This instruction can be used to generate pointers for later memory references. In addition,
it can be used to compactly describe common arithmetic operations. For example, if register %rdx contains value x, then
the instruction leaq 7(%rdx,%rdx,4), %rax will set register %rax to 5x + 7. Compilers often find clever uses of leaq that have nothing to do
with effective address computations. The destination operand must be a register.