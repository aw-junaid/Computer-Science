In SQLite, a **trigger** is a database object that automatically executes a specified set of SQL statements in response to certain events on a particular table. Triggers are helpful for enforcing business rules, maintaining audit logs, and automatically updating related tables when changes occur.

### Key Points About Triggers

- **Event-Driven**: Triggers activate in response to `INSERT`, `UPDATE`, or `DELETE` operations on a table.
- **Execution Timing**: Triggers can be set to run `BEFORE` or `AFTER` the triggering event.
- **Attached to a Table**: Each trigger is associated with a specific table.

### Syntax of Triggers

```sql
CREATE TRIGGER trigger_name
[BEFORE | AFTER] [INSERT | UPDATE | DELETE]
ON table_name
[FOR EACH ROW]
WHEN condition
BEGIN
    -- SQL statements to execute
END;
```

**Parts of a Trigger**:
- **trigger_name**: The name of the trigger.
- **BEFORE | AFTER**: Specifies when the trigger should execute, relative to the event.
- **INSERT | UPDATE | DELETE**: Specifies the event that activates the trigger.
- **table_name**: The table associated with the trigger.
- **FOR EACH ROW**: Ensures that the trigger activates for each row affected by the event.
- **WHEN condition**: An optional clause to specify when the trigger should execute (based on a condition).
- **BEGIN...END**: A block that contains one or more SQL statements to execute when the trigger fires.

---

### Types of Triggers in SQLite

1. **BEFORE INSERT**: Executes before an `INSERT` operation.
2. **AFTER INSERT**: Executes after an `INSERT` operation.
3. **BEFORE UPDATE**: Executes before an `UPDATE` operation.
4. **AFTER UPDATE**: Executes after an `UPDATE` operation.
5. **BEFORE DELETE**: Executes before a `DELETE` operation.
6. **AFTER DELETE**: Executes after a `DELETE` operation.

---

### Example Use Cases for Triggers

#### 1. Automatically Updating a Timestamp Column

A common use of triggers is to update a timestamp field whenever a row in a table is modified.

**Example**:
```sql
CREATE TABLE employees (
    id INTEGER PRIMARY KEY,
    name TEXT,
    department_id INTEGER,
    updated_at DATETIME
);

CREATE TRIGGER update_timestamp
AFTER UPDATE ON employees
FOR EACH ROW
BEGIN
    UPDATE employees SET updated_at = CURRENT_TIMESTAMP WHERE id = OLD.id;
END;
```

**Explanation**: This trigger sets `updated_at` to the current timestamp every time a row in the `employees` table is updated. `OLD.id` refers to the `id` of the row before the update.

---

#### 2. Preventing Deletion of Important Records

You can use a trigger to prevent deletion of certain records by raising an exception.

**Example**:
```sql
CREATE TRIGGER prevent_hr_deletion
BEFORE DELETE ON employees
FOR EACH ROW
WHEN OLD.department_id = 1  -- assuming 1 is the HR department
BEGIN
    SELECT RAISE(ABORT, 'Cannot delete HR employees');
END;
```

**Explanation**: This trigger checks if the `department_id` of the employee being deleted is `1` (HR department). If so, it aborts the deletion and raises an error message.

---

#### 3. Logging Changes in an Audit Table

Triggers can log changes to a separate audit table, which can be useful for maintaining a history of changes.

**Example**:
```sql
CREATE TABLE employee_audit (
    id INTEGER,
    name TEXT,
    department_id INTEGER,
    action TEXT,
    action_time DATETIME DEFAULT CURRENT_TIMESTAMP
);

CREATE TRIGGER log_employee_update
AFTER UPDATE ON employees
FOR EACH ROW
BEGIN
    INSERT INTO employee_audit (id, name, department_id, action)
    VALUES (OLD.id, OLD.name, OLD.department_id, 'UPDATE');
END;
```

**Explanation**: When an employee record is updated, this trigger logs the old values in an `employee_audit` table with an `action` indicating the type of change (`UPDATE` in this case).

---

### Accessing OLD and NEW Values in Triggers

In triggers, you can reference the values of the affected row using:
- **OLD**: Refers to the original values before the triggering action.
- **NEW**: Refers to the values after the triggering action.

These are especially useful for comparing or recording changes.

**Example**:
```sql
CREATE TRIGGER track_department_change
AFTER UPDATE OF department_id ON employees
FOR EACH ROW
BEGIN
    INSERT INTO employee_audit (id, name, department_id, action)
    VALUES (OLD.id, OLD.name, OLD.department_id, 'DEPARTMENT CHANGE');
END;
```

**Explanation**: This trigger only runs when the `department_id` of an employee changes. It logs the old `department_id` in the audit table.

---

### Deleting a Trigger

To delete a trigger, use the `DROP TRIGGER` statement.

**Syntax**:
```sql
DROP TRIGGER IF EXISTS trigger_name;
```

**Example**:
```sql
DROP TRIGGER IF EXISTS prevent_hr_deletion;
```

### Summary of SQLite Triggers

- **Triggers** allow automated responses to changes in the database (like `INSERT`, `UPDATE`, or `DELETE`).
- **Types**: BEFORE or AFTER each action, for granular control.
- **OLD and NEW**: Use these to access pre- and post-action values of the row.
- **RAISE Function**: Abort actions and display error messages when conditions are met.

Triggers in SQLite are powerful tools for enforcing rules, maintaining data integrity, and automating actions that respond to changes in the database.
