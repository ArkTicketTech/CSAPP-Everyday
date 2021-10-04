## 2.2 Integer Representation

### 2.2.3 Two's-Complement Encodings

Binary to two's complementary

For vector $\overrightarrow{x} = [x_{w-1}, x_{w-2}, ..., x_0]$:

$$B2T(\overrightarrow{x})  = - x_{w-1}2^{w-1} + \sum_{i=0}^{w-2}{x_i2^i} $$

$x_{w-1}$: the most significant bit, the sign bit.

So if only the most significant bit is set to 1, the value should be the smallest.