 Some properties of gprof are worth noting :

* The calling information is quite reliable, assuming no inline substitutions have been performed. The compiled program maintains a counter for each combination of caller and callee. The appropriate counter is incremented 
 every time a procedure is called. 
* By default, the timings for library functions are not shown. Instead, these times are incorporated into the times for the calling functions. 
