The **`index_list`** PRAGMA in SQLite provides information about all indexes associated with a specific table in the database. This is useful for identifying which indexes exist on a table, checking if they are unique, and seeing their names.

### Syntax of `index_list` PRAGMA

```sql
PRAGMA index_list(table_name);
```

- **`table_name`**: The name of the table for which you want to list indexes.

### Output of `index_list`

Running this PRAGMA returns a result set with the following columns:

1. **`seq`**: The sequence number of the index (starting from 0). This represents the order in which indexes were created.
2. **`name`**: The name of the index.
3. **`unique`**: Indicates if the index enforces uniqueness on its columns. A value of `1` means the index is unique, and `0` means it is not.
4. **`origin`**: The origin of the index, showing how it was created:
   - `c`: Created by the `CREATE INDEX` command.
   - `u`: Automatically created by a `UNIQUE` constraint.
   - `pk`: Automatically created by a `PRIMARY KEY` constraint.
5. **`partial`**: Indicates if the index is a partial index. A value of `1` means it is a partial index, and `0` means it is not.

### Example Usage of `index_list`

Suppose we have a table `employees` with the following structure:

```sql
CREATE TABLE employees (
    id INTEGER PRIMARY KEY,
    name TEXT,
    department TEXT,
    salary REAL,
    UNIQUE (name, department)
);
```

And we create an additional index on the `salary` column:

```sql
CREATE INDEX idx_salary ON employees (salary);
```

To list all indexes on the `employees` table, use:

```sql
PRAGMA index_list('employees');
```

This will return a result set like:

| seq | name               | unique | origin | partial |
|-----|---------------------|--------|--------|---------|
| 0   | sqlite_autoindex_employees_1 | 1      | u      | 0       |
| 1   | idx_salary         | 0      | c      | 0       |

Explanation:

- **`sqlite_autoindex_employees_1`**: This is an automatically generated index by SQLite to enforce the `UNIQUE` constraint on `(name, department)`.
- **`idx_salary`**: The index on the `salary` column that we created manually.
- **`unique`**: The `sqlite_autoindex_employees_1` index is unique (`unique = 1`), while `idx_salary` is not (`unique = 0`).
- **`origin`**: 
   - `u` for `sqlite_autoindex_employees_1`, indicating it was created by a `UNIQUE` constraint.
   - `c` for `idx_salary`, meaning it was created with the `CREATE INDEX` command.
- **`partial`**: Both indexes have `partial = 0`, meaning they are not partial indexes.

### Practical Uses of `index_list`

1. **Identifying Available Indexes**: Use `index_list` to quickly see all indexes on a table, which helps when optimizing queries.
  
2. **Index Maintenance**: Helps verify if the expected indexes are present and identify auto-created indexes by SQLite.

3. **Performance Tuning**: When tuning for performance, this PRAGMA is helpful to check if all the necessary indexes are unique and how they were created.

### Related PRAGMAs

- **`PRAGMA index_info(index_name)`**: Provides detailed information about the columns within a specific index.
- **`PRAGMA index_xinfo(index_name)`**: Similar to `index_info` but includes additional information, such as whether a column is sorted in descending order.

### Summary of `index_list` PRAGMA

- **Purpose**: Lists all indexes on a specified table, including information on whether they are unique, their origin, and if they are partial indexes.
- **Syntax**: `PRAGMA index_list(table_name);`
- **Use Cases**: Useful for identifying indexes on a table, understanding their uniqueness, and seeing how they were created, which is helpful for query optimization and database maintenance.
