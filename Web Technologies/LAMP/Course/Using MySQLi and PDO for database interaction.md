### **Using MySQLi and PDO for Database Interaction in PHP**

When interacting with a MySQL database in PHP, you can use either **MySQLi (MySQL Improved)** or **PDO (PHP Data Objects)**. Both libraries allow you to connect to a MySQL database, perform queries, and manage results. However, each has its strengths, and your choice will depend on the specific requirements of your project.

#### **1. MySQLi (MySQL Improved)**

MySQLi is a PHP extension that allows you to interact with MySQL databases. It provides a richer set of features than the original MySQL extension, including support for **prepared statements**, **multiple statements**, and **transaction support**. MySQLi can be used in two modes:

- **Procedural** (function-based)
- **Object-Oriented** (object-based)

##### **1.1 Example: MySQLi (Object-Oriented)**

```php
<?php
// Create a connection to the database
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "my_database";

$conn = new mysqli($servername, $username, $password, $dbname);

// Check the connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Prepare a SQL statement
$sql = "SELECT * FROM users WHERE email = ?";
$stmt = $conn->prepare($sql);

// Bind parameters
$email = "example@example.com";
$stmt->bind_param("s", $email);  // "s" denotes the type of parameter (string)

// Execute the statement
$stmt->execute();

// Get the result
$result = $stmt->get_result();

// Fetch and display the rows
while ($row = $result->fetch_assoc()) {
    echo "User: " . $row['name'] . "<br>";
}

// Close the statement and connection
$stmt->close();
$conn->close();
?>
```

- **Prepared Statements**: `prepare()` is used to prepare the SQL query. `bind_param()` binds parameters to the placeholders (`?`) in the SQL query.
- **`get_result()`**: Fetches the result of the query.
- **Object-Oriented Syntax**: You can use methods like `prepare()`, `bind_param()`, `execute()`, and `get_result()` to interact with the database.

##### **1.2 Example: MySQLi (Procedural)**

```php
<?php
// Create a connection to the database
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "my_database";

$conn = mysqli_connect($servername, $username, $password, $dbname);

// Check the connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

// Prepare a SQL statement
$sql = "SELECT * FROM users WHERE email = ?";
$stmt = mysqli_prepare($conn, $sql);

// Bind parameters
$email = "example@example.com";
mysqli_stmt_bind_param($stmt, "s", $email);  // "s" denotes the type of parameter (string)

// Execute the statement
mysqli_stmt_execute($stmt);

// Get the result
$result = mysqli_stmt_get_result($stmt);

// Fetch and display the rows
while ($row = mysqli_fetch_assoc($result)) {
    echo "User: " . $row['name'] . "<br>";
}

// Close the statement and connection
mysqli_stmt_close($stmt);
mysqli_close($conn);
?>
```

- **Procedural Syntax**: Uses `mysqli_connect()`, `mysqli_prepare()`, `mysqli_stmt_bind_param()`, and other procedural functions.

---

#### **2. PDO (PHP Data Objects)**

PDO is a more flexible and object-oriented approach to interacting with databases. It allows you to work with different database types (not just MySQL) and provides a consistent API for database interactions. PDO supports **prepared statements**, **transactions**, and **fetching results in various formats** (such as associative arrays and objects).

##### **2.1 Example: PDO for MySQL**

```php
<?php
// Set up the PDO connection
$dsn = "mysql:host=localhost;dbname=my_database";
$username = "root";
$password = "";

try {
    // Create a PDO instance
    $pdo = new PDO($dsn, $username, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Prepare a SQL statement
    $stmt = $pdo->prepare("SELECT * FROM users WHERE email = :email");

    // Bind parameters
    $email = "example@example.com";
    $stmt->bindParam(':email', $email, PDO::PARAM_STR);

    // Execute the statement
    $stmt->execute();

    // Fetch and display the rows
    while ($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
        echo "User: " . $row['name'] . "<br>";
    }

} catch (PDOException $e) {
    echo "Connection failed: " . $e->getMessage();
}

$pdo = null;  // Close the PDO connection
?>
```

- **`prepare()`**: Prepares an SQL query with named placeholders (`:email`).
- **`bindParam()`**: Binds user input (`$email`) to the prepared statement.
- **`execute()`**: Executes the prepared statement.
- **Fetching results**: You can fetch results using `fetch(PDO::FETCH_ASSOC)` to return data as an associative array.

##### **2.2 Example: PDO (Insert Statement)**

```php
<?php
// Set up the PDO connection
$dsn = "mysql:host=localhost;dbname=my_database";
$username = "root";
$password = "";

try {
    // Create a PDO instance
    $pdo = new PDO($dsn, $username, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Prepare an INSERT statement
    $stmt = $pdo->prepare("INSERT INTO users (name, email) VALUES (:name, :email)");

    // Bind parameters
    $stmt->bindParam(':name', $name);
    $stmt->bindParam(':email', $email);

    // Set values and execute the statement
    $name = "John Doe";
    $email = "john@example.com";
    $stmt->execute();

    echo "New record inserted successfully";

} catch (PDOException $e) {
    echo "Error: " . $e->getMessage();
}

$pdo = null;  // Close the PDO connection
?>
```

---

### **Comparison of MySQLi and PDO**

| Feature                         | MySQLi                                   | PDO                                      |
|----------------------------------|------------------------------------------|------------------------------------------|
| **Database support**             | MySQL only                               | Supports multiple databases (MySQL, PostgreSQL, SQLite, etc.) |
| **API**                          | Procedural and Object-Oriented           | Object-Oriented only                    |
| **Prepared Statements**          | Supported                                | Supported                                |
| **Named Placeholders**           | No                                       | Yes                                      |
| **Error Handling**               | Uses error codes or exceptions (with `mysqli_report()`) | Uses exceptions by default (`PDO::ERRMODE_EXCEPTION`) |
| **Multiple Queries**             | Supports multiple queries in one statement | No direct support for multiple queries  |
| **Fetching Results**             | `fetch_assoc()`, `fetch_row()`, etc.     | `fetch()`, `fetchAll()`, etc.            |

### **Which One to Use?**

- **MySQLi**: If your application will only work with MySQL and you prefer working with a procedural style or object-oriented approach.
- **PDO**: If you need support for multiple databases or prefer an object-oriented approach. PDO is also a good choice if you anticipate needing to switch database types in the future.

### **Security Considerations**

Both MySQLi and PDO support **prepared statements**, which are crucial for preventing **SQL injection** attacks. Always use prepared statements with bound parameters and avoid including raw user input directly into queries. 

By following these practices, you ensure that your database interactions are secure, efficient, and maintainable.
