### MariaDB Connection in PHP

To connect a MariaDB database to a PHP application, you can use either **MySQLi** (MySQL Improved) or **PDO** (PHP Data Objects). Both methods allow you to interact with the database, but they differ in features and flexibility.

Here's an overview of both methods for establishing a connection to a MariaDB database.

---

### 1. **MariaDB Connection using MySQLi**

**MySQLi** is a PHP extension that allows you to interact with MariaDB and MySQL databases. You can use **procedural** or **object-oriented** styles to connect to the database.

#### 1.1. **Procedural Style**

```php
<?php
$servername = "localhost";   // Database host
$username = "root";          // Database username
$password = "your_password"; // Database password
$dbname = "your_database";   // Database name

// Create connection
$conn = mysqli_connect($servername, $username, $password, $dbname);

// Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}
echo "Connected successfully";
?>
```

#### 1.2. **Object-Oriented Style**

```php
<?php
$servername = "localhost";   // Database host
$username = "root";          // Database username
$password = "your_password"; // Database password
$dbname = "your_database";   // Database name

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
echo "Connected successfully";
?>
```

---

### 2. **MariaDB Connection using PDO**

**PDO (PHP Data Objects)** is a more flexible database interface that supports multiple database systems, including MariaDB. It's a good choice if you want to make your application database-agnostic.

#### 2.1. **Basic PDO Connection**

```php
<?php
$servername = "localhost";   // Database host
$username = "root";          // Database username
$password = "your_password"; // Database password
$dbname = "your_database";   // Database name

try {
    // Create a new PDO connection
    $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);

    // Set the PDO error mode to exception
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    echo "Connected successfully"; 
}
catch(PDOException $e) {
    // Catch connection errors and display the error message
    echo "Connection failed: " . $e->getMessage();
}
?>
```

---

### 3. **Error Handling and Debugging**

Both **MySQLi** and **PDO** provide ways to handle errors gracefully.

#### 3.1. **Error Handling in MySQLi**

By default, MySQLi shows an error message when a connection fails. However, you can handle errors more explicitly:

```php
<?php
$conn = mysqli_connect($servername, $username, $password, $dbname);

if (mysqli_connect_errno()) {
    echo "Failed to connect to MariaDB: " . mysqli_connect_error();
    exit();
}
?>
```

#### 3.2. **Error Handling in PDO**

In PDO, you can set the error mode to exceptions. This will throw an exception if there is an error during the connection or query execution:

```php
<?php
try {
    $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
    echo "Connection failed: " . $e->getMessage();
}
?>
```

---

### 4. **Closing the Connection**

#### 4.1. **Closing Connection in MySQLi**

In MySQLi, you explicitly close the connection using `mysqli_close()`:

```php
<?php
// Close the connection
mysqli_close($conn);
?>
```

#### 4.2. **Closing Connection in PDO**

In PDO, the connection is automatically closed when the script finishes executing, but you can also set the connection object to `null` to close it explicitly:

```php
<?php
// Close the connection
$conn = null;
?>
```

---

### 5. **Common Errors and Solutions**

#### 5.1. **Connection Refused**
If you receive a "Connection refused" error, it could be due to one of the following reasons:
- The MariaDB server is not running.
- Incorrect hostname or IP address.
- Firewall issues.
- Incorrect credentials (username or password).

**Solution:**
- Ensure the MariaDB server is running: `sudo systemctl status mariadb` or `sudo service mariadb status`.
- Verify the credentials and try connecting to MariaDB from the command line using the same credentials.

#### 5.2. **Access Denied for User**
If you get an error like "Access denied for user 'username'@'hostname'", it means that the user does not have permission to access the database from the specified host.

**Solution:**
- Ensure that the user has the correct privileges. You can grant the required permissions:
  ```sql
  GRANT ALL PRIVILEGES ON database_name.* TO 'username'@'hostname' IDENTIFIED BY 'password';
  FLUSH PRIVILEGES;
  ```

#### 5.3. **Database Not Found**
If you get an error indicating that the database doesn't exist, ensure the database name is correct.

**Solution:**
- Check if the database exists by running:
  ```sql
  SHOW DATABASES;
  ```

---

### Conclusion

Connecting to a **MariaDB** database using PHP can be done easily using either the **MySQLi** or **PDO** extension. 

- **MySQLi** is easier for those who only plan to work with MariaDB or MySQL and can be used in both **procedural** or **object-oriented** style.
- **PDO** provides more flexibility, as it supports various database systems, and is often preferred when building more complex or database-agnostic applications.

Remember to always handle errors, especially for production environments, to ensure your application is secure and user-friendly.
