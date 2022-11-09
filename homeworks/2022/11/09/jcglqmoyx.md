 Profiling with gprof requires three steps, as shown for a C program   prog.c  , which runs with command-line argument   file.txt  : 

1. The program must be compiled and linked for profiling.With gcc (and other C compilers), this involves simply including the run-time flag   -pg   on the command line. It is important to ensure that the compiler does not attempt to perform any optimizations via inline substitution, or else the calls to functions may not be tabulated accurately. We use optimization flag   -Og  , guaranteeing that function calls will be tracked properly. 

 ```
 linux> gcc -Og -pg prog.c -o prog 
 ```

 2. The program is then executed as usual: 

 ```
 linux> ./prog file.txt 
 ```

 It runs slightly (around a factor of 2) slower than normal, but otherwise the only difference is that it generates a file   gmon.out  . 

 3. gprof is invoked to analyze the data in   gmon.out  : 

 ```
 linux> gprof prog 
 ```
