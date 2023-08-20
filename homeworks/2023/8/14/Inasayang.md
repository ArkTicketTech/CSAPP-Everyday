##### 有符号数和无符号数的转换

-   同样字长的有符号数和无符号数的转换规则
    -   数值可能会改变，但是位模式不变



##### 扩展一个数字的位

-   小数->大数

    -   无符号
        -   零扩展（`zero extension`），添加0即可
    -   有符号
        -   符号扩展（`sign extension`），添加最高有效位的值

    -   ![](https://inasa.dev/image/csapp/02/18.png)

​					`sx`使用符号扩展，添加`oxFFFF`

​					`usx`使用零扩展，添加`0x0000`

Pp. 49-55