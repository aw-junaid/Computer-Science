### TypeScript - Operators

TypeScript supports a wide variety of operators that are used to perform operations on variables and values. These operators are the same as those in JavaScript, but TypeScript also includes some additional operators and enforces type safety during operations. Let's dive into the different categories of operators in TypeScript.

---

### 1. **Arithmetic Operators**

These operators are used to perform basic mathematical operations like addition, subtraction, multiplication, division, and modulus.

| Operator | Description                   | Example           |
|----------|-------------------------------|-------------------|
| `+`      | Addition (numeric or string)   | `5 + 3 = 8`       |
| `-`      | Subtraction                    | `5 - 3 = 2`       |
| `*`      | Multiplication                 | `5 * 3 = 15`      |
| `/`      | Division                       | `5 / 3 = 1.6667`  |
| `%`      | Modulus (remainder)            | `5 % 3 = 2`       |
| `**`     | Exponentiation                 | `2 ** 3 = 8`      |

- **Example**:
    ```typescript
    let x: number = 10;
    let y: number = 5;
    console.log(x + y);  // 15
    console.log(x - y);  // 5
    console.log(x * y);  // 50
    console.log(x / y);  // 2
    console.log(x % y);  // 0
    ```

---

### 2. **Comparison Operators**

Comparison operators are used to compare two values. They return a boolean (`true` or `false`) based on the comparison result.

| Operator | Description                         | Example         |
|----------|-------------------------------------|-----------------|
| `==`     | Equal to (loose equality)           | `5 == '5'` → `true`  |
| `===`    | Equal to (strict equality)          | `5 === '5'` → `false` |
| `!=`     | Not equal to (loose inequality)     | `5 != 4` → `true`     |
| `!==`    | Not equal to (strict inequality)    | `5 !== '5'` → `true`  |
| `>`      | Greater than                        | `5 > 3` → `true`      |
| `<`      | Less than                           | `5 < 10` → `true`     |
| `>=`     | Greater than or equal to            | `5 >= 5` → `true`     |
| `<=`     | Less than or equal to               | `5 <= 10` → `true`    |

- **Example**:
    ```typescript
    let a: number = 10;
    let b: number = 5;
    console.log(a > b);  // true
    console.log(a === 10);  // true
    console.log(a !== b);  // true
    ```

---

### 3. **Logical Operators**

Logical operators are used to perform logical operations, often to combine multiple conditions in a boolean expression.

| Operator | Description                             | Example            |
|----------|-----------------------------------------|--------------------|
| `&&`     | Logical AND (both must be true)         | `true && false` → `false` |
| `||`     | Logical OR (at least one must be true)  | `true || false` → `true`  |
| `!`      | Logical NOT (negation)                  | `!true` → `false`  |

- **Example**:
    ```typescript
    let x: boolean = true;
    let y: boolean = false;

    console.log(x && y);  // false
    console.log(x || y);  // true
    console.log(!x);      // false
    ```

---

### 4. **Assignment Operators**

Assignment operators are used to assign values to variables. TypeScript also includes shorthand assignment operators that combine a mathematical operation with assignment.

| Operator | Description                          | Example           |
|----------|--------------------------------------|-------------------|
| `=`      | Assign value to a variable           | `let a = 5;`      |
| `+=`     | Add and assign                       | `a += 5;` → `a = a + 5` |
| `-=`     | Subtract and assign                  | `a -= 3;` → `a = a - 3` |
| `*=`     | Multiply and assign                  | `a *= 2;` → `a = a * 2` |
| `/=`     | Divide and assign                    | `a /= 2;` → `a = a / 2` |
| `%=`     | Modulus and assign                   | `a %= 3;` → `a = a % 3` |

- **Example**:
    ```typescript
    let num: number = 10;
    num += 5;  // num = 15
    num -= 3;  // num = 12
    num *= 2;  // num = 24
    num /= 4;  // num = 6
    num %= 2;  // num = 0
    ```

---

### 5. **Unary Operators**

Unary operators operate on a single operand.

| Operator | Description                         | Example      |
|----------|-------------------------------------|--------------|
| `++`     | Increment (adds 1 to operand)       | `x++` → `x = x + 1` |
| `--`     | Decrement (subtracts 1 from operand)| `x--` → `x = x - 1` |
| `+`      | Unary plus (converts to number)     | `+ '5'` → `5` |
| `-`      | Unary minus (negates the operand)   | `-5` → `-5` |
| `!`      | Logical NOT (negates boolean value) | `!true` → `false` |

- **Example**:
    ```typescript
    let x: number = 5;
    x++;  // x = 6
    x--;  // x = 5
    console.log(+ "5");  // 5
    console.log(-5);     // -5
    ```

---

### 6. **Bitwise Operators**

Bitwise operators perform operations on the binary representations of integers. These operators are often used for low-level programming tasks.

| Operator | Description                        | Example             |
|----------|------------------------------------|---------------------|
| `&`      | Bitwise AND                        | `5 & 3` → `1`       |
| `|`      | Bitwise OR                         | `5 | 3` → `7`       |
| `^`      | Bitwise XOR                        | `5 ^ 3` → `6`       |
| `~`      | Bitwise NOT (inverts bits)         | `~5` → `-6`         |
| `<<`     | Bitwise left shift                 | `5 << 1` → `10`     |
| `>>`     | Bitwise right shift                | `5 >> 1` → `2`      |
| `>>>`    | Bitwise unsigned right shift       | `-5 >>> 1` → `2147483643` |

- **Example**:
    ```typescript
    let x: number = 5;  // 0101 in binary
    let y: number = 3;  // 0011 in binary
    console.log(x & y);  // 1 (0101 & 0011 = 0001)
    console.log(x | y);  // 7 (0101 | 0011 = 0111)
    console.log(x ^ y);  // 6 (0101 ^ 0011 = 0110)
    ```

---

### 7. **Ternary (Conditional) Operator**

The ternary operator is a shorthand for an `if`-`else` statement. It returns one of two values based on a condition.

| Operator | Description                            | Example               |
|----------|----------------------------------------|-----------------------|
| `? :`    | Conditional (ternary) operator         | `condition ? expr1 : expr2` |

- **Example**:
    ```typescript
    let age: number = 18;
    let isAdult = (age >= 18) ? "Yes" : "No";
    console.log(isAdult);  // Output: "Yes"
    ```

---

### 8. **Type Operators**

TypeScript includes some special operators to work with types.

| Operator | Description                        | Example                            |
|----------|------------------------------------|------------------------------------|
| `typeof` | Returns the type of a variable     | `typeof "hello"` → `"string"`      |
| `instanceof` | Tests whether an object is an instance of a class | `obj instanceof MyClass` |

- **Example**:
    ```typescript
    let name: string = "Alice";
    console.log(typeof name);  // Output: "string"
    ```

---

### Conclusion

TypeScript includes a wide variety of operators similar to JavaScript, but with additional features related to type safety and type inference. By using the right operators effectively, you can manipulate data and perform calculations while maintaining the benefits of TypeScript's type system, such as avoiding type mismatches and ensuring safer code.
