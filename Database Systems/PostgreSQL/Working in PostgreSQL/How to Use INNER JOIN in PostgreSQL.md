### Using INNER JOIN in PostgreSQL

The `INNER JOIN` in PostgreSQL allows you to combine rows from two or more tables based on related columns between them. Here's how you can use it:

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

3. **Perform an INNER JOIN**:
   ```sql
   SELECT table1.column1, table1.column2, table2.column3, ...
   FROM table1
   INNER JOIN table2 ON table1.column_name = table2.column_name;
   ```
   Replace `table1`, `table2`, `column1`, `column2`, `column3`, and `column_name` with the appropriate table and column names.

   For example:
   ```sql
   SELECT orders.order_id, customers.customer_name
   FROM orders
   INNER JOIN customers ON orders.customer_id = customers.customer_id;
   ```
   This retrieves order IDs and customer names for orders that have corresponding customers.

Remember, an `INNER JOIN` only returns rows where there's a match in both tables based on the specified condition. It's a powerful tool for combining data from different tables in a meaningful way.
