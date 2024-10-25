### Using Aggregate Functions in PostgreSQL

Aggregate functions in PostgreSQL allow you to perform calculations across rows of a result set. Here's how you can use them:

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

3. **Using COUNT() Function**:
   The `COUNT()` function counts the number of rows in a result set.
   ```sql
   SELECT COUNT(column_name) FROM table_name;
   ```
   For example:
   ```sql
   SELECT COUNT(customer_id) FROM customers;
   ```
   This counts the number of customer IDs in the `customers` table.

4. **Using SUM() Function**:
   The `SUM()` function calculates the sum of a numeric column.
   ```sql
   SELECT SUM(column_name) FROM table_name;
   ```
   For example:
   ```sql
   SELECT SUM(order_total) FROM orders;
   ```
   This calculates the total order amount in the `orders` table.

5. **Using AVG() Function**:
   The `AVG()` function calculates the average of a numeric column.
   ```sql
   SELECT AVG(column_name) FROM table_name;
   ```
   For example:
   ```sql
   SELECT AVG(price) FROM products;
   ```
   This calculates the average price of products in the `products` table.

6. **Using MAX() and MIN() Functions**:
   The `MAX()` function retrieves the highest value in a column, while `MIN()` retrieves the lowest.
   ```sql
   SELECT MAX(column_name), MIN(column_name) FROM table_name;
   ```
   For example:
   ```sql
   SELECT MAX(age), MIN(age) FROM users;
   ```
   This finds the highest and lowest ages in the `users` table.

7. **Using GROUP BY with Aggregate Functions**:
   You can combine aggregate functions with `GROUP BY` to perform calculations for specific groups of data.
   ```sql
   SELECT column1, aggregate_function(column2)
   FROM table_name
   GROUP BY column1;
   ```
   For example:
   ```sql
   SELECT category, AVG(price) FROM products GROUP BY category;
   ```
   This calculates the average price for each product category.

Remember to replace placeholders with actual values and adapt the queries to your specific use case. Aggregate functions are powerful tools for summarizing and analyzing data in PostgreSQL.
