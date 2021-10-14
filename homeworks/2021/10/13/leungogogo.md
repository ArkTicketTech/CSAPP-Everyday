# CSAPP 10/13 Notes
## Chapter 2. Representing and Manipulating Information
### 2.4 Floating Point
* Rational numbers of the form `V = x * 2^y` can be encoded with floating-point representation, which is useful for representing:
  * very large numbers (|V| >> 0)
  * very small numbers (|V| << 1)
* Rounding: when a number can't be represented exactly hence have to adjusted upward or downward.

### 2.4.1 Fractional Binary Numbers
* We can simulate the fractional values of binary numbers with dot notation
  
  <img width="1032" alt="Screen Shot 2021-10-13 at 8 04 27 PM" src="https://user-images.githubusercontent.com/26990923/137243903-695b90e8-9e22-42b7-9e2c-5965e9f1b8b2.png">

* The binary number b can be represented as the summation: 

  <img width="204" alt="Screen Shot 2021-10-13 at 8 05 35 PM" src="https://user-images.githubusercontent.com/26990923/137244017-a123a484-0a7a-409d-9994-f776805f2dc7.png">

### 2.4.2 IEEE Floating-Point Representation
* The dot notation can't represent very large number, since it will need so many bits, and we need something like scientific notation.
* The IEEE floating-point standard represents a number in a form `V = (−1)^s × M × 2^E`.
  * `s` determines the size of number.
  * Significand `M` is a fractional binary numnber, which is like the base of decimal scientific notation.
  * The exponent `E` weights the value by a (possibly negative) power of `2`.

