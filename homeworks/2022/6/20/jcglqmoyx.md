Practice problem

Executing a continue statement in C causes the program to jump to the end of the current loop iteration. The stated rule for translating a for loop into a while loop needs some refinement when dealing with continue statements. For example, consider the following code:

```
    /* Example of for loop containing a continue statement */
    /* Sum even numbers between 0 and 9 */
    long sum = 0;
    long i;
    for (i = 0; i < 10; i++) {
        if (i & 1)
            continue;
        sum += i;
    }
```

 A. What would we get if we naively applied our rule for translating the for loop into a while loop? What would be wrong with this code?
 B. How could you replace the continue statement with a goto statement to ensure that the while loop correctly duplicates the behavior of the for loop?

***

Our stated rule for translating a for loop into a while loop is just a bit too simplistic—this is the only aspect that requires special consideration.

A. Applying our translation rule would yield the following code:

```
         /* Naive translation of for loop into while loop */
         /* WARNING: This is buggy code */
         long sum = 0;
         long i = 0;
         while (i < 10) {
             if (i & 1)
                 /* This will cause an infinite loop */
                 continue;
             sum += i;
          	 i++;
         }
```

This code has an infinite loop, since the continue statement would prevent index variable i from being updated.

B. The general solution is to replace the continue statement with a goto statement that skips the rest of the loop body and goes directly to the update portion:

```
         /* Correct translation of for loop into while loop */
         long sum = 0;
         long i = 0;
         while (i < 10) {
             if (i & 1)
                 goto update;
             sum += i;
         update:
         		i++;
         }
```