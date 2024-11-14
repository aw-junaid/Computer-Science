### SQLite - Transactions

In SQLite, **transactions** allow you to execute a series of SQL statements in a way that ensures they are processed reliably. A transaction groups multiple SQL statements into a single unit of work, making sure that either all changes are committed (saved) to the database or none of them are. This ensures data integrity, consistency, and isolation, even in the event of errors or system failures.

SQLite follows the **ACID properties** (Atomicity, Consistency, Isolation, Durability) for transactions, ensuring that:

- **Atomicity**: All operations in the transaction are completed successfully, or none are. If any part fails, the entire transaction is rolled back.
- **Consistency**: The database is always in a consistent state before and after a transaction.
- **Isolation**: Transactions are isolated from each other, meaning changes made in one transaction are not visible to others until the transaction is committed.
- **Durability**: Once a transaction is committed, its changes are permanent, even if there is a system crash.

---

### Transaction Syntax in SQLite

SQLite provides the following commands for managing transactions:

1. **BEGIN TRANSACTION**
2. **COMMIT**
3. **ROLLBACK**

---

### 1. **BEGIN TRANSACTION**

This command starts a new transaction. After `BEGIN`, any changes you make to the database (e.g., `INSERT`, `UPDATE`, `DELETE`) are part of the transaction. These changes will not be permanent until the transaction is committed.

**Syntax**:
```sql
BEGIN TRANSACTION;
```

Alternatively, you can use the shorthand `BEGIN` to start a transaction.

**Example**:
```sql
BEGIN TRANSACTION;
```

---

### 2. **COMMIT**

The `COMMIT` command is used to permanently apply all changes made during the current transaction. Once committed, all changes are saved to the database.

**Syntax**:
```sql
COMMIT;
```

**Example**:
```sql
COMMIT;
```

After `COMMIT`, all changes made within the transaction are finalized and made permanent in the database.

---

### 3. **ROLLBACK**

If an error occurs or you decide to cancel the transaction before committing it, you can use the `ROLLBACK` command. This undoes all changes made during the transaction, returning the database to its state before the `BEGIN TRANSACTION`.

**Syntax**:
```sql
ROLLBACK;
```

**Example**:
```sql
ROLLBACK;
```

After `ROLLBACK`, any changes made during the transaction are discarded, and the database remains unchanged.

---

### Example of Using Transactions

Let’s assume we have an `employees` table:

```sql
CREATE TABLE employees (
    id INTEGER PRIMARY KEY,
    name TEXT,
    department_id INTEGER
);
```

We will perform a transaction that inserts multiple records. If one of the insertions fails, the entire transaction will be rolled back to ensure data integrity.

```sql
BEGIN TRANSACTION;

-- First insertion
INSERT INTO employees (name, department_id) VALUES ('Alice', 1);

-- Second insertion
INSERT INTO employees (name, department_id) VALUES ('Bob', 2);

-- Third insertion
-- This is an intentional error (trying to insert a duplicate primary key)
INSERT INTO employees (id, name, department_id) VALUES (1, 'Charlie', 3);

-- Commit the transaction
COMMIT;
```

In the above example:
- The first two insertions will be committed to the database.
- The third insertion tries to insert a duplicate `id`, which will cause an error (because `id` is the primary key).
- Since the transaction has not been committed yet, SQLite will **ROLLBACK** all the changes, and no data will be inserted into the table.

To ensure atomicity, you can add error handling:

```sql
BEGIN TRANSACTION;

-- First insertion
INSERT INTO employees (name, department_id) VALUES ('Alice', 1);

-- Second insertion
INSERT INTO employees (name, department_id) VALUES ('Bob', 2);

-- Third insertion
-- This will cause an error, so we'll roll back
BEGIN TRY
    INSERT INTO employees (id, name, department_id) VALUES (1, 'Charlie', 3);
    COMMIT;
END TRY
BEGIN CATCH
    ROLLBACK;
END CATCH
```

This ensures that if an error occurs at any point in the transaction, all changes are rolled back, preserving the integrity of the data.

---

### Implicit Transactions in SQLite

SQLite also has **implicit transactions** that automatically wrap individual `INSERT`, `UPDATE`, or `DELETE` statements in a transaction. This means that even without explicitly using `BEGIN`, `COMMIT`, or `ROLLBACK`, SQLite ensures that each individual statement is executed as a transaction.

**Example of implicit transaction**:

```sql
INSERT INTO employees (name, department_id) VALUES ('Alice', 1);
```

This `INSERT` command is wrapped in an implicit transaction, so if it fails, no data is written to the database. However, implicit transactions are limited to individual statements. If you need to group multiple operations together, you must use explicit transactions.

---

### SAVEPOINTs

SQLite also supports **savepoints**, which allow you to set intermediate points within a transaction that you can roll back to, rather than rolling back the entire transaction.

#### Syntax:
- **SAVEPOINT**: Creates a savepoint.
- **ROLLBACK TO SAVEPOINT**: Rolls back to the specific savepoint without affecting the entire transaction.
- **RELEASE SAVEPOINT**: Releases a savepoint (if you no longer need to roll back to it).

#### Example with Savepoints:
```sql
BEGIN TRANSACTION;

SAVEPOINT sp1;

-- First insertion
INSERT INTO employees (name, department_id) VALUES ('Alice', 1);

SAVEPOINT sp2;

-- Second insertion
INSERT INTO employees (name, department_id) VALUES ('Bob', 2);

-- Something goes wrong, so roll back to savepoint sp1
ROLLBACK TO SAVEPOINT sp1;

-- The first insertion will be discarded, but the second one is still intact
COMMIT;
```

**Explanation**:
- `SAVEPOINT sp1` sets a savepoint after the first `INSERT`.
- `SAVEPOINT sp2` sets a savepoint after the second `INSERT`.
- If something goes wrong, you can roll back to `sp1`, which will discard only the first insertion while leaving the second one intact.

---

### Key Points about SQLite Transactions

- **ACID properties**: SQLite transactions ensure **Atomicity**, **Consistency**, **Isolation**, and **Durability**.
- **Explicit Transactions**: Use `BEGIN TRANSACTION`, `COMMIT`, and `ROLLBACK` to control transactions.
- **Implicit Transactions**: SQLite automatically wraps single `INSERT`, `UPDATE`, or `DELETE` commands in transactions.
- **Savepoints**: Allows partial rollback within a larger transaction.
- **Concurrency**: SQLite uses **database-level locking** for transactions. Only one transaction can modify the database at a time, but multiple transactions can read from it concurrently.

---

### Conclusion

SQLite transactions ensure the integrity and consistency of the database by grouping multiple operations into a single unit. Using transactions effectively prevents partial updates, maintains database consistency, and allows for safe error recovery. For simple operations, implicit transactions are sufficient, but for more complex workflows, explicit transactions with `BEGIN`, `COMMIT`, and `ROLLBACK` are preferred. Savepoints offer an additional level of control within a transaction.
