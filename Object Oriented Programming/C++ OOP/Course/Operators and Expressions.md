### **Operators and Expressions in C++**

Operators are symbols used to perform operations on variables and values, and expressions combine these operators with variables to produce results.

---

### **1. Types of Operators in C++**

#### **A. Arithmetic Operators**
Perform mathematical operations.

| **Operator** | **Description**       | **Example**         | **Result**   |
|--------------|-----------------------|---------------------|--------------|
| `+`          | Addition              | `a + b`             | Sum of `a` and `b` |
| `-`          | Subtraction           | `a - b`             | Difference between `a` and `b` |
| `*`          | Multiplication        | `a * b`             | Product of `a` and `b` |
| `/`          | Division              | `a / b`             | Quotient of `a` divided by `b` |
| `%`          | Modulus (remainder)   | `a % b`             | Remainder of `a` divided by `b` |

---

#### **B. Relational (Comparison) Operators**
Compare two values and return a Boolean result (`true` or `false`).

| **Operator** | **Description**       | **Example**         | **Result**   |
|--------------|-----------------------|---------------------|--------------|
| `==`         | Equal to              | `a == b`            | `true` if `a` equals `b` |
| `!=`         | Not equal to          | `a != b`            | `true` if `a` is not equal to `b` |
| `<`          | Less than             | `a < b`             | `true` if `a` is less than `b` |
| `>`          | Greater than          | `a > b`             | `true` if `a` is greater than `b` |
| `<=`         | Less than or equal to | `a <= b`            | `true` if `a` is less than or equal to `b` |
| `>=`         | Greater than or equal to | `a >= b`         | `true` if `a` is greater than or equal to `b` |

---

#### **C. Logical Operators**
Used to combine conditional statements.

| **Operator** | **Description**        | **Example**          | **Result**              |
|--------------|------------------------|----------------------|-------------------------|
| `&&`         | Logical AND            | `(a > b) && (c < d)` | `true` if both conditions are true |
| `||`         | Logical OR             | `(a > b) || (c < d)` | `true` if at least one condition is true |
| `!`          | Logical NOT            | `!(a > b)`           | Negates the result (`true` becomes `false`) |

---

#### **D. Bitwise Operators**
Operate on bits of a number.

| **Operator** | **Description**        | **Example**          | **Result**   |
|--------------|------------------------|----------------------|--------------|
| `&`          | AND                    | `a & b`              | Performs AND operation bit-by-bit |
| `|`          | OR                     | `a | b`              | Performs OR operation bit-by-bit |
| `^`          | XOR                    | `a ^ b`              | Performs XOR operation bit-by-bit |
| `~`          | NOT                    | `~a`                 | Inverts all bits |
| `<<`         | Left shift             | `a << 2`             | Shifts bits to the left by 2 places |
| `>>`         | Right shift            | `a >> 2`             | Shifts bits to the right by 2 places |

---

#### **E. Assignment Operators**
Assign values to variables.

| **Operator** | **Description**        | **Example**          | **Equivalent To**      |
|--------------|------------------------|----------------------|------------------------|
| `=`          | Assignment             | `a = b`              | Assign `b` to `a`      |
| `+=`         | Add and assign         | `a += b`             | `a = a + b`            |
| `-=`         | Subtract and assign    | `a -= b`             | `a = a - b`            |
| `*=`         | Multiply and assign    | `a *= b`             | `a = a * b`            |
| `/=`         | Divide and assign      | `a /= b`             | `a = a / b`            |
| `%=`         | Modulus and assign     | `a %= b`             | `a = a % b`            |

---

#### **F. Increment and Decrement Operators**
Modify a variable’s value by 1.

| **Operator** | **Description**          | **Example**     | **Result**       |
|--------------|--------------------------|-----------------|------------------|
| `++`         | Increment by 1           | `a++` or `++a`  | Increases `a` by 1 |
| `--`         | Decrement by 1           | `a--` or `--a`  | Decreases `a` by 1 |

---

#### **G. Other Operators**
| **Operator**  | **Description**                 | **Example**          |
|---------------|---------------------------------|----------------------|
| `sizeof`      | Returns the size of a variable | `sizeof(int)`        |
| `?:`          | Ternary (conditional) operator | `(a > b) ? a : b`    |
| `&`           | Address-of operator            | `int* p = &a;`       |
| `*`           | Pointer dereference            | `int x = *p;`        |

---

### **2. Expressions**
An expression is a combination of operators and operands that computes a value.

#### **Example Expressions**
1. **Arithmetic Expression**:
   ```cpp
   int result = (a + b) * c;
   ```

2. **Logical Expression**:
   ```cpp
   bool isValid = (x > 10) && (y < 20);
   ```

3. **Compound Expression**:
   ```cpp
   int x = (a + b) / c + d * e;
   ```

---

### **3. Example Program**
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20, c = 5;
    int sum = a + b;          // Arithmetic
    bool isEqual = (a == b);  // Relational
    int bitwiseAnd = a & b;   // Bitwise

    cout << "Sum: " << sum << endl;
    cout << "Is Equal: " << isEqual << endl;
    cout << "Bitwise AND: " << bitwiseAnd << endl;

    return 0;
}
```

**Output**:
```
Sum: 30
Is Equal: 0
Bitwise AND: 0
```

---

