### MariaDB - Sequences

In MariaDB, **sequences** are objects that generate a series of unique numbers, typically used for auto-incrementing fields like primary keys. Unlike traditional auto-increment columns, which automatically generate unique values for a specific column in a table, sequences are standalone objects that can be used across multiple tables and can be controlled explicitly.

As of MariaDB 10.3, **sequence support** is available as a feature, which allows you to create and manage sequences independently from the tables, offering more flexibility in generating unique numbers for various purposes.

---

### 1. **Creating a Sequence**

A sequence is created using the `CREATE SEQUENCE` statement. When you create a sequence, you can specify various parameters such as the starting value, increment value, and minimum and maximum values for the sequence.

#### Syntax:

```sql
CREATE SEQUENCE sequence_name
  START WITH start_value
  INCREMENT BY increment_value
  MINVALUE minimum_value
  MAXVALUE maximum_value
  CYCLE | NO CYCLE;
```

- **`sequence_name`**: The name of the sequence.
- **`START WITH start_value`**: The value at which the sequence will begin.
- **`INCREMENT BY increment_value`**: The value by which the sequence will increase after each use (default is 1).
- **`MINVALUE minimum_value`**: The minimum value for the sequence.
- **`MAXVALUE maximum_value`**: The maximum value for the sequence.
- **`CYCLE`**: Allows the sequence to restart once it reaches the maximum value.
- **`NO CYCLE`**: Prevents the sequence from restarting after reaching the maximum value (default).

#### Example:

```sql
CREATE SEQUENCE order_id_seq
  START WITH 1
  INCREMENT BY 1
  MINVALUE 1
  MAXVALUE 10000
  NO CYCLE;
```

This creates a sequence named `order_id_seq`, starting at 1 and incrementing by 1, with a maximum value of 10,000. It will not cycle (i.e., it won’t restart after reaching the maximum value).

---

### 2. **Using a Sequence**

Once a sequence is created, you can use it to generate values by using the `NEXTVAL` and `CURRVAL` functions.

#### `NEXTVAL`

- **`NEXTVAL`** retrieves the next value from the sequence and increments the sequence by the specified increment value.

#### Syntax:

```sql
SELECT NEXTVAL(sequence_name);
```

#### Example:

```sql
SELECT NEXTVAL(order_id_seq);
```

This retrieves the next value from the `order_id_seq` sequence. If the sequence was created with an increment of 1, the first value returned would be 1, the next would be 2, and so on.

#### `CURRVAL`

- **`CURRVAL`** retrieves the current value of the sequence after `NEXTVAL` has been called.

#### Syntax:

```sql
SELECT CURRVAL(sequence_name);
```

#### Example:

```sql
SELECT CURRVAL(order_id_seq);
```

This retrieves the most recently used value from the `order_id_seq` sequence.

---

### 3. **Using Sequences in Tables**

You can use sequences to populate columns in a table, especially in cases where you need unique values for primary keys or other fields.

#### Example:

```sql
CREATE TABLE orders (
    order_id INT DEFAULT NEXTVAL(order_id_seq),
    customer_id INT,
    order_date DATE
);
```

In this example, the `order_id` field will automatically get its value from the `order_id_seq` sequence whenever a new row is inserted.

You can insert data into the table without specifying the `order_id`, as it will be automatically assigned by the sequence.

```sql
INSERT INTO orders (customer_id, order_date)
VALUES (1, '2024-12-16');
```

This will insert a new row with the next available value from `order_id_seq` as the `order_id`.

---

### 4. **Modifying a Sequence**

You can modify an existing sequence using the `ALTER SEQUENCE` statement. This allows you to change properties like the increment value, start value, and others.

#### Syntax:

```sql
ALTER SEQUENCE sequence_name
  RESTART WITH new_value;
```

This will restart the sequence with a new value.

#### Example:

```sql
ALTER SEQUENCE order_id_seq
  RESTART WITH 1000;
```

This restarts the `order_id_seq` sequence at 1000, meaning the next value generated by `NEXTVAL` will be 1000.

---

### 5. **Dropping a Sequence**

To remove a sequence, you use the `DROP SEQUENCE` statement.

#### Syntax:

```sql
DROP SEQUENCE sequence_name;
```

#### Example:

```sql
DROP SEQUENCE order_id_seq;
```

This will delete the `order_id_seq` sequence from the database.

---

### 6. **Sequence with CYCLE**

When you use the `CYCLE` option, the sequence will automatically restart once it reaches the maximum value.

#### Example:

```sql
CREATE SEQUENCE order_id_seq_cycle
  START WITH 1
  INCREMENT BY 1
  MINVALUE 1
  MAXVALUE 5
  CYCLE;
```

In this case, once the sequence reaches 5, it will restart at 1, effectively cycling through values 1 to 5.

---

### 7. **Limitations of Sequences**

- **No auto-rollback**: Sequences do not support automatic rollback for values that have been used. If you generate a value using `NEXTVAL`, that value is consumed and cannot be "rolled back" like an auto-increment field in a table.
  
- **Limited to MariaDB 10.3 and above**: Sequences are available in MariaDB starting from version 10.3, so they are not available in earlier versions.

---

### 8. **Practical Use Case: Sequence for Inserting Data**

Let’s take an example where you want to use a sequence for generating unique invoice numbers in a table.

#### Example:

1. **Create a sequence for invoice numbers**:

```sql
CREATE SEQUENCE invoice_number_seq
  START WITH 1000
  INCREMENT BY 1
  MINVALUE 1000
  MAXVALUE 9999
  NO CYCLE;
```

2. **Create a table to store invoices**:

```sql
CREATE TABLE invoices (
    invoice_id INT DEFAULT NEXTVAL(invoice_number_seq),
    customer_id INT,
    amount DECIMAL(10, 2),
    issue_date DATE
);
```

3. **Insert an invoice**:

```sql
INSERT INTO invoices (customer_id, amount, issue_date)
VALUES (1, 250.75, '2024-12-16');
```

This automatically generates a new invoice ID from the `invoice_number_seq` sequence, starting at 1000.

---

### Conclusion

Sequences in MariaDB provide a flexible and powerful mechanism for generating unique values in your database, especially for cases that require non-auto-incremental primary key values, or when you need a sequence of numbers to be shared across multiple tables or operations. With the ability to customize starting points, increments, and limits, sequences are highly useful for advanced scenarios like invoice numbers, transaction IDs, or other use cases requiring sequential values.
