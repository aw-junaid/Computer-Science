### MariaDB - SQL Injection Protection

SQL Injection is one of the most common and dangerous vulnerabilities in web applications. It occurs when an attacker is able to manipulate an SQL query by injecting malicious SQL code into an input field, which the application then executes on the database. This can lead to unauthorized access, data leakage, data manipulation, or even complete database destruction.

In this section, we will explore how to protect MariaDB from SQL injection attacks by using best practices and secure coding techniques.

---

### 1. **Use Prepared Statements (Parameterized Queries)**

Prepared statements (also called parameterized queries) are the most effective way to prevent SQL injection. They allow you to define an SQL query with placeholders for parameters, which are later substituted with actual values in a safe manner. The database engine treats these parameters as values, not executable code, so any user input is not executed as part of the query.

#### **Example of Prepared Statements**

Here’s how you can use prepared statements in MariaDB using PHP as an example:

##### **PHP Example:**

```php
<?php
// Create a connection to MariaDB
$conn = new mysqli("localhost", "username", "password", "database");

// Check for errors in connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Prepare the SQL query with placeholders
$stmt = $conn->prepare("SELECT * FROM employees WHERE email = ? AND password = ?");

// Bind the input parameters to the placeholders (s = string)
$stmt->bind_param("ss", $email, $password);

// Set the values of the parameters
$email = $_POST['email'];
$password = $_POST['password'];

// Execute the query
$stmt->execute();

// Get the result
$result = $stmt->get_result();

// Fetch the data
if ($row = $result->fetch_assoc()) {
    echo "Welcome " . $row['name'];
} else {
    echo "Invalid credentials.";
}

// Close the connection
$stmt->close();
$conn->close();
?>
```

In this example:
- The query has placeholders (`?`) for `email` and `password`.
- The user input is bound to these placeholders using `bind_param()`, so it is treated as data rather than executable code.
- This prevents SQL injection, as the input is handled safely by the database.

---

### 2. **Use Stored Procedures**

Stored procedures are another way to mitigate SQL injection risks. A stored procedure is a precompiled collection of one or more SQL statements that can be executed by an application. Since the SQL code is predefined in the database and not dynamically constructed in the application, the chances of SQL injection are minimized.

#### **Example of Stored Procedure:**

```sql
DELIMITER $$

CREATE PROCEDURE GetEmployeeByEmail(IN email_param VARCHAR(255))
BEGIN
    SELECT * FROM employees WHERE email = email_param;
END $$

DELIMITER ;
```

In this case, the stored procedure `GetEmployeeByEmail` takes an email address as an input parameter. Since the query is predefined in the database, and the parameter is passed separately, SQL injection is avoided.

#### **Calling the Stored Procedure:**

```php
<?php
// Create a connection to MariaDB
$conn = new mysqli("localhost", "username", "password", "database");

// Check for errors in connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Call the stored procedure
$email = $_POST['email'];
$sql = "CALL GetEmployeeByEmail(?)";
$stmt = $conn->prepare($sql);
$stmt->bind_param("s", $email);
$stmt->execute();
$result = $stmt->get_result();

// Fetch the data
if ($row = $result->fetch_assoc()) {
    echo "Welcome " . $row['name'];
} else {
    echo "Employee not found.";
}

$stmt->close();
$conn->close();
?>
```

Since the query is encapsulated in a stored procedure, the user input is treated as a parameter, not executable code, thus protecting against SQL injection.

---

### 3. **Escaping User Inputs**

Although using prepared statements and stored procedures is the best approach, sometimes you may need to build dynamic queries. In such cases, you must ensure that user inputs are properly escaped to prevent SQL injection. **Escaping** means adding escape characters to special characters like quotes (`'`), semicolons (`;`), or backslashes (`\`) so that they are treated as data rather than executable SQL code.

#### **Escaping Strings in PHP (mysqli):**

```php
$email = mysqli_real_escape_string($conn, $_POST['email']);
$password = mysqli_real_escape_string($conn, $_POST['password']);
```

The `mysqli_real_escape_string()` function escapes special characters in a string, making it safe for use in an SQL query. However, this method is prone to human error and is less secure than using prepared statements or stored procedures.

---

### 4. **Limit Database Privileges**

SQL injection attacks can have a devastating impact if the database user account has excessive privileges. You should always use the principle of **least privilege** by assigning database users only the permissions they need to perform their specific tasks.

For example:
- If your application only needs to **read** from a database, don't grant it write (`INSERT`, `UPDATE`, `DELETE`) or administrative privileges (`DROP`, `ALTER`).
- Create separate database users with distinct roles for different parts of your application.

#### **Example: Limiting Privileges for a User**

```sql
GRANT SELECT ON my_database.* TO 'read_user'@'localhost' IDENTIFIED BY 'secure_password';
```

This grants the user `read_user` only `SELECT` privileges on the `my_database` database, preventing them from modifying data even if an SQL injection attack is successful.

---

### 5. **Validate and Sanitize User Inputs**

Another important step in preventing SQL injection is validating and sanitizing all user inputs before they are used in SQL queries. Input validation ensures that the input meets expected formats, while sanitization removes any potentially harmful characters.

#### **Example: Input Validation (Email)**

You can validate that the email input is in a valid email format using regular expressions:

```php
if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
    die("Invalid email format");
}
```

#### **Example: Input Sanitization (Removing Special Characters)**

To sanitize inputs, you can remove unwanted characters:

```php
$email = filter_var($_POST['email'], FILTER_SANITIZE_EMAIL);
$password = filter_var($_POST['password'], FILTER_SANITIZE_STRING);
```

While sanitization helps clean the input, **validation** ensures that only properly formatted data is accepted.

---

### 6. **Use Web Application Firewalls (WAFs)**

A Web Application Firewall (WAF) can be used to filter and monitor HTTP requests for potentially malicious input. WAFs can detect and block SQL injection attempts before they reach the MariaDB server.

There are several commercial and open-source WAFs available that provide SQL injection protection by analyzing HTTP requests and blocking known attack patterns.

---

### 7. **Regular Security Audits**

Regularly auditing your application and database for security vulnerabilities is crucial. Use automated tools or conduct manual reviews of your codebase to check for potential SQL injection points. Tools like **OWASP ZAP** (Zed Attack Proxy) or **SQLMap** can help you identify vulnerabilities.

---

### 8. **Error Handling and Logging**

Avoid exposing detailed error messages to end-users. Error messages should not display database details or SQL queries, as these can provide attackers with clues about the structure of your database and vulnerabilities in your code.

#### **Example: Hiding Detailed Error Messages in PHP**

```php
<?php
// Display generic error messages
ini_set('display_errors', 0);
error_reporting(E_ALL);
?>
```

Instead, log detailed errors to a secure location, such as a server log, to monitor for potential attacks.

---

### Conclusion

SQL injection is a serious security risk that can have severe consequences for your application and database. To protect your MariaDB database from SQL injection:

1. **Use prepared statements** (parameterized queries) to safely handle user input.
2. **Use stored procedures** to encapsulate SQL queries and avoid dynamic query construction.
3. **Escape user input** if you must build dynamic queries.
4. **Limit database privileges** to prevent attackers from gaining excessive control over the database.
5. **Validate and sanitize user inputs** to ensure they meet the expected format.
6. Use a **Web Application Firewall (WAF)** to block malicious requests before they reach the database.
7. Regularly **audit your application** for vulnerabilities.
8. Implement **proper error handling** to avoid exposing sensitive information.

By following these best practices, you can significantly reduce the risk of SQL injection attacks and keep your MariaDB database secure.
