### MariaDB - Select Database

In MariaDB, selecting a database allows you to set the context for all subsequent operations, such as querying tables or inserting data. After selecting a database, any SQL queries you run will apply to that database unless you specify otherwise.

You can select a database in several ways:

1. **Using the MariaDB Command-Line Interface (CLI)**.
2. **Using SQL within a PHP script (MySQLi or PDO)**.

---

### 1. **Select Database Using MariaDB Command-Line Interface (CLI)**

#### 1.1. **Log in to MariaDB**

First, log in to the MariaDB command-line interface using the following command:

```bash
mysql -u root -p
```

You will be prompted to enter your password.

#### 1.2. **Select the Database**

Once logged in, you can select a database with the `USE` command. This sets the current database to the one specified, so all subsequent SQL queries will affect that database.

For example, to select the `test_db` database, you would run:

```sql
USE test_db;
```

After executing this command, you can perform operations like querying tables, inserting records, and more within the `test_db` database.

#### 1.3. **Verify the Selected Database**

To verify which database you are currently using, you can run the following query:

```sql
SELECT DATABASE();
```

This will return the name of the current database.

---

### 2. **Select Database Using PHP**

You can also select a database when connecting to MariaDB from a PHP script. Both **MySQLi** and **PDO** allow you to select a database programmatically.

#### 2.1. **Select Database Using MySQLi**

```php
<?php
$servername = "localhost";   // Database host
$username = "root";          // Database username
$password = "your_password"; // Database password

// Create connection
$conn = new mysqli($servername, $username, $password);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Select the database
$conn->select_db("test_db");

// Check if the database is selected
if ($conn->query("SELECT DATABASE()")) {
    echo "Database selected successfully";
} else {
    echo "Error selecting database: " . $conn->error;
}

// Close connection
$conn->close();
?>
```

#### 2.2. **Select Database Using PDO**

```php
<?php
$servername = "localhost";   // Database host
$username = "root";          // Database username
$password = "your_password"; // Database password

try {
    // Create PDO connection
    $conn = new PDO("mysql:host=$servername", $username, $password);

    // Set the PDO error mode to exception
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Select the database
    $conn->exec("USE test_db");
    echo "Database selected successfully"; 
}
catch(PDOException $e) {
    echo "Error selecting database: " . $e->getMessage();
}

// Close the connection
$conn = null;
?>
```

In both examples, the database `test_db` is selected after the connection is established.

---

### 3. **Using `USE` in Queries**

When running a query, if you want to make sure you're interacting with the correct database, you can explicitly use the `USE` statement within your SQL script. This is helpful when you're working with multiple databases in the same session.

Example:

```sql
USE test_db;
SELECT * FROM users;
```

This ensures that the `users` table from the `test_db` database is queried.

---

### 4. **Switching Between Databases**

Once you're working with a database, you can easily switch to another database using the `USE` command again. For example, if you're currently using `test_db` and want to switch to `prod_db`, run:

```sql
USE prod_db;
```

This changes the context to `prod_db`, so all subsequent operations will apply to that database.

---

### 5. **Database Access Permissions**

Make sure that the user account you’re using has the necessary permissions to access the database. If you're unable to select a database, it may be due to insufficient privileges. You can grant the necessary privileges like this:

```sql
GRANT ALL PRIVILEGES ON test_db.* TO 'username'@'localhost';
FLUSH PRIVILEGES;
```

This command grants the user `'username'` full access to the `test_db` database.

---

### Conclusion

- **MariaDB CLI**: Use the `USE` statement to select a database.
- **PHP (MySQLi and PDO)**: Use `select_db()` in MySQLi or `exec("USE db_name")` in PDO to select a database programmatically.

Selecting the right database is essential for any operation you perform within MariaDB, whether you're querying data, inserting records, or altering tables. Always ensure the correct database is selected before performing operations to avoid working with the wrong set of data.
