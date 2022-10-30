*For a code segment forming a loop, we can classify the registers that are*
*accessed into four categories:*

* *Read-only. These are used as source values, either as data or to compute memory*
  *addresses, but they are not modified within the loop. The only readonly*
  *register for the loop in* *combine4* *is* *%rax*.
* *Write-only. These are used as the destinations of data-movement operations.*
  *There are no such registers in this loop.*
* *Local. These are updated and used within the loop, but there is no dependency*
  *from one iteration to another. The condition code registers are examples*
  *for this loop: they are updated by the* *cmp* *operation and used by the* *jne*
  *operation, but this dependency is contained within individual iterations.*
* Loop. These are used both as source values and as destinations for the loop,
  *with the value generated in one iteration being used in another. We can*
  *see that* *%rdx* *and* *%xmm0* *are loop registers for* *combine4*, corresponding*
  *to program values* *data+i* *and* *acc*.
