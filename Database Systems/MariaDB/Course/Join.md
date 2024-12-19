### MariaDB - JOIN

In MariaDB, a `JOIN` is used to combine rows from two or more tables based on a related column between them. It is commonly used to retrieve data from multiple tables in a single query, by linking them together using a shared key (usually a foreign key).

There are different types of joins in MariaDB:
- **INNER JOIN**
- **LEFT JOIN (or LEFT OUTER JOIN)**
- **RIGHT JOIN (or RIGHT OUTER JOIN)**
- **FULL JOIN (or FULL OUTER JOIN)**
- **CROSS JOIN**
- **SELF JOIN**

---

### 1. **INNER JOIN**

An `INNER JOIN` returns rows when there is at least one match in both tables. If no match is found, the row will not be included in the result.

#### Basic Syntax:

```sql
SELECT columns
FROM table1
INNER JOIN table2
ON table1.column = table2.column;
```

#### Example:

```sql
SELECT users.id, users.name, orders.order_date
FROM users
INNER JOIN orders
ON users.id = orders.user_id;
```

This will return only the users who have placed orders. The `INNER JOIN` ensures that the result includes only users who have a matching `user_id` in the `orders` table.

---

### 2. **LEFT JOIN (or LEFT OUTER JOIN)**

A `LEFT JOIN` returns all rows from the left table (table1) and the matched rows from the right table (table2). If no match is found, NULL values will be returned for columns from the right table.

#### Basic Syntax:

```sql
SELECT columns
FROM table1
LEFT JOIN table2
ON table1.column = table2.column;
```

#### Example:

```sql
SELECT users.id, users.name, orders.order_date
FROM users
LEFT JOIN orders
ON users.id = orders.user_id;
```

This will return all users, along with their orders if available. If a user has not placed any order, the result will still include the user, but with `NULL` values for the `order_date` column.

---

### 3. **RIGHT JOIN (or RIGHT OUTER JOIN)**

A `RIGHT JOIN` is the opposite of a `LEFT JOIN`. It returns all rows from the right table (table2) and the matched rows from the left table (table1). If no match is found, NULL values will be returned for columns from the left table.

#### Basic Syntax:

```sql
SELECT columns
FROM table1
RIGHT JOIN table2
ON table1.column = table2.column;
```

#### Example:

```sql
SELECT users.id, users.name, orders.order_date
FROM users
RIGHT JOIN orders
ON users.id = orders.user_id;
```

This will return all orders, along with the corresponding user details. If an order doesn't have a matching user (e.g., an order placed by an unknown user), the `users` columns will contain `NULL`.

---

### 4. **FULL JOIN (or FULL OUTER JOIN)**

A `FULL JOIN` returns all rows when there is a match in one of the tables. It returns **all rows from both tables**, with `NULL` values where there is no match.

**Note:** MariaDB does not directly support `FULL JOIN`. However, you can achieve a full outer join using a combination of `LEFT JOIN` and `RIGHT JOIN`.

#### Example (Simulating FULL JOIN):

```sql
SELECT users.id, users.name, orders.order_date
FROM users
LEFT JOIN orders ON users.id = orders.user_id
UNION
SELECT users.id, users.name, orders.order_date
FROM users
RIGHT JOIN orders ON users.id = orders.user_id;
```

This query uses the `UNION` operator to combine results from a `LEFT JOIN` and a `RIGHT JOIN`, ensuring that all rows from both tables are included, even if there are no matches.

---

### 5. **CROSS JOIN**

A `CROSS JOIN` returns the **Cartesian product** of the two tables. This means it combines each row from the first table with every row from the second table. A `CROSS JOIN` does not require a condition.

#### Basic Syntax:

```sql
SELECT columns
FROM table1
CROSS JOIN table2;
```

#### Example:

```sql
SELECT users.name, products.product_name
FROM users
CROSS JOIN products;
```

This will return every possible combination of `users.name` and `products.product_name`, which can result in a large number of rows if both tables have many records.

---

### 6. **SELF JOIN**

A `SELF JOIN` is a join where a table is joined with itself. It is useful when you have a hierarchical relationship or when you need to compare rows within the same table.

#### Basic Syntax:

```sql
SELECT a.column, b.column
FROM table a, table b
WHERE a.column = b.column;
```

#### Example:

```sql
SELECT e1.name AS Employee, e2.name AS Manager
FROM employees e1
JOIN employees e2
ON e1.manager_id = e2.id;
```

This example shows a self join where the `employees` table is joined with itself to retrieve each employee's manager.

---

### 7. **JOIN with Multiple Tables**

You can join more than two tables in a single query. You simply need to add more `JOIN` clauses and specify the condition for each one.

#### Example:

```sql
SELECT employees.name, departments.name, locations.city
FROM employees
INNER JOIN departments ON employees.department_id = departments.id
INNER JOIN locations ON departments.location_id = locations.id;
```

This query joins three tables:
1. `employees` to `departments` via `department_id`.
2. `departments` to `locations` via `location_id`.

---

### 8. **Using Aliases in JOINs**

You can use table aliases to make your SQL code more readable, especially when working with multiple tables.

#### Example:

```sql
SELECT u.name, o.order_date
FROM users u
INNER JOIN orders o ON u.id = o.user_id;
```

In this example, `users` is aliased as `u` and `orders` as `o`, making the query shorter and more readable.

---

### 9. **JOIN Conditions**

You can use various types of conditions in `JOIN` clauses, not just equality (`=`). For instance, you can use other comparison operators, such as `>`, `<`, `BETWEEN`, `IN`, etc.

#### Example:

```sql
SELECT orders.id, orders.total_amount, customers.name
FROM orders
INNER JOIN customers ON orders.customer_id = customers.id
WHERE orders.total_amount > 100;
```

This query joins the `orders` and `customers` tables and filters the results to include only orders with a total amount greater than 100.

---

### Summary of JOIN Types:

- **`INNER JOIN`**: Returns only matching rows from both tables.
- **`LEFT JOIN` (LEFT OUTER JOIN)**: Returns all rows from the left table and matching rows from the right table (NULL if no match).
- **`RIGHT JOIN` (RIGHT OUTER JOIN)**: Returns all rows from the right table and matching rows from the left table (NULL if no match).
- **`FULL JOIN` (FULL OUTER JOIN)**: Returns all rows from both tables, with NULLs for non-matching rows. (Not directly supported in MariaDB, but can be simulated).
- **`CROSS JOIN`**: Returns the Cartesian product of the tables, i.e., all combinations of rows.
- **`SELF JOIN`**: Joins a table with itself, often used for hierarchical relationships or comparing rows in the same table.

---

### Conclusion

`JOIN` is one of the most important features in SQL, enabling the combination of related data from multiple tables. Understanding the different types of joins and when to use them will help you efficiently query relational data in MariaDB. Whether you're linking data by foreign keys or performing more complex joins, MariaDB provides a range of options to meet your needs.
