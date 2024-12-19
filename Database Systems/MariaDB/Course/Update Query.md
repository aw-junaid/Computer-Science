### MariaDB - UPDATE Query

The `UPDATE` statement in MariaDB is used to modify existing records in a table. It allows you to update one or more columns for specific rows that match a given condition.

### Basic Syntax

```sql
UPDATE table_name
SET column1 = value1, column2 = value2, ...
WHERE condition;
```

#### Parameters:
- **`table_name`**: The name of the table where the data is to be updated.
- **`column1, column2, ...`**: The columns to be updated.
- **`value1, value2, ...`**: The new values for the specified columns.
- **`condition`**: The condition that determines which rows should be updated. This is important to avoid updating all rows in the table.

---

### 1. **Updating a Single Column**

You can update a single column in a table. Here’s an example:

```sql
UPDATE users
SET email = 'john.doe@newdomain.com'
WHERE id = 1;
```

In this example:
- The `email` column of the `users` table is updated to "john.doe@newdomain.com" for the row where `id` equals 1.

---

### 2. **Updating Multiple Columns**

You can update multiple columns in the same query by separating them with commas:

```sql
UPDATE users
SET first_name = 'John', last_name = 'Smith', email = 'john.smith@domain.com'
WHERE id = 2;
```

This updates:
- `first_name` to "John"
- `last_name` to "Smith"
- `email` to "john.smith@domain.com"
- For the row where `id` equals 2.

---

### 3. **Updating Multiple Rows**

The `WHERE` clause determines which rows will be updated. If the condition matches multiple rows, they will all be updated.

Example:

```sql
UPDATE users
SET status = 'inactive'
WHERE last_login < '2023-01-01';
```

This query will update the `status` column to "inactive" for all users who haven't logged in since January 1, 2023.

---

### 4. **Using Arithmetic Operators in UPDATE**

You can perform arithmetic operations (such as addition, subtraction, multiplication, etc.) while updating a column's value.

Example:

```sql
UPDATE users
SET age = age + 1
WHERE last_name = 'Doe';
```

This query will increase the `age` of all users with the last name "Doe" by 1.

---

### 5. **Using Subqueries in UPDATE**

You can use a subquery to set a column value in the `UPDATE` statement. This is useful when you need to update a column based on values from another table.

Example:

```sql
UPDATE users
SET status = (SELECT status FROM user_status WHERE user_status.id = users.id)
WHERE EXISTS (SELECT 1 FROM user_status WHERE user_status.id = users.id);
```

In this case:
- The `status` column in the `users` table is updated based on the corresponding value in the `user_status` table, where both tables share the same `id`.

---

### 6. **Using `LIMIT` with UPDATE**

The `LIMIT` clause can be used with the `UPDATE` statement to restrict the number of rows affected by the query. This is particularly useful if you want to update only a certain number of rows.

Example:

```sql
UPDATE users
SET status = 'active'
WHERE last_login > '2023-01-01'
LIMIT 10;
```

This will update the `status` to "active" for the first 10 users whose `last_login` is after January 1, 2023.

---

### 7. **Using `CASE` Statements in UPDATE**

You can use the `CASE` statement inside an `UPDATE` query to perform conditional updates. This allows you to apply different updates depending on certain conditions.

Example:

```sql
UPDATE users
SET status = CASE
    WHEN last_login > '2023-01-01' THEN 'active'
    ELSE 'inactive'
END;
```

This will set:
- `status` to "active" for users who have logged in after January 1, 2023.
- `status` to "inactive" for users who haven't logged in since then.

---

### 8. **Update with Joins**

You can use a `JOIN` in an `UPDATE` statement to update rows in one table based on data from another table. This is useful when you need to update a table with values from another related table.

Example:

```sql
UPDATE users u
JOIN user_status s ON u.id = s.user_id
SET u.status = s.status
WHERE s.status = 'active';
```

In this case:
- The `status` column in the `users` table is updated based on the `status` from the `user_status` table, where the `status` is "active".

---

### 9. **Preventing Unintended Updates**

Without a `WHERE` clause, all rows in the table will be updated. To prevent updating all rows unintentionally, always make sure to include the appropriate condition in the `WHERE` clause.

#### Example of an unsafe update (without `WHERE` clause):

```sql
UPDATE users
SET status = 'inactive';
```

This query will set the `status` of **all** users to "inactive" because it lacks a `WHERE` clause. Always double-check your query before executing it.

---

### 10. **Rollback an Update**

If you are using MariaDB with transactions enabled (which is default in InnoDB), you can use `ROLLBACK` to undo an update within a transaction.

Example:

```sql
START TRANSACTION;
UPDATE users
SET status = 'active'
WHERE last_name = 'Doe';
-- If you want to undo the update before committing:
ROLLBACK;
```

If you execute `ROLLBACK`, the update will not be saved to the database. You can also use `COMMIT` to save changes permanently.

---

### 11. **Common Errors in UPDATE Queries**
- **No `WHERE` clause**: Failing to include a `WHERE` clause in an `UPDATE` statement can lead to updating all rows in the table.
- **Data type mismatch**: Ensure that the new value matches the data type of the column (e.g., trying to set a string value into a numeric column will cause an error).
- **Locking issues**: Updating large tables can lock rows, so be cautious when running updates in production environments.

---

### Conclusion

The `UPDATE` query is essential for modifying existing data in a table. It allows you to update one or more columns based on a condition, and can be combined with arithmetic, subqueries, joins, and conditional logic using `CASE` statements. Always be cautious when using `UPDATE` to ensure that the correct rows are being modified and that you're not unintentionally updating all rows in the table.

**Key Takeaways:**
- Use `WHERE` to filter which rows to update.
- Use `SET` to specify the columns and their new values.
- Perform calculations directly in the `UPDATE` statement.
- Ensure safe updates by testing your query and using transactions where appropriate.
