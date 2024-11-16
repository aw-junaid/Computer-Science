In PL/SQL, a **procedure** is a named block of code that performs a specific task or a set of tasks. Procedures are used to encapsulate logic that can be reused multiple times within the same session or across different applications. They can accept parameters and return values, making them flexible for a variety of tasks.

### **Structure of a Procedure**

A PL/SQL procedure has the following structure:

```sql
CREATE OR REPLACE PROCEDURE procedure_name
   [parameter_list]
IS
   -- Declarations (optional)
BEGIN
   -- Execution logic
END procedure_name;
```

- **procedure_name**: The name of the procedure.
- **parameter_list** (optional): A comma-separated list of parameters (input or output) for the procedure.
- **IS**: Marks the beginning of the procedure's logic.
- **Declarations** (optional): Variables, cursors, and other structures needed for the procedure.
- **BEGIN...END**: The executable section where the procedure's logic resides.

---

### **Procedure Types:**
1. **Procedures with Input Parameters (IN)**: These accept values when the procedure is called.
2. **Procedures with Output Parameters (OUT)**: These return values back to the calling environment.
3. **Procedures with Both IN and OUT Parameters**: These can accept and return values.

---

### **Basic Example of a Procedure**

A simple procedure that prints a message to the console.

```sql
CREATE OR REPLACE PROCEDURE greet_user IS
BEGIN
   DBMS_OUTPUT.PUT_LINE('Hello, User!');
END greet_user;
```

- This procedure does not take any parameters and simply prints a message.

To **execute** this procedure, you would use:
```sql
BEGIN
   greet_user;
END;
```

---

### **Example with Input Parameters**

A procedure that accepts an employee's name and salary and prints a greeting.

```sql
CREATE OR REPLACE PROCEDURE greet_employee (p_name IN VARCHAR2, p_salary IN NUMBER) IS
BEGIN
   DBMS_OUTPUT.PUT_LINE('Hello, ' || p_name || '! Your salary is ' || p_salary);
END greet_employee;
```

- **p_name**: An input parameter of type `VARCHAR2` for the employee’s name.
- **p_salary**: An input parameter of type `NUMBER` for the employee’s salary.

To **call** this procedure:
```sql
BEGIN
   greet_employee('John Doe', 5000);
END;
```

---

### **Example with Output Parameters**

A procedure that calculates the total salary based on a given basic salary and bonus, and returns the result.

```sql
CREATE OR REPLACE PROCEDURE calculate_total_salary (p_basic IN NUMBER, p_bonus IN NUMBER, p_total_salary OUT NUMBER) IS
BEGIN
   p_total_salary := p_basic + p_bonus;
END calculate_total_salary;
```

- **p_basic**: An input parameter for the basic salary.
- **p_bonus**: An input parameter for the bonus.
- **p_total_salary**: An output parameter to return the total salary.

To **call** this procedure and capture the output:
```sql
DECLARE
   v_total_salary NUMBER;
BEGIN
   calculate_total_salary(4000, 500, v_total_salary);
   DBMS_OUTPUT.PUT_LINE('Total Salary: ' || v_total_salary);
END;
```

---

### **Example with Both IN and OUT Parameters**

A procedure that takes an employee's name and salary, and then updates the salary.

```sql
CREATE OR REPLACE PROCEDURE update_salary (p_name IN VARCHAR2, p_new_salary IN NUMBER, p_status OUT VARCHAR2) IS
BEGIN
   UPDATE employees
   SET salary = p_new_salary
   WHERE employee_name = p_name;

   IF SQL%ROWCOUNT > 0 THEN
      p_status := 'Salary updated successfully';
   ELSE
      p_status := 'Employee not found';
   END IF;
END update_salary;
```

- **p_name**: An input parameter for the employee's name.
- **p_new_salary**: An input parameter for the new salary.
- **p_status**: An output parameter to return the status message.

To **call** this procedure:
```sql
DECLARE
   v_status VARCHAR2(100);
BEGIN
   update_salary('John Doe', 6000, v_status);
   DBMS_OUTPUT.PUT_LINE(v_status);
END;
```

---

### **Using `PRAGMA EXCEPTION_INIT` for Custom Exceptions**

You can use exceptions to handle errors within a procedure. Here’s an example of a procedure with error handling.

```sql
CREATE OR REPLACE PROCEDURE update_salary (p_name IN VARCHAR2, p_new_salary IN NUMBER) IS
   e_employee_not_found EXCEPTION;
   PRAGMA EXCEPTION_INIT(e_employee_not_found, -20001);
BEGIN
   UPDATE employees
   SET salary = p_new_salary
   WHERE employee_name = p_name;

   IF SQL%ROWCOUNT = 0 THEN
      RAISE e_employee_not_found;
   END IF;
   
   DBMS_OUTPUT.PUT_LINE('Salary updated successfully');
EXCEPTION
   WHEN e_employee_not_found THEN
      DBMS_OUTPUT.PUT_LINE('Employee not found');
END update_salary;
```

- **Custom Exception**: `e_employee_not_found` is raised if no rows are updated, indicating the employee was not found.

---

### **Procedure with Multiple Parameters and Loop**

A procedure that calculates the total salary for all employees in a specific department.

```sql
CREATE OR REPLACE PROCEDURE calculate_department_salary (p_dept_id IN NUMBER) IS
   v_total_salary NUMBER := 0;
BEGIN
   FOR rec IN (SELECT salary FROM employees WHERE department_id = p_dept_id) LOOP
      v_total_salary := v_total_salary + rec.salary;
   END LOOP;

   DBMS_OUTPUT.PUT_LINE('Total salary for department ' || p_dept_id || ' is: ' || v_total_salary);
END calculate_department_salary;
```

- This procedure iterates through all employees in a specified department and calculates the total salary.

To **call** the procedure:
```sql
BEGIN
   calculate_department_salary(10);
END;
```

---

### **Procedure with Default Parameter Values**

You can define default values for parameters in procedures. This is useful when the parameter may be optional.

```sql
CREATE OR REPLACE PROCEDURE greet_user (p_name IN VARCHAR2 DEFAULT 'Guest') IS
BEGIN
   DBMS_OUTPUT.PUT_LINE('Hello, ' || p_name);
END greet_user;
```

- If you don’t pass a name, it defaults to `'Guest'`.

To **call** this procedure with a default:
```sql
BEGIN
   greet_user; -- Outputs: Hello, Guest
END;
```

Or you can pass a name:
```sql
BEGIN
   greet_user('Alice'); -- Outputs: Hello, Alice
END;
```

---

### **Privileges and Security for Procedures**

When creating and executing procedures, ensure the following:

1. **EXECUTE privilege**: The user must have EXECUTE privileges on the procedure to call it.
2. **GRANTING Privileges**:
   ```sql
   GRANT EXECUTE ON procedure_name TO user_or_role;
   ```
3. **Schema-bound procedures**: If the procedure is created in a different schema, you need to reference it as `schema_name.procedure_name`.

---

### **Dropping Procedures**

To drop a procedure from the database, you can use the `DROP` statement:

```sql
DROP PROCEDURE procedure_name;
```

---

### **Best Practices**

1. **Use Procedures for Reusability**: If a block of logic is used repeatedly, encapsulate it in a procedure for easier maintenance and readability.
2. **Exception Handling**: Always handle exceptions in procedures to prevent unexpected behavior and provide meaningful error messages.
3. **Document Your Procedures**: Add comments within the code to describe its purpose, parameters, and behavior.
4. **Optimize for Performance**: Avoid using procedures that repeatedly perform complex operations on large datasets. Instead, aim to perform operations in bulk.
5. **Use Parameterized Procedures for Flexibility**: When writing procedures that interact with database records, ensure they can handle different sets of input through parameters.

---

### **Practice Problems**

1. Write a procedure that:
   - Accepts an employee ID and returns the employee’s name and salary.
   
2. Create a procedure that:
   - Takes a department ID as input and outputs the total number of employees and their average salary.

3. Write a procedure that:
   - Accepts a product ID and updates its price. It should return a message indicating whether the update was successful.

