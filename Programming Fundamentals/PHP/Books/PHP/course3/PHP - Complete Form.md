### PHP – Complete Form Handling

A complete form in PHP involves creating a form in HTML, handling the form submission, validating the input, and then either displaying the data, storing it, or redirecting the user to another page. Below is a step-by-step guide for building and handling a form in PHP, including validation and displaying the submitted information.

---

### Steps to Create a Complete PHP Form:

1. **Create the HTML Form**
2. **Process the Form with PHP**
3. **Validate the Form Data**
4. **Display Submitted Data or Handle Errors**

---

### 1. **Create the HTML Form**

Here’s an example of an HTML form with input fields for a name, email, and message:

```html
<form method="POST" action="">
    <label for="name">Name:</label>
    <input type="text" name="name" id="name">
    <br><br>

    <label for="email">Email:</label>
    <input type="email" name="email" id="email">
    <br><br>

    <label for="message">Message:</label>
    <textarea name="message" id="message"></textarea>
    <br><br>

    <input type="submit" value="Submit">
</form>
```

**Explanation:**
- The `method="POST"` means the form will send the data to the same page.
- The `action=""` ensures that the form submits to itself.
- The `name` attribute is used to identify each form field.

---

### 2. **Process the Form with PHP**

Once the form is submitted, PHP processes the form data using `$_POST` to collect the form values. Here’s how we handle the form in PHP.

```php
<?php
// Check if form is submitted
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Collect and sanitize form data
    $name = sanitize_input($_POST['name']);
    $email = sanitize_input($_POST['email']);
    $message = sanitize_input($_POST['message']);

    // Form validation
    $errors = [];

    // Validate name
    if (empty($name)) {
        $errors[] = "Name is required.";
    }

    // Validate email
    if (empty($email)) {
        $errors[] = "Email is required.";
    } elseif (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        $errors[] = "Invalid email format.";
    }

    // Validate message
    if (empty($message)) {
        $errors[] = "Message is required.";
    }

    // If no errors, process the form
    if (empty($errors)) {
        echo "Form submitted successfully!<br>";
        echo "Name: " . $name . "<br>";
        echo "Email: " . $email . "<br>";
        echo "Message: " . $message . "<br>";
    } else {
        // Display errors
        foreach ($errors as $error) {
            echo $error . "<br>";
        }
    }
}

// Function to sanitize input data
function sanitize_input($data) {
    return htmlspecialchars(stripslashes(trim($data)));
}
?>
```

**Explanation:**
- **`$_SERVER["REQUEST_METHOD"] == "POST"`**: Checks if the form is submitted using POST.
- **`sanitize_input()`**: A custom function to clean the data by trimming spaces, removing slashes, and converting special characters to HTML entities to avoid XSS attacks.
- **Validation**: The form data is validated for required fields and proper email format.
- **Error handling**: If there are validation errors, they are displayed on the page. If no errors are found, the form is processed, and the data is displayed.

---

### 3. **Form Validation**

Form validation is crucial to ensure that the data provided is in the expected format. The PHP code checks:
- If the name is provided.
- If the email is provided and in a valid email format using `filter_var()` with the `FILTER_VALIDATE_EMAIL` filter.
- If the message is not empty.

If any of the fields fail validation, an error message is displayed, and the form is not processed until the errors are corrected.

---

### 4. **Display Submitted Data or Handle Errors**

When the form is successfully submitted without errors, the PHP code will display the submitted data. If there are validation errors, they are displayed below the form so the user can fix them.

---

### Full Example: Complete PHP Form with Validation and Display

```php
<?php
// Check if the form is submitted
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Collect and sanitize input data
    $name = sanitize_input($_POST['name']);
    $email = sanitize_input($_POST['email']);
    $message = sanitize_input($_POST['message']);
    
    // Initialize an array to store validation errors
    $errors = [];

    // Validate name
    if (empty($name)) {
        $errors[] = "Name is required.";
    }

    // Validate email
    if (empty($email)) {
        $errors[] = "Email is required.";
    } elseif (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        $errors[] = "Invalid email format.";
    }

    // Validate message
    if (empty($message)) {
        $errors[] = "Message is required.";
    }

    // If no errors, process the form
    if (empty($errors)) {
        // Form is successfully validated
        echo "<h2>Form Submitted Successfully!</h2>";
        echo "<b>Name:</b> " . $name . "<br>";
        echo "<b>Email:</b> " . $email . "<br>";
        echo "<b>Message:</b> " . nl2br($message) . "<br>";
    } else {
        // Display errors
        echo "<h3>Errors:</h3>";
        foreach ($errors as $error) {
            echo $error . "<br>";
        }
    }
}

// Function to sanitize input data
function sanitize_input($data) {
    return htmlspecialchars(stripslashes(trim($data)));
}
?>

<!-- HTML Form -->
<form method="POST" action="">
    <label for="name">Name:</label>
    <input type="text" name="name" id="name" value="<?php echo isset($name) ? $name : ''; ?>"><br><br>

    <label for="email">Email:</label>
    <input type="email" name="email" id="email" value="<?php echo isset($email) ? $email : ''; ?>"><br><br>

    <label for="message">Message:</label>
    <textarea name="message" id="message"><?php echo isset($message) ? $message : ''; ?></textarea><br><br>

    <input type="submit" value="Submit">
</form>
```

### Explanation:
- **Displaying Form Data**: After form submission, if no validation errors are present, the name, email, and message entered by the user are displayed back to them. This ensures that the form data is processed and presented to the user.
- **Error Handling**: If any required field is missing or invalid, the corresponding error message is displayed, and the user is prompted to correct their input.
- **Data Persistence**: After form submission, the previously entered data is repopulated in the form fields so the user doesn't need to re-enter everything if they need to correct errors.

---

### Conclusion

This example demonstrates a complete form handling process in PHP. It covers:
- Creating the form in HTML.
- Validating the form data in PHP.
- Sanitizing the data to prevent XSS.
- Displaying validation errors and successfully submitted data.

Form handling with PHP is fundamental to collecting and processing user input securely and efficiently. By validating and sanitizing the data, you ensure the integrity of your application.
