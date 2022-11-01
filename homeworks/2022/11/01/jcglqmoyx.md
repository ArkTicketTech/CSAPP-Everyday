 the following snippet of code shows how accumulator  acc0  is updated in the inner loop of the code with 10 x 10 unrolling: 

 ```
 // Updating of accumulator acc0 in 10 x 10 urolling 
 vmulsd (%rdx), %xmm0, %xmm0   acc0 \ = data[i] 
 ```

The accumulator is kept in register   %xmm0  , and so the program can simply read   data[i]   from memory and multiply it by this register. 

The comparable part of the code for 20 x 20 unrolling has a much different form: 

```
// Updating of accumulator acc0 in 20 x 20 unrolling
vmovsd 40(%rsp), %xmm0
vmulsd (%rdx), %xmm0, %xmm0
vmovsd %xmm0, 40(%rsp)
```

The accumulator is kept as a local variable on the stack, at offset 40 from the stack pointer. The program must read both its value and the value of   data[i] from memory, multiply them, and store the result back to memory.  

Once a compiler must resort to register spilling, any advantage of maintaining multiple accumulators will most likely be lost. Fortunately, x86-64 has enough registers that most loops will become throughput limited before this occurs. 
