In PL/SQL, a **cursor** is a pointer to a private area in memory where SQL query results are stored. Cursors are used to retrieve and manipulate data row by row in PL/SQL blocks, procedures, and functions. They are particularly useful when you need to work with large result sets, as they allow you to fetch rows one at a time and perform operations on them.

There are two types of cursors in PL/SQL:
1. **Implicit Cursors**: These are automatically created by Oracle when a SELECT statement is executed in a PL/SQL block, without the need for explicit cursor declaration.
2. **Explicit Cursors**: These are explicitly declared and controlled by the programmer. They provide more control over query execution and data retrieval.

---

### **1. Implicit Cursors**

An implicit cursor is automatically created by Oracle when you execute a `SELECT INTO` or DML statement (INSERT, UPDATE, DELETE). The results are implicitly fetched by Oracle without needing to explicitly declare or open a cursor.

For example:
```sql
DECLARE
   v_emp_name VARCHAR2(50);
BEGIN
   -- Implicit Cursor used for SELECT INTO statement
   SELECT first_name
   INTO v_emp_name
   FROM employees
   WHERE employee_id = 101;

   DBMS_OUTPUT.PUT_LINE('Employee Name: ' || v_emp_name);
END;
```

In this case, Oracle internally manages the cursor behind the scenes, fetching the result for the `SELECT INTO` statement.

---

### **2. Explicit Cursors**

An **explicit cursor** is explicitly declared and used to retrieve multiple rows from a query result. It gives you more control over the query and allows you to fetch and process each row individually.

### **Declaring and Using an Explicit Cursor**

#### **Step 1: Declare the Cursor**

A cursor is declared by using the `CURSOR` keyword followed by the cursor name and the SQL query.

```sql
DECLARE
   CURSOR emp_cursor IS
      SELECT employee_id, first_name, last_name
      FROM employees
      WHERE department_id = 10;
```

#### **Step 2: Open the Cursor**

To execute the query and retrieve the result set, the cursor must be **opened** using the `OPEN` statement.

```sql
DECLARE
   CURSOR emp_cursor IS
      SELECT employee_id, first_name, last_name
      FROM employees
      WHERE department_id = 10;
   
   v_emp_id employees.employee_id%TYPE;
   v_first_name employees.first_name%TYPE;
   v_last_name employees.last_name%TYPE;
BEGIN
   OPEN emp_cursor;  -- Open the cursor to begin fetching rows
   
   -- Fetch rows from the cursor (one at a time)
   FETCH emp_cursor INTO v_emp_id, v_first_name, v_last_name;
   DBMS_OUTPUT.PUT_LINE('Employee ID: ' || v_emp_id || ', Name: ' || v_first_name || ' ' || v_last_name);
   
   CLOSE emp_cursor;  -- Close the cursor after usage
END;
```

- **OPEN**: Opens the cursor, which executes the SQL query.
- **FETCH INTO**: Retrieves the next row from the cursor and places the column values into variables.
- **CLOSE**: Closes the cursor when you're done fetching data.

#### **Step 3: Fetch Data from the Cursor**

To retrieve data from the cursor, you use the `FETCH` statement inside a loop (typically). It fetches one row at a time from the result set and assigns the values to variables.

```sql
DECLARE
   CURSOR emp_cursor IS
      SELECT employee_id, first_name, last_name
      FROM employees
      WHERE department_id = 10;
   
   v_emp_id employees.employee_id%TYPE;
   v_first_name employees.first_name%TYPE;
   v_last_name employees.last_name%TYPE;
BEGIN
   OPEN emp_cursor;  -- Open the cursor
   
   -- Loop through the cursor and fetch all rows
   LOOP
      FETCH emp_cursor INTO v_emp_id, v_first_name, v_last_name;
      EXIT WHEN emp_cursor%NOTFOUND;  -- Exit when no more rows are available
      
      DBMS_OUTPUT.PUT_LINE('Employee ID: ' || v_emp_id || ', Name: ' || v_first_name || ' ' || v_last_name);
   END LOOP;
   
   CLOSE emp_cursor;  -- Close the cursor after looping through all rows
END;
```

- **emp_cursor%NOTFOUND**: A special attribute that returns `TRUE` when the cursor has fetched all rows (no more rows are available).

#### **Step 4: Close the Cursor**

Always close the cursor once you're done using it to free up memory resources.

```sql
CLOSE emp_cursor;
```

---

### **Cursor Attributes**

PL/SQL provides a set of attributes for cursors that help you control and monitor the cursor's status:

1. **%FOUND**: Returns `TRUE` if the last `FETCH` returned a row, and `FALSE` if it did not.
2. **%NOTFOUND**: Returns `TRUE` if the last `FETCH` did not return a row, and `FALSE` if it did.
3. **%ROWCOUNT**: Returns the number of rows fetched so far.
4. **%ISOPEN**: Returns `TRUE` if the cursor is currently open, and `FALSE` if it is not.

For example:

```sql
DECLARE
   CURSOR emp_cursor IS
      SELECT employee_id, first_name, last_name
      FROM employees;
   
   v_emp_id employees.employee_id%TYPE;
   v_first_name employees.first_name%TYPE;
   v_last_name employees.last_name%TYPE;
BEGIN
   OPEN emp_cursor;
   
   LOOP
      FETCH emp_cursor INTO v_emp_id, v_first_name, v_last_name;
      EXIT WHEN emp_cursor%NOTFOUND;  -- Exit when no more rows
      DBMS_OUTPUT.PUT_LINE('Fetched ' || emp_cursor%ROWCOUNT || ' rows: ' || v_first_name || ' ' || v_last_name);
   END LOOP;
   
   CLOSE emp_cursor;
END;
```

---

### **Implicit vs. Explicit Cursors**

- **Implicit cursors** are simpler to use, as they do not require manual cursor management (declaration, opening, fetching, closing).
- **Explicit cursors** give you more control, allowing you to iterate over result sets row by row and manage large datasets more efficiently.

---

### **Using Cursors in Procedures and Functions**

You can also use cursors inside procedures and functions to process multiple rows of data. For example, the following procedure loops over employees in a given department and updates their salary:

```sql
CREATE OR REPLACE PROCEDURE update_salary_in_department (p_dept_id IN NUMBER, p_increase IN NUMBER) IS
   CURSOR emp_cursor IS
      SELECT employee_id, salary
      FROM employees
      WHERE department_id = p_dept_id;

   v_emp_id employees.employee_id%TYPE;
   v_salary employees.salary%TYPE;
BEGIN
   OPEN emp_cursor;
   
   LOOP
      FETCH emp_cursor INTO v_emp_id, v_salary;
      EXIT WHEN emp_cursor%NOTFOUND;
      
      -- Update the employee's salary
      UPDATE employees
      SET salary = v_salary + p_increase
      WHERE employee_id = v_emp_id;
   END LOOP;
   
   CLOSE emp_cursor;
   
   COMMIT;  -- Commit the updates to the database
END update_salary_in_department;
```

---

### **Ref Cursors (Parameterized Cursors)**

A **ref cursor** is a cursor that can be passed as a parameter between PL/SQL blocks, allowing you to use dynamic queries. Ref cursors are particularly useful when you don’t know the exact query in advance.

#### **Declaring a Ref Cursor**

```sql
DECLARE
   TYPE ref_cursor IS REF CURSOR;
   emp_cursor ref_cursor;
   v_emp_id employees.employee_id%TYPE;
   v_first_name employees.first_name%TYPE;
BEGIN
   OPEN emp_cursor FOR
      SELECT employee_id, first_name
      FROM employees
      WHERE department_id = 10;

   LOOP
      FETCH emp_cursor INTO v_emp_id, v_first_name;
      EXIT WHEN emp_cursor%NOTFOUND;
      DBMS_OUTPUT.PUT_LINE('Employee ID: ' || v_emp_id || ', Name: ' || v_first_name);
   END LOOP;

   CLOSE emp_cursor;
END;
```

#### **Passing Ref Cursors Between Procedures**

You can pass a ref cursor as an argument between PL/SQL blocks, functions, and procedures.

```sql
CREATE OR REPLACE PROCEDURE get_employees_by_dept (p_dept_id IN NUMBER, p_cursor OUT SYS_REFCURSOR) IS
BEGIN
   OPEN p_cursor FOR
      SELECT employee_id, first_name, last_name
      FROM employees
      WHERE department_id = p_dept_id;
END get_employees_by_dept;
```

To call this procedure and fetch data from the ref cursor:

```sql
DECLARE
   v_cursor SYS_REFCURSOR;
   v_emp_id employees.employee_id%TYPE;
   v_first_name employees.first_name%TYPE;
   v_last_name employees.last_name%TYPE;
BEGIN
   get_employees_by_dept(10, v_cursor);

   LOOP
      FETCH v_cursor INTO v_emp_id, v_first_name, v_last_name;
      EXIT WHEN v_cursor%NOTFOUND;
      DBMS_OUTPUT.PUT_LINE('Employee ID: ' || v_emp_id || ', Name: ' || v_first_name || ' ' || v_last_name);
   END LOOP;

   CLOSE v_cursor;
END;
```

---

### **Best Practices for Using Cursors**

1. **Close Cursors Properly**: Always close cursors after you're done fetching rows to free up resources.
2. **Avoid Unnecessary Cursors**: If you

 can achieve your goal with a single `SELECT INTO` statement, use it instead of a cursor.
3. **Limit the Number of Rows**: Use cursors for large datasets, but ensure you're not unnecessarily fetching too many rows into memory at once.
4. **Use Bulk Operations**: For large result sets, consider using `BULK COLLECT` and `FORALL` to optimize performance.

---

Let me know if you need more detailed examples or further explanation on any cursor-related topic!
