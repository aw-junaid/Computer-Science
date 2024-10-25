Bitwise operators in Python are used to manipulate individual bits of integers. These operators perform operations on the binary representation of the numbers. Here are the bitwise operators available in Python:

1. **Bitwise AND (`&`):**
   Performs a bitwise AND operation between corresponding bits of two numbers.

   ```python
   result = 5 & 3  # Binary: 0101 & 0011 = 0001 (Decimal: 1)
   ```

2. **Bitwise OR (`|`):**
   Performs a bitwise OR operation between corresponding bits of two numbers.

   ```python
   result = 5 | 3  # Binary: 0101 | 0011 = 0111 (Decimal: 7)
   ```

3. **Bitwise XOR (`^`):**
   Performs a bitwise XOR (exclusive OR) operation between corresponding bits of two numbers.

   ```python
   result = 5 ^ 3  # Binary: 0101 ^ 0011 = 0110 (Decimal: 6)
   ```

4. **Bitwise NOT (`~`):**
   Flips the bits of a number, changing 0s to 1s and vice versa. Note that the result is platform-dependent due to the representation of negative integers.

   ```python
   result = ~5  # Binary: ~0101 = 1010 (Decimal: -6)
   ```

5. **Left Shift (`<<`):**
   Shifts the bits of a number to the left by a specified number of positions. The leftmost bits are filled with zeros.

   ```python
   result = 5 << 2  # Binary: 0101 << 2 = 10100 (Decimal: 20)
   ```

6. **Right Shift (`>>`):**
   Shifts the bits of a number to the right by a specified number of positions. The rightmost bits are filled with zeros.

   ```python
   result = 5 >> 1  # Binary: 0101 >> 1 = 0010 (Decimal: 2)
   ```

These operators are useful when working with low-level programming, optimizing code, or performing bit manipulation tasks. Bitwise operators can be used to perform efficient operations at the binary level.
