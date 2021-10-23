Let $x$ be the two's complement integer represented by bit pattern $[x_{w-1}, x_{w-2}, ..., x_{0}]$, and let $k$ be in the range $0\leq k < w$ Let $x'$ be the two's complement number represented by the $w-k$ bits $[x_{w-1}, x_{w-2}, ..., x_{k}]$, let $x''$ be the unsigned number $[x_{k-1}, ..., x_{0}]$ we have $x=2^{k}x'+x''$ and $0\leq x'' < 2^{k}$ giving $x'=⌊x/2^{k}⌋$. 

### two's complement division by a power of 2, rounding up
Let C variables `x` and `k` have two's complement value x and unsigned value k, respectively, such that $0\leq k < w$. The C expression `(x + (1<<k) - 1) >> k`, when the shift is performed arithmetically, yields the value $⌈x/2^{k}⌉$

## Fractional binary numbers
A notation of the form $b_{m}b_{m-1}...b_{1}b_{0}.b_{-1}b_{-2}...b_{-n+1}b_{-n}$ represents a number $b=\sum_{i=-n}^{m}2^{i}\times b_{i}$

### IEEE floating point representation
$V=(-1)^{s}\times M \times 2^{E}$
- sign s determines whether number is genative (s = 1) or positive (s = 0)
- significant M is a fractional binary number ranges between 1 and $2-\epsilon $ or between 0 and $1-\epsilon $
- exponent E weights the value by a power of 2
