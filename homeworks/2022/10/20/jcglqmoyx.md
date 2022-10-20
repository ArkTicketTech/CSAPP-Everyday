different functional units are designed to perform different operations. Those labeled as performing “arithmetic operations” are typically specialized to perform different combinations of integer and floatingpoint operations. As the number of transistors that can be integrated onto a single microprocessor chip has grown over time, successive models of microprocessors have increased the total number of functional units, the combinations of operations each unit can perform, and the performance of each of these units. The arithmetic units are intentionally designed to be able to perform a variety of different operations, since the required operations vary widely across different programs.  For example, some programs might involve many integer operations, while others require many floating-point operations. If one functional unit were specialized to perform integer operations while another could only perform floating-point operations, then none of these programs would get the full benefit of having multiple functional units.  For example, our Intel Core i7 Haswell reference machine has eight functional units, numbered 0–7. Here is a partial list of each one’s capabilities:

* 0. Integer arithmetic, floating-point multiplication, integer and floating-point division, branches

* 1. Integer arithmetic, floating-point addition, integer multiplication, floatingpoint
multiplication
* 2. Load, address computation
* 3. Load, address computation
* 4. Store
* 5. Integer arithmetic
* 6. Integer arithmetic, branches
* 7. Store address computation
