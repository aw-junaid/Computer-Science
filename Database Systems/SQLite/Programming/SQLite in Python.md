### SQLite in Python

SQLite is an embedded relational database that works well with Python applications. Python’s `sqlite3` module provides an interface to SQLite, enabling you to interact with SQLite databases directly within Python scripts.

---

### 1. **Installation**

If you're using Python 2.5 or newer, the `sqlite3` module comes pre-installed as part of the standard library. If for some reason it's not available, you can install it manually using `pip` (though this is rare for most recent Python versions).

```bash
pip install sqlite3
```

---

### 2. **Python sqlite3 Module APIs**

The `sqlite3` module in Python provides a DB-API 2.0 interface for SQLite. The basic methods to interact with SQLite databases are:

- `sqlite3.connect()`: Connect to the SQLite database.
- `connection.cursor()`: Create a cursor object for executing SQL queries.
- `cursor.execute()`: Execute an SQL statement.
- `connection.commit()`: Save (commit) the changes to the database.
- `connection.close()`: Close the connection to the database.

---

### 3. **Connect to a Database**

You can connect to an SQLite database using `sqlite3.connect()`. If the database doesn't exist, it will be created automatically.

```python
import sqlite3

# Connect to SQLite database (or create it if it doesn't exist)
connection = sqlite3.connect("test.db")

# Create a cursor object using the connection
cursor = connection.cursor()

# Close the connection
connection.close()
```

- `sqlite3.connect("test.db")`: Opens a connection to `test.db`. If the file doesn't exist, SQLite will create it.

---

### 4. **Create a Table**

To create a table, you can use the `cursor.execute()` method with a `CREATE TABLE` statement.

```python
import sqlite3

# Connect to the database
connection = sqlite3.connect("test.db")
cursor = connection.cursor()

# Create a table
cursor.execute("""
    CREATE TABLE IF NOT EXISTS users (
        id INTEGER PRIMARY KEY,
        name TEXT NOT NULL,
        age INTEGER
    );
""")

# Commit changes and close connection
connection.commit()
connection.close()
```

- `cursor.execute()` runs the SQL statement to create a table called `users`.

---

### 5. **INSERT Operation**

Inserting data into a table can be done using `cursor.execute()` or by using a prepared statement with `cursor.executemany()` for multiple inserts.

#### **Single Insert**

```python
import sqlite3

# Connect to the database
connection = sqlite3.connect("test.db")
cursor = connection.cursor()

# Insert a single record
cursor.execute("INSERT INTO users (name, age) VALUES ('John Doe', 30)")

# Commit changes and close connection
connection.commit()
connection.close()
```

#### **Multiple Inserts Using a Tuple**

```python
import sqlite3

# Connect to the database
connection = sqlite3.connect("test.db")
cursor = connection.cursor()

# Insert multiple records using executemany
users = [
    ('Alice', 25),
    ('Bob', 27),
    ('Charlie', 22)
]

cursor.executemany("INSERT INTO users (name, age) VALUES (?, ?)", users)

# Commit changes and close connection
connection.commit()
connection.close()
```

- `cursor.executemany()` is used to insert multiple records efficiently.

---

### 6. **SELECT Operation**

To select data from a table, use `cursor.execute()` with a `SELECT` query. Then, you can fetch the results using `fetchone()`, `fetchall()`, or `fetchmany()`.

```python
import sqlite3

# Connect to the database
connection = sqlite3.connect("test.db")
cursor = connection.cursor()

# Select all users
cursor.execute("SELECT * FROM users")

# Fetch all results
rows = cursor.fetchall()

for row in rows:
    print(row)  # Prints each row of the result

# Close connection
connection.close()
```

- `cursor.fetchall()` retrieves all rows from the query result.
- `cursor.fetchone()` retrieves one row at a time.

---

### 7. **UPDATE Operation**

To update records, you can use the `UPDATE` SQL statement with `cursor.execute()`.

```python
import sqlite3

# Connect to the database
connection = sqlite3.connect("test.db")
cursor = connection.cursor()

# Update a user's age
cursor.execute("UPDATE users SET age = ? WHERE name = ?", (35, 'John Doe'))

# Commit changes and close connection
connection.commit()
connection.close()
```

- The question marks (`?`) are placeholders for values that are passed in as a tuple in the second argument of `execute()`. This helps prevent SQL injection attacks.

---

### 8. **DELETE Operation**

To delete records, use the `DELETE` SQL statement.

```python
import sqlite3

# Connect to the database
connection = sqlite3.connect("test.db")
cursor = connection.cursor()

# Delete a user by name
cursor.execute("DELETE FROM users WHERE name = ?", ('Alice',))

# Commit changes and close connection
connection.commit()
connection.close()
```

- Like `UPDATE`, `DELETE` statements use placeholders to safely pass in data.

---

### Full Example: Basic SQLite Operations

```python
import sqlite3

# Connect to the database (creates a new file if not existing)
connection = sqlite3.connect("test.db")
cursor = connection.cursor()

# Create table
cursor.execute("""
    CREATE TABLE IF NOT EXISTS users (
        id INTEGER PRIMARY KEY,
        name TEXT NOT NULL,
        age INTEGER
    );
""")

# Insert some data
cursor.execute("INSERT INTO users (name, age) VALUES ('John Doe', 30)")
cursor.executemany("INSERT INTO users (name, age) VALUES (?, ?)", [
    ('Alice', 25),
    ('Bob', 27),
    ('Charlie', 22)
])

# Update a record
cursor.execute("UPDATE users SET age = ? WHERE name = ?", (35, 'John Doe'))

# Fetch all records
cursor.execute("SELECT * FROM users")
rows = cursor.fetchall()
for row in rows:
    print(row)

# Delete a record
cursor.execute("DELETE FROM users WHERE name = ?", ('Alice',))

# Commit changes and close connection
connection.commit()
connection.close()
```

---

### Summary of Common Operations

- **Connect to Database**: `sqlite3.connect("database.db")`
- **Create Table**: `cursor.execute("CREATE TABLE ...")`
- **Insert Data**: `cursor.execute("INSERT INTO ...")` or `cursor.executemany()`
- **Select Data**: `cursor.execute("SELECT * FROM ...")` and `cursor.fetchall()`
- **Update Data**: `cursor.execute("UPDATE ...")`
- **Delete Data**: `cursor.execute("DELETE FROM ...")`

These steps outline how to perform essential database operations using SQLite in Python. The `sqlite3` module is simple to use and provides robust features for interacting with SQLite databases.
