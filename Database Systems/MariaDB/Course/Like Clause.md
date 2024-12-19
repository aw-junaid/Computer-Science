### MariaDB - LIKE Clause

The `LIKE` clause in MariaDB is used in a `WHERE` statement to search for a specified pattern in a column. It is typically used with string values and supports two wildcards:
- **`%`**: Represents zero, one, or multiple characters.
- **`_`**: Represents a single character.

The `LIKE` clause is case-insensitive in MariaDB by default, but this behavior can vary based on the collation used in the table or column.

---

### Basic Syntax

```sql
SELECT column1, column2, ...
FROM table_name
WHERE column_name LIKE pattern;
```

- **`column1, column2, ...`**: The columns to retrieve.
- **`table_name`**: The table from which to retrieve the data.
- **`column_name`**: The column to search in.
- **`pattern`**: The pattern to search for in the column.

---

### 1. **Using `%` Wildcard**

The **`%`** wildcard matches zero, one, or multiple characters.

#### Example:

```sql
SELECT * FROM users
WHERE first_name LIKE 'Jo%';
```

This will return all users whose `first_name` starts with "Jo", such as "John", "Joanna", "Joseph", etc.

#### Example (any position):

```sql
SELECT * FROM users
WHERE email LIKE '%gmail.com';
```

This will return all users whose `email` ends with "gmail.com", such as "john.doe@gmail.com", "jane.smith@gmail.com", etc.

---

### 2. **Using `_` Wildcard**

The **`_`** wildcard matches exactly one character.

#### Example:

```sql
SELECT * FROM users
WHERE first_name LIKE 'J_n';
```

This will return all users whose `first_name` has "J" at the beginning and "n" at the end, with exactly one character in between, such as "Jon", "Jan", etc.

---

### 3. **Combining `%` and `_` Wildcards**

You can combine both wildcards to match more specific patterns.

#### Example:

```sql
SELECT * FROM users
WHERE first_name LIKE 'J_o_n';
```

This will return all users whose `first_name` starts with "J", has "o" in the second position, and "n" in the fourth position, such as "John" or "Joan".

#### Example (with both wildcards):

```sql
SELECT * FROM users
WHERE first_name LIKE 'J_o%';
```

This will return all users whose `first_name` starts with "J", has "o" in the second position, and any characters afterward, such as "John", "Joanna", etc.

---

### 4. **Using `NOT LIKE`**

The `NOT LIKE` clause is used to find records that do not match a specified pattern.

#### Example:

```sql
SELECT * FROM users
WHERE first_name NOT LIKE 'Jo%';
```

This will return all users whose `first_name` does not start with "Jo".

---

### 5. **Case Sensitivity in LIKE**

By default, MariaDB uses a case-insensitive collation for string comparisons, which means `LIKE` will not distinguish between uppercase and lowercase letters. However, this behavior can be altered depending on the collation used in the table or column.

#### Example (case-insensitive):

```sql
SELECT * FROM users
WHERE first_name LIKE 'john';
```

This will match "John", "JOHN", "john", etc.

#### Example (case-sensitive):

If you want to make the `LIKE` query case-sensitive, you can change the collation or use the `BINARY` keyword:

```sql
SELECT * FROM users
WHERE BINARY first_name LIKE 'john';
```

This will only match "john" and not "John" or "JOHN".

---

### 6. **Using `LIKE` with `OR`**

You can combine the `LIKE` clause with the `OR` operator to search for multiple patterns.

#### Example:

```sql
SELECT * FROM users
WHERE first_name LIKE 'J%' OR first_name LIKE 'M%';
```

This will return all users whose `first_name` starts with "J" or "M".

---

### 7. **Using `LIKE` with Multiple Columns**

You can also use `LIKE` on multiple columns, either by combining them in the `WHERE` clause or using a `CONCAT` function.

#### Example:

```sql
SELECT * FROM users
WHERE first_name LIKE 'J%' AND last_name LIKE 'D%';
```

This will return all users whose `first_name` starts with "J" and `last_name` starts with "D".

#### Example (using `CONCAT`):

```sql
SELECT * FROM users
WHERE CONCAT(first_name, ' ', last_name) LIKE 'J% D%';
```

This will return users whose combined `first_name` and `last_name` start with "J" and "D" respectively.

---

### 8. **Performance Considerations**

- **Indexes**: The `LIKE` clause, particularly with the `%` wildcard at the beginning of the pattern (e.g., `LIKE '%pattern'`), can be slow because it prevents the database from using indexes efficiently.
- **Full-text Indexes**: For better performance in searching large text fields, consider using **full-text search** if appropriate for your use case.

---

### Conclusion

The `LIKE` clause in MariaDB is a flexible and powerful way to search for patterns in string columns. It supports the use of wildcards (`%` and `_`) to match different parts of a string, and can be used for complex search patterns in data.

**Key Points to Remember:**
- **`%`** matches zero or more characters.
- **`_`** matches exactly one character.
- **`NOT LIKE`** excludes a pattern.
- **Case sensitivity** can be managed by collation or the `BINARY` keyword.
- You can combine multiple patterns using `OR` or apply `LIKE` to multiple columns.

By understanding how to use `LIKE` effectively, you can perform more flexible and sophisticated searches in your MariaDB database.
