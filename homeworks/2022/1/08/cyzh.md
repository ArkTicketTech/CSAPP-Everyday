#### Power-of-2 Multiply with Shift

- $u << k = u * 2^k$
- both signed and unsigned

And the reason for that as an optimization is historically the multiplication instruction took a lot longer than   a lot longer than a shift a shift instruction, Say one clock cycle to do a shift, and it used to be like 11, 12, 13 clock cycles to do a multiplicaion, Nowadays like on computers we use the shark machines it only takes three clock cycles to do multiplication, because they added a lot of hard ware to do that.

#### Unsigned Power-of-2 Divide with Shift

- $u >> k =  \lfloor u / 2^k\rfloor$
- use logical shift

#### Proper way to use unsigned as loop index

```c
unsigned int i;
for(i = cnt - 1; i < cnt; i--)
    a[i] ++;
```

### Word size

Right now the point is the hardware itself doesn't necessarily define what the word size is, It's combination of the hardware and the compiler that determines, what is the word size being used in this particular program.

### Byte Ordering

#### How are the bytes within a multi-byte word ordered in memory?

#### Conventions

- **Big Endian**: Sun, PPC Mac, Intrenet
  Least significant byte has hiahest address
- **Little Endian**:x86, ARM, processors running Android, IOS, and Windows
  Least significant byte has lowest address

```c
#include<stdio.h>

typedef unsigned char* pointer;

void show_bytes(pointer start, size_t len){
    size_t i; 
    for(i = 0; i < len; i++)
        printf("%p\t0x%.2x\n", start + i, start[i]);
    printf("\n");
}

int main(){
    int a = 15213;
    printf("int a = 15213;\n");
    show_bytes((pointer) &a, sizeof(int));

    return 0;
}
/*
int a = 15213;
000000000061FE1C        0x6d
000000000061FE1D        0x3b
000000000061FE1E        0x00
000000000061FE1F        0x00
*/
```

