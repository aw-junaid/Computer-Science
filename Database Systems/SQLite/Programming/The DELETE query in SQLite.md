The **`DELETE`** query in SQLite is used to remove one or more rows from a table based on a specified condition in the `WHERE` clause. This query is useful when you need to remove data from your database. However, be careful when using the `DELETE` statement, as it **permanently removes** data from the table, and it cannot be undone unless a backup is available.

### Basic Syntax of the `DELETE` Query

```sql
DELETE FROM table_name
WHERE condition;
```

- **`table_name`**: The name of the table from which you want to delete data.
- **`WHERE condition`**: Specifies which rows should be deleted. If no `WHERE` clause is provided, **all rows** will be deleted from the table.

### Example 1: Deleting a Specific Row

Suppose we have a table called `employees` with columns `id`, `name`, and `age`. If we want to delete the employee with `id = 3`, the query would look like this:

```sql
DELETE FROM employees
WHERE id = 3;
```

This query will delete the row where the `id` is equal to 3.

---

### Example 2: Deleting Multiple Rows Based on a Condition

If you want to delete all employees who are older than 60, you can use the following query:

```sql
DELETE FROM employees
WHERE age > 60;
```

This will delete all employees whose `age` is greater than 60.

---

### Example 3: Deleting All Rows from a Table

If you want to delete all rows from a table, you can simply omit the `WHERE` clause. **Be very careful** with this, as it will delete **all records** in the table.

```sql
DELETE FROM employees;
```

This query will remove **all employees** from the `employees` table but will not remove the table itself.

---

### Example 4: Deleting with `IN` Clause

You can use the `IN` clause in the `DELETE` query to delete multiple rows that match one of several values. For example, if you want to delete employees with `id` values of 3, 5, and 7, you can use:

```sql
DELETE FROM employees
WHERE id IN (3, 5, 7);
```

This will delete the employees with `id` 3, 5, and 7.

---

### Example 5: Deleting with `NOT IN` Clause

Similarly, you can use `NOT IN` to delete rows that do **not** match certain values. For example, if you want to delete employees whose `id` is not in the list of 2, 4, and 6:

```sql
DELETE FROM employees
WHERE id NOT IN (2, 4, 6);
```

This will delete all employees except those with `id` values 2, 4, and 6.

---

### Example 6: Deleting with `AND` / `OR` Conditions

You can combine multiple conditions using **`AND`** and **`OR`** operators in the `WHERE` clause. For example, to delete all employees who are either older than 60 or work in the 'HR' department:

```sql
DELETE FROM employees
WHERE age > 60 OR department = 'HR';
```

This query will delete all employees who are either older than 60 or belong to the 'HR' department.

---

### Example 7: Using a Subquery in the `DELETE` Query

You can also use a subquery within the `DELETE` query to remove rows based on the result of another query. For example, to delete employees whose `id` exists in another table called `resignations`:

```sql
DELETE FROM employees
WHERE id IN (SELECT employee_id FROM resignations);
```

This query will delete all employees whose `id` matches an `employee_id` in the `resignations` table.

---

### Example 8: Deleting with a Complex Condition

You can use multiple conditions combined with logical operators. For example, to delete all employees in the 'Sales' department who were hired before 2010:

```sql
DELETE FROM employees
WHERE department = 'Sales' AND hire_date < '2010-01-01';
```

This will delete all employees in the **Sales** department hired before January 1, 2010.

---

### Important Considerations

- **Be careful with the `WHERE` clause**: Without a `WHERE` clause, all rows in the table will be deleted. If you want to avoid accidental deletion, always double-check your conditions.
  
- **Backup your data**: If you are performing a critical deletion, it's a good practice to back up the data before running the `DELETE` query.

- **Delete vs Truncate**: Unlike the `TRUNCATE` command in some other databases, `DELETE` in SQLite does not remove the table structure. It only removes the rows.

- **Foreign Key Constraints**: If your table has foreign key constraints, you might encounter issues when deleting rows that are referenced in another table. You can configure SQLite to handle cascading deletes, where deleting a row will automatically delete related rows in other tables. 

  To enable foreign key constraints in SQLite, you must run:

  ```sql
  PRAGMA foreign_keys = ON;
  ```

  This enables foreign key enforcement, allowing cascading delete behavior when set up in the table schema.

---

### Example with Foreign Key Cascading (Optional)

When using foreign keys, you can define the behavior for cascading deletes. For example, if you have a `departments` table and an `employees` table where `employees.department_id` is a foreign key referencing `departments.id`, you could set up a cascading delete:

```sql
CREATE TABLE departments (
    id INTEGER PRIMARY KEY,
    name TEXT
);

CREATE TABLE employees (
    id INTEGER PRIMARY KEY,
    name TEXT,
    department_id INTEGER,
    FOREIGN KEY (department_id) REFERENCES departments(id) ON DELETE CASCADE
);
```

With this setup, if you delete a department from the `departments` table, all employees in that department will automatically be deleted due to the `ON DELETE CASCADE` clause.

---

### Summary

- **`DELETE`** removes one or more rows from a table based on a condition.
- **Use the `WHERE` clause** to specify which rows to delete. Without it, all rows will be deleted.
- You can use **`IN`**, **`NOT IN`**, **`AND`**, **`OR`**, and **subqueries** to create complex conditions for deletion.
- **Always back up** your data before performing delete operations, especially for large-scale deletions.
- SQLite supports **foreign key constraints** with cascading deletes, which automatically delete related rows in other tables when a referenced row is deleted.
