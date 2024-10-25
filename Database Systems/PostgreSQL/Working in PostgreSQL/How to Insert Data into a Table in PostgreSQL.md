### Inserting Data into a Table in PostgreSQL

To add data into a PostgreSQL table, you can use the `INSERT INTO` statement. Here's a step-by-step guide:

1. **Connect to Your Database**:
   ```
   psql -U your_username -d your_database_name -h your_host -p your_port
   ```
   Replace `your_username`, `your_database_name`, `your_host`, and `your_port` with actual database credentials.

2. **Switch to the Database**:
   ```
   \c your_database_name
   ```
   This command switches your current connection to the specified database.

3. **Insert Data**:
   ```sql
   INSERT INTO your_table_name (column1, column2, ...)
   VALUES (value1, value2, ...);
   ```
   Replace `your_table_name` with the table's name, and fill in the values for the respective columns.

For instance:
```sql
INSERT INTO users (username, email)
VALUES ('john_doe', 'john@example.com');
```

Remember to adjust column names and values according to your specific table structure.
