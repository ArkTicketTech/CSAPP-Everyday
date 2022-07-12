# Local Storage on the Stack

Most of the procedure examples we have seen so far did not require any local storage beyond what could be held in registers. At times, however, local data must be stored in memory. Common cases of this include these:

* There are not enough registers to hold all of the local data
* The address operator ‘&’ is applied to a local variable, and hence we must be

able to generate an address for it.

* Some of the local variables are arrays or structures and hence must be accessed by array or structure references. We will discuss this possibility when we describe how arrays and structures are allocated.