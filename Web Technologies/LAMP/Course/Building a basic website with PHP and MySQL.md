### **Building a Basic Website with PHP and MySQL**

Creating a basic website with PHP and MySQL involves several steps. This guide will walk you through setting up a simple dynamic website where you can view, add, edit, and delete user records. The website will have the following components:

1. **Homepage** - Display a list of users stored in the database.
2. **Add User Page** - A form to add new users to the database.
3. **Edit User Page** - A form to update user details.
4. **Delete User** - A link to delete users from the database.

### **Step 1: Set Up the MySQL Database**

First, you need a MySQL database to store the data. Here’s how to create the `users` table.

1. **Create Database**:
   ```sql
   CREATE DATABASE my_website;
   ```

2. **Create `users` Table**:
   ```sql
   USE my_website;

   CREATE TABLE users (
       id INT(11) AUTO_INCREMENT PRIMARY KEY,
       name VARCHAR(100),
       email VARCHAR(100),
       age INT(3)
   );
   ```

3. **Insert Sample Data**:
   ```sql
   INSERT INTO users (name, email, age) VALUES 
   ('John Doe', 'john@example.com', 25),
   ('Jane Smith', 'jane@example.com', 30),
   ('Mike Johnson', 'mike@example.com', 22);
   ```

### **Step 2: Directory Structure**

Here’s the directory structure for the website:

```
/my_website
    /css
        style.css
    /includes
        db_connect.php
    /index.php
    /add_user.php
    /edit_user.php
    /delete_user.php
```

### **Step 3: Connect to the MySQL Database**

Create a file called `db_connect.php` inside the `includes` folder to handle the database connection.

```php
<?php
// includes/db_connect.php

$servername = "localhost";
$username = "root"; // change this to your MySQL username
$password = ""; // change this to your MySQL password
$dbname = "my_website"; // the database you created

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
?>
```

### **Step 4: Display Users on the Homepage**

Create a file called `index.php` to display the list of users.

```php
<?php
// index.php
include('includes/db_connect.php');

// Fetch users from the database
$sql = "SELECT * FROM users";
$result = $conn->query($sql);

echo "<h2>User List</h2>";

if ($result->num_rows > 0) {
    echo "<table border='1'>
            <tr>
                <th>ID</th>
                <th>Name</th>
                <th>Email</th>
                <th>Age</th>
                <th>Actions</th>
            </tr>";
    
    // Output data of each row
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
    echo "No users found.";
}

$conn->close();
?>
```

### **Step 5: Add New User (Create)**

Create a form for adding new users in `add_user.php`.

```php
<?php
// add_user.php
include('includes/db_connect.php');

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Get form data
    $name = $_POST['name'];
    $email = $_POST['email'];
    $age = $_POST['age'];

    // Insert data into the database
    $sql = "INSERT INTO users (name, email, age) VALUES ('$name', '$email', '$age')";

    if ($conn->query($sql) === TRUE) {
        echo "New user added successfully!";
    } else {
        echo "Error: " . $conn->error;
    }

    $conn->close();
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Add User</title>
</head>
<body>
    <h2>Add New User</h2>
    <form method="POST" action="add_user.php">
        <label for="name">Name:</label>
        <input type="text" name="name" required><br><br>

        <label for="email">Email:</label>
        <input type="email" name="email" required><br><br>

        <label for="age">Age:</label>
        <input type="number" name="age" required><br><br>

        <button type="submit">Add User</button>
    </form>
</body>
</html>
```

### **Step 6: Edit User (Update)**

Create `edit_user.php` to allow users to edit their information.

```php
<?php
// edit_user.php
include('includes/db_connect.php');

// Get the ID of the user to edit
$id = $_GET['id'];

// Fetch the user details
$sql = "SELECT * FROM users WHERE id = $id";
$result = $conn->query($sql);
$user = $result->fetch_assoc();

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Get updated form data
    $name = $_POST['name'];
    $email = $_POST['email'];
    $age = $_POST['age'];

    // Update the user in the database
    $sql = "UPDATE users SET name='$name', email='$email', age='$age' WHERE id=$id";

    if ($conn->query($sql) === TRUE) {
        echo "User updated successfully!";
    } else {
        echo "Error: " . $conn->error;
    }
}

$conn->close();
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
    <form method="POST" action="edit_user.php?id=<?php echo $user['id']; ?>">
        <label for="name">Name:</label>
        <input type="text" name="name" value="<?php echo $user['name']; ?>" required><br><br>

        <label for="email">Email:</label>
        <input type="email" name="email" value="<?php echo $user['email']; ?>" required><br><br>

        <label for="age">Age:</label>
        <input type="number" name="age" value="<?php echo $user['age']; ?>" required><br><br>

        <button type="submit">Update User</button>
    </form>
</body>
</html>
```

### **Step 7: Delete User (Delete)**

Create `delete_user.php` to delete a user from the database.

```php
<?php
// delete_user.php
include('includes/db_connect.php');

// Get the ID of the user to delete
$id = $_GET['id'];

// Delete the user from the database
$sql = "DELETE FROM users WHERE id=$id";

if ($conn->query($sql) === TRUE) {
    echo "User deleted successfully!";
} else {
    echo "Error: " . $conn->error;
}

$conn->close();
?>
```

### **Step 8: Add Basic Styling**

Create a `style.css` file in the `css` folder for basic styling.

```css
/* css/style.css */

body {
    font-family: Arial, sans-serif;
}

table {
    width: 100%;
    border-collapse: collapse;
    margin-top: 20px;
}

th, td {
    padding: 10px;
    text-align: left;
}

th {
    background-color: #f2f2f2;
}

form {
    margin-top: 20px;
}

label {
    font-weight: bold;
}

button {
    padding: 10px 20px;
    background-color: #4CAF50;
    color: white;
    border: none;
    cursor: pointer;
}

button:hover {
    background-color: #45a049;
}
```

Link the stylesheet in each of your PHP pages:

```html
<link rel="stylesheet" href="css/style.css">
```

### **Step 9: Testing the Website**

- **Homepage**: Open `index.php` in a browser to view the list of users.
- **Add User**: Navigate to `add_user.php` to add a new user.
- **Edit User**: Click "Edit" on a user in the list to modify their details.
- **Delete User**: Click "Delete" to remove a user.

---

### **Conclusion**

You’ve now built a basic website with PHP and MySQL that allows you to:

1. **View users** from the database.
2. **Add new users** via a form.
3. **Edit user information**.
4. **Delete users** from the database.

You can extend this website by adding features like user authentication, form validation, and error handling for a more robust and secure application.
