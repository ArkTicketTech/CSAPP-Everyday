# Chapter 1 A tour of Computer Systems

## 1.4 Processors Read and Interpret Instructions Stored in Memory

在这一点上（？？？现在？？？走到这一步的意思？？？），我们的 hello.c 源程序 已经被编译系统翻译成存储在磁盘上，叫做 hello 的可执行程序了。要在 Unix 系统上运行这个可执行文件，我们把它的名字打到叫做shell 的应用程序中:

```shell
./hello
```

shell 是打印命令提示符的 命令行解释器，等待你输入一行命令，然后执行命令。如果命令行中的第一个单词不是 shell 内置的命令，shell就会认为它是应该加载并运行的可执行程序文件名。所以我们这种情况下，shell 加载并运行 hello 程序并等待它终止。hello 程序打印它的消息到屏幕上然后终止。之后 shell 打印命令提示符并等待下一行命令输入

