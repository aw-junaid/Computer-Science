PL/SQL provides a rich set of **data types** for variables, constants, and table columns. These data types help define the kind of data that can be stored and manipulated in PL/SQL programs.

---

### **PL/SQL Data Types Categories**

1. **Scalar Data Types**  
   Store single values like numbers, characters, and dates.

2. **Composite Data Types**  
   Store collections or groups of data, such as records and collections.

3. **Reference Data Types**  
   Store references (pointers) to objects.

4. **LOB (Large Object) Data Types**  
   Store large data like text, images, and multimedia.

---

### **1. Scalar Data Types**

#### **Numeric Data Types**
- **NUMBER**: Stores fixed or floating-point numbers.  
  Example: `NUMBER(p, s)`  
  - `p`: Precision (total digits, max 38).
  - `s`: Scale (digits after the decimal point).

    ```sql
    DECLARE
       v_salary NUMBER(10, 2); -- 10 digits, 2 after the decimal
    BEGIN
       v_salary := 12345.67;
    END;
    ```

- **PLS_INTEGER**: Stores integers; optimized for performance.
- **BINARY_INTEGER**: Similar to `PLS_INTEGER` but less efficient.

---

#### **Character Data Types**
- **CHAR**: Fixed-length string.
  ```sql
  DECLARE
     v_fixed CHAR(10) := 'ABC';
  END;
  ```

- **VARCHAR2**: Variable-length string (up to 32,767 bytes in PL/SQL).  
  Example:  
  ```sql
  DECLARE
     v_name VARCHAR2(50); -- String with max length 50
  END;
  ```

- **NCHAR** / **NVARCHAR2**: For Unicode strings.

---

#### **Date and Time Data Types**
- **DATE**: Stores date and time (accuracy to seconds).
  ```sql
  DECLARE
     v_date DATE := SYSDATE; -- Current system date and time
  END;
  ```

- **TIMESTAMP**: Stores date and time with fractional seconds.
  ```sql
  DECLARE
     v_time TIMESTAMP := SYSTIMESTAMP;
  END;
  ```

- **INTERVAL**: Represents intervals of time.

---

#### **Boolean Data Type**
- **BOOLEAN**: Stores `TRUE`, `FALSE`, or `NULL`.
  ```sql
  DECLARE
     v_flag BOOLEAN := TRUE;
  BEGIN
     IF v_flag THEN
        DBMS_OUTPUT.PUT_LINE('Boolean is true');
     END IF;
  END;
  ```

---

### **2. Composite Data Types**

#### **Records**:  
Used to group related data together.

```sql
DECLARE
   TYPE emp_rec IS RECORD (
      id    NUMBER,
      name  VARCHAR2(50),
      salary NUMBER
   );
   v_emp emp_rec;
BEGIN
   v_emp.id := 101;
   v_emp.name := 'John';
   v_emp.salary := 50000;
END;
```

#### **Collections**:
- **Associative Arrays (Index-by tables)**:
  ```sql
  DECLARE
     TYPE num_table IS TABLE OF NUMBER INDEX BY VARCHAR2(50);
     v_table num_table;
  BEGIN
     v_table('A') := 100;
  END;
  ```
- **Nested Tables** and **VARRAYs** are other collection types.

---

### **3. Reference Data Types**
- **REF CURSOR**: Points to a result set of a query.  
  Example:
  ```sql
  DECLARE
     TYPE emp_cursor IS REF CURSOR;
     v_emp_cursor emp_cursor;
  BEGIN
     OPEN v_emp_cursor FOR SELECT * FROM employees;
  END;
  ```

---

### **4. LOB Data Types**
- **BLOB**: Binary large object (e.g., images).
- **CLOB**: Character large object (e.g., large text).
- **NCLOB**: Unicode CLOB.
- **BFILE**: Pointer to binary files stored outside the database.

---

### **Examples of Common Data Types**

```sql
DECLARE
   v_employee_id NUMBER(6);           -- Numeric data
   v_employee_name VARCHAR2(100);    -- String data
   v_hire_date DATE;                 -- Date and time
   v_is_active BOOLEAN := TRUE;      -- Boolean value
   v_large_text CLOB;                -- Large text
BEGIN
   v_employee_id := 101;
   v_employee_name := 'Alice';
   v_hire_date := SYSDATE;           -- Assign current date
   IF v_is_active THEN
      DBMS_OUTPUT.PUT_LINE('Employee is active.');
   END IF;
END;
```

---

### Summary Table of Common Data Types

| Data Type     | Description                                  | Example                |
|---------------|----------------------------------------------|------------------------|
| `NUMBER`      | Fixed/float-point numbers                   | `NUMBER(5, 2)`         |
| `VARCHAR2`    | Variable-length string                      | `VARCHAR2(50)`         |
| `CHAR`        | Fixed-length string                         | `CHAR(10)`             |
| `DATE`        | Date and time                               | `DATE`                 |
| `TIMESTAMP`   | Date and time with fractional seconds       | `TIMESTAMP`            |
| `BOOLEAN`     | Logical values (TRUE/FALSE/NULL)            | `BOOLEAN`              |
| `CLOB`        | Character large object                      | `CLOB`                 |
| `BLOB`        | Binary large object                         | `BLOB`                 |
| `REF CURSOR`  | Pointer to query results                    | `REF CURSOR`           |

