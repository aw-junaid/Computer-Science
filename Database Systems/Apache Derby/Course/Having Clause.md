In Apache Derby, the `HAVING` clause is used to filter the results of a `GROUP BY` query after the data has been grouped and aggregated. It works similarly to the `WHERE` clause but is specifically used to filter groups created by the `GROUP BY` clause, not individual rows.

While the `WHERE` clause filters rows before the grouping process, the `HAVING` clause filters the grouped results after aggregation. You generally use the `HAVING` clause with aggregate functions like `COUNT`, `SUM`, `AVG`, `MIN`, and `MAX`.

### Basic Syntax of `HAVING`
```sql
SELECT column1, column2, aggregate_function(column_name)
FROM table_name
WHERE condition
GROUP BY column1, column2
HAVING aggregate_condition;
```
- **`column1, column2, ...`**: The columns you want to group by.
- **`aggregate_function(column_name)`**: The aggregate function (e.g., `COUNT`, `SUM`, `AVG`, etc.) applied to the columns.
- **`WHERE`**: (Optional) The condition to filter rows before grouping.
- **`GROUP BY`**: The column(s) to group the rows by.
- **`HAVING`**: The condition to filter the groups after aggregation.

### Example 1: Using `HAVING` with `COUNT`
You can use `HAVING` to filter groups based on the result of an aggregate function such as `COUNT`.

```sql
SELECT department_id, COUNT(*)
FROM employees
GROUP BY department_id
HAVING COUNT(*) > 5;
```
- This query groups employees by `department_id` and returns only those departments where the number of employees is greater than 5.

### Example 2: Using `HAVING` with `SUM`
You can also use the `HAVING` clause to filter based on the sum of a column's values.

```sql
SELECT department_id, SUM(salary)
FROM employees
GROUP BY department_id
HAVING SUM(salary) > 100000;
```
- This query groups employees by `department_id` and returns only those departments where the total salary is greater than 100,000.

### Example 3: Using `HAVING` with `AVG`
The `HAVING` clause can be used to filter groups based on the average value of a column.

```sql
SELECT department_id, AVG(salary)
FROM employees
GROUP BY department_id
HAVING AVG(salary) > 50000;
```
- This query groups employees by `department_id` and returns departments where the average salary is greater than 50,000.

### Example 4: Using `HAVING` with `MIN` and `MAX`
You can filter groups based on the minimum or maximum values of a column.

```sql
SELECT department_id, MIN(salary), MAX(salary)
FROM employees
GROUP BY department_id
HAVING MAX(salary) > 80000;
```
- This query groups employees by `department_id` and returns departments where the maximum salary is greater than 80,000.

### Example 5: Combining `HAVING` with `WHERE`
You can use both `WHERE` and `HAVING` in a query. The `WHERE` clause filters the rows before grouping, while `HAVING` filters the results after grouping.

```sql
SELECT department_id, AVG(salary)
FROM employees
WHERE hire_date > '2020-01-01'
GROUP BY department_id
HAVING AVG(salary) > 50000;
```
- This query first filters employees who were hired after `'2020-01-01'` and then groups them by `department_id`. The result will only include departments where the average salary is greater than 50,000.

### Example 6: Using `HAVING` with Multiple Conditions
You can combine multiple conditions in the `HAVING` clause using logical operators like `AND` or `OR`.

```sql
SELECT department_id, AVG(salary), COUNT(*)
FROM employees
GROUP BY department_id
HAVING AVG(salary) > 50000 AND COUNT(*) > 10;
```
- This query groups employees by `department_id` and returns only those departments where the average salary is greater than 50,000 and the number of employees is greater than 10.

### Example 7: Using `HAVING` with `NULL` Values
You can also use `HAVING` to filter groups based on `NULL` values, though this is less common. For example, to find departments where the sum of salaries is `NULL`:

```sql
SELECT department_id, SUM(salary)
FROM employees
GROUP BY department_id
HAVING SUM(salary) IS NULL;
```
- This query returns departments where the sum of the salaries is `NULL`, which could happen if all employees in that department have `NULL` salaries.

### Important Notes:
1. **`HAVING` vs. `WHERE`**: The `WHERE` clause is used to filter rows before grouping, while the `HAVING` clause filters the results after aggregation. You cannot use aggregate functions in the `WHERE` clause, but you can in the `HAVING` clause.
2. **Order of Execution**: The general order of operations for SQL queries involving `GROUP BY` and `HAVING` is:
   - First, `WHERE` filters the rows.
   - Then, `GROUP BY` groups the rows.
   - After grouping, `HAVING` filters the grouped results.
3. **Use of Aggregate Functions**: The `HAVING` clause is typically used with aggregate functions to filter based on the result of those functions (like `COUNT`, `SUM`, `AVG`, etc.).
4. **`HAVING` for Non-Aggregated Columns**: You can use `HAVING` to filter based on non-aggregated columns, though this is less common. For example:
   ```sql
   SELECT department_id
   FROM employees
   GROUP BY department_id
   HAVING department_id = 5;
   ```
   - This query groups the employees by `department_id` and then returns only the group for department `5`.

### Conclusion
The `HAVING` clause in Apache Derby is a powerful tool for filtering the results of aggregated queries. It is used to apply conditions to groups formed by the `GROUP BY` clause, and it typically works in conjunction with aggregate functions like `COUNT`, `SUM`, `AVG`, `MIN`, and `MAX`. By using `HAVING` with `GROUP BY`, you can perform more advanced filtering based on the results of aggregation, enabling more sophisticated queries.
