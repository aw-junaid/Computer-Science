In SQLite, the `SELECT` query is used to retrieve data from one or more tables in the database. It allows you to specify which columns to return, filter data with conditions, and manipulate the results with various clauses.

### Basic Syntax of `SELECT`

```sql
SELECT column1, column2, ...
FROM table_name;
```

- **`column1, column2, ...`**: The list of columns you want to retrieve. Use `*` to select all columns.
- **`table_name`**: The name of the table from which to retrieve data.

### Example 1: Basic `SELECT` Query

To select all columns from a table:

```sql
SELECT * FROM users;
```

This query retrieves all rows and all columns from the `users` table.

To select specific columns:

```sql
SELECT name, age FROM users;
```

This query retrieves only the `name` and `age` columns from the `users` table.

---

### Example 2: Filtering Results with `WHERE`

You can filter the results using the `WHERE` clause to return only the rows that meet a specific condition.

```sql
SELECT * FROM users
WHERE age > 30;
```

This retrieves all columns from the `users` table where the `age` is greater than 30.

You can combine multiple conditions using `AND` or `OR`:

```sql
SELECT * FROM users
WHERE age > 30 AND name LIKE 'A%';
```

This returns all columns for users who are older than 30 and have names starting with the letter 'A'.

---

### Example 3: Sorting Results with `ORDER BY`

You can sort the results using the `ORDER BY` clause. You can specify ascending (`ASC`, default) or descending (`DESC`) order.

```sql
SELECT * FROM users
ORDER BY age DESC;
```

This retrieves all columns from the `users` table and sorts the rows by `age` in descending order (from oldest to youngest).

To sort by multiple columns:

```sql
SELECT * FROM users
ORDER BY name ASC, age DESC;
```

This sorts first by `name` in ascending order, and if two names are the same, it sorts by `age` in descending order.

---

### Example 4: Limiting Results with `LIMIT`

The `LIMIT` clause is used to specify the number of rows to return.

```sql
SELECT * FROM users
LIMIT 5;
```

This retrieves only the first 5 rows from the `users` table.

You can also use `OFFSET` to skip a specific number of rows:

```sql
SELECT * FROM users
LIMIT 5 OFFSET 10;
```

This retrieves 5 rows starting from the 11th row (skipping the first 10 rows).

---

### Example 5: Using `DISTINCT` to Avoid Duplicates

If you want to return only distinct (unique) values, you can use the `DISTINCT` keyword:

```sql
SELECT DISTINCT age FROM users;
```

This returns a list of unique ages from the `users` table.

---

### Example 6: Aggregate Functions

SQLite supports various aggregate functions to perform calculations on a set of values, such as `COUNT`, `SUM`, `AVG`, `MIN`, and `MAX`.

1. **COUNT**: Counts the number of rows that match the query.

```sql
SELECT COUNT(*) FROM users;
```

This returns the total number of rows in the `users` table.

2. **SUM**: Sums the values of a column.

```sql
SELECT SUM(age) FROM users;
```

This returns the sum of all ages in the `users` table.

3. **AVG**: Computes the average of a column.

```sql
SELECT AVG(age) FROM users;
```

This returns the average age from the `users` table.

4. **MIN/MAX**: Finds the minimum or maximum value of a column.

```sql
SELECT MIN(age), MAX(age) FROM users;
```

This returns the minimum and maximum age values from the `users` table.

---

### Example 7: Grouping Results with `GROUP BY`

You can group rows by one or more columns using the `GROUP BY` clause. This is often used with aggregate functions to summarize data.

```sql
SELECT age, COUNT(*) 
FROM users
GROUP BY age;
```

This groups the rows by `age` and counts how many users have each age.

You can combine `GROUP BY` with `HAVING` to filter the grouped results:

```sql
SELECT age, COUNT(*) 
FROM users
GROUP BY age
HAVING COUNT(*) > 1;
```

This retrieves only ages that appear more than once in the `users` table.

---

### Example 8: Using `JOIN` to Combine Tables

SQLite supports several types of joins to combine rows from two or more tables based on related columns.

1. **INNER JOIN**: Returns only matching rows from both tables.

```sql
SELECT users.name, orders.order_date
FROM users
INNER JOIN orders ON users.id = orders.user_id;
```

This query returns the `name` from the `users` table and the `order_date` from the `orders` table where the `user_id` in the `orders` table matches the `id` in the `users` table.

2. **LEFT JOIN (or LEFT OUTER JOIN)**: Returns all rows from the left table and the matching rows from the right table. If no match is found, `NULL` is returned for columns from the right table.

```sql
SELECT users.name, orders.order_date
FROM users
LEFT JOIN orders ON users.id = orders.user_id;
```

This query retrieves all users, along with any orders they may have. If a user doesn't have an order, `NULL` will be returned for the `order_date`.

3. **RIGHT JOIN (SQLite does not support RIGHT JOIN)**: Unlike other databases, SQLite does not support `RIGHT JOIN`. However, you can simulate it by swapping the tables and using a `LEFT JOIN`.

---

### Example 9: Subqueries

A **subquery** is a query inside another query. You can use subqueries in the `WHERE`, `FROM`, or `SELECT` clause.

1. **Subquery in `WHERE` clause**:

```sql
SELECT name
FROM users
WHERE id IN (SELECT user_id FROM orders WHERE order_date > '2024-01-01');
```

This query retrieves the names of users who have placed orders after January 1, 2024.

2. **Subquery in `SELECT` clause**:

```sql
SELECT name, (SELECT MAX(age) FROM users) AS max_age
FROM users;
```

This retrieves the `name` of each user and also the maximum `age` from the `users` table in a new column `max_age`.

---

### Example 10: `CASE` Statement for Conditional Logic

You can use the `CASE` statement to perform conditional logic within your query.

```sql
SELECT name,
       CASE
           WHEN age < 18 THEN 'Minor'
           WHEN age >= 18 THEN 'Adult'
           ELSE 'Unknown'
       END AS age_group
FROM users;
```

This query categorizes users as "Minor" or "Adult" based on their `age`.

---

### Summary

The `SELECT` query in SQLite is a versatile command that allows you to:
- Retrieve data from tables.
- Filter results with the `WHERE` clause.
- Sort and limit results with `ORDER BY` and `LIMIT`.
- Perform calculations using aggregate functions like `COUNT`, `SUM`, and `AVG`.
- Group data with `GROUP BY` and filter grouped data with `HAVING`.
- Join multiple tables together using `INNER JOIN`, `LEFT JOIN`, etc.
- Use subqueries for more complex queries.
- Implement conditional logic with the `CASE` statement.

These capabilities make the `SELECT` query powerful and flexible for querying and analyzing data in SQLite.
