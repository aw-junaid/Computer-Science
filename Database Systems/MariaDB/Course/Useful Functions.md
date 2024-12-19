### MariaDB - Useful Functions

MariaDB provides a wide range of built-in functions to manipulate data, perform calculations, and streamline database operations. These functions are useful for querying, transforming, and analyzing data in your MariaDB databases. Below is a collection of some of the most commonly used and useful functions in MariaDB.

---

### 1. **String Functions**

String functions allow you to manipulate string data in various ways.

#### **`CONCAT()`**
Combines multiple strings into one string.

```sql
SELECT CONCAT('Hello', ' ', 'World');
-- Output: 'Hello World'
```

#### **`SUBSTRING()`**
Extracts a substring from a given string.

```sql
SELECT SUBSTRING('Hello World', 1, 5);
-- Output: 'Hello'
```

#### **`LENGTH()`**
Returns the length of a string in characters.

```sql
SELECT LENGTH('Hello');
-- Output: 5
```

#### **`TRIM()`**
Removes leading and trailing spaces from a string.

```sql
SELECT TRIM('  Hello  ');
-- Output: 'Hello'
```

#### **`REPLACE()`**
Replaces occurrences of a substring within a string.

```sql
SELECT REPLACE('Hello World', 'World', 'MariaDB');
-- Output: 'Hello MariaDB'
```

#### **`UPPER()`**
Converts a string to uppercase.

```sql
SELECT UPPER('hello');
-- Output: 'HELLO'
```

#### **`LOWER()`**
Converts a string to lowercase.

```sql
SELECT LOWER('HELLO');
-- Output: 'hello'
```

---

### 2. **Mathematical Functions**

Mathematical functions are used to perform arithmetic operations and calculations.

#### **`ABS()`**
Returns the absolute value of a number.

```sql
SELECT ABS(-100);
-- Output: 100
```

#### **`ROUND()`**
Rounds a number to the nearest integer or a specified number of decimal places.

```sql
SELECT ROUND(123.4567, 2);
-- Output: 123.46
```

#### **`CEIL()`**
Returns the smallest integer greater than or equal to the given number.

```sql
SELECT CEIL(123.45);
-- Output: 124
```

#### **`FLOOR()`**
Returns the largest integer less than or equal to the given number.

```sql
SELECT FLOOR(123.45);
-- Output: 123
```

#### **`MOD()`**
Returns the remainder of a division.

```sql
SELECT MOD(10, 3);
-- Output: 1
```

#### **`RAND()`**
Generates a random number between 0 and 1.

```sql
SELECT RAND();
-- Output: A random number between 0 and 1
```

---

### 3. **Date and Time Functions**

Date and time functions help manipulate date and time values.

#### **`CURDATE()`**
Returns the current date in 'YYYY-MM-DD' format.

```sql
SELECT CURDATE();
-- Output: '2024-12-16'
```

#### **`NOW()`**
Returns the current date and time in 'YYYY-MM-DD HH:MM:SS' format.

```sql
SELECT NOW();
-- Output: '2024-12-16 14:30:45'
```

#### **`DATE_ADD()`**
Adds a specified time interval to a date.

```sql
SELECT DATE_ADD('2024-12-16', INTERVAL 1 DAY);
-- Output: '2024-12-17'
```

#### **`DATE_SUB()`**
Subtracts a specified time interval from a date.

```sql
SELECT DATE_SUB('2024-12-16', INTERVAL 1 MONTH);
-- Output: '2024-11-16'
```

#### **`YEAR()`**
Extracts the year from a date.

```sql
SELECT YEAR('2024-12-16');
-- Output: 2024
```

#### **`MONTH()`**
Extracts the month from a date.

```sql
SELECT MONTH('2024-12-16');
-- Output: 12
```

#### **`DAY()`**
Extracts the day of the month from a date.

```sql
SELECT DAY('2024-12-16');
-- Output: 16
```

#### **`DATEDIFF()`**
Returns the difference in days between two dates.

```sql
SELECT DATEDIFF('2024-12-16', '2024-12-01');
-- Output: 15
```

---

### 4. **Aggregate Functions**

Aggregate functions perform calculations on a set of rows and return a single value.

#### **`COUNT()`**
Returns the number of rows in a result set or the number of non-NULL values in a column.

```sql
SELECT COUNT(*) FROM employees;
-- Output: The number of employees
```

#### **`SUM()`**
Returns the sum of values in a numeric column.

```sql
SELECT SUM(salary) FROM employees;
-- Output: The total salary of all employees
```

#### **`AVG()`**
Returns the average value of a numeric column.

```sql
SELECT AVG(salary) FROM employees;
-- Output: The average salary of all employees
```

#### **`MIN()`**
Returns the smallest value in a column.

```sql
SELECT MIN(salary) FROM employees;
-- Output: The lowest salary
```

#### **`MAX()`**
Returns the largest value in a column.

```sql
SELECT MAX(salary) FROM employees;
-- Output: The highest salary
```

---

### 5. **Conditional Functions**

Conditional functions help implement logic directly within SQL queries.

#### **`IF()`**
Returns one value if a condition is true and another if false.

```sql
SELECT IF(salary > 50000, 'High', 'Low') FROM employees;
-- Output: 'High' or 'Low' depending on the salary value
```

#### **`CASE`**
Evaluates conditions and returns the first true condition’s result.

```sql
SELECT
  CASE
    WHEN salary > 50000 THEN 'High'
    WHEN salary > 30000 THEN 'Medium'
    ELSE 'Low'
  END
FROM employees;
-- Output: 'High', 'Medium', or 'Low' based on salary
```

---

### 6. **NULL Handling Functions**

These functions help to manage NULL values in queries.

#### **`ISNULL()`**
Returns 1 if the expression is NULL, otherwise returns 0.

```sql
SELECT ISNULL(salary) FROM employees;
-- Output: 1 if salary is NULL, 0 otherwise
```

#### **`IFNULL()`**
Returns the first non-NULL value in a list of expressions.

```sql
SELECT IFNULL(salary, 0) FROM employees;
-- Output: 0 if salary is NULL, otherwise salary value
```

#### **`COALESCE()`**
Returns the first non-NULL value in a list of expressions.

```sql
SELECT COALESCE(salary, bonus, 0) FROM employees;
-- Output: First non-NULL value from salary or bonus, else 0
```

---

### 7. **JSON Functions**

MariaDB provides functions for working with JSON data.

#### **`JSON_EXTRACT()`**
Extracts a value from a JSON document.

```sql
SELECT JSON_EXTRACT('{"name": "John", "age": 30}', '$.name');
-- Output: 'John'
```

#### **`JSON_ARRAY()`**
Creates a JSON array from the given values.

```sql
SELECT JSON_ARRAY(1, 'hello', TRUE);
-- Output: '[1, "hello", true]'
```

#### **`JSON_OBJECT()`**
Creates a JSON object from key-value pairs.

```sql
SELECT JSON_OBJECT('name', 'John', 'age', 30);
-- Output: '{"name": "John", "age": 30}'
```

---

### 8. **Window Functions**

Window functions are useful for performing calculations across a set of rows related to the current row.

#### **`ROW_NUMBER()`**
Assigns a unique row number to each row within the result set.

```sql
SELECT ROW_NUMBER() OVER (ORDER BY salary DESC) AS rank, name, salary
FROM employees;
```

#### **`RANK()`**
Assigns a rank to each row within the result set, with gaps in case of ties.

```sql
SELECT RANK() OVER (ORDER BY salary DESC) AS rank, name, salary
FROM employees;
```

#### **`NTILE()`**
Divides rows into a specified number of groups and assigns a group number.

```sql
SELECT NTILE(4) OVER (ORDER BY salary DESC) AS quartile, name, salary
FROM employees;
```

---

### Conclusion

MariaDB provides a wide range of useful functions for working with data, including string manipulation, mathematical operations, date and time handling, aggregation, conditionals, null handling, JSON functions, and even advanced window functions. By utilizing these functions, you can streamline your queries, perform complex data transformations, and gain insights from your database more efficiently.
