In PL/SQL, **conditions** are used to control the flow of execution based on logical evaluations. Conditions determine which block of code gets executed, making PL/SQL programs dynamic and adaptable.

---

### **Types of Conditional Statements**

1. **IF-THEN Statement**
2. **IF-THEN-ELSE Statement**
3. **IF-THEN-ELSIF-ELSE Statement**
4. **CASE Statement**
5. **CASE Expression**

---

### **1. IF-THEN Statement**

The simplest form of conditional statement. Executes a block of code if the condition is `TRUE`.

#### Syntax:
```sql
IF condition THEN
   -- Statements
END IF;
```

#### Example:
```sql
DECLARE
   v_salary NUMBER := 5000;
BEGIN
   IF v_salary > 4000 THEN
      DBMS_OUTPUT.PUT_LINE('Salary is greater than 4000');
   END IF;
END;
```

---

### **2. IF-THEN-ELSE Statement**

Executes one block of code if the condition is `TRUE`, and another block if it is `FALSE`.

#### Syntax:
```sql
IF condition THEN
   -- Statements if condition is TRUE
ELSE
   -- Statements if condition is FALSE
END IF;
```

#### Example:
```sql
DECLARE
   v_age NUMBER := 16;
BEGIN
   IF v_age >= 18 THEN
      DBMS_OUTPUT.PUT_LINE('You are eligible to vote');
   ELSE
      DBMS_OUTPUT.PUT_LINE('You are not eligible to vote');
   END IF;
END;
```

---

### **3. IF-THEN-ELSIF-ELSE Statement**

Allows multiple conditions to be checked in sequence. Executes the first block of code where the condition is `TRUE`.

#### Syntax:
```sql
IF condition1 THEN
   -- Statements if condition1 is TRUE
ELSIF condition2 THEN
   -- Statements if condition2 is TRUE
ELSIF condition3 THEN
   -- Statements if condition3 is TRUE
ELSE
   -- Statements if none of the conditions are TRUE
END IF;
```

#### Example:
```sql
DECLARE
   v_marks NUMBER := 75;
BEGIN
   IF v_marks >= 90 THEN
      DBMS_OUTPUT.PUT_LINE('Grade: A');
   ELSIF v_marks >= 75 THEN
      DBMS_OUTPUT.PUT_LINE('Grade: B');
   ELSIF v_marks >= 50 THEN
      DBMS_OUTPUT.PUT_LINE('Grade: C');
   ELSE
      DBMS_OUTPUT.PUT_LINE('Grade: F');
   END IF;
END;
```

---

### **4. CASE Statement**

Simpler and more readable than `IF-ELSIF`. Checks multiple conditions and executes the corresponding block.

#### Syntax:
```sql
CASE
   WHEN condition1 THEN
      -- Statements
   WHEN condition2 THEN
      -- Statements
   ELSE
      -- Default Statements
END CASE;
```

#### Example:
```sql
DECLARE
   v_day VARCHAR2(10) := 'Monday';
BEGIN
   CASE
      WHEN v_day = 'Monday' THEN
         DBMS_OUTPUT.PUT_LINE('Start of the week');
      WHEN v_day = 'Friday' THEN
         DBMS_OUTPUT.PUT_LINE('End of the work week');
      ELSE
         DBMS_OUTPUT.PUT_LINE('Mid-week day');
   END CASE;
END;
```

---

### **5. CASE Expression**

Returns a value based on conditions. Used within SQL queries or PL/SQL blocks.

#### Syntax:
```sql
CASE
   WHEN condition1 THEN result1
   WHEN condition2 THEN result2
   ELSE default_result
END;
```

#### Example:
```sql
DECLARE
   v_marks NUMBER := 85;
   v_grade VARCHAR2(10);
BEGIN
   v_grade := CASE
                 WHEN v_marks >= 90 THEN 'A'
                 WHEN v_marks >= 75 THEN 'B'
                 WHEN v_marks >= 50 THEN 'C'
                 ELSE 'F'
              END;

   DBMS_OUTPUT.PUT_LINE('Grade: ' || v_grade);
END;
```

---

### **Comparison Between IF and CASE**

| Feature                  | IF-THEN-ELSIF                 | CASE                        |
|--------------------------|-------------------------------|-----------------------------|
| **Readability**          | Can get complex for many conditions | More readable for multiple conditions |
| **Functionality**         | Executes blocks of statements  | Can return a value or execute statements |
| **Usage in SQL**         | Not allowed                   | Allowed                     |

---

### **Using Conditions with SQL**

PL/SQL conditions are often used with SQL queries via the `SELECT INTO` or dynamic SQL statements.

#### Example: Using IF with SQL
```sql
DECLARE
   v_salary NUMBER;
BEGIN
   SELECT salary INTO v_salary
   FROM employees
   WHERE employee_id = 101;

   IF v_salary > 5000 THEN
      DBMS_OUTPUT.PUT_LINE('High salary');
   ELSE
      DBMS_OUTPUT.PUT_LINE('Average salary');
   END IF;
END;
```

---

### **Best Practices for Conditions**

1. **Use CASE for Simplicity**:
   - For multiple conditions, prefer `CASE` for better readability.
2. **Avoid Deep Nesting**:
   - Too many nested `IF` statements make code harder to read.
3. **Include Default Conditions**:
   - Always include an `ELSE` or `DEFAULT` block to handle unexpected cases.
4. **Optimize for Performance**:
   - Evaluate the simplest conditions first to minimize execution time.

---

### **Practice Problems**

1. Write a PL/SQL block to categorize a person's age:
   - If age < 18: Output "Minor"
   - If age between 18 and 60: Output "Adult"
   - Otherwise: Output "Senior"

2. Implement a PL/SQL block that checks if a number is positive, negative, or zero using `IF-THEN-ELSIF-ELSE`.

3. Use a `CASE` statement to assign a discount percentage based on a customer's membership type:
   - "Gold": 20%
   - "Silver": 10%
   - "Bronze": 5%

---

