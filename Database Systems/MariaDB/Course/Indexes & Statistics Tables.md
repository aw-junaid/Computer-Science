### MariaDB - Indexes & Statistics Tables

In MariaDB, **indexes** are used to speed up the retrieval of rows from a table by reducing the amount of data scanned during queries. Indexes play a crucial role in enhancing performance, especially for large tables. Additionally, **statistics tables** provide information about the distribution of data, which MariaDB uses for query optimization.

---

### 1. **Indexes in MariaDB**

An index in MariaDB is a data structure that allows the database to find rows more quickly based on column values. Indexes are typically used in **SELECT** queries to improve performance, but they can also be used to enforce constraints (e.g., **PRIMARY KEY**, **UNIQUE**).

#### Types of Indexes

1. **Primary Key Index**
   - A **primary key** is a unique identifier for each row in a table.
   - Every table can have only one primary key.
   - Automatically creates a **unique index** on the primary key column(s).
   
   ```sql
   CREATE TABLE employees (
       id INT PRIMARY KEY,
       name VARCHAR(100)
   );
   ```

2. **Unique Index**
   - A **unique index** ensures that all values in the indexed column(s) are distinct.
   - Unlike primary keys, a table can have multiple unique indexes.

   ```sql
   CREATE TABLE employees (
       id INT,
       email VARCHAR(100) UNIQUE
   );
   ```

3. **Normal Index**
   - A **normal index** is used to speed up data retrieval on non-unique columns.

   ```sql
   CREATE INDEX idx_name ON employees (name);
   ```

4. **Full-Text Index**
   - A **full-text index** allows for efficient full-text search on text-based columns (e.g., `TEXT`, `VARCHAR`).
   
   ```sql
   CREATE FULLTEXT INDEX idx_description ON products (description);
   ```

5. **Spatial Index**
   - **Spatial indexes** are used for spatial data types (e.g., `POINT`, `LINESTRING`, `POLYGON`), typically for geographic or geometric data.

   ```sql
   CREATE SPATIAL INDEX idx_location ON places (location);
   ```

6. **Composite Index**
   - A **composite index** is an index on multiple columns. It helps when queries filter or sort based on multiple columns.

   ```sql
   CREATE INDEX idx_name_email ON employees (name, email);
   ```

#### Syntax for Creating Indexes

```sql
CREATE INDEX index_name ON table_name (column1, column2, ...);
```

Example:

```sql
CREATE INDEX idx_name ON employees (name);
```

This creates an index named `idx_name` on the `name` column of the `employees` table.

#### Drop Index

To remove an index, you use the `DROP INDEX` command:

```sql
DROP INDEX index_name ON table_name;
```

Example:

```sql
DROP INDEX idx_name ON employees;
```

---

### 2. **How Indexes Work**

- **Index Structure**: MariaDB uses data structures like **B-trees** (balanced trees) or **hashes** to store indexes. A B-tree is commonly used for indexes on columns with range queries (e.g., `BETWEEN`, `>`, `<`), while hash indexes are more efficient for exact match queries.
  
- **Query Performance**: When a query is run, MariaDB will check if there are indexes available for the columns used in the query’s `WHERE` clause or in sorting (`ORDER BY`) or joining conditions (`JOIN`). If an index exists, MariaDB will use it to locate the data faster, without scanning the entire table.

- **Drawbacks of Indexes**:
  - **Disk Space**: Indexes consume disk space and memory.
  - **Insert/Update Overhead**: Whenever a row is inserted or updated, the associated indexes must also be updated, which may lead to performance overhead.
  - **Choice of Columns**: It's important to index the right columns. Indexing frequently searched columns can boost query performance, but unnecessary indexes might slow down write operations.

---

### 3. **Statistics Tables in MariaDB**

MariaDB uses **statistics tables** to store metadata about the database schema. These tables hold information that the query optimizer uses to create execution plans for SQL queries. The statistics are important for MariaDB to determine the most efficient way to execute a query.

#### Key Statistics Tables in MariaDB

1. **`information_schema.STATISTICS`**
   - This table contains information about indexes, including their names, types, and the columns they index.

   Example query to view statistics:

   ```sql
   SELECT * FROM information_schema.STATISTICS WHERE table_name = 'employees';
   ```

   This query shows index information for the `employees` table, including the index name, the indexed column, and whether the index is unique.

2. **`performance_schema.table_io_waits_summary_by_table`**
   - This table provides information about IO (input/output) waits for each table, including the number of reads and writes.

   Example query to view IO waits:

   ```sql
   SELECT * FROM performance_schema.table_io_waits_summary_by_table WHERE object_name = 'employees';
   ```

3. **`information_schema.INNODB_SYS_INDEXES`**
   - InnoDB tables store index statistics in the `INNODB_SYS_INDEXES` table.

   Example query:

   ```sql
   SELECT * FROM information_schema.INNODB_SYS_INDEXES WHERE NAME = 'idx_name';
   ```

4. **`performance_schema.events_statements_summary_by_digest`**
   - This table provides aggregated statistics about statements executed by the server, allowing you to analyze query performance.

   Example query:

   ```sql
   SELECT * FROM performance_schema.events_statements_summary_by_digest;
   ```

5. **`information_schema.tables`**
   - This table provides information about all tables in the database, including their statistics like the number of rows, and data length.

   Example query:

   ```sql
   SELECT table_name, table_rows FROM information_schema.tables WHERE table_schema = 'my_database';
   ```

---

### 4. **Optimizing Index Usage**

To optimize the use of indexes in MariaDB:

1. **Use Indexes for SELECT Queries**: Ensure frequently used `WHERE`, `ORDER BY`, and `JOIN` columns are indexed.
2. **Use EXPLAIN**: The `EXPLAIN` statement helps you understand how indexes are used in a query. It shows the execution plan and indicates whether indexes are being used or not.

   Example:

   ```sql
   EXPLAIN SELECT * FROM employees WHERE name = 'John';
   ```

3. **Avoid Over-Indexing**: Adding too many indexes can slow down write operations (inserts, updates, deletes). Index only the columns that are frequently queried.
4. **Reorganize Indexes**: Periodically reorganize or rebuild indexes to improve performance, especially for large tables.

   ```sql
   OPTIMIZE TABLE employees;
   ```

5. **Use Composite Indexes Wisely**: Composite indexes can improve performance when queries involve multiple columns. However, MariaDB will only use a composite index if the columns are specified in the same order as the index.

---

### 5. **Examples of Indexes and Usage**

- **Creating a primary key index**:

```sql
CREATE TABLE employees (
    id INT PRIMARY KEY,
    name VARCHAR(100)
);
```

- **Creating a unique index**:

```sql
CREATE TABLE employees (
    id INT,
    email VARCHAR(100) UNIQUE
);
```

- **Creating a normal index**:

```sql
CREATE INDEX idx_name ON employees (name);
```

- **Creating a composite index**:

```sql
CREATE INDEX idx_name_email ON employees (name, email);
```

- **Creating a full-text index**:

```sql
CREATE FULLTEXT INDEX idx_description ON products (description);
```

---

### Conclusion

Indexes and statistics tables are crucial components for optimizing performance in MariaDB. **Indexes** speed up data retrieval by reducing the number of rows that need to be scanned, while **statistics tables** help the query optimizer choose the most efficient query execution plan. Careful index design is essential, as unnecessary or poorly designed indexes can degrade performance, especially during write operations. Understanding how to use **EXPLAIN** and how to analyze **statistics tables** can help you ensure that your MariaDB instance is running as efficiently as possible.
