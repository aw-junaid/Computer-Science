### Using GROUP BY in PostgreSQL

The `GROUP BY` clause is used to group rows that have the same values into summary rows, typically with an aggregate function like `COUNT`, `SUM`, etc. Here's how to use it:

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

3. **Basic GROUP BY**:
   ```sql
   SELECT column1, aggregate_function(column2)
   FROM your_table_name
   GROUP BY column1;
   ```
   Replace `your_table_name`, `column1`, and `column2` with the appropriate table and column names.

   For example:
   ```sql
   SELECT category, COUNT(*) 
   FROM products
   GROUP BY category;
   ```
   This groups products by category and counts the number of products in each category.

4. **Using Aggregate Functions**:
   You can use aggregate functions with `GROUP BY` to perform calculations on grouped data.
   ```sql
   SELECT column1, aggregate_function(column2)
   FROM your_table_name
   GROUP BY column1;
   ```
   For example:
   ```sql
   SELECT category, MAX(price) 
   FROM products
   GROUP BY category;
   ```
   This finds the maximum price in each category.

5. **Filtering Groups with HAVING**:
   Use `HAVING` to filter the results of a `GROUP BY` query.
   ```sql
   SELECT column1, aggregate_function(column2)
   FROM your_table_name
   GROUP BY column1
   HAVING condition;
   ```
   For example:
   ```sql
   SELECT category, AVG(price) 
   FROM products
   GROUP BY category
   HAVING AVG(price) > 50;
   ```
   This finds categories with an average price greater than 50.

Remember to replace placeholders with actual values and adapt the queries to your specific use case.
