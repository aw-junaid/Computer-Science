### Using ORDER BY in PostgreSQL

The `ORDER BY` clause is used to sort the result set of a query in PostgreSQL. Here's how you can use it:

1. **Connect to Your Database**:
   ```bash
   psql -U your_username -d your_database_name -h your_host -p your_port
   ```
   Replace `your_username`, `your_database_name`, `your_host`, and `your_port` with actual database credentials.

2. **Switch to the Database**:
   ```sql
   \c your_database_name
   ```
   This command switches your current connection to the specified database.

3. **Basic ORDER BY**:
   ```sql
   SELECT * FROM your_table_name ORDER BY column;
   ```
   Replace `your_table_name` with the name of the table you're querying, and `column` with the column by which you want to sort.

   For example:
   ```sql
   SELECT * FROM users ORDER BY age;
   ```
   This sorts the result set by the `age` column in ascending order.

4. **Descending Order**:
   To sort in descending order, add `DESC` after the column name.
   ```sql
   SELECT * FROM your_table_name ORDER BY column DESC;
   ```
   For example:
   ```sql
   SELECT * FROM users ORDER BY age DESC;
   ```

5. **Sorting by Multiple Columns**:
   You can sort by multiple columns, with the first column taking precedence.
   ```sql
   SELECT * FROM your_table_name ORDER BY column1, column2;
   ```
   For example:
   ```sql
   SELECT * FROM products ORDER BY category, price DESC;
   ```
   This sorts by `category` in ascending order and then by `price` in descending order.

6. **NULL Handling**:
   By default, `NULL` values come last in ascending order. To change this behavior, use `NULLS FIRST` or `NULLS LAST`.
   ```sql
   SELECT * FROM your_table_name ORDER BY column NULLS FIRST;
   ```
   For example:
   ```sql
   SELECT * FROM employees ORDER BY salary NULLS LAST;
   ```
   This sorts by `salary` with `NULL` values coming last.

Remember to replace placeholders with actual values and adapt the queries to your specific use case.
