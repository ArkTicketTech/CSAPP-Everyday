### unsigned multiplication by a power of 2
For C variables `x` and `k` with unsigned values $x$ and $k$, such that $0 \leq k < w$ The C expression `x << k` yields the value $x*_{w}^{u}2^{k}$

### Two's-complement multiplication by a power of 2
For C variables `x` and `k` with two's complement value $x$ and unsigned value $k$, such that $0 \leq k < w$, the C expression `x<<k` yields the value $x*_{w}^{t}2^{k}$

Integer multiplication is more costly than shifting and adding

For any real number $a$, define $⌊a⌋$ to be the unique integer $a'$ such that $a'\leq a < a'+1$, define $⌈a⌉$ to be the unique integer $a'$ such that $a'-1<a\leq a'$

### unsigned division by a power of 2
For C variables `x` and `k` with unsigned values $x$ and $k$, such that $0\leq k<w$, the C expression `x >> k` yields the value $⌊x/2^{k}⌋$

Let $x$ be the unsigned integer represented by bit pattern $[x_{w-1}, x_{w-2}, ..., x_{0}]$, and let $k$ be in the range $0\leq k<w$, let $x'$ be the unsigned number with $w-k$-bit representation $[x_{w-1}, x_{w-2}, ..., x_{k}]$, and let $x''$ be the unsigned number with $k$-bit representation $[x_{k-1}, ..., x_{0}]$. $x=2^{k}x'+x''$, and $0\leq x''<2^{k}$, so $⌊x/2^{k}⌋ = x'$

### two's complement division by a power of 2, rounding down
Let C variables `x` and `k` have two's-complement value $x$ and unsigned value $k$, respectively, such that $0\leq k < w$ The C expression `x >> k` when the shift is performed arithmetically, yields $⌊x/2^{k}⌋$