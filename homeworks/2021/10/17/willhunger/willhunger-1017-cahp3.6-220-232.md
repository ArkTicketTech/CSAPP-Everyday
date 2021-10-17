# Ch3 Machine-Level Representation of Programs

## 3.6 Control

**循环** 

C 中的 do-while、while 和 for 三种循环结构，在汇编中使用条件测试和跳转组合来实现循环。

* do - while 循环：循环体的最后加上一个条件跳转；

* while 循环：
    * jump to middle 方法，先执行一个无条件跳转到循环结尾处，进行测试，然后根据测试结果跳转或结束。
    * guarded-do 方法，先进行条件分支，条件不成立则跳过循环，将代码变成 do-while 形式。(-O1 以上的优化使用这种形式)。
* for 循环：和 while 的两种方法一样。