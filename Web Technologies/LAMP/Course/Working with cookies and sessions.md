### **Working with Cookies and Sessions in PHP**

Cookies and sessions are two important tools in web development that help maintain state between HTTP requests, which is otherwise stateless. They allow you to store and retrieve data across different pages of a website, making the user experience smoother.

Here’s an overview of how **cookies** and **sessions** work and how you can use them in PHP.

---

### **1. Cookies in PHP**

#### **What is a Cookie?**
A **cookie** is a small piece of data that is stored on the user's browser. It can be used to store user preferences, tracking information, or any other data that you want to persist across page requests.

#### **Setting a Cookie**

To set a cookie, use the `setcookie()` function. This function must be called before any output is sent to the browser (i.e., before HTML content).

```php
<?php
// Setting a cookie
$cookie_name = "user";
$cookie_value = "John Doe";
$cookie_expire_time = time() + (86400 * 30);  // 30 days from now

// Setting the cookie
setcookie($cookie_name, $cookie_value, $cookie_expire_time, "/");  // "/" means the cookie is available across the whole website
?>
```

- `$cookie_name` is the name of the cookie.
- `$cookie_value` is the value stored in the cookie.
- `$cookie_expire_time` is the expiration time of the cookie (using `time()` to specify a time).
- The fourth parameter (`"/"`) specifies the path where the cookie is available. By default, it's available for the entire website.

#### **Accessing a Cookie**

To access a cookie, use the `$_COOKIE` superglobal.

```php
<?php
// Accessing the cookie
if (isset($_COOKIE["user"])) {
    echo "Hello, " . $_COOKIE["user"];
} else {
    echo "Cookie 'user' is not set.";
}
?>
```

#### **Deleting a Cookie**

To delete a cookie, set its expiration time to a past time.

```php
<?php
// Deleting a cookie
setcookie("user", "", time() - 3600, "/");  // Set expiry time to 1 hour ago
?>
```

### **2. Sessions in PHP**

#### **What is a Session?**
A **session** allows you to store data across multiple pages in a way that is much more secure than cookies. Session data is stored on the server rather than the client’s browser. PHP automatically handles session IDs via a cookie or URL, and the session data is available as long as the session is active.

#### **Starting a Session**

To start a session in PHP, use the `session_start()` function. It must be called at the beginning of the script (before any HTML or output).

```php
<?php
// Starting a session
session_start();
?>
```

#### **Storing Data in a Session**

Session data is stored in the `$_SESSION` superglobal array.

```php
<?php
// Storing data in session
session_start();
$_SESSION["username"] = "JohnDoe";
$_SESSION["email"] = "john@example.com";
?>
```

#### **Accessing Session Data**

You can access session variables just like any other array in PHP.

```php
<?php
// Accessing session data
session_start();
echo "Welcome, " . $_SESSION["username"];  // Output: Welcome, JohnDoe
echo "Your email is: " . $_SESSION["email"];  // Output: Your email is: john@example.com
?>
```

#### **Modifying Session Data**

You can modify session data by simply assigning a new value to the session variable.

```php
<?php
// Modifying session data
session_start();
$_SESSION["username"] = "JaneDoe";  // Changing the username
?>
```

#### **Deleting Session Data**

To delete specific session variables, you can use `unset()`.

```php
<?php
// Deleting specific session variable
session_start();
unset($_SESSION["username"]);
?>
```

To destroy all session data, use `session_destroy()`. This will delete all session variables and end the session.

```php
<?php
// Destroying the session
session_start();
session_unset();  // Unset all session variables
session_destroy();  // Destroy the session
?>
```

#### **Session Timeout**

PHP sessions are typically designed to last until the user closes their browser, but you can configure session timeouts or expiration by setting session lifetime in your PHP configuration (`php.ini`) or programmatically.

For example, to change the session lifetime:

```php
<?php
// Set session expiration time (e.g., 30 minutes)
ini_set('session.gc_maxlifetime', 1800);  // 1800 seconds = 30 minutes
session_start();
?>
```

You can also check the last activity time and log users out if it’s been too long:

```php
<?php
session_start();

// Set the session timeout period (e.g., 30 minutes)
$timeout_duration = 1800;

if (isset($_SESSION['last_activity']) && (time() - $_SESSION['last_activity']) > $timeout_duration) {
    // Destroy session if it has expired
    session_unset();
    session_destroy();
    header("Location: login.php");  // Redirect to login page after session expiry
    exit();
}

$_SESSION['last_activity'] = time();  // Update last activity time
?>
```

### **When to Use Cookies vs Sessions**

- **Cookies**: Best for storing small pieces of data (like preferences) that need to persist across sessions and be available to the client. Cookies can be easily tampered with, so they should never store sensitive data (like passwords).
- **Sessions**: Best for storing sensitive information, as the data is stored on the server. Sessions are more secure than cookies and should be used for things like user authentication and access control.

### **Example: User Authentication Using Sessions and Cookies**

Here’s a simple example of how you can use sessions and cookies together to remember a logged-in user.

#### **Login Page (login.php)**

```php
<?php
// login.php
session_start();
include('includes/db_connect.php');

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = $_POST['username'];
    $password = $_POST['password'];

    // Query the database for the user
    $sql = "SELECT * FROM users WHERE username = '$username'";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        $user = $result->fetch_assoc();

        // Check if the password is correct
        if (password_verify($password, $user['password'])) {
            $_SESSION['user_id'] = $user['id'];
            $_SESSION['username'] = $user['username'];

            // Set a cookie for "remember me" (optional)
            if (isset($_POST['remember_me'])) {
                setcookie("username", $username, time() + (86400 * 30), "/");
            }

            header("Location: welcome.php");
            exit();
        } else {
            echo "Invalid password.";
        }
    } else {
        echo "No user found.";
    }

    $conn->close();
}
?>

<form method="POST" action="login.php">
    <label for="username">Username:</label>
    <input type="text" name="username" required><br><br>

    <label for="password">Password:</label>
    <input type="password" name="password" required><br><br>

    <input type="checkbox" name="remember_me" /> Remember Me<br><br>

    <button type="submit">Login</button>
</form>
```

#### **Welcome Page (welcome.php)**

```php
<?php
// welcome.php
session_start();

if (!isset($_SESSION['user_id'])) {
    header("Location: login.php");
    exit();
}

echo "Welcome, " . $_SESSION['username'] . "!";
echo "<br><a href='logout.php'>Logout</a>";
?>
```

#### **Logout Page (logout.php)**

```php
<?php
// logout.php
session_start();

// Destroy session
session_unset();
session_destroy();

// Delete cookies (if set)
setcookie("username", "", time() - 3600, "/");

header("Location: login.php");
exit();
?>
```

---

### **Conclusion**

- **Cookies**: Ideal for storing user preferences, authentication tokens, and other non-sensitive data.
- **Sessions**: Ideal for storing sensitive data like login credentials or temporary user information.
  
By understanding and effectively using **cookies** and **sessions**, you can manage state in your web applications, improve user experience, and enhance security.
