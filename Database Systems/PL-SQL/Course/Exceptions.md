In PL/SQL, **exceptions** are used to handle errors that occur during the execution of a PL/SQL block. Exception handling allows you to deal with runtime errors gracefully, instead of letting the program fail unexpectedly. PL/SQL provides mechanisms to define and raise exceptions, as well as to handle predefined and user-defined exceptions.

### **Types of Exceptions in PL/SQL**

1. **Predefined Exceptions**: These are built-in exceptions provided by Oracle, such as `NO_DATA_FOUND`, `TOO_MANY_ROWS`, `ZERO_DIVIDE`, etc.
2. **User-Defined Exceptions**: These are custom exceptions that you define in your PL/SQL block.
3. **Implicit vs. Explicit Exceptions**:
   - **Implicit Exceptions**: These are automatically raised by Oracle when certain errors occur (e.g., divide by zero, no data found).
   - **Explicit Exceptions**: These are explicitly raised using the `RAISE` statement in your PL/SQL code.

---

### **1. Predefined Exceptions**

PL/SQL provides several predefined exceptions that correspond to common errors in Oracle databases. These exceptions are automatically raised by Oracle when specific conditions occur during execution.

#### **Common Predefined Exceptions**

- **`NO_DATA_FOUND`**: Raised when a SELECT INTO query returns no rows.
- **`TOO_MANY_ROWS`**: Raised when a SELECT INTO query returns more than one row.
- **`ZERO_DIVIDE`**: Raised when an attempt to divide by zero occurs.
- **`VALUE_ERROR`**: Raised when an arithmetic error or a conversion error occurs (e.g., trying to assign a value that’s too large for a variable).
- **`DUP_VAL_ON_INDEX`**: Raised when a unique constraint is violated during an INSERT or UPDATE operation.
- **`LOGIN_DENIED`**: Raised when login attempts fail due to invalid credentials.

#### **Example: Handling a Predefined Exception**

```sql
DECLARE
   v_salary NUMBER;
BEGIN
   -- Attempt to divide by zero
   v_salary := 100 / 0;  -- This will cause a ZERO_DIVIDE error
EXCEPTION
   WHEN ZERO_DIVIDE THEN
      DBMS_OUTPUT.PUT_LINE('Error: Attempted to divide by zero.');
END;
```

In this example, the `ZERO_DIVIDE` exception is raised when attempting to divide by zero. The exception handler catches the error and displays an appropriate message.

---

### **2. User-Defined Exceptions**

You can define your own exceptions to handle specific situations that may arise in your application. User-defined exceptions allow you to define custom error conditions that are relevant to your business logic.

#### **Declaring a User-Defined Exception**

You can declare a user-defined exception using the `EXCEPTION` keyword. After declaring an exception, you can raise it using the `RAISE` statement and handle it in an `EXCEPTION` block.

#### **Example: Declaring and Using a User-Defined Exception**

```sql
DECLARE
   -- Declare a user-defined exception
   e_invalid_salary EXCEPTION;
   v_salary NUMBER := -1000;  -- Example of an invalid salary
BEGIN
   -- Check if the salary is negative
   IF v_salary < 0 THEN
      RAISE e_invalid_salary;  -- Raise the user-defined exception
   END IF;
   
   DBMS_OUTPUT.PUT_LINE('Salary is valid: ' || v_salary);
EXCEPTION
   WHEN e_invalid_salary THEN
      DBMS_OUTPUT.PUT_LINE('Error: Invalid salary value. Salary cannot be negative.');
END;
```

In this example:
- A user-defined exception `e_invalid_salary` is declared.
- The exception is raised when a negative salary value is encountered.
- The exception is caught and handled in the `EXCEPTION` block, where an appropriate error message is displayed.

---

### **3. Exception Propagation**

Exceptions can be propagated from a subprogram (like a procedure or function) to the calling block. If an exception is raised in a nested block and not handled there, it will propagate up to the outer block until it’s caught or the program terminates.

#### **Example: Exception Propagation**

```sql
CREATE OR REPLACE PROCEDURE check_salary(p_salary IN NUMBER) IS
BEGIN
   IF p_salary < 0 THEN
      RAISE_APPLICATION_ERROR(-20001, 'Salary cannot be negative');
   END IF;
   DBMS_OUTPUT.PUT_LINE('Salary is valid: ' || p_salary);
END;

DECLARE
   v_salary NUMBER := -1000;
BEGIN
   check_salary(v_salary);  -- Call the procedure with an invalid salary
EXCEPTION
   WHEN OTHERS THEN
      DBMS_OUTPUT.PUT_LINE('Error: ' || SQLERRM);
END;
```

In this example:
- The `check_salary` procedure raises an exception if the salary is negative.
- The exception propagates to the outer block, where it is handled by the `WHEN OTHERS` exception handler.

---

### **4. Exception Handling Block**

An exception handler in PL/SQL is defined inside the `EXCEPTION` section of a PL/SQL block. The structure of the block is as follows:

```sql
DECLARE
   -- Variable declarations
BEGIN
   -- Executable statements
EXCEPTION
   WHEN exception_name1 THEN
      -- Exception handling code for exception_name1
   WHEN exception_name2 THEN
      -- Exception handling code for exception_name2
   WHEN OTHERS THEN
      -- Catch all other exceptions (optional)
END;
```

The `EXCEPTION` block handles exceptions raised during the execution of the code in the `BEGIN` section. You can have multiple `WHEN` clauses to handle different types of exceptions. The `OTHERS` handler is a catch-all for any exception not explicitly handled.

---

### **5. The `RAISE` Statement**

The `RAISE` statement is used to raise exceptions. It can be used to raise a predefined exception, a user-defined exception, or to re-raise an exception that has been caught.

#### **Raising a Predefined Exception**

```sql
BEGIN
   IF some_condition THEN
      RAISE NO_DATA_FOUND;  -- Raise a predefined exception
   END IF;
END;
```

#### **Re-Raising an Exception**

If you catch an exception and decide to propagate it again, you can re-raise it with the `RAISE` statement.

```sql
BEGIN
   -- Some code
EXCEPTION
   WHEN NO_DATA_FOUND THEN
      -- Handle exception
      RAISE;  -- Re-raise the same exception to propagate it further
END;
```

---

### **6. The `SQLCODE` and `SQLERRM` Functions**

When an exception is raised, you can use the `SQLCODE` and `SQLERRM` functions to retrieve the error code and error message associated with the exception.

- **`SQLCODE`**: Returns the numeric error code of the exception.
- **`SQLERRM`**: Returns the error message associated with the exception.

#### **Example: Using `SQLCODE` and `SQLERRM`**

```sql
DECLARE
   v_salary NUMBER;
BEGIN
   -- Cause a divide by zero error
   v_salary := 100 / 0;
EXCEPTION
   WHEN ZERO_DIVIDE THEN
      DBMS_OUTPUT.PUT_LINE('Error Code: ' || SQLCODE);
      DBMS_OUTPUT.PUT_LINE('Error Message: ' || SQLERRM);
END;
```

This example will print the error code and message when the `ZERO_DIVIDE` exception is raised.

---

### **7. Handling Multiple Exceptions**

You can handle multiple exceptions in a single block. For example, you can handle both the `NO_DATA_FOUND` and `TOO_MANY_ROWS` exceptions separately:

#### **Example: Handling Multiple Exceptions**

```sql
DECLARE
   v_emp_id NUMBER := 9999;  -- Example of an employee ID that may not exist
   v_salary NUMBER;
BEGIN
   -- Attempt to fetch employee salary
   SELECT salary
   INTO v_salary
   FROM employees
   WHERE employee_id = v_emp_id;
   
EXCEPTION
   WHEN NO_DATA_FOUND THEN
      DBMS_OUTPUT.PUT_LINE('Error: No employee found with ID ' || v_emp_id);
   WHEN TOO_MANY_ROWS THEN
      DBMS_OUTPUT.PUT_LINE('Error: More than one employee found with ID ' || v_emp_id);
   WHEN OTHERS THEN
      DBMS_OUTPUT.PUT_LINE('Unexpected error: ' || SQLERRM);
END;
```

In this example, different exceptions are handled specifically: if no rows are found, a `NO_DATA_FOUND` error is raised; if more than one row is returned, a `TOO_MANY_ROWS` error is raised. Any other exception is handled with the `OTHERS` handler.

---

### **Best Practices for Exception Handling**

1. **Use Specific Exception Handlers**: Whenever possible, handle specific exceptions (like `NO_DATA_FOUND`, `TOO_MANY_ROWS`) rather than using a generic `WHEN OTHERS`.
2. **Avoid Using `WHEN OTHERS` Unnecessarily**: Using `WHEN OTHERS` without logging the error or re-raising it can hide underlying issues in your application. It’s best to log or raise the error to keep track of it.
3. **Handle Exceptions in Subprograms**: When writing functions and procedures, handle exceptions locally and propagate them to higher levels if necessary.
4. **Raise Custom Exceptions for Business Logic**: Define custom exceptions to handle specific business rules (e.g., invalid input or domain-specific errors).

---

