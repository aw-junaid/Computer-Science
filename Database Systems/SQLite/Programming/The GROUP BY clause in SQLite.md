The **`GROUP BY`** clause in SQLite is used to group rows that have the same values in specified columns into summary rows. This is typically used with aggregate functions like `COUNT()`, `SUM()`, `AVG()`, `MIN()`, and `MAX()` to perform operations on each group of data.

The `GROUP BY` clause allows you to analyze data in groups, making it an essential tool for tasks like generating reports, computing averages, or summarizing datasets.

### Syntax of the `GROUP BY` Clause

```sql
SELECT column_name(s), aggregate_function(column_name)
FROM table
WHERE condition
GROUP BY column_name;
```

- **`column_name(s)`**: The column(s) you want to select.
- **`aggregate_function(column_name)`**: The aggregate function you want to apply to the grouped data (e.g., `COUNT()`, `SUM()`, `AVG()`).
- **`table`**: The table from which to retrieve the data.
- **`condition`**: Optional filter using the `WHERE` clause to narrow down the results.
- **`GROUP BY column_name`**: The column by which to group the rows.

---

### Example 1: Using `GROUP BY` with `COUNT()`

Suppose you have a table of `employees`, and you want to know how many employees are in each department. You would group the results by `department` and use the `COUNT()` aggregate function to count the number of employees in each department:

```sql
SELECT department, COUNT(*) AS num_employees
FROM employees
GROUP BY department;
```

This query will return the number of employees in each department.

---

### Example 2: Using `GROUP BY` with `SUM()`

If you want to find the total salary for each department, you can use the `SUM()` function in conjunction with `GROUP BY`:

```sql
SELECT department, SUM(salary) AS total_salary
FROM employees
GROUP BY department;
```

This query will return the total salary paid in each department.

---

### Example 3: Using `GROUP BY` with `AVG()`

To find the average salary for each department:

```sql
SELECT department, AVG(salary) AS avg_salary
FROM employees
GROUP BY department;
```

This query will return the average salary for each department.

---

### Example 4: Using `GROUP BY` with `MAX()` and `MIN()`

If you want to find the highest and lowest salary in each department:

```sql
SELECT department, MAX(salary) AS highest_salary, MIN(salary) AS lowest_salary
FROM employees
GROUP BY department;
```

This query will return the highest and lowest salaries for each department.

---

### Example 5: Using `GROUP BY` with `HAVING`

The **`HAVING`** clause is used to filter the groups created by `GROUP BY`. While the `WHERE` clause filters rows before the grouping, the `HAVING` clause filters the groups after they have been created.

For example, if you only want to see departments where the total salary is greater than 100,000, you can use `HAVING`:

```sql
SELECT department, SUM(salary) AS total_salary
FROM employees
GROUP BY department
HAVING total_salary > 100000;
```

This query will return only the departments where the total salary exceeds 100,000.

---

### Example 6: Grouping by Multiple Columns

You can also group by multiple columns. For instance, if you want to find the total salary for each combination of `department` and `job_title`:

```sql
SELECT department, job_title, SUM(salary) AS total_salary
FROM employees
GROUP BY department, job_title;
```

This query will return the total salary for each unique combination of department and job title.

---

### Example 7: Using `GROUP BY` with `DISTINCT`

If you want to find the unique departments in the `employees` table, you can use `DISTINCT` along with `GROUP BY`:

```sql
SELECT DISTINCT department
FROM employees;
```

While this doesn't require aggregation, it ensures that only unique departments are returned.

---

### Example 8: Grouping with `ORDER BY`

You can combine the `GROUP BY` clause with the `ORDER BY` clause to sort the grouped results. For example, if you want to find the total salary for each department and sort the result by the total salary in descending order:

```sql
SELECT department, SUM(salary) AS total_salary
FROM employees
GROUP BY department
ORDER BY total_salary DESC;
```

This query will return the departments with the highest total salary at the top.

---

### Summary of `GROUP BY` Usage

- **Basic Grouping**: The `GROUP BY` clause groups rows with the same value in specified columns, allowing you to apply aggregate functions like `COUNT()`, `SUM()`, `AVG()`, `MIN()`, or `MAX()`.
- **Multiple Columns**: You can group by more than one column.
- **`HAVING` Clause**: After grouping the results, the `HAVING` clause can be used to filter the groups, similar to how `WHERE` is used for filtering individual rows.
- **Ordering Groups**: The `ORDER BY` clause can be used to sort the grouped results.
- **Aggregate Functions**: Common aggregate functions to use with `GROUP BY` are:
  - `COUNT()`: Counts the number of rows.
  - `SUM()`: Adds up the values in a column.
  - `AVG()`: Calculates the average value of a column.
  - `MAX()`: Returns the maximum value in a column.
  - `MIN()`: Returns the minimum value in a column.

#### Common Scenarios:
- **Counting the number of items in each group**: `GROUP BY department, COUNT(*)`
- **Summing or averaging values in each group**: `GROUP BY category, SUM(amount)`
- **Filtering grouped results**: `HAVING COUNT(*) > 10`
  
The `GROUP BY` clause is powerful when you need to organize data into logical groups and perform calculations or summaries for each group.
