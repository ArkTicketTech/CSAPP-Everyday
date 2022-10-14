### Aside: RISC and CISC instruction sets
CISC出现的更早。微处理器出现在70s,随着处理器技术的发展，到80s的时候，指令集已经很庞大了。x86沿着这条路径发展出了IA32和x86-64。
RISC在80s由IBM率先提出，之后由 Professors David Patterson, of the University of California at Berkeley, and John Hennessy, of Stanford University 两位发扬光大。

80s, RISC 和 CISC 产生了巨大的争论。 
RISC 阵营认为，通过流水线的指令集设计、处理器实现和高级的编译器技术，RISC可以获得更强大的运算能力。
CISC 阵营认为，同一个任务采用更少的指令执行显然会带来更强的性能。

当时大部分公司采用CISC，ARM采用RISC。

90s，争论小了很多。RISC也引入了更多的指令，但是仍然保留了对流水线的支持。CISC则也引入了对流水线的支持。
市场因素也是影响指令集之争的重要因素。x86一直保留着向前兼容性，在笔记本，个人电脑和服务器上取得了巨大的份额。而对于嵌入式设备、移动设备的场景下，节省资源相比于兼容性要更重要，因此RISC获得了更大的份额。




