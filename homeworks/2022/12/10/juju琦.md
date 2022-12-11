## I/O多路复用-select
    select实现多路复用的方式是， 将已连接的socket都放在一个文件描述符集合， 然后调用select函数将文件描述符拷贝到内核里， 让内核来检查是否有网络事件产生， 检查的方式很粗暴，就是通过遍历文件描述符集合的方式，当检查到有事件产生后，将此socket标记为可读或可写，接着再把整个文件描述符集合拷贝到用户态里，然后用户态还需要在通过遍历的方法找到可读或可写的socket，然后在对其处理。
  select函数应用场景：  当同时有网络请求和cli发起的io后， 需要同时做出响应。  
  实现方式： 1. 从用户态传有关描述符的集合到内核态遍历， 标记好可读或可写后。
                     2.再从内核态传到用户态，遍历寻找自己的socket，进行处理。
出处：E.Bryant Randal,O'Hallaron David《深入理解计算机系统（原书第3版）》(2016) P684
https://xiaolincoding.com/os/8_network_system/selete_poll_epoll.html#select-poll
https://www.cnblogs.com/anker/p/3258674.html
https://www.cnblogs.com/wt645631686/p/8528912.html
