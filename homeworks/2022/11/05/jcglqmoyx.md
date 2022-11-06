 The performance of a program containing load operations depends on both the  pipelining capability and the latency of the load unit. One factor limiting the CPE  is that they all require reading one value from memory for each element computed.  With two load units, each able to initiate at most 1 load operation every clock  cycle, the CPE cannot be less than 0.50. For applications where we must load   k   values for every element computed, we can never achieve a CPE lower than   k/2. To determine the latency of the load operation on a machine, we can set up   a computation with a sequence of load operations, where the outcome of one   determines the address for the next. As an example, consider the function   list_len below, which computes the length of a linked list. In the loop of this   function, each successive value of variable   ls  depends on the value read by the  pointer reference   ls->next  . Our measurements show that function   list_len   has 

```c
typedef struct ELE {
    struct ELE *next;
    long data;
} list_ele,  *list_ptr;

long list_len(list_ptr ls) {
    long len = 0;
    while (ls) {
        len++;
        ls = ls->next;
    }
    return len;
}
```

 a CPE of 4.00, which we claim is a direct indication of the latency of the load  operation. To see this, consider the assembly code for the loop: 

```assembly
// Inner loop of list_len
// ls in %rdi, len in %rax
 .L3: loop:
 addq $1, %rax Increment len
 movq (%rdi), %rdi ls = ls->next
 testq %rdi, %rdi Test ls
 jne .L3 If nonnull, goto loop
```



 The   movq   instruction on line 3 forms the critical bottleneck in this loop. Each  successive value of register   %rdi   depends on the result of a load operation having   the value in   %rdi   as its address. Thus, the load operation for one iteration cannot   begin until the one for the previous iteration has completed. The CPE of 4.00   for this function is determined by the latency of the load operation. Indeed, this   measurement matches the documented access time of 4 cycles for the reference   machine’s L1 cache.
