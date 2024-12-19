### MariaDB - Temporary Tables

Temporary tables in MariaDB are used to store data temporarily during the session in which they are created. These tables are useful when you need to perform intermediate operations within a query or session, such as storing intermediate results for further manipulation, without affecting the permanent tables in the database.

Temporary tables are automatically dropped at the end of the session or when the connection to the database is closed. This makes them a great tool for handling session-specific data without leaving any permanent traces in the database.

---

### 1. **Creating Temporary Tables**

To create a temporary table in MariaDB, you use the `CREATE TEMPORARY TABLE` statement, which is similar to creating a regular table, but with the `TEMPORARY` keyword.

#### Syntax:

```sql
CREATE TEMPORARY TABLE table_name (
    column1 data_type,
    column2 data_type,
    ...
);
```

#### Example:

```sql
CREATE TEMPORARY TABLE temp_employees (
    id INT,
    name VARCHAR(100),
    department VARCHAR(50)
);
```

This creates a temporary table named `temp_employees` with three columns: `id`, `name`, and `department`.

---

### 2. **Inserting Data into Temporary Tables**

Once a temporary table is created, you can insert data into it just like a regular table. You can use `INSERT INTO` statements or `SELECT INTO` statements.

#### Example:

```sql
INSERT INTO temp_employees (id, name, department) VALUES (1, 'John Doe', 'Sales');
```

Or you can insert data into a temporary table by selecting from another table:

```sql
INSERT INTO temp_employees (id, name, department)
SELECT id, name, department FROM employees WHERE department = 'Sales';
```

---

### 3. **Using Temporary Tables in Queries**

You can use temporary tables within any queries, including `SELECT`, `UPDATE`, `DELETE`, and `JOIN`, just like a normal table.

#### Example:

```sql
SELECT * FROM temp_employees WHERE department = 'Sales';
```

This selects all rows from the `temp_employees` temporary table where the department is "Sales."

You can also join temporary tables with permanent tables:

```sql
SELECT e.name, t.department 
FROM employees e
JOIN temp_employees t ON e.id = t.id;
```

---

### 4. **Dropping Temporary Tables**

Temporary tables are dropped automatically when the session ends or when the connection is closed. However, you can also manually drop a temporary table during the session using the `DROP` statement.

#### Syntax:

```sql
DROP TEMPORARY TABLE IF EXISTS table_name;
```

#### Example:

```sql
DROP TEMPORARY TABLE IF EXISTS temp_employees;
```

This manually drops the `temp_employees` table if it exists in the current session.

---

### 5. **Scope and Lifetime of Temporary Tables**

- **Session-specific**: Temporary tables exist only within the session that created them. They are automatically dropped when the session ends or when the connection is closed.
- **Automatic Deletion**: Once the session or connection is closed, MariaDB automatically deletes temporary tables, so you do not need to manually delete them unless you want to free up resources sooner.
- **No Shared Access**: Temporary tables are not accessible to other sessions or connections. Each session that creates a temporary table can only access its own temporary tables.
  
### 6. **Temporary Tables in Transactions**

Temporary tables are supported within transactions. You can create and use temporary tables, perform operations within a transaction, and roll back the transaction if needed. However, rolling back a transaction does not automatically drop the temporary table—it will still exist until the session is closed.

#### Example:

```sql
START TRANSACTION;

CREATE TEMPORARY TABLE temp_orders (
    order_id INT,
    customer_id INT
);

INSERT INTO temp_orders (order_id, customer_id) VALUES (1, 1001), (2, 1002);

-- Do some work with the temp table

ROLLBACK;  -- The temp table is not dropped, only the operations within the transaction are rolled back.

-- You must manually drop the temp table or let the session end.
```

---

### 7. **Temporary Tables and Indexes**

You can create indexes on temporary tables just like you would on regular tables. Indexes can improve query performance when working with large amounts of data in a temporary table.

#### Example:

```sql
CREATE INDEX idx_temp_department ON temp_employees (department);
```

This creates an index `idx_temp_department` on the `department` column of the `temp_employees` temporary table.

---

### 8. **Temporary Tables vs. Regular Tables**

- **Temporary tables** are session-specific and automatically deleted when the session ends, while **regular tables** persist until explicitly dropped.
- **Temporary tables** do not require explicit cleanup and are isolated to a single session, whereas **regular tables** can be shared between multiple sessions and must be explicitly dropped when no longer needed.
- **Temporary tables** are stored in memory or on disk (depending on size), which can make them faster to access but also subject to memory limitations for large datasets.

---

### 9. **Example Usage of Temporary Tables**

Here is an example of how temporary tables can be useful in a practical scenario.

#### Example Scenario: Processing Data in Steps

```sql
-- Create a temporary table to hold intermediate results
CREATE TEMPORARY TABLE temp_sales_summary (
    product_id INT,
    total_sales DECIMAL(10, 2)
);

-- Insert data into the temporary table from a main sales table
INSERT INTO temp_sales_summary
SELECT product_id, SUM(sales_amount) 
FROM sales 
GROUP BY product_id;

-- Perform further analysis or processing on the temporary table
SELECT * FROM temp_sales_summary WHERE total_sales > 1000;

-- Drop the temporary table explicitly, although it will be dropped at session end
DROP TEMPORARY TABLE IF EXISTS temp_sales_summary;
```

In this scenario, a temporary table `temp_sales_summary` is used to hold intermediate results from a query that aggregates sales data, which is then further analyzed.

---

### 10. **Limitations of Temporary Tables**

- Temporary tables are not visible to other sessions or connections.
- Temporary tables cannot be used to store permanent data, as they are automatically dropped at the end of the session.
- Large temporary tables might consume significant server resources, especially if MariaDB needs to store them on disk instead of in memory.

---

### Conclusion

Temporary tables in MariaDB are powerful tools for handling intermediate data within a session. They provide a convenient way to store and manipulate data without affecting permanent tables in the database. They are session-specific and automatically deleted at the end of the session, making them ideal for transient data storage. Using temporary tables effectively can lead to cleaner, more efficient queries, particularly when performing complex multi-step operations.
