Instruction | effect | description
------------|--------|------------
imulq S | R[%rdx]:R[%rax] <- S x R[%rax] | signed full multiply
mulq S | R[%rdx]:R[%rax] <- S x R[%rax] | unsigned full multiply
cqto | R[%rdx]:R[%rax] <- SignExtend(R[%rax]) | convert to oct word
idivq S | R[%rdx] <- R[%rdx]:R[%rax] mod S; <br> R[%rax] <- R[%rdx]:R[%rax] / S | Signed divide
divq S | R[%rdx] <- R[%rdx]:R[%rax] mod S; <br> R[%rax] <- R[%rdx]:R[%rax] / S | unsigned divide