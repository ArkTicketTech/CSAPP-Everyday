Encode any subset ![equation](https://latex.codecogs.com/gif.latex?A%5Csubseteq%20%5Cleft%20%5C%7B%200%2C%201%2C%20...%2C%20w%20-%201%20%5Cright%20%5C%7D) with a bit vector [a<sub>w-1</sub>, ..., a<sub>1</sub>, a<sub>0</sub>], where a<sub>i</sub> = 1 if and only if ![equation](https://latex.codecogs.com/gif.latex?i%20%5Cepsilon%20A)

logical operators `&&` and `||` do not evaluate their second argument if the result of the expression can be determined by the first

x = [x<sub>w-1</sub>, x<sub>w-2</sub>, ..., x<sub>0</sub>]
x << k
 - x is shifted k bits to the left
 - dropping off the k most significant bits and filling the right end with k zeros

x >> k
- _logical_ - fills the left end with k zeros, [0, ..., 0, x<sub>w-1</sub>, x<sub>w-2</sub>, ..., x<sub>k</sub>]
- _arithmetic_ fills the left end iwth k repetitions of the most significant bit, [x<sub>w-1</sub>, ..., x<sub>w-1</sub>, x<sub>w-1</sub>, x<sub>w-2</sub>, ..., x<sub>k</sub>]

Uniqueness of unsigned encoding - Function B2U<sub>w</sub> is a bijection
bijection: a function f that goes two ways: it maps a value x to a value y where y = f(x), it can also operate in reverse