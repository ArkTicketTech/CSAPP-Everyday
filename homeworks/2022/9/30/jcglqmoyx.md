 With x86-64, the XMM registers are used for passing floating-point arguments to 

 functions and for returning floating-point values from them.

 * Up to eight floating-point arguments can be passed inXMMregisters %xmm0–%xmm7. These registers are used in the order the arguments are listed. Additional floating-point arguments can be passed on the stack. 

 * A function that returns a floating-point value does so in register %xmm0.

 * All XMM registers are caller saved. The callee may overwrite any of these registers without first saving it. 
