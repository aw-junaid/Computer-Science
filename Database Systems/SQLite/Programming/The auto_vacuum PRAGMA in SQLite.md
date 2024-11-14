The **`auto_vacuum`** PRAGMA in SQLite is used to control whether or not the database should automatically reclaim unused space when rows are deleted. 

In SQLite, when you delete data from a table, the space previously occupied by those rows is not immediately released to the file system. Instead, SQLite marks the space as free for reuse within the database. The **`auto_vacuum`** PRAGMA controls whether this unused space is reclaimed automatically, making the database file smaller.

### Syntax of `auto_vacuum` PRAGMA

```sql
PRAGMA auto_vacuum = {NONE | FULL | INCREMENTAL};
```

- **`NONE`**: (default setting) Auto-vacuum is off. When rows are deleted, SQLite does not attempt to reclaim space, and the database file size remains unchanged. Deleted space is reused for future inserts but is not returned to the file system.
- **`FULL`**: Enables full auto-vacuum. When rows are deleted, SQLite attempts to shrink the database file by actually reclaiming unused space and reducing the size of the database file. This may lead to performance overhead during deletion operations.
- **`INCREMENTAL`**: Enables incremental auto-vacuum. Similar to `FULL`, but it reclaims space incrementally during database writes rather than during every delete operation. This is typically used to reduce the performance impact of **`FULL`** auto-vacuum.

### Changing the `auto_vacuum` Mode

You can change the **`auto_vacuum`** mode of a database by using the following PRAGMA statement:

```sql
PRAGMA auto_vacuum = FULL;
```

To disable auto-vacuum:

```sql
PRAGMA auto_vacuum = NONE;
```

To use incremental auto-vacuum:

```sql
PRAGMA auto_vacuum = INCREMENTAL;
```

### Example

To enable auto-vacuum on an SQLite database:

```sql
PRAGMA auto_vacuum = FULL;
```

This will instruct SQLite to automatically reclaim unused space and reduce the file size whenever rows are deleted.

### Important Notes

1. **Changing `auto_vacuum`**: You can only change the `auto_vacuum` setting on an **empty** database or after performing a **`VACUUM`** operation. Once you change the `auto_vacuum` mode, SQLite will begin reclaiming space during subsequent deletes or inserts, depending on the mode selected.
   
2. **Performance Impact**: 
   - **`NONE`** (the default) has the least overhead because no additional work is done to shrink the database file.
   - **`FULL`** auto-vacuum introduces overhead whenever data is deleted, as SQLite must compact the database file.
   - **`INCREMENTAL`** auto-vacuum is a compromise between performance and file size, as it reclaims space gradually.

3. **Reclaiming Space with `VACUUM`**: Even if you disable auto-vacuum, you can manually reclaim unused space by running the **`VACUUM`** command, which rebuilds the database file, compacting it and removing any unused space.

### Example of `VACUUM`:

```sql
VACUUM;
```

This command will rebuild the entire database and reclaim any unused space.

---

### Summary of `auto_vacuum` PRAGMA

- **`auto_vacuum = NONE`**: No automatic space reclamation. Default setting.
- **`auto_vacuum = FULL`**: Automatically reclaims space when rows are deleted and reduces the database file size.
- **`auto_vacuum = INCREMENTAL`**: Reclaims space gradually during operations, reducing performance overhead compared to `FULL`.
- **Effect on performance**: Enabling auto-vacuum, especially in `FULL` mode, can introduce performance overhead during delete operations.
- **Database file size**: `FULL` and `INCREMENTAL` auto-vacuum can help reduce the database file size by reclaiming space, while `NONE` leaves unused space in the file.

The **`auto_vacuum`** feature is useful for managing database file size, especially in scenarios where large amounts of data are frequently deleted. However, you should be mindful of the performance impact when choosing the appropriate mode.
