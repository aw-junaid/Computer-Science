In Apache Derby, the `ORDER BY` clause is used to sort the result set of a query based on one or more columns, either in ascending (`ASC`) or descending (`DESC`) order. By default, the `ORDER BY` clause sorts the results in ascending order.

### Basic Syntax of `ORDER BY`
```sql
SELECT column1, column2, ...
FROM table_name
WHERE condition
ORDER BY column1 [ASC|DESC], column2 [ASC|DESC], ...;
```
- **`column1, column2, ...`**: The columns by which you want to order the result set.
- **`ASC`**: Specifies ascending order (this is the default).
- **`DESC`**: Specifies descending order.

### Example 1: Sorting Results by a Single Column
```sql
SELECT name, hire_date
FROM employees
ORDER BY hire_date;
```
- This query sorts the employees by their `hire_date` in **ascending** order (earliest hire dates first).

### Example 2: Sorting Results in Descending Order
```sql
SELECT name, salary
FROM employees
ORDER BY salary DESC;
```
- This query sorts the employees by their `salary` in **descending** order (highest salary first).

### Example 3: Sorting by Multiple Columns
You can sort the results by more than one column. The sorting happens in the order of columns listed in the `ORDER BY` clause.

```sql
SELECT name, department_id, salary
FROM employees
ORDER BY department_id ASC, salary DESC;
```
- This query sorts employees first by `department_id` in **ascending** order, and within each department, it sorts by `salary` in **descending** order (highest salary first).

### Example 4: Sorting with `NULL` Values
By default, `NULL` values are considered the lowest value when sorting in **ascending** order, and the highest value when sorting in **descending** order. However, you can explicitly control the order of `NULL` values using `NULLS FIRST` or `NULLS LAST`.

```sql
SELECT name, salary
FROM employees
ORDER BY salary DESC NULLS LAST;
```
- This query sorts employees by `salary` in **descending** order and places `NULL` values **last** in the result set.

```sql
SELECT name, salary
FROM employees
ORDER BY salary ASC NULLS FIRST;
```
- This query sorts employees by `salary` in **ascending** order and places `NULL` values **first** in the result set.

### Example 5: Sorting with `ORDER BY` and `GROUP BY`
You can use `ORDER BY` in combination with `GROUP BY` to sort the grouped results.

```sql
SELECT department_id, COUNT(*)
FROM employees
GROUP BY department_id
ORDER BY COUNT(*) DESC;
```
- This query counts the number of employees in each department and sorts the departments by the number of employees, in **descending** order (departments with the most employees appear first).

### Example 6: Sorting Alphabetically (String Columns)
For string columns, the `ORDER BY` clause will sort alphabetically by default (case-sensitive by default in most databases).

```sql
SELECT name
FROM employees
ORDER BY name ASC;
```
- This query sorts the employee names alphabetically in **ascending** order.

### Example 7: Sorting by Date or Time Columns
You can use `ORDER BY` to sort by date or time columns as well.

```sql
SELECT name, hire_date
FROM employees
ORDER BY hire_date DESC;
```
- This query sorts employees by their `hire_date` in **descending** order (most recent hires first).

### Example 8: Sorting Using Expressions
You can also order by expressions or computed values (e.g., sorting by a calculated column or using `CASE`).

```sql
SELECT name, salary, (salary * 0.1) AS bonus
FROM employees
ORDER BY bonus DESC;
```
- This query calculates a bonus for each employee based on their `salary` (10% of salary) and sorts the results by the calculated `bonus` in **descending** order.

### Example 9: Sorting with `DISTINCT`
If you're using the `DISTINCT` keyword to eliminate duplicate rows, you can still use the `ORDER BY` clause to sort the result set.

```sql
SELECT DISTINCT department_id
FROM employees
ORDER BY department_id ASC;
```
- This query returns unique department IDs from the `employees` table, sorted in **ascending** order.

### Important Notes:
1. **Default Sort Order**: The default sorting order is **ascending**. If you don't specify `ASC` or `DESC`, it will be sorted in ascending order.
2. **Multiple Columns**: When you specify multiple columns in the `ORDER BY` clause, the sorting is performed in the order of the columns. The first column is sorted first, then the second column is sorted within the groups formed by the first, and so on.
3. **NULL Handling**: You can explicitly specify how to handle `NULL` values in the result set using `NULLS FIRST` or `NULLS LAST`.
4. **Performance Considerations**: Sorting large datasets can be resource-intensive, especially when using multiple columns or complex expressions. Indexing the columns used in the `ORDER BY` clause can help improve performance.
5. **Case Sensitivity**: In Apache Derby, sorting for text columns is case-sensitive by default, meaning uppercase letters are sorted before lowercase letters.

### Conclusion
The `ORDER BY` clause in Apache Derby is a powerful tool for controlling the order of query results. It allows you to sort data in ascending or descending order, using one or more columns. By combining `ORDER BY` with other clauses like `GROUP BY`, you can create sophisticated queries that return data in the desired order, whether it's based on numerical values, strings, dates, or expressions.
