信号量：

是一个全局的非负整数。

有两种操作P，V

P(s):如果s非零 那么把s减一并且返回 如果s是0 那么就挂起该线程直到s非零 一般由另一个线程的V操作来使得s加一从而重启上一个被挂起的线程

V(s):V操作把s加一 如果有任何线程阻塞在P操作中 就重启**这些线程中的一个** 然后该线程把s减一 完成它的P操作

**重点：**  **当有多个线程在等待同一个信号量的时候，你不能预测V操作将会重启哪一个线程。**
