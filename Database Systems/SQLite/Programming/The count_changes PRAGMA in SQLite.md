The **`count_changes`** PRAGMA in SQLite is used to control whether SQLite tracks the number of changes (such as insertions, updates, or deletions) made to the database during the current session.

### Syntax of `count_changes` PRAGMA

```sql
PRAGMA count_changes = { ON | OFF };
```

- **`ON`**: Enables the tracking of changes. When set to `ON`, SQLite will count the number of rows affected by `INSERT`, `UPDATE`, and `DELETE` operations during the current session. The count can be accessed using the `changes()` function.
- **`OFF`**: Disables the tracking of changes. When set to `OFF`, SQLite will not count changes made to the database during the session. The default value is `OFF`.

### Default Behavior

By default, **`count_changes`** is set to **`OFF`**, meaning SQLite does not track the number of changes. If you want to track the number of rows affected by modifications, you must explicitly enable it.

### Example of `count_changes`

1. **Track Changes (Enable `count_changes`)**

```sql
PRAGMA count_changes = ON;
```

Now, SQLite will count how many rows were affected by each `INSERT`, `UPDATE`, and `DELETE` operation during the current session.

2. **Performing Operations**

```sql
-- Insert rows into a table
INSERT INTO employees (name, department) VALUES ('John', 'Sales');
INSERT INTO employees (name, department) VALUES ('Jane', 'HR');

-- Update rows in a table
UPDATE employees SET department = 'Marketing' WHERE name = 'John';

-- Delete rows from a table
DELETE FROM employees WHERE name = 'Jane';
```

3. **Accessing the Number of Changes with `changes()`**

After performing the operations, you can retrieve the number of affected rows by calling the `changes()` function:

```sql
SELECT changes();  -- Returns the number of rows affected by the last operation
```

The function `changes()` will return the number of rows that were affected by the most recent `INSERT`, `UPDATE`, or `DELETE` statement.

For example, if two rows were inserted, one row was updated, and one row was deleted, `changes()` will return the count of affected rows (in this case, 1 for the `UPDATE` operation, 1 for the `DELETE`, etc.).

---

### Example of Disabling `count_changes`

```sql
PRAGMA count_changes = OFF;
```

When `count_changes` is turned off, SQLite will no longer track the number of changes made to the database. Calling `changes()` will always return `0`, even after making modifications to the database.

### Use Case for `count_changes`

- **Tracking changes**: Useful when you want to track how many rows were modified by an operation. For example, you might want to log the number of rows affected by an update or keep track of insertions.
- **Performance considerations**: Enabling `count_changes` can have a small performance impact, especially in databases with many changes. For performance reasons, it's typically turned off by default unless tracking is required.

---

### Summary of `count_changes` PRAGMA

- **Purpose**: Enables or disables the tracking of the number of changes (insertions, updates, deletions) made to the database during the session.
- **Syntax**: `PRAGMA count_changes = { ON | OFF };`
  - **`ON`**: Tracks the number of changes.
  - **`OFF`**: Does not track changes (default).
- **Usage**: Use the `changes()` function to get the number of rows affected by the last operation.
- **Performance Impact**: Enabling change tracking may introduce a small performance overhead, so it’s typically used only when necessary.
