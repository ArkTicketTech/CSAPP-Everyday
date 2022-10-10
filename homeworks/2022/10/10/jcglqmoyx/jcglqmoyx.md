*We introduce the metric cycles per element, abbreviated CPE, to express program*

*performance in a way that can guide us in improving the code. CPE measurements*

*help us understand the loop performance of an iterative program at a*

*detailed level. It is appropriate for programs that perform a repetitive computation,*

*such as processing the pixels in an image or computing the elements in a*

*matrix product.*

*The sequencing of activities by a processor is controlled by a clock providing*

*a regular signal of some frequency, usually expressed in gigahertz (GHz), billions*

*of cycles per second. For example, when product literature characterizes a system*

*as a “4 GHz” processor, it means that the processor clock runs at 4**.**0* *°ø* *10**9* *cycles*

*per second. The time required for each clock cycle is given by the reciprocal of*

*the clock frequency. These typically are expressed in nanoseconds (1 nanosecond*

*is 10**−**9* *seconds) or picoseconds (1 picosecond is 10**−**12* *seconds). For example,*

*the period of a 4 GHz clock can be expressed as either 0.25 nanoseconds or 250*

*picoseconds. From a programmer’s perspective, it is more instructive to express*

*measurements in clock cycles rather than nanoseconds or picoseconds. That way,*

*the measurements express how many instructions are being executed rather than*

*how fast the clock runs.*