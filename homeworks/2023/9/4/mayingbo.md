1.传输过程流数据 --→ xdr_stream(内存分布)



首先为了满足RPCxxx的要求，流数据内容均32位对齐，也就是每个数据至少都是4字节，也就是4B→  下文未强调的内容结果均为usigned int .
*p在内存上是连续分布的，每次按4个字节移动。
*p中前4为分别是，Xid（RPC响应标识符），Ver（RDMA协议版本号），Max_req（最大的请求数目），Msg（是否携带消息的格式）---->只有不携带数据的时候这里是NO_MSG，也就是tail，pages均为空时，才是NO_MSG.
Read_List
如果Read_List个数为0：则直接进入Wirte_List
如果不为0，在这里假设个数为cnt，则接下来的共有n*4*4个字节（实际上每个Read_List由4个 usigned int来描述）
分别为Position（4）--->在xdr_buf中的偏移量，也就是xdr_buf->head->iov_len的长度，Handle（4），Length（4），Offset（8个字节）
Write_List
如果Write_List个数为0：则直接进入Reply_Chunk
如果不为0，在这里假设个数为cnt，则接下来会有cnt个Write_chunk，
write_chunk又包括num个segment（4个字节），每个RDMA_segment包含Handle（4），Length（4），Offset（8） 
Reply_chunk-→ RFC8166 指定为只有write_chunk
如果Reply_Chunk个数为0：则结束
如果不为0，则查看wirte_chunk个数，存在的话打印内容与上相同

+-----------------+
|      xid        |  4 bytes
+-----------------+
|   messageType   |  4 bytes
+-----------------+
|   rpcVersion    |  4 bytes
+-----------------+
|     program     |  4 bytes
+-----------------+
| programVersion  |  4 bytes
+-----------------+
|    procedure    |  4 bytes
+-----------------+
|   credentials   |  variable length
+-----------------+
|    verifier     |  variable length
+-----------------+
       
  kworker/u16:30-579   [007] ....    47.106879: rpcrdma_marshal_req: | 0xffff88810c1e0800 | 8f 0a 71 c7     | xid:0x8f0a71c7                                                   |
  kworker/u16:30-579   [007] ....    47.106882: rpcrdma_marshal_req: | 0xffff88810c1e0804 | 00 00 00 00     | messagetype:0(CALL调用请求) 1（Reply回复消息）                     |
  kworker/u16:30-579   [007] ....    47.106885: rpcrdma_marshal_req: | 0xffff88810c1e0808 | 00 00 00 02     | RPC版本:2                                                         | 
  kworker/u16:30-579   [007] ....    47.106887: rpcrdma_marshal_req: | 0xffff88810c1e080c | 00 01 86 a3     | Program:NFS(10003)                                               |
  kworker/u16:30-579   [007] ....    47.106890: rpcrdma_marshal_req: | 0xffff88810c1e0810 | 00 00 00 03     | NFS版本:3                                                        |
  kworker/u16:30-579   [007] ....    47.106892: rpcrdma_marshal_req: | 0xffff88810c1e0814 | 00 00 00 06     | NFS程序号：6 （Read） 每一个OP都对应一个程序号                      |
  kworker/u16:30-579   [007] ....    47.106895: rpcrdma_marshal_req: | 0xffff88810c1e0818 | 00 00 00 01     | Credentials--->Flavor: AUTH_UNIX(1)                              |
  kworker/u16:30-579   [007] ....    47.106898: rpcrdma_marshal_req: | 0xffff88810c1e081c | 00 00 00 30     |           ---->Length: 48(接下来需要读取的长度)                    |
  kworker/u16:30-579   [007] ....    47.106900: rpcrdma_marshal_req: | 0xffff88810c1e0820 | 00 00 00 00     |           ---->Stamp : 0x00000000                    
  kworker/u16:30-579   [007] ....    47.106903: rpcrdma_marshal_req: | 0xffff88810c1e0824 | 00 00 00 15     |           ---->Machine_name： --->length:21 需要读取的长度        |
  kworker/u16:30-579   [007] ....    47.106905: rpcrdma_marshal_req: | 0xffff88810c1e0828 | 6c 6f 63 61     |                                 contents: localhost.localdomain  |
  kworker/u16:30-579   [007] ....    47.106908: rpcrdma_marshal_req: | 0xffff88810c1e082c | 6c 68 6f 73     |                                                                  |
  kworker/u16:30-579   [007] ....    47.106911: rpcrdma_marshal_req: | 0xffff88810c1e0830 | 74 2e 6c 6f     |                                                                  |
  kworker/u16:30-579   [007] ....    47.106914: rpcrdma_marshal_req: | 0xffff88810c1e0834 | 63 61 6c 64     |                                                                  |
  kworker/u16:30-579   [007] ....    47.106916: rpcrdma_marshal_req: | 0xffff88810c1e0838 | 6f 6d 61 69     |                                                                  |
  kworker/u16:30-579   [007] ....    47.106919: rpcrdma_marshal_req: | 0xffff88810c1e083c | 6e 00 00 00     | -->实际名字到6e就结束了，后面三个00为对齐的补充字节（filedata）    |
  kworker/u16:30-579   [007] ....    47.106922: rpcrdma_marshal_req: | 0xffff88810c1e0840 | 00 00 00 00     |         ------>UID:0                                             |                       
  kworker/u16:30-579   [007] ....    47.106924: rpcrdma_marshal_req: | 0xffff88810c1e0844 | 00 00 00 00     |         ------>GID:0                                             |
  kworker/u16:30-579   [007] ....    47.106927: rpcrdma_marshal_req: | 0xffff88810c1e0848 | 00 00 00 01     |         ------>Auxiliary GIDs(辅助组不理解) ： 1-->应该是个数    |
  kworker/u16:30-579   [007] ....    47.106929: rpcrdma_marshal_req: | 0xffff88810c1e084c | 00 00 00 00     |                           表示属于GID【0】组也就是root组         |
  kworker/u16:30-579   [007] ....    47.106932: rpcrdma_marshal_req: | 0xffff88810c1e0850 | 00 00 00 00     | Verifier---->Flavor:AUTH_NULL(0)                                 |
  kworker/u16:30-579   [007] ....    47.106934: rpcrdma_marshal_req: | 0xffff88810c1e0854 | 00 00 00 00     |         ---->Length:0                                            |
  kworker/u16:30-579   [007] ....    47.106937: rpcrdma_marshal_req: | 0xffff88810c1e0858 | 00 00 00 28     | file---->length:40                                               |
  kworker/u16:30-579   [007] ....    47.106940: rpcrdma_marshal_req: | 0xffff88810c1e085c | 01 00 07 81     |     ---->Handle:自己拼吧，反正40的长度                           |
  kworker/u16:30-579   [007] ....    47.106942: rpcrdma_marshal_req: | 0xffff88810c1e0860 | 84 00 00 00     |                                                                  |
  kworker/u16:30-579   [007] ....    47.106945: rpcrdma_marshal_req: | 0xffff88810c1e0864 | 00 00 00 00     |                                                                  |
  kworker/u16:30-579   [007] ....    47.106947: rpcrdma_marshal_req: | 0xffff88810c1e0868 | a6 d1 ff e0     |                                                                  |
  kworker/u16:30-579   [007] ....    47.106950: rpcrdma_marshal_req: | 0xffff88810c1e0864 | 4a 18 4a 30     |                                                                  |
  kworker/u16:30-579   [007] ....    47.106953: rpcrdma_marshal_req: | 0xffff88810c1e0870 | 94 bd 9e 20     |                                                                  |
  kworker/u16:30-579   [007] ....    47.106956: rpcrdma_marshal_req: | 0xffff88810c1e0874 | ac cd a2 0a     |                                                                  |
  kworker/u16:30-579   [007] ....    47.106959: rpcrdma_marshal_req: | 0xffff88810c1e0878 | 97 00 00 00     |                                                                  |
  kworker/u16:30-579   [007] ....    47.106962: rpcrdma_marshal_req: | 0xffff88810c1e087c | 00 00 00 00     |                                                                  |
  kworker/u16:30-579   [007] ....    47.106965: rpcrdma_marshal_req: | 0xffff88810c1e0880 | c4 54 11 55     |                                                                  |
  kworker/u16:30-579   [007] ....    47.106968: rpcrdma_marshal_req: | 0xffff88810c1e0884 | 00 00 00 00     |     ---->offset:在文件中的偏移量0   这列读8B                     |
  kworker/u16:30-579   [007] ....    47.106972: rpcrdma_marshal_req: | 0xffff88810c1e0888 | 00 00 00 00     |                                                                  |
  kworker/u16:30-579   [007] ....    47.106976: rpcrdma_marshal_req: | 0xffff88810c1e088c | 00 00 10 00     |     ---->length:共读512B（4096bytes）                            |


_______
NFSv3常用程序号

0	NULL	无操作
1	GETATTR	获取文件属性
2	SETATTR	设置文件属性
3	LOOKUP	查找文件
4	ACCESS	检查文件访问权限
5	READLINK	读取符号链接
6	READ	读取文件内容
7	WRITE	写入文件内容
8	CREATE	创建文件
9	MKDIR	创建目录
10	SYMLINK	创建符号链接
11	MKNOD	创建特殊文件
12	REMOVE	删除文件或目录
13	RMDIR	删除目录
14	RENAME	重命名文件或目录
15	LINK	创建硬链接
16	READDIR	读取目录内容
17	READDIRPLUS	读取目录内容和属性
18	FSSTAT	获取文件系统状态
19	FSINFO	获取文件系统信息
20	PATHCONF	获取路径配置信息
21	COMMIT	提交文件修改
