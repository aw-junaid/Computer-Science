Loops in PL/SQL are control structures that allow the repeated execution of a block of statements. They are essential for performing iterative tasks such as processing rows in a table or repeating calculations.

---

### **Types of Loops in PL/SQL**

1. **Basic Loop**  
2. **WHILE Loop**  
3. **FOR Loop**  
4. **Nested Loops**

---

### **1. Basic Loop**

A simple loop that executes repeatedly until an `EXIT` condition is met. The condition is typically checked within the loop body.

#### **Syntax**
```sql
LOOP
   -- Statements
   EXIT WHEN condition;
END LOOP;
```

#### **Example**
```sql
DECLARE
   v_counter NUMBER := 1;
BEGIN
   LOOP
      DBMS_OUTPUT.PUT_LINE('Iteration: ' || v_counter);
      v_counter := v_counter + 1;

      -- Exit when counter exceeds 5
      EXIT WHEN v_counter > 5;
   END LOOP;
END;
```

---

### **2. WHILE Loop**

Executes a block of statements while a specified condition is `TRUE`. The condition is evaluated before each iteration.

#### **Syntax**
```sql
WHILE condition LOOP
   -- Statements
END LOOP;
```

#### **Example**
```sql
DECLARE
   v_number NUMBER := 1;
BEGIN
   WHILE v_number <= 5 LOOP
      DBMS_OUTPUT.PUT_LINE('Number: ' || v_number);
      v_number := v_number + 1;
   END LOOP;
END;
```

---

### **3. FOR Loop**

A loop that iterates over a specified range of values. The counter is automatically incremented or decremented, and it does not need to be explicitly managed.

#### **Syntax**
```sql
FOR counter IN start_value .. end_value LOOP
   -- Statements
END LOOP;
```

- **`..`**: Defines the range (inclusive).
- The counter variable is implicitly declared and cannot be modified inside the loop.

#### **Example**
```sql
BEGIN
   FOR i IN 1 .. 5 LOOP
      DBMS_OUTPUT.PUT_LINE('Value of i: ' || i);
   END LOOP;
END;
```

#### **Reverse FOR Loop**
```sql
BEGIN
   FOR i IN REVERSE 5 .. 1 LOOP
      DBMS_OUTPUT.PUT_LINE('Value of i: ' || i);
   END LOOP;
END;
```

---

### **4. Nested Loops**

Loops within loops allow iterating over multiple levels of data. Each loop must have its own exit condition.

#### **Example**
```sql
BEGIN
   FOR i IN 1 .. 3 LOOP
      FOR j IN 1 .. 2 LOOP
         DBMS_OUTPUT.PUT_LINE('Outer Loop: ' || i || ', Inner Loop: ' || j);
      END LOOP;
   END LOOP;
END;
```

---

### **Loop Control Statements**

1. **EXIT**: Terminates the loop immediately.  
2. **EXIT WHEN**: Exits the loop when a specific condition is met.  
3. **CONTINUE**: Skips the current iteration and moves to the next.  
4. **CONTINUE WHEN**: Skips the iteration if the specified condition is met.

---

#### **Using EXIT**
```sql
DECLARE
   v_counter NUMBER := 1;
BEGIN
   LOOP
      DBMS_OUTPUT.PUT_LINE('Counter: ' || v_counter);
      v_counter := v_counter + 1;
      EXIT WHEN v_counter > 3; -- Exit the loop
   END LOOP;
END;
```

#### **Using CONTINUE**
```sql
BEGIN
   FOR i IN 1 .. 5 LOOP
      IF MOD(i, 2) = 0 THEN
         CONTINUE; -- Skip even numbers
      END IF;
      DBMS_OUTPUT.PUT_LINE('Odd number: ' || i);
   END LOOP;
END;
```

---

### **Iterating Over Rows Using Loops**

You can use loops to process rows fetched from a table.

#### **Using Cursor in a FOR Loop**
```sql
DECLARE
   CURSOR emp_cursor IS
      SELECT employee_id, first_name FROM employees WHERE department_id = 10;
BEGIN
   FOR emp_rec IN emp_cursor LOOP
      DBMS_OUTPUT.PUT_LINE('Employee ID: ' || emp_rec.employee_id || ', Name: ' || emp_rec.first_name);
   END LOOP;
END;
```

#### **Manually Fetching Rows**
```sql
DECLARE
   CURSOR emp_cursor IS
      SELECT employee_id, first_name FROM employees WHERE department_id = 10;
   emp_rec emp_cursor%ROWTYPE;
BEGIN
   OPEN emp_cursor;

   LOOP
      FETCH emp_cursor INTO emp_rec;
      EXIT WHEN emp_cursor%NOTFOUND; -- Exit if no more rows
      DBMS_OUTPUT.PUT_LINE('Employee ID: ' || emp_rec.employee_id || ', Name: ' || emp_rec.first_name);
   END LOOP;

   CLOSE emp_cursor;
END;
```

---

### **Best Practices**

1. **Use EXIT/CONTINUE Wisely**:
   - Avoid infinite loops by ensuring `EXIT` conditions are well-defined.
2. **Prefer FOR Loops**:
   - Use `FOR` loops for simple iterations to avoid manual counter management.
3. **Limit Nested Loops**:
   - Minimize nested loops for better readability and performance.
4. **Optimize Row Processing**:
   - Use bulk operations (`FORALL` or `BULK COLLECT`) for large datasets.

---

### **Practice Problems**

1. Write a PL/SQL block to print the first 10 Fibonacci numbers using a loop.
2. Create a PL/SQL block to calculate the factorial of a given number using a `WHILE` loop.
3. Use a cursor and a `FOR` loop to iterate through rows in a table and print all employee names with a salary greater than 5000.

Let me know if you’d like help with solutions or further explanations!
