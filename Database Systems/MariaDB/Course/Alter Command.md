### MariaDB - ALTER Command

The `ALTER` command in MariaDB is used to modify the structure of an existing database object, such as a table, column, or index. This command allows you to add, modify, or delete columns, as well as rename tables or columns. It's a flexible tool for making changes to database structures without losing existing data.

---

### 1. **ALTER TABLE**

The `ALTER TABLE` command is the most common use of the `ALTER` command in MariaDB. It allows you to modify the structure of a table by adding, modifying, or removing columns, as well as renaming the table or columns.

#### Syntax:

```sql
ALTER TABLE table_name [alteration];
```

Where `[alteration]` is the operation you wish to perform on the table (e.g., add, modify, drop, rename).

---

### 2. **Add Columns**

You can add new columns to an existing table using the `ADD` keyword.

#### Syntax:

```sql
ALTER TABLE table_name ADD column_name data_type [constraints];
```

#### Example:

```sql
ALTER TABLE employees ADD date_of_birth DATE;
```

This will add a new column `date_of_birth` with the data type `DATE` to the `employees` table.

You can add multiple columns at once:

```sql
ALTER TABLE employees
ADD phone_number VARCHAR(15),
    hire_date DATE;
```

This adds two new columns: `phone_number` and `hire_date`.

---

### 3. **Modify Columns**

You can change the definition of an existing column (e.g., change the data type or size).

#### Syntax:

```sql
ALTER TABLE table_name MODIFY column_name new_data_type [constraints];
```

#### Example:

```sql
ALTER TABLE employees MODIFY name VARCHAR(100);
```

This changes the `name` column's data type to `VARCHAR(100)`, increasing its length.

You can also modify other column properties, like making a column `NOT NULL` or `UNIQUE`:

```sql
ALTER TABLE employees MODIFY email VARCHAR(255) NOT NULL;
```

This changes the `email` column to have a `NOT NULL` constraint.

---

### 4. **Rename Columns**

MariaDB allows you to rename columns in a table.

#### Syntax:

```sql
ALTER TABLE table_name CHANGE old_column_name new_column_name data_type [constraints];
```

#### Example:

```sql
ALTER TABLE employees CHANGE date_of_birth birth_date DATE;
```

This renames the `date_of_birth` column to `birth_date` and retains the `DATE` data type.

Note that when renaming a column, you need to specify the column’s data type as well, even if you're only changing the column name.

---

### 5. **Drop Columns**

You can remove a column from a table using the `DROP` keyword.

#### Syntax:

```sql
ALTER TABLE table_name DROP COLUMN column_name;
```

#### Example:

```sql
ALTER TABLE employees DROP COLUMN phone_number;
```

This deletes the `phone_number` column from the `employees` table.

You can also drop multiple columns at once:

```sql
ALTER TABLE employees DROP COLUMN phone_number, DROP COLUMN hire_date;
```

This will drop both `phone_number` and `hire_date` columns from the `employees` table.

---

### 6. **Rename a Table**

You can rename a table using the `RENAME` keyword in `ALTER TABLE`.

#### Syntax:

```sql
ALTER TABLE old_table_name RENAME TO new_table_name;
```

#### Example:

```sql
ALTER TABLE employees RENAME TO staff;
```

This renames the `employees` table to `staff`.

---

### 7. **Change Table's Storage Engine**

In MariaDB, you can change the storage engine of a table (e.g., from `InnoDB` to `MyISAM`).

#### Syntax:

```sql
ALTER TABLE table_name ENGINE = new_engine;
```

#### Example:

```sql
ALTER TABLE employees ENGINE = InnoDB;
```

This changes the storage engine of the `employees` table to `InnoDB`.

---

### 8. **Add/Drop Indexes**

You can add or remove indexes from a table using `ALTER TABLE`. 

#### Add Index:

To add an index, use the `ADD INDEX` clause.

```sql
ALTER TABLE table_name ADD INDEX index_name (column_name);
```

#### Example:

```sql
ALTER TABLE employees ADD INDEX idx_email (email);
```

This adds an index on the `email` column of the `employees` table.

#### Drop Index:

To drop an index, use the `DROP INDEX` clause.

```sql
ALTER TABLE table_name DROP INDEX index_name;
```

#### Example:

```sql
ALTER TABLE employees DROP INDEX idx_email;
```

This removes the index `idx_email` from the `employees` table.

---

### 9. **Modify Table Properties**

You can modify some table properties, like its character set or collation.

#### Syntax:

```sql
ALTER TABLE table_name [MODIFY TABLE PROPERTY];
```

#### Example (Change Character Set):

```sql
ALTER TABLE employees CONVERT TO CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
```

This converts the `employees` table to use the `utf8mb4` character set and `utf8mb4_unicode_ci` collation.

---

### 10. **Add/Drop Foreign Key Constraints**

You can add or remove foreign key constraints on a table using the `ALTER TABLE` command.

#### Add Foreign Key:

```sql
ALTER TABLE table_name ADD CONSTRAINT constraint_name FOREIGN KEY (column_name) REFERENCES referenced_table (referenced_column);
```

#### Example:

```sql
ALTER TABLE orders ADD CONSTRAINT fk_customer FOREIGN KEY (customer_id) REFERENCES customers (id);
```

This adds a foreign key constraint to the `orders` table, linking the `customer_id` column to the `id` column in the `customers` table.

#### Drop Foreign Key:

To drop a foreign key constraint, use the `DROP FOREIGN KEY` clause.

```sql
ALTER TABLE table_name DROP FOREIGN KEY constraint_name;
```

#### Example:

```sql
ALTER TABLE orders DROP FOREIGN KEY fk_customer;
```

This drops the `fk_customer` foreign key constraint from the `orders` table.

---

### 11. **Change the Auto Increment Value**

You can set the next auto-increment value for a column using `ALTER TABLE`.

#### Syntax:

```sql
ALTER TABLE table_name AUTO_INCREMENT = value;
```

#### Example:

```sql
ALTER TABLE employees AUTO_INCREMENT = 1001;
```

This sets the next auto-increment value for the `employees` table to `1001`.

---

### 12. **Examples of ALTER Command**

- **Add a column**:

```sql
ALTER TABLE employees ADD department VARCHAR(50);
```

- **Modify a column**:

```sql
ALTER TABLE employees MODIFY department VARCHAR(100);
```

- **Rename a column**:

```sql
ALTER TABLE employees CHANGE department department_name VARCHAR(100);
```

- **Drop a column**:

```sql
ALTER TABLE employees DROP COLUMN department_name;
```

- **Rename a table**:

```sql
ALTER TABLE employees RENAME TO staff;
```

- **Change the engine**:

```sql
ALTER TABLE employees ENGINE = MyISAM;
```

- **Add a foreign key**:

```sql
ALTER TABLE orders ADD CONSTRAINT fk_customer FOREIGN KEY (customer_id) REFERENCES customers (id);
```

---

### Conclusion

The `ALTER` command in MariaDB is an essential tool for modifying the structure of your database objects, such as tables, columns, and indexes, without losing data. Whether you need to add, modify, or remove columns, rename tables, or change indexes and constraints, the `ALTER TABLE` command provides flexibility to manage your database schema efficiently. Always use this command with caution, especially in production environments, and ensure proper backups are in place before making structural changes.
