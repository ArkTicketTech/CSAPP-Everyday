# Procedure

Stack Structure

![Untitled](Procedure%20fe5eadf7f1534dcfae8a229b97b51433/Untitled.png)

1. %rsp  store the top of stack 
2.  when the stack grow,  the adress  decrease
3. the address of the Bottom of stack  is greater than the top

Pushq src 

1.  fetch the src  data 
2.  descrease the %rsp (%rsp -8 )
3. store the data to the address (%rsp)

Popq  Dest

1. Dest must be a register
2. fetch the data from %rsp 
3. add %rsp
4. store the data to Dest