In Apache Derby, the `SELECT` statement is used to retrieve data from one or more tables. The `SELECT` statement allows you to fetch specific columns, filter rows based on conditions, join multiple tables, and perform various operations like sorting, grouping, and aggregating data.

### Basic Syntax for `SELECT`
```sql
SELECT column1, column2, ...
FROM table_name
[WHERE condition]
[ORDER BY column_name [ASC|DESC]]
[LIMIT number];
```
- **`column1, column2, ...`**: The columns you want to retrieve.
- **`table_name`**: The name of the table from which to retrieve data.
- **`WHERE`**: (Optional) A condition that filters rows based on certain criteria.
- **`ORDER BY`**: (Optional) Sorts the result set by one or more columns.
- **`LIMIT`**: (Optional) Limits the number of rows returned.

### Example 1: Retrieving All Data from a Table
To retrieve all the data from a table, you can use the `SELECT *` statement, where `*` represents all columns.

```sql
SELECT * FROM employees;
```
- This will return all columns and all rows from the `employees` table.

### Example 2: Retrieving Specific Columns
If you want to retrieve only certain columns, you can specify those columns in the `SELECT` statement.

```sql
SELECT id, name, hire_date FROM employees;
```
- This will return only the `id`, `name`, and `hire_date` columns from the `employees` table.

### Example 3: Filtering Data with `WHERE`
You can filter the rows returned by the query using the `WHERE` clause to specify conditions.

```sql
SELECT id, name, hire_date 
FROM employees
WHERE hire_date > '2024-12-01';
```
- This will return the `id`, `name`, and `hire_date` columns for employees whose `hire_date` is later than `2024-12-01`.

### Example 4: Using Comparison Operators
You can use comparison operators such as `=`, `>`, `<`, `>=`, `<=`, and `<>` (not equal) in the `WHERE` clause.

```sql
SELECT name, hire_date 
FROM employees
WHERE id >= 3;
```
- This will return the `name` and `hire_date` of employees whose `id` is greater than or equal to `3`.

### Example 5: Sorting Data with `ORDER BY`
The `ORDER BY` clause is used to sort the result set by one or more columns. By default, it sorts in ascending (`ASC`) order, but you can specify descending (`DESC`) order as well.

```sql
SELECT name, hire_date 
FROM employees
ORDER BY hire_date DESC;
```
- This will return the `name` and `hire_date` of employees, sorted by `hire_date` in descending order (most recent hire dates first).

### Example 6: Limiting the Number of Rows with `LIMIT`
The `LIMIT` clause is used to limit the number of rows returned by the query. (Note: Apache Derby uses `FETCH FIRST` instead of `LIMIT`.)

```sql
SELECT name, hire_date 
FROM employees
ORDER BY hire_date DESC
FETCH FIRST 5 ROWS ONLY;
```
- This will return the `name` and `hire_date` of the first 5 employees sorted by their hire date in descending order.

### Example 7: Using `AND`, `OR`, and `NOT` in `WHERE`
You can combine multiple conditions using `AND`, `OR`, and `NOT` to filter rows more precisely.

```sql
SELECT id, name, hire_date 
FROM employees
WHERE hire_date > '2024-01-01' AND name LIKE 'J%';
```
- This will return the `id`, `name`, and `hire_date` of employees who were hired after `2024-01-01` and whose `name` starts with the letter "J".

### Example 8: Using `LIKE` for Pattern Matching
The `LIKE` operator allows you to filter data based on pattern matching.

```sql
SELECT name
FROM employees
WHERE name LIKE 'A%';
```
- This will return the names of all employees whose names start with the letter "A".

### Example 9: Using `IN` for Multiple Conditions
The `IN` operator allows you to check if a column's value matches any value in a specified list.

```sql
SELECT id, name
FROM employees
WHERE id IN (1, 3, 5);
```
- This will return the `id` and `name` of employees with `id` 1, 3, or 5.

### Example 10: Using `BETWEEN` for Range Queries
The `BETWEEN` operator is used to filter data within a certain range.

```sql
SELECT name, hire_date
FROM employees
WHERE hire_date BETWEEN '2024-01-01' AND '2024-12-31';
```
- This will return the `name` and `hire_date` of employees hired between `2024-01-01` and `2024-12-31`.

### Example 11: Aggregating Data with `GROUP BY`
You can use `GROUP BY` to group rows that have the same values in specified columns, and then aggregate data with functions like `COUNT()`, `SUM()`, `AVG()`, `MIN()`, and `MAX()`.

```sql
SELECT department_id, COUNT(*) AS num_employees
FROM employees
GROUP BY department_id;
```
- This will return the number of employees (`num_employees`) in each department (`department_id`).

### Example 12: Filtering Groups with `HAVING`
The `HAVING` clause is used to filter groups created by `GROUP BY`. It is similar to `WHERE`, but is used for filtering after grouping the data.

```sql
SELECT department_id, COUNT(*) AS num_employees
FROM employees
GROUP BY department_id
HAVING COUNT(*) > 5;
```
- This will return the departments that have more than 5 employees.

### Example 13: Joining Tables
You can use `JOIN` to combine rows from two or more tables based on a related column.

```sql
SELECT e.name, d.department_name
FROM employees e
JOIN departments d ON e.department_id = d.department_id;
```
- This will return the `name` of each employee along with their `department_name` by joining the `employees` and `departments` tables on the `department_id`.

### Example 14: Using `INNER JOIN`, `LEFT JOIN`, `RIGHT JOIN`
- **`INNER JOIN`**: Returns rows when there is a match in both tables.
- **`LEFT JOIN`**: Returns all rows from the left table, and the matched rows from the right table.
- **`RIGHT JOIN`**: Returns all rows from the right table, and the matched rows from the left table.

```sql
-- Inner Join Example
SELECT e.name, d.department_name
FROM employees e
INNER JOIN departments d ON e.department_id = d.department_id;

-- Left Join Example
SELECT e.name, d.department_name
FROM employees e
LEFT JOIN departments d ON e.department_id = d.department_id;

-- Right Join Example
SELECT e.name, d.department_name
FROM employees e
RIGHT JOIN departments d ON e.department_id = d.department_id;
```

### Conclusion
The `SELECT` statement in Apache Derby is a powerful tool for retrieving data from tables with flexibility. You can filter, sort, and aggregate data, and you can also join tables to combine data from multiple sources. Using the `WHERE`, `ORDER BY`, `GROUP BY`, and `HAVING` clauses, along with various operators like `LIKE`, `IN`, and `BETWEEN`, you can tailor your queries to suit a wide range of needs.
