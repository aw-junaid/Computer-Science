### Restoring a PostgreSQL Database from a Backup

Restoring a PostgreSQL database from a backup is crucial for recovering data in case of accidental deletion or database corruption. Here's how you can do it:

#### Using `pg_restore`:

1. **Connect to Your Server**:

   Log in to your server or the machine where PostgreSQL is installed.

2. **Open a Terminal or Command Prompt**:

   Open a terminal or command prompt window.

3. **Restore Command**:

   Use the `pg_restore` command to restore your database from the backup file. Replace `your_database_name` with the actual name of your database and `backup_filename.dump` with the name of your backup file.

   ```bash
   pg_restore -U your_username -d your_database_name backup_filename.dump
   ```

   - `-U`: Specify the PostgreSQL username.
   - `-d`: Specify the name of the database you want to restore to.

   Example:

   ```bash
   pg_restore -U myuser -d mydatabase mybackup.dump
   ```

4. **Password Prompt**:

   You'll be prompted for the password of the PostgreSQL user.

5. **Monitor Progress**:

   Depending on the size of your database and the backup file, the restoration process may take some time. You'll see progress updates in the terminal.

#### Using `psql`:

If you used `pg_dumpall` to back up all databases:

1. **Connect to Your Server**:

   Log in to your server or the machine where PostgreSQL is installed.

2. **Open a Terminal or Command Prompt**:

   Open a terminal or command prompt window.

3. **Restore Command**:

   Use the `psql` command to restore all databases from the backup file. Replace `all_databases_dump.sql` with the name of your backup file.

   ```bash
   psql -U your_username -f all_databases_dump.sql
   ```

   - `-U`: Specify the PostgreSQL username.
   - `-f`: Specify the input file (backup file).

   Example:

   ```bash
   psql -U myuser -f alldatabases.sql
   ```

4. **Password Prompt**:

   You'll be prompted for the password of the PostgreSQL user.

5. **Monitor Progress**:

   The restoration process may take some time. You'll see progress updates in the terminal.

Remember to replace placeholders like `your_username`, `your_database_name`, and `backup_filename.dump` with actual values. Additionally, make sure to have backups in a safe location before performing a restoration.
