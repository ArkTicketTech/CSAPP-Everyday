C提供了一种用户级异常控制流形式，非本地跳转。将控制直接从一个函数转移到另一个当前正在执行的函数，而无需经过正常的调用-返回序列。非本地跳转是通过setjmp和longjmp函数来提供的。1允许从一个深层嵌套的函数调用中立即返回，通常是由检测到某个错误情况引起。longjmp允许它跳过所有中间调用的特性可能产生意外的后果。2使一个信号处理程序分支到一个特殊的代码位置，而不是返回到被信号到达中断了的指令的位置。

操作进程的工具：STRACE,PS,TOP,PMAP