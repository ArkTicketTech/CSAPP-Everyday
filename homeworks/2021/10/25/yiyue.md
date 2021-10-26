The bit representation of a floating-point number is divided into three fields to encode these values
 - the single sign bit `s` directly encodes the sign $s$
 - k-bit exponent field `exp` = $e_{k-1}...e_{1}e_{0}$ encodes the exponent E
 - n-bit fraction field `frac` = $f_{n-1}...f_{1}f_{0}$ encodes the significand M but the value encoded also depends on whether or not the exponent field equals 0