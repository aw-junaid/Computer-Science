### PHP - Copying Files

In PHP, you can copy a file using the `copy()` function. This function allows you to duplicate a file from one location to another. It takes the source file as input and the destination where the file should be copied.

### 1. **The `copy()` Function**

The `copy()` function in PHP copies a file from one location to another.

#### Syntax:
```php
copy(string $source, string $destination): bool
```
- **$source**: The path to the source file (the file you want to copy).
- **$destination**: The path where the file will be copied to. This can be a different directory or file name.

#### Example: Basic File Copy

```php
<?php
$source = "source.txt";  // Path to the source file
$destination = "destination.txt";  // Path where the file will be copied

if (copy($source, $destination)) {
    echo "File copied successfully!";
} else {
    echo "Failed to copy the file.";
}
?>
```
- **Explanation**: This script copies the `source.txt` file to a new location called `destination.txt`. If the copy operation is successful, a success message is displayed; otherwise, an error message is shown.

---

### 2. **Copying Files with Different Directories**

You can also copy a file from one directory to another. Just provide the full path to both the source file and the destination directory.

#### Example: Copy to a Different Directory

```php
<?php
$source = "example.txt";
$destination = "backup/example.txt";  // Copying the file to the "backup" directory

if (copy($source, $destination)) {
    echo "File copied to backup directory!";
} else {
    echo "Failed to copy the file.";
}
?>
```
- **Explanation**: This example copies `example.txt` to a directory called `backup`. The destination includes both the directory and the file name.

---

### 3. **Handling Errors**

It’s good practice to check if the source file exists and if the destination is writable before trying to copy a file. You can use functions like `file_exists()` and `is_writable()` to prevent errors.

#### Example: Check if File Exists and Is Writable

```php
<?php
$source = "source.txt";
$destination = "destination.txt";

// Check if the source file exists
if (file_exists($source)) {
    // Check if the destination is writable
    if (is_writable(dirname($destination))) {
        if (copy($source, $destination)) {
            echo "File copied successfully!";
        } else {
            echo "Failed to copy the file.";
        }
    } else {
        echo "Destination is not writable.";
    }
} else {
    echo "Source file does not exist.";
}
?>
```
- **Explanation**: This example first checks if the source file exists and if the destination directory is writable before attempting to copy the file. If any condition is not met, it displays an appropriate error message.

---

### 4. **Copying Files with Renaming**

When copying a file, you can also rename it in the destination directory.

#### Example: Copy and Rename the File

```php
<?php
$source = "example.txt";
$destination = "backup/new_example.txt";  // Renaming the file while copying

if (copy($source, $destination)) {
    echo "File copied and renamed successfully!";
} else {
    echo "Failed to copy the file.";
}
?>
```
- **Explanation**: In this case, `example.txt` is copied to the `backup` directory and renamed as `new_example.txt`.

---

### 5. **Handling Large Files with `copy()`**

If you're copying large files and you want to ensure it doesn't cause memory issues, you can copy the file in smaller chunks using `fopen()`, `fread()`, and `fwrite()`, though `copy()` is typically sufficient for most use cases.

---

### 6. **Permissions Considerations**

When copying files, ensure that both the source file and the destination directory have appropriate permissions:
- The script must have read permissions for the source file.
- The script must have write permissions for the destination directory.

You can check file permissions with `is_readable()` and `is_writable()` to avoid potential issues.

#### Example: Checking Permissions Before Copying

```php
<?php
$source = "source.txt";
$destination = "destination.txt";

// Check if source file is readable and destination directory is writable
if (is_readable($source) && is_writable(dirname($destination))) {
    if (copy($source, $destination)) {
        echo "File copied successfully!";
    } else {
        echo "Failed to copy the file.";
    }
} else {
    echo "Check file or directory permissions.";
}
?>
```

---

### Summary

- **`copy()`**: The main function to copy a file from one location to another.
- **Error Handling**: Check if the file exists and if the destination is writable using `file_exists()` and `is_writable()`.
- **Renaming**: You can rename a file when copying by specifying a new name in the destination path.
- **Permissions**: Ensure proper file and directory permissions for reading and writing before copying a file.
