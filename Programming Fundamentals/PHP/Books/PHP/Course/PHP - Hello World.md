To create a simple "Hello World" program in PHP, you can follow these steps:

### **1. Basic PHP "Hello World"**
This is the simplest PHP script that prints "Hello World" to the browser.

#### Example:
```php
<?php
  echo "Hello, World!";
?>
```

### **Explanation:**
- `<?php`: This is the opening PHP tag, which tells the server that the following code should be interpreted as PHP.
- `echo`: This is a PHP function used to output or print data to the screen. In this case, it prints the string `"Hello, World!"`.
- `?>`: This is the closing PHP tag, which marks the end of the PHP code. This tag is optional if the PHP code is at the end of the file, but it's good practice to include it.

### **2. PHP "Hello World" within HTML**
You can also embed PHP code within an HTML document to display the "Hello World" message on a webpage.

#### Example:
```php
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Hello World</title>
</head>
<body>
    <h1><?php echo "Hello, World!"; ?></h1>
</body>
</html>
```

### **Explanation:**
- This code combines HTML with PHP. The `<?php echo "Hello, World!"; ?>` is used inside the `<h1>` tag to print the message "Hello, World!" on the webpage.
- The HTML structure creates a webpage with a heading that displays the output of the PHP code.

### **Running the PHP Script**
To run a PHP script locally, you need:
1. A web server (like **Apache** or **Nginx**) with PHP installed, or use a built-in PHP server.
2. Save your PHP file with a `.php` extension (e.g., `hello_world.php`).
3. Access the file through the browser using `http://localhost/hello_world.php`.

#### Using the Built-in PHP Development Server:
If you have PHP installed, you can quickly run a PHP server from the command line:
1. Navigate to the folder containing your PHP file.
2. Run this command:
   ```bash
   php -S localhost:8000
   ```
3. Open your browser and go to `http://localhost:8000/hello_world.php` to see the output.

This will display "Hello, World!" on your browser.
