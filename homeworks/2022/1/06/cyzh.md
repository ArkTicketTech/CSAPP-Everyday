### Overflow

#### 1.Memory Referencing Bug Example

```c
#include<stdio.h>
typedef struct{
    int a[2];
    double d;
} struct_t;

double fun(int i){
    volatile struct_t s;
    s.d = 3.14;
    s.a[i] = 1073741824;
    return s.d;
}
int main(){
    printf("%.10lf", fun(2));
    return 0;
}
/*
fun(0) -- 3.1400000000
fun(1) -- 3.1400000000
fun(2) -- 3.1399998665
fun(3) -- 2.0000006104
fun(4) -- 3.1400000000
fun(5) -- 3.1400000000
fun(6) -- There is no output(vscode)
This is Sementation Falut in the video
*/
```

C and CPP do not take subscript out of bounds into account, but the operating system does (complain).

| content        | subscript |
| -------------- | --------- |
| critical state | 6         |
| ?              | 5         |
| ?              | 4         |
| d7... d4       | 3         |
| d3... d0       | 2         |
| a[1]           | 1         |
| a[0]           | 0         |

And then I go up at some point when I hit 6, I'm modifying some state of program that it's using to kind of keep things organized most likely how it keeps track of allocated memory, and that's causing the program to crash.(primitive)



#### 2.Memory System Performance Example

```c
#include<stdio.h>
#include<time.h>
const int N = 2048;
int a[2048][2048], b[2048][2048];

int main(){
    clock_t t0, t1, t2;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            b[i][j] = i * 10000 + j;
    t0 = clock();
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            a[i][j] = b[i][j];
    t1 = clock();
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            a[j][i] = b[j][i];
    t2 = clock();
    printf("%lf\n", (double)(t1 - t0) / CLOCKS_PER_SEC);
    printf("%lf\n", (double)(t2 - t1) / CLOCKS_PER_SEC);
    return 0;
}
/*
0.032000 s
0.135000 s
*/
```

ref：[CMU 15213/15513 CSAPP 深入理解计算机系统 Lecture 01 Course Overview 中英字幕 - YouTube](https://www.youtube.com/watch?v=ScMxnXq6fbI&list=PLcQU3vbfgCc9sVAiHf5761UUApjZ3ZD3x&index=1)

