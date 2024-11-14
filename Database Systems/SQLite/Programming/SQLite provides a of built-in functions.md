SQLite provides a variety of built-in functions that help you manipulate and retrieve data efficiently. These functions can be categorized into several types, such as **aggregate functions**, **scalar functions**, **date and time functions**, and others that simplify common tasks. Below is an overview of some of the most useful functions in SQLite.

### 1. **Aggregate Functions**

Aggregate functions perform a calculation on a set of values and return a single result.

#### **COUNT()**
Counts the number of rows in a dataset or the number of non-NULL values in a column.

- **Example**: Get the number of users:

```sql
SELECT COUNT(*) FROM users;
```

#### **SUM()**
Returns the sum of all the values in a numeric column.

- **Example**: Calculate the total price of all orders:

```sql
SELECT SUM(price) FROM orders;
```

#### **AVG()**
Returns the average of the values in a numeric column.

- **Example**: Get the average age of users:

```sql
SELECT AVG(age) FROM users;
```

#### **MAX()**
Returns the maximum value in a column.

- **Example**: Find the oldest user:

```sql
SELECT MAX(age) FROM users;
```

#### **MIN()**
Returns the minimum value in a column.

- **Example**: Find the youngest user:

```sql
SELECT MIN(age) FROM users;
```

---

### 2. **String Functions**

SQLite provides several functions for manipulating string data.

#### **UPPER()**
Converts a string to uppercase.

- **Example**: Convert a name to uppercase:

```sql
SELECT UPPER(name) FROM users;
```

#### **LOWER()**
Converts a string to lowercase.

- **Example**: Convert a name to lowercase:

```sql
SELECT LOWER(name) FROM users;
```

#### **LENGTH()**
Returns the length of a string.

- **Example**: Get the length of a user's name:

```sql
SELECT LENGTH(name) FROM users;
```

#### **SUBSTR()**
Extracts a substring from a string.

- **Example**: Get the first 5 characters of a name:

```sql
SELECT SUBSTR(name, 1, 5) FROM users;
```

#### **REPLACE()**
Replaces occurrences of a substring with another string.

- **Example**: Replace a specific character in a string:

```sql
SELECT REPLACE(name, 'John', 'Jane') FROM users;
```

#### **TRIM()**
Removes leading and trailing spaces from a string.

- **Example**: Trim spaces from a name:

```sql
SELECT TRIM(name) FROM users;
```

---

### 3. **Mathematical Functions**

SQLite supports a variety of mathematical functions.

#### **ABS()**
Returns the absolute value of a number.

- **Example**: Get the absolute value of a number:

```sql
SELECT ABS(-15);  -- Returns 15
```

#### **ROUND()**
Rounds a number to a specified number of decimal places.

- **Example**: Round a price to two decimal places:

```sql
SELECT ROUND(price, 2) FROM products;
```

#### **RANDOM()**
Returns a random integer.

- **Example**: Generate a random number:

```sql
SELECT RANDOM();
```

#### **PI()**
Returns the value of Pi (3.14159...).

- **Example**: Get the value of Pi:

```sql
SELECT PI();
```

#### **MOD()**
Returns the remainder of dividing two numbers.

- **Example**: Get the remainder of dividing 10 by 3:

```sql
SELECT MOD(10, 3);  -- Returns 1
```

---

### 4. **Date and Time Functions**

SQLite provides a range of functions to manipulate and retrieve date and time values.

#### **DATE()**
Returns the current date in the `YYYY-MM-DD` format.

- **Example**: Get the current date:

```sql
SELECT DATE('now');
```

#### **TIME()**
Returns the current time in `HH:MM:SS` format.

- **Example**: Get the current time:

```sql
SELECT TIME('now');
```

#### **DATETIME()**
Returns the current date and time in `YYYY-MM-DD HH:MM:SS` format.

- **Example**: Get the current date and time:

```sql
SELECT DATETIME('now');
```

#### **JULIANDAY()**
Returns the Julian day, which is the number of days since the start of the Julian Period.

- **Example**: Get the Julian day for the current date:

```sql
SELECT JULIANDAY('now');
```

#### **STRFTIME()**
Formats a date or time string according to a specific format.

- **Example**: Get the current date in `DD-MM-YYYY` format:

```sql
SELECT STRFTIME('%d-%m-%Y', 'now');
```

---

### 5. **Conditional Functions**

SQLite provides several conditional functions that help in decision-making within queries.

#### **IFNULL()**
Returns the first non-NULL value from a list of expressions.

- **Example**: Return a default value if a column is NULL:

```sql
SELECT IFNULL(name, 'Unknown') FROM users;
```

#### **COALESCE()**
Returns the first non-NULL value from a list of expressions (like `IFNULL`, but can handle multiple values).

- **Example**: Return the first non-NULL column value:

```sql
SELECT COALESCE(name, email, 'No name or email') FROM users;
```

#### **CASE**
Evaluates conditions and returns values based on those conditions (similar to `if` statements in programming).

- **Example**: Classify users as either 'Adult' or 'Minor' based on age:

```sql
SELECT name, 
       CASE 
           WHEN age >= 18 THEN 'Adult'
           ELSE 'Minor'
       END AS age_group
FROM users;
```

---

### 6. **JSON Functions**

SQLite supports a set of JSON functions if the JSON extension is enabled. These functions allow you to interact with JSON data stored in the database.

#### **json_extract()**
Extracts data from a JSON object.

- **Example**: Extract the value of the "name" key from a JSON object:

```sql
SELECT json_extract(data, '$.name') FROM users;
```

#### **json_object()**
Creates a JSON object from key-value pairs.

- **Example**: Create a JSON object from user data:

```sql
SELECT json_object('name', name, 'age', age) FROM users;
```

#### **json_array()**
Creates a JSON array from a list of values.

- **Example**: Create a JSON array from user names:

```sql
SELECT json_array(name) FROM users;
```

---

### 7. **Utility Functions**

These are general-purpose functions useful for working with various types of data.

#### **CAST()**
Converts a value from one type to another.

- **Example**: Convert a string to an integer:

```sql
SELECT CAST('123' AS INTEGER);
```

#### **NULLIF()**
Returns NULL if the two expressions are equal, otherwise returns the first expression.

- **Example**: Return NULL if the values are equal, else return the first value:

```sql
SELECT NULLIF(5, 5);  -- Returns NULL
SELECT NULLIF(5, 6);  -- Returns 5
```

#### **GROUP_CONCAT()**
Concatenates values from multiple rows into a single string.

- **Example**: Concatenate all usernames into a single string:

```sql
SELECT GROUP_CONCAT(username) FROM users;
```

---

### Conclusion

SQLite offers a wide range of built-in functions that help you manipulate and query data efficiently. These functions cover a variety of use cases, from working with numbers and strings to handling date/time values and JSON data. By leveraging these functions, you can streamline your SQL queries and improve performance, making your SQLite-powered applications more powerful and flexible.
