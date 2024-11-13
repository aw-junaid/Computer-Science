In SQLite, **operators** are used in SQL queries to perform operations on values or expressions. Operators help filter, compare, and manipulate data. SQLite supports a wide variety of operators, which can be grouped into several categories:

### 1. **Arithmetic Operators**
Arithmetic operators are used to perform basic mathematical operations.

- **`+`**: Addition
- **`-`**: Subtraction
- **`*`**: Multiplication
- **`/`**: Division
- **`%`**: Modulo (remainder after division)

#### Example:

```sql
SELECT 5 + 3 AS addition, 
       10 - 4 AS subtraction, 
       2 * 3 AS multiplication, 
       10 / 2 AS division, 
       10 % 3 AS modulo;
```

### 2. **Comparison Operators**
Comparison operators are used to compare two values. The result is a Boolean value (`TRUE`, `FALSE`, or `NULL`).

- **`=`**: Equal to
- **`!=`** or **`<>`**: Not equal to
- **`>`**: Greater than
- **`<`**: Less than
- **`>=`**: Greater than or equal to
- **`<=`**: Less than or equal to

#### Example:

```sql
SELECT * FROM users
WHERE age >= 18;
```

This selects users whose `age` is greater than or equal to 18.

### 3. **Logical Operators**
Logical operators are used to combine multiple conditions in a query.

- **`AND`**: Returns true if both conditions are true.
- **`OR`**: Returns true if at least one condition is true.
- **`NOT`**: Negates a condition.

#### Example:

```sql
SELECT * FROM users
WHERE age > 18 AND name LIKE 'A%';
```

This query selects users who are older than 18 **and** whose name starts with 'A'.

### 4. **String Operators**
SQLite supports several operators to work with string data.

- **`||`**: Concatenation operator. It combines two strings into one.

#### Example:

```sql
SELECT 'Hello' || ' ' || 'World' AS greeting;
```

This will output `'Hello World'`.

- **`LIKE`**: Used for pattern matching in string values. It supports wildcard characters:
  - **`%`**: Matches zero or more characters.
  - **`_`**: Matches exactly one character.

#### Example:

```sql
SELECT * FROM users
WHERE name LIKE 'A%';
```

This query finds all users whose name starts with the letter 'A'.

### 5. **IS NULL / IS NOT NULL**
These operators are used to check if a value is `NULL` or not.

- **`IS NULL`**: Returns true if the value is `NULL`.
- **`IS NOT NULL`**: Returns true if the value is not `NULL`.

#### Example:

```sql
SELECT * FROM users
WHERE age IS NULL;
```

This retrieves all users whose `age` is `NULL`.

### 6. **BETWEEN**
The `BETWEEN` operator is used to filter results within a specific range, inclusive of the boundary values.

#### Example:

```sql
SELECT * FROM users
WHERE age BETWEEN 18 AND 30;
```

This query returns users whose `age` is between 18 and 30, inclusive.

### 7. **IN**
The `IN` operator is used to check if a value is within a specified list of values.

#### Example:

```sql
SELECT * FROM users
WHERE age IN (18, 21, 25);
```

This returns users whose `age` is either 18, 21, or 25.

### 8. **EXISTS**
The `EXISTS` operator is used to check if a subquery returns any results. It returns true if the subquery contains any rows.

#### Example:

```sql
SELECT * FROM users
WHERE EXISTS (SELECT 1 FROM orders WHERE user_id = users.id);
```

This selects users who have placed at least one order.

### 9. **CASE**
The `CASE` expression allows you to perform conditional logic directly in your SQL query, much like an `IF` statement in programming.

#### Example:

```sql
SELECT name, 
       CASE
           WHEN age < 18 THEN 'Minor'
           WHEN age >= 18 THEN 'Adult'
           ELSE 'Unknown'
       END AS age_group
FROM users;
```

This returns each user's name and their corresponding age group (`Minor` or `Adult`), based on their `age`.

### 10. **Unary Operators**
- **`+`**: Unary plus, which doesn't change the value but indicates it's positive.
- **`-`**: Unary minus, which negates a number (converts positive to negative and vice versa).

#### Example:

```sql
SELECT -age AS negative_age FROM users;
```

This returns the negative value of each user's age.

### 11. **Aggregation Operators**
These operators perform calculations on a set of rows and return a single value.

- **`COUNT()`**: Returns the number of rows in a set.
- **`SUM()`**: Returns the sum of values in a set.
- **`AVG()`**: Returns the average of values in a set.
- **`MIN()`**: Returns the minimum value in a set.
- **`MAX()`**: Returns the maximum value in a set.

#### Example:

```sql
SELECT COUNT(*), AVG(age) FROM users;
```

This returns the total number of users and the average age of all users.

### 12. **`ALL` and `ANY`**
- **`ALL`**: Used to compare a value to all values in another result set or subquery. The comparison must be true for all rows.
- **`ANY`**: Used to compare a value to any value in another result set or subquery. The comparison is true if it is true for at least one row.

#### Example with `ALL`:

```sql
SELECT * FROM users
WHERE age > ALL (SELECT age FROM users WHERE name LIKE 'A%');
```

This query finds users whose age is greater than the age of all users whose name starts with 'A'.

---

### Summary of Common Operators

- **Arithmetic**: `+`, `-`, `*`, `/`, `%`
- **Comparison**: `=`, `!=`, `>`, `<`, `>=`, `<=`
- **Logical**: `AND`, `OR`, `NOT`
- **String**: `||`, `LIKE`, `IN`, `BETWEEN`
- **Null Checks**: `IS NULL`, `IS NOT NULL`
- **Conditional**: `CASE`
- **Subquery**: `EXISTS`
- **Aggregate**: `COUNT()`, `SUM()`, `AVG()`, `MIN()`, `MAX()`

These operators allow you to perform a wide variety of operations when querying and manipulating data in SQLite. You can combine them to write complex queries for filtering, sorting, and transforming data based on your specific needs.
