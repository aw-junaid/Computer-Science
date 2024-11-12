SQLite3 is the command-line interface for SQLite, allowing you to interact with SQLite databases directly. It’s especially useful for small applications, testing, and prototyping. Below is a guide on using `sqlite3` to create and manage databases, tables, and data.

---

### 1. **Starting `sqlite3`**

To open `sqlite3` and create a new database:

```sh
sqlite3 my_database.db
```

- If `my_database.db` exists, this command opens it; if not, it creates a new one.
- To work with an in-memory database, use `sqlite3 :memory:`.

---

### 2. **Basic `sqlite3` Commands**

Inside `sqlite3`, you can use special commands that start with a dot (`.`) and regular SQL commands.

#### Common `.commands` in `sqlite3`

- **`.tables`**: Lists all tables in the database.
- **`.schema table_name`**: Shows the SQL used to create a specific table.
- **`.databases`**: Lists all attached databases.
- **`.quit`**: Exits the `sqlite3` session.
- **`.help`**: Lists all available `sqlite3` commands.

**Example:**
```sql
.tables
.schema my_table
.quit
```

---

### 3. **Creating Tables**

To create a table, use the `CREATE TABLE` SQL command.

**Example:**

```sql
CREATE TABLE employees (
    id INTEGER PRIMARY KEY,
    name TEXT NOT NULL,
    position TEXT,
    salary REAL
);
```

- `INTEGER PRIMARY KEY` automatically sets `id` as a unique identifier for each record.
- `NOT NULL` ensures the `name` field cannot be empty.

---

### 4. **Inserting Data**

Use `INSERT INTO` to add data to a table.

**Example:**

```sql
INSERT INTO employees (name, position, salary) VALUES ('Alice', 'Manager', 75000);
INSERT INTO employees (name, position, salary) VALUES ('Bob', 'Developer', 60000);
```

---

### 5. **Querying Data**

Use the `SELECT` command to retrieve data.

**Example:**

```sql
SELECT * FROM employees;
SELECT name, salary FROM employees WHERE position = 'Developer';
SELECT AVG(salary) AS average_salary FROM employees;
```

---

### 6. **Updating Data**

To update existing records, use `UPDATE`.

**Example:**

```sql
UPDATE employees
SET salary = 80000
WHERE name = 'Alice';
```

This updates Alice’s salary to `80000`.

---

### 7. **Deleting Data**

Use `DELETE FROM` to remove records.

**Example:**

```sql
DELETE FROM employees WHERE name = 'Bob';
```

This removes Bob from the `employees` table.

---

### 8. **Managing Transactions**

SQLite supports transactions, allowing multiple operations to be committed or rolled back as a unit.

**Example:**

```sql
BEGIN;
INSERT INTO employees (name, position, salary) VALUES ('Charlie', 'Analyst', 50000);
UPDATE employees SET salary = 85000 WHERE name = 'Alice';
ROLLBACK;  -- Undo changes

BEGIN;
UPDATE employees SET salary = 90000 WHERE name = 'Alice';
COMMIT;  -- Save changes
```

---

### 9. **Using `.import` to Load Data**

To load data from a CSV file into an SQLite table, use `.import`.

**Steps:**
1. Ensure the table exists and has a structure matching the CSV.
2. Use the `.import` command:

   ```sql
   .mode csv
   .import /path/to/yourfile.csv employees
   ```

This imports data from `yourfile.csv` into the `employees` table.

---

### 10. **Exporting Data**

To export data to a CSV, use `.mode csv` followed by `.output`.

**Example:**

```sql
.mode csv
.output employees_export.csv
SELECT * FROM employees;
.output stdout  -- Resets output back to standard output
```

---

### 11. **Exiting `sqlite3`**

Type `.quit` to exit the SQLite prompt:

```sql
.quit
```

---

### Summary

Using `sqlite3` provides a straightforward way to manage SQLite databases from the command line. It supports all basic SQL commands and offers `.commands` for database management and data import/export. Whether you’re inserting, querying, updating, or deleting data, `sqlite3` makes it easy to interact with your SQLite databases.
