# Chapter 2: Representing and Manipulating Information

***

## 2.1 Information Storage

### 2.1.2 Data Sizes

Every computer has a word size, indicating the nominal size of pointer data. Since a virtual address is encoded by such
a word, the most important system parameter determined by the word size is the maximum size of the virtual address
space. That is, for a machine with a w-bit word size, the virtual addresses can range from 0 to 2^w − 1, giving the
program access to at most 2^w bytes. In recent years, there has been a widespread shift from machines with 32-bit word
sizes to those with word sizes of 64 bits. This occurred first for high-end machines designed for large-scale scientific
and database applications, followed by desktop and laptop machines, and most recently for the processors found in
smartphones. A 32-bit word size limits the virtual address space to 4 gigabytes(written 4 GB), that is, just over 4×10^9
bytes. Scaling up to a 64-bit word size leads to a virtual address space of 16 exabytes, or around 1.84 × 10^19 bytes.

Most 64-bit machines can also run programs compiled for use on 32-bit machines, a form of backward compatibility. So,
for example, when a program prog.c is compiled with the directive

```shell
linux> gcc -m32 prog.c
```

then this program will run correctly on either a 32-bit or a 64-bit machine. On the other hand, a program compiled with
the directive

```shell
linux> gcc -m64 prog.c
```

will only run on a 64-bit machine. We will therefore refer to programs as being either “32-bit programs” or “64-bit
programs,” since the distinction lies in how a program is compiled, rather than the type of machine on which it runs.

### 2.1.3 Addressing and Byte Ordering

For program objects that span multiple bytes, we must establish two conventions:
what the address of the object will be, and how we will order the bytes in memory. In virtually all machines, a
multi-byte object is stored as a contiguous sequence of bytes, with the address of the object given by the smallest
address of the bytes used. For example, suppose a variable x of type int has address 0x100; that is, the value of the
address expression &x is 0x100. Then (assuming data type int has a 32-bit representation) the 4 bytes of x would be
stored in memory locations 0x100, 0x101, 0x102, and 0x103. For ordering the bytes representing an object, there are two
common conventions. Consider a w-bit integer having a bit representation [xw−1, xw−2,...,x1, x0], where xw−1 is the most
significant bit and x0 is the least. Assuming w is a multiple of 8, these bits can be grouped as bytes, with the most
significant byte having bits[xw−1, xw−2,...,xw−8], the least significant byte having bits [x7, x6,...,x0], and the other
bytes having bits from the middle. Some machines choose to store the object in memory ordered from least significant
byte to most, while other machines store them from most to least. The former convention—where the least significant byte
comes first—is referred to as little endian. The latter convention—where the most significant byte comes first—is
referred to as big endian.
![](./resources/images/big%20endian%20and%20little%20endian.png)
Note that in the word 0x01234567 the high-order byte has hexadecimal value 0x01, while the low-order byte has value
0x67.

the following C code uses casting to access and print the byte representations of different program objects.

```c
#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}
```

#### Note that the byte ordering is not decided by the operating system but the architecture of the CPU!

