*Optimizing compilers attempt to perform code motion. Unfortunately, as discussed*

*previously, they are typically very cautious about making transformations*

*that change where or how many times a procedure is called. They cannot reliably*

*detect whether or not a function will have side effects, and so they assume that*

*it might. For example, if* *vec_length* *had some side effect, then* *combine1* *and*

*combine2* *could have different behaviors. To improve the code, the programmer*

*must often help the compiler by explicitly performing code motion.*

*As an extreme example of the loop inefficiency seen in* *combine1**, consider the*

*procedure* *lower1* *shown in Figure 5.7. This procedure is styled after routines submitted*

*by several students as part of a network programming project. Its purpose*

*is to convert all of the uppercase letters in a string to lowercase. The procedure*

*steps through the string, converting each uppercase character to lowercase. The*

*case conversion involves shifting characters in the range ‘**A**’ to ‘**Z**’ to the range ‘**a**’*

*to ‘**z**’.*

*The library function* *strlen* *is called as part of the loop test of* *lower1**. Although*

*strlen* *is typically implemented with special x86 string-processing instructions,*

*its overall execution is similar to the simple version that is also shown in*

*Figure 5.7. Since strings in C are null-terminated character sequences,* *strlen* *can*

*only determine the length of a string by stepping through the sequence until it*

*hits a null character. For a string of length* *n**,* *strlen* *takes time proportional to* *n**.*

*Since* *strlen* *is called in each of the* *n* *iterations of* *lower1**, the overall run time*

*of* *lower1* *is quadratic in the string length, proportional to* *n**2**.*

```c
/* Convert string to lowercase: slow */
void lower1(char *s) {
    long i;

    for (i = 0; i < strlen(s); i++)
        if (s[i] >= ’A’ && s[i] <= ’Z’)
    s[i] -= (’A’ - ’a’);
}

/* Convert string to lowercase: faster */
void lower2(char *s) {
    long i;
    long len = strlen(s);

    for (i = 0; i < len; i++)
        if (s[i] >= ’A’ && s[i] <= ’Z’)
    s[i] -= (’A’ - ’a’);
}

/* Sample implementation of library function strlen */
/* Compute length of string */
size_t strlen(const char *s) {
    long length = 0;
    while (*s != ’\0’) {
        s++;
        length++;
    }
    return length;
}

```

