### MariaDB - NULL Values

In MariaDB (and SQL in general), `NULL` is a special marker used to indicate that a data value does not exist in the database. It is not the same as an empty string (`''`), a zero value (`0`), or a blank space (`' '`), and it represents the absence or unknown value of a field.

#### Key Points About NULL:
- `NULL` indicates **no value** or **unknown** value.
- `NULL` is not equal to any other value, including another `NULL`. This means `NULL = NULL` is not true. To check for `NULL`, specific SQL functions and conditions need to be used.
- `NULL` can be used in any data type (integer, string, date, etc.).

---

### 1. **Inserting NULL Values**

You can insert `NULL` values into a column if the column allows it (i.e., the column is not defined with `NOT NULL` constraint).

#### Example:

```sql
INSERT INTO employees (name, email, hire_date)
VALUES ('John Doe', NULL, '2024-01-01');
```

This inserts a record where the `email` field is `NULL`.

---

### 2. **Selecting NULL Values**

You can use `IS NULL` or `IS NOT NULL` to filter rows with or without `NULL` values.

#### Example (Selecting rows where a column is NULL):

```sql
SELECT * FROM employees
WHERE email IS NULL;
```

This query will return all employees whose `email` is `NULL`.

#### Example (Selecting rows where a column is NOT NULL):

```sql
SELECT * FROM employees
WHERE email IS NOT NULL;
```

This query will return all employees who have a non-`NULL` email.

---

### 3. **NULL in Conditions**

When dealing with `NULL` in conditions, be aware that regular comparison operators (`=`, `!=`, `>`, `<`, etc.) will not work directly with `NULL`. For example:

```sql
SELECT * FROM employees
WHERE email = NULL;  -- This will not return any results
```

To check for `NULL`, you must use `IS NULL` or `IS NOT NULL`.

---

### 4. **Handling NULL in SELECT Queries**

You can use `IFNULL()` or `COALESCE()` to replace `NULL` values with another value when selecting data.

#### Using `IFNULL()`:

The `IFNULL()` function returns a specified value if the expression is `NULL`; otherwise, it returns the expression itself.

```sql
SELECT name, IFNULL(email, 'No email provided') AS email
FROM employees;
```

This query will return "No email provided" instead of `NULL` for employees who do not have an email.

#### Using `COALESCE()`:

The `COALESCE()` function returns the first non-`NULL` value in a list of expressions.

```sql
SELECT name, COALESCE(email, phone, 'No contact available') AS contact
FROM employees;
```

This query will return the first non-`NULL` value from the `email` or `phone` columns for each employee, or 'No contact available' if both are `NULL`.

---

### 5. **NULL and Aggregation Functions**

Most aggregation functions in SQL (e.g., `COUNT()`, `SUM()`, `AVG()`) ignore `NULL` values. However, `COUNT()` can behave differently when used on a column containing `NULL` values.

#### Example:

```sql
SELECT COUNT(email) FROM employees;
```

This counts the number of non-`NULL` `email` values in the `employees` table.

#### Example (Counting all rows, including those with NULL values):

```sql
SELECT COUNT(*) FROM employees;
```

This counts all rows, including those with `NULL` values in any column.

#### Example (Calculating average while ignoring NULL):

```sql
SELECT AVG(salary) FROM employees;
```

This calculates the average salary, ignoring `NULL` values in the `salary` column.

---

### 6. **NULL and Sorting**

When sorting data, `NULL` values are treated as lower than any other value in **ascending** order (`ASC`) and higher than any other value in **descending** order (`DESC`).

#### Example (Sorting with `NULL` values):

```sql
SELECT name, email
FROM employees
ORDER BY email ASC;
```

In this query, employees with `NULL` emails will appear first in the result set when sorted in ascending order.

---

### 7. **NULL and JOINs**

When performing `JOIN` operations, `NULL` values can affect how the results are returned, especially in `LEFT JOIN` or `RIGHT JOIN` scenarios. A `NULL` in the joining column means no match was found.

#### Example (LEFT JOIN with NULL):

```sql
SELECT users.name, orders.order_id
FROM users
LEFT JOIN orders ON users.id = orders.user_id;
```

If a user has no orders, the result will show `NULL` for `order_id`.

---

### 8. **NULL Constraints**

When creating or altering a table, you can specify whether a column allows `NULL` values or not. 

- **`NOT NULL`**: Ensures the column cannot store `NULL` values.
- **`NULL`**: Allows the column to store `NULL` values (this is the default).

#### Example (Creating a table with NULL and NOT NULL constraints):

```sql
CREATE TABLE employees (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(100) NULL,
    hire_date DATE NOT NULL
);
```

In this example:
- `name` and `hire_date` cannot be `NULL`.
- `email` can be `NULL`.

---

### 9. **Replacing NULL During Data Insertion**

When inserting data, you can replace `NULL` with a default value.

#### Example:

```sql
INSERT INTO employees (name, email, hire_date)
VALUES ('Alice', NULLIF('alice@example.com', ''), '2024-01-01');
```

This will insert a `NULL` value for the `email` column if the provided value is an empty string.

---

### 10. **NULL in Comparison Expressions**

Sometimes, you might want to check if a value is either `NULL` or not using the `IS NULL` or `IS NOT NULL` conditions.

#### Example (Checking if a value is NULL):

```sql
SELECT * FROM employees
WHERE email IS NULL;
```

This will return employees where `email` is `NULL`.

#### Example (Checking if a value is NOT NULL):

```sql
SELECT * FROM employees
WHERE email IS NOT NULL;
```

This will return employees where `email` is **not** `NULL`.

---

### Conclusion

`NULL` values are important in MariaDB to represent missing, undefined, or inapplicable data. Understanding how to handle `NULL` values effectively will ensure that your queries behave as expected, especially when filtering, sorting, or performing calculations. Always remember that `NULL` is not the same as an empty string or zero and requires special handling using functions like `IS NULL`, `IS NOT NULL`, `IFNULL()`, and `COALESCE()`.
