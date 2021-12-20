# Chapter.5 优化程序性能

--------------

- 1. 必须选择一组适当的算法和数据结构
- 2. 必须编写出编译器能够有效优化的源代码

## 优化编译器的能力和局限性

> 1. 编译器无法优化不能确定指针是否指向同一个区域的程序

```cpp
void twiddle1(long *xp,long *yp){
    *xp += *yp;
    *xp+= *yp;
}

void twiddle2(long *xp,long *yp){
    *xp += 2* *yp;
}

```

上面的式子中,如果yp和xp没有指向同一个地址,就不会出错,但是如果指向了同一个地址,结果就会出错,`第一个程序是4倍的xp,第二个程序只有3倍的xp`

## 抽象的代码如何转换成更有效的代码

### 消除循环的低效率

比如循环的末尾会对条件进行一次计算  

所以如果有需要计算的条件,尽量在编写循环前计算出来,比如:  

```cpp
void combine2(vec_ptr v,data_t *dest){
    long i;
    long length = vec_length(v);

    *dest = IDENT;
    for(i=0;i<length;++i){
        data_t val;
        get_vec_element(v,i,&val);
        *dest = *dest OP val;
    }
}

```

上述代码中,长度在一开始就被计算了,每次循环末尾就不需要再次获取了




--------------


> Latex转Svg

https://www.latexlive.com/