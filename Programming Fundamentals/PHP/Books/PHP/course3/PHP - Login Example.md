### PHP - Login Example

A login system is a fundamental feature for most web applications. Here's a simple PHP login system that demonstrates user authentication using a username and password.

In this example, we'll use **PHP sessions** to manage the logged-in user's state. The password will be stored securely using **password hashing** to ensure that it is not stored in plain text.

### 1. Database Structure

Assume we have a simple database table `users` that stores the username and password:

```sql
CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) NOT NULL UNIQUE,
    password VARCHAR(255) NOT NULL
);
```

For this example, we'll use **MySQL** to store the user credentials.

### 2. Creating a Registration Page (for testing)

Before we can log in, we need a way to register users and store their passwords securely.

#### `register.php`

```php
<?php
// Include database connection
include('db.php');

// Handle form submission
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $username = $_POST['username'];
    $password = $_POST['password'];

    // Hash the password before saving
    $hashedPassword = password_hash($password, PASSWORD_DEFAULT);

    // Insert the new user into the database
    $query = "INSERT INTO users (username, password) VALUES ('$username', '$hashedPassword')";
    
    if (mysqli_query($conn, $query)) {
        echo "User registered successfully!";
    } else {
        echo "Error: " . mysqli_error($conn);
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Register</title>
</head>
<body>
    <h2>Register</h2>
    <form method="POST" action="">
        <label for="username">Username:</label>
        <input type="text" name="username" required><br><br>
        
        <label for="password">Password:</label>
        <input type="password" name="password" required><br><br>
        
        <input type="submit" value="Register">
    </form>
</body>
</html>
```

### 3. Creating a Login Page

Now let's create the login page where users can log in using their credentials.

#### `login.php`

```php
<?php
session_start();
include('db.php'); // Include database connection

// Handle form submission
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $username = $_POST['username'];
    $password = $_POST['password'];

    // Fetch the user from the database
    $query = "SELECT * FROM users WHERE username = '$username'";
    $result = mysqli_query($conn, $query);

    if (mysqli_num_rows($result) > 0) {
        $user = mysqli_fetch_assoc($result);
        
        // Verify password
        if (password_verify($password, $user['password'])) {
            // Set session variables for the logged-in user
            $_SESSION['username'] = $user['username'];
            $_SESSION['user_id'] = $user['id'];
            
            // Redirect to the welcome page
            header('Location: welcome.php');
            exit;
        } else {
            echo "Invalid password!";
        }
    } else {
        echo "No user found with that username!";
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login</title>
</head>
<body>
    <h2>Login</h2>
    <form method="POST" action="">
        <label for="username">Username:</label>
        <input type="text" name="username" required><br><br>
        
        <label for="password">Password:</label>
        <input type="password" name="password" required><br><br>
        
        <input type="submit" value="Login">
    </form>
</body>
</html>
```

### 4. Creating a Welcome Page

The **welcome page** will be shown after a successful login.

#### `welcome.php`

```php
<?php
session_start();

// Check if user is logged in
if (!isset($_SESSION['username'])) {
    header('Location: login.php'); // Redirect to login if not logged in
    exit;
}

echo "Welcome, " . $_SESSION['username'] . "! <br>";
echo "<a href='logout.php'>Logout</a>";
?>
```

### 5. Creating a Logout Page

#### `logout.php`

```php
<?php
session_start();

// Destroy the session to log out
session_unset();
session_destroy();

header('Location: login.php'); // Redirect to login page after logout
exit;
?>
```

### 6. Database Connection (db.php)

You'll need to create a database connection file for your MySQL connection. Here's an example:

#### `db.php`

```php
<?php
$servername = "localhost";
$username = "root"; // Your database username
$password = ""; // Your database password
$dbname = "test"; // Your database name

// Create connection
$conn = mysqli_connect($servername, $username, $password, $dbname);

// Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}
?>
```

### How It Works:
1. **Registration (`register.php`)**: The user provides a username and password. The password is hashed using `password_hash()` before being stored in the database.
   
2. **Login (`login.php`)**: The user provides a username and password. The password is checked using `password_verify()`, which compares the provided password with the hashed one stored in the database.

3. **Session Management**: After a successful login, session variables are set (`$_SESSION['username']` and `$_SESSION['user_id']`). These session variables are used to track the logged-in user. If the user tries to access the welcome page without logging in, they are redirected back to the login page.

4. **Logout (`logout.php`)**: This script destroys the session, effectively logging the user out and redirecting them to the login page.

### Security Considerations:
- **Password Hashing**: We use `password_hash()` to hash the password and `password_verify()` to check the password during login. This ensures that passwords are not stored in plain text.
- **Sessions**: PHP sessions are used to maintain the user's login state. The session data is stored on the server, making it more secure than relying on cookies.
- **SQL Injection Prevention**: In a real-world scenario, it's important to use **prepared statements** to prevent SQL injection attacks. The code above does not include prepared statements for simplicity, but it should be implemented for production use.

This is a simple and secure login system, but in production, you'd want to implement additional security features such as:
- HTTPS for secure data transmission.
- Rate limiting and CAPTCHA to prevent brute-force attacks.
- Password reset functionality.

