### floating point addition
if $a\geq b$, then $x +^{f}a\geq x +^{f}b$ for any values of a, b, and x other than NaN

### floating point multiplication
Define $x*^{f}y$ to be $Round(x\times y)$
- closed under multiplication
- commutative
- not associative

For any values a, b, and c other than NaN

$a\geq b$ and $c\geq 0 \Rightarrow a*^{f}c\geq b*^{f}c$

$a\geq b$ and $c\leq 0 \Rightarrow a*^{f}c\leq b*^{f}c$

$a*^{f}a\geq 0$ as long as $a\neq NaN$