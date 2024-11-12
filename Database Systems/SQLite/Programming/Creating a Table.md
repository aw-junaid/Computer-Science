Creating a table in SQLite involves using the `CREATE TABLE` statement, where you define the table's name, columns, and data types. You can also specify constraints to enforce rules for the data. Here’s a step-by-step guide to creating tables with various features in SQLite.

---

### Basic `CREATE TABLE` Syntax

The syntax for creating a basic table is:

```sql
CREATE TABLE table_name (
    column1_name column1_type constraint,
    column2_name column2_type constraint,
    ...
);
```

- **`table_name`**: The name you want to give the table.
- **`column_name`**: Name of each column.
- **`column_type`**: Data type of each column (e.g., `INTEGER`, `TEXT`, `REAL`).
- **`constraint`**: Optional constraint on the column, such as `PRIMARY KEY`, `NOT NULL`, `UNIQUE`.

---

### Example 1: Creating a Simple Table

```sql
CREATE TABLE students (
    id INTEGER PRIMARY KEY,
    name TEXT NOT NULL,
    age INTEGER,
    grade REAL
);
```

- `id`: An integer primary key that uniquely identifies each student.
- `name`: A text field that cannot be null.
- `age`: An integer column for the student's age.
- `grade`: A real (floating-point) column for storing grades.

---

### Example 2: Adding Constraints

Constraints ensure data integrity and validity in your table.

```sql
CREATE TABLE employees (
    employee_id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    department TEXT,
    email TEXT UNIQUE,
    salary REAL CHECK (salary > 0)
);
```

- `AUTOINCREMENT`: Automatically increments the `employee_id` for each new row.
- `UNIQUE`: Ensures each email is unique.
- `CHECK`: Ensures the salary is always positive.

---

### Example 3: Foreign Key Constraints

Foreign keys establish relationships between tables by linking one table to another.

1. **Create the primary table**:

   ```sql
   CREATE TABLE departments (
       department_id INTEGER PRIMARY KEY,
       department_name TEXT NOT NULL
   );
   ```

2. **Create the secondary table with a foreign key**:

   ```sql
   CREATE TABLE employees (
       employee_id INTEGER PRIMARY KEY AUTOINCREMENT,
       name TEXT NOT NULL,
       department_id INTEGER,
       FOREIGN KEY (department_id) REFERENCES departments(department_id)
   );
   ```

Here, `department_id` in the `employees` table references the `department_id` in the `departments` table. This ensures that each employee’s `department_id` must correspond to an existing `department_id` in the `departments` table.

---

### Example 4: Using Default Values

You can set default values for columns to fill in when no value is provided.

```sql
CREATE TABLE projects (
    project_id INTEGER PRIMARY KEY,
    project_name TEXT NOT NULL,
    start_date TEXT DEFAULT (DATE('now')),
    status TEXT DEFAULT 'Pending'
);
```

- `start_date`: Defaults to the current date.
- `status`: Defaults to 'Pending' if no status is specified.

---

### Example 5: Using `IF NOT EXISTS`

To avoid errors when creating a table that may already exist, you can use the `IF NOT EXISTS` clause.

```sql
CREATE TABLE IF NOT EXISTS employees (
    employee_id INTEGER PRIMARY KEY,
    name TEXT NOT NULL,
    position TEXT,
    salary REAL
);
```

This only creates the `employees` table if it doesn’t already exist in the database.

---

### Example 6: Temporary Tables

Temporary tables exist only for the duration of a database session and are deleted automatically afterward.

```sql
CREATE TEMP TABLE temp_employees (
    id INTEGER PRIMARY KEY,
    name TEXT
);
```

- `TEMP` or `TEMPORARY`: Indicates that the table is temporary.

---

### Data Types in SQLite

SQLite uses a dynamic type system and commonly supports these types:

- **`INTEGER`**: For whole numbers.
- **`REAL`**: For floating-point numbers.
- **`TEXT`**: For strings and text data.
- **`BLOB`**: For binary data, stored exactly as input.
  
---

### Example: Comprehensive Table with Multiple Constraints

```sql
CREATE TABLE orders (
    order_id INTEGER PRIMARY KEY AUTOINCREMENT,
    customer_id INTEGER NOT NULL,
    order_date TEXT DEFAULT (DATE('now')),
    amount REAL CHECK (amount > 0),
    status TEXT DEFAULT 'Processing',
    FOREIGN KEY (customer_id) REFERENCES customers(customer_id)
);
```

This table `orders` includes:

- An automatically incrementing primary key.
- A `NOT NULL` constraint for `customer_id`.
- A `CHECK` constraint for positive `amount`.
- A foreign key to the `customers` table.

---

### Summary

Creating tables with `CREATE TABLE` in SQLite allows you to define the structure, relationships, and integrity constraints of your data. Experimenting with these features helps you set up robust databases tailored to the needs of your application.
