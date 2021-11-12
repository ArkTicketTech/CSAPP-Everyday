## Pushing and popping stack data

instruction | effect | description
------------|--------|------------
pushq S | R[%rsp] <- R[%rsp] - 8 <br> M[R%rsp] <- s | push quad word
popq D | D <- M[R[%rsp]]; <br> R[%rsp] <- R[%rsp] + 8 | pop quad word

## arithmetic and logical operations

_load effective address_ - `leaq` a variant of `movq`. It reads from memory to register, not reference memory