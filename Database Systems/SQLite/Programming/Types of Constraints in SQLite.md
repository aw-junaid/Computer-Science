In SQLite, **constraints** are rules applied to database tables that enforce specific conditions on data, ensuring the integrity, consistency, and validity of the data stored. SQLite supports several types of constraints, each serving a unique purpose. Constraints can be defined at the column level or table level, depending on their function and scope.

### Types of Constraints in SQLite

1. **NOT NULL Constraint**
   - Ensures that a column cannot have `NULL` values.
   - Useful for columns that require a value in every row, like `id`, `name`, or other essential fields.
   - Example:
     ```sql
     CREATE TABLE employees (
         id INTEGER NOT NULL,
         name TEXT NOT NULL
     );
     ```

2. **UNIQUE Constraint**
   - Ensures that all values in a column (or a group of columns) are unique across the table.
   - Prevents duplicate values in specified columns.
   - Example:
     ```sql
     CREATE TABLE employees (
         id INTEGER PRIMARY KEY,
         email TEXT UNIQUE
     );
     ```
   - **Composite UNIQUE Constraint**: A `UNIQUE` constraint can also be applied to multiple columns to enforce uniqueness across a combination of columns.
     ```sql
     CREATE TABLE employees (
         id INTEGER PRIMARY KEY,
         name TEXT,
         department TEXT,
         UNIQUE (name, department)
     );
     ```

3. **PRIMARY KEY Constraint**
   - A `PRIMARY KEY` is a unique identifier for each row in a table.
   - A column (or combination of columns) defined as the primary key must be unique and cannot contain `NULL` values.
   - SQLite only allows one primary key per table, which automatically includes a `UNIQUE` and `NOT NULL` constraint.
   - Example:
     ```sql
     CREATE TABLE employees (
         id INTEGER PRIMARY KEY,
         name TEXT NOT NULL
     );
     ```
   - **Composite PRIMARY KEY**: You can define a primary key on multiple columns, creating a composite primary key.
     ```sql
     CREATE TABLE employee_projects (
         employee_id INTEGER,
         project_id INTEGER,
         PRIMARY KEY (employee_id, project_id)
     );
     ```

4. **FOREIGN KEY Constraint**
   - Establishes a relationship between columns in different tables, enforcing referential integrity.
   - Requires that values in a column (or set of columns) match values in a referenced column in another table, typically the primary key.
   - To enforce foreign keys, SQLite requires enabling `PRAGMA foreign_keys = ON;` because they are off by default.
   - Example:
     ```sql
     PRAGMA foreign_keys = ON;

     CREATE TABLE departments (
         id INTEGER PRIMARY KEY,
         name TEXT NOT NULL
     );

     CREATE TABLE employees (
         id INTEGER PRIMARY KEY,
         name TEXT NOT NULL,
         department_id INTEGER,
         FOREIGN KEY (department_id) REFERENCES departments(id)
     );
     ```

5. **CHECK Constraint**
   - Specifies a condition that values in a column or row must satisfy.
   - If the condition evaluates to `FALSE`, the insertion or update will be rejected.
   - Example:
     ```sql
     CREATE TABLE employees (
         id INTEGER PRIMARY KEY,
         name TEXT NOT NULL,
         age INTEGER CHECK (age >= 18),
         salary REAL CHECK (salary > 0)
     );
     ```

6. **DEFAULT Constraint**
   - Sets a default value for a column when an `INSERT` operation does not provide a value.
   - Useful for providing automatic values, such as default text or numeric values.
   - Example:
     ```sql
     CREATE TABLE employees (
         id INTEGER PRIMARY KEY,
         name TEXT NOT NULL,
         department TEXT DEFAULT 'General'
     );
     ```

### Examples of Common Constraint Usage

1. **Combining Constraints**
   - Multiple constraints can be applied to a single column by chaining them within the column definition.
   - Example:
     ```sql
     CREATE TABLE employees (
         id INTEGER PRIMARY KEY,
         name TEXT NOT NULL UNIQUE,
         email TEXT UNIQUE,
         age INTEGER CHECK (age >= 18)
     );
     ```

2. **Constraints at Table Level**
   - Some constraints, like `PRIMARY KEY`, `UNIQUE`, and `CHECK`, can also be defined at the table level. This is often used for composite constraints (involving multiple columns).
   - Example:
     ```sql
     CREATE TABLE employee_projects (
         employee_id INTEGER,
         project_id INTEGER,
         role TEXT,
         PRIMARY KEY (employee_id, project_id),
         UNIQUE (employee_id, role),
         FOREIGN KEY (employee_id) REFERENCES employees(id)
     );
     ```

### Practical Use Cases for Constraints

- **Data Integrity**: Constraints like `FOREIGN KEY` and `CHECK` help ensure data consistency and enforce relationships.
- **Preventing Duplicates**: The `UNIQUE` constraint is essential for avoiding duplicate entries, especially in columns like `email` or `username`.
- **Default Values**: The `DEFAULT` constraint is useful for setting automatic default values, reducing the need for manual input.
- **Validation**: Constraints like `CHECK` act as a form of validation, ensuring that values meet specific criteria before insertion.

### Summary

- **Constraints** help enforce data integrity, ensure consistency, and validate data at the database level.
- **Common constraints** include `NOT NULL`, `UNIQUE`, `PRIMARY KEY`, `FOREIGN KEY`, `CHECK`, and `DEFAULT`.
- **Composite constraints** and **table-level constraints** allow flexibility in managing complex relationships and validations.
- **Use constraints thoughtfully** for effective database design and data quality management.
