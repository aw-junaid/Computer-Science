### **Building a Basic Website with PHP and MySQL**

In this tutorial, we'll walk through building a simple dynamic website using **PHP** and **MySQL**. This website will allow users to view, add, edit, and delete records from a MySQL database, demonstrating the basic CRUD (Create, Read, Update, Delete) operations.

### **Requirements**
- **PHP** (version 7.4 or higher)
- **MySQL** (for database management)
- **Apache Web Server** (or any web server supporting PHP)
- **Text editor** (e.g., VS Code, Sublime Text)

### **Steps to Build the Website**

#### **1. Set Up the MySQL Database**

1. **Create the Database:**

   Log into your MySQL server (using MySQL Workbench, phpMyAdmin, or the command line) and create a database called `website_db`.

   ```sql
   CREATE DATABASE website_db;
   ```

2. **Create a Table:**

   Now, let's create a table to store user information. We'll create a `users` table with the following columns: `id`, `name`, and `email`.

   ```sql
   USE website_db;

   CREATE TABLE users (
       id INT AUTO_INCREMENT PRIMARY KEY,
       name VARCHAR(100),
       email VARCHAR(100)
   );
   ```

3. **Insert Sample Data:**

   You can insert a few rows to have some sample data in the `users` table.

   ```sql
   INSERT INTO users (name, email) VALUES
   ('John Doe', 'john@example.com'),
   ('Jane Smith', 'jane@example.com');
   ```

#### **2. Set Up the PHP Project**

Create a directory for your project, e.g., `my_website`, inside the root directory of your web server (e.g., `htdocs` if you're using XAMPP). Inside this directory, create the following structure:

```
my_website/
├── index.php
├── db.php
├── create.php
├── update.php
├── delete.php
└── config.php
```

#### **3. Connect to the MySQL Database**

In `config.php`, we’ll define the database connection.

```php
<?php
$host = 'localhost';     // Database host
$dbname = 'website_db';  // Database name
$username = 'root';      // Database username
$password = '';          // Database password (empty for localhost by default)

try {
    $pdo = new PDO("mysql:host=$host;dbname=$dbname", $username, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
    echo "Connection failed: " . $e->getMessage();
}
?>
```

#### **4. Create the Main Page (index.php)**

In `index.php`, we will fetch and display all the users stored in the MySQL database.

```php
<?php
include('config.php');

$query = "SELECT * FROM users";
$stmt = $pdo->prepare($query);
$stmt->execute();
$users = $stmt->fetchAll(PDO::FETCH_ASSOC);
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>PHP & MySQL Website</title>
</head>
<body>
    <h1>User List</h1>
    <a href="create.php">Add New User</a>
    <table border="1">
        <thead>
            <tr>
                <th>ID</th>
                <th>Name</th>
                <th>Email</th>
                <th>Actions</th>
            </tr>
        </thead>
        <tbody>
            <?php foreach ($users as $user): ?>
            <tr>
                <td><?= htmlspecialchars($user['id']) ?></td>
                <td><?= htmlspecialchars($user['name']) ?></td>
                <td><?= htmlspecialchars($user['email']) ?></td>
                <td>
                    <a href="update.php?id=<?= $user['id'] ?>">Edit</a> | 
                    <a href="delete.php?id=<?= $user['id'] ?>" onclick="return confirm('Are you sure?')">Delete</a>
                </td>
            </tr>
            <?php endforeach; ?>
        </tbody>
    </table>
</body>
</html>
```

- **Fetching Users**: The script queries the `users` table and fetches all rows, which are then displayed in an HTML table.
- **Edit & Delete Links**: Links for editing and deleting users are provided. We'll create the `update.php` and `delete.php` files next.

#### **5. Create New Users (create.php)**

In `create.php`, we’ll display a form to add new users to the database.

```php
<?php
include('config.php');

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $name = $_POST['name'];
    $email = $_POST['email'];

    // Insert the user data into the database
    $query = "INSERT INTO users (name, email) VALUES (:name, :email)";
    $stmt = $pdo->prepare($query);
    $stmt->bindParam(':name', $name);
    $stmt->bindParam(':email', $email);
    $stmt->execute();

    // Redirect to the home page after successful insertion
    header('Location: index.php');
    exit;
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Create User</title>
</head>
<body>
    <h1>Add New User</h1>
    <form method="POST" action="create.php">
        <label for="name">Name:</label><br>
        <input type="text" id="name" name="name" required><br><br>

        <label for="email">Email:</label><br>
        <input type="email" id="email" name="email" required><br><br>

        <input type="submit" value="Create User">
    </form>
    <br>
    <a href="index.php">Back to User List</a>
</body>
</html>
```

- **Form Submission**: The form takes `name` and `email` as input, and on submission, the data is inserted into the `users` table.
- **Redirect**: After the user is added, the page redirects to `index.php`.

#### **6. Update User Information (update.php)**

In `update.php`, we will allow users to edit their details.

```php
<?php
include('config.php');

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $id = $_POST['id'];
    $name = $_POST['name'];
    $email = $_POST['email'];

    // Update the user data in the database
    $query = "UPDATE users SET name = :name, email = :email WHERE id = :id";
    $stmt = $pdo->prepare($query);
    $stmt->bindParam(':name', $name);
    $stmt->bindParam(':email', $email);
    $stmt->bindParam(':id', $id);
    $stmt->execute();

    // Redirect to the home page after successful update
    header('Location: index.php');
    exit;
}

if (isset($_GET['id'])) {
    $id = $_GET['id'];

    // Fetch the user data from the database
    $query = "SELECT * FROM users WHERE id = :id";
    $stmt = $pdo->prepare($query);
    $stmt->bindParam(':id', $id);
    $stmt->execute();
    $user = $stmt->fetch(PDO::FETCH_ASSOC);
} else {
    header('Location: index.php');
    exit;
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Update User</title>
</head>
<body>
    <h1>Edit User</h1>
    <form method="POST" action="update.php">
        <input type="hidden" name="id" value="<?= $user['id'] ?>">

        <label for="name">Name:</label><br>
        <input type="text" id="name" name="name" value="<?= htmlspecialchars($user['name']) ?>" required><br><br>

        <label for="email">Email:</label><br>
        <input type="email" id="email" name="email" value="<?= htmlspecialchars($user['email']) ?>" required><br><br>

        <input type="submit" value="Update User">
    </form>
    <br>
    <a href="index.php">Back to User List</a>
</body>
</html>
```

- **Editing Users**: The form is pre-filled with the user’s existing information, which can be updated.
- **Updating the Database**: Upon submission, the changes are saved to the database, and the user is redirected to `index.php`.

#### **7. Delete Users (delete.php)**

In `delete.php`, we will delete a user from the database.

```php
<?php
include('config.php');

if (isset($_GET['id'])) {
    $id = $_GET['id'];

    // Delete the user from the database
    $query = "DELETE FROM users WHERE id = :id";
    $stmt = $pdo->prepare($query);
    $stmt->bindParam(':id', $id);
    $stmt->execute();

    // Redirect to the home page after deletion
    header('Location: index.php');
    exit;
}
?>
```

- **Delete Confirmation**: When the user clicks "Delete", the record is removed from the database, and the user is redirected back to the user list.

---

### **Conclusion**

You now have a simple dynamic website that interacts with a MySQL database using PHP. This website allows you to:

- View a list of users
- Add new users
- Edit existing users
- Delete users

This tutorial demonstrates basic CRUD operations using PHP and MySQL. You can extend the website by adding more features such as user authentication, input validation, and error handling.
