# Chapter.7 链接

- 1. 理解连接器将帮助你构造大型程序
- 2. 理解连接器将帮助你避免一些危险的编译错误
- 3. 理解链接将帮助你理解语言的作用域规则是如何实现的
- 4. 理解链接将帮助你理解其他重要的系统概念
- 5. 理解链接将使你能够利用共享库

--------------

## 从应用程序中加载和链接共享库

> 一个动态加载`libvector.so`(Linux)

```cpp
#include <stdio.h>
#include <dlfcn.h>

int x[2] = {1,2};
int y[2] = {3,4};
int z[2];

int main(){
    void *handle;
    void (*addvec)(int*,int*,int*,int);
    char *error;

    /*动态加载包含addvec()函数的共享库*/
    handle = dlopen("./libvector.so",RTLD_LAZY);
    if(!handle){
        fprintf(stderr,"%s\n",dlerror());
        exit(1);
    }

    /*获得addvec()函数的函数指针*/
    addvec = dlsym(handle,"addvec");
    if((error = dlerror()) != NULL){
        fprintf(stderr,"%s\n",error);
        exit(1);
    }

    /*调用addvec*/
    addvec(x,y,z,2);
    printf("Z = [%d %d]\n",z[0],z[1]);

    /*卸载函数*/
    if(dlclose(handle)<0){
        fprintf(stderr,"%s\n",dlerror());
        exit(1);
    }

    return 0;
}

```

> 共享库和Java本地接口

Java定义了一个标准调用接口,叫做Java本地接口,(JNI),它允许Java调用本地的C/C++函数,JNI思想是将本地C函数,编译到共享库中,比如`foo.so`,当一个正在运行的Jvaa程序试图调用函数foo时,Java解释程序利用`dlopen`接口动态加载和卸载这个共享库.

## 位置无关码(PIC)

为了避免多个进程共享一个程序造成的各种问题,现代操作系统使他们可以加载到内存的任何位置而无需连接修改,使用这种方法可以使无限个进程共享一个共享模块的代码的单一副本  
但是,不同进程共享同一块代码的时候,每个进程仍然会维护自己的读写数据快

## 库打桩机制

> 用于实现共享库可调式的机制

## 常见的处理目标文件的工具

- AR: 创建静态库,插入、删除、列出和提取成员
- STRINGS: 列出一个目标文件所有的可打印字符串
- STRIP: 从目标文件中删除符号信息
- NM: 列出一个目标文件中符号表定义的符号
- SIZE: 列出目标文件中节的名字和大小
- READELF: 显示一个目标文件完整结构,包括ELF头中编码的所有信息,包含SIZE和NM的功能
- OBJDUMP: 所有二进制工具之母,最大作用是反汇编.text节中的二进制指令
- LDD: 列出一个可执行文件在运行时所需要的共享库。

相关实践:  

（1）readelf分析。（https://blog.csdn.net/zl6481033/article/details/85317790）

（2）静态链接。    （https://blog.csdn.net/zl6481033/article/details/85340096）

（3）动态链接。    （https://blog.csdn.net/zl6481033/article/details/85699083）




--------------


> Latex转Svg

https://www.latexlive.com/