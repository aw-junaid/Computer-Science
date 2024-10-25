### Deleting Data in PostgreSQL

Deleting data in PostgreSQL is done using the `DELETE` statement. Here's how you can do it:

1. **Connect to Your Database**:
   ```bash
   psql -U your_username -d your_database_name -h your_host -p your_port
   ```
   Replace `your_username`, `your_database_name`, `your_host`, and `your_port` with your actual database credentials.

2. **Switch to the Database**:
   ```sql
   \c your_database_name
   ```
   This command switches your current connection to the specified database.

3. **Delete Data**:
   ```sql
   DELETE FROM your_table_name
   WHERE condition;
   ```
   Replace `your_table_name` with the name of the table from which you want to delete data. Use a `WHERE` clause to specify the conditions for deletion.

   For example:
   ```sql
   DELETE FROM users
   WHERE id = 1;
   ```
   This deletes the row where the `id` is 1 from the `users` table.

Remember, the `WHERE` clause is important to avoid accidentally deleting all rows in a table. Always make sure the condition is specific enough to target only the records you intend to delete.
