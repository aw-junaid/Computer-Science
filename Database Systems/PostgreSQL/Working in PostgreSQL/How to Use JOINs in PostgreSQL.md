### Using JOINs in PostgreSQL

Joins in PostgreSQL allow you to combine rows from two or more tables based on related columns between them. Here's how to use them:

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

3. **INNER JOIN**:
   This type of join returns records that have matching values in both tables.
   ```sql
   SELECT columns
   FROM table1
   INNER JOIN table2 ON table1.column_name = table2.column_name;
   ```
   For example:
   ```sql
   SELECT orders.order_id, customers.customer_name
   FROM orders
   INNER JOIN customers ON orders.customer_id = customers.customer_id;
   ```
   This retrieves order IDs and customer names for orders that have corresponding customers.

4. **LEFT JOIN (or LEFT OUTER JOIN)**:
   This join returns all records from the left table and the matched records from the right table. If there's no match, NULL values are returned for columns from the right table.
   ```sql
   SELECT columns
   FROM table1
   LEFT JOIN table2 ON table1.column_name = table2.column_name;
   ```
   For example:
   ```sql
   SELECT customers.customer_name, orders.order_id
   FROM customers
   LEFT JOIN orders ON customers.customer_id = orders.customer_id;
   ```
   This retrieves customer names and their associated order IDs, including customers with no orders.

5. **RIGHT JOIN (or RIGHT OUTER JOIN)**:
   This join returns all records from the right table and the matched records from the left table. If there's no match, NULL values are returned for columns from the left table.
   ```sql
   SELECT columns
   FROM table1
   RIGHT JOIN table2 ON table1.column_name = table2.column_name;
   ```
   **Note:** PostgreSQL doesn't directly support RIGHT JOIN. You can achieve the same result by reversing the order of the tables in a LEFT JOIN.

6. **FULL JOIN (or FULL OUTER JOIN)**:
   This join returns all records when there is a match in one of the tables. It combines the results of both left and right outer joins.
   ```sql
   SELECT columns
   FROM table1
   FULL JOIN table2 ON table1.column_name = table2.column_name;
   ```
   **Note:** PostgreSQL doesn't directly support FULL JOIN. You can achieve the same result by using a combination of LEFT JOIN and RIGHT JOIN.

Remember to replace placeholders with actual values and adapt the queries to your specific use case.
