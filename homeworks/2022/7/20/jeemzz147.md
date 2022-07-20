在反汇编时，endian出错会出现问题

或者在c语言的指针用来绕过数据类型时，endian出错会出现问题

linux windows: little endian

sun : big endian

```
include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++)
    	printf(" %.2x", start[i]);
    printf("\n");
}
```

