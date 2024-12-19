### MariaDB - DELETE Query

The `DELETE` query in MariaDB is used to remove one or more records from a table. This query can be used to delete a single row, multiple rows, or all rows in a table, depending on the conditions specified in the `WHERE` clause.

### Basic Syntax

```sql
DELETE FROM table_name
WHERE condition;
```

#### Parameters:
- **`table_name`**: The name of the table from which the data will be deleted.
- **`condition`**: The condition that specifies which rows should be deleted. Without a `WHERE` clause, all rows in the table will be deleted.

---

### 1. **Deleting a Single Row**

To delete a single row based on a specific condition:

```sql
DELETE FROM users
WHERE id = 1;
```

In this example:
- The row where `id` equals 1 will be deleted from the `users` table.

---

### 2. **Deleting Multiple Rows**

You can delete multiple rows by specifying a condition that matches multiple rows.

Example:

```sql
DELETE FROM users
WHERE last_login < '2023-01-01';
```

This query deletes all users who have not logged in since January 1, 2023.

---

### 3. **Deleting All Rows**

If you want to delete all rows from a table, but keep the table structure intact, you can omit the `WHERE` clause.

```sql
DELETE FROM users;
```

This will delete **all rows** in the `users` table, but the table will remain in the database.

---

### 4. **Using `LIMIT` with DELETE**

You can limit the number of rows to delete using the `LIMIT` clause. This is useful if you want to delete only a specific number of rows.

Example:

```sql
DELETE FROM users
WHERE status = 'inactive'
LIMIT 10;
```

This will delete up to 10 rows from the `users` table where the `status` is 'inactive'.

---

### 5. **Deleting with Joins**

You can use a `JOIN` in a `DELETE` statement to delete rows based on conditions from other tables.

Example:

```sql
DELETE users
FROM users
JOIN orders ON users.id = orders.user_id
WHERE orders.order_date < '2023-01-01';
```

In this query:
- The `DELETE` is applied to the `users` table based on the `orders` table.
- It deletes users who have placed orders before January 1, 2023.

---

### 6. **Using Subqueries in DELETE**

You can also use a subquery to specify which rows to delete based on data from another table.

Example:

```sql
DELETE FROM users
WHERE id IN (SELECT user_id FROM orders WHERE order_date < '2023-01-01');
```

This query deletes users who have placed orders before January 1, 2023, using a subquery.

---

### 7. **Cascade Deletion (Foreign Key Constraints)**

If your table has foreign key constraints with `ON DELETE CASCADE`, deleting a row in the parent table can automatically delete related rows in the child table.

Example:

```sql
DELETE FROM users
WHERE id = 1;
```

If the `users` table is the parent table with a foreign key reference to the `orders` table with the `ON DELETE CASCADE` option, deleting the user with `id = 1` will automatically delete all orders associated with that user.

---

### 8. **Rollback a DELETE (Transactions)**

If you are working within a transaction, you can use `ROLLBACK` to undo a `DELETE` operation before committing it to the database.

Example:

```sql
START TRANSACTION;

DELETE FROM users
WHERE id = 1;

-- If you want to undo the delete before committing:
ROLLBACK;
```

If you execute `ROLLBACK`, the deletion will not be saved. Otherwise, you can use `COMMIT` to permanently save the changes.

---

### 9. **Performance Considerations**

- **DELETE and Large Tables**: Deleting a large number of rows can lock the table and affect performance. Consider using batching (with `LIMIT` or pagination) to delete large datasets incrementally.
- **Foreign Key Constraints**: Ensure that foreign key constraints are handled properly. For example, cascading deletes might affect related rows in other tables.
- **Indexes**: Deleting rows from indexed tables can be slower than from non-indexed tables, as the indexes need to be updated.

---

### 10. **Common Errors with DELETE Queries**

- **No `WHERE` Clause**: Omitting the `WHERE` clause will delete **all rows** in the table. Always ensure that the `WHERE` clause is correctly specified to avoid unintended deletions.
- **Referential Integrity**: If you attempt to delete a row that is referenced by another table (with a foreign key), and the foreign key is not set to cascade, you might receive an error or have an unsuccessful deletion.

---

### Example Summary

1. **Delete a specific record**:
    ```sql
    DELETE FROM users WHERE id = 3;
    ```

2. **Delete multiple records based on condition**:
    ```sql
    DELETE FROM users WHERE last_login < '2023-01-01';
    ```

3. **Delete all records**:
    ```sql
    DELETE FROM users;
    ```

4. **Delete using subquery**:
    ```sql
    DELETE FROM users WHERE id IN (SELECT user_id FROM orders WHERE order_date < '2023-01-01');
    ```

5. **Delete with `LIMIT`**:
    ```sql
    DELETE FROM users WHERE status = 'inactive' LIMIT 5;
    ```

---

### Conclusion

The `DELETE` statement in MariaDB is a powerful tool for removing data from a table. It is important to use the `WHERE` clause carefully to avoid deleting unintended rows. You can also use `LIMIT` to control the number of deleted rows, subqueries to delete based on related data, and joins for more complex deletion logic.

Always ensure that your `DELETE` queries are precise, especially in production environments, to prevent accidental data loss.
