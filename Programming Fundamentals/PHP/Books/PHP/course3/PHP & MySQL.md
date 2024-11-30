### PHP & MySQL Integration

PHP and MySQL are often used together to build dynamic web applications, where PHP handles the server-side logic and MySQL stores and manages data. PHP can interact with MySQL databases to retrieve, insert, update, and delete data. The integration typically involves using **MySQLi** (MySQL Improved) or **PDO** (PHP Data Objects).

Here's a guide on how to use PHP with MySQL:

---

### 1. **Setting Up MySQL Database**

Before working with PHP and MySQL, you need to have a MySQL database set up. You can create a database and tables either via the **MySQL command line** or using a tool like **phpMyAdmin**.

#### Example: Create a Database and Table
```sql
-- Create a database
CREATE DATABASE my_database;

-- Select the database
USE my_database;

-- Create a table
CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(100) NOT NULL UNIQUE,
    password VARCHAR(255) NOT NULL
);
```

---

### 2. **Connecting PHP to MySQL**

You can connect to a MySQL database using two primary methods in PHP: **MySQLi** and **PDO**. We'll cover both.

#### a) **MySQLi Connection**

The **MySQLi** extension provides an interface to communicate with MySQL. It supports both **procedural** and **object-oriented** programming styles.

##### Example: Procedural Style

```php
<?php
$servername = "localhost";
$username = "root";  // Change this to your MySQL username
$password = "";      // Change this to your MySQL password
$dbname = "my_database";  // The name of the database you want to connect to

// Create connection
$conn = mysqli_connect($servername, $username, $password, $dbname);

// Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}
echo "Connected successfully";
?>
```

##### Example: Object-Oriented Style

```php
<?php
$servername = "localhost";
$username = "root";  // Change this to your MySQL username
$password = "";      // Change this to your MySQL password
$dbname = "my_database";  // The name of the database you want to connect to

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
echo "Connected successfully";
?>
```

#### b) **PDO (PHP Data Objects) Connection**

PDO provides a more flexible interface for connecting to various databases and supports prepared statements for enhanced security.

```php
<?php
$servername = "localhost";
$username = "root";  // Change this to your MySQL username
$password = "";      // Change this to your MySQL password
$dbname = "my_database";  // The name of the database you want to connect to

try {
    $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
    // Set the PDO error mode to exception
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    echo "Connected successfully"; 
}
catch(PDOException $e) {
    echo "Connection failed: " . $e->getMessage();
}
?>
```

---

### 3. **Inserting Data into MySQL**

To insert data into a MySQL table, you can use either **MySQLi** or **PDO**.

#### a) **Insert with MySQLi**

```php
<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "my_database";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sql = "INSERT INTO users (name, email, password) VALUES ('John Doe', 'john@example.com', 'password123')";

if ($conn->query($sql) === TRUE) {
    echo "New record created successfully";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
?>
```

#### b) **Insert with PDO**

```php
<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "my_database";

try {
    $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $sql = "INSERT INTO users (name, email, password) VALUES ('John Doe', 'john@example.com', 'password123')";
    $conn->exec($sql);

    echo "New record created successfully";
}
catch(PDOException $e) {
    echo "Error: " . $e->getMessage();
}

$conn = null;
?>
```

---

### 4. **Reading Data from MySQL**

You can fetch data from MySQL using `SELECT` queries.

#### a) **Select with MySQLi**

```php
<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "my_database";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sql = "SELECT id, name, email FROM users";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    while($row = $result->fetch_assoc()) {
        echo "id: " . $row["id"]. " - Name: " . $row["name"]. " - Email: " . $row["email"]. "<br>";
    }
} else {
    echo "0 results";
}

$conn->close();
?>
```

#### b) **Select with PDO**

```php
<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "my_database";

try {
    $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $stmt = $conn->prepare("SELECT id, name, email FROM users");
    $stmt->execute();

    // Set the fetch mode to associative array
    $stmt->setFetchMode(PDO::FETCH_ASSOC);

    while ($row = $stmt->fetch()) {
        echo "id: " . $row['id'] . " - Name: " . $row['name'] . " - Email: " . $row['email'] . "<br>";
    }
}
catch(PDOException $e) {
    echo "Error: " . $e->getMessage();
}

$conn = null;
?>
```

---

### 5. **Updating Data in MySQL**

To update data, use an `UPDATE` query.

#### a) **Update with MySQLi**

```php
<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "my_database";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sql = "UPDATE users SET email='newemail@example.com' WHERE id=1";

if ($conn->query($sql) === TRUE) {
    echo "Record updated successfully";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
?>
```

#### b) **Update with PDO**

```php
<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "my_database";

try {
    $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $sql = "UPDATE users SET email='newemail@example.com' WHERE id=1";
    $conn->exec($sql);

    echo "Record updated successfully";
}
catch(PDOException $e) {
    echo "Error: " . $e->getMessage();
}

$conn = null;
?>
```

---

### 6. **Deleting Data from MySQL**

To delete data, use a `DELETE` query.

#### a) **Delete with MySQLi**

```php
<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "my_database";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sql = "DELETE FROM users WHERE id=1";

if ($conn->query($sql) === TRUE) {
    echo "Record deleted successfully";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
?>
```

#### b) **Delete with PDO**

```php
<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "my_database";

try {
    $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $sql = "DELETE FROM users WHERE id=1";
    $conn->exec($sql);

    echo "Record deleted successfully";
}
catch

(PDOException $e) {
    echo "Error: " . $e->getMessage();
}

$conn = null;
?>
```

---

### 7. **Prepared Statements for Security (SQL Injection Protection)**

To prevent SQL injection attacks, always use prepared statements for executing queries, especially when accepting user inputs.

#### Example: Prepared Statement with PDO

```php
<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "my_database";

try {
    $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Prepare and bind
    $stmt = $conn->prepare("INSERT INTO users (name, email, password) VALUES (:name, :email, :password)");
    $stmt->bindParam(':name', $name);
    $stmt->bindParam(':email', $email);
    $stmt->bindParam(':password', $password);

    // Insert a row
    $name = "Jane Doe";
    $email = "jane@example.com";
    $password = "password123";
    $stmt->execute();

    echo "New record created successfully";
}
catch(PDOException $e) {
    echo "Error: " . $e->getMessage();
}

$conn = null;
?>
```

---

### Conclusion

Using PHP and MySQL together allows you to create dynamic web applications where you can store, retrieve, update, and delete data. The **MySQLi** and **PDO** extensions provide robust methods for interacting with MySQL databases. Always use prepared statements to protect your application from SQL injection attacks.
