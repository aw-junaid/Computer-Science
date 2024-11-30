### PHP - `$_SESSION`

In PHP, **`$_SESSION`** is a superglobal array used to store session variables, which are values that can be maintained across different pages during a user's visit to a website. Session variables are used to store user-specific information, such as login status, user preferences, or shopping cart contents, without the need for storing data on the client's side (as is the case with cookies).

Unlike cookies, which are stored on the client's machine, session data is stored on the server. The server assigns a unique session ID to each user, which is passed back and forth between the client and server using cookies (or URL parameters) to associate the user with their specific session data.

---

### How Sessions Work in PHP

1. **Starting a Session**:
   Before you can store or retrieve session data, you must call `session_start()` at the beginning of your script. This function initializes a session or resumes an existing session based on the session ID passed from the client (usually stored in a cookie).

   ```php
   <?php
   session_start(); // Start or resume the session
   ?>
   ```

2. **Storing Session Variables**:
   Once a session is started, you can store data in the `$_SESSION` superglobal array. Session variables can hold values of any data type, including arrays or objects.

   Example:
   ```php
   <?php
   session_start();
   $_SESSION['username'] = 'john_doe';
   $_SESSION['loggedIn'] = true;
   ?>
   ```

   In this example:
   - The `username` and `loggedIn` values are stored in the session.
   - These values will be available on any page as long as the session is active.

3. **Accessing Session Variables**:
   To access a session variable, simply use the `$_SESSION` array, just like you would with any other associative array.

   Example:
   ```php
   <?php
   session_start();
   echo "Hello, " . $_SESSION['username']; // Outputs: Hello, john_doe
   ?>
   ```

4. **Modifying Session Variables**:
   You can modify session variables by assigning new values to them.

   Example:
   ```php
   <?php
   session_start();
   $_SESSION['username'] = 'jane_doe';  // Modify session variable
   ?>
   ```

5. **Destroying Session Variables**:
   You can remove individual session variables using the `unset()` function.

   Example:
   ```php
   <?php
   session_start();
   unset($_SESSION['username']);  // Remove the 'username' session variable
   ?>
   ```

6. **Destroying the Entire Session**:
   If you want to completely remove all session data (e.g., for logging out a user), you can use `session_destroy()` along with `session_unset()`. However, `session_destroy()` only marks the session for deletion, and you must call `session_unset()` to remove all session variables.

   Example:
   ```php
   <?php
   session_start();
   session_unset();  // Remove all session variables
   session_destroy();  // Destroy the session
   ?>
   ```

---

### Example: Using Sessions for User Login

A typical use case for sessions is handling user authentication, where session variables are used to track whether a user is logged in.

1. **Login Script**:
   This script checks if the user provides correct login credentials and stores their username in the session.

   ```php
   <?php
   session_start();
   
   // Dummy data for demonstration
   $correct_username = "john_doe";
   $correct_password = "password123";
   
   if ($_POST['username'] == $correct_username && $_POST['password'] == $correct_password) {
       $_SESSION['username'] = $correct_username;  // Store username in session
       $_SESSION['loggedIn'] = true;
       header("Location: welcome.php");  // Redirect to the welcome page
       exit();
   } else {
       echo "Invalid credentials!";
   }
   ?>
   ```

2. **Protected Page (e.g., `welcome.php`)**:
   This page checks if the user is logged in by checking the session variable.

   ```php
   <?php
   session_start();
   
   // Check if user is logged in
   if (!isset($_SESSION['username']) || !$_SESSION['loggedIn']) {
       header("Location: login.php");  // Redirect to login page if not logged in
       exit();
   }
   
   echo "Welcome, " . $_SESSION['username'];  // Greet the logged-in user
   ?>
   ```

3. **Logout Script**:
   This script logs the user out by clearing the session.

   ```php
   <?php
   session_start();
   session_unset();  // Remove all session variables
   session_destroy();  // Destroy the session
   header("Location: login.php");  // Redirect to login page
   exit();
   ?>
   ```

---

### Session Configuration in `php.ini`

You can configure session behavior in the `php.ini` file. Some common session-related directives include:

- **`session.save_path`**: Specifies the directory where session files are stored on the server.
- **`session.gc_maxlifetime`**: Defines the maximum lifetime (in seconds) of a session before it is considered garbage and cleaned up.
- **`session.cookie_lifetime`**: Specifies how long the session cookie should last in the user's browser.
- **`session.cookie_secure`**: If set to `true`, the session cookie will only be sent over secure (HTTPS) connections.
- **`session.cookie_httponly`**: If set to `true`, the session cookie will not be accessible via JavaScript.

Example from `php.ini`:

```ini
session.save_path = "/var/lib/php/sessions"
session.gc_maxlifetime = 1440  // Session expires after 24 minutes of inactivity
session.cookie_lifetime = 0  // Cookie lasts until the browser is closed
session.cookie_secure = true  // Send cookie only over HTTPS
session.cookie_httponly = true  // Cookie not accessible via JavaScript
```

---

### Session Security

- **Session Fixation**:
  Session fixation is a security vulnerability where an attacker sets a valid session ID before the user logs in. After the user logs in, the attacker can hijack the session. To mitigate this, you can regenerate the session ID after login:

  ```php
  session_start();
  session_regenerate_id(true);  // Regenerate the session ID after login
  ```

- **Session Hijacking**:
  Session hijacking occurs when an attacker steals the session ID and impersonates the user. To prevent this, use secure cookies (`session.cookie_secure` and `session.cookie_httponly`), and ensure your site uses HTTPS.

- **Session Expiration**:
  To reduce the risk of session hijacking, set an appropriate session timeout. The `session.gc_maxlifetime` setting can control how long sessions are valid. Additionally, you can manually expire sessions after a certain period of inactivity.

---

### Session Example: Tracking User Preferences

```php
<?php
session_start();

// Set a user preference in the session
$_SESSION['theme'] = 'dark';  // The user prefers the dark theme

// Later, access the stored preference
if ($_SESSION['theme'] == 'dark') {
    echo "User prefers dark theme.";
} else {
    echo "User prefers light theme.";
}
?>
```

---

### Summary

- **`$_SESSION`** is a PHP superglobal array used to store session variables.
- Sessions require the `session_start()` function to be called at the beginning of each script where session data is needed.
- Session data is stored on the server, not in cookies, making it more secure for sensitive information.
- Session variables can be used for tracking user authentication, preferences, and other stateful data.
- Sessions can be ended using `session_unset()` and `session_destroy()`.
- Session security is important, so use `session_regenerate_id()`, secure cookies, and appropriate session lifetimes to protect against session fixation and hijacking.
