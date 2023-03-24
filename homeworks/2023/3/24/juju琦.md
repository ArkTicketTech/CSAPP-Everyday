## 一个进程同时多次打开同一个文件

一个文件 调用open函数两次。   因为产生2个描述符， 在文件表中有2个位置， 共享v-node表。
![image](https://user-images.githubusercontent.com/18367460/227407626-3a20961a-4c43-4c77-b21c-3766410437da.png)
