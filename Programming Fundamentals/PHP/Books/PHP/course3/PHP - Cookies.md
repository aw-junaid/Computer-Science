### PHP - Cookies

In PHP, **cookies** are small pieces of data stored on the client’s browser. They can be used to store information that is accessible between different page requests, such as user preferences, session information, or other data. Cookies have an expiration date and are sent to the server with every HTTP request.

---

### 1. **Setting Cookies in PHP**

To set a cookie, you can use the `setcookie()` function. The `setcookie()` function must be called before any HTML or other output is sent to the browser.

#### Syntax of `setcookie()`:

```php
setcookie(name, value, expire, path, domain, secure, httponly);
```

- **name**: The name of the cookie.
- **value**: The value of the cookie.
- **expire**: The expiration date of the cookie (in Unix timestamp format). If not set, the cookie will expire when the browser is closed.
- **path**: The path on the server where the cookie will be available (default is the current directory).
- **domain**: The domain that the cookie is available to (default is the current domain).
- **secure**: If `true`, the cookie will only be sent over HTTPS connections.
- **httponly**: If `true`, the cookie will be accessible only via HTTP(S), not through JavaScript (increased security).

#### Example: Setting a Cookie

```php
// Set a cookie that expires in 1 hour
setcookie("user", "John Doe", time() + 3600, "/");

// Set a cookie with secure and HttpOnly flags
setcookie("secure_user", "John Doe", time() + 3600, "/", "", true, true);
```

- In this example, the cookie `user` is set with a value `"John Doe"`, and it will expire in 1 hour (3600 seconds). It will be available to all pages in the domain (`"/"`).
- The second cookie, `secure_user`, has the `secure` and `httponly` flags enabled, which increases security.

---

### 2. **Accessing Cookies in PHP**

To access the value of a cookie, you can use the `$_COOKIE` superglobal array.

#### Example: Accessing a Cookie

```php
if (isset($_COOKIE["user"])) {
    echo "Hello, " . $_COOKIE["user"];
} else {
    echo "Cookie 'user' is not set!";
}
```

- `$_COOKIE['user']` retrieves the value of the cookie named `user`.

---

### 3. **Deleting Cookies in PHP**

To delete a cookie, you can set its expiration date to a time in the past (i.e., before the current time). This effectively tells the browser to remove the cookie.

#### Example: Deleting a Cookie

```php
// Delete a cookie by setting its expiration time in the past
setcookie("user", "", time() - 3600, "/");
```

- In this example, the cookie `user` is deleted by setting its expiration time to 1 hour ago (`time() - 3600`).

---

### 4. **Cookie Expiration**

The expiration of a cookie is controlled using the `expire` parameter in the `setcookie()` function. This is specified in the form of a Unix timestamp (i.e., the number of seconds since January 1, 1970). You can calculate this using `time()` (the current timestamp) and adding the desired number of seconds for the expiration time.

#### Example: Set a Cookie with a 7-day Expiration

```php
// Set cookie to expire in 7 days
setcookie("user", "John Doe", time() + (7 * 24 * 60 * 60), "/"); // 7 days
```

- This cookie will expire 7 days from the time it's set.

---

### 5. **Cookie Path and Domain**

- **Path**: Specifies the directory or path on the server to which the cookie will be available. If you set `/`, the cookie will be available across the entire website.
- **Domain**: Specifies the domain for which the cookie is valid. If you set `example.com`, the cookie will be sent only to `example.com` and its subdomains.

Example:

```php
// Set a cookie that is available for the entire domain
setcookie("user", "John Doe", time() + 3600, "/", "example.com");
```

- The cookie `user` will be sent to the server only for `example.com` and its subdomains.

---

### 6. **Secure Cookies**

If your website uses HTTPS, you can set the `secure` flag to `true` when setting a cookie. This ensures the cookie is only sent over secure HTTPS connections.

```php
// Set a secure cookie (only sent over HTTPS)
setcookie("secure_user", "John Doe", time() + 3600, "/", "", true);
```

- In this case, the cookie `secure_user` will only be sent over HTTPS, ensuring it is not transmitted over an unsecured HTTP connection.

---

### 7. **HttpOnly Cookies**

Setting the `httponly` flag to `true` ensures that the cookie is only accessible by the server, and not by JavaScript running in the browser. This is a security feature that helps prevent attacks such as cross-site scripting (XSS).

```php
// Set an HttpOnly cookie
setcookie("http_only_user", "John Doe", time() + 3600, "/", "", true, true);
```

- This cookie cannot be accessed by JavaScript (i.e., `document.cookie`), which helps mitigate security risks.

---

### 8. **Limitations of Cookies**

- **Size Limit**: Cookies are limited to 4 KB in size, so they are not suitable for storing large amounts of data.
- **Visibility**: Cookies are visible to both the client and the server, which could expose sensitive information unless properly encrypted.
- **Security**: Cookies can be hijacked or modified by malicious actors if not properly secured, particularly over insecure HTTP connections. Always use `secure` and `httponly` flags for sensitive data.

---

### 9. **Cookie Example: User Authentication**

Here’s an example of using cookies to remember a user’s login status:

```php
// Set cookie on login
setcookie("username", "JohnDoe", time() + 3600, "/", "", false, true);

// Check if the cookie is set
if (isset($_COOKIE["username"])) {
    echo "Welcome back, " . $_COOKIE["username"];
} else {
    echo "Please log in.";
}
```

- If the user logs in, their username is stored in a cookie. On subsequent visits, the application checks for this cookie and greets the user.

---

### Conclusion

Cookies in PHP provide a simple mechanism for storing data on the client-side and can be used for various purposes, including user authentication, session management, and user preferences. However, care must be taken to secure cookies by using the `secure` and `httponly` flags and limiting sensitive data stored in cookies.
