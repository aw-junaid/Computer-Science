### MariaDB - WHERE Clause

The `WHERE` clause in MariaDB is used to filter records that meet a specific condition. It is often used with `SELECT`, `UPDATE`, `DELETE`, and other SQL statements to specify which rows should be affected by the query. The `WHERE` clause helps to narrow down the results by applying filters to the data.

### Basic Syntax

```sql
SELECT column1, column2, ...
FROM table_name
WHERE condition;
```

- **`column1, column2, ...`**: The columns you want to retrieve.
- **`table_name`**: The name of the table.
- **`condition`**: The condition that must be met for the rows to be included in the result.

---

### 1. **Basic WHERE Clause**

The simplest use of the `WHERE` clause is to filter data based on a condition that must be met.

Example:

```sql
SELECT * FROM users WHERE last_name = 'Doe';
```

This query will retrieve all columns (`*`) from the `users` table where the `last_name` is exactly "Doe".

---

### 2. **Comparison Operators**

The `WHERE` clause often uses comparison operators to filter data. Some of the most common comparison operators are:

- **`=`**: Equal to
- **`!=` or `<>`**: Not equal to
- **`>`**: Greater than
- **`<`**: Less than
- **`>=`**: Greater than or equal to
- **`<=`**: Less than or equal to
- **`BETWEEN`**: Range of values
- **`LIKE`**: Pattern matching
- **`IS NULL`**: Null value check
- **`IN`**: Matching multiple values

#### Example using `=`:
```sql
SELECT * FROM users WHERE age = 30;
```

This will return all users whose age is exactly 30.

#### Example using `!=`:
```sql
SELECT * FROM users WHERE age != 30;
```

This will return all users whose age is not 30.

#### Example using `>`:
```sql
SELECT * FROM users WHERE age > 30;
```

This will return all users whose age is greater than 30.

---

### 3. **Using `AND`, `OR`, and `NOT`**

The `WHERE` clause can combine multiple conditions using logical operators like `AND`, `OR`, and `NOT`:

- **`AND`**: Requires both conditions to be true.
- **`OR`**: Requires at least one condition to be true.
- **`NOT`**: Reverses the condition (used to negate the condition).

#### Example using `AND`:

```sql
SELECT * FROM users WHERE first_name = 'John' AND last_name = 'Doe';
```

This will return all rows where the `first_name` is "John" and the `last_name` is "Doe".

#### Example using `OR`:

```sql
SELECT * FROM users WHERE first_name = 'John' OR last_name = 'Doe';
```

This will return all rows where either the `first_name` is "John" or the `last_name` is "Doe".

#### Example using `NOT`:

```sql
SELECT * FROM users WHERE NOT age = 30;
```

This will return all users whose age is not 30.

---

### 4. **Using `BETWEEN`**

The `BETWEEN` operator is used to filter values within a specified range (inclusive).

#### Example:

```sql
SELECT * FROM users WHERE age BETWEEN 20 AND 30;
```

This will return all users whose `age` is between 20 and 30, including 20 and 30.

---

### 5. **Using `LIKE` for Pattern Matching**

The `LIKE` operator is used for pattern matching in string columns. It supports two wildcards:
- **`%`**: Represents any number of characters (including zero).
- **`_`**: Represents exactly one character.

#### Example using `%`:

```sql
SELECT * FROM users WHERE first_name LIKE 'J%';
```

This will return all users whose `first_name` starts with "J" (e.g., "John", "Jack", "Jane").

#### Example using `_`:

```sql
SELECT * FROM users WHERE first_name LIKE '_ohn';
```

This will return all users whose `first_name` has "ohn" as the last three characters (e.g., "John", "Mohammad").

---

### 6. **Using `IS NULL` and `IS NOT NULL`**

You can use `IS NULL` to check if a column contains `NULL` values, and `IS NOT NULL` to check if a column does not contain `NULL` values.

#### Example using `IS NULL`:

```sql
SELECT * FROM users WHERE email IS NULL;
```

This will return all users who do not have an email address (i.e., their `email` is `NULL`).

#### Example using `IS NOT NULL`:

```sql
SELECT * FROM users WHERE email IS NOT NULL;
```

This will return all users who have an email address.

---

### 7. **Using `IN`**

The `IN` operator allows you to match a column against a list of values.

#### Example:

```sql
SELECT * FROM users WHERE last_name IN ('Doe', 'Smith', 'Johnson');
```

This will return all users whose `last_name` is either "Doe", "Smith", or "Johnson".

---

### 8. **Using `EXISTS`**

The `EXISTS` operator is used to check whether a subquery returns any results. It is often used in correlated subqueries.

#### Example:

```sql
SELECT * FROM users WHERE EXISTS (SELECT 1 FROM orders WHERE users.id = orders.user_id);
```

This will return all users who have at least one order in the `orders` table.

---

### 9. **Using `AND` with `OR`**

You can combine `AND` and `OR` within the `WHERE` clause, but use parentheses to clarify the precedence.

#### Example:

```sql
SELECT * FROM users WHERE (age > 30 OR age < 20) AND last_name = 'Doe';
```

This will return all users whose `last_name` is "Doe" and whose `age` is either greater than 30 or less than 20.

---

### 10. **Case Sensitivity in `WHERE` Clause**

By default, MariaDB is case-insensitive for string comparison in the `WHERE` clause (for `CHAR`, `VARCHAR`, and `TEXT` columns). However, you can use the `BINARY` keyword to make comparisons case-sensitive.

#### Example:

```sql
SELECT * FROM users WHERE BINARY first_name = 'john';
```

This will only return users whose `first_name` is exactly "john" (case-sensitive).

---

### Conclusion

The `WHERE` clause is essential for filtering records based on specific conditions. It supports a wide variety of conditions using comparison operators, logical operators, pattern matching, and more. By effectively using the `WHERE` clause, you can retrieve or manipulate data in a highly flexible and precise manner. 

### Key Points:
- **Comparison operators** (`=`, `!=`, `>`, `<`, etc.) help filter records based on specific conditions.
- **Logical operators** (`AND`, `OR`, `NOT`) combine multiple conditions.
- **Pattern matching** with `LIKE`, `IN` for value lists, and `BETWEEN` for ranges.
- Use **`IS NULL`** and **`IS NOT NULL`** for checking null values.
- **`EXISTS`** helps with subqueries to check for the existence of data.

With these tools, you can filter data in powerful ways and efficiently retrieve the information you need from MariaDB.
