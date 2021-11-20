when `t = a+b` where `a`, `b`, `t` are integers

`CF (unsigned) t < (unsigned) a` Unsigned overflow

`ZF (t == 0)` Zero

`SF (t < 0)` Negative

`OF (a < 0 == b < 0) && (t < 0 != a < 0)` signed overflow

Instruction | Based on | Description
------------|----------|------------
CMP S<sub>1</sub>, S<sub>2</sub> | S<sub>2</sub> - S<sub>1</sub> | Compare
cmpb |      | Compare byte
cmpw |      | Compare word
cmpl |      | Compare double word
cmpq |      | Compare quad word
 