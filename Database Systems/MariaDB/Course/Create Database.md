### MariaDB - Create Database

Creating a database in MariaDB is a straightforward process. You can do this using SQL commands from within the **MariaDB Command-Line Interface (CLI)**, through a **PHP script**, or with a graphical tool like **phpMyAdmin**. Here, we'll focus on creating a database using the MariaDB CLI and PHP.

---

### 1. **Create Database Using MariaDB Command-Line Interface (CLI)**

#### 1.1. **Log in to MariaDB**

First, log in to MariaDB using the root user or another user with sufficient privileges:

```bash
mysql -u root -p
```

You’ll be prompted for the root password.

#### 1.2. **Create the Database**

Once logged in, use the `CREATE DATABASE` command to create a new database:

```sql
CREATE DATABASE database_name;
```

Replace `database_name` with your desired database name. For example, to create a database named `test_db`, the command would be:

```sql
CREATE DATABASE test_db;
```

#### 1.3. **Check if the Database was Created**

You can verify that the database has been created by listing all databases:

```sql
SHOW DATABASES;
```

You should see `test_db` listed among the databases.

#### 1.4. **Use the Newly Created Database**

To start using the newly created database, use the `USE` command:

```sql
USE test_db;
```

Now, any subsequent operations (like creating tables or inserting data) will be done in this database.

---

### 2. **Create Database Using PHP (MySQLi or PDO)**

You can also create a database using PHP. Below are examples for both **MySQLi** and **PDO**.

#### 2.1. **Create Database Using MySQLi**

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

// Create database
$sql = "CREATE DATABASE test_db";
if ($conn->query($sql) === TRUE) {
    echo "Database created successfully";
} else {
    echo "Error creating database: " . $conn->error;
}

// Close connection
$conn->close();
?>
```

#### 2.2. **Create Database Using PDO**

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
    
    // SQL to create database
    $sql = "CREATE DATABASE test_db";
    $conn->exec($sql);
    echo "Database created successfully"; 
}
catch(PDOException $e) {
    echo "Error creating database: " . $e->getMessage();
}

// Close the connection
$conn = null;
?>
```

---

### 3. **Create Database with Additional Options**

You can also specify additional options when creating a database, such as the character set or collation.

#### 3.1. **Create Database with Character Set and Collation**

```sql
CREATE DATABASE database_name
CHARACTER SET utf8mb4
COLLATE utf8mb4_unicode_ci;
```

This command will create a database using the `utf8mb4` character set and `utf8mb4_unicode_ci` collation, which supports a wider range of characters and is generally recommended for modern applications.

#### Example:

```sql
CREATE DATABASE test_db
CHARACTER SET utf8mb4
COLLATE utf8mb4_unicode_ci;
```

---

### 4. **Permissions and User Grants**

Once the database is created, you may want to grant permissions to a user to interact with the database.

#### 4.1. **Create a New User and Grant Permissions**

```sql
CREATE USER 'username'@'localhost' IDENTIFIED BY 'password';
GRANT ALL PRIVILEGES ON test_db.* TO 'username'@'localhost';
FLUSH PRIVILEGES;
```

- Replace `'username'` and `'password'` with the username and password for the new user.
- `test_db.*` gives the user full access to the `test_db` database.
- `FLUSH PRIVILEGES;` is used to apply the changes.

---

### 5. **Drop a Database**

If you want to delete a database, use the `DROP DATABASE` command. Be careful, as this will permanently remove the database and all its data.

```sql
DROP DATABASE test_db;
```

---

### Conclusion

Creating a database in MariaDB is simple and can be done in several ways, either through the **MariaDB Command-Line Interface**, **PHP scripts** (using MySQLi or PDO), or graphical tools like **phpMyAdmin**. The most common steps involve:

1. **Connecting to MariaDB**.
2. **Using the `CREATE DATABASE` command** to create a new database.
3. Optionally setting the **character set and collation** for your database.
4. Granting appropriate **permissions to users** for database access.

By using these methods, you can efficiently manage your databases in MariaDB.
