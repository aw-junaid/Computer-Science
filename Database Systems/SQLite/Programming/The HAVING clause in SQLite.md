The **`HAVING`** clause in SQLite is used in conjunction with the **`GROUP BY`** clause to filter the results of grouped rows. While the **`WHERE`** clause is used to filter rows before the grouping operation, the **`HAVING`** clause filters groups after the grouping has been performed.

The `HAVING` clause is especially useful when you want to apply a condition on aggregate functions like `COUNT()`, `SUM()`, `AVG()`, `MIN()`, `MAX()`, etc. It allows you to filter out entire groups based on the results of these aggregate calculations.

### Syntax of the `HAVING` Clause

```sql
SELECT column_name(s), aggregate_function(column_name)
FROM table
WHERE condition
GROUP BY column_name
HAVING condition_on_aggregated_column;
```

- **`column_name(s)`**: The columns you want to retrieve.
- **`aggregate_function(column_name)`**: The aggregate function you want to apply to the grouped data (e.g., `COUNT()`, `SUM()`, `AVG()`).
- **`condition_on_aggregated_column`**: The condition that filters the groups created by `GROUP BY`, which usually involves an aggregate function.

---

### Example 1: Using `HAVING` with `COUNT()`

Let's say you have a table of `employees` and you want to find departments with more than 5 employees. You can use `HAVING` to filter groups based on the `COUNT()` aggregate function:

```sql
SELECT department, COUNT(*) AS num_employees
FROM employees
GROUP BY department
HAVING COUNT(*) > 5;
```

This query will return only those departments that have more than 5 employees.

---

### Example 2: Using `HAVING` with `SUM()`

If you want to find departments where the total salary exceeds $100,000, you can use the `SUM()` function in conjunction with `HAVING`:

```sql
SELECT department, SUM(salary) AS total_salary
FROM employees
GROUP BY department
HAVING SUM(salary) > 100000;
```

This query will return departments where the total salary paid to employees exceeds 100,000.

---

### Example 3: Using `HAVING` with `AVG()`

To find departments where the average salary is greater than 50,000:

```sql
SELECT department, AVG(salary) AS avg_salary
FROM employees
GROUP BY department
HAVING AVG(salary) > 50000;
```

This query will return departments where the average salary of employees is above 50,000.

---

### Example 4: Using `HAVING` with `MAX()` and `MIN()`

You can use `HAVING` to filter based on the results of `MAX()` or `MIN()` as well. For example, to find departments where the highest salary is greater than 100,000:

```sql
SELECT department, MAX(salary) AS highest_salary
FROM employees
GROUP BY department
HAVING MAX(salary) > 100000;
```

This query will return departments where the highest salary is above 100,000.

---

### Example 5: Filtering with `HAVING` and Multiple Conditions

You can combine multiple conditions in the `HAVING` clause. For example, to find departments with more than 10 employees and a total salary greater than 500,000:

```sql
SELECT department, COUNT(*) AS num_employees, SUM(salary) AS total_salary
FROM employees
GROUP BY department
HAVING COUNT(*) > 10 AND SUM(salary) > 500000;
```

This query will return departments where both conditions are true: there are more than 10 employees, and the total salary exceeds 500,000.

---

### Example 6: Using `HAVING` Without `GROUP BY`

While the `HAVING` clause is typically used with `GROUP BY`, it can also be used without `GROUP BY` to filter the result set based on an aggregate function. This is useful when you want to apply a condition to an aggregate function over the entire result set.

For example, if you want to find if the total salary of all employees exceeds 1,000,000:

```sql
SELECT SUM(salary) AS total_salary
FROM employees
HAVING SUM(salary) > 1000000;
```

This query will return the total salary for all employees if it exceeds 1,000,000.

---

### Difference Between `WHERE` and `HAVING`

- **`WHERE`**: Filters rows before grouping (i.e., it filters individual records before any aggregation happens).
- **`HAVING`**: Filters groups after the grouping operation (i.e., it filters aggregated results, like counts, sums, averages).

### Example of `WHERE` vs. `HAVING`

Let's say you want to find employees in each department where the total salary exceeds $100,000, but you only want to include employees with a salary greater than 30,000.

- **Using `WHERE` for individual employee filtering**:

```sql
SELECT department, SUM(salary) AS total_salary
FROM employees
WHERE salary > 30000
GROUP BY department
HAVING SUM(salary) > 100000;
```

Here, `WHERE salary > 30000` filters individual employees before they are grouped by department, and `HAVING` filters departments with total salaries greater than 100,000.

---

### Summary of `HAVING` Clause Usage

- **`HAVING`** is used to filter groups created by `GROUP BY`, often based on aggregate functions (e.g., `COUNT()`, `SUM()`, `AVG()`).
- **`WHERE`** filters rows before grouping, while **`HAVING`** filters groups after the grouping.
- **Common aggregate functions** used with `HAVING`:
  - `COUNT()`: Counts the number of rows.
  - `SUM()`: Adds up the values in a column.
  - `AVG()`: Calculates the average value of a column.
  - `MAX()`: Returns the maximum value in a column.
  - `MIN()`: Returns the minimum value in a column.
- **`HAVING`** can also be used without `GROUP BY` for filtering based on aggregate functions over the entire result set.

The **`HAVING`** clause is essential when you need to apply conditions to the results of aggregate functions or to filter grouped data. It enables you to refine the results based on calculations such as counts, sums, and averages.
