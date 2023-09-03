#include<stdio.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
	printf(" %.2x", start[i]);    //line:data:show_bytes_printf
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int)); //line:data:show_bytes_amp1
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float)); //line:data:show_bytes_amp2
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *)); //line:data:show_bytes_amp3
}
int test1_endian() {
    int i = 1;
    char *a = (char *)&i;
    if (*a == 1)
         printf("小端\n");
    else
         printf("大端\n");
    return 0;
}
int main(int argc, char const *argv[])
{
    test1_endian();
    short sx=-12345;
    unsigned short usx=sx;
    int x=sx;
    unsigned ux=usx;
    printf("sx = %d:\t",sx);
    show_bytes((byte_pointer)&sx,sizeof(short));
    
    printf("usx = %u:\t",usx);
    show_bytes((byte_pointer)&usx,sizeof(unsigned short));

    printf("x = %d:\t",x);
    show_bytes((byte_pointer)&x,sizeof(int));
   

    printf("ux = %u:\t",ux);
    show_bytes((byte_pointer)&ux,sizeof(unsigned));
    return 0;
}
