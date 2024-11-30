### PHP - `$_COOKIE`

In PHP, **`$_COOKIE`** is a superglobal array that is used to access cookies that are sent by the user's browser to the server. Cookies are small pieces of data that are stored on the user's computer and can be used to remember user preferences, login sessions, or any other kind of data across different pages or sessions.

When a cookie is set in PHP, it is sent to the client's browser as part of the HTTP response. Later, on subsequent requests, the browser sends the cookie data back to the server, and PHP makes it accessible via the `$_COOKIE` superglobal array.

---

### How Cookies Work in PHP

1. **Setting a Cookie**:
   Cookies are set using the `setcookie()` function. Once a cookie is set, it is sent to the user's browser and stored there. The cookie will be included in every subsequent request to the same domain until it expires or is deleted.

2. **Accessing a Cookie**:
   After a cookie is set and the user makes a request, PHP can access the cookie using the `$_COOKIE` array. Each cookie is stored in the `$_COOKIE` array by its name as the key.

3. **Cookie Lifespan**:
   Cookies can be set with an expiration time. If no expiration time is provided, the cookie will be a **session cookie**, which will be deleted once the browser is closed.

---

### Syntax for Setting a Cookie

```php
setcookie(name, value, expire, path, domain, secure, httponly);
```

- **`name`**: The name of the cookie (must be a string).
- **`value`**: The value of the cookie (must also be a string).
- **`expire`**: The expiration time of the cookie. This is a Unix timestamp. For example, `time() + 3600` would set the cookie to expire in one hour.
- **`path`**: The path on the server where the cookie will be available (e.g., `/` for the entire site).
- **`domain`**: The domain that the cookie is available to.
- **`secure`**: If set to `true`, the cookie will only be sent over HTTPS connections.
- **`httponly`**: If set to `true`, the cookie will be accessible only through the HTTP protocol (i.e., not available to JavaScript).

---

### Example: Setting a Cookie

```php
<?php
// Set a cookie to store the user's name for 30 days
setcookie("user", "JohnDoe", time() + (30 * 24 * 60 * 60), "/");

// Check if the cookie has been set
if(isset($_COOKIE["user"])) {
    echo "Welcome " . $_COOKIE["user"];
} else {
    echo "Cookie is not set!";
}
?>
```

In this example:
- The cookie is named `user` and contains the value `"JohnDoe"`.
- The cookie is set to expire in 30 days (using `time() + (30 * 24 * 60 * 60)`).
- The cookie will be available for the entire website (`"/"`).
- After setting the cookie, we check if it exists using `isset($_COOKIE['user'])`. If it does, we display the cookie's value.

---

### Accessing a Cookie

After the cookie has been set and the user makes a subsequent request, the cookie value is automatically included in the `$_COOKIE` superglobal array. You can access it as follows:

```php
<?php
// Access the value of the 'user' cookie
if (isset($_COOKIE["user"])) {
    echo "Hello, " . $_COOKIE["user"];
} else {
    echo "Cookie 'user' is not set.";
}
?>
```

In this example:
- We use `$_COOKIE["user"]` to get the value of the `user` cookie.
- If the cookie is set, it will print "Hello, JohnDoe". If not, it will print "Cookie 'user' is not set."

---

### Example: Setting Cookies with Expiry

To create a cookie that expires after 7 days:

```php
<?php
// Set a cookie that expires in 7 days
setcookie("user", "JaneDoe", time() + 7 * 24 * 60 * 60, "/");

// Check if the cookie is set and display it
if (isset($_COOKIE["user"])) {
    echo "User: " . $_COOKIE["user"];
} else {
    echo "Cookie is not set or expired.";
}
?>
```

In this example, the cookie will expire in 7 days. If the cookie has expired, the server will not send the cookie on subsequent requests.

---

### Deleting a Cookie

To delete a cookie, you set the cookie with an expiration time in the past (e.g., `time() - 3600`).

```php
<?php
// Delete the 'user' cookie by setting its expiration to the past
setcookie("user", "", time() - 3600, "/");

// Check if the cookie has been deleted
if (isset($_COOKIE["user"])) {
    echo "User: " . $_COOKIE["user"];
} else {
    echo "Cookie has been deleted.";
}
?>
```

In this example, the cookie named `user` will be deleted because its expiration date is set to one hour in the past.

---

### Cookies and HTTP Headers

- **Important**: Cookies must be set **before any output** is sent to the browser (i.e., before any HTML content). This is because cookies are sent as HTTP headers. If you try to send a cookie after any output, PHP will throw an error like "headers already sent."
  
- **Example Error**: If you try to set a cookie after HTML or any other output:
  ```php
  echo "Hello, World!";  // Output first
  setcookie("user", "JohnDoe");  // Will cause "headers already sent" error
  ```

To fix this, always set cookies before any HTML output or use `ob_start()` to buffer the output.

---

### Cookie Security

- **Secure Cookies**: When setting cookies, you can set the `secure` parameter to `true` if you want the cookie to only be sent over HTTPS connections.
  
  Example:
  ```php
  setcookie("user", "JohnDoe", time() + 3600, "/", "", true, true);
  ```
  In this example:
  - The cookie will only be sent over secure HTTPS connections.
  - The cookie will also be accessible only via HTTP (not JavaScript), making it more secure.

- **HttpOnly Cookies**: The `httponly` flag can prevent JavaScript from accessing the cookie. This is useful to mitigate risks like cross-site scripting (XSS) attacks.

---

### Common Cookie Use Cases

1. **User Authentication**:
   Cookies are widely used for session management, like storing a session ID after login.
   
   ```php
   setcookie("session_id", "abc123", time() + 3600, "/");
   ```

2. **Remember Me Functionality**:
   Store a "remember me" cookie to keep users logged in after they close the browser.
   
   ```php
   setcookie("remember_me", "true", time() + 30 * 24 * 60 * 60, "/");
   ```

3. **User Preferences**:
   Store user preferences like theme choice, language, etc., in cookies.
   
   ```php
   setcookie("theme", "dark", time() + 365 * 24 * 60 * 60, "/");
   ```

4. **Tracking and Analytics**:
   Cookies can be used to track user behavior and preferences across sessions.

---

### Summary

- **`$_COOKIE`** is a PHP superglobal array that allows you to access cookies sent from the client’s browser.
- Cookies are set using the `setcookie()` function, and their values can be accessed using the `$_COOKIE` array.
- Cookies have a name, value, expiration time, and can be scoped to a specific path or domain.
- Cookies are commonly used for session management, remembering user preferences, and storing user authentication data.
- Always set cookies before sending any output to avoid errors, and consider security by using the `secure` and `httponly` flags.

