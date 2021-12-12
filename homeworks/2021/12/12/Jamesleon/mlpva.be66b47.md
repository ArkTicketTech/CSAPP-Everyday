# Machine Level Programming V Advanced

## X86-64 Linux Memory Layout

- Stack
    - Runtime Stack (8MB limit)
    - E. g.local variables
- Heap
    - Dynamically allocated as needed
    - When call malloc(), calloc(), new()
- Data
    - statically allocated data
    - E.g. global vars , static vars, string constants
    
- Text /Shared Libraries
    - Executable machine instructions
    - Read-only
    
    ```
    00007FFFFFFFFFF┌──────────────────────────┐
                   │                          │
                   │          Stack           │
                   │                          │
                   ├────────────┬─────────────┤ 8MB
                   │            │             │
                   │            │             │
                   │            ▼             │
                   │                          │
                   ├──────────────────────────┤
                   │                          │
                   │                          │
                   │                          │
                   │                          │
                   │                          │
                   │                          │
                   │                          │
                   │                          │
                   │                          │
                   ├──────────────────────────┤
                   │                          │
                   │    Shared Libraries      │
                   │                          │
                   ├──────────────────────────┤
                   │                          │
                   │             ▲            │
                   │             │            │
                   │             │            │
                   │             │            │
                   │             │            │
                   ├─────────────┴────────────┤
                   │                          │
                   │           Heap           │
                   │                          │
                   ├──────────────────────────┤
                   │                          │
                   │           Data           │
                   │                          │
                   ├──────────────────────────┤
                   │                          │
                   │           Text           │
                   │                          │
                   ├──────────────────────────┤
                   │                          │
                   └──────────────────────────┘
    ```
    
    ## 栈溢出
    
    ```c
    void echo(){
      char buf[4];
      gets(buf);
      puts(buf);
    }
    
    void call_echo(){
      echo();
    }
    
    void main(){
      call_echo();
    }
    ```
    
    ```bash
    [root@VM-218-35-centos /home/lorrainema/cc/buffer]# ./echo_nsp
    123456789012345678901234
    123456789012345678901234
    [root@VM-218-35-centos /home/lorrainema/cc/buffer]# ./echo_nsp
    1234567890123456789012345 # 输出超过24个字符就报栈溢出错误
    1234567890123456789012345
    Segmentation fault
    [root@VM-218-35-centos /home/lorrainema/cc/buffer]#
    [root@VM-218-35-centos /home/lorrainema/cc/buffer]# gdb ./echo_nsp
    GNU gdb (GDB) Red Hat Enterprise Linux 7.6.1-80.el7
    Copyright (C) 2013 Free Software Foundation, Inc.
    License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
    This is free software: you are free to change and redistribute it.
    There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
    and "show warranty" for details.
    This GDB was configured as "x86_64-redhat-linux-gnu".
    For bug reporting instructions, please see:
    <http://www.gnu.org/software/gdb/bugs/>...
    Reading symbols from /home/lorrainema/cc/buffer/echo_nsp...(no debugging symbols found)...done.
    (gdb) dis
    disable      disassemble  disconnect   display
    (gdb) disassemble  /m echo
    Dump of assembler code for function echo:
       0x000000000040057d <+0>:	sub    $0x18,%rsp  # 分配24字节大小的栈空间， 所以输入超过24个字符，就会栈溢出
       0x0000000000400581 <+4>:	mov    %rsp,%rdi
       0x0000000000400584 <+7>:	mov    $0x0,%eax
       0x0000000000400589 <+12>:	callq  0x400480 <gets@plt>
       0x000000000040058e <+17>:	mov    %rsp,%rdi
       0x0000000000400591 <+20>:	callq  0x400450 <puts@plt>
       0x0000000000400596 <+25>:	add    $0x18,%rsp
       0x000000000040059a <+29>:	retq
    End of assembler dump.
    ```