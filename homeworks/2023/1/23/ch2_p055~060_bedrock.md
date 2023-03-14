【具体数学需要推导】
拓展

**无符号数** $\to$ 更大类型，零拓展（在表示的开头添加0）

**补码** $\to$ 更大类型，符号拓展（表示中添加最高有效位的值，若字长为16，即为f）

截断

无符号数，截断为$k$位，即$mod 2^{k}$的结果

补码，截断为$k$位，即$mod 2^{k}$后再把结果转换为补码