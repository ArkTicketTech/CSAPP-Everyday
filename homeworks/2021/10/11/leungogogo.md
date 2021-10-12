# CSAPP 10/11 Notes
## Chapter 2. Representing and Manipulating Information
### 2.3 Integer Arithmetic
The nuances of computer arithmetic cause some weired behaviors of our program:
* Adding two postive integers gives a negative integer.
* `(x < y) != (x - y < 0)`

### 2.3.1 Unsigned Addition
* Addition Overflow: If both `x` and `y` are w-bit unsigned integers, we may require `w + 1` bits to represent their sum.
* For `x`, `y` s.t. `0 <= x, y < 2^w`, we have:

  ![Screen Shot 2021-10-11 at 8 17 12 PM](https://user-images.githubusercontent.com/26990923/136885470-0b7da54d-695a-408a-8608-269bb072c3e1.png)

* In C and many other programming languages, integer overflow will not cause errors, but we want to identify it to prevent bugs in the program.
