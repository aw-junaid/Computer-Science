### Using LEFT JOIN in PostgreSQL

The `LEFT JOIN` (or `LEFT OUTER JOIN`) in PostgreSQL allows you to retrieve all records from the left table and the matched records from the right table. If there's no match, NULL values are returned for columns from the right table. Here's how you can use it:

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

3. **Perform a LEFT JOIN**:
   ```sql
   SELECT table1.column1, table1.column2, table2.column3, ...
   FROM table1
   LEFT JOIN table2 ON table1.column_name = table2.column_name;
   ```
   Replace `table1`, `table2`, `column1`, `column2`, `column3`, and `column_name` with the appropriate table and column names.

   For example:
   ```sql
   SELECT customers.customer_name, orders.order_id
   FROM customers
   LEFT JOIN orders ON customers.customer_id = orders.customer_id;
   ```
   This retrieves customer names and their associated order IDs, including customers with no orders.

Remember, a `LEFT JOIN` returns all records from the left table and the matched records from the right table. If there's no match, NULL values are returned for columns from the right table. It's a powerful tool for combining data from different tables while preserving all records from the left table.
