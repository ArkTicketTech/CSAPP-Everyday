### two's complement encoding

For vector ![equation](https://latex.codecogs.com/gif.latex?%5Cvec%7Bx%7D%3D%5Bx_%7Bw-1%7D%2C%20x_%7Bw-2%7D%2C%20...%2C%20x_%7B0%7D%5D):

![equation](https://latex.codecogs.com/gif.latex?B2T_%7Bw%7D%28%5Cvec%7Bx%7D%29%5Cdoteq%20-x_%7Bw-1%7D2%5E%7Bw-1%7D&plus;%5Csum_%7Bi%3D0%7D%5E%7Bw-2%7Dx_%7Bi%7D2%5E%7Bi%7D)

_sign bit_ - The most significant bit x<sub>w-1</sub>
Function B2T<sub>w</sub> is a bijection

### Conversion from two's complement to unsigned

For x such that ![equation](https://latex.codecogs.com/gif.latex?TMin_%7Bw%7D%5Cleq%20x%5Cleq%20TMax_%7Bw%7D)
![equation](https://latex.codecogs.com/gif.latex?T2U_%7Bw%7D%28x%29%3D%5Cleft%5C%7B%5Cbegin%7Bmatrix%7D%20x&plus;2%5E%7Bw%7D%2C%20x%3C0%5C%5C%20x%2C%20x%5Cgeq%200%20%5Cend%7Bmatrix%7D%5Cright.)


![equation](https://latex.codecogs.com/gif.latex?B2U_%7Bw%7D%28T2B_%7Bw%7D%28x%29%29%3DT2U_%7Bw%7D%28x%29%3Dx&plus;x_%7Bw-1%7D2%5E%7Bw%7D)

### Unsigned to two's complement conversion

For u such that ![equation](https://latex.codecogs.com/gif.latex?0%5Cleq%20u%5Cleq%20UMax_%7Bw%7D)

![equation](https://latex.codecogs.com/gif.latex?U2T_%7Bw%7D%28u%29%3D%5Cleft%5C%7B%5Cbegin%7Bmatrix%7D%20u%2C%20%26u%5Cleq%20TMax_%7Bw%7D%20%5C%5C%20u-2%5E%7Bw%7D%2C%20%26%20u%3ETMax_%7Bw%7D%20%5Cend%7Bmatrix%7D%5Cright.)


![equation](https://latex.codecogs.com/gif.latex?U2T_%7Bw%7D%28u%29%3D-u_%7Bw-1%7D2%5E%7Bw%7D&plus;u)

### Expansion of a two's complement number by sign extension

Let w' = w + k
![equation](https://latex.codecogs.com/gif.latex?B2T_%7Bw&plus;k%7D%28%5B%5Cunderset%7Bk%20times%7D%7B%5Cunderbrace%7Bx_%7Bw-1%7D%2C%20...%2C%20x_%7Bw-1%7D%2C%7D%7Dx_%7Bw-1%7D%2C%20x_%7Bw-2%7D%2C...%2Cx_%7B0%7D%5D%29%3DB2T_%7Bw%7D%28%5Bx_%7Bw-1%7D%2C%20x_%7Bw-2%7D%2C%20...%2C%20x_%7B0%7D%5D%29)

### Truncation of an unsigned number

Let ![equation](https://latex.codecogs.com/gif.latex?%5Cvec%7Bx%7D) be the bit vector ![equation](https://latex.codecogs.com/gif.latex?%5Bx_%7Bw-1%7D%2C%20x_%7Bw-2%7D%2C%20...%2C%20x_%7B0%7D%5D), let ![equation](https://latex.codecogs.com/gif.latex?%5Cvec%7Bx%7D%27) be the result of truncating it to k bits: ![equation](https://latex.codecogs.com/gif.latex?%5Cvec%7Bx%7D%27%20%3D%20%5Bx_%7Bk-1%7D%2C%20x_%7Bk-2%7D%2C...x_%7B0%7D%5D). Let ![equation](https://latex.codecogs.com/gif.latex?x%3DB2U_%7Bw%7D%28%5Cvec%7Bx%7D%29) and ![equation](https://latex.codecogs.com/gif.latex?x%27%3DB2U_%7Bk%7D%28%5Cvec%7Bx%7D%27%29)
then ![equation](https://latex.codecogs.com/gif.latex?x%27%3Dx%5C%3A%20mod%5C%3A%202%5E%7Bk%7D)

### Truncation of a two's complement number

Let ![equation](https://latex.codecogs.com/gif.latex?%5Cvec%7Bx%7D) be the bit vector ![equation](https://latex.codecogs.com/gif.latex?%5Bx_%7Bw-1%7D%2C%20x_%7Bw-2%7D%2C%20...%2C%20x_%7B0%7D%5D), let ![equation](https://latex.codecogs.com/gif.latex?%5Cvec%7Bx%7D%27) be the result of truncating it to k bits: ![equation](https://latex.codecogs.com/gif.latex?%5Cvec%7Bx%7D%27%20%3D%20%5Bx_%7Bk-1%7D%2C%20x_%7Bk-2%7D%2C...x_%7B0%7D%5D). Let ![equation](https://latex.codecogs.com/gif.latex?x%20%3D%20B2T_%7Bx%7D%28%5Cvec%7Bx%7D%29) and ![equation](https://latex.codecogs.com/gif.latex?x%27%20%3D%20B2T_%7Bx%7D%28%5Cvec%7Bx%7D%27%29) then ![equation](https://latex.codecogs.com/gif.latex?x%27%20%3D%20U2T_%7Bk%7D%28x%5C%3A%20mod%5C%3A%202%5E%7Bk%7D%29)

Let ![equation](https://latex.codecogs.com/gif.latex?&plus;%5Cbegin%7Bmatrix%7D%20u%5C%5C%20w%20%5Cend%7Bmatrix%7D) for arguments x and y, where ![equation](https://latex.codecogs.com/gif.latex?0%5Cleq%20x%2Cy%20%3C%202%5E%7Bw%7D), as the result of truncating the integer sum x + y to be w bits long, viewing the result as unsigned number

Unsigned addition

For x and y such that ![equation](https://latex.codecogs.com/gif.latex?0%5Cleq%20x%2Cy%20%3C%202%5E%7Bw%7D)

![equation](https://latex.codecogs.com/gif.latex?x%5C%3B%20&plus;_%7Bu%7D%5E%7Bw%7Dy%3D%5Cleft%5C%7B%5Cbegin%7Bmatrix%7D%20x&plus;y%2C%20x&plus;y%3C2%5E%7Bw%7D%5C%3B%20Normal%5C%5C%20x&plus;y-2%5E%7Bw%7D%2C2%5E%7Bw%7D%5Cleq%20x&plus;y%3C2%5E%7Bw&plus;1%7D%5C%3B%20Overflow%20%5Cend%7Bmatrix%7D%5Cright.)