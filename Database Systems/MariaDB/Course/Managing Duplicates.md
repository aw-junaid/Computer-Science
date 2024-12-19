### MariaDB - Managing Duplicates

Managing duplicates in MariaDB refers to techniques and strategies used to prevent, identify, and handle duplicate rows within a table. Duplicates can occur due to various reasons such as improper data entry, incorrect query logic, or system errors. MariaDB provides several methods for handling duplicate data, including constraints, queries, and specific SQL techniques.

Below are common strategies for managing duplicates in MariaDB:

---

### 1. **Preventing Duplicates with Constraints**

The most effective way to manage duplicates is to **prevent them** in the first place by using constraints like `UNIQUE` and `PRIMARY KEY`. These constraints ensure that no duplicate values are allowed in specified columns.

#### **Using the UNIQUE Constraint**

The `UNIQUE` constraint ensures that all values in a specified column (or combination of columns) are unique across the table. If you try to insert a duplicate value into a column that has a `UNIQUE` constraint, MariaDB will return an error.

##### Example: Adding a Unique Constraint

```sql
CREATE TABLE employees (
    id INT PRIMARY KEY,
    email VARCHAR(255) UNIQUE,
    name VARCHAR(100)
);
```

In this example, the `email` column is constrained to be unique. If an attempt is made to insert another row with the same email, it will be rejected.

#### **Using the PRIMARY KEY Constraint**

The `PRIMARY KEY` constraint uniquely identifies each row in a table. A table can have only one `PRIMARY KEY`, and it automatically creates a `UNIQUE` constraint on the column(s) that make up the primary key.

```sql
CREATE TABLE orders (
    order_id INT PRIMARY KEY,
    customer_id INT,
    order_date DATE
);
```

Here, the `order_id` column is the primary key, ensuring each row in the table is uniquely identified by `order_id`.

---

### 2. **Identifying Duplicates Using Queries**

Sometimes, duplicates already exist in a table, and you may need to identify them. You can use `GROUP BY` and `HAVING` clauses to find rows that appear more than once.

#### **Finding Duplicates Using `GROUP BY`**

You can group rows by a column (or set of columns) and then use the `HAVING` clause to filter groups that have more than one row, which indicates duplicates.

##### Example: Finding Duplicate Emails

```sql
SELECT email, COUNT(*) as duplicates
FROM employees
GROUP BY email
HAVING COUNT(*) > 1;
```

This query identifies which emails in the `employees` table appear more than once.

---

### 3. **Removing Duplicates**

Once you have identified duplicates, you may need to remove them. MariaDB offers several approaches for deleting duplicate rows, either by keeping one row or removing all duplicates.

#### **Removing Duplicate Rows Using `DELETE` with `ROW_NUMBER()` (Common Table Expressions)**

MariaDB 10.2 and above supports **window functions** like `ROW_NUMBER()`, which can help in deleting duplicates while keeping one instance of each duplicated row.

##### Example: Deleting Duplicates and Keeping One Row

Suppose you have a table `employees` with duplicate `email` values, and you want to delete all but one instance for each email:

```sql
WITH duplicates AS (
    SELECT id, email, ROW_NUMBER() OVER (PARTITION BY email ORDER BY id) AS row_num
    FROM employees
)
DELETE FROM employees
WHERE id IN (SELECT id FROM duplicates WHERE row_num > 1);
```

In this query:
- The `ROW_NUMBER()` function assigns a unique row number to each row within each partition of `email`.
- The `PARTITION BY` clause groups the rows by `email`.
- The `DELETE` query removes the rows where `row_num` is greater than 1, effectively deleting all but one row for each `email`.

#### **Using `DISTINCT` to Remove Duplicates While Selecting Data**

You can also use the `DISTINCT` keyword to select only unique rows from a table, although it won’t remove duplicates in the table itself.

##### Example: Selecting Unique Rows

```sql
SELECT DISTINCT email, name
FROM employees;
```

This query will return only unique combinations of `email` and `name`.

---

### 4. **Handling Duplicates During Insertion**

When inserting new data into a table, MariaDB provides a few methods to handle potential duplicates.

#### **Using `INSERT IGNORE`**

The `INSERT IGNORE` statement allows you to insert new records while ignoring errors that would be caused by duplicate keys or unique constraints. If a duplicate entry is encountered, it will not be inserted, and no error will be thrown.

##### Example: Inserting Data and Ignoring Duplicates

```sql
INSERT IGNORE INTO employees (id, email, name)
VALUES (1, 'john.doe@example.com', 'John Doe');
```

If an entry with the same `id` or `email` already exists, the insert will be ignored for that row.

#### **Using `ON DUPLICATE KEY UPDATE`**

The `ON DUPLICATE KEY UPDATE` clause can be used to update existing rows when a duplicate key (usually a `PRIMARY KEY` or `UNIQUE` constraint violation) is encountered. Instead of throwing an error, the existing row is updated with new values.

##### Example: Inserting Data or Updating on Duplicate

```sql
INSERT INTO employees (id, email, name)
VALUES (1, 'john.doe@example.com', 'John Doe')
ON DUPLICATE KEY UPDATE name = 'Johnathan Doe';
```

If a row with the same `id` or `email` already exists, it will update the `name` field for that row instead of inserting a new row.

---

### 5. **Creating Temporary Tables for Removing Duplicates**

In cases where you want to remove duplicates but keep the original table intact, you can create a temporary table, copy unique rows into it, and then swap the tables.

#### **Steps:**

1. Create a temporary table with the same structure as the original table.
2. Insert unique rows into the temporary table.
3. Drop the original table.
4. Rename the temporary table to the original table name.

##### Example:

```sql
-- Step 1: Create a temporary table
CREATE TEMPORARY TABLE temp_employees LIKE employees;

-- Step 2: Insert unique rows into the temporary table
INSERT INTO temp_employees
SELECT * FROM employees
GROUP BY email;

-- Step 3: Drop the original table
DROP TABLE employees;

-- Step 4: Rename the temporary table to the original table name
RENAME TABLE temp_employees TO employees;
```

This approach ensures that only unique rows remain in the table.

---

### 6. **Best Practices for Managing Duplicates**

- **Enforce Uniqueness at the Database Level**: Always use `UNIQUE` constraints or `PRIMARY KEY` constraints to prevent duplicates during data insertion.
- **Use Batch Processes for Cleaning Duplicates**: For large tables with duplicates, it's better to use batch operations like temporary tables or `ROW_NUMBER()` with `DELETE` statements to clean up the data efficiently.
- **Regular Audits**: Regularly audit your data to check for duplicates, especially in large or frequently updated tables.
- **Use `ON DUPLICATE KEY UPDATE`**: If you need to update existing records when duplicates are encountered, the `ON DUPLICATE KEY UPDATE` approach is a useful and efficient way to handle this without adding additional complexity to your logic.

---

### Conclusion

Managing duplicates in MariaDB is crucial to maintain data integrity and consistency. By using constraints like `UNIQUE` and `PRIMARY KEY`, you can prevent duplicates during data insertion. If duplicates already exist, you can identify and remove them using techniques such as `GROUP BY`, `ROW_NUMBER()`, and `DELETE`. Additionally, you can handle duplicates during insertion using `INSERT IGNORE` or `ON DUPLICATE KEY UPDATE` to ensure that your data remains clean and accurate.
