### SQLite - Date & Time

SQLite provides several functions and ways to work with **date and time** values. Although SQLite does not have a dedicated `DATE` or `TIME` data type, it supports a range of date and time functions that allow you to store and manipulate date and time values.

SQLite stores **date and time** as **text**, **real**, or **integer** values:
- **Text**: In the format `YYYY-MM-DD HH:MM:SS`.
- **Real**: The number of days since the Julian day (a continuous count of days since the start of the Julian Period, which started in 4713 BC).
- **Integer**: The number of seconds since `1970-01-01 00:00:00` UTC (UNIX epoch).

SQLite’s date and time functions make it easy to manipulate dates and times in SQL queries.

---

### Date and Time Functions in SQLite

SQLite provides several built-in date and time functions that you can use in SQL queries. Here are the most commonly used functions:

---

#### 1. **`DATE`**: Returns the date in the format `YYYY-MM-DD`.

- **Syntax**: `DATE(timestring, modifier1, modifier2, ...)`
  
- **Example**: To get the current date:

```sql
SELECT DATE('now');
```

This will return the current date in `YYYY-MM-DD` format (e.g., `2024-11-11`).

- **Modifiers**: You can apply modifiers to adjust the result:
  - `'now'`: Returns the current date and time in UTC.
  - `'+'` and `'-'`: To add or subtract from the current date.
  - Example: Get the date 5 days ago:

  ```sql
  SELECT DATE('now', '-5 days');
  ```

  Output might be: `2024-11-06`.

---

#### 2. **`TIME`**: Returns the time in the format `HH:MM:SS`.

- **Syntax**: `TIME(timestring, modifier1, modifier2, ...)`

- **Example**: To get the current time:

```sql
SELECT TIME('now');
```

This will return the current time in `HH:MM:SS` format (e.g., `12:45:30`).

- **Modifiers**: Similar to the `DATE` function, you can modify the time:
  - Get the time one hour ago:

  ```sql
  SELECT TIME('now', '-1 hour');
  ```

  Output might be: `11:45:30`.

---

#### 3. **`DATETIME`**: Combines the `DATE` and `TIME` functions to return both the date and time in the format `YYYY-MM-DD HH:MM:SS`.

- **Syntax**: `DATETIME(timestring, modifier1, modifier2, ...)`

- **Example**: To get the current date and time:

```sql
SELECT DATETIME('now');
```

This will return the current date and time in `YYYY-MM-DD HH:MM:SS` format (e.g., `2024-11-11 12:45:30`).

- **Modifiers**: You can modify both date and time together:
  - Get the date and time 5 days from now:

  ```sql
  SELECT DATETIME('now', '+5 days');
  ```

  Output might be: `2024-11-16 12:45:30`.

---

#### 4. **`JULIANDAY`**: Returns the Julian day, which is the number of days since January 1, 4713 BC.

- **Syntax**: `JULIANDAY(timestring)`

- **Example**: To get the current Julian day:

```sql
SELECT JULIANDAY('now');
```

This will return a real number representing the current Julian day.

- **Modifiers**: Similar to other functions, you can modify the Julian day result:
  - Get the Julian day 3 days in the future:

  ```sql
  SELECT JULIANDAY('now', '+3 days');
  ```

---

#### 5. **`STRFTIME`**: Formats a given date/time value into a string based on a specified format.

- **Syntax**: `STRFTIME(format, timestring, modifier1, modifier2, ...)`

- **Example**: To get the current date in `DD-MM-YYYY` format:

```sql
SELECT STRFTIME('%d-%m-%Y', 'now');
```

This will return the current date formatted as `11-11-2024`.

- **Common Format Specifiers**:
  - `%Y`: Year (4 digits).
  - `%m`: Month (2 digits).
  - `%d`: Day (2 digits).
  - `%H`: Hour (24-hour format).
  - `%M`: Minute.
  - `%S`: Second.
  - `%w`: Day of the week (0 = Sunday, 1 = Monday, etc.).

Example: Get the current date and time in `YYYY-MM-DD HH:MM:SS` format:

```sql
SELECT STRFTIME('%Y-%m-%d %H:%M:%S', 'now');
```

Output might be: `2024-11-11 12:45:30`.

---

### Storing Date and Time in SQLite

In SQLite, date and time values are stored as:

1. **Text**: Formatted as `YYYY-MM-DD HH:MM:SS` (ISO 8601).
2. **Real**: Julian day (a floating-point value representing the number of days since 4713 BC).
3. **Integer**: Unix timestamp (the number of seconds since `1970-01-01 00:00:00` UTC).

If you're storing date and time in SQLite, it's generally a good practice to store them as **text** in the ISO 8601 format (`YYYY-MM-DD HH:MM:SS`) since this format is easily readable and compatible with SQLite's date and time functions.

---

### Example: Working with Date and Time in a Table

Consider a table `events` with a `start_time` column that stores the date and time of an event.

```sql
CREATE TABLE events (
    event_id INTEGER PRIMARY KEY,
    event_name TEXT,
    start_time TEXT
);
```

You can insert an event with a specific date and time:

```sql
INSERT INTO events (event_name, start_time) 
VALUES ('Conference', DATETIME('2024-11-15 09:00:00'));
```

To retrieve events that start after a certain date:

```sql
SELECT * 
FROM events 
WHERE start_time > DATETIME('2024-11-11 00:00:00');
```

---

### Common Use Cases for Date and Time Functions

1. **Calculating the difference between two dates**:  
   To calculate the number of days between two dates, you can use `JULIANDAY`:

   ```sql
   SELECT JULIANDAY('2024-11-11') - JULIANDAY('2024-11-01');
   ```

   This will return the number of days between `2024-11-11` and `2024-11-01`.

2. **Getting events that happened in the last 7 days**:

   ```sql
   SELECT * 
   FROM events 
   WHERE start_time >= DATETIME('now', '-7 days');
   ```

3. **Extracting parts of a date**:  
   To get the year, month, or day from a date:

   ```sql
   SELECT STRFTIME('%Y', '2024-11-11');  -- Returns '2024'
   SELECT STRFTIME('%m', '2024-11-11');  -- Returns '11'
   SELECT STRFTIME('%d', '2024-11-11');  -- Returns '11'
   ```

---

### Conclusion

SQLite’s date and time functions offer a robust set of tools for working with date and time values, even though SQLite doesn't have a native `DATE` or `TIME` data type. You can use **`DATE`**, **`TIME`**, **`DATETIME`**, **`JULIANDAY`**, and **`STRFTIME`** functions to perform a variety of date and time operations, such as retrieving the current date and time, adding or subtracting from dates, formatting dates, and more. Whether you're working with timestamps, durations, or formatted dates, SQLite provides flexibility for handling temporal data in your applications.
