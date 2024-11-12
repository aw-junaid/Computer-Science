In SQLite, the `ATTACH DATABASE` command is used to attach an additional database to an existing database connection. This allows you to work with multiple databases in a single SQL session. Once attached, you can access tables, views, and other objects from the attached database alongside those of the main database.

The `ATTACH DATABASE` command is particularly useful when you need to combine data from different databases or move data between them without the need to merge the databases physically into a single file.

### Syntax of `ATTACH DATABASE`

```sql
ATTACH DATABASE 'file_path' AS alias;
```

- **`file_path`**: The file path of the database to attach. This can be a relative or absolute path to the SQLite database file.
- **`alias`**: A user-defined name (alias) that will be used to reference the attached database in SQL queries.

### Example of Using `ATTACH DATABASE`

Let’s assume you have two SQLite database files: `main.db` (your primary database) and `secondary.db` (an additional database you want to attach).

1. **Attaching the Database**:
   Open `main.db` and attach `secondary.db`:

   ```sql
   ATTACH DATABASE 'secondary.db' AS secondary;
   ```

2. **Querying Data from Both Databases**:
   After attaching `secondary.db`, you can access its tables and data by prefixing table names with the alias (`secondary` in this case):

   ```sql
   -- Query from the main database
   SELECT * FROM users;

   -- Query from the attached database
   SELECT * FROM secondary.orders;
   ```

In this example:
- You are querying the `users` table from the main database (`main.db`).
- You are querying the `orders` table from the attached database (`secondary.db`) by using the alias `secondary`.

3. **Combining Data from Both Databases**:
   You can perform queries that join tables from both databases. For example:

   ```sql
   SELECT u.name, o.order_id
   FROM users u
   JOIN secondary.orders o ON u.id = o.user_id;
   ```

This query joins the `users` table from `main.db` with the `orders` table from `secondary.db` on the `user_id` field.

---

### Detaching a Database

Once you're done working with the attached database, you can detach it using the `DETACH` command:

```sql
DETACH DATABASE secondary;
```

After detaching, you can no longer reference tables or other objects in `secondary.db` during the current session.

---

### Important Points About `ATTACH DATABASE`

- **Multiple Attachments**: You can attach more than one database to the same session. Each attached database must have a unique alias.
  
  ```sql
  ATTACH DATABASE 'database1.db' AS db1;
  ATTACH DATABASE 'database2.db' AS db2;
  ```

- **File Paths**: The path to the database file can be relative or absolute. However, the database files must be accessible from the current working directory of the SQLite session or application.

- **Read-Only Attachments**: If you want to attach a database in read-only mode, you can use the `READONLY` keyword:

  ```sql
  ATTACH DATABASE 'readonly.db' AS readonly_db READONLY;
  ```

  This ensures that you can query the database but cannot modify it.

- **Shared Cache Mode**: If you are using SQLite in **shared cache mode** (using `sqlite3_enable_shared_cache`), you can attach databases to that shared cache.

---

### Example: Combining Data from Two Databases

Let’s say you have a `main.db` database with a `users` table, and a `secondary.db` database with an `orders` table. You can attach `secondary.db` and join the data like so:

```sql
ATTACH DATABASE 'secondary.db' AS secondary;

SELECT u.name, o.order_id, o.amount
FROM users u
JOIN secondary.orders o ON u.id = o.user_id;
```

This will return a list of users along with their corresponding orders from the `orders` table in the attached `secondary.db`.

---

### Summary

The `ATTACH DATABASE` command in SQLite is a powerful feature that allows you to work with multiple databases in a single session. It enables querying and combining data from different SQLite database files without physically merging them. This makes it easy to manage and manipulate data from different sources in a seamless way.
