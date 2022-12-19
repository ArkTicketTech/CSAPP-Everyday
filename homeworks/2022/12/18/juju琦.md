##  select实现
   
select(int maxfd, fd_set *readfds, fd_set* writefds,  fd_set *exceptfds, struct timeval \**timeout);

fd_set:声明的是一个集合，有点像int, 又有点像struct。
maxfds：是一个整数值，是指集合中所有文件描述符的范围，既所有文件描述符的最大值加1
readfs:是一个容器，里面可以容纳多个文件描述符，把需要监视的描述符放入这个集合中， 当有文件描述符可读时， select 就会返回一个大于0的值，表示 有文件可读。
writefds: 和readfs类似，表示有一个可写的文件描述符集合，当有文件可写时，select就会返回一个大于0的值，表示有文件可写。
出处：https://zhuanlan.zhihu.com/p/57518857
