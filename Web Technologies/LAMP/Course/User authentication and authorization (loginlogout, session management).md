### **User Authentication and Authorization in PHP (Login/Logout, Session Management)**

User authentication and authorization are essential components of web applications that require users to log in to access specific content or perform actions. In this guide, we’ll implement basic user authentication (login/logout) and session management using PHP and MySQL.

---

### **Overview**

We will:
1. Create a user login system.
2. Implement user authentication (verify credentials).
3. Use PHP sessions to manage user state.
4. Allow users to log out and destroy their session.

### **Step 1: Set Up the MySQL Database**

You need a `users` table with a username, email, and password. We will also store a hashed version of the password for security purposes.

1. **Create Database** (if not already done):
   ```sql
   CREATE DATABASE my_website;
   ```

2. **Create `users` Table**:
   ```sql
   USE my_website;

   CREATE TABLE users (
       id INT(11) AUTO_INCREMENT PRIMARY KEY,
       username VARCHAR(50) NOT NULL,
       email VARCHAR(100) NOT NULL,
       password VARCHAR(255) NOT NULL
   );
   ```

3. **Insert a Sample User** (with a hashed password):
   ```sql
   INSERT INTO users (username, email, password) VALUES 
   ('admin', 'admin@example.com', '$2y$10$abcdefg1234567890abcdefg1234567890abcdefg1234567890'); 
   ```
   The password here is a **hashed** version of "password123" generated using `password_hash('password123', PASSWORD_DEFAULT)` in PHP.

### **Step 2: Creating the Login Form (HTML)**

Create a form for users to enter their username and password.

```html
<!-- login.php -->
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login</title>
</head>
<body>
    <h2>Login</h2>
    <form method="POST" action="login.php">
        <label for="username">Username:</label>
        <input type="text" name="username" required><br><br>

        <label for="password">Password:</label>
        <input type="password" name="password" required><br><br>

        <button type="submit">Login</button>
    </form>
</body>
</html>
```

### **Step 3: Handling the Login Logic in PHP**

The login logic will verify the credentials by checking the username and password against the database.

```php
<?php
// login.php
session_start();
include('includes/db_connect.php'); // Include database connection

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Get form data
    $username = $_POST['username'];
    $password = $_POST['password'];

    // Query to fetch the user from the database
    $sql = "SELECT * FROM users WHERE username = '$username'";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        // User found, now check the password
        $user = $result->fetch_assoc();

        if (password_verify($password, $user['password'])) {
            // Password is correct, start session
            $_SESSION['user_id'] = $user['id'];
            $_SESSION['username'] = $user['username'];
            header("Location: welcome.php"); // Redirect to a protected page
            exit();
        } else {
            echo "Invalid password.";
        }
    } else {
        echo "No user found with that username.";
    }

    $conn->close();
}
?>
```

- **password_verify()**: This function checks if the password entered by the user matches the hashed password stored in the database.
- If the credentials are correct, a session is started with `$_SESSION` variables that store the user ID and username.

### **Step 4: Creating a Protected Page**

After successful login, the user should be redirected to a protected page (e.g., `welcome.php`). The page should check if the user is logged in by verifying the session.

```php
<?php
// welcome.php
session_start();

if (!isset($_SESSION['user_id'])) {
    header("Location: login.php"); // Redirect to login if not logged in
    exit();
}

echo "<h1>Welcome, " . $_SESSION['username'] . "!</h1>";
echo "<a href='logout.php'>Logout</a>";
?>
```

- The session is checked using `isset($_SESSION['user_id'])`. If not set, the user is redirected to the login page.

### **Step 5: Implementing Logout Functionality**

The user should be able to log out, which will destroy the session and redirect them to the login page.

```php
<?php
// logout.php
session_start();

// Destroy the session
session_unset();
session_destroy();

header("Location: login.php"); // Redirect to the login page
exit();
?>
```

- `session_unset()` clears all session variables.
- `session_destroy()` destroys the session.

### **Step 6: Optional: Creating a Registration Page**

If you want to allow users to register on your site, you’ll need a registration form and logic to insert new users into the database with a hashed password.

#### **Registration Form (HTML)**

```html
<!-- register.php -->
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Register</title>
</head>
<body>
    <h2>Register</h2>
    <form method="POST" action="register.php">
        <label for="username">Username:</label>
        <input type="text" name="username" required><br><br>

        <label for="email">Email:</label>
        <input type="email" name="email" required><br><br>

        <label for="password">Password:</label>
        <input type="password" name="password" required><br><br>

        <button type="submit">Register</button>
    </form>
</body>
</html>
```

#### **Registration Logic (PHP)**

```php
<?php
// register.php
include('includes/db_connect.php');

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Get form data
    $username = $_POST['username'];
    $email = $_POST['email'];
    $password = $_POST['password'];

    // Hash the password
    $hashed_password = password_hash($password, PASSWORD_DEFAULT);

    // Insert new user into the database
    $sql = "INSERT INTO users (username, email, password) VALUES ('$username', '$email', '$hashed_password')";

    if ($conn->query($sql) === TRUE) {
        echo "Registration successful! <a href='login.php'>Login</a>";
    } else {
        echo "Error: " . $conn->error;
    }

    $conn->close();
}
?>
```

- **password_hash()**: This function hashes the user's password before storing it in the database.
- After the user is registered, they can log in using the login form.

### **Step 7: Add Basic Styling (Optional)**

You can add a `style.css` file for simple styling of your login, registration, and protected pages.

```css
/* css/style.css */
body {
    font-family: Arial, sans-serif;
}

h1, h2 {
    text-align: center;
}

form {
    max-width: 400px;
    margin: auto;
    padding: 20px;
    border: 1px solid #ccc;
    border-radius: 8px;
}

input, button {
    width: 100%;
    padding: 10px;
    margin: 10px 0;
    border-radius: 4px;
}

button {
    background-color: #4CAF50;
    color: white;
    border: none;
    cursor: pointer;
}

button:hover {
    background-color: #45a049;
}

a {
    display: block;
    text-align: center;
    margin-top: 20px;
}
```

Link the stylesheet in your PHP files:

```html
<link rel="stylesheet" href="css/style.css">
```

### **Step 8: Testing the System**

- **Login**: Go to `login.php`, enter the credentials of a user (like "admin" and "password123"), and try logging in.
- **Registration**: If you’ve added the registration page, you can test creating a new user in `register.php`.
- **Logout**: After logging in, click the "Logout" link to destroy the session and log out.
- **Access Control**: Try accessing `welcome.php` without logging in, and it should redirect you to the login page.

---

### **Conclusion**

You’ve now implemented a basic user authentication and authorization system using PHP and MySQL. The system includes:
- **User Login**: Verifying user credentials and starting a session.
- **Session Management**: Using `$_SESSION` to track logged-in users.
- **User Logout**: Destroying the session and logging out the user.
- **User Registration** (Optional): Allowing new users to register with a hashed password.

You can enhance this system by adding features such as password reset, email verification, and user roles (e.g., admin, user).
