**In Apache Derby, a **trigger** is a database object that automatically executes a specified set of actions when certain events (like **INSERT**, **UPDATE**, or **DELETE**) occur on a table. Triggers allow you to enforce business rules, data validation, and automate actions based on data changes.

Triggers can be used for various purposes such as:
- Enforcing data integrity rules.
- Automatically updating related tables when a record is inserted, updated, or deleted.
- Logging changes to sensitive data.
- Enforcing audit trails.

### Key Concepts of Triggers in Apache Derby

1. **Event**: The trigger is activated by a specific event such as an `INSERT`, `UPDATE`, or `DELETE`.
2. **Timing**: Triggers can be set to fire **before** or **after** the event. For example, a trigger can be executed before a new row is inserted (`BEFORE INSERT`), or after an update to a table (`AFTER UPDATE`).
3. **Action**: The action is the SQL code (usually a statement or a block of code) that is executed when the trigger is fired.

### Types of Triggers

1. **BEFORE Trigger**: Executes before the event (INSERT, UPDATE, DELETE) is performed on the table.
2. **AFTER Trigger**: Executes after the event is performed on the table.
3. **INSTEAD OF Trigger**: Executes in place of the event, allowing you to replace the default action (like inserting or updating data).

### Syntax for Creating a Trigger

The syntax for creating a trigger in Apache Derby is as follows:

```sql
CREATE TRIGGER trigger_name
{ BEFORE | AFTER | INSTEAD OF } 
{ INSERT | UPDATE | DELETE } 
ON table_name
[ REFERENCING { OLD AS old | NEW AS new } ]
FOR EACH ROW
[ WHEN (condition) ]
BEGIN
    -- Trigger action (SQL statements)
END;
```

- **`trigger_name`**: The name of the trigger.
- **`BEFORE | AFTER | INSTEAD OF`**: Specifies when the trigger is fired (before, after, or instead of the event).
- **`INSERT | UPDATE | DELETE`**: Specifies the event that triggers the action (INSERT, UPDATE, DELETE).
- **`table_name`**: The table on which the trigger is set.
- **`REFERENCING OLD AS old | NEW AS new`**: Defines aliases for the old and new row values. `OLD` refers to the row values before the change (for UPDATE and DELETE), and `NEW` refers to the row values after the change (for INSERT and UPDATE).
- **`FOR EACH ROW`**: Indicates that the trigger will execute once for each affected row.
- **`WHEN (condition)`**: An optional condition that limits when the trigger is fired (can be used with `BEFORE` and `AFTER` triggers).
- **Trigger action (SQL statements)**: The SQL code executed when the trigger is fired.

### Example 1: BEFORE INSERT Trigger

Suppose we have a table `employees` and we want to ensure that the salary is never set to a negative value. We can create a `BEFORE INSERT` trigger to check this condition before inserting the data:

```sql
CREATE TRIGGER check_salary_before_insert
BEFORE INSERT ON employees
FOR EACH ROW
BEGIN
    IF (NEW.salary < 0) THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Salary cannot be negative';
    END IF;
END;
```

- **`NEW.salary`**: Refers to the new value being inserted into the `salary` column.
- If the salary is less than 0, the trigger raises an error (`SIGNAL SQLSTATE`), preventing the insert from happening.

### Example 2: AFTER UPDATE Trigger

Suppose we want to track changes in the `employees` table. Whenever an employee’s salary is updated, we want to log the old and new salary values into a separate `salary_log` table. We can use an `AFTER UPDATE` trigger to perform this action:

```sql
CREATE TRIGGER log_salary_update
AFTER UPDATE ON employees
REFERENCING OLD AS old NEW AS new
FOR EACH ROW
BEGIN
    INSERT INTO salary_log (employee_id, old_salary, new_salary, update_time)
    VALUES (OLD.employee_id, OLD.salary, NEW.salary, CURRENT_TIMESTAMP);
END;
```

- This trigger fires **after** an update operation on the `employees` table.
- The `REFERENCING OLD AS old NEW AS new` clause allows us to access the old and new values of the row being updated.
- The `INSERT` statement logs the old and new salaries, along with the employee ID and the timestamp of the update, into the `salary_log` table.

### Example 3: BEFORE DELETE Trigger

Let’s say we want to prevent the deletion of an employee if their `salary` is above a certain amount (e.g., $100,000). We can create a `BEFORE DELETE` trigger to enforce this rule:

```sql
CREATE TRIGGER prevent_high_salary_deletion
BEFORE DELETE ON employees
FOR EACH ROW
BEGIN
    IF (OLD.salary > 100000) THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Cannot delete employee with salary greater than $100,000';
    END IF;
END;
```

- **`OLD.salary`**: Refers to the salary value of the employee before the deletion.
- If the salary is greater than $100,000, the trigger raises an error, preventing the deletion.

### Example 4: INSTEAD OF Trigger

An `INSTEAD OF` trigger allows you to override the default behavior of an event. For example, you can replace an `INSERT` operation with a custom behavior. Let’s say we want to insert a record into one table and another related table at the same time when a new employee is added:

```sql
CREATE TRIGGER insert_employee_with_details
INSTEAD OF INSERT ON employees
FOR EACH ROW
BEGIN
    INSERT INTO employee_details (employee_id, department)
    VALUES (NEW.employee_id, NEW.department);
    INSERT INTO employees (employee_id, name, salary)
    VALUES (NEW.employee_id, NEW.name, NEW.salary);
END;
```

- This `INSTEAD OF INSERT` trigger intercepts the insert operation on the `employees` table and instead inserts data into both the `employee_details` table and the `employees` table.

### Dropping a Trigger

To remove a trigger from the database, you can use the `DROP TRIGGER` statement:

```sql
DROP TRIGGER trigger_name;
```

Example:
```sql
DROP TRIGGER check_salary_before_insert;
```

This removes the `check_salary_before_insert` trigger from the database.

### Trigger Execution Order

- Triggers are executed in the order in which they are defined in the database. However, the `BEFORE` and `AFTER` triggers for the same table and event are executed in a specific order:
  - **`BEFORE` triggers** execute first.
  - **`AFTER` triggers** execute afterward.
- In the case of **INSTEAD OF** triggers, they override the default action and are executed instead of the event.

### Use Cases for Triggers

1. **Data Validation**: Ensuring data adheres to business rules before being inserted or updated.
2. **Audit Logging**: Keeping track of changes to critical data, such as logging changes to salary or sensitive information.
3. **Enforcing Referential Integrity**: Automatically updating or deleting related records in other tables when a record is inserted, updated, or deleted.
4. **Preventing Invalid Operations**: Preventing actions that violate business rules, such as deleting a record with important data.
5. **Synchronizing Data**: Automatically keeping data in sync between tables when changes occur.

### Conclusion

Triggers in Apache Derby provide a powerful mechanism to automate database operations and enforce business rules directly within the database. They can be used to ensure data integrity, audit changes, and prevent invalid operations. However, care should be taken to avoid overuse of triggers, as they can introduce complexity and performance overhead, especially when dealing with large amounts of data.**
