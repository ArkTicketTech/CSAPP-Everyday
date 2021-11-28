## bomblabq6

全部通过了，不容易qaq 好像还有个隐藏关卡，都做完lab有空再看看T_T

```
fanzhipeng@LAPTOP-ILT6KOAH:~/work/cmu15213/bomblab$ ./bomb input.txt
Welcome to my fiendish little bomb. You have 6 phases with
which to blow yourself up. Have a nice day!
Phase 1 defused. How about the next one?
That's number 2.  Keep going!
Halfway there!
So you got that one.  Try this one.
Good work!  On to the next...
Congratulations! You've defused the bomb!
```


```
00000000004010f4 <phase_6>:
 513   4010f4:   41 56                   push   %r14
 514   4010f6:   41 55                   push   %r13
 515   4010f8:   41 54                   push   %r12
 516   4010fa:   55                      push   %rbp
 517   4010fb:   53                      push   %rbx
 518   4010fc:   48 83 ec 50             sub    $0x50,%rsp
 519   401100:   49 89 e5                mov    %rsp,%r13
 520   401103:   48 89 e6                mov    %rsp,%rsi
 521   401106:   e8 51 03 00 00          callq  40145c <read_six_numbers>  // 读6个数 memory[rsp ~ rsp +5]
 522   40110b:   49 89 e6                mov    %rsp,%r14
 523   40110e:   41 bc 00 00 00 00       mov    $0x0,%r12d
 524   401114:   4c 89 ed                mov    %r13,%rbp
 525   401117:   41 8b 45 00             mov    0x0(%r13),%eax
 526   40111b:   83 e8 01                sub    $0x1,%eax
 527   40111e:   83 f8 05                cmp    $0x5,%eax // 第一个数减1 必须小于等于5
 528   401121:   76 05                   jbe    401128 <phase_6+0x34>
 529   401123:   e8 12 03 00 00          callq  40143a <explode_bomb>
 530   401128:   41 83 c4 01             add    $0x1,%r12d
 531   40112c:   41 83 fc 06             cmp    $0x6,%r12d
 532   401130:   74 21                   je     401153 <phase_6+0x5f> // 第六次跳出循环
 533   401132:   44 89 e3                mov    %r12d,%ebx // 内循环
 534   401135:   48 63 c3                movslq %ebx,%rax
 535   401138:   8b 04 84                mov    (%rsp,%rax,4),%eax // 取第rax的数
 536   40113b:   39 45 00                cmp    %eax,0x0(%rbp)
 537   40113e:   75 05                   jne    401145 <phase_6+0x51> //保证和当前数不等
 538   401140:   e8 f5 02 00 00          callq  40143a <explode_bomb>
 539   401145:   83 c3 01                add    $0x1,%ebx // ebx 类似于j++
 540   401148:   83 fb 05                cmp    $0x5,%ebx // j <= 5
 541   40114b:   7e e8                   jle    401135 <phase_6+0x41>
 542   40114d:   49 83 c5 04             add    $0x4,%r13 // a++; 那个存的数组的位置的下标++
 543   401151:   eb c1                   jmp    401114 <phase_6+0x20> // 循环体
 544   401153:   48 8d 74 24 18          lea    0x18(%rsp),%rsi // 上面两个循环的意思应该就是判断6个数字互不相等
 545   401158:   4c 89 f0                mov    %r14,%rax
 546   40115b:   b9 07 00 00 00          mov    $0x7,%ecx
 547   401160:   89 ca                   mov    %ecx,%edx
 548   401162:   2b 10                   sub    (%rax),%edx
 549   401164:   89 10                   mov    %edx,(%rax)
 550   401166:   48 83 c0 04             add    $0x4,%rax
 551   40116a:   48 39 f0                cmp    %rsi,%rax
 552   40116d:   75 f1                   jne    401160 <phase_6+0x6c> //  401158到当前行意思是对每个数x求7 - x
 553   40116f:   be 00 00 00 00          mov    $0x0,%esi
 554   401174:   eb 21                   jmp    401197 <phase_6+0xa3>
 555   401176:   48 8b 52 08             mov    0x8(%rdx),%rdx //链表操作
 556   40117a:   83 c0 01                add    $0x1,%eax
 557   40117d:   39 c8                   cmp    %ecx,%eax
 558   40117f:   75 f5                   jne    401176 <phase_6+0x82>
 559   401181:   eb 05                   jmp    401188 <phase_6+0x94>
 560   401183:   ba d0 32 60 00          mov    $0x6032d0,%edx
 561   401188:   48 89 54 74 20          mov    %rdx,0x20(%rsp,%rsi,2)
 562   40118d:   48 83 c6 04             add    $0x4,%rsi
 563   401191:   48 83 fe 18             cmp    $0x18,%rsi // 如果这6个数操作完了 跳转到4011ab
 564   401195:   74 14                   je     4011ab <phase_6+0xb7>
 565   401197:   8b 0c 34                mov    (%rsp,%rsi,1),%ecx    // ecx = a[rsi]
 566   40119a:   83 f9 01                cmp    $0x1,%ecx
 567   40119d:   7e e4                   jle    401183 <phase_6+0x8f> // <= 1
 568   40119f:   b8 01 00 00 00          mov    $0x1,%eax
 569   4011a4:   ba d0 32 60 00          mov    $0x6032d0,%edx
 570   4011a9:   eb cb                   jmp    401176 <phase_6+0x82>
 571   4011ab:   48 8b 5c 24 20          mov    0x20(%rsp),%rbx // rsp8个字节后，存了6个node指针 按照输入deorder
 572   4011b0:   48 8d 44 24 28          lea    0x28(%rsp),%rax
 573   4011b5:   48 8d 74 24 50          lea    0x50(%rsp),%rsi
 574   4011ba:   48 89 d9                mov    %rbx,%rcx
 575   4011bd:   48 8b 10                mov    (%rax),%rdx
 576   4011c0:   48 89 51 08             mov    %rdx,0x8(%rcx) //
 577   4011c4:   48 83 c0 08             add    $0x8,%rax
 578   4011c8:   48 39 f0                cmp    %rsi,%rax
 579   4011cb:   74 05                   je     4011d2 <phase_6+0xde>
 580   4011cd:   48 89 d1                mov    %rdx,%rcx
 581   4011d0:   eb eb                   jmp    4011bd <phase_6+0xc9n>
 582   4011d2:   48 c7 42 08 00 00 00    movq   $0x0,0x8(%rdx) // 末尾 = nullptr
 583   4011d9:   00
 584   4011da:   bd 05 00 00 00          mov    $0x5,%ebp
 585   4011df:   48 8b 43 08             mov    0x8(%rbx),%rax // next(rax) = node->next;
 586   4011e3:   8b 00                   mov    (%rax),%eax    // eax = 1dd
 587   4011e5:   39 03                   cmp    %eax,(%rbx)   // cmp()
 588   4011e7:   7d 05                   jge    4011ee <phase_6+0xfa> // 必须大于 相当于要把这6个node排序，按照从大到小，输入的就是顺序
 589   4011e9:   e8 4c 02 00 00          callq  40143a <explode_bomb>
 590   4011ee:   48 8b 5b 08             mov    0x8(%rbx),%rbx
 591   4011f2:   83 ed 01                sub    $0x1,%ebp
 592   4011f5:   75 e8                   jne    4011df <phase_6+0xeb>
 593   4011f7:   48 83 c4 50             add    $0x50,%rsp
```