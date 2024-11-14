In SQLite, **NULL values** represent missing or undefined data within a table. NULL is a special marker used to indicate that a data value does not exist in a specific row or column, distinct from values like zero, an empty string, or any other placeholder. Understanding how NULL works is essential for working with SQLite queries, as NULLs affect conditions, calculations, and query results.

### Key Points About NULL in SQLite

1. **NULL Is Not a Value**: NULL represents the absence of a value. It is different from a zero number, an empty string, or a space.
2. **NULL Comparisons**: NULL is not equal to any value, including another NULL. Using `=` or `!=` with NULL does not yield expected results because NULL is undefined.
3. **Three-Valued Logic**: NULL comparisons in SQLite follow a three-valued logic: true, false, and unknown (for NULL). This affects how conditions with NULL are evaluated.

### Working with NULL in SQLite

#### Checking for NULL with IS NULL and IS NOT NULL

To check for NULL values in SQLite, use `IS NULL` or `IS NOT NULL` in the query. 

- **IS NULL**: Checks if a value is NULL.
- **IS NOT NULL**: Checks if a value is not NULL.

**Example**:
```sql
SELECT name, department_id
FROM employees
WHERE department_id IS NULL;
```

This query will return employees who do not have a `department_id` assigned.

#### Inserting NULL Values

You can insert NULL values explicitly using the keyword `NULL` or by omitting the column value if it allows NULL values.

**Example**:
```sql
INSERT INTO employees (name, department_id) VALUES ('Alice', NULL);
```

If `department_id` can accept NULLs, this command will insert a row with a NULL in the `department_id` column.

### NULL in Expressions and Calculations

NULL in any arithmetic or concatenation operation results in NULL.

**Example**:
```sql
SELECT name, salary * 1.1 AS increased_salary
FROM employees;
```

If an employee's `salary` is NULL, `increased_salary` will also be NULL.

### Handling NULL in Queries

1. **Using IFNULL**: The `IFNULL` function replaces NULL with a specified value.

   **Syntax**:
   ```sql
   IFNULL(expression, replacement)
   ```

   **Example**:
   ```sql
   SELECT name, IFNULL(department_id, 'Not Assigned') AS department
   FROM employees;
   ```

   This will display “Not Assigned” for employees without a `department_id`.

2. **Using COALESCE**: `COALESCE` returns the first non-NULL value in a list of arguments.

   **Syntax**:
   ```sql
   COALESCE(value1, value2, ..., valueN)
   ```

   **Example**:
   ```sql
   SELECT name, COALESCE(department_id, 'Unknown') AS department
   FROM employees;
   ```

   This query will display the `department_id` if available, otherwise “Unknown.”

3. **NULLIF Function**: `NULLIF` returns NULL if two expressions are equal; otherwise, it returns the first expression.

   **Syntax**:
   ```sql
   NULLIF(expression1, expression2)
   ```

   **Example**:
   ```sql
   SELECT name, NULLIF(department_id, 0) AS department
   FROM employees;
   ```

   This will return NULL if `department_id` is `0`, otherwise, it will return `department_id`.

### Sorting NULLs

When using `ORDER BY` with a column that contains NULLs, SQLite places NULL values at the end of the result set in ascending order by default, and at the beginning in descending order.

**Example**:
```sql
SELECT name, department_id
FROM employees
ORDER BY department_id ASC;
```

To explicitly control where NULLs appear, SQLite supports `NULLS FIRST` or `NULLS LAST`:

```sql
SELECT name, department_id
FROM employees
ORDER BY department_id ASC NULLS LAST;
```

### NULL in Aggregate Functions

Aggregate functions like `SUM`, `AVG`, `MAX`, `MIN`, and `COUNT` ignore NULL values, except for `COUNT(*)`, which counts all rows, including those with NULL values.

**Example**:
```sql
SELECT AVG(salary) AS average_salary FROM employees;
```

This calculates the average `salary` excluding any NULL `salary` values.

### Summary of SQLite NULL Handling

- NULL represents missing or undefined values, not equal to zero, an empty string, or a space.
- Use `IS NULL` or `IS NOT NULL` to check for NULL values.
- Functions like `IFNULL`, `COALESCE`, and `NULLIF` help manage and replace NULLs in query results.
- NULLs affect expressions, calculations, and comparisons, often leading to NULL results when involved.
- Aggregate functions ignore NULLs, with the exception of `COUNT(*)`.

Proper handling of NULL values is crucial in database operations, as it directly impacts query results and data integrity in SQLite.
