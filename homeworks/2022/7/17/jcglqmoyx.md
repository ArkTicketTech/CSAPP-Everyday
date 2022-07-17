# Practice problem 3.36

Consider the following declarations:

```c
int    P[5];
short  Q[2];
int    **R[9];
double *S[10];
short  *T[2];
```

Fill in the following table describing the element size, the total size, and the address of element i for each of these arrays.

| Array | Element Size | Total Size | Start address | Element i |
| ----- | ------------ | ---------- | ------------- | --------- |
| P     | 4            | 20         | Xp            | Xp + 4i   |
| Q     | 2            | 4          | Xq            | Xq + 2i   |
| R     | 8            | 72         | Xr            | Xr + 8i   |
| S     | 8            | 80         | Xs            | Xs + 8i   |
| T     | 8            | 16         | Xt            | Xt + 8i   |

