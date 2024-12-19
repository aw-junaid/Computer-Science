### MariaDB - PHP Syntax

To interact with a MariaDB database using PHP, you can use several methods. The most common way is using **MySQLi (MySQL Improved)** or **PDO (PHP Data Objects)**. Below, we’ll cover the syntax for using both.

### 1. **Using MySQLi in PHP**

**MySQLi** is a PHP extension that allows you to interact with MySQL and MariaDB databases. It can be used in two ways: **procedural** and **object-oriented**.

#### 1.1. **Connecting to MariaDB using MySQLi**

##### **Procedural Style**
```php
<?php
$servername = "localhost";
$username = "root";
$password = "your_password";
$dbname = "your_database";

// Create connection
$conn = mysqli_connect($servername, $username, $password, $dbname);

// Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}
echo "Connected successfully";
?>
```

##### **Object-Oriented Style**
```php
<?php
$servername = "localhost";
$username = "root";
$password = "your_password";
$dbname = "your_database";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
echo "Connected successfully";
?>
```

#### 1.2. **Performing Queries**

##### **Select Query**
```php
<?php
$query = "SELECT id, name FROM users";
$result = mysqli_query($conn, $query);

if (mysqli_num_rows($result) > 0) {
    while($row = mysqli_fetch_assoc($result)) {
        echo "id: " . $row["id"]. " - Name: " . $row["name"]. "<br>";
    }
} else {
    echo "0 results";
}
?>
```

##### **Insert Query**
```php
<?php
$name = "John";
$age = 30;
$query = "INSERT INTO users (name, age) VALUES ('$name', $age)";

if (mysqli_query($conn, $query)) {
    echo "New record created successfully";
} else {
    echo "Error: " . $query . "<br>" . mysqli_error($conn);
}
?>
```

##### **Update Query**
```php
<?php
$id = 1;
$new_name = "John Doe";
$query = "UPDATE users SET name = '$new_name' WHERE id = $id";

if (mysqli_query($conn, $query)) {
    echo "Record updated successfully";
} else {
    echo "Error: " . $query . "<br>" . mysqli_error($conn);
}
?>
```

##### **Delete Query**
```php
<?php
$id = 1;
$query = "DELETE FROM users WHERE id = $id";

if (mysqli_query($conn, $query)) {
    echo "Record deleted successfully";
} else {
    echo "Error: " . $query . "<br>" . mysqli_error($conn);
}
?>
```

#### 1.3. **Closing the Connection**
```php
<?php
mysqli_close($conn);
?>
```

---

### 2. **Using PDO in PHP**

**PDO** (PHP Data Objects) provides a consistent interface for interacting with various databases, including MariaDB. PDO is more flexible than MySQLi because it supports multiple database systems.

#### 2.1. **Connecting to MariaDB using PDO**

```php
<?php
$servername = "localhost";
$username = "root";
$password = "your_password";
$dbname = "your_database";

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

#### 2.2. **Performing Queries with PDO**

##### **Select Query**
```php
<?php
$query = "SELECT id, name FROM users";
$stmt = $conn->prepare($query);
$stmt->execute();

// Set the resulting array to associative
$result = $stmt->fetchAll(PDO::FETCH_ASSOC);

foreach ($result as $row) {
    echo "id: " . $row["id"] . " - Name: " . $row["name"] . "<br>";
}
?>
```

##### **Insert Query**
```php
<?php
$name = "Jane";
$age = 25;
$query = "INSERT INTO users (name, age) VALUES (:name, :age)";
$stmt = $conn->prepare($query);
$stmt->bindParam(':name', $name);
$stmt->bindParam(':age', $age);

if ($stmt->execute()) {
    echo "New record created successfully";
} else {
    echo "Error: " . $stmt->errorInfo();
}
?>
```

##### **Update Query**
```php
<?php
$id = 1;
$new_name = "Jane Doe";
$query = "UPDATE users SET name = :name WHERE id = :id";
$stmt = $conn->prepare($query);
$stmt->bindParam(':name', $new_name);
$stmt->bindParam(':id', $id);

if ($stmt->execute()) {
    echo "Record updated successfully";
} else {
    echo "Error: " . $stmt->errorInfo();
}
?>
```

##### **Delete Query**
```php
<?php
$id = 1;
$query = "DELETE FROM users WHERE id = :id";
$stmt = $conn->prepare($query);
$stmt->bindParam(':id', $id);

if ($stmt->execute()) {
    echo "Record deleted successfully";
} else {
    echo "Error: " . $stmt->errorInfo();
}
?>
```

#### 2.3. **Closing the Connection**
In PDO, the connection is closed automatically when the object is destroyed, but you can explicitly set the connection to `null` to close it early:
```php
<?php
$conn = null;
?>
```

---

### 3. **Prepared Statements (Security Best Practices)**

Using **prepared statements** with placeholders for user input is a best practice for preventing **SQL injection** attacks.

#### Example of a Prepared Statement in MySQLi
```php
<?php
$query = "SELECT id, name FROM users WHERE age > ?";
$stmt = mysqli_prepare($conn, $query);
$age = 20;
mysqli_stmt_bind_param($stmt, "i", $age);
mysqli_stmt_execute($stmt);
$result = mysqli_stmt_get_result($stmt);
while ($row = mysqli_fetch_assoc($result)) {
    echo "id: " . $row["id"] . " - Name: " . $row["name"] . "<br>";
}
?>
```

#### Example of a Prepared Statement in PDO
```php
<?php
$query = "SELECT id, name FROM users WHERE age > :age";
$stmt = $conn->prepare($query);
$stmt->bindParam(':age', $age, PDO::PARAM_INT);
$age = 20;
$stmt->execute();
$result = $stmt->fetchAll(PDO::FETCH_ASSOC);
foreach ($result as $row) {
    echo "id: " . $row["id"] . " - Name: " . $row["name"] . "<br>";
}
?>
```

---

### Conclusion

The basic PHP syntax for interacting with a MariaDB database can be done using **MySQLi** or **PDO**. Both methods allow you to connect to the database, perform queries, handle user input securely through prepared statements, and close the connection.

- **MySQLi** is specific to MySQL/MariaDB databases and can be used in procedural or object-oriented style.
- **PDO** is a more flexible database interface, supporting multiple database systems and providing more powerful features, such as prepared statements, which help prevent SQL injection.

Choosing between MySQLi and PDO largely depends on your preferences and the specific needs of your application.
