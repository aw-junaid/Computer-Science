In PL/SQL, **triggers** are special types of stored procedures that are automatically executed (or "triggered") by the database in response to specific events or changes in the database. These events are usually DML (Data Manipulation Language) operations like `INSERT`, `UPDATE`, or `DELETE`, but they can also respond to other database activities such as database startup or user login.

### **Trigger Types in PL/SQL**

There are several types of triggers in PL/SQL, each serving a different purpose:

1. **DML Triggers**: These triggers respond to data changes (e.g., `INSERT`, `UPDATE`, `DELETE`).
2. **DDL Triggers**: These are triggered by Data Definition Language events such as `CREATE`, `ALTER`, or `DROP`.
3. **LOGON and LOGOFF Triggers**: These are triggered when a user logs on or logs off from the database.
4. **Compound Triggers**: These allow multiple actions to be grouped together in a single trigger, providing a way to manage complex triggering logic.

---

### **Basic Syntax for DML Triggers**

A **DML trigger** is typically created on a table or a view, and it can be associated with one or more of the following events:

- `BEFORE INSERT`: Executes before an `INSERT` operation.
- `AFTER INSERT`: Executes after an `INSERT` operation.
- `BEFORE UPDATE`: Executes before an `UPDATE` operation.
- `AFTER UPDATE`: Executes after an `UPDATE` operation.
- `BEFORE DELETE`: Executes before a `DELETE` operation.
- `AFTER DELETE`: Executes after a `DELETE` operation.

#### **General Syntax for a DML Trigger**

```sql
CREATE [OR REPLACE] TRIGGER trigger_name
   {BEFORE | AFTER} {INSERT | UPDATE | DELETE}
   ON table_name
   [FOR EACH ROW]
   DECLARE
      -- Declarations (if necessary)
   BEGIN
      -- Trigger logic goes here
   END;
```

- `trigger_name`: The name of the trigger.
- `BEFORE` or `AFTER`: Defines whether the trigger fires before or after the DML operation.
- `INSERT`, `UPDATE`, or `DELETE`: The event that triggers the action.
- `table_name`: The table (or view) on which the trigger is defined.
- `FOR EACH ROW`: Indicates that the trigger is row-level (executes for each row affected by the DML operation). If omitted, the trigger is statement-level (executes once for the entire statement).

---

### **Example: `AFTER INSERT` Trigger**

This trigger will automatically log the insertion of a new row into the `employees` table into a `log_table`.

```sql
CREATE OR REPLACE TRIGGER log_employee_insert
AFTER INSERT ON employees
FOR EACH ROW
DECLARE
   v_log_message VARCHAR2(100);
BEGIN
   v_log_message := 'New employee inserted: ' || :NEW.first_name || ' ' || :NEW.last_name;
   
   -- Insert the log message into a log table
   INSERT INTO log_table (log_message, log_date)
   VALUES (v_log_message, SYSDATE);
END;
```

Explanation:
- `:NEW` is a keyword used to reference the new values of the inserted row. It’s used to access the values of the columns after an `INSERT`.
- The trigger is fired after a new row is inserted into the `employees` table, and it logs the insert into a separate `log_table`.

---

### **Example: `BEFORE UPDATE` Trigger**

This trigger will prevent the salary of an employee from being updated to a value less than 1000.

```sql
CREATE OR REPLACE TRIGGER prevent_low_salary
BEFORE UPDATE ON employees
FOR EACH ROW
BEGIN
   IF :NEW.salary < 1000 THEN
      RAISE_APPLICATION_ERROR(-20001, 'Salary cannot be less than 1000.');
   END IF;
END;
```

Explanation:
- `:NEW` refers to the new value of the `salary` column that is being updated.
- If the new salary is less than 1000, the trigger raises an error, preventing the update from taking place.

---

### **Example: `AFTER DELETE` Trigger**

This trigger will log whenever a row is deleted from the `employees` table.

```sql
CREATE OR REPLACE TRIGGER log_employee_delete
AFTER DELETE ON employees
FOR EACH ROW
DECLARE
   v_log_message VARCHAR2(100);
BEGIN
   v_log_message := 'Employee deleted: ' || :OLD.first_name || ' ' || :OLD.last_name;
   
   -- Insert the log message into a log table
   INSERT INTO log_table (log_message, log_date)
   VALUES (v_log_message, SYSDATE);
END;
```

Explanation:
- `:OLD` is used to reference the old value of the column before the delete operation.
- The trigger logs the deleted employee's name into a `log_table`.

---

### **Trigger Timing: BEFORE vs. AFTER**

- **`BEFORE` Triggers**: These are executed before the DML operation. You can use them to modify the data before it’s committed to the database, such as altering the value of `:NEW` or performing checks before the operation.
  
- **`AFTER` Triggers**: These are executed after the DML operation. They are useful for tasks like auditing, logging, or enforcing business rules that can only be checked after the operation has occurred.

---

### **Trigger Scope: Row-Level vs. Statement-Level**

- **Row-Level Triggers**: The trigger is executed once for each row affected by the DML operation. You define a row-level trigger with the `FOR EACH ROW` clause.

  Example:
  ```sql
  CREATE OR REPLACE TRIGGER check_salary
  BEFORE UPDATE ON employees
  FOR EACH ROW
  BEGIN
     IF :NEW.salary < 1000 THEN
        RAISE_APPLICATION_ERROR(-20002, 'Salary cannot be less than 1000.');
     END IF;
  END;
  ```

- **Statement-Level Triggers**: The trigger is executed once for the entire DML statement, regardless of how many rows are affected. You don’t need the `FOR EACH ROW` clause.

  Example:
  ```sql
  CREATE OR REPLACE TRIGGER log_update
  AFTER UPDATE ON employees
  BEGIN
     -- Log the fact that an update has occurred
     INSERT INTO log_table (log_message, log_date)
     VALUES ('Employee record updated', SYSDATE);
  END;
  ```

---

### **Disabling and Enabling Triggers**

You can disable and enable triggers at any time using the following commands:

- **Disable a Trigger**:
  ```sql
  ALTER TRIGGER trigger_name DISABLE;
  ```

- **Enable a Trigger**:
  ```sql
  ALTER TRIGGER trigger_name ENABLE;
  ```

---

### **Compound Triggers**

PL/SQL allows you to create **compound triggers**, which are used to group multiple triggering actions in a single trigger. This is useful to avoid the complication of managing separate triggers that could conflict with each other. A compound trigger is particularly helpful when you need to manage "before" and "after" actions within a single trigger.

#### **Example: Compound Trigger**

```sql
CREATE OR REPLACE TRIGGER compound_trigger_example
FOR INSERT, UPDATE, DELETE ON employees
COMPOUND TRIGGER
   -- Declare variables to hold values
   v_before_salary NUMBER;
   v_after_salary NUMBER;

   -- BEFORE trigger logic
   BEFORE STATEMENT IS
   BEGIN
      NULL;  -- You can put logic here that runs before the statement
   END BEFORE STATEMENT;

   -- BEFORE ROW trigger logic
   BEFORE EACH ROW IS
   BEGIN
      v_before_salary := :OLD.salary;  -- Old salary before update
   END BEFORE EACH ROW;

   -- AFTER ROW trigger logic
   AFTER EACH ROW IS
   BEGIN
      v_after_salary := :NEW.salary;  -- New salary after update
   END AFTER EACH ROW;

   -- AFTER STATEMENT logic
   AFTER STATEMENT IS
   BEGIN
      -- Logic to execute after the statement completes
      DBMS_OUTPUT.PUT_LINE('Before Salary: ' || v_before_salary || ', After Salary: ' || v_after_salary);
   END AFTER STATEMENT;
END compound_trigger_example;
```

Explanation:
- The compound trigger handles both `BEFORE` and `AFTER` logic.
- The trigger is fired for both `INSERT`, `UPDATE`, and `DELETE` statements on the `employees` table.
- Variables are used to capture old and new values, and the logic is grouped into `BEFORE STATEMENT`, `BEFORE EACH ROW`, `AFTER EACH ROW`, and `AFTER STATEMENT` sections.

---

### **Trigger Best Practices**

1. **Minimize the use of triggers**: While triggers are powerful, they can complicate database maintenance. Use them sparingly, especially for tasks that can be handled by application logic.
2. **Avoid side effects**: Triggers can introduce side effects, such as modifying data in unexpected ways. Always ensure that the trigger logic is transparent and well-documented.
3. **Use compound triggers**: If you need to manage both `BEFORE` and `AFTER` logic, consider using compound triggers to keep your code organized and avoid conflicts.
4. **Test triggers thoroughly**: Since triggers are automatic, make sure they’re well-tested to avoid unexpected results.

---

