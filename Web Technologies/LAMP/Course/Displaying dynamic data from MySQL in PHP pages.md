### **Displaying Dynamic Data from MySQL in PHP Pages**

Displaying dynamic data from a MySQL database in PHP pages is a common task when building dynamic web applications. PHP, along with MySQL, provides an efficient way to retrieve and display data from a database. Below is a detailed guide on how to fetch and display dynamic data in PHP using MySQLi or PDO.

---

### **1. Set Up the MySQL Database**

First, make sure you have a MySQL database with data that you want to display. For this example, let's assume we have a `users` table with the following structure:

```sql
CREATE TABLE users (
    id INT(11) AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100),
    email VARCHAR(100),
    age INT(3)
);
```

And the table contains some sample data:

```sql
INSERT INTO users (name, email, age) VALUES 
('John Doe', 'john@example.com', 25),
('Jane Smith', 'jane@example.com', 30),
('Mike Johnson', 'mike@example.com', 22);
```

---

### **2. Connect to the MySQL Database**

You need to establish a connection to your MySQL database in PHP. We will use **MySQLi** (object-oriented) and **PDO** methods for this example.

#### **2.1 Using MySQLi**

```php
<?php
// Database connection parameters
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "my_database";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
?>
```

#### **2.2 Using PDO**

```php
<?php
// Database connection parameters
$dsn = "mysql:host=localhost;dbname=my_database";
$username = "root";
$password = "";

try {
    // Create a PDO instance
    $pdo = new PDO($dsn, $username, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
    echo "Connection failed: " . $e->getMessage();
}
?>
```

---

### **3. Fetch Data from the Database**

Once you have successfully connected to the database, you can write queries to fetch data and display it on your page.

#### **3.1 Using MySQLi**

```php
<?php
// MySQL query to fetch all users
$sql = "SELECT * FROM users";
$result = $conn->query($sql);

// Check if there are results
if ($result->num_rows > 0) {
    // Output data of each row
    while ($row = $result->fetch_assoc()) {
        echo "ID: " . $row['id'] . "<br>";
        echo "Name: " . $row['name'] . "<br>";
        echo "Email: " . $row['email'] . "<br>";
        echo "Age: " . $row['age'] . "<br><br>";
    }
} else {
    echo "No records found";
}

// Close the connection
$conn->close();
?>
```

- **`$conn->query()`**: Executes the query and returns a result set.
- **`$result->fetch_assoc()`**: Fetches each row of the result as an associative array.
- **Loop through results**: The `while` loop processes each row and displays the data.

#### **3.2 Using PDO**

```php
<?php
// MySQL query to fetch all users
$sql = "SELECT * FROM users";
$stmt = $pdo->prepare($sql);
$stmt->execute();

// Fetch data
$users = $stmt->fetchAll(PDO::FETCH_ASSOC);

// Check if data exists and display it
if ($users) {
    foreach ($users as $user) {
        echo "ID: " . $user['id'] . "<br>";
        echo "Name: " . $user['name'] . "<br>";
        echo "Email: " . $user['email'] . "<br>";
        echo "Age: " . $user['age'] . "<br><br>";
    }
} else {
    echo "No records found";
}
?>
```

- **`$pdo->prepare()`**: Prepares the SQL query.
- **`$stmt->execute()`**: Executes the prepared statement.
- **`$stmt->fetchAll(PDO::FETCH_ASSOC)`**: Fetches all rows as an associative array.

---

### **4. Display Data in HTML Table Format**

You can organize the fetched data in a structured format like an HTML table for better readability.

#### **4.1 Using MySQLi with HTML Table**

```php
<?php
$sql = "SELECT * FROM users";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    echo "<table border='1'>
            <tr>
                <th>ID</th>
                <th>Name</th>
                <th>Email</th>
                <th>Age</th>
            </tr>";

    // Output data of each row
    while ($row = $result->fetch_assoc()) {
        echo "<tr>
                <td>" . $row['id'] . "</td>
                <td>" . $row['name'] . "</td>
                <td>" . $row['email'] . "</td>
                <td>" . $row['age'] . "</td>
              </tr>";
    }

    echo "</table>";
} else {
    echo "No records found";
}

$conn->close();
?>
```

#### **4.2 Using PDO with HTML Table**

```php
<?php
$sql = "SELECT * FROM users";
$stmt = $pdo->prepare($sql);
$stmt->execute();
$users = $stmt->fetchAll(PDO::FETCH_ASSOC);

if ($users) {
    echo "<table border='1'>
            <tr>
                <th>ID</th>
                <th>Name</th>
                <th>Email</th>
                <th>Age</th>
            </tr>";

    foreach ($users as $user) {
        echo "<tr>
                <td>" . $user['id'] . "</td>
                <td>" . $user['name'] . "</td>
                <td>" . $user['email'] . "</td>
                <td>" . $user['age'] . "</td>
              </tr>";
    }

    echo "</table>";
} else {
    echo "No records found";
}
?>
```

---

### **5. Handling Errors**

You should always handle errors gracefully, especially when dealing with database queries. In both MySQLi and PDO, you can handle errors by checking for connection issues and query failures.

#### **5.1 MySQLi Error Handling**

```php
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Perform query and check for errors
$sql = "SELECT * FROM users";
$result = $conn->query($sql);

if (!$result) {
    echo "Query failed: " . $conn->error;
    exit;
}
```

#### **5.2 PDO Error Handling**

```php
try {
    $pdo = new PDO($dsn, $username, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    
    // Perform query
    $sql = "SELECT * FROM users";
    $stmt = $pdo->prepare($sql);
    $stmt->execute();
    
} catch (PDOException $e) {
    echo "Error: " . $e->getMessage();
}
```

- **MySQLi**: Use `$conn->error` to display any errors from the MySQL server.
- **PDO**: Use `try-catch` blocks to catch exceptions and handle errors.

---

### **6. Closing the Database Connection**

After fetching and displaying data, it’s important to close the database connection.

- **MySQLi**: `$conn->close();`
- **PDO**: `unset($pdo);` (PDO automatically closes the connection when the object is destroyed).

---

### **Conclusion**

Displaying dynamic data from MySQL in PHP pages involves:

1. **Connecting** to the database using MySQLi or PDO.
2. **Fetching** data from the database using SQL queries.
3. **Displaying** the fetched data in an HTML table or other formats.
4. **Handling errors** gracefully.
5. **Closing** the database connection after use.

Both **MySQLi** and **PDO** allow you to interact with the MySQL database, but PDO is more flexible and supports multiple databases, while MySQLi is more specific to MySQL. Choose the one that fits your project requirements.
