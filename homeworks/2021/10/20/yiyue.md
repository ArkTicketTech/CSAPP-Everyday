### Unsigned multiplication
For x and y such that ![equation](https://latex.codecogs.com/gif.latex?0%5Cleq%20x%2C%20y%5Cleq%20UMax_%7Bw%7D)

![equation](https://latex.codecogs.com/gif.latex?x*_%7Bw%7D%5E%7Bu%7Dy%3D%28x%5Ccdot%20y%29mod%5C%2C%202%5E%7Bw%7D)

### Two's complement multiplication
For x and y such that ![equation](https://latex.codecogs.com/gif.latex?TMin_%7Bw%7D%5Cleq%20x%2Cy%5Cleq%20TMax_%7Bw%7D)

![equation](https://latex.codecogs.com/gif.latex?x*_%7Bw%7D%5E%7Bt%7Dy%3DU2T_%7Bw%7D%28%28x%5Ccdot%20y%29%5C%2C%20mod%5C%2C%202%5E%7Bw%7D%29)

### Bit-level equivalence of unsigned and two's complement multiplication
Let ![equation](https://latex.codecogs.com/gif.latex?%5Cvec%7Bx%7D) and ![equation](https://latex.codecogs.com/gif.latex?%5Cvec%7By%7D) be bit vectors of length w. ![equation](https://latex.codecogs.com/gif.latex?x%20%3D%20B2T_%7Bw%7D%28%5Cvec%7Bx%7D%29) and ![equation](https://latex.codecogs.com/gif.latex?y%20%3D%20B2T_%7Bw%7D%28%5Cvec%7By%7D%29) Let ![equation](https://latex.codecogs.com/gif.latex?x%27%20%3D%20B2U_%7Bw%7D%28%5Cvec%7Bx%7D%29) and ![equation](https://latex.codecogs.com/gif.latex?y%27%20%3D%20B2U_%7Bw%7D%28%5Cvec%7By%7D%29) Then

![equation](https://latex.codecogs.com/gif.latex?T2B_%7Bw%7D%28x*_%7Bw%7D%5E%7Bt%7Dy%29%3DU2B_%7Bw%7D%28x%27*_%7Bw%7D%5E%7Bu%7Dy%27%29)

### Multiplication by a power of 2
Let x be the unsigned integer represented by bit patter [x<sub>w-1</sub>, x<sub>w-2</sub>, ..., x<sub>0</sub>] Then for any k &#8805; 0, the w+k-bit unsigned representation of $x2^{k}$ is given by $[x_{w-1}, x_{w-2}, ..., x_{0}, 0, ..., 0]$ where k zeros have been added to the right