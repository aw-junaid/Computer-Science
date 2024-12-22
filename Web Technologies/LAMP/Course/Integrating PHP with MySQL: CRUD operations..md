### **Integrating PHP with MySQL: CRUD Operations**

PHP and MySQL are commonly used together to build dynamic, data-driven websites. The integration allows PHP to interact with MySQL databases to perform **CRUD** (Create, Read, Update, Delete) operations. These operations allow users to manipulate data stored in MySQL through a PHP interface.

---

### **1. Connecting PHP to MySQL**

Before performing any database operations, you need to connect PHP to your MySQL database using the `mysqli` or `PDO` extension. Below is an example using `mysqli`, which is simpler and more commonly used.

#### **1.1 MySQLi Connection**

```php
<?php
$servername = "localhost";  // Database host (usually localhost)
$username = "root";         // MySQL username
$password = "";             // MySQL password
$dbname = "my_database";    // MySQL database name

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
echo "Connected successfully";
?>
```

- **`new mysqli()`**: Creates a new connection to the MySQL database.
- **`$conn->connect_error`**: Checks if the connection failed.

Once the connection is established, you can use `$conn` to execute queries.

---

### **2. CRUD Operations**

Now that you're connected to MySQL, you can perform **CRUD** operations.

#### **2.1 Create: Inserting Data**

To insert data into a MySQL table, you can use the `INSERT INTO` SQL statement.

##### **2.1.1 Example: Insert Data**

```php
<?php
// Example data to insert
$name = "John Doe";
$email = "john.doe@example.com";

// SQL query to insert data into the users table
$sql = "INSERT INTO users (name, email) VALUES ('$name', '$email')";

// Execute the query
if ($conn->query($sql) === TRUE) {
    echo "New record created successfully";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}
?>
```

- **`$conn->query()`**: Executes the SQL query. If successful, it returns `TRUE`, else it returns `FALSE`.
- **SQL Injection Risk**: Directly inserting variables into SQL queries is risky. Use prepared statements to prevent **SQL injection**.

##### **2.1.2 Example: Using Prepared Statements**

```php
<?php
// Prepare the SQL statement
$stmt = $conn->prepare("INSERT INTO users (name, email) VALUES (?, ?)");

// Bind parameters
$stmt->bind_param("ss", $name, $email);  // "ss" means two strings

// Set values and execute the statement
$name = "Jane Doe";
$email = "jane.doe@example.com";
$stmt->execute();

echo "New record created successfully";

// Close the prepared statement
$stmt->close();
?>
```

- **`prepare()`**: Prepares an SQL query for execution.
- **`bind_param()`**: Binds the variables to the SQL query, ensuring safe data insertion.
- **`execute()`**: Executes the prepared statement.

#### **2.2 Read: Retrieving Data**

To retrieve data from a MySQL database, you use the `SELECT` SQL statement.

##### **2.2.1 Example: Select Data**

```php
<?php
// SQL query to select data from the users table
$sql = "SELECT id, name, email FROM users";
$result = $conn->query($sql);

// Check if any records are returned
if ($result->num_rows > 0) {
    // Output data for each row
    while($row = $result->fetch_assoc()) {
        echo "id: " . $row["id"] . " - Name: " . $row["name"] . " - Email: " . $row["email"] . "<br>";
    }
} else {
    echo "0 results";
}
?>
```

- **`$result->num_rows`**: Returns the number of rows returned by the query.
- **`$result->fetch_assoc()`**: Fetches the result as an associative array, where the keys are the column names.

#### **2.3 Update: Modifying Data**

To update existing data, you use the `UPDATE` SQL statement.

##### **2.3.1 Example: Update Data**

```php
<?php
// Example data to update
$new_email = "john.updated@example.com";
$id = 1;

// SQL query to update the email address of a specific user
$sql = "UPDATE users SET email = '$new_email' WHERE id = $id";

if ($conn->query($sql) === TRUE) {
    echo "Record updated successfully";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}
?>
```

- **`UPDATE`**: Updates existing records in the table.
- **`WHERE`**: Specifies the condition to identify the row to be updated.

##### **2.3.2 Example: Using Prepared Statements for Update**

```php
<?php
// Prepare the SQL statement for updating
$stmt = $conn->prepare("UPDATE users SET email = ? WHERE id = ?");

// Bind parameters
$stmt->bind_param("si", $new_email, $id);

// Set values and execute the statement
$new_email = "john.updated@example.com";
$id = 1;
$stmt->execute();

echo "Record updated successfully";

// Close the prepared statement
$stmt->close();
?>
```

#### **2.4 Delete: Removing Data**

To delete records, you use the `DELETE` SQL statement.

##### **2.4.1 Example: Delete Data**

```php
<?php
// Example data to delete
$id = 1;

// SQL query to delete a specific user
$sql = "DELETE FROM users WHERE id = $id";

if ($conn->query($sql) === TRUE) {
    echo "Record deleted successfully";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}
?>
```

- **`DELETE FROM`**: Deletes records from the table based on the specified condition (`WHERE`).
  
##### **2.4.2 Example: Using Prepared Statements for Delete**

```php
<?php
// Prepare the SQL statement for deleting
$stmt = $conn->prepare("DELETE FROM users WHERE id = ?");

// Bind parameter
$stmt->bind_param("i", $id);

// Set the value and execute the statement
$id = 1;
$stmt->execute();

echo "Record deleted successfully";

// Close the prepared statement
$stmt->close();
?>
```

---

### **3. Closing the Database Connection**

After all database operations are complete, it's good practice to close the connection.

```php
<?php
$conn->close();  // Close the MySQL connection
?>
```

- **`$conn->close()`**: Closes the MySQL connection and frees up resources.

---

### **4. Error Handling in CRUD Operations**

For better error handling, you can check for errors after executing each query.

```php
if ($conn->query($sql) === TRUE) {
    echo "Operation successful.";
} else {
    echo "Error: " . $conn->error;
}
```

Using **prepared statements** ensures that user input is sanitized and prevents SQL injection attacks.

---

### **Summary of CRUD Operations**

- **Create**: Use `INSERT INTO` to add data to the database.
- **Read**: Use `SELECT` to retrieve data from the database.
- **Update**: Use `UPDATE` to modify existing data.
- **Delete**: Use `DELETE FROM` to remove data.
- **Prepared Statements**: Always use prepared statements for safer and more efficient SQL queries.

This basic CRUD functionality enables you to create dynamic, data-driven websites with PHP and MySQL.
