In PL/SQL, **variables** are used to store data that can be manipulated during the execution of a block. They are declared in the **DECLARE** section of a PL/SQL block and can store different types of data such as numbers, strings, and dates.

---

### **Declaring Variables**

Syntax:
```sql
variable_name [CONSTANT] data_type [NOT NULL] [:= initial_value];
```

- **`variable_name`**: The name of the variable.
- **`CONSTANT`**: Makes the variable unchangeable (optional).
- **`data_type`**: Specifies the type of data the variable can store.
- **`NOT NULL`**: Ensures the variable cannot store a `NULL` value (optional).
- **`initial_value`**: Sets an initial value for the variable (optional).

---

### **Examples**

#### **1. Basic Declaration and Assignment**
```sql
DECLARE
   v_employee_id NUMBER;       -- Variable without initialization
   v_salary NUMBER := 5000;    -- Variable with initialization
BEGIN
   v_employee_id := 101;       -- Assign value
   DBMS_OUTPUT.PUT_LINE('Employee ID: ' || v_employee_id);
   DBMS_OUTPUT.PUT_LINE('Salary: ' || v_salary);
END;
```

---

#### **2. Declaring Constants**
- A constant cannot be reassigned after its declaration.
```sql
DECLARE
   c_tax_rate CONSTANT NUMBER := 0.18; -- Constant declaration
BEGIN
   DBMS_OUTPUT.PUT_LINE('Tax Rate: ' || c_tax_rate);
   -- c_tax_rate := 0.2; -- This will cause an error
END;
```

---

#### **3. Using NOT NULL**
- A variable declared as `NOT NULL` must be initialized.
```sql
DECLARE
   v_department_name VARCHAR2(50) NOT NULL := 'Sales';
BEGIN
   DBMS_OUTPUT.PUT_LINE('Department: ' || v_department_name);
END;
```

---

### **Variable Scope**
- **Local Variables**: Declared in the `DECLARE` section of a block and are accessible only within that block.
- **Global Variables**: Declared in a package specification and accessible across multiple blocks.

---

### **Variable Data Types**

PL/SQL supports all data types available in SQL, as well as some specific to PL/SQL.

- **Numeric**: `NUMBER`, `PLS_INTEGER`, `BINARY_FLOAT`, etc.
- **Character**: `CHAR`, `VARCHAR2`, `NCHAR`, `NVARCHAR2`
- **Date and Time**: `DATE`, `TIMESTAMP`, etc.
- **Boolean**: `BOOLEAN`
- **LOB**: `CLOB`, `BLOB`

Example:
```sql
DECLARE
   v_name VARCHAR2(50);       -- Character
   v_dob DATE;                -- Date
   v_is_active BOOLEAN := TRUE; -- Boolean
BEGIN
   v_name := 'Alice';
   v_dob := TO_DATE('1990-01-01', 'YYYY-MM-DD');
   DBMS_OUTPUT.PUT_LINE('Name: ' || v_name);
   DBMS_OUTPUT.PUT_LINE('DOB: ' || TO_CHAR(v_dob, 'DD-MON-YYYY'));
   IF v_is_active THEN
      DBMS_OUTPUT.PUT_LINE('Status: Active');
   END IF;
END;
```

---

### **Assigning Values**

1. **Using the `:=` Operator**:
   ```sql
   DECLARE
      v_salary NUMBER := 10000;
   BEGIN
      v_salary := v_salary + 2000; -- Update value
   END;
   ```

2. **Using SQL Statements (`SELECT INTO`)**:
   ```sql
   DECLARE
      v_salary NUMBER;
   BEGIN
      SELECT salary INTO v_salary
      FROM employees
      WHERE employee_id = 101;

      DBMS_OUTPUT.PUT_LINE('Salary: ' || v_salary);
   END;
   ```

---

### **Working with Bind Variables**

Bind variables are placeholders in PL/SQL used in tools like SQL*Plus or SQL Developer.

- Declare a bind variable using a `VARIABLE` command.
  ```sql
  VARIABLE v_emp_id NUMBER;
  ```

- Use it in PL/SQL:
  ```sql
  BEGIN
     :v_emp_id := 101; -- Assign value to bind variable
     DBMS_OUTPUT.PUT_LINE('Bind Variable: ' || :v_emp_id);
  END;
  ```

---

### **Example: Multiple Variable Usage**

```sql
DECLARE
   v_employee_name VARCHAR2(50);
   v_hire_date DATE;
   v_department_id NUMBER;
BEGIN
   -- Assign values directly
   v_employee_name := 'John Doe';
   v_hire_date := SYSDATE;
   v_department_id := 10;

   DBMS_OUTPUT.PUT_LINE('Name: ' || v_employee_name);
   DBMS_OUTPUT.PUT_LINE('Hire Date: ' || TO_CHAR(v_hire_date, 'DD-MON-YYYY'));
   DBMS_OUTPUT.PUT_LINE('Department ID: ' || v_department_id);
END;
```

---

### **Key Points**
1. **Case Insensitivity**: Variable names are not case-sensitive.
2. **Initialization**: Variables can be initialized at the time of declaration.
3. **NULL Values**: Variables default to `NULL` unless initialized.
4. **Debugging**: Use `DBMS_OUTPUT.PUT_LINE` to display variable values.

