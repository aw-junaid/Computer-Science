### MariaDB - Select Query

In MariaDB, the `SELECT` query is used to retrieve data from one or more tables in a database. It is the most commonly used query for querying and retrieving data from MariaDB.

### Basic Syntax

```sql
SELECT column1, column2, ...
FROM table_name
WHERE condition
ORDER BY column
LIMIT number_of_rows;
```

#### Parameters:
- **`column1, column2, ...`**: The columns to retrieve data from. You can list specific columns or use `*` to select all columns.
- **`table_name`**: The name of the table from which to retrieve data.
- **`WHERE`** (optional): Filters the rows based on a condition.
- **`ORDER BY`** (optional): Sorts the results by one or more columns.
- **`LIMIT`** (optional): Limits the number of rows returned.

---

### 1. **Selecting All Columns from a Table**

To retrieve all columns from a table, you can use `*` to select everything:

```sql
SELECT * FROM users;
```

This will return all rows and columns from the `users` table.

---

### 2. **Selecting Specific Columns**

If you only need to retrieve certain columns, you can list the column names:

```sql
SELECT first_name, last_name, email FROM users;
```

This will return only the `first_name`, `last_name`, and `email` columns from the `users` table.

---

### 3. **Filtering Data with WHERE Clause**

The `WHERE` clause is used to filter rows based on a specific condition.

Example:

```sql
SELECT * FROM users WHERE last_name = 'Doe';
```

This will return all columns for the rows where the `last_name` is "Doe".

You can also use logical operators like `AND`, `OR`, and comparison operators to combine multiple conditions:

```sql
SELECT * FROM users WHERE first_name = 'John' AND last_name = 'Doe';
```

---

### 4. **Sorting Results with ORDER BY**

The `ORDER BY` clause is used to sort the result set by one or more columns. By default, the sorting is in ascending order (`ASC`), but you can specify descending order (`DESC`).

Example:

```sql
SELECT * FROM users ORDER BY last_name ASC;
```

This will return all rows from the `users` table, sorted by the `last_name` column in ascending order.

To sort in descending order:

```sql
SELECT * FROM users ORDER BY last_name DESC;
```

You can also sort by multiple columns:

```sql
SELECT * FROM users ORDER BY last_name ASC, first_name DESC;
```

This sorts first by `last_name` in ascending order, and for rows with the same last name, it sorts by `first_name` in descending order.

---

### 5. **Limiting Results with LIMIT**

The `LIMIT` clause is used to restrict the number of rows returned.

Example:

```sql
SELECT * FROM users LIMIT 5;
```

This will return the first 5 rows from the `users` table.

You can also use `LIMIT` with `OFFSET` to retrieve a specific subset of rows. For example, to retrieve rows 6 to 10:

```sql
SELECT * FROM users LIMIT 5 OFFSET 5;
```

Or, you can use the shorthand:

```sql
SELECT * FROM users LIMIT 5, 5;
```

This will return 5 rows, starting from row 6.

---

### 6. **Using Wildcards in WHERE Clause (LIKE)**

The `LIKE` operator is used to search for a specified pattern in a column. You can use `%` to represent any sequence of characters, and `_` to represent a single character.

Example:

```sql
SELECT * FROM users WHERE first_name LIKE 'J%';
```

This will return all users whose `first_name` starts with "J" (e.g., "John", "Jane").

To find names that contain a specific substring:

```sql
SELECT * FROM users WHERE first_name LIKE '%oh%';
```

This will return all users whose `first_name` contains "oh" (e.g., "John", "Mohamed").

---

### 7. **Using IN for Multiple Conditions**

The `IN` operator is used to filter results based on a list of values.

Example:

```sql
SELECT * FROM users WHERE last_name IN ('Doe', 'Smith', 'Johnson');
```

This will return all users whose `last_name` is either "Doe", "Smith", or "Johnson".

---

### 8. **Using Aggregate Functions**

MariaDB provides aggregate functions to perform calculations on multiple rows of data.

- **COUNT()**: Returns the number of rows.
- **SUM()**: Returns the sum of values.
- **AVG()**: Returns the average of values.
- **MAX()**: Returns the maximum value.
- **MIN()**: Returns the minimum value.

Example:

```sql
SELECT COUNT(*) FROM users;
```

This will return the total number of rows in the `users` table.

To find the average age of users:

```sql
SELECT AVG(age) FROM users;
```

---

### 9. **GROUP BY Clause**

The `GROUP BY` clause is used to group rows that have the same values in specified columns into summary rows. It is often used with aggregate functions.

Example:

```sql
SELECT last_name, COUNT(*) FROM users GROUP BY last_name;
```

This will return the count of users for each `last_name`.

---

### 10. **HAVING Clause**

The `HAVING` clause is used to filter groups in a `GROUP BY` query, similar to how the `WHERE` clause is used to filter individual rows.

Example:

```sql
SELECT last_name, COUNT(*) FROM users GROUP BY last_name HAVING COUNT(*) > 1;
```

This will return only the last names that appear more than once in the `users` table.

---

### 11. **JOIN Queries**

You can use `JOIN` to combine rows from two or more tables based on a related column.

- **INNER JOIN**: Returns rows when there is a match in both tables.
- **LEFT JOIN**: Returns all rows from the left table, and matching rows from the right table (or NULL if there is no match).
- **RIGHT JOIN**: Returns all rows from the right table, and matching rows from the left table (or NULL if there is no match).
- **FULL JOIN**: Returns rows when there is a match in either left or right table.

Example of an `INNER JOIN` between two tables, `users` and `orders`:

```sql
SELECT users.first_name, users.last_name, orders.order_id
FROM users
INNER JOIN orders ON users.id = orders.user_id;
```

This will return a list of users along with their associated order IDs.

---

### Conclusion

The `SELECT` query in MariaDB is essential for querying and retrieving data from your database. Key elements of the `SELECT` query include:

- Retrieving all columns or specific columns.
- Filtering results using `WHERE`, `LIKE`, `IN`, etc.
- Sorting the results with `ORDER BY`.
- Limiting the number of results with `LIMIT`.
- Using aggregate functions like `COUNT()`, `SUM()`, and `AVG()`.
- Grouping data with `GROUP BY` and filtering groups with `HAVING`.
- Joining multiple tables with `JOIN`.

With these tools, you can construct powerful queries to retrieve, filter, and analyze your data in MariaDB.
