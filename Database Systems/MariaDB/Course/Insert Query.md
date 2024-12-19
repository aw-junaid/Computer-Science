### MariaDB - Insert Query

In MariaDB, the `INSERT` statement is used to add new records (rows) into a table. The `INSERT` statement allows you to insert data into all or specific columns of a table, and you can insert multiple rows in a single query.

### Basic Syntax

```sql
INSERT INTO table_name (column1, column2, column3, ...)
VALUES (value1, value2, value3, ...);
```

#### Parameters:
- **`table_name`**: The name of the table into which you want to insert data.
- **`column1, column2, ...`**: The names of the columns where you want to insert the data. These should match the columns in the table.
- **`value1, value2, ...`**: The corresponding values for each column. The values must match the data types of the columns.

---

### 1. **Inserting a Single Row**

The most basic form of the `INSERT` statement is inserting a single row of data into the table. Here's an example of how to insert a row into a `users` table:

```sql
INSERT INTO users (first_name, last_name, email, date_of_birth)
VALUES ('John', 'Doe', 'john.doe@example.com', '1990-05-10');
```

This will insert a new user with the first name "John", last name "Doe", email "john.doe@example.com", and a date of birth of May 10, 1990.

---

### 2. **Inserting Data Without Specifying Columns**

If you're inserting data into every column of the table in the same order as defined in the table schema, you can omit the column names in the `INSERT` statement.

Example:

```sql
INSERT INTO users
VALUES (NULL, 'Jane', 'Smith', 'jane.smith@example.com', '1985-07-15', CURRENT_TIMESTAMP);
```

In this case:
- The `NULL` value is inserted into the `id` column (assuming it is an `AUTO_INCREMENT` column).
- The `CURRENT_TIMESTAMP` will be used for the `created_at` column (if it has a `DEFAULT CURRENT_TIMESTAMP`).

---

### 3. **Inserting Multiple Rows**

You can insert multiple rows at once by separating each set of values with a comma.

Example:

```sql
INSERT INTO users (first_name, last_name, email, date_of_birth)
VALUES 
    ('Alice', 'Johnson', 'alice.johnson@example.com', '1992-03-25'),
    ('Bob', 'Williams', 'bob.williams@example.com', '1988-11-20'),
    ('Charlie', 'Brown', 'charlie.brown@example.com', '1995-02-14');
```

This will insert three new rows into the `users` table.

---

### 4. **Inserting Data from Another Table (INSERT SELECT)**

You can insert data from one table into another using the `INSERT INTO ... SELECT` statement. This is particularly useful when you want to copy data from one table to another.

Example:

```sql
INSERT INTO users_archive (id, first_name, last_name, email, date_of_birth)
SELECT id, first_name, last_name, email, date_of_birth 
FROM users
WHERE date_of_birth < '1990-01-01';
```

This query will copy all users born before January 1, 1990, from the `users` table to the `users_archive` table.

---

### 5. **Inserting Data with `ON DUPLICATE KEY UPDATE`**

If you are inserting data where there may be a conflict with a unique or primary key (e.g., a user with the same email already exists), you can use the `ON DUPLICATE KEY UPDATE` clause to handle the conflict.

Example:

```sql
INSERT INTO users (id, first_name, last_name, email)
VALUES (1, 'John', 'Doe', 'john.doe@example.com')
ON DUPLICATE KEY UPDATE 
    first_name = VALUES(first_name), 
    last_name = VALUES(last_name);
```

In this example, if a user with the same `id` (primary key) already exists, the `first_name` and `last_name` will be updated with the new values provided. If no duplicate exists, a new record will be inserted.

---

### 6. **Inserting Data with `DEFAULT` Values**

If a column has a `DEFAULT` value (e.g., for `AUTO_INCREMENT` or `DEFAULT` constraints), you can use the `DEFAULT` keyword to explicitly insert the default value.

Example:

```sql
INSERT INTO users (first_name, last_name, email)
VALUES ('Eva', 'Green', 'eva.green@example.com');
```

If the `id` column is `AUTO_INCREMENT`, MariaDB will automatically generate a value for it. Similarly, if other columns have `DEFAULT` values, they will be inserted automatically without explicitly specifying them in the `INSERT` statement.

---

### 7. **Handling NULL Values**

If a column allows `NULL` values, you can insert a `NULL` value into the column explicitly, if needed.

Example:

```sql
INSERT INTO users (first_name, last_name, email, date_of_birth)
VALUES ('Tom', 'Hanks', 'tom.hanks@example.com', NULL);
```

In this case, `NULL` is inserted into the `date_of_birth` column.

---

### 8. **Common Errors**

- **Duplicate Key Error**: If you're trying to insert a value into a column with a unique constraint (such as `PRIMARY KEY` or `UNIQUE`), and the value already exists, an error will occur unless handled by `ON DUPLICATE KEY UPDATE`.
- **Data Type Mismatch**: Ensure that the values you're inserting match the data types of the columns in the table (e.g., inserting text into a numeric column will result in an error).
- **Missing Columns**: If you're not specifying the column names, ensure that the values you're inserting match the number and order of the columns in the table.

---

### Conclusion

The `INSERT` statement is a powerful tool for adding data to your MariaDB tables. Whether you're inserting a single row or multiple rows, from literal values or another table, MariaDB provides flexibility to handle various data insertion tasks. Additionally, you can handle conflicts with duplicate keys using `ON DUPLICATE KEY UPDATE`, and manage `DEFAULT` and `NULL` values as needed.

**Key Points**:
- Use `INSERT INTO` to add new rows to a table.
- Use `INSERT INTO ... SELECT` to copy data from another table.
- Handle conflicts with `ON DUPLICATE KEY UPDATE`.
- Be mindful of data types and constraints to avoid errors.
