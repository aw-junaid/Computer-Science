The **`DISTINCT`** keyword in SQLite is used to remove duplicate rows from the result set of a query. When you use `DISTINCT`, SQLite will return only the unique rows based on the selected columns, eliminating any duplicates.

The `DISTINCT` keyword is commonly used when you need to retrieve distinct or unique values from a column or a combination of columns, without worrying about repetitions in the data.

### Syntax of the `DISTINCT` Keyword

```sql
SELECT DISTINCT column_name(s)
FROM table
WHERE condition;
```

- **`column_name(s)`**: The column(s) for which you want to retrieve distinct values.
- **`table`**: The table from which to select the data.
- **`condition`**: An optional `WHERE` clause to filter the rows before retrieving distinct values.

### Key Points

- The `DISTINCT` keyword affects the entire result set. If you select multiple columns, the combination of values in those columns will be considered when determining uniqueness.
- **`DISTINCT`** can be used with one or more columns.
- It will only return rows where the values in the selected columns are unique.

---

### Example 1: Using `DISTINCT` on a Single Column

Suppose you have a `customers` table with a column `city` that contains the names of cities where customers are located. If you want to retrieve only the unique cities from the table, you can use the `DISTINCT` keyword:

```sql
SELECT DISTINCT city
FROM customers;
```

This query will return a list of unique cities without any duplicates.

---

### Example 2: Using `DISTINCT` on Multiple Columns

You can use `DISTINCT` to get unique combinations of values across multiple columns. For example, if you have a table of `orders` and you want to find the unique combinations of `customer_id` and `product_id` (i.e., the distinct pairs of customers and the products they ordered), you can use:

```sql
SELECT DISTINCT customer_id, product_id
FROM orders;
```

This query will return only unique pairs of `customer_id` and `product_id`, eliminating duplicates.

---

### Example 3: Using `DISTINCT` with `COUNT()`

You can also use `DISTINCT` in combination with aggregate functions like `COUNT()` to count the number of distinct values in a column. For example, to count the number of distinct cities in the `customers` table:

```sql
SELECT COUNT(DISTINCT city)
FROM customers;
```

This query will return the number of unique cities in the `customers` table, excluding duplicates.

---

### Example 4: Using `DISTINCT` with `WHERE` Clause

The `DISTINCT` keyword can also be used in combination with a `WHERE` clause to filter the rows before removing duplicates. For example, to get the unique `city` values for customers who live in a specific country:

```sql
SELECT DISTINCT city
FROM customers
WHERE country = 'USA';
```

This query will return the unique cities in the USA, filtering out duplicates.

---

### Example 5: Using `DISTINCT` on All Columns

If you want to retrieve distinct rows across all columns in a table (i.e., unique rows where every column combination is distinct), you can simply apply `DISTINCT` without specifying specific columns:

```sql
SELECT DISTINCT *
FROM customers;
```

This query will return only the unique rows in the `customers` table, where every column combination is unique.

---

### Performance Considerations

- Using `DISTINCT` can be resource-intensive, especially when working with large datasets. This is because SQLite needs to check for duplicates across all selected columns.
- If you only need to filter duplicates for specific columns, it's generally better to specify those columns in the `DISTINCT` clause rather than using `SELECT DISTINCT *`, which can be less efficient.

---

### Summary of `DISTINCT` Usage

- **`DISTINCT`** removes duplicate rows from the result set based on the columns specified.
- **Used with one or more columns**: You can retrieve unique values from one column or unique combinations of multiple columns.
- **Combined with `COUNT()`**: You can count the number of unique values using `COUNT(DISTINCT ...)`.
- **Can be used with `WHERE`**: You can filter rows before applying the `DISTINCT` keyword using the `WHERE` clause.
- **Used with `*`**: `DISTINCT *` returns only unique rows across all columns.

#### Common Use Cases:
- **Finding unique values**: `SELECT DISTINCT city FROM customers;`
- **Counting distinct values**: `SELECT COUNT(DISTINCT product_id) FROM orders;`
- **Removing duplicate rows**: `SELECT DISTINCT * FROM orders;`

The **`DISTINCT`** keyword is useful for eliminating duplicate data, allowing you to focus on unique values or combinations of values.
