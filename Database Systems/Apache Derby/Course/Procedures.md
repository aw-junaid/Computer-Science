In Apache Derby, **procedures** are a set of SQL statements that are grouped together and stored in the database. A procedure allows you to encapsulate business logic or repetitive tasks in the database, making it reusable and easier to manage. Procedures in Derby are written in **SQL** or **Java** (using stored Java procedures), but for simplicity, we'll focus on SQL procedures.

### Creating a Procedure

To create a stored procedure in Apache Derby, you use the `CREATE PROCEDURE` statement. The syntax for creating a simple SQL procedure is as follows:

```sql
CREATE PROCEDURE procedure_name
[parameter_list]
LANGUAGE SQL
[DETERMINISTIC | NOT DETERMINISTIC]
MODIFIES SQL DATA
[external_name];
```

- **`procedure_name`**: The name of the procedure.
- **`parameter_list`**: A comma-separated list of parameters (input/output) the procedure will use. Parameters can be of type `IN`, `OUT`, or `INOUT`.
  - **`IN`**: An input parameter; the procedure can read it, but it cannot modify it.
  - **`OUT`**: An output parameter; the procedure can modify it and return a value.
  - **`INOUT`**: A parameter that is both input and output, allowing the procedure to read and modify its value.
- **`LANGUAGE SQL`**: Indicates that the procedure is written in SQL. This is optional in Apache Derby as it defaults to SQL.
- **`DETERMINISTIC | NOT DETERMINISTIC`**: Specifies whether the procedure always produces the same result for the same input parameters. This is more relevant for optimization, but is not required in many cases.
- **`MODIFIES SQL DATA`**: Indicates that the procedure will modify data (e.g., performing INSERT, UPDATE, DELETE operations).
- **`external_name`**: This is used when you are writing a Java-based procedure, pointing to the Java method to be executed.

### Example 1: Creating a Simple SQL Procedure

Here’s an example of a simple SQL procedure that accepts two input parameters, performs an operation, and returns a value:

```sql
CREATE PROCEDURE get_total_salary (IN dept_id INT, OUT total_salary DECIMAL)
LANGUAGE SQL
MODIFIES SQL DATA
BEGIN
    SELECT SUM(salary) 
    INTO total_salary
    FROM employees
    WHERE department_id = dept_id;
END;
```

- This procedure, named `get_total_salary`, takes an `IN` parameter (`dept_id`), which is the department ID, and an `OUT` parameter (`total_salary`), which will hold the total salary of employees in the specified department.
- It uses a `SELECT` statement to calculate the sum of salaries for a given department and stores the result in the `total_salary` output parameter.

### Example 2: Creating a Procedure with Multiple Parameters

This example demonstrates a procedure with both input and output parameters:

```sql
CREATE PROCEDURE update_employee_salary (IN emp_id INT, IN new_salary DECIMAL, OUT old_salary DECIMAL)
LANGUAGE SQL
MODIFIES SQL DATA
BEGIN
    -- Get the old salary of the employee
    SELECT salary INTO old_salary
    FROM employees
    WHERE employee_id = emp_id;

    -- Update the salary of the employee
    UPDATE employees
    SET salary = new_salary
    WHERE employee_id = emp_id;
END;
```

- This procedure, `update_employee_salary`, takes an `IN` parameter (`emp_id` for employee ID) and another `IN` parameter (`new_salary` for the new salary).
- It also has an `OUT` parameter (`old_salary`), which stores the previous salary of the employee.
- The procedure first retrieves the old salary of the employee using a `SELECT` query, and then updates the salary in the `employees` table.

### Calling a Stored Procedure

Once a stored procedure is created, you can call it using the `CALL` statement. The syntax for calling a procedure is:

```sql
CALL procedure_name (parameter_list);
```

For example, to call the `get_total_salary` procedure:

```sql
CALL get_total_salary(5, ?);
```

- Here, `5` is the `dept_id` value passed as an argument, and `?` represents an output parameter that will receive the total salary.

If you're calling the procedure from a Java program, you would use `CallableStatement` to execute the stored procedure.

### Example of Calling a Procedure with OUT Parameter

When calling a procedure with an output parameter, you would use a placeholder (`?`) for the output parameter and retrieve its value after execution.

```sql
DECLARE total_salary DECIMAL;

CALL get_total_salary(5, total_salary);

SELECT total_salary FROM SYSIBM.SYSDUMMY1;
```

Here:
- The `CALL` statement invokes the `get_total_salary` procedure with a department ID of `5`, and the total salary for that department is returned in the `total_salary` variable.

### Modifying an Existing Procedure

To modify an existing procedure, you typically need to drop and recreate it, as Apache Derby does not support `ALTER PROCEDURE`. The syntax for dropping a procedure is:

```sql
DROP PROCEDURE procedure_name;
```

After dropping the procedure, you can create a new version with the updated logic.

### Dropping a Procedure

If you no longer need a procedure, you can remove it from the database using the `DROP PROCEDURE` statement:

```sql
DROP PROCEDURE procedure_name;
```

### Exception Handling in Procedures

In Apache Derby, stored procedures do not have advanced exception handling capabilities (like those available in PL/SQL or T-SQL), but you can handle basic SQL errors using the `SQLCODE` system variable in Java-based procedures or by using error-handling in your application logic.

### Java-Based Stored Procedures

While Apache Derby provides support for SQL-based procedures, you can also create stored procedures using Java. A Java-based procedure is defined by implementing a method in a Java class, compiling the class, and then linking the class to a stored procedure.

Here’s a basic overview of how to create a Java-based stored procedure:

1. **Write a Java method** to be executed as a stored procedure.
2. **Compile the Java class** and add it to the Derby database’s classpath.
3. **Create the stored procedure** by referencing the Java class and method.

Example of Java-based stored procedure:

```java
public class MyStoredProcedure {
    public static void updateEmployeeSalary(int emp_id, double new_salary) {
        // JDBC code to update employee salary
    }
}
```

To register the procedure in Derby:

```sql
CREATE PROCEDURE update_employee_salary (IN emp_id INT, IN new_salary DECIMAL)
    EXTERNAL NAME 'com.mycompany.MyStoredProcedure.updateEmployeeSalary'
    LANGUAGE JAVA PARAMETER STYLE JAVA;
```

This links the `updateEmployeeSalary` method from your Java class to the stored procedure in the Derby database.

### Conclusion

Stored procedures in Apache Derby allow you to encapsulate and reuse SQL logic directly within the database, providing better performance for repetitive tasks and complex operations. You can create procedures that accept input parameters and return output values, manage transactions, and help enforce business logic. Derby also supports Java-based stored procedures, which provide more advanced features and flexibility when necessary. However, keep in mind that the SQL-based procedures in Derby are relatively simple compared to other databases like Oracle or SQL Server.
