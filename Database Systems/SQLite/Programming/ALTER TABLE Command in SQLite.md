The **`ALTER TABLE`** command in SQLite is used to modify an existing table. SQLite's support for the `ALTER TABLE` command is more limited compared to other relational database management systems (RDBMS), but it still provides the most common operations that you might need, such as renaming a table, adding columns, or dropping columns (though dropping columns has limited support in SQLite).

### Syntax of `ALTER TABLE`

```sql
ALTER TABLE table_name action;
```

Where:
- **`table_name`**: The name of the table to modify.
- **`action`**: The operation you want to perform, such as renaming the table or adding a column.

---

### Supported `ALTER TABLE` Actions in SQLite

1. **Renaming a Table**
2. **Adding a New Column**
3. **Renaming a Column** (limited support)
4. **Dropping a Column** (limited support, not directly supported in SQLite)

---

### 1. **Renaming a Table**

To rename an existing table in SQLite, you use the `RENAME TO` clause.

**Syntax**:
```sql
ALTER TABLE old_table_name RENAME TO new_table_name;
```

**Example**:
```sql
ALTER TABLE employees RENAME TO staff;
```

**Explanation**: This command renames the `employees` table to `staff`.

---

### 2. **Adding a New Column**

You can add a new column to an existing table using the `ADD COLUMN` clause.

**Syntax**:
```sql
ALTER TABLE table_name ADD COLUMN column_name column_definition;
```

**Example**:
```sql
ALTER TABLE employees ADD COLUMN hire_date DATE;
```

**Explanation**: This adds a new column `hire_date` of type `DATE` to the `employees` table. The new column is added at the end of the table.

---

### 3. **Renaming a Column** (SQLite Version 3.25.0 and Later)

SQLite version 3.25.0 (released in 2018) introduced support for renaming columns. Prior to this, renaming columns was not directly supported.

**Syntax**:
```sql
ALTER TABLE table_name RENAME COLUMN old_column_name TO new_column_name;
```

**Example**:
```sql
ALTER TABLE employees RENAME COLUMN hire_date TO date_of_hire;
```

**Explanation**: This renames the `hire_date` column to `date_of_hire` in the `employees` table.

---

### 4. **Dropping a Column** (Not Directly Supported)

SQLite does not support the `DROP COLUMN` clause directly, which means you cannot drop a column from an existing table with a simple `ALTER TABLE` command. However, you can simulate the process by creating a new table without the unwanted column, copying the data, and then replacing the old table.

#### Steps to Drop a Column (workaround):
1. Create a new table that has the same structure as the original table, but without the column you want to remove.
2. Copy data from the old table to the new table, excluding the column to be dropped.
3. Drop the old table.
4. Rename the new table to the original table name.

**Example**:

Suppose you want to drop the `hire_date` column from the `employees` table.

1. Create a new table without the `hire_date` column:

```sql
CREATE TABLE new_employees (
    id INTEGER PRIMARY KEY,
    name TEXT,
    department_id INTEGER
);
```

2. Copy data from the old table to the new table:

```sql
INSERT INTO new_employees (id, name, department_id)
SELECT id, name, department_id FROM employees;
```

3. Drop the old table:

```sql
DROP TABLE employees;
```

4. Rename the new table to the original table name:

```sql
ALTER TABLE new_employees RENAME TO employees;
```

---

### Important Limitations of `ALTER TABLE` in SQLite

- **Cannot Drop a Column Directly**: As shown, SQLite doesn't directly support dropping a column. You need to create a new table and migrate the data.
- **No Modifying Column Data Types**: You cannot change a column's data type with `ALTER TABLE`. If you need to change a column's data type, you will have to create a new table and copy the data over, similar to dropping a column.
- **No Reordering Columns**: SQLite doesn’t support reordering columns using `ALTER TABLE`. The column order is determined when the table is created.

---

### Example: Modifying a Table in SQLite

Let’s combine some of the commands for a more complete example.

#### Step 1: Create an initial table

```sql
CREATE TABLE employees (
    id INTEGER PRIMARY KEY,
    name TEXT,
    department_id INTEGER,
    hire_date DATE
);
```

#### Step 2: Add a new column

```sql
ALTER TABLE employees ADD COLUMN salary DECIMAL(10, 2);
```

#### Step 3: Rename a column

```sql
ALTER TABLE employees RENAME COLUMN hire_date TO date_of_hire;
```

#### Step 4: Rename the table

```sql
ALTER TABLE employees RENAME TO staff_members;
```

---

### Summary of SQLite `ALTER TABLE` Command

- **Renaming a Table**: Use `RENAME TO`.
- **Adding a Column**: Use `ADD COLUMN`.
- **Renaming a Column**: Available from SQLite 3.25.0 with `RENAME COLUMN`.
- **Dropping a Column**: Not directly supported; workarounds involve creating a new table.
- **Limitations**: Cannot modify column types or reorder columns directly.

The `ALTER TABLE` command in SQLite is useful for making minor changes to a table structure but is limited when compared to other more feature-rich RDBMS systems. For major schema changes, like column type modifications or column reordering, you often have to follow a more manual approach (creating a new table and migrating data).
