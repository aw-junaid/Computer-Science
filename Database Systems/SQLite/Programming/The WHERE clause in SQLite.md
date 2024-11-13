The **`WHERE`** clause in SQLite is used to filter records in a query. It specifies a condition that the rows must meet to be included in the result set. The `WHERE` clause can be used with various SQL statements like `SELECT`, `UPDATE`, `DELETE`, etc., to narrow down the results based on specific criteria.

### Basic Syntax of the `WHERE` Clause

```sql
SELECT column1, column2, ...
FROM table_name
WHERE condition;
```

Here, the `condition` is the expression that must evaluate to `TRUE`, `FALSE`, or `NULL`. If the condition is `TRUE`, the row is included in the result; if it's `FALSE` or `NULL`, the row is excluded.

### Common `WHERE` Clause Conditions

#### 1. **Comparison Operators**
Comparison operators are used to compare values in the `WHERE` clause.

- **`=`**: Equal to
- **`!=`** or **`<>`**: Not equal to
- **`>`**: Greater than
- **`<`**: Less than
- **`>=`**: Greater than or equal to
- **`<=`**: Less than or equal to

##### Example:

```sql
SELECT * FROM users
WHERE age >= 18;
```

This query selects all users where the `age` is greater than or equal to 18.

---

#### 2. **Logical Operators**
Logical operators are used to combine multiple conditions in the `WHERE` clause.

- **`AND`**: Returns true if both conditions are true.
- **`OR`**: Returns true if at least one condition is true.
- **`NOT`**: Negates a condition, returning true if the condition is false.

##### Example using `AND`:

```sql
SELECT * FROM users
WHERE age >= 18 AND gender = 'M';
```

This query selects all male users who are 18 or older.

##### Example using `OR`:

```sql
SELECT * FROM users
WHERE age < 18 OR age > 60;
```

This selects all users who are either under 18 or over 60 years old.

##### Example using `NOT`:

```sql
SELECT * FROM users
WHERE NOT age = 25;
```

This excludes users who are exactly 25 years old.

---

#### 3. **Pattern Matching**
You can use the `LIKE` operator for pattern matching with strings. The `LIKE` operator works with two wildcards:

- **`%`**: Matches zero or more characters.
- **`_`**: Matches exactly one character.

##### Example:

```sql
SELECT * FROM users
WHERE name LIKE 'A%';
```

This query selects users whose `name` starts with the letter 'A'.

##### Example with `_` wildcard:

```sql
SELECT * FROM users
WHERE name LIKE '_o%';
```

This selects users whose name has 'o' as the second character.

---

#### 4. **IS NULL / IS NOT NULL**
The `IS NULL` operator is used to check whether a column has a `NULL` value. The `IS NOT NULL` operator is used to check for non-`NULL` values.

##### Example:

```sql
SELECT * FROM users
WHERE age IS NULL;
```

This selects users where `age` is `NULL`.

##### Example using `IS NOT NULL`:

```sql
SELECT * FROM users
WHERE age IS NOT NULL;
```

This selects users where `age` is not `NULL`.

---

#### 5. **BETWEEN**
The `BETWEEN` operator is used to filter values within a specified range. The range is inclusive, meaning both boundary values are included.

##### Example:

```sql
SELECT * FROM users
WHERE age BETWEEN 18 AND 30;
```

This selects users whose `age` is between 18 and 30, inclusive.

---

#### 6. **IN**
The `IN` operator is used to check if a value matches any value in a list of specified values.

##### Example:

```sql
SELECT * FROM users
WHERE age IN (18, 21, 25);
```

This selects users whose `age` is either 18, 21, or 25.

---

#### 7. **Subqueries in the `WHERE` Clause**
A subquery can be used in the `WHERE` clause to filter results based on the result of another query.

##### Example:

```sql
SELECT name, age
FROM users
WHERE age > (SELECT AVG(age) FROM users);
```

This selects users whose `age` is greater than the average age of all users. The subquery calculates the average age, and the outer query filters users who are older than that value.

---

#### 8. **CASE Expressions in the `WHERE` Clause**
A `CASE` expression can be used inside the `WHERE` clause for conditional logic.

##### Example:

```sql
SELECT * FROM users
WHERE 
  CASE 
    WHEN age >= 18 THEN 'Adult'
    ELSE 'Minor'
  END = 'Adult';
```

This query selects users whose age is greater than or equal to 18, treating them as "Adults" based on the `CASE` expression.

---

### Examples of `WHERE` Clause Usage

#### Example 1: Using Multiple Conditions

```sql
SELECT * FROM users
WHERE age > 20 AND gender = 'F' AND city = 'New York';
```

This selects all female users older than 20 living in New York.

#### Example 2: Using `LIKE` with Wildcards

```sql
SELECT * FROM products
WHERE product_name LIKE 'S%';
```

This selects products whose name starts with the letter 'S'.

#### Example 3: Using `IN` with a List

```sql
SELECT * FROM orders
WHERE status IN ('Pending', 'Shipped');
```

This selects orders that are either "Pending" or "Shipped".

---

### Summary of `WHERE` Clause Operators

- **Comparison Operators**: `=`, `!=`, `>`, `<`, `>=`, `<=`
- **Logical Operators**: `AND`, `OR`, `NOT`
- **String Matching**: `LIKE`, `%`, `_`
- **NULL Checks**: `IS NULL`, `IS NOT NULL`
- **Range Check**: `BETWEEN`
- **Multiple Values**: `IN`
- **Subqueries**: Using a subquery to filter results.
- **Conditional Expressions**: Using `CASE` for conditional logic.

The `WHERE` clause is a powerful tool in SQLite that allows you to filter rows based on various conditions, helping you get precise results from your database queries.
