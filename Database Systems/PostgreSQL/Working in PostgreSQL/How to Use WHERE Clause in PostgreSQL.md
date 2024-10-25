### Using WHERE Clause in PostgreSQL

The `WHERE` clause is essential for filtering data in PostgreSQL. Here's how you can use it:

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

3. **Basic WHERE Clause**:
   ```sql
   SELECT * FROM your_table_name WHERE condition;
   ```
   Replace `your_table_name` with the name of the table you're querying, and `condition` with the specific condition you want to apply.

   For example:
   ```sql
   SELECT * FROM users WHERE age > 25;
   ```
   This retrieves all columns for users with an age greater than 25.

4. **Logical Operators**:
   Use logical operators (`AND`, `OR`, `NOT`) to combine conditions.
   ```sql
   SELECT * FROM your_table_name WHERE condition1 AND condition2;
   ```
   For example:
   ```sql
   SELECT * FROM users WHERE age > 25 AND city = 'New York';
   ```

5. **Comparison Operators**:
   Employ comparison operators (`=`, `<>`, `<`, `>`, `<=`, `>=`) for specific value comparisons.
   ```sql
   SELECT * FROM your_table_name WHERE column = value;
   ```
   For example:
   ```sql
   SELECT * FROM products WHERE price > 100;
   ```

6. **Pattern Matching with LIKE**:
   Use `LIKE` for pattern matching with wildcard characters (`%` for any number of characters, `_` for a single character).
   ```sql
   SELECT * FROM your_table_name WHERE column LIKE pattern;
   ```
   For example:
   ```sql
   SELECT * FROM users WHERE name LIKE 'J%';
   ```

7. **Negation with NOT**:
   Use `NOT` to negate a condition.
   ```sql
   SELECT * FROM your_table_name WHERE NOT condition;
   ```
   For example:
   ```sql
   SELECT * FROM users WHERE NOT age > 25;
   ```

Remember to adapt the queries to your specific use case and replace placeholders with actual values.
