### **Implementing CRUD Operations in PHP**

CRUD operations (Create, Read, Update, Delete) are essential in most database-driven web applications. These operations allow users to interact with the data in the database by adding, reading, updating, and deleting records. Below is a comprehensive guide to implementing CRUD operations using PHP and MySQL.

For this example, we'll use a **MySQL database** with a **`users` table**, which contains the following columns:
- `id` (int, primary key, auto-increment)
- `name` (varchar)
- `email` (varchar)
- `age` (int)

### **1. Set Up the Database**

Assume you already have a `users` table in your MySQL database. Here's how you can create the table:

```sql
CREATE TABLE users (
    id INT(11) AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100),
    email VARCHAR(100),
    age INT(3)
);
```

### **2. Create PHP Functions for CRUD Operations**

We will create PHP functions to handle the **Create**, **Read**, **Update**, and **Delete** operations.

---

### **3. Create Operation (Insert Data into Database)**

#### **3.1 HTML Form to Input Data**

The user can add a new record through a form.

```html
<!-- add_user.php -->
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Add User</title>
</head>
<body>
    <h2>Add User</h2>
    <form method="POST" action="add_user.php">
        <label for="name">Name:</label>
        <input type="text" name="name" id="name" required><br><br>

        <label for="email">Email:</label>
        <input type="email" name="email" id="email" required><br><br>

        <label for="age">Age:</label>
        <input type="number" name="age" id="age" required><br><br>

        <button type="submit">Submit</button>
    </form>
</body>
</html>
```

#### **3.2 PHP Script to Insert Data (Create)**

```php
<?php
// add_user.php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Get form data
    $name = $_POST['name'];
    $email = $_POST['email'];
    $age = $_POST['age'];

    // Database connection
    $conn = new mysqli("localhost", "root", "", "my_database");

    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    // SQL query to insert data
    $sql = "INSERT INTO users (name, email, age) VALUES ('$name', '$email', '$age')";

    if ($conn->query($sql) === TRUE) {
        echo "New record created successfully.";
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }

    $conn->close();
}
?>
```

- **POST method**: Data is sent via POST to the `add_user.php` file.
- **SQL query**: The `INSERT INTO` statement adds a new user record into the `users` table.

---

### **4. Read Operation (Display Data from Database)**

#### **4.1 PHP Script to Fetch and Display Data (Read)**

```php
<?php
// view_users.php

$conn = new mysqli("localhost", "root", "", "my_database");

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sql = "SELECT * FROM users";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    echo "<table border='1'>
            <tr>
                <th>ID</th>
                <th>Name</th>
                <th>Email</th>
                <th>Age</th>
                <th>Actions</th>
            </tr>";

    while ($row = $result->fetch_assoc()) {
        echo "<tr>
                <td>" . $row['id'] . "</td>
                <td>" . $row['name'] . "</td>
                <td>" . $row['email'] . "</td>
                <td>" . $row['age'] . "</td>
                <td><a href='edit_user.php?id=" . $row['id'] . "'>Edit</a> | <a href='delete_user.php?id=" . $row['id'] . "'>Delete</a></td>
              </tr>";
    }
    echo "</table>";
} else {
    echo "No records found";
}

$conn->close();
?>
```

- This script fetches all users from the `users` table and displays them in an HTML table.
- The **Edit** and **Delete** links allow for updating or deleting records.

---

### **5. Update Operation (Edit Data in the Database)**

#### **5.1 HTML Form for Editing Data**

When a user clicks on "Edit" in the view, they are taken to a form with the current user data pre-filled.

```php
<!-- edit_user.php -->
<?php
// Get the ID of the user to edit
$id = $_GET['id'];

$conn = new mysqli("localhost", "root", "", "my_database");

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Fetch the user details
$sql = "SELECT * FROM users WHERE id = $id";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    $row = $result->fetch_assoc();
} else {
    echo "No user found";
    exit;
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Edit User</title>
</head>
<body>
    <h2>Edit User</h2>
    <form method="POST" action="edit_user.php?id=<?php echo $row['id']; ?>">
        <label for="name">Name:</label>
        <input type="text" name="name" id="name" value="<?php echo $row['name']; ?>" required><br><br>

        <label for="email">Email:</label>
        <input type="email" name="email" id="email" value="<?php echo $row['email']; ?>" required><br><br>

        <label for="age">Age:</label>
        <input type="number" name="age" id="age" value="<?php echo $row['age']; ?>" required><br><br>

        <button type="submit">Update</button>
    </form>
</body>
</html>
```

#### **5.2 PHP Script to Update Data (Update)**

```php
<?php
// edit_user.php

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Get the ID and updated data
    $id = $_GET['id'];
    $name = $_POST['name'];
    $email = $_POST['email'];
    $age = $_POST['age'];

    $conn = new mysqli("localhost", "root", "", "my_database");

    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    // SQL query to update data
    $sql = "UPDATE users SET name='$name', email='$email', age='$age' WHERE id=$id";

    if ($conn->query($sql) === TRUE) {
        echo "Record updated successfully.";
    } else {
        echo "Error: " . $conn->error;
    }

    $conn->close();
}
?>
```

- The form allows users to modify the existing user details.
- The `UPDATE` SQL query updates the record where the `id` matches.

---

### **6. Delete Operation (Delete Data from the Database)**

#### **6.1 PHP Script to Delete Data (Delete)**

```php
<?php
// delete_user.php
$id = $_GET['id'];

$conn = new mysqli("localhost", "root", "", "my_database");

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// SQL query to delete data
$sql = "DELETE FROM users WHERE id=$id";

if ($conn->query($sql) === TRUE) {
    echo "Record deleted successfully.";
} else {
    echo "Error: " . $conn->error;
}

$conn->close();
?>
```

- This script deletes the user with the given `id` from the `users` table.

---

### **7. Final Thoughts**

These are the basic CRUD operations implemented in PHP using MySQL:

- **Create**: Adds a new record into the database.
- **Read**: Fetches and displays records from the database.
- **Update**: Modifies existing records in the database.
- **Delete**: Removes records from the database.

#### **Security Considerations**
- Always **sanitize** and **validate** user inputs to avoid SQL injection attacks (use prepared statements with PDO or MySQLi).
- Use **form validation** on both the client side and server side to ensure data integrity.
