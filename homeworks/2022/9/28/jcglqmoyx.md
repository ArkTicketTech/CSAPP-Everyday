Gcc uses the scalar movement operations only to transfer data from memory
to an XMM register or from an XMM register to memory. For transferring data
between two XMM registers, it uses one of two different instructions for copying
the entire contents of oneXMMregister to another—namely, vmovaps for singleprecision
and vmovapd for double-precision values. For these cases, whether the
program copies the entire register or just the low-order value affects neither the
program functionality nor the execution speed, and so using these instructions
rather than ones specific to scalar data makes no real difference. The letter ‘a’
in these instruction names stands for “aligned.” When used to read and write
memory, they will cause an exception if the address does not satisfy a 16-byte
alignment. For transferring between two registers, there is no possibility of an
incorrect alignment.
