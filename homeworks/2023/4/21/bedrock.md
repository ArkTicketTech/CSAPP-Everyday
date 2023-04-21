对于 select 子句中的每个字段，都会创建一个 Item_field 类（或子类）的实例。

后面的内容中，Item_field 类以及其子类的实例都会直接说成 Item_field 类实例。

select子句中，字段可能有 2 种类型，一种是星号（*），一种是普通字段，星号会用 Item_asterisk 类实例化，而 Item_asterisk 类是 Item_field 类的子类。普通字段就直接用 Item_field 类实例化。

词法分析 & 语法分析阶段，各字段只是完成了 Item_field 类的实例化，但是还没有对应到表中真实的字段。此时，Item_field 类实例就像刚刚成形的小蝌蚪，还没有找到妈妈。它的妈妈是 Field 类（或子类）的实例。要等到查询准备阶段，Item_field 类实例才会去找妈妈，找到妈妈之后，Item_field 类实例中的 field 属性会指向找到的 Field 类（或子类）实例，从此以后，小蝌蚪和妈妈就过上了幸福快乐的生活。

