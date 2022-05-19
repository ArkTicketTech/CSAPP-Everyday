# Condition Codes

In addition to the integer registers, the CPU maintains a set of single-bit condition code registers describing
attributes of the most recent arithmetic or logical operation. These registers can then be tested to perform conditional
branches. These condition codes are the most useful:

* CF: Carry flag. The most recent operation generated a carry out of the most significant bit. Used to detect overflow
  for unsigned operations.
* ZF: Zero flag. The most recent operation yielded zero.
* SF: Sign flag. The most recent operation yielded a negative value.
* OF: Overflow flag. The most recent operation caused a two’s-complement overflow—either negative or positive.