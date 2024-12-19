In Apache Derby, the `WHERE` clause is used to filter records from a table based on specified conditions. It allows you to specify criteria that must be met for a row to be included in the result set or affected by a `DELETE`, `UPDATE`, or `SELECT` statement. The `WHERE` clause can include one or more conditions combined using logical operators, comparison operators, and pattern matching.

### Basic Syntax of `WHERE` Clause
```sql
SELECT column1, column2, ...
FROM table_name
WHERE condition;
```
- **`column1, column2, ...`**: The columns you want to retrieve (for `SELECT` statements).
- **`table_name`**: The table from which to retrieve or modify data.
- **`condition`**: The condition that each row must satisfy to be included.

### Comparison Operators
You can use comparison operators in the `WHERE` clause to compare column values to constants or other column values.

- **`=`**: Equal to
- **`<>` or `!=`**: Not equal to
- **`>`**: Greater than
- **`<`**: Less than
- **`>=`**: Greater than or equal to
- **`<=`**: Less than or equal to

#### Example 1: Using Comparison Operators
```sql
SELECT name, hire_date
FROM employees
WHERE hire_date >= '2024-01-01';
```
- This retrieves employees whose `hire_date` is on or after `'2024-01-01'`.

### Logical Operators
You can combine multiple conditions using logical operators like `AND`, `OR`, and `NOT`.

- **`AND`**: Returns true if both conditions are true.
- **`OR`**: Returns true if at least one of the conditions is true.
- **`NOT`**: Reverses the result of a condition.

#### Example 2: Using `AND` and `OR`
```sql
SELECT name, hire_date
FROM employees
WHERE hire_date > '2023-01-01' AND department_id = 5;
```
- This retrieves employees hired after `'2023-01-01'` and who belong to department `5`.

```sql
SELECT name, hire_date
FROM employees
WHERE department_id = 5 OR department_id = 6;
```
- This retrieves employees who belong to either department `5` or department `6`.

### Pattern Matching with `LIKE`
The `LIKE` operator allows you to perform pattern matching on text columns. The percent sign (`%`) is used as a wildcard to match any number of characters, and the underscore (`_`) is used to match a single character.

#### Example 3: Using `LIKE`
```sql
SELECT name
FROM employees
WHERE name LIKE 'J%';
```
- This retrieves employees whose `name` starts with the letter "J".

```sql
SELECT name
FROM employees
WHERE name LIKE '%son';
```
- This retrieves employees whose `name` ends with "son".

```sql
SELECT name
FROM employees
WHERE name LIKE '_a%';
```
- This retrieves employees whose `name` has "a" as the second letter.

### Checking for Null Values with `IS NULL` and `IS NOT NULL`
You can use `IS NULL` and `IS NOT NULL` to check for `NULL` values in a column.

#### Example 4: Using `IS NULL` and `IS NOT NULL`
```sql
SELECT name
FROM employees
WHERE phone_number IS NULL;
```
- This retrieves employees whose `phone_number` is `NULL`.

```sql
SELECT name
FROM employees
WHERE phone_number IS NOT NULL;
```
- This retrieves employees who have a non-`NULL` `phone_number`.

### Using `IN` for Multiple Values
The `IN` operator allows you to check if a column’s value matches any value from a list of values.

#### Example 5: Using `IN`
```sql
SELECT name, department_id
FROM employees
WHERE department_id IN (1, 3, 5);
```
- This retrieves employees who belong to department `1`, `3`, or `5`.

### Using `BETWEEN` for Range Queries
The `BETWEEN` operator allows you to filter records within a specified range of values. The range is inclusive of the boundary values.

#### Example 6: Using `BETWEEN`
```sql
SELECT name, hire_date
FROM employees
WHERE hire_date BETWEEN '2024-01-01' AND '2024-12-31';
```
- This retrieves employees whose `hire_date` is between `'2024-01-01'` and `'2024-12-31'`.

### Using `EXISTS` for Subqueries
The `EXISTS` operator is used to check if a subquery returns any rows. It is typically used in situations where you want to check for the existence of related records in another table.

#### Example 7: Using `EXISTS`
```sql
SELECT name
FROM employees e
WHERE EXISTS (SELECT 1 FROM departments d WHERE e.department_id = d.department_id AND d.department_name = 'Sales');
```
- This retrieves employees who belong to the "Sales" department.

### Using `AND`/`OR` with Grouped Conditions
You can group conditions using parentheses to ensure the correct order of evaluation when combining `AND` and `OR`.

#### Example 8: Grouping Conditions
```sql
SELECT name, hire_date
FROM employees
WHERE (hire_date > '2023-01-01' AND department_id = 5) OR department_id = 6;
```
- This retrieves employees who either belong to department `6`, or were hired after `'2023-01-01'` and belong to department `5`.

### Combining Multiple Conditions
You can combine different types of conditions in a `WHERE` clause, such as using comparison operators, `LIKE`, `IN`, `BETWEEN`, and logical operators together.

#### Example 9: Combining Multiple Conditions
```sql
SELECT name, hire_date
FROM employees
WHERE hire_date BETWEEN '2024-01-01' AND '2024-12-31'
  AND department_id IN (1, 3, 5)
  AND name LIKE 'J%';
```
- This retrieves employees who were hired in 2024, belong to departments `1`, `3`, or `5`, and whose `name` starts with "J".

### Conclusion
The `WHERE` clause in Apache Derby allows you to filter rows based on specific conditions, making it a powerful tool for narrowing down your query results or for updating or deleting specific rows. By using operators like `=`, `<>`, `LIKE`, `IN`, `BETWEEN`, and combining conditions with logical operators (`AND`, `OR`, `NOT`), you can construct complex queries tailored to your needs.
