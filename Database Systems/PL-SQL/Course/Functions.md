In PL/SQL, a **function** is a named block of code that performs a specific task and returns a value. Like procedures, functions encapsulate logic and can accept parameters. The main difference between a procedure and a function is that a function always returns a value, while a procedure does not.

### **Structure of a Function**

The basic structure of a PL/SQL function is as follows:

```sql
CREATE OR REPLACE FUNCTION function_name
   (parameter_list)
   RETURN return_data_type
IS
   -- Declarations (optional)
BEGIN
   -- Execution logic
   RETURN value;  -- The return value of the function
END function_name;
```

- **function_name**: The name of the function.
- **parameter_list** (optional): A list of parameters that can be passed into the function. These parameters can be **IN**, **OUT**, or **IN OUT**.
- **RETURN return_data_type**: Specifies the datatype of the value that the function will return (e.g., `NUMBER`, `VARCHAR2`, etc.).
- **IS**: Marks the beginning of the function’s logic.
- **Declarations** (optional): You can declare variables, cursors, or other structures needed for the function.
- **BEGIN...END**: The executable section where the logic is written.
- **RETURN**: The value to be returned from the function.

---

### **Basic Example of a Function**

A simple function that takes two numbers and returns their sum:

```sql
CREATE OR REPLACE FUNCTION add_numbers (p_num1 IN NUMBER, p_num2 IN NUMBER)
   RETURN NUMBER
IS
BEGIN
   RETURN p_num1 + p_num2;
END add_numbers;
```

To **call** this function:

```sql
DECLARE
   v_result NUMBER;
BEGIN
   v_result := add_numbers(5, 10);
   DBMS_OUTPUT.PUT_LINE('The sum is: ' || v_result);
END;
```

---

### **Example with Input Parameters**

A function that accepts a string and returns its length:

```sql
CREATE OR REPLACE FUNCTION get_string_length (p_str IN VARCHAR2)
   RETURN NUMBER
IS
BEGIN
   RETURN LENGTH(p_str);
END get_string_length;
```

To **call** this function:

```sql
DECLARE
   v_length NUMBER;
BEGIN
   v_length := get_string_length('Hello, World!');
   DBMS_OUTPUT.PUT_LINE('The length of the string is: ' || v_length);
END;
```

---

### **Example with RETURNING a Result from a Query**

A function that calculates the total salary of an employee based on their employee ID:

```sql
CREATE OR REPLACE FUNCTION get_employee_salary (p_emp_id IN NUMBER)
   RETURN NUMBER
IS
   v_salary NUMBER;
BEGIN
   SELECT salary INTO v_salary
   FROM employees
   WHERE employee_id = p_emp_id;

   RETURN v_salary;
EXCEPTION
   WHEN NO_DATA_FOUND THEN
      RETURN 0;  -- Return 0 if no employee is found
END get_employee_salary;
```

To **call** this function:

```sql
DECLARE
   v_salary NUMBER;
BEGIN
   v_salary := get_employee_salary(101);
   DBMS_OUTPUT.PUT_LINE('Employee Salary: ' || v_salary);
END;
```

---

### **Example with Exception Handling**

A function that divides two numbers, with exception handling for division by zero:

```sql
CREATE OR REPLACE FUNCTION divide_numbers (p_num1 IN NUMBER, p_num2 IN NUMBER)
   RETURN NUMBER
IS
   v_result NUMBER;
BEGIN
   IF p_num2 = 0 THEN
      RAISE_APPLICATION_ERROR(-20001, 'Cannot divide by zero');
   END IF;
   
   v_result := p_num1 / p_num2;
   RETURN v_result;
EXCEPTION
   WHEN OTHERS THEN
      DBMS_OUTPUT.PUT_LINE('Error: ' || SQLERRM);
      RETURN NULL;  -- Return NULL in case of any error
END divide_numbers;
```

To **call** this function:

```sql
DECLARE
   v_result NUMBER;
BEGIN
   v_result := divide_numbers(10, 0);  -- This will raise an error
   DBMS_OUTPUT.PUT_LINE('Result: ' || v_result);
END;
```

---

### **Using Functions in SQL Queries**

PL/SQL functions can be used directly in SQL queries, just like built-in SQL functions.

For example, if you have a function that calculates the total salary of an employee:

```sql
SELECT employee_name, get_employee_salary(employee_id) AS salary
FROM employees;
```

This would return the name of the employee along with their calculated salary based on the `get_employee_salary` function.

---

### **Functions with OUT Parameters**

Unlike procedures, functions in PL/SQL **cannot have OUT parameters**. Functions are designed to return a single value through the `RETURN` keyword, while procedures can return values using OUT parameters.

However, you can simulate this by returning records or complex types, like objects or collections.

---

### **Function with Default Parameter Values**

You can define default values for function parameters. Here’s an example where the function calculates the area of a rectangle, and the default value for the width is `1` if it’s not provided.

```sql
CREATE OR REPLACE FUNCTION calculate_area (p_length IN NUMBER, p_width IN NUMBER DEFAULT 1)
   RETURN NUMBER
IS
BEGIN
   RETURN p_length * p_width;
END calculate_area;
```

To **call** this function with only the length:

```sql
DECLARE
   v_area NUMBER;
BEGIN
   v_area := calculate_area(5);  -- Uses default width of 1
   DBMS_OUTPUT.PUT_LINE('Area: ' || v_area);
END;
```

Or with both parameters:

```sql
DECLARE
   v_area NUMBER;
BEGIN
   v_area := calculate_area(5, 3);  -- Uses provided width of 3
   DBMS_OUTPUT.PUT_LINE('Area: ' || v_area);
END;
```

---

### **Returning Complex Data Types (Objects or Collections)**

You can use a function to return complex data types like collections or objects. For example, a function that returns a record or a table of employees.

```sql
CREATE OR REPLACE FUNCTION get_employee_details (p_emp_id IN NUMBER)
   RETURN employees%ROWTYPE
IS
   v_employee employees%ROWTYPE;
BEGIN
   SELECT * INTO v_employee
   FROM employees
   WHERE employee_id = p_emp_id;

   RETURN v_employee;
END get_employee_details;
```

To **call** this function and retrieve the employee details:

```sql
DECLARE
   v_employee employees%ROWTYPE;
BEGIN
   v_employee := get_employee_details(101);
   DBMS_OUTPUT.PUT_LINE('Employee Name: ' || v_employee.first_name || ' ' || v_employee.last_name);
END;
```

---

### **Privileges for Functions**

To execute a function in a PL/SQL block or query, the user must have the **EXECUTE privilege** on the function.

```sql
GRANT EXECUTE ON function_name TO user_or_role;
```

---

### **Dropping Functions**

To remove a function from the database, use the `DROP FUNCTION` command:

```sql
DROP FUNCTION function_name;
```

---

### **Best Practices for Functions**

1. **Keep Functions Short and Focused**: A function should do one thing and do it well. Avoid putting too much logic inside a function.
2. **Use Functions for Calculations and Retrieving Values**: Functions are ideal for tasks that require returning a value, such as calculations, string manipulations, or retrieving information from the database.
3. **Avoid Side Effects**: Functions should not modify the state of the database (such as inserting, updating, or deleting records). Functions should only return values.
4. **Handle Exceptions Gracefully**: Always include exception handling in functions, especially when dealing with external input or database operations.

---

### **Practice Problems**

1. Write a function that:
   - Takes a product ID as input and returns the product’s price.

2. Write a function that:
   - Accepts a department ID and returns the average salary of the employees in that department.

3. Create a function that:
   - Takes two dates as parameters and returns the number of days between them.

4. Write a function that:
   - Accepts an employee’s ID and returns whether the employee is eligible for a bonus based on their salary (e.g., salary > 5000 = eligible).

