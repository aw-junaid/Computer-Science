### PHP - Deleting Files

In PHP, you can delete a file using the `unlink()` function. This function removes a file from the filesystem. If the file does not exist or cannot be deleted (e.g., due to insufficient permissions), it will return `false`.

### 1. **The `unlink()` Function**

The `unlink()` function is used to delete a file in PHP.

#### Syntax:
```php
unlink(string $filename): bool
```
- **$filename**: The path to the file that you want to delete.

#### Example: Basic File Deletion

```php
<?php
$file = "example.txt";  // Path to the file to be deleted

// Check if the file exists before attempting to delete it
if (file_exists($file)) {
    if (unlink($file)) {
        echo "File deleted successfully!";
    } else {
        echo "Failed to delete the file.";
    }
} else {
    echo "The file does not exist.";
}
?>
```
- **Explanation**:
  - The script checks if the file exists using `file_exists()`.
  - If the file exists, it proceeds to delete the file using `unlink()`.
  - If the deletion is successful, a success message is displayed; otherwise, an error message is shown.

---

### 2. **Deleting a File Without Checking Existence**

You can also delete a file without explicitly checking if it exists, but this is less safe, as it can produce errors or unexpected behavior if the file doesn’t exist.

#### Example: Without Existence Check

```php
<?php
$file = "example.txt";  // Path to the file to be deleted

// Attempt to delete the file
if (unlink($file)) {
    echo "File deleted successfully!";
} else {
    echo "Failed to delete the file.";
}
?>
```
- **Explanation**:
  - This approach does not check if the file exists before calling `unlink()`. If the file doesn't exist or is not deletable, `unlink()` will return `false`.

---

### 3. **Deleting Files in Directories**

You can delete files from any directory, as long as the PHP script has permission to do so. When specifying the file path, include the full path or the relative path from the script.

#### Example: Delete a File in a Subdirectory

```php
<?php
$file = "uploads/example.txt";  // Path to the file in a subdirectory

// Attempt to delete the file
if (unlink($file)) {
    echo "File deleted successfully!";
} else {
    echo "Failed to delete the file.";
}
?>
```
- **Explanation**: This example shows how to delete a file located in a subdirectory (`uploads/`).

---

### 4. **Deleting Multiple Files**

You can delete multiple files by looping through an array of file paths and calling `unlink()` for each file.

#### Example: Deleting Multiple Files

```php
<?php
$files = ["file1.txt", "file2.txt", "file3.txt"];  // Array of files to delete

// Loop through each file and attempt to delete it
foreach ($files as $file) {
    if (file_exists($file)) {
        if (unlink($file)) {
            echo "$file deleted successfully!<br>";
        } else {
            echo "Failed to delete $file.<br>";
        }
    } else {
        echo "$file does not exist.<br>";
    }
}
?>
```
- **Explanation**:
  - This example loops through an array of files (`$files`) and attempts to delete each one.
  - If the file exists, it will be deleted, and a success message will be shown.
  - If the file doesn’t exist, an appropriate message is displayed.

---

### 5. **Check File Permissions Before Deleting**

Before attempting to delete a file, it's a good idea to check if the file is writable using the `is_writable()` function, as PHP cannot delete files it doesn't have permission to modify.

#### Example: Check Permissions Before Deleting

```php
<?php
$file = "example.txt";  // Path to the file to be deleted

// Check if the file exists and is writable
if (file_exists($file) && is_writable($file)) {
    if (unlink($file)) {
        echo "File deleted successfully!";
    } else {
        echo "Failed to delete the file.";
    }
} else {
    echo "The file does not exist or is not writable.";
}
?>
```
- **Explanation**:
  - This code checks if the file exists and if it is writable using `is_writable()`.
  - If both conditions are met, the script attempts to delete the file using `unlink()`.
  - If the file doesn't exist or isn't writable, an error message is shown.

---

### 6. **Deleting a File with `file_exists()`**

Although the `unlink()` function itself doesn't throw errors for non-existent files, it is a good practice to check for the file's existence beforehand.

#### Example: Check Existence and Delete

```php
<?php
$file = "example.txt";  // Path to the file to be deleted

if (file_exists($file)) {
    unlink($file);
    echo "File deleted successfully!";
} else {
    echo "File does not exist.";
}
?>
```
- **Explanation**: This example ensures that the file exists before calling `unlink()` to delete it.

---

### 7. **Deleting Files with Absolute Paths**

You can also delete files using absolute paths, especially when working with files outside of your script’s directory.

#### Example: Absolute Path Deletion

```php
<?php
$file = "/var/www/html/uploads/example.txt";  // Absolute path to the file

if (unlink($file)) {
    echo "File deleted successfully!";
} else {
    echo "Failed to delete the file.";
}
?>
```
- **Explanation**: In this example, the file is located using its absolute path, and `unlink()` is used to delete it.

---

### Summary

- **`unlink()`**: The main function to delete a file in PHP.
- **Check for Existence**: It’s a good idea to check if the file exists using `file_exists()` before attempting to delete it.
- **Permissions**: Ensure the file is writable and the script has proper permissions to delete the file.
- **Multiple Files**: You can delete multiple files by looping through an array of file paths.
