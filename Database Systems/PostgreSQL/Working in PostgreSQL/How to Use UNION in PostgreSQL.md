### Using UNION in PostgreSQL

The `UNION` operator in PostgreSQL is used to combine the result sets of two or more `SELECT` queries into a single result set. Here's how you can use it:

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

3. **Perform a UNION**:
   ```sql
   SELECT column1, column2, ...
   FROM table1
   UNION
   SELECT column1, column2, ...
   FROM table2;
   ```
   Replace `column1`, `column2`, and `table1`, `table2` with the appropriate column names and table names.

   For example:
   ```sql
   SELECT customer_name
   FROM customers
   UNION
   SELECT employee_name
   FROM employees;
   ```
   This retrieves a list of both customer names and employee names, with duplicates removed.

4. **Using UNION ALL**:
   If you want to include duplicate rows in the result set, you can use `UNION ALL` instead of `UNION`.
   ```sql
   SELECT column1, column2, ...
   FROM table1
   UNION ALL
   SELECT column1, column2, ...
   FROM table2;
   ```

   For example:
   ```sql
   SELECT customer_name
   FROM customers
   UNION ALL
   SELECT customer_name
   FROM old_customers;
   ```
   This includes duplicate customer names in the result set.

Remember, when using `UNION`, the number of columns, their data types, and their positions in the `SELECT` statements must match. `UNION ALL` allows for differences in these aspects.
