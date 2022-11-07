# basic strategies in performance improvement

## High-level design. 

Choose appropriate algorithms and data structures for the problem at hand. Be especially vigilant to avoid algorithms or coding techniques that yield asymptotically poor performance. 

## Basic coding principles. 
 Avoid optimization blockers so that a compiler can generate efficient code.  Eliminate excessive function calls. Move computations out of loops when possible. Consider selective compromises of program modularity to gain greater efficiency. 
## Low-level optimizations. 
 Structure code to take advantage of the hardware capabilities.  Unroll loops to reduce overhead and to enable further optimizations.  Find ways to increase instruction-level parallelism by techniques such as multiple accumulators and reassociation.  Rewrite conditional operations in a functional style to enable compilation via conditional data transfers. 
