#### 10.7 读取文件目录

使用`readdir`系列函数读取目录内容。

```c
#include <sys/types.h>
#include <dirent.h>

DIR *opendir(const char *name);

// 返回：若成功，则为处理的指针；若出错，则为 NULL。
```

函数 opendir 以路径名为参数，返回指向**目录流**（directory stream）的指针。流是对条目有序列表的抽象，在这里是指目录项的列表。

```c
#include <dirent.h>

struct dirent *readdir(DIR *dirp);

// 返回：若成功，则为指向下一个目录项的指针；
//      若没有更多的目录项或出错，则为 NULL。
```

每次对 readdir 的调用返回的都是指向流 dirp 中下一个目录项的指针，或者，如果没有更多目录项则返回 NULL。每个目录项都是一个结构，其形式如下：

```c
struct dirent {
    ino_t d_ino;      /* inode number */
    char d_name[256]; /* Filename */
};
```

虽然有些 Linux 版本包含了其他的结构成员，但是只有这两个对所有系统来说都是标准的。成员 d_name 是文件名，d_ino 是文件位置。

如果出错，则 readdir 返回 NULL，并设置 errno。可惜的是，唯一能区分错误和流结束情况的方法是检査自调用 readdir 以来 errno 是否被修改过。

```c
#include <dirent.h>

int closedir(DIR *dirp);

// 返回：成功为 0；错误为 -1。
```

函数 closedir 关闭流并释放其所有的资源。图 10-11 展示了怎样用 readdir 来读取目录的内容。

```c
//code/io/readdir.c
#include "csapp.h"

int main(int argc, char **argv)
{
    DIR *streamp;
    struct dirent *dep;

    streamp = Opendir(argv[1]);

    errno = 0;
    while ((dep = readdir(streamp)) != NULL) {
        printf("Found file: %s\n", dep->d_name);
    }
    if (errno != 0)
        unix_error("readdir error");

    Closedir(streamp);
    exit(0);
}
```

