常量折叠

将常量表达式计算结果替换常量,减少运行时计算

```jsx
c
int x = 10 * 5; 
int y = x + 10;   // x is constant 50
```

优化后:

```jsx
c
int x = 50;  
int y = x + 10;
```

重复表达式折叠: 检测重复的表达式并只计算一次,复用结果。 例如:

```jsx
c
int a = b * c;
int d = b * c;
```

优化后:

```jsx
c
int tmp = b * c;
int a = tmp;  
int d = tmp;
```

死代码消除: 移除程序中永远不会被执行的代码部分。 例如:

```jsx
c
int x = 10;
if (x > 20) {   // Dead code
    doSomething();
}
```

优化后:

```jsx
c
int x = 10;
```