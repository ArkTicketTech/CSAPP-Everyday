### Detecting overflow of unsigned addition

For x and y in the range ![equation](https://latex.codecogs.com/gif.latex?0%20%5Cleq%20x%2Cy%20%5Cleq%20UMax_%7Bw%7D), let ![equation](https://latex.codecogs.com/gif.latex?s%5Cdoteq%20x&plus;_%7Bw%7D%5E%7Bu%7Dy), computation of s overflowed if and only if s < x (or s < y)

### unsigned negation

For any number x such that ![equation](https://latex.codecogs.com/gif.latex?0%5Cleq%20x%20%3C%202%5E%7Bw%7D), its w-bit unsigned negation ![equation](https://latex.codecogs.com/gif.latex?-_%7Bw%7D%5E%7Bu%7Dx) is given by

![equation](https://latex.codecogs.com/gif.latex?-_%7Bw%7D%5E%7Bu%7Dx%3D%5Cbegin%7Bcases%7D%20x%2C%20%26%20%5Ctext%7B%20if%20%7D%20x%3D0%20%5C%5C%202%5E%7Bw%7D-x%20%26%20%5Ctext%7B%20if%20%7D%20x%3E0%20%5Cend%7Bcases%7D)

### Two's-complement addition

For integer values x and y in the range ![equation](https://latex.codecogs.com/gif.latex?-2%5E%7Bw-1%7D%5Cleq%20x%2Cy%5Cleq%202%5E%7Bw-1%7D-1)
![equation](https://latex.codecogs.com/gif.latex?x&plus;_%7Bw%7D%5E%7Bt%7Dy%3D%5Cleft%5C%7B%5Cbegin%7Bmatrix%7D%20x&plus;y-2%5E%7Bw%7D%2C%202%5E%7Bw-1%7D%20%5Cleq%20x&plus;y%5C%3B%20positive%5C%3Boverflow%5C%5C%20x%20&plus;%20y%2C%20-2%5E%7Bw-1%7D%20%5Cleq%20x&plus;y%20%3C%202%5E%7Bw-1%7D%5C%3B%20Normal%5C%5C%20x&plus;y&plus;2%5E%7Bw%7D%2C%20x&plus;y%3C-2%5E%7Bw-1%7D%5C%3B%20Negative%5C%3B%20overflow%20%5Cend%7Bmatrix%7D%5Cright.)

![equation](https://latex.codecogs.com/gif.latex?x&plus;_%7Bw%7D%5E%7Bt%7Dy%3DU2T_%7Bw%7D%28T2U_%7Bw%7D%28x%29&plus;_%7Bw%7D%5E%7Bu%7DT2U_%7Bw%7D%28y%29%29)

### Detecting overflow in two's complement addition

For x and y in the range ![equation](https://latex.codecogs.com/gif.latex?TMin_%7Bw%7D%5Cleq%20x%2Cy%20%5Cleq%20TMax_%7Bw%7D) let ![equation](https://latex.codecogs.com/gif.latex?s%20%5Cdoteq%20x%20&plus;_%7Bx%7D%5E%7Bt%7Dy) The computation of s has had positive overflow if and only if x > 0 and y > 0 but ![equation](https://latex.codecogs.com/gif.latex?s%5Cleq%200) The computation has had negative overflow if and only if x < 0 and y < 0 but ![equation](https://latex.codecogs.com/gif.latex?s%5Cgeq%200)

### Two's complement negation

For x in the range ![equation](https://latex.codecogs.com/gif.latex?TMin_%7Bw%7D%5Cleq%20x%20%5Cleq%20TMax_%7Bw%7D) its two's complement negation ![equation](https://latex.codecogs.com/gif.latex?-_%7Bw%7D%5E%7Bt%7Dx) is given by

![equation](https://latex.codecogs.com/gif.latex?-_%7Bw%7D%5E%7Bt%7Dx%3D%5Cleft%5C%7B%5Cbegin%7Bmatrix%7D%20TMin_%7Bw%7D%2C%20x%20%3D%20TMin_%7Bw%7D%5C%5C%20-x%2C%20x%20%3E%20TMin_%7Bw%7D%20%5Cend%7Bmatrix%7D%5Cright.)