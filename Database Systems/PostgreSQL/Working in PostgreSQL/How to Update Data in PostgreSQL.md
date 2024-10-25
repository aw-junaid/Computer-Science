### Updating Data in PostgreSQL

Updating data in PostgreSQL involves using the `UPDATE` statement. Here's how you do it:

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

3. **Update Data**:
   ```sql
   UPDATE your_table_name
   SET column1 = value1, column2 = value2, ...
   WHERE condition;
   ```
   Replace `your_table_name` with the table's name, and specify the columns and values you want to update. Use a `WHERE` clause to target specific rows.

   For example:
   ```sql
   UPDATE users
   SET email = 'new_email@example.com'
   WHERE id = 1;
   ```
   This updates the email of the user with `id` 1.

Remember, the `WHERE` clause is crucial to prevent accidentally updating all rows. Always ensure it's specific enough to target only the intended records.
