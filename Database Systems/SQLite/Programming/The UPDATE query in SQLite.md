The **`UPDATE`** query in SQLite is used to modify existing records in a table. This query allows you to change the values of one or more columns in one or more rows of a table based on a condition provided in the `WHERE` clause.

### Basic Syntax of the `UPDATE` Query

```sql
UPDATE table_name
SET column1 = value1, column2 = value2, ...
WHERE condition;
```

- **`table_name`**: The name of the table where you want to update data.
- **`SET`**: Specifies the columns to be updated and the new values to assign.
- **`column1 = value1`**: This updates `column1` with the new value `value1`.
- **`WHERE condition`**: Defines which rows to update. If no `WHERE` clause is provided, **all rows** in the table will be updated.

---

### Example 1: Simple `UPDATE` with One Column

Suppose we have a table called `employees` with columns `id`, `name`, and `age`, and we want to update the age of the employee with `id = 1`.

```sql
UPDATE employees
SET age = 30
WHERE id = 1;
```

This query will update the `age` of the employee with `id = 1` to 30.

---

### Example 2: `UPDATE` Multiple Columns

You can update multiple columns in the same `UPDATE` statement. For example, if you want to change both the `name` and `age` of an employee with `id = 2`, you can do the following:

```sql
UPDATE employees
SET name = 'John Doe', age = 35
WHERE id = 2;
```

This query will update both the `name` and `age` of the employee with `id = 2`.

---

### Example 3: Using a Condition in the `WHERE` Clause

In most cases, you will want to update only specific rows, which can be achieved by using a condition in the `WHERE` clause.

For example, to update the `age` of employees who are older than 40:

```sql
UPDATE employees
SET age = age + 1
WHERE age > 40;
```

This query increases the `age` by 1 for all employees whose age is greater than 40.

---

### Example 4: Using `UPDATE` Without a `WHERE` Clause

If you omit the `WHERE` clause, **all** records in the table will be updated. Be careful when doing this, as it can result in unintended changes to the entire table.

```sql
UPDATE employees
SET age = 25;
```

This query will set the `age` to 25 for **all employees** in the `employees` table.

---

### Example 5: Using Subqueries in `UPDATE` Statement

You can use a subquery in an `UPDATE` statement to dynamically determine the value to update a column with. For example, let's assume we have a `sales` table, and we want to update the `bonus` column based on the `total_sales` for each employee.

```sql
UPDATE employees
SET bonus = (SELECT total_sales * 0.1 FROM sales WHERE sales.employee_id = employees.id)
WHERE EXISTS (SELECT 1 FROM sales WHERE sales.employee_id = employees.id);
```

In this query:
- We use a subquery to calculate a bonus as 10% of the `total_sales` from the `sales` table.
- The `WHERE EXISTS` clause ensures that the update only happens if there is a matching entry in the `sales` table for the employee.

---

### Example 6: Updating Based on a Complex Condition

You can also combine `AND`, `OR`, and other logical operators to create complex conditions in the `WHERE` clause.

```sql
UPDATE employees
SET age = age + 1
WHERE department = 'Sales' AND hire_date < '2020-01-01';
```

This query will increase the `age` by 1 for all employees in the **Sales** department who were hired before **January 1, 2020**.

---

### Example 7: Updating a Column with a Calculated Value

You can update a column based on a calculation or transformation of existing values. For example, to increase the salary of all employees by 10%:

```sql
UPDATE employees
SET salary = salary * 1.10;
```

This query will update the `salary` column for all employees, increasing it by 10%.

---

### Best Practices

- **Always use a `WHERE` clause** unless you want to update all rows in the table. Without a `WHERE` clause, your update will apply to every row in the table.
- **Use transactions** when performing multiple updates to ensure data consistency. For example, you can wrap multiple `UPDATE` statements inside a `BEGIN TRANSACTION` and `COMMIT` block.
- **Backup your data** before performing large-scale updates, especially when using complex conditions, to avoid accidental data loss or corruption.

---

### Summary

- The **`UPDATE`** statement allows you to modify existing data in a table.
- You can update one or more columns at a time.
- The **`WHERE`** clause filters the rows to be updated.
- Omitting the `WHERE` clause will update all rows in the table.
- You can use subqueries, logical operators, and calculated values in the `UPDATE` query.

This powerful query allows you to make changes to data in your database efficiently, with the flexibility to apply complex conditions and calculations.
