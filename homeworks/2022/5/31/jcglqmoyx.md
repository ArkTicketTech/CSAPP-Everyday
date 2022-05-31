It is common to find assembly-code lines of the form

```asm
xorq %rcx,%rcx
```

in code that was generated from C where no exclusive-or operations were present.

* A. Explain the effect of this particular exclusive-or instruction and what useful operation it implements.

```text
This instruction is used to set register %rcx to zero.
```

* B. What would be the more straightforward way to express this operation in assembly code?

```asm
movq $0, %rcx
```

* C. Compare the number of bytes to encode any two of these three different implementations of the same operation.

```text
The version with xorq requires only 3 bytes, while the version with movq requires 7.
xor1 %ecx, %ecx will also do the same.
```