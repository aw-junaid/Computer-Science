### MariaDB - Regular Expressions

In MariaDB, **regular expressions** are patterns used to match character combinations in strings. Regular expressions provide powerful search and text-processing capabilities. You can use regular expressions for tasks like pattern matching, data validation, and text manipulation in SQL queries.

MariaDB supports **regular expressions** in several string comparison functions, most notably `REGEXP` (or `RLIKE`), which is used to match a pattern against a string.

---

### 1. **REGEXP and RLIKE**

- `REGEXP` and `RLIKE` are the same and can be used interchangeably. Both are used in `SELECT` queries to find records that match a given regular expression pattern.
  
#### Syntax:

```sql
SELECT column_name
FROM table_name
WHERE column_name REGEXP 'pattern';
```

- **`REGEXP`** returns rows where the specified column matches the given regular expression.
- **`RLIKE`** is a synonym for `REGEXP`, so you can use either in your queries.

#### Example (Matching a pattern):

```sql
SELECT name
FROM employees
WHERE email REGEXP '@example\.com$';
```

This query returns employees whose email addresses end with `@example.com`.

---

### 2. **Regular Expression Syntax in MariaDB**

MariaDB uses **POSIX regular expressions** (portable operating system interface). The regular expressions in MariaDB are similar to those used in other regular expression engines but with some unique characteristics.

Here are some basic constructs in regular expressions:

- **`.`** (Dot): Matches any single character except a newline.
- **`*`**: Matches zero or more occurrences of the preceding character or group.
- **`+`**: Matches one or more occurrences of the preceding character or group.
- **`?`**: Matches zero or one occurrence of the preceding character or group.
- **`[]`**: Matches any single character from the set inside the brackets. For example, `[a-z]` matches any lowercase letter.
- **`^`**: Anchors the match at the beginning of the string.
- **`$`**: Anchors the match at the end of the string.
- **`|`**: Alternation (logical OR), for example, `cat|dog` matches either "cat" or "dog".
- **`()`**: Groups expressions together.

---

### 3. **Examples of Regular Expressions in MariaDB**

#### 1. **Match Any Character (Dot Operator)**

```sql
SELECT name
FROM employees
WHERE email REGEXP '^a.e$';
```

This query matches emails that start with 'a', followed by any character (due to the dot `.`), and end with 'e'. For example, it would match `ate`, `axe`, etc.

#### 2. **Match a Range of Characters**

```sql
SELECT name
FROM employees
WHERE email REGEXP '[a-z]+@[a-z]+\.[a-z]+';
```

This query matches emails that contain lowercase letters, followed by `@`, lowercase letters, a dot (`.`), and then more lowercase letters. It would match emails like `abc@xyz.com`.

#### 3. **Match Specific String**

```sql
SELECT name
FROM employees
WHERE email REGEXP 'admin.*@example\.com';
```

This query will match emails that start with `admin` and end with `@example.com`. The `.*` in the middle matches any string.

#### 4. **Match Multiple Alternatives (Alternation Operator)**

```sql
SELECT name
FROM employees
WHERE email REGEXP 'admin|manager';
```

This will return employees whose email contains either `admin` or `manager`.

#### 5. **Match Start or End of String**

```sql
SELECT name
FROM employees
WHERE email REGEXP '^user.*@domain\.com$';
```

This query matches emails that:
- Start with `user` (`^` at the beginning).
- End with `@domain.com` (`$` at the end).
- Have any number of characters in between (`.*`).

#### 6. **Match Specific Number of Characters**

```sql
SELECT name
FROM employees
WHERE phone REGEXP '^[0-9]{10}$';
```

This query matches a `phone` column that contains exactly 10 digits. The `{10}` specifies that exactly 10 occurrences of the preceding character (digits in this case) are required.

#### 7. **Escape Special Characters**

If you need to match a special character (like a dot `.` or asterisk `*`), you can escape it with a backslash `\`.

```sql
SELECT name
FROM employees
WHERE email REGEXP '\\.';
```

This query matches any email containing a literal dot (`.`), because the dot is a special character in regular expressions and needs to be escaped with `\\`.

---

### 4. **Other Useful Functions for Pattern Matching**

- **`NOT REGEXP`**: Used for negating the regular expression match. It returns rows where the column does not match the regular expression.

```sql
SELECT name
FROM employees
WHERE email NOT REGEXP 'admin';
```

This query returns employees whose email does not contain the string `admin`.

- **`REGEXP_LIKE()`**: This function can also be used to check if a pattern matches. It is often used for compatibility with other database systems.

```sql
SELECT name
FROM employees
WHERE REGEXP_LIKE(email, '^admin');
```

- **`REGEXP_REPLACE()`**: Allows you to replace a pattern in a string with another value.

```sql
SELECT REGEXP_REPLACE(email, '@example\.com', '@newdomain\.com')
FROM employees;
```

This replaces all occurrences of `@example.com` with `@newdomain.com` in the `email` column.

- **`REGEXP_INSTR()`**: Returns the position of the first match of the regular expression pattern in a string.

```sql
SELECT REGEXP_INSTR(email, '@')
FROM employees;
```

This query returns the position of the first occurrence of `@` in each email address.

---

### 5. **Limitations of Regular Expressions in MariaDB**

While regular expressions are powerful, there are some limitations in MariaDB:

- MariaDB's regular expression engine is based on POSIX, which may not be as feature-rich as other regular expression engines like Perl, Python, or JavaScript.
- MariaDB does not support some advanced regular expression features like lookahead/lookbehind assertions and non-capturing groups (?:).
- Regular expression matching in MariaDB can be less efficient compared to simple string matching.

---

### Conclusion

Regular expressions in MariaDB are a powerful tool for pattern matching and text manipulation. They allow you to perform complex searches, data validation, and transformations within SQL queries. Understanding how to use `REGEXP` (or `RLIKE`), the various regular expression operators, and functions like `REGEXP_REPLACE()` can greatly enhance your ability to work with string data in MariaDB.
