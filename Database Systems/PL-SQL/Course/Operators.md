In PL/SQL, **operators** are symbols used to perform operations on variables, constants, and literals. They can manipulate data, evaluate conditions, and perform calculations.

---

### **Types of Operators in PL/SQL**

1. **Arithmetic Operators**
2. **Relational (Comparison) Operators**
3. **Logical Operators**
4. **String Operators**
5. **Miscellaneous Operators**

---

### **1. Arithmetic Operators**

Arithmetic operators perform basic mathematical operations.

| Operator | Description             | Example        | Result |
|----------|-------------------------|----------------|--------|
| `+`      | Addition                | `5 + 3`        | `8`    |
| `-`      | Subtraction             | `5 - 3`        | `2`    |
| `*`      | Multiplication          | `5 * 3`        | `15`   |
| `/`      | Division                | `10 / 2`       | `5`    |
| `MOD`    | Remainder (Modulo)      | `10 MOD 3`     | `1`    |

**Example:**
```sql
DECLARE
   v_num1 NUMBER := 10;
   v_num2 NUMBER := 3;
   v_result NUMBER;
BEGIN
   v_result := v_num1 + v_num2;  -- Addition
   DBMS_OUTPUT.PUT_LINE('Addition: ' || v_result);

   v_result := v_num1 MOD v_num2;  -- Modulo
   DBMS_OUTPUT.PUT_LINE('Remainder: ' || v_result);
END;
```

---

### **2. Relational (Comparison) Operators**

Relational operators are used to compare values.

| Operator | Description                 | Example         | Result  |
|----------|-----------------------------|-----------------|---------|
| `=`      | Equal to                    | `5 = 5`         | `TRUE`  |
| `!=`     | Not equal to                | `5 != 3`        | `TRUE`  |
| `<>`     | Not equal to (alternative)  | `5 <> 3`        | `TRUE`  |
| `<`      | Less than                   | `3 < 5`         | `TRUE`  |
| `>`      | Greater than                | `5 > 3`         | `TRUE`  |
| `<=`     | Less than or equal to       | `5 <= 5`        | `TRUE`  |
| `>=`     | Greater than or equal to    | `5 >= 3`        | `TRUE`  |

**Example:**
```sql
DECLARE
   v_num1 NUMBER := 10;
   v_num2 NUMBER := 5;
BEGIN
   IF v_num1 > v_num2 THEN
      DBMS_OUTPUT.PUT_LINE('v_num1 is greater than v_num2');
   ELSE
      DBMS_OUTPUT.PUT_LINE('v_num1 is not greater than v_num2');
   END IF;
END;
```

---

### **3. Logical Operators**

Logical operators combine multiple conditions.

| Operator | Description                     | Example                  | Result  |
|----------|---------------------------------|--------------------------|---------|
| `AND`    | Returns `TRUE` if both are true | `(5 > 3) AND (3 < 4)`    | `TRUE`  |
| `OR`     | Returns `TRUE` if one is true   | `(5 > 3) OR (3 > 4)`     | `TRUE`  |
| `NOT`    | Reverses the condition          | `NOT (5 > 3)`            | `FALSE` |

**Example:**
```sql
DECLARE
   v_age NUMBER := 25;
   v_salary NUMBER := 5000;
BEGIN
   IF (v_age > 18 AND v_salary > 3000) THEN
      DBMS_OUTPUT.PUT_LINE('Eligible for the loan.');
   ELSE
      DBMS_OUTPUT.PUT_LINE('Not eligible for the loan.');
   END IF;
END;
```

---

### **4. String Operators**

String operators are used to manipulate text.

| Operator | Description         | Example                    | Result      |
|----------|---------------------|----------------------------|-------------|
| `||`     | Concatenation       | `'Hello ' || 'World!'`     | `Hello World!` |

**Example:**
```sql
DECLARE
   v_first_name VARCHAR2(20) := 'John';
   v_last_name VARCHAR2(20) := 'Doe';
   v_full_name VARCHAR2(40);
BEGIN
   v_full_name := v_first_name || ' ' || v_last_name;
   DBMS_OUTPUT.PUT_LINE('Full Name: ' || v_full_name);
END;
```

---

### **5. Miscellaneous Operators**

#### **1. Concatenation (`||`)**
- Joins two or more strings.
```sql
DECLARE
   v_text VARCHAR2(50);
BEGIN
   v_text := 'PL/SQL' || ' ' || 'Tutorial';
   DBMS_OUTPUT.PUT_LINE(v_text);
END;
```

#### **2. Assignment (`:=`)**
- Assigns a value to a variable.
```sql
DECLARE
   v_salary NUMBER;
BEGIN
   v_salary := 10000;
   DBMS_OUTPUT.PUT_LINE('Salary: ' || v_salary);
END;
```

---

### **Operator Precedence**

Operator precedence determines the order of operations in an expression. The following table shows the precedence, from highest to lowest:

| Precedence | Operator               |
|------------|------------------------|
| 1          | `NOT`                 |
| 2          | `*`, `/`, `MOD`       |
| 3          | `+`, `-`              |
| 4          | Relational operators  |
| 5          | `AND`                 |
| 6          | `OR`                  |

**Example with Precedence:**
```sql
DECLARE
   v_result BOOLEAN;
BEGIN
   v_result := NOT (5 > 3 AND 3 < 4) OR (4 = 4); -- Evaluates based on precedence
   DBMS_OUTPUT.PUT_LINE('Result: ' || v_result);
END;
```

---

### **Examples of Combined Usage**

#### Example 1: Arithmetic and Relational
```sql
DECLARE
   v_num1 NUMBER := 15;
   v_num2 NUMBER := 10;
BEGIN
   IF (v_num1 + v_num2 > 20) THEN
      DBMS_OUTPUT.PUT_LINE('Sum is greater than 20');
   ELSE
      DBMS_OUTPUT.PUT_LINE('Sum is less than or equal to 20');
   END IF;
END;
```

#### Example 2: Logical and Relational
```sql
DECLARE
   v_age NUMBER := 30;
   v_income NUMBER := 5000;
BEGIN
   IF (v_age > 18 AND v_income >= 4000) THEN
      DBMS_OUTPUT.PUT_LINE('Eligible for the program');
   ELSE
      DBMS_OUTPUT.PUT_LINE('Not eligible');
   END IF;
END;
```

---

### **Key Points**
1. Use parentheses `()` to enforce precedence when needed.
2. Use `||` for string concatenation.
3. Combine logical operators (`AND`, `OR`, `NOT`) for complex conditions.

