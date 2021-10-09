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

### Characterizing TAdd
+ Functionality
  - True sum requires w+1 bits
  - Drop off MSB
  - Treat remaining bits as 2’s comp. integer

![TAddw.png](TAddw.png)

----
## Multiplication
+ Goal: Computing Product of w-bit numbers x, y
  - Either signed or unsigned
+ Exact results can be bigger than w bits
  - Unsigned: up to 2w bits
  - Result range: 0 ≤ x * y ≤ (2<sup>w</sup> – 1)<sup>2</sup> = 2<sup>2w</sup> – 2<sup>w+1</sup> + 1
  - Two’s complement min (negative): Up to 2w-1 bits
  - Result range: x * y  ≥ (–2<sup>w–1</sup>)*(2<sup>w–1</sup>–1)  =  –2<sup>2w–2</sup> + 2<sup>w–1</sup>
  - Two’s complement max (positive): Up to 2w bits, but only for (TMinw)2
  - Result range: x * y ≤ (–2<sup>w–1</sup>)<sup>2</sup>  =  2<sup>2w–2</sup>
+ Maintaining exact results needs to:
  - keep expanding word size with each product computed
  - is done in software, if needed. 
  - e.g., by “arbitrary precision” arithmetic packages

### Unsigned Multiplication in C
|||
|--|--|
|Operand|w bits|
|True Product|2*w bits|
|Discard|w bits|
+ Standard Multiplication Function
  - Ignores high order w bits
+ Implements Modular Arithmetic
  - UMult<sub>w</sub>(u , v) = u·v mod 2<sup>w</sup>

### Signed Multiplication in C

Same as unsigned multiplication but seem  most significant bit as signed bit

### Power-of-2 Multiply with Shift
|||
|--|--|
|Operand|w bits|
|True Product|w+k bits|
|Discard|w bits|
Same as x * 2<sup>k</sup>
----
## Shifting

### Unsigned Power-of-2 Divide with Shift
+ Quotient of Unsigned by Power of 2
  - u >> k gives `int`(u / 2<sup>k</sup>)
  - Uses **logical** shift **(左补0)**
### Signed Power-of-2 Divide with Shift
+ Quotient of Signed by Power of 2
  - x >> k gives `int`(x / 2<sup>k</sup>)
  - Uses **arithmetic** shift **(左补符号位)**
  - Rounds wrong direction when x < 0
### Correct Power-of-2 Divide
### 负数移位，向上取整
+ Quotient of Negative Number by Power of 2
  - Want `int`(x / 2<sup>k</sup>) <font color=#FF0000>**+ 1**</font>    (Round Toward 0) **向上取整**
  - Compute as `int`(x+2<sup>k</sup>-1)/ 2<sup>k</sup>
    * In C: (x + (1<<k)-1) >> k
    * Biases dividend toward 0
----
## Negation: Complement & Increment
+ Negate through complement and increase:
+ Exp: `~x + 1 == -x`
+ Canonical Exps:
   - <font color=FF0000>**0和Tmin的补码都是其本身**</font>

|Val|Decimal|Hex|Binary|
|:--:|:--:|:--:|:--:|
|0|0|00 00|00000000 00000000|
|~0|-1|FF FF|11111111 11111111|
|~0+1|0|00 00|00000000 00000000|

`x = TMin`
|Val|Decimal|Hex|Binary|
|:--:|:--:|:--:|:--:|
|-x|-32768|80 00|10000000 00000000|
|~x|32767|7F FF|01111111 11111111|
|~x+1|-32768|80 00|10000000 00000000|