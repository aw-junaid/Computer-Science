An extended PL/SQL (Procedural Language/SQL) cheat sheet that covers a wide range of commands and functionalities. Each command includes an explanation and examples to help you understand its use.

---

# **PL/SQL Extended Cheat Sheet**

## **1. Basics of PL/SQL**

### 1.1 PL/SQL Block Structure

A PL/SQL block consists of three main sections:

```sql
DECLARE
    -- Declarations of variables and cursors
BEGIN
    -- Executable statements
EXCEPTION
    -- Exception handling statements
END;
```
**Explanation**: PL/SQL blocks are structured in a way to allow for variable declaration, execution of SQL statements, and exception handling.

### 1.2 Anonymous Blocks

```sql
BEGIN
    DBMS_OUTPUT.PUT_LINE('Hello, PL/SQL!');
END;
```
**Explanation**: An anonymous block does not have a name and can be executed immediately. The `DBMS_OUTPUT.PUT_LINE` procedure outputs text to the console.

---

## **2. Variables and Constants**

### 2.1 Declaring Variables

```sql
DECLARE
    v_variable_name VARCHAR2(100);
BEGIN
    v_variable_name := 'Sample Text';
    DBMS_OUTPUT.PUT_LINE(v_variable_name);
END;
```
**Explanation**: Variables can be declared with a specified datatype and can store values.

### 2.2 Declaring Constants

```sql
DECLARE
    c_constant_name CONSTANT NUMBER := 100;
BEGIN
    DBMS_OUTPUT.PUT_LINE(c_constant_name);
END;
```
**Explanation**: Constants are declared using the `CONSTANT` keyword and cannot be modified after initialization.

---

## **3. Control Structures**

### 3.1 Conditional Statements**

- **IF Statement**

```sql
DECLARE
    v_number NUMBER := 10;
BEGIN
    IF v_number > 0 THEN
        DBMS_OUTPUT.PUT_LINE('Positive');
    ELSIF v_number < 0 THEN
        DBMS_OUTPUT.PUT_LINE('Negative');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Zero');
    END IF;
END;
```
**Explanation**: Executes code based on the evaluation of a condition.

- **CASE Statement**

```sql
DECLARE
    v_grade CHAR(1) := 'B';
BEGIN
    CASE v_grade
        WHEN 'A' THEN DBMS_OUTPUT.PUT_LINE('Excellent');
        WHEN 'B' THEN DBMS_OUTPUT.PUT_LINE('Good');
        WHEN 'C' THEN DBMS_OUTPUT.PUT_LINE('Average');
        ELSE DBMS_OUTPUT.PUT_LINE('Poor');
    END CASE;
END;
```
**Explanation**: A control structure that executes specific code based on the value of an expression.

### 3.2 Loops

- **Basic Loop**

```sql
DECLARE
    v_counter NUMBER := 1;
BEGIN
    LOOP
        DBMS_OUTPUT.PUT_LINE('Count: ' || v_counter);
        v_counter := v_counter + 1;
        EXIT WHEN v_counter > 5;
    END LOOP;
END;
```
**Explanation**: Repeats a block of code until a specified condition is met.

- **FOR Loop**

```sql
BEGIN
    FOR i IN 1..5 LOOP
        DBMS_OUTPUT.PUT_LINE('Count: ' || i);
    END LOOP;
END;
```
**Explanation**: Iterates over a range of values.

- **WHILE Loop**

```sql
DECLARE
    v_counter NUMBER := 1;
BEGIN
    WHILE v_counter <= 5 LOOP
        DBMS_OUTPUT.PUT_LINE('Count: ' || v_counter);
        v_counter := v_counter + 1;
    END LOOP;
END;
```
**Explanation**: Continues to execute as long as the specified condition is true.

---

## **4. Cursors**

### 4.1 Implicit Cursor

**Example**:

```sql
BEGIN
    INSERT INTO employees (id, name) VALUES (1, 'John Doe');
    DBMS_OUTPUT.PUT_LINE('Rows affected: ' || SQL%ROWCOUNT);
END;
```
**Explanation**: Implicit cursors are used for single SQL statements. `SQL%ROWCOUNT` returns the number of rows affected by the last statement.

### 4.2 Explicit Cursor

```sql
DECLARE
    CURSOR c_emp IS SELECT name FROM employees;
    v_name employees.name%TYPE;
BEGIN
    OPEN c_emp;
    LOOP
        FETCH c_emp INTO v_name;
        EXIT WHEN c_emp%NOTFOUND;
        DBMS_OUTPUT.PUT_LINE('Employee Name: ' || v_name);
    END LOOP;
    CLOSE c_emp;
END;
```
**Explanation**: Explicit cursors provide more control over context and allow for complex queries. They must be opened, fetched from, and closed manually.

---

## **5. Exception Handling**

### 5.1 Basic Exception Handling

```sql
BEGIN
    -- Code that may raise an exception
    INSERT INTO employees (id, name) VALUES (NULL, 'John Doe');
EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Error: ' || SQLERRM);
END;
```
**Explanation**: Use the `EXCEPTION` section to handle errors. `SQLERRM` returns the error message associated with the most recent error.

### 5.2 Named Exception

```sql
DECLARE
    e_invalid_id EXCEPTION;
BEGIN
    -- Simulate an error
    RAISE e_invalid_id;
EXCEPTION
    WHEN e_invalid_id THEN
        DBMS_OUTPUT.PUT_LINE('Invalid ID error occurred.');
END;
```
**Explanation**: Named exceptions can be defined and raised explicitly.

---

## **6. Stored Procedures and Functions**

### 6.1 Creating a Procedure

```sql
CREATE OR REPLACE PROCEDURE proc_name (p_param IN NUMBER) AS
BEGIN
    DBMS_OUTPUT.PUT_LINE('Parameter value: ' || p_param);
END;
```
**Explanation**: Procedures are stored in the database and can be executed. Parameters can be defined as `IN`, `OUT`, or `IN OUT`.

### 6.2 Calling a Procedure

```sql
BEGIN
    proc_name(10);
END;
```
**Explanation**: Calls the stored procedure, passing a parameter.

### 6.3 Creating a Function

```sql
CREATE OR REPLACE FUNCTION func_name (p_param IN NUMBER) RETURN NUMBER AS
BEGIN
    RETURN p_param * 2;
END;
```
**Explanation**: Functions return a value and can be called in SQL statements.

### 6.4 Calling a Function

```sql
DECLARE
    v_result NUMBER;
BEGIN
    v_result := func_name(10);
    DBMS_OUTPUT.PUT_LINE('Result: ' || v_result);
END;
```
**Explanation**: Calls the function and stores the result in a variable.

---

## **7. Packages**

### 7.1 Creating a Package

```sql
CREATE OR REPLACE PACKAGE package_name AS
    PROCEDURE proc_one;
    FUNCTION func_one RETURN NUMBER;
END package_name;
```
**Explanation**: Packages are collections of related procedures and functions.

### 7.2 Creating Package Body

```sql
CREATE OR REPLACE PACKAGE BODY package_name AS
    PROCEDURE proc_one IS
    BEGIN
        DBMS_OUTPUT.PUT_LINE('Procedure One');
    END proc_one;

    FUNCTION func_one RETURN NUMBER IS
    BEGIN
        RETURN 1;
    END func_one;
END package_name;
```
**Explanation**: The package body contains the implementation of the package specifications.

### 7.3 Using a Package

```sql
BEGIN
    package_name.proc_one;
    DBMS_OUTPUT.PUT_LINE('Function result: ' || package_name.func_one);
END;
```
**Explanation**: Call the procedures and functions defined in a package.

---

## **8. Triggers**

### 8.1 Creating a Trigger

```sql
CREATE OR REPLACE TRIGGER trg_name
BEFORE INSERT ON employees
FOR EACH ROW
BEGIN
    :NEW.creation_date := SYSDATE;
END trg_name;
```
**Explanation**: Triggers are automatically executed in response to certain events on a table. In this example, the trigger sets the `creation_date` to the current date before inserting a new employee.

### 8.2 Types of Triggers

- **BEFORE**: Executes before the triggering event (INSERT, UPDATE, DELETE).
- **AFTER**: Executes after the triggering event.
- **INSTEAD OF**: Used for views to perform actions instead of the triggering event.

---

## **9. Dynamic SQL**

### 9.1 Using Dynamic SQL

```sql
DECLARE
    v_sql VARCHAR2(100);
BEGIN
    v_sql := 'INSERT INTO employees (id, name) VALUES (1, ''John Doe'')';
    EXECUTE IMMEDIATE v_sql;
END;
```
**Explanation**: Dynamic SQL allows for building and executing SQL statements at runtime.

---

## **10. Utilities and Built-in Packages**

### 10.1 DBMS_OUTPUT

- **Enable Output**
```sql
SET SERVEROUTPUT ON;
```
**Explanation**: Enables output from `DBMS_OUTPUT.PUT_LINE` to be displayed in the console.

### 10.2 DBMS_SQL Package

```sql
DECLARE
    v_cursor INTEGER;
BEGIN
    v_cursor := DBMS_SQL.OPEN_CURSOR;
    DBMS_SQL.PARSE(v_cursor, 'SELECT name FROM employees', DBMS_SQL.NATIVE);
    -- Further processing...
    DBMS_SQL.CLOSE_CURSOR(v_cursor);
END;
```
**Explanation**: The `DBMS_SQL` package provides an interface for dynamic SQL, allowing more complex SQL processing.

---

## **11. Additional Commands**

### 11.1 Describing Objects

```sql
DESCRIBE employees

;
```
**Explanation**: Displays the structure of a database object.

### 11.2 Committing Transactions

```sql
COMMIT;
```
**Explanation**: Saves all changes made during the current transaction.

### 11.3 Rolling Back Transactions

```sql
ROLLBACK;
```
**Explanation**: Reverts the database to the last committed state.

---

This cheat sheet covers many of the essential commands and structures in PL/SQL. You can modify and expand upon it based on your specific needs and use cases!
