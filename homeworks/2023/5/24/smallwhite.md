当前主流的`cpu` 架构

- x86架构：是由Intel和AMD等公司开发的指令集架构，广泛应用于个人电脑和服务器领域。x86架构包括32位和64位版本，如Intel的Core系列和AMD的Ryzen系列。

	1. `example` 

		```bash
		Linux VM-20-12-ubuntu 5.15.0-56-generic #62-Ubuntu SMP Tue Nov 22 19:54:14 UTC 2022 x86_64 x86_64 x86_64 GNU/Linux
		```

	2. 指令集

		x86架构有非常多的指令集可选，

		- 主要使用的指令集是x86指令集，包括16位的x86指令集（如8086和80286），32位的x86指令集（如80386、Pentium和Xeon）
		- 以及64位的x86-64指令集（如Intel的Core系列和AMD的Ryzen系列）



- ARM架构：ARM架构是由ARM Holdings开发的指令集架构，广泛应用于移动设备、嵌入式系统和低功耗领域。ARM架构具有低功耗和高性能的特点，如ARM Cortex系列处理器被广泛应用于智能手机、平板电脑和物联网设备等。

	1. ```bash
		Darwin 192.168.124.22 22.4.0 Darwin Kernel Version 22.4.0: Mon Mar  6 20:59:58 PST 2023; root:xnu-8796.101.5~3/RELEASE_ARM64_T6020 arm64
		```

	2. ARM架构使用的主要指令集是ARM指令集，包括ARMv7和ARMv8。ARMv7是32位指令集，广泛应用于移动设备和嵌入式系统。ARMv8引入了64位指令集（AArch64），提供更高的性能和更大的内存寻址能力。

- POWER架构：POWER架构是由IBM开发的指令集架构，主要应用于大型服务器和超级计算机。POWER架构的特点是高性能、可扩展性和可靠性，如IBM的POWER系列处理器。
	1. POWER架构主要使用的指令集是POWER指令集，包括PowerPC指令集和POWER ISA。PowerPC指令集广泛应用于苹果早期的PowerPC处理器系列。POWER ISA是IBM开发的指令集体系结构，主要应用于IBM的POWER系列处理器

- RISC-V架构：RISC-V架构是一种开源的指令集架构，由加州大学伯克利分校开发。RISC-V架构的设计简洁、灵活，被广泛应用于嵌入式系统和物联网设备等领域。
	1. RISC-V架构：RISC-V架构使用的指令集是RISC-V指令集，这是一种开源的指令集架构。RISC-V指令集设计简洁、灵活，并且支持定制化，因此被广泛应用于嵌入式系统和物联网设备等领域。