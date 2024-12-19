### MariaDB - ORDER BY Clause

The `ORDER BY` clause in MariaDB is used to sort the result set of a query in either ascending or descending order. It can be applied to one or more columns in a table. By default, the sorting is in **ascending** order (from A to Z, or smallest to largest), but you can specify **descending** order (from Z to A, or largest to smallest).

---

### Basic Syntax

```sql
SELECT column1, column2, ...
FROM table_name
WHERE condition
ORDER BY column_name [ASC|DESC];
```

- **`column1, column2, ...`**: The columns to retrieve.
- **`table_name`**: The name of the table.
- **`WHERE condition`**: Optional. The condition to filter the rows.
- **`ORDER BY column_name`**: Specifies the column by which to sort the result.
- **`ASC|DESC`**: Optional. Defines the sorting order.
  - `ASC` (default) means ascending order.
  - `DESC` means descending order.

---

### 1. **Sorting in Ascending Order (Default)**

By default, the `ORDER BY` clause sorts the result set in ascending order.

#### Example:

```sql
SELECT * FROM users
ORDER BY first_name;
```

This will return all users, sorted by `first_name` in ascending order (A to Z).

#### Example (numeric sorting):

```sql
SELECT * FROM products
ORDER BY price;
```

This will return all products, sorted by `price` in ascending order (lowest to highest).

---

### 2. **Sorting in Descending Order**

You can specify the sorting order to be descending by using the `DESC` keyword.

#### Example:

```sql
SELECT * FROM users
ORDER BY first_name DESC;
```

This will return all users, sorted by `first_name` in descending order (Z to A).

#### Example (numeric sorting):

```sql
SELECT * FROM products
ORDER BY price DESC;
```

This will return all products, sorted by `price` in descending order (highest to lowest).

---

### 3. **Sorting by Multiple Columns**

You can sort the result by multiple columns. The rows are first sorted by the first column, and then within those rows, sorted by the second column, and so on.

#### Example:

```sql
SELECT * FROM users
ORDER BY last_name ASC, first_name ASC;
```

This will:
1. Sort the result by `last_name` in ascending order.
2. For users with the same `last_name`, it will sort them by `first_name` in ascending order.

---

### 4. **Sorting by Expressions**

You can sort by expressions, which means that you can sort based on the results of calculations or functions.

#### Example:

```sql
SELECT first_name, last_name, salary
FROM employees
ORDER BY salary * 0.9 DESC;
```

This will return all employees, sorted by a calculation on their `salary` (e.g., after applying a 10% discount), in descending order.

---

### 5. **Sorting by NULL Values**

When sorting data with `ORDER BY`, MariaDB places `NULL` values first when sorting in ascending order and last when sorting in descending order. You can control this behavior with the `IS NULL` condition or use the `NULLS FIRST` or `NULLS LAST` keywords (available in some MariaDB versions).

#### Example (default behavior):

```sql
SELECT * FROM products
ORDER BY price;
```

This will list products, with `NULL` values for `price` coming at the beginning (in ascending order).

#### Example (sorting `NULL` values at the end):

```sql
SELECT * FROM products
ORDER BY price DESC NULLS LAST;
```

This will place rows with `NULL` values for `price` at the end of the result set when sorting in descending order.

---

### 6. **Sorting with `LIMIT`**

You can combine `ORDER BY` with `LIMIT` to get a specific number of rows from the sorted result.

#### Example:

```sql
SELECT * FROM users
ORDER BY last_login DESC
LIMIT 5;
```

This will return the **top 5** users who logged in most recently (sorted by `last_login` in descending order).

---

### 7. **Sorting Text Data (Case Sensitivity)**

MariaDB’s sorting behavior depends on the collation of the column. By default, text columns are sorted case-insensitively, but this can be changed based on the column’s collation.

#### Example (case-insensitive sorting):

```sql
SELECT * FROM users
ORDER BY first_name;
```

This will sort `first_name` in a case-insensitive manner by default (e.g., "alice", "Bob", and "john" will all be treated equally in sorting).

#### Example (case-sensitive sorting):

To perform case-sensitive sorting, you can use the `BINARY` keyword:

```sql
SELECT * FROM users
ORDER BY BINARY first_name;
```

This will sort the `first_name` column in a case-sensitive manner, where "Alice" will come before "alice".

---

### 8. **Sorting with `RAND()`**

You can use the `RAND()` function in `ORDER BY` to get random rows from the table.

#### Example:

```sql
SELECT * FROM products
ORDER BY RAND();
```

This will return the products in a random order.

---

### 9. **Performance Considerations**

- **Indexes**: If the column you are sorting by is indexed, MariaDB can use the index to speed up the sorting process. Sorting on non-indexed columns may result in slower queries, especially for large datasets.
- **Multiple Sort Keys**: Sorting by multiple columns can also be slow, especially if the columns are not indexed or the dataset is large.
- **Sorting Complex Data**: Sorting by calculated expressions, `RAND()`, or columns with large text fields can be more resource-intensive and should be used carefully in large queries.

---

### Example Summary

1. **Sorting in ascending order**:
    ```sql
    SELECT * FROM products
    ORDER BY product_name;
    ```

2. **Sorting in descending order**:
    ```sql
    SELECT * FROM products
    ORDER BY price DESC;
    ```

3. **Sorting by multiple columns**:
    ```sql
    SELECT * FROM users
    ORDER BY last_name ASC, first_name ASC;
    ```

4. **Sorting with expressions**:
    ```sql
    SELECT name, price
    FROM products
    ORDER BY price * 1.2 DESC;
    ```

5. **Using `LIMIT` with `ORDER BY`**:
    ```sql
    SELECT * FROM users
    ORDER BY last_login DESC
    LIMIT 10;
    ```

6. **Sorting with random order**:
    ```sql
    SELECT * FROM products
    ORDER BY RAND();
    ```

---

### Conclusion

The `ORDER BY` clause in MariaDB is essential for organizing the result set of queries in a meaningful way. Whether you're sorting in ascending or descending order, by one or more columns, or applying custom expressions, `ORDER BY` provides flexibility in displaying data. By using it wisely, you can enhance the user experience and improve the performance of your queries.
