PL/SQL (Procedural Language/SQL) is organized in a **block structure**, consisting of three main sections: **Declarative**, **Executable**, and **Exception Handling**. Here's an overview of the basic syntax and its components.

---

### **General Structure of a PL/SQL Block**

```sql
DECLARE
   -- Declarative section (optional)
   -- Variables, constants, cursors, etc. are declared here.
BEGIN
   -- Executable section (mandatory)
   -- The actual code to perform operations goes here.
EXCEPTION
   -- Exception handling section (optional)
   -- Define actions to handle runtime errors.
END;
```

### **Key Sections Explained**

1. **Declarative Section**:
   - Begins with the `DECLARE` keyword.
   - Used to declare variables, constants, and cursors.
   - This section is optional.

2. **Executable Section**:
   - Begins with the `BEGIN` keyword.
   - Contains SQL and PL/SQL statements.
   - This section is mandatory.

3. **Exception Handling Section**:
   - Begins with the `EXCEPTION` keyword.
   - Handles runtime errors.
   - This section is optional.

---

### **Basic PL/SQL Syntax Elements**

#### **1. Variables**
Variables are declared in the `DECLARE` section.

```sql
DECLARE
   v_name VARCHAR2(50); -- Variable declaration
   v_salary NUMBER := 5000; -- Variable with an initial value
BEGIN
   DBMS_OUTPUT.PUT_LINE('Salary: ' || v_salary); -- Concatenation
END;
```

#### **2. SQL Statements in PL/SQL**
Use SQL statements to interact with the database.

```sql
DECLARE
   v_count NUMBER;
BEGIN
   SELECT COUNT(*) INTO v_count
   FROM employees
   WHERE department_id = 10;

   DBMS_OUTPUT.PUT_LINE('Employee Count: ' || v_count);
END;
```

- `SELECT INTO`: Used to retrieve and assign values to variables.
- `INSERT`, `UPDATE`, `DELETE` are also supported.

#### **3. Control Structures**
- **Conditional Statements**:
  ```sql
  IF condition THEN
     -- Code to execute if condition is true
  ELSIF another_condition THEN
     -- Code to execute if another condition is true
  ELSE
     -- Code to execute if none of the above conditions are true
  END IF;
  ```

- **Loops**:
  - **Basic Loop**:
    ```sql
    LOOP
       -- Code to execute repeatedly
       EXIT WHEN condition;
    END LOOP;
    ```

  - **FOR Loop**:
    ```sql
    FOR i IN 1..10 LOOP
       DBMS_OUTPUT.PUT_LINE('Value: ' || i);
    END LOOP;
    ```

  - **WHILE Loop**:
    ```sql
    WHILE condition LOOP
       -- Code to execute
    END LOOP;
    ```

#### **4. Exception Handling**
Handle runtime errors using predefined or user-defined exceptions.

```sql
BEGIN
   -- Code that may cause an error
   SELECT 1/0 INTO v_result FROM dual; -- This causes a divide-by-zero error
EXCEPTION
   WHEN ZERO_DIVIDE THEN
      DBMS_OUTPUT.PUT_LINE('Division by zero error occurred.');
   WHEN OTHERS THEN
      DBMS_OUTPUT.PUT_LINE('An unexpected error occurred.');
END;
```

---

### **Example: Complete PL/SQL Block**

```sql
DECLARE
   v_employee_name VARCHAR2(50);
BEGIN
   -- Retrieving data
   SELECT first_name INTO v_employee_name
   FROM employees
   WHERE employee_id = 101;

   -- Displaying the result
   DBMS_OUTPUT.PUT_LINE('Employee Name: ' || v_employee_name);
EXCEPTION
   WHEN NO_DATA_FOUND THEN
      DBMS_OUTPUT.PUT_LINE('No employee found with the given ID.');
   WHEN OTHERS THEN
      DBMS_OUTPUT.PUT_LINE('An unexpected error occurred.');
END;
```

---

### **Key Points**
1. **Semicolons** (`;`) terminate statements within the block.
2. Use the `DBMS_OUTPUT.PUT_LINE` procedure for debugging and displaying output.
3. PL/SQL is case-insensitive but follows a structured syntax.
4. Blocks can be nested.

