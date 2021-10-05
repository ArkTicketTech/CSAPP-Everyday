> ***2021.10.04\***

------

### 2.1.3 Addressing and Byte Ordering

多字节地址的程序对象，需要确认两条规则：

- 对象的地址是什么
  - 对象的地址位所有字节中最小的地址
- 在内存中怎样对字节排序
  - **小端法**（Little endian）——内存中按照从最低有效字节到最高有效字节存储对象
  - 大端法（Big endian）——与小端法相反

![img](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/bc30345d-f53c-4501-a863-91f8a0b31136/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20211005%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20211005T031641Z&X-Amz-Expires=86400&X-Amz-Signature=debec9872637332a8555280db14bf25fe974ab5253ab5404af292a164f98e913&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22)

字节顺序可能出现问题的情况：

- 当通过网络传输时，两端机器规则不同则会造成字节反序
- 当阅读字节序列时，文件中给出的顺序（小端低有效位在左），与平时书写的顺序也会不同
- 当编写则规避正常的类型系统的程序时，直接显示或者处理标准类型中的字节

### 2.1.4 Representing Strings

C字符串是以null字符结尾的字符数组。每个字符都由某种标准编码表示，例如ASCII、Unicode。

在使用ASCII作为字符编码，在任何系统都有同样的结果，与字节顺序或者字大小无关。文本数据在不同平台比二进制数据更有独立行。