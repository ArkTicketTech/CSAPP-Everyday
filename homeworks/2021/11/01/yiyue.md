### Floating point in C
- from `int` to `float`, the number cannot overflow, but may be rounded
- from `int` or `float` to `double`, the exact numeric value can be preserved
- from `double` to `float`, the value can overflow to $+\infty$ or $-\infty$, since range is smaller. Otherwise, rounded
- from `float` or `double` to `int`, the value will be rounded toward zero