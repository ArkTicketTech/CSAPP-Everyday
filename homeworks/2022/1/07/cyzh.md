### Logic operations in C

```c
!0x41 = 0x00
!0x00 = 0x01
!0x41 = 0x01
0x34 && 0x13 = 0x01
0x41 || 0x24 = 0x01
!0x41 = 0x01
```

#### Shift operations

##### Left Shift：x << y

Fill with 0's on right

##### Right Shift: x >> y

Logical Shift: Fill wih 0's on left

Arithmetic Shift: Replicate most significant bit on left.

```c
printf("%d\n", 1 << 31);
//output: -2147483648
printf("%d\n", 1 << 32);
// warning: left shift count >= width of type [-Wshift-count-overflow]
```

#### Sign Extension

##### Task:

- Given w-bit signed integer x
- Convert it to w + k - bit integer with same value

just expand forward by sign bit, that end up with the same value as this original bit

