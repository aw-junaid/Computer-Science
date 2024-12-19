Apache Derby, like other relational database management systems (RDBMS), supports SQL syntax for creating, modifying, querying, and managing databases. Since Apache Derby supports a broad subset of SQL standards, it allows you to perform most of the common database operations. Below is an overview of the **basic SQL syntax** for various operations in Apache Derby.

### 1. **Creating a Database**
In **embedded mode**, Derby creates a database automatically when you connect to a non-existent database. In **client-server mode**, you can also create a new database using the `CREATE DATABASE` command.

- **Embedded Mode**:
  To create a database in embedded mode, you simply connect to it using JDBC or the `ij` tool with a `create=true` option in the connection string.
  
  ```sql
  connect 'jdbc:derby:/path/to/database;create=true';
  ```

### 2. **Creating Tables**
The `CREATE TABLE` statement defines a new table within the database.

#### Syntax:
```sql
CREATE TABLE table_name (
    column1 datatype [constraints],
    column2 datatype [constraints],
    ...
);
```

#### Example:
```sql
CREATE TABLE employees (
    id INT PRIMARY KEY,
    name VARCHAR(100),
    hire_date DATE
);
```

### 3. **Inserting Data into Tables**
The `INSERT INTO` statement adds new rows to a table.

#### Syntax:
```sql
INSERT INTO table_name (column1, column2, ...) VALUES (value1, value2, ...);
```

#### Example:
```sql
INSERT INTO employees (id, name, hire_date)
VALUES (1, 'John Doe', '2020-01-15');
```

### 4. **Querying Data**
The `SELECT` statement retrieves data from a table.

#### Syntax:
```sql
SELECT column1, column2, ... FROM table_name WHERE condition;
```

#### Example:
```sql
SELECT * FROM employees;
SELECT name, hire_date FROM employees WHERE id = 1;
```

### 5. **Updating Data**
The `UPDATE` statement modifies existing records in a table.

#### Syntax:
```sql
UPDATE table_name SET column1 = value1, column2 = value2 WHERE condition;
```

#### Example:
```sql
UPDATE employees SET hire_date = '2021-03-01' WHERE id = 1;
```

### 6. **Deleting Data**
The `DELETE` statement removes records from a table.

#### Syntax:
```sql
DELETE FROM table_name WHERE condition;
```

#### Example:
```sql
DELETE FROM employees WHERE id = 1;
```

### 7. **Dropping Tables**
The `DROP TABLE` statement removes a table and all its data from the database.

#### Syntax:
```sql
DROP TABLE table_name;
```

#### Example:
```sql
DROP TABLE employees;
```

### 8. **Altering Tables**
The `ALTER TABLE` statement is used to modify an existing table, such as adding, removing, or modifying columns.

#### Syntax to Add a Column:
```sql
ALTER TABLE table_name ADD column_name datatype;
```

#### Syntax to Drop a Column:
```sql
ALTER TABLE table_name DROP COLUMN column_name;
```

#### Example:
```sql
ALTER TABLE employees ADD salary DECIMAL(10, 2);
ALTER TABLE employees DROP COLUMN hire_date;
```

### 9. **Creating Indexes**
The `CREATE INDEX` statement creates an index on a table to improve the speed of data retrieval.

#### Syntax:
```sql
CREATE INDEX index_name ON table_name (column1, column2, ...);
```

#### Example:
```sql
CREATE INDEX idx_employees_name ON employees (name);
```

### 10. **Transactions**
Apache Derby supports **ACID** transactions, which ensure that database operations are performed reliably. Transactions begin with `BEGIN TRANSACTION`, end with either `COMMIT` or `ROLLBACK`.

#### Syntax:
- **Start a transaction**:
  ```sql
  BEGIN TRANSACTION;
  ```

- **Commit the transaction**:
  ```sql
  COMMIT;
  ```

- **Rollback the transaction**:
  ```sql
  ROLLBACK;
  ```

#### Example:
```sql
BEGIN TRANSACTION;

UPDATE employees SET salary = 50000 WHERE id = 1;

COMMIT;
```

### 11. **Constraints**
You can define **constraints** to enforce rules on columns, such as ensuring uniqueness, checking data validity, or defining relationships between tables.

- **PRIMARY KEY**: Uniquely identifies each record in a table.
- **FOREIGN KEY**: Enforces a relationship between two tables.
- **UNIQUE**: Ensures that all values in a column are different.
- **CHECK**: Ensures that values in a column meet a specific condition.
- **NOT NULL**: Ensures that a column cannot have a `NULL` value.

#### Example with Constraints:
```sql
CREATE TABLE employees (
    id INT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    hire_date DATE,
    salary DECIMAL(10, 2),
    department_id INT,
    CONSTRAINT fk_department FOREIGN KEY (department_id) REFERENCES departments(id)
);
```

### 12. **Joins**
Joins combine rows from two or more tables based on a related column. Apache Derby supports `INNER JOIN`, `LEFT JOIN`, `RIGHT JOIN`, and `FULL JOIN`.

#### Example:
```sql
SELECT employees.name, departments.name 
FROM employees
INNER JOIN departments ON employees.department_id = departments.id;
```

### 13. **Subqueries**
A subquery is a query inside another query. It can be used in `SELECT`, `INSERT`, `UPDATE`, or `DELETE` statements.

#### Example:
```sql
SELECT name 
FROM employees 
WHERE id IN (SELECT employee_id FROM sales WHERE amount > 1000);
```

### 14. **Grouping and Aggregation**
You can group rows that have the same values into summary rows, such as finding the total number of employees in each department.

- **GROUP BY**: Groups rows that have the same values.
- **HAVING**: Used to filter groups based on an aggregate condition.
- **COUNT(), SUM(), AVG(), MIN(), MAX()**: Aggregate functions.

#### Example:
```sql
SELECT department_id, COUNT(*) AS num_employees
FROM employees
GROUP BY department_id
HAVING COUNT(*) > 5;
```

### 15. **Views**
A **view** is a virtual table based on the result of a `SELECT` query. It can be used to simplify complex queries or hide certain columns from users.

#### Syntax:
```sql
CREATE VIEW view_name AS
SELECT column1, column2
FROM table_name
WHERE condition;
```

#### Example:
```sql
CREATE VIEW employee_salaries AS
SELECT name, salary
FROM employees
WHERE salary > 50000;
```

### 16. **Sequences**
A **sequence** is a database object that generates a sequence of unique numeric values, often used for auto-incrementing primary key values.

#### Syntax:
```sql
CREATE SEQUENCE sequence_name START WITH 1 INCREMENT BY 1;
```

#### Example:
```sql
CREATE SEQUENCE emp_seq START WITH 1 INCREMENT BY 1;
```

To get the next value from the sequence:
```sql
SELECT emp_seq.NEXTVAL FROM SYSIBM.SYSDUMMY1;
```

### Conclusion
Apache Derby supports a broad range of SQL syntax and features, making it suitable for lightweight database applications. Its SQL syntax closely adheres to the SQL standards, allowing for straightforward interaction and management of relational data. By leveraging basic SQL commands like `CREATE`, `SELECT`, `INSERT`, `UPDATE`, and `DELETE`, you can perform most common database operations in Derby effectively.
