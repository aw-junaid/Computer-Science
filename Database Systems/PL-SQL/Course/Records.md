In PL/SQL, **records** are composite data types that allow you to store a collection of related values of different types. A record is similar to a row in a database table, where each field or attribute of the record corresponds to a column in the table.

### **Creating a Record Type**

In PL/SQL, a record is defined using the `TYPE` keyword, followed by the record name and its structure (a list of fields and their data types). You can then declare variables of that type and use them to store related data.

There are two ways to work with records in PL/SQL:

1. **%ROWTYPE**: A special PL/SQL attribute that allows you to declare a record that has the same structure as a row in a database table or a cursor result set.
2. **USER-DEFINED RECORD TYPE**: A custom record type defined using the `TYPE` keyword, which allows you to define records with fields of varying data types.

---

### **1. Using `%ROWTYPE` to Declare a Record**

The `%ROWTYPE` attribute is used to define a record that holds a row of data from a table or a query result. The record will automatically have the same fields as the table or cursor.

#### **Example: Using `%ROWTYPE` for a Record**

```sql
DECLARE
   -- Declare a record to hold a row of the "employees" table
   v_employee employees%ROWTYPE;
BEGIN
   -- Fetch a single row into the record
   SELECT employee_id, first_name, last_name, salary
   INTO v_employee
   FROM employees
   WHERE employee_id = 101;
   
   -- Access and display the record's fields
   DBMS_OUTPUT.PUT_LINE('Employee ID: ' || v_employee.employee_id);
   DBMS_OUTPUT.PUT_LINE('Name: ' || v_employee.first_name || ' ' || v_employee.last_name);
   DBMS_OUTPUT.PUT_LINE('Salary: ' || v_employee.salary);
END;
```

In this example:
- `v_employee` is a record variable that holds a row from the `employees` table.
- Each field in the record corresponds to a column in the `employees` table (e.g., `employee_id`, `first_name`, etc.).

---

### **2. Creating a User-Defined Record Type**

You can also define your own custom record type using the `TYPE` keyword. This is useful when you want to group together different data types (e.g., string, number, date) into a single variable.

#### **Example: Defining and Using a User-Defined Record**

```sql
DECLARE
   -- Define a custom record type
   TYPE EmployeeRecord IS RECORD (
      emp_id      NUMBER,
      first_name  VARCHAR2(50),
      last_name   VARCHAR2(50),
      salary      NUMBER
   );

   -- Declare a record variable of the custom type
   v_employee EmployeeRecord;
BEGIN
   -- Assign values to the fields of the record
   v_employee.emp_id := 101;
   v_employee.first_name := 'John';
   v_employee.last_name := 'Doe';
   v_employee.salary := 5000;

   -- Access and display the record's fields
   DBMS_OUTPUT.PUT_LINE('Employee ID: ' || v_employee.emp_id);
   DBMS_OUTPUT.PUT_LINE('Name: ' || v_employee.first_name || ' ' || v_employee.last_name);
   DBMS_OUTPUT.PUT_LINE('Salary: ' || v_employee.salary);
END;
```

In this example:
- We define a custom record type `EmployeeRecord` with fields for employee ID, name, and salary.
- We then declare a variable `v_employee` of type `EmployeeRecord` and assign values to its fields.

---

### **3. Working with Records in Loops**

You can also use records inside loops, especially when working with cursors to fetch multiple rows.

#### **Example: Using a Record with a Cursor**

```sql
DECLARE
   -- Declare a record type based on the "employees" table structure
   TYPE EmployeeRecord IS RECORD (
      employee_id  employees.employee_id%TYPE,
      first_name   employees.first_name%TYPE,
      last_name    employees.last_name%TYPE
   );

   -- Declare a cursor for fetching employee data
   CURSOR emp_cursor IS
      SELECT employee_id, first_name, last_name
      FROM employees;

   -- Declare a variable of the record type
   v_employee EmployeeRecord;
BEGIN
   -- Open the cursor
   OPEN emp_cursor;

   -- Loop through the cursor and fetch rows into the record
   LOOP
      FETCH emp_cursor INTO v_employee.employee_id, v_employee.first_name, v_employee.last_name;
      EXIT WHEN emp_cursor%NOTFOUND;
      
      -- Display the data from the record
      DBMS_OUTPUT.PUT_LINE('Employee ID: ' || v_employee.employee_id || 
                           ', Name: ' || v_employee.first_name || ' ' || v_employee.last_name);
   END LOOP;

   -- Close the cursor
   CLOSE emp_cursor;
END;
```

In this example:
- We declare a custom record type `EmployeeRecord` that holds `employee_id`, `first_name`, and `last_name`.
- A cursor `emp_cursor` is used to fetch employee data, and the values are stored in the record `v_employee`.
- The loop fetches the data row by row, and the fields of the record are used to display the employee details.

---

### **4. Records in Procedures and Functions**

You can pass records as parameters to procedures and functions.

#### **Example: Passing Records to a Procedure**

```sql
CREATE OR REPLACE PROCEDURE print_employee_details (v_employee IN OUT EmployeeRecord) IS
BEGIN
   -- Display the employee's details
   DBMS_OUTPUT.PUT_LINE('Employee ID: ' || v_employee.emp_id);
   DBMS_OUTPUT.PUT_LINE('Name: ' || v_employee.first_name || ' ' || v_employee.last_name);
   DBMS_OUTPUT.PUT_LINE('Salary: ' || v_employee.salary);
END print_employee_details;
```

To call this procedure:

```sql
DECLARE
   TYPE EmployeeRecord IS RECORD (
      emp_id      NUMBER,
      first_name  VARCHAR2(50),
      last_name   VARCHAR2(50),
      salary      NUMBER
   );
   
   v_employee EmployeeRecord;
BEGIN
   -- Assign values to the record fields
   v_employee.emp_id := 101;
   v_employee.first_name := 'John';
   v_employee.last_name := 'Doe';
   v_employee.salary := 5000;
   
   -- Pass the record to the procedure
   print_employee_details(v_employee);
END;
```

In this example, we define a record type `EmployeeRecord` and pass it to the `print_employee_details` procedure, which prints the record’s fields.

---

### **5. Records in Collections**

You can also use records within collections (like arrays or tables) to group related data dynamically.

#### **Example: Using Records in a Nested Table**

```sql
DECLARE
   -- Define a custom record type for employees
   TYPE EmployeeRecord IS RECORD (
      emp_id      NUMBER,
      first_name  VARCHAR2(50),
      last_name   VARCHAR2(50)
   );
   
   -- Define a collection type of records
   TYPE EmployeeTable IS TABLE OF EmployeeRecord;
   
   -- Declare a variable of the collection type
   v_employees EmployeeTable := EmployeeTable();
BEGIN
   -- Add records to the collection
   v_employees.EXTEND(2);  -- Extend the collection to hold 2 records
   
   -- Populate the first record
   v_employees(1).emp_id := 101;
   v_employees(1).first_name := 'John';
   v_employees(1).last_name := 'Doe';
   
   -- Populate the second record
   v_employees(2).emp_id := 102;
   v_employees(2).first_name := 'Jane';
   v_employees(2).last_name := 'Smith';
   
   -- Loop through the collection and display the records
   FOR i IN 1..v_employees.COUNT LOOP
      DBMS_OUTPUT.PUT_LINE('Employee ID: ' || v_employees(i).emp_id ||
                           ', Name: ' || v_employees(i).first_name || ' ' || v_employees(i).last_name);
   END LOOP;
END;
```

In this example:
- We define a custom record type `EmployeeRecord`.
- We then define a collection (`EmployeeTable`) that holds multiple `EmployeeRecord` entries.
- We extend the collection to add records and loop through it to print employee details.

---

### **Best Practices for Using Records**

1. **Use `%ROWTYPE` for Tables and Cursors**: When working with database rows or cursor result sets, `%ROWTYPE` is a convenient and efficient way to create a record that matches the structure of the table or query result.
2. **Define User-Defined Records When Necessary**: When you need to store related data of different types that don’t correspond to a table or cursor structure, define custom record types.
3. **Avoid Excessive Record Nesting**: While it’s possible to nest records within other records, this can make your code harder to maintain. Use it judiciously.
4. **Pass Records to Procedures**: You can pass records to procedures or functions to reduce the need for multiple parameters and simplify your code.

---

