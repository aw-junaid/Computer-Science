In SQLite, the **INDEXED BY** clause is used within a `SELECT` statement to explicitly specify which index should be used when querying a table. This clause gives you control over query optimization by instructing SQLite to use a particular index for a query, rather than relying on SQLite’s automatic index selection. The `INDEXED BY` clause can be especially useful when you want to fine-tune performance or test different indexes.

### Syntax of INDEXED BY Clause

```sql
SELECT columns
FROM table_name INDEXED BY index_name
WHERE conditions;
```

- **table_name**: The table being queried.
- **index_name**: The name of the index that SQLite must use for this query.

### Example Usage

Suppose we have an `employees` table with an index `idx_department_id` on the `department_id` column:

```sql
CREATE INDEX idx_department_id ON employees (department_id);
```

To ensure that this index is used in a query, we can use the `INDEXED BY` clause:

```sql
SELECT name
FROM employees INDEXED BY idx_department_id
WHERE department_id = 5;
```

**Explanation**: This query instructs SQLite to use the `idx_department_id` index specifically for locating rows with `department_id = 5`. SQLite will not use any other index for this query, even if other indexes could potentially optimize the query.

---

### Using the NOT INDEXED Clause

The **NOT INDEXED** clause can be used to specify that no indexes should be used for a query, even if there are indexes available on the columns involved. This might be useful when testing query performance without indexes, or if you know that a full table scan will be more efficient for a particular query.

**Syntax**:
```sql
SELECT columns
FROM table_name NOT INDEXED
WHERE conditions;
```

**Example**:
```sql
SELECT name
FROM employees NOT INDEXED
WHERE department_id = 5;
```

**Explanation**: This query explicitly tells SQLite not to use any indexes on the `employees` table, even though an index on `department_id` exists.

---

### When to Use INDEXED BY and NOT INDEXED

- **INDEXED BY**: Use when you know a specific index is optimal for a query and want to ensure it is used. This might be necessary when testing different indexes or if SQLite’s automatic index selection doesn’t choose the best option.
- **NOT INDEXED**: Use when you want to avoid index usage, perhaps for testing or if a full table scan is known to be faster.

### Considerations

- **Manual Control**: While `INDEXED BY` gives fine-grained control, SQLite’s query planner usually chooses the best index based on the query structure, table size, and data distribution. Use it when you need precise index control.
- **Query Optimization**: Using the `EXPLAIN QUERY PLAN` statement before and after adding `INDEXED BY` or `NOT INDEXED` can help analyze how indexes impact performance.

---

### Example: Comparing Query Plans

Without `INDEXED BY`:
```sql
EXPLAIN QUERY PLAN
SELECT name FROM employees WHERE department_id = 5;
```

With `INDEXED BY`:
```sql
EXPLAIN QUERY PLAN
SELECT name FROM employees INDEXED BY idx_department_id WHERE department_id = 5;
```

### Summary of INDEXED BY Clause in SQLite

- **INDEXED BY**: Forces SQLite to use a specified index in a query, overriding the default selection.
- **NOT INDEXED**: Prevents any index from being used in a query, forcing a full table scan.
- **Use Cases**: Best for performance testing, query optimization, or ensuring specific indexes are used or bypassed.

Using `INDEXED BY` and `NOT INDEXED` offers a way to control index usage on a per-query basis, providing flexibility for performance tuning and analysis.
