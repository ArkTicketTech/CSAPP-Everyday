# Ch5 Program Optimizations

- Overview
- Generally Useful Optimizations
    - Code motion/precomputation
    - Strength reduction
    - Sharing of common subexpressions
    - Removing unecessary procedure calls
- Optimization Blockers
    - Procedure calls
    - Memory aliasing
- Exploiting Instruction-Level Parallelism
- Dealing with Conditionals

## Memory Aliasing

- exp1

```go
void twiddle1(long *xp, long *yp) 2{
	 *xp += *yp;
	 *xp += *yp;
}
```

- exp2

```go
void twiddle2(long *xp, long *yp) 8{
	 *xp += 2* *yp;
}
```

直观上来讲， exp1 需要6次内存访问， exp2只需要3次内存访问。 编译器把exp1 优化成exp2的话， 是一个正确的决策。 但是，  如果 *xp == yp 的话，   exp1的结果是4 * xp,  exp2 的结果是 3*xp*

编译器并不知道exp1 会被怎样调用， 以及参数是什么。  exp1优化成exp2的话， 就会产生不正确的结果， 这就叫 Memory Aliasing 问题