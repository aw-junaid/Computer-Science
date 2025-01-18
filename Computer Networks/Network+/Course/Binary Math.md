### **Binary Math**

Binary math refers to performing arithmetic operations on numbers in the **binary numeral system**, which is the base-2 system. In binary, each digit (bit) represents a power of 2, and only two digits are used: **0** and **1**. Binary math is fundamental to how computers process data because all computer systems and digital electronics rely on binary operations.

### **Binary Number System Recap**

- **Base-2 System**: In binary, each digit represents a power of 2, where:
  - The rightmost bit (least significant bit) represents $\( 2^0 \)$.
  - The next bit to the left represents $\( 2^1 \)$, and so on.

Example: The binary number **1101** represents:

$\[
1 \times 2^3 + 1 \times 2^2 + 0 \times 2^1 + 1 \times 2^0 = 8 + 4 + 0 + 1 = 13 \text{ (in decimal)}
\]$

### **Basic Binary Arithmetic Operations**

1. **Addition**
2. **Subtraction**
3. **Multiplication**
4. **Division**

Let's look at each of these operations in detail.

---

### **1. Binary Addition**

Binary addition follows the same rules as decimal addition, with the key difference that the only possible digits are **0** and **1**.

#### **Rules for Binary Addition:**
- \( 0 + 0 = 0 \)
- \( 0 + 1 = 1 \)
- \( 1 + 0 = 1 \)
- \( 1 + 1 = 10 \) (this is a carry-over)

#### **Example:**

Adding two binary numbers:
```
  1011
+ 1101
-------
```

Step-by-step:
1. \( 1 + 1 = 10 \) (write 0, carry 1)
2. \( 1 + 0 + 1 (carry) = 10 \) (write 0, carry 1)
3. \( 0 + 1 + 1 (carry) = 10 \) (write 0, carry 1)
4. \( 1 + 1 + 1 (carry) = 11 \) (write 1, carry 1)

Final result:
```
  1011
+ 1101
-------
  11000
```
**Result**: $\( 1011_2 + 1101_2 = 11000_2 \)$ (which is 24 in decimal).

---

### **2. Binary Subtraction**

Binary subtraction is similar to decimal subtraction but also includes borrowing.

#### **Rules for Binary Subtraction:**
- \( 0 - 0 = 0 \)
- \( 1 - 0 = 1 \)
- \( 1 - 1 = 0 \)
- \( 0 - 1 \) requires borrowing: you borrow 1 from the next higher bit, turning it into \( 10_2 \) (which is 2 in decimal).

#### **Example:**

Subtracting two binary numbers:
```
  1101
-  101
-------
```

Step-by-step:
1. Start from the rightmost bit: $\( 1 - 1 = 0 \)$
2. $\( 0 - 0 = 0 \)$
3. $\( 1 - 1 = 0 \)$
4. $\( 1 - 0 = 1 \)$

Final result:
```
  1101
-  101
-------
   1000
```
**Result**: $\( 1101_2 - 101_2 = 1000_2 \)$ (which is 8 in decimal).

---

### **3. Binary Multiplication**

Binary multiplication is performed similarly to decimal multiplication, with the basic rule:
- $\( 1 \times 1 = 1 \)$
- $\( 1 \times 0 = 0 \)$
- $\( 0 \times 1 = 0 \)$
- $\( 0 \times 0 = 0 \)$

#### **Example:**

Multiplying two binary numbers:
```
   101
×   11
-------
```

Step-by-step:
1. Multiply $\( 101 \times 1 = 101 \)$ (write this down).
2. Multiply $\( 101 \times 1 \)$ (shifted one position left): $\( 1010 \)$.
3. Add the results:
```
   101
+ 1010
-------
  1111
```
**Result**: $\( 101_2 \times 11_2 = 1111_2 \)$ (which is 15 in decimal).

---

### **4. Binary Division**

Binary division is similar to long division in decimal. The process involves dividing the dividend by the divisor and finding the quotient, with the remainder if necessary.

#### **Example:**

Dividing $\( 1011_2 \)$ by $\( 11_2 \)$:

1. **Step 1**: First, divide the leftmost bits that are equal or greater than the divisor. $\( 10 \div 11 \)$ (this is smaller than the divisor, so consider the next bit).
2. **Step 2**: Now divide $\( 101 \div 11 \)$, which gives a quotient of \( 1 \) and a remainder of \( 0 \).
3. **Step 3**: Bring down the next bit and divide again.

The process continues similarly to decimal division, and the result is:
```
  1011 ÷ 11 = 11 with a remainder of 0
```
**Result**: $\( 1011_2 \div 11_2 = 11_2 \)$ with a remainder of 0 (which is 3 in decimal).

---

### **Other Operations in Binary Math**

#### **1. Binary to Decimal Conversion:**
To convert a binary number to decimal, multiply each bit by $\( 2^n \)$, where \( n \) is the position of the bit, starting from 0 from the rightmost bit.

For example, to convert $\( 1011_2 \)$ to decimal:
$\[
1 \times 2^3 + 0 \times 2^2 + 1 \times 2^1 + 1 \times 2^0 = 8 + 0 + 2 + 1 = 11
\]$

#### **2. Decimal to Binary Conversion:**
To convert a decimal number to binary, repeatedly divide the number by 2, noting the remainder for each division. The remainders give the binary number, read from bottom to top.

For example, converting $\( 13_{10} \)$ to binary:
- $\( 13 \div 2 = 6 \)$ remainder 1
- $\( 6 \div 2 = 3 \)$ remainder 0
- $\( 3 \div 2 = 1 \)$ remainder 1
- $\( 1 \div 2 = 0 \)$ remainder 1

The binary result is $\( 1101_2 \)$.

---

### **Conclusion**

Binary math is an essential concept in computer science and digital electronics, as computers operate using the binary number system. The basic operations of **addition**, **subtraction**, **multiplication**, and **division** are all performed using the binary system, with similar principles to arithmetic in the decimal system, but adapted to only two digits, 0 and 1. Understanding these operations is fundamental for tasks such as programming, network design, and low-level hardware development.
