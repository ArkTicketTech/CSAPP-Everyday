# Bits, Bytes, & Integers II
## Addition
### Unsigned Addition
+ Standard Addition Function
  - Ignores carry output
+ Implements Modular Arithmetic
  - s = UAdd<sub>w</sub>(u, v) = (u + v) mod 2<sup>w</sup>

### Two’s Complement Addition
+ TAdd and UAdd have Identical Bit-Level Behavior
  - Signed vs. unsigned addition in C:
  
``` C
int s, t, u, v;
s = (int) ((unsigned) u + (unsigned) v);
t = u + v
```

  - Will give `s == t`

### TAdd Overflow
- True sum requires w+1 bits
- Drop off MSB
- Treat remaining bits as 2’s comp. integer

![TrueSumOverflow.png](TrueSumOverflow.png)
----
## Negation
----
## Multiplication
----
## Shifting