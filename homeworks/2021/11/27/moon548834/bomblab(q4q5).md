## bomblab q4q5

完成了前5个小任务，还差最后一个明天解决qaq:

```
fanzhipeng@LAPTOP-ILT6KOAH:~/work/cmu15213/bomblab$ ./bomb input.txt
Welcome to my fiendish little bomb. You have 6 phases with
which to blow yourself up. Have a nice day!
Phase 1 defused. How about the next one?
That's number 2.  Keep going!
Halfway there!
So you got that one.  Try this one.
Good work!  On to the next...
```

### q4

```
0000000000400fce <func4>: // 要求返回值必须等于0  edx = 14 esi = 0 edi = $1 // 一个直接的做法是不执行任何递归，这样一定会到400ff2返回值是0
 422   400fce:   48 83 ec 08             sub    $0x8,%rsp
 423   400fd2:   89 d0                   mov    %edx,%eax  //rax = 14;
 424   400fd4:   29 f0                   sub    %esi,%eax  //rax = 14;
 425   400fd6:   89 c1                   mov    %eax,%ecx
 426   400fd8:   c1 e9 1f                shr    $0x1f,%ecx
 427   400fdb:   01 c8                   add    %ecx,%eax  //rcx = 0
 428   400fdd:   d1 f8                   sar    %eax      // rax = rax >> 1
 429   400fdf:   8d 0c 30                lea    (%rax,%rsi,1),%ecx // ecx = 7
 430   400fe2:   39 f9                   cmp    %edi,%ecx
 431   400fe4:   7e 0c                   jle    400ff2 <func4+0x24> // if $1 < 7
 432   400fe6:   8d 51 ff                lea    -0x1(%rcx),%edx // edx = 6
 433   400fe9:   e8 e0 ff ff ff          callq  400fce <func4> // 递归过程
 434   400fee:   01 c0                   add    %eax,%eax // s
 435   400ff0:   eb 15                   jmp    401007 <func4+0x39>
 436   400ff2:   b8 00 00 00 00          mov    $0x0,%eax
 437   400ff7:   39 f9                   cmp    %edi,%ecx
 438   400ff9:   7d 0c                   jge    401007 <func4+0x39>
 439   400ffb:   8d 71 01                lea    0x1(%rcx),%esi
 440   400ffe:   e8 cb ff ff ff          callq  400fce <func4> // 递归调用后eax是某个值
 441   401003:   8d 44 00 01             lea    0x1(%rax,%rax,1),%eax
 442   401007:   48 83 c4 08             add    $0x8,%rsp
 443   40100b:   c3                      retq
 444
 445 000000000040100c <phase_4>:
 446   40100c:   48 83 ec 18             sub    $0x18,%rsp
 447   401010:   48 8d 4c 24 0c          lea    0xc(%rsp),%rcx
 448   401015:   48 8d 54 24 08          lea    0x8(%rsp),%rdx
 449   40101a:   be cf 25 40 00          mov    $0x4025cf,%esi  // %d %d
 450   40101f:   b8 00 00 00 00          mov    $0x0,%eax
 451   401024:   e8 c7 fb ff ff          callq  400bf0 <__isoc99_sscanf@plt> // 读到 0xc(%rsp) 0x8(%rsp)
 452   401029:   83 f8 02                cmp    $0x2,%eax
 453   40102c:   75 07                   jne    401035 <phase_4+0x29>
 454   40102e:   83 7c 24 08 0e          cmpl   $0xe,0x8(%rsp) // $1 <= 14
 455   401033:   76 05                   jbe    40103a <phase_4+0x2e>
 456   401035:   e8 00 04 00 00          callq  40143a <explode_bomb>
 457   40103a:   ba 0e 00 00 00          mov    $0xe,%edx
 458   40103f:   be 00 00 00 00          mov    $0x0,%esi
 459   401044:   8b 7c 24 08             mov    0x8(%rsp),%edi
 460   401048:   e8 81 ff ff ff          callq  400fce <func4> // 调用这个函数之后 0xc(%rsp) == 0 而func4 无修改 故$2 = 0
 461   40104d:   85 c0                   test   %eax,%eax // eax 必须等于0
 462   40104f:   75 07                   jne    401058 <phase_4+0x4c>
 463   401051:   83 7c 24 0c 00          cmpl   $0x0,0xc(%rsp)
......
```

### q5

```
0000000000401062 <phase_5>:
 470   401062:   53                      push   %rbx
 471   401063:   48 83 ec 20             sub    $0x20,%rsp
 472   401067:   48 89 fb                mov    %rdi,%rbx
 473   40106a:   64 48 8b 04 25 28 00    mov    %fs:0x28,%rax // rax 是个很怪的数: 0xa82181df124aef00
 474   401071:   00 00
 475   401073:   48 89 44 24 18          mov    %rax,0x18(%rsp)
 476   401078:   31 c0                   xor    %eax,%eax
 477   40107a:   e8 9c 02 00 00          callq  40131b <string_length>
 478   40107f:   83 f8 06                cmp    $0x6,%eax                // 字符串长度必须是6
 479   401082:   74 4e                   je     4010d2 <phase_5+0x70>
 480   401084:   e8 b1 03 00 00          callq  40143a <explode_bomb>
 481   401089:   eb 47                   jmp    4010d2 <phase_5+0x70>
 482   40108b:   0f b6 0c 03             movzbl (%rbx,%rax,1),%ecx      // 访问字符串s[rax]元素
 483   40108f:   88 0c 24                mov    %cl,(%rsp)
 484   401092:   48 8b 14 24             mov    (%rsp),%rdx
 485   401096:   83 e2 0f                and    $0xf,%edx              // 取s[rax]的末四位
 486   401099:   0f b6 92 b0 24 40 00    movzbl 0x4024b0(%rdx),%edx   // edx = s2[(s[rax] & 0xf)] // x/s 0x4024b0: maduiersnfotvbyl
 487                                                                                                       映射   abcdefghijklmnop(错一位)
 488   4010a0:   88 54 04 10             mov    %dl,0x10(%rsp,%rax,1)
 489   4010a4:   48 83 c0 01             add    $0x1,%rax
 490   4010a8:   48 83 f8 06             cmp    $0x6,%rax
 491   4010ac:   75 dd                   jne    40108b <phase_5+0x29>
 492   4010ae:   c6 44 24 16 00          movb   $0x0,0x16(%rsp)       // rsp(0x10 - 0x16)
 493   4010b3:   be 5e 24 40 00          mov    $0x40245e,%esi        // 需要被匹配的字符串是 x/s 0x40245e "flyers" 那么我们从0x4024b0找到这几个字符映射位置就行了
 494   4010b8:   48 8d 7c 24 10          lea    0x10(%rsp),%rdi
 495   4010bd:   e8 76 02 00 00          callq  401338 <strings_not_equal>
......
```
