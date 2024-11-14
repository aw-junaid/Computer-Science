In SQLite, the **`PRAGMA`** statement is used to query and set various configuration options for the SQLite database. It allows you to interact with the database engine to modify its behavior or retrieve internal information about the database.

The **`PRAGMA`** statements are typically used for database management tasks such as modifying performance settings, controlling database file settings, or checking the current state of the database.

### Syntax of `PRAGMA`

```sql
PRAGMA pragma_name [parameters];
```

- **`pragma_name`**: The name of the PRAGMA command you want to use.
- **`parameters`**: Optional parameters that are used with certain PRAGMA commands to specify settings or conditions.

### Common `PRAGMA` Commands

Here are some commonly used **`PRAGMA`** commands in SQLite:

---

### 1. **`PRAGMA database_list`**

The **`database_list`** command returns information about the databases attached to the current SQLite connection. It provides the name of the database and its associated file path.

```sql
PRAGMA database_list;
```

Example output:

| seq | name  | file                |
|-----|-------|---------------------|
| 0   | main  | /path/to/database.db |
| 1   | temp  | /path/to/temp.db     |

- **`main`**: The default database.
- **`temp`**: The temporary database, often used for intermediate data.

---

### 2. **`PRAGMA table_info(table_name)`**

The **`table_info`** command retrieves information about the columns of a given table, such as column names, data types, and whether they can be `NULL`.

```sql
PRAGMA table_info(employees);
```

Example output:

| cid | name      | type    | notnull | dflt_value | pk |
|-----|-----------|---------|---------|------------|----|
| 0   | id        | INTEGER | 0       | NULL       | 1  |
| 1   | name      | TEXT    | 0       | NULL       | 0  |
| 2   | salary    | REAL    | 0       | NULL       | 0  |

This command returns column definitions for the `employees` table, including:
- **`cid`**: Column ID (internal representation).
- **`name`**: Column name.
- **`type`**: Data type of the column.
- **`notnull`**: Whether the column can be `NULL` (1 = `NOT NULL`, 0 = `NULL` allowed).
- **`dflt_value`**: Default value for the column.
- **`pk`**: Whether the column is part of the primary key (1 = yes, 0 = no).

---

### 3. **`PRAGMA foreign_keys`**

This command controls the enforcement of foreign key constraints. By default, foreign key constraints are disabled in SQLite. To enable them, you must use this PRAGMA:

```sql
PRAGMA foreign_keys = ON;
```

To check if foreign key constraints are enabled:

```sql
PRAGMA foreign_keys;
```

Example output:

```
1
```

(1 means enabled, 0 means disabled)

**Note**: Foreign key constraints are only enforced if they are enabled and the database is in **WAL** (Write-Ahead Logging) mode.

---

### 4. **`PRAGMA cache_size`**

The **`cache_size`** command allows you to set or retrieve the number of pages in the database cache. The database cache is used to store database pages in memory for faster access.

```sql
PRAGMA cache_size = 1000;
```

This command sets the cache size to 1000 pages. You can retrieve the current cache size with:

```sql
PRAGMA cache_size;
```

Example output:

```
2000
```

This will return the current cache size in number of pages.

---

### 5. **`PRAGMA synchronous`**

The **`synchronous`** PRAGMA controls the durability of the database. It determines how SQLite handles transactions in terms of safety and performance.

```sql
PRAGMA synchronous = FULL;
```

The `synchronous` setting can take one of the following values:
- **`OFF`**: No sync is performed (fastest but least safe).
- **`NORMAL`**: The default. Syncing occurs in most cases, but not all.
- **`FULL`**: Ensures that all writes to the database are fully synced (safest but slowest).

To check the current setting:

```sql
PRAGMA synchronous;
```

Example output:

```
2
```

Where:
- `0` = OFF
- `1` = NORMAL
- `2` = FULL

---

### 6. **`PRAGMA journal_mode`**

The **`journal_mode`** command specifies the journal mode for the database, which controls how changes are written to the database file.

```sql
PRAGMA journal_mode = WAL;
```

Common journal modes are:
- **`DELETE`** (default): Simple rollback journal.
- **`TRUNCATE`**: Uses the same rollback journal but truncates it when the transaction is committed.
- **`PERSIST`**: Prevents the journal file from being deleted after the transaction.
- **`WAL`** (Write-Ahead Logging): Provides better concurrency, and is the preferred mode for most use cases.

To check the current journal mode:

```sql
PRAGMA journal_mode;
```

Example output:

```
wal
```

---

### 7. **`PRAGMA encoding`**

The **`encoding`** PRAGMA returns the text encoding used by the database. SQLite supports UTF-8, UTF-16, and UTF-16LE encodings.

```sql
PRAGMA encoding;
```

Example output:

```
UTF-8
```

---

### 8. **`PRAGMA user_version`**

The **`user_version`** PRAGMA can be used to set or get the user-defined version of the database. This is often used for tracking schema versions.

To retrieve the current user version:

```sql
PRAGMA user_version;
```

To set the user version to `2`:

```sql
PRAGMA user_version = 2;
```

---

### 9. **`PRAGMA optimize`**

The **`optimize`** command is used to perform an optimization of the database, improving performance by defragmenting the database and cleaning up unused space.

```sql
PRAGMA optimize;
```

This command is useful for improving the database's performance over time, especially after performing many updates or deletions.

---

### 10. **`PRAGMA temp_store`**

The **`temp_store`** PRAGMA controls whether temporary tables and indices are stored in memory or on disk.

```sql
PRAGMA temp_store = MEMORY;
```

You can set the value to:
- **`DEFAULT`**: Use the default storage location.
- **`MEMORY`**: Store temporary tables in memory.
- **`FILE`**: Store temporary tables on disk.

To check the current setting:

```sql
PRAGMA temp_store;
```

Example output:

```
1
```

Where:
- `1` = MEMORY
- `0` = FILE
- `2` = DEFAULT

---

### Summary of `PRAGMA` Usage

- **Configuration and Behavior**: The `PRAGMA` command is used to configure settings such as foreign key enforcement, journal modes, and synchronization behavior.
- **Database Information**: It can provide useful information about the structure and settings of the database (e.g., `PRAGMA table_info`, `PRAGMA foreign_keys`).
- **Performance Tuning**: Use PRAGMAs like `cache_size`, `synchronous`, and `journal_mode` to optimize database performance.
- **Versioning and Schema Tracking**: Commands like `PRAGMA user_version` help track the version of the database schema.
- **Temporary Storage**: The `PRAGMA temp_store` allows control over where temporary data is stored.

PRAGMA statements are an essential tool for managing and tuning SQLite databases, giving you control over many aspects of the database’s configuration and performance.
