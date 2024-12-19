### MariaDB - Transactions

In MariaDB, a **transaction** is a sequence of one or more SQL operations executed as a single unit. Transactions ensure data integrity by following the **ACID properties**: **Atomicity**, **Consistency**, **Isolation**, and **Durability**. Transactions allow you to execute multiple queries as a single unit of work, ensuring that either all operations are successfully completed or none are.

---

### 1. **ACID Properties**

Transactions in MariaDB follow these four key properties:

1. **Atomicity**: This means that a transaction is all or nothing. Either all changes are committed, or none are if there is a failure.
2. **Consistency**: A transaction will bring the database from one consistent state to another, ensuring data integrity.
3. **Isolation**: Each transaction operates independently of other transactions. The intermediate states of a transaction are not visible to other transactions.
4. **Durability**: Once a transaction is committed, its changes are permanent, even in the event of a system crash.

---

### 2. **Transaction Lifecycle**

A typical transaction follows these steps:

1. **Start the transaction**: This is done with the `START TRANSACTION` command.
2. **Execute queries**: You can execute any number of SQL queries within the transaction.
3. **Commit the transaction**: If all queries are successful and you want to save changes, use the `COMMIT` command.
4. **Rollback the transaction**: If something goes wrong and you want to revert all changes made in the transaction, use the `ROLLBACK` command.

---

### 3. **Basic Transaction Commands**

#### **START TRANSACTION**
Begins a new transaction. You can explicitly start a transaction before executing your queries.

```sql
START TRANSACTION;
```

Alternatively, you can use the `BEGIN` statement, which is equivalent to `START TRANSACTION`.

```sql
BEGIN;
```

#### **COMMIT**
Commits a transaction, making all changes permanent. If all operations within the transaction are successful, you commit the transaction.

```sql
COMMIT;
```

#### **ROLLBACK**
Rolls back a transaction, undoing any changes made during the transaction. This is useful if an error occurs or if you decide not to proceed with the transaction.

```sql
ROLLBACK;
```

---

### 4. **Using Transactions in MariaDB**

Here’s an example of how you would use a transaction to ensure data integrity:

```sql
START TRANSACTION;

-- Example: Transfer money between two accounts
UPDATE accounts SET balance = balance - 100 WHERE account_id = 1;
UPDATE accounts SET balance = balance + 100 WHERE account_id = 2;

-- If both updates are successful, commit the transaction
COMMIT;
```

In this example, we are transferring money from `account_id = 1` to `account_id = 2`. If both `UPDATE` queries are successful, we commit the transaction. If any error occurs, the changes are rolled back, and no money is transferred.

---

### 5. **Autocommit Mode**

By default, MariaDB operates in **autocommit mode**, which means every statement is treated as a separate transaction. Once a statement is executed, it is automatically committed.

- **Autocommit mode** can be turned off manually using `SET autocommit = 0;` and re-enabled with `SET autocommit = 1;`.
- When autocommit is off, you need to explicitly commit the transaction after the queries are executed.

#### Example: Disabling autocommit

```sql
SET autocommit = 0;

-- Execute multiple queries
UPDATE accounts SET balance = balance - 100 WHERE account_id = 1;
UPDATE accounts SET balance = balance + 100 WHERE account_id = 2;

-- Commit the transaction
COMMIT;
```

If autocommit is off, the `UPDATE` queries are not committed until `COMMIT` is called.

---

### 6. **Transaction Isolation Levels**

MariaDB supports different **transaction isolation levels**, which define how transactions interact with each other. The isolation level determines how visible a transaction's changes are to other transactions before it is committed. MariaDB supports the following isolation levels:

1. **READ UNCOMMITTED**: Transactions can read data that is not yet committed by other transactions (dirty reads).
2. **READ COMMITTED**: Transactions can only read committed data, but may still experience non-repeatable reads (data may change between reads within the same transaction).
3. **REPEATABLE READ**: Transactions can only read committed data, and the data read during a transaction is guaranteed to remain the same for the duration of the transaction (no non-repeatable reads).
4. **SERIALIZABLE**: The strictest isolation level. Transactions are executed in a way that ensures no other transaction can access the same data at the same time (no dirty reads, no non-repeatable reads, and no phantom reads).

#### Set Isolation Level:

```sql
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
```

For example, if you want to ensure that no other transaction modifies data during your transaction, you could use the `SERIALIZABLE` isolation level.

---

### 7. **Saving and Rolling Back Partial Changes (SAVEPOINT)**

MariaDB also allows you to set **savepoints** within a transaction. A savepoint is a point within a transaction to which you can roll back without affecting the entire transaction.

#### Example: Using Savepoints

```sql
START TRANSACTION;

-- First part of the transaction
UPDATE accounts SET balance = balance - 100 WHERE account_id = 1;

-- Savepoint
SAVEPOINT transfer_savepoint;

-- Second part of the transaction
UPDATE accounts SET balance = balance + 100 WHERE account_id = 2;

-- If second update fails, rollback to savepoint
ROLLBACK TO transfer_savepoint;

-- Commit the rest of the transaction
COMMIT;
```

In this example, the transaction is rolled back to the `SAVEPOINT` if there is a problem with the second `UPDATE`, but the first `UPDATE` is retained.

---

### 8. **Transaction Example with Error Handling**

You can also use transactions in combination with error handling to manage complex scenarios.

```sql
START TRANSACTION;

-- Query 1
UPDATE accounts SET balance = balance - 100 WHERE account_id = 1;

-- Query 2
UPDATE accounts SET balance = balance + 100 WHERE account_id = 2;

-- If both queries are successful, commit
COMMIT;

-- If an error occurs, rollback the entire transaction
ROLLBACK;
```

You can implement error-handling logic in your application code (e.g., in PHP, Python, etc.) that checks the success or failure of each query and decides whether to commit or roll back the transaction.

---

### 9. **Transaction in Stored Procedures**

Transactions can also be used inside stored procedures, allowing complex business logic to be executed in a transactional context.

```sql
DELIMITER //

CREATE PROCEDURE transfer_money(from_account INT, to_account INT, amount DECIMAL)
BEGIN
    DECLARE EXIT HANDLER FOR SQLEXCEPTION
    BEGIN
        -- Rollback if an error occurs
        ROLLBACK;
    END;

    START TRANSACTION;
    
    -- Perform the transfer
    UPDATE accounts SET balance = balance - amount WHERE account_id = from_account;
    UPDATE accounts SET balance = balance + amount WHERE account_id = to_account;
    
    COMMIT;
END //

DELIMITER ;
```

This procedure ensures that the money transfer is atomic: either both updates are successful, or none are.

---

### 10. **Transaction Rollbacks in Case of Error**

MariaDB also supports handling errors during transactions using the `DECLARE` and `HANDLER` syntax to automatically roll back a transaction if an error occurs.

```sql
DECLARE CONTINUE HANDLER FOR SQLEXCEPTION
ROLLBACK;
```

This ensures that if an exception occurs in the middle of a transaction, the entire transaction is rolled back automatically.

---

### Conclusion

Transactions are a crucial part of ensuring data integrity in MariaDB. By using **`START TRANSACTION`**, **`COMMIT`**, and **`ROLLBACK`**, along with options like **SAVEPOINT** and different **isolation levels**, you can manage complex multi-step operations while ensuring that your data remains consistent. By using these tools correctly, you can handle errors gracefully and ensure that all your database operations are atomic and reliable.
