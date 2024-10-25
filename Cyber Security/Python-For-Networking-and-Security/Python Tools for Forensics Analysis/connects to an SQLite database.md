This Python script connects to an SQLite database, retrieves the names of tables (excluding the `sqlite_sequence` table), and then performs a SELECT query on each table, printing the table name and the number of records in each table (excluding the 'Order' table). Here's an explanation of each part of the code:

```python
#!/usr/bin/env python3

import sqlite3

# Connect to the SQLite database
connection = sqlite3.connect('database.sqlite')
```

1. **Shebang Line:**
   - `#!/usr/bin/env python3`: This line is a shebang or hashbang line. It specifies the path to the Python interpreter that should be used to execute the script.

2. **Imports:**
   - `import sqlite3`: Imports the `sqlite3` module for working with SQLite databases.

3. **Database Connection:**
   - `connection = sqlite3.connect('database.sqlite')`: Establishes a connection to the SQLite database file named 'database.sqlite'. If the file doesn't exist, it will be created.

```python
def tables_in_sqlite_database(connection):
    cursor = connection.execute("SELECT name FROM sqlite_master WHERE type='table';")
    tables = [
        v[0] for v in cursor.fetchall()
        if v[0] != "sqlite_sequence"
    ]
    cursor.close()
    return tables
```

4. **Function Definition: `tables_in_sqlite_database`:**
   - Defines a function that takes a database connection as an argument.
   - Executes a query to fetch the names of all tables in the database (excluding the `sqlite_sequence` table).
   - Creates a list of table names (`tables`), and then closes the cursor.
   - Returns the list of table names.

```python
tables = tables_in_sqlite_database(connection)
tables.remove('Order')
```

5. **Fetching Table Names and Removing 'Order':**
   - Calls the `tables_in_sqlite_database` function to get a list of table names.
   - Removes the 'Order' table from the list.

```python
cursor = connection.cursor()

for table in tables:
    sql = "SELECT * FROM {}".format(table)
    cursor.execute(sql)
    records = cursor.fetchall()
    print(sql + " " + str(len(records)) + " elements")
```

6. **Iterating Over Tables and Fetching Records:**
   - Creates a cursor for executing SQL queries.
   - Iterates over the list of table names.
   - For each table, constructs a SELECT query (`sql`) and executes it using `cursor.execute`.
   - Fetches all records using `cursor.fetchall()`.
   - Prints the SQL query and the number of records in each table.

```python
connection.close()
```

7. **Closing the Connection:**
   - Closes the database connection to free up resources.

This script provides a simple example of querying table names and fetching records from an SQLite database using the `sqlite3` module in Python.
