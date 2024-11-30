### PHP - `$_SERVER`

In PHP, **`$_SERVER`** is a superglobal array that contains information about the server environment, headers, paths, and script execution details. It provides a wealth of information related to the server and the HTTP request, which can be useful for a variety of purposes, such as determining request method, accessing headers, or retrieving environment variables.

---

### Commonly Used `$_SERVER` Elements

1. **`$_SERVER['SERVER_NAME']`**  
   - **Description**: The name of the server host under which the current script is executing (e.g., `www.example.com`).
   - **Example**:
     ```php
     echo $_SERVER['SERVER_NAME'];  // Output: www.example.com
     ```

2. **`$_SERVER['SERVER_ADDR']`**  
   - **Description**: The IP address of the server hosting the script.
   - **Example**:
     ```php
     echo $_SERVER['SERVER_ADDR'];  // Output: 192.168.0.1
     ```

3. **`$_SERVER['REQUEST_METHOD']`**  
   - **Description**: The request method used to access the page (e.g., `GET`, `POST`, `PUT`, `DELETE`).
   - **Example**:
     ```php
     echo $_SERVER['REQUEST_METHOD'];  // Output: GET (or POST, depending on the method used)
     ```

4. **`$_SERVER['QUERY_STRING']`**  
   - **Description**: The query string (if any) passed to the script via the URL (everything after `?` in the URL).
   - **Example**:
     ```php
     echo $_SERVER['QUERY_STRING'];  // Output: name=John&age=25
     ```

5. **`$_SERVER['HTTP_USER_AGENT']`**  
   - **Description**: The user agent string sent by the browser (e.g., browser type, operating system).
   - **Example**:
     ```php
     echo $_SERVER['HTTP_USER_AGENT'];  // Output: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36
     ```

6. **`$_SERVER['HTTP_REFERER']`**  
   - **Description**: The URL of the page that referred the user to the current page. It is sent by the browser if the user arrived via a link from another page.
   - **Example**:
     ```php
     echo $_SERVER['HTTP_REFERER'];  // Output: https://www.example.com/page1
     ```

7. **`$_SERVER['REMOTE_ADDR']`**  
   - **Description**: The IP address of the client (user) making the request.
   - **Example**:
     ```php
     echo $_SERVER['REMOTE_ADDR'];  // Output: 192.168.0.100
     ```

8. **`$_SERVER['DOCUMENT_ROOT']`**  
   - **Description**: The document root directory under which the current script is executing.
   - **Example**:
     ```php
     echo $_SERVER['DOCUMENT_ROOT'];  // Output: /var/www/html
     ```

9. **`$_SERVER['SCRIPT_FILENAME']`**  
   - **Description**: The absolute pathname of the currently executing script.
   - **Example**:
     ```php
     echo $_SERVER['SCRIPT_FILENAME'];  // Output: /var/www/html/index.php
     ```

10. **`$_SERVER['SCRIPT_NAME']`**  
    - **Description**: The path of the current script relative to the document root.
    - **Example**:
      ```php
      echo $_SERVER['SCRIPT_NAME'];  // Output: /index.php
      ```

11. **`$_SERVER['REQUEST_URI']`**  
    - **Description**: The URI which was given in order to access the page. This includes the full URL minus the domain (i.e., everything after the domain name).
    - **Example**:
      ```php
      echo $_SERVER['REQUEST_URI'];  // Output: /page1?name=John&age=25
      ```

12. **`$_SERVER['HTTPS']`**  
    - **Description**: A boolean value that indicates whether the request was made using HTTPS (secure protocol).
    - **Example**:
      ```php
      if (isset($_SERVER['HTTPS']) && $_SERVER['HTTPS'] === 'on') {
          echo "Secure connection (HTTPS)";
      } else {
          echo "Non-secure connection (HTTP)";
      }
      ```

---

### Practical Example Using `$_SERVER`

You can use `$_SERVER` to get various details about the request and the server environment.

```php
<?php
echo "Server Name: " . $_SERVER['SERVER_NAME'] . "<br>";
echo "Request Method: " . $_SERVER['REQUEST_METHOD'] . "<br>";
echo "Client IP: " . $_SERVER['REMOTE_ADDR'] . "<br>";
echo "Request URI: " . $_SERVER['REQUEST_URI'] . "<br>";
echo "User Agent: " . $_SERVER['HTTP_USER_AGENT'] . "<br>";
?>
```

#### Output:
```
Server Name: www.example.com
Request Method: GET
Client IP: 192.168.0.100
Request URI: /page1?name=John&age=25
User Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36
```

---

### Security Considerations with `$_SERVER`

While `$_SERVER` is incredibly useful, some of the information it contains, such as the `HTTP_REFERER` or `REMOTE_ADDR`, can be manipulated or spoofed by the client. Therefore, data from `$_SERVER` should always be sanitized or validated before being used, especially when using values that influence security decisions (such as referrer checks or IP-based restrictions).

For example, to avoid relying on potentially spoofed headers like `HTTP_REFERER`, you might implement server-side checks or validate known referers from trusted sources.

---

### Summary

- **`$_SERVER`** provides access to server-related information and HTTP request details such as server name, request method, client IP, and headers.
- It is a powerful tool for handling server-side data and can be used for debugging, logging, or controlling behavior based on the request context.
- Always be cautious of the data, as some values (like `HTTP_REFERER` or `REMOTE_ADDR`) can be spoofed, and should be validated if used for critical security functions.
