### PHP – Create Directory

In PHP, you can create directories using the `mkdir()` function. This function creates a new directory on the file system, and you can specify the permissions, as well as whether you want to create nested directories.

### 1. **Creating a Directory Using `mkdir()`**

#### Syntax:
```php
mkdir(string $pathname, int $mode = 0777, bool $recursive = false, int $context = null): bool
```

- **$pathname**: The path to the directory you want to create.
- **$mode**: The permissions for the new directory. It is an optional parameter and defaults to `0777`. You can specify permissions as a 3-digit number (octal format).
- **$recursive**: A boolean value. If set to `true`, PHP will create any parent directories that do not exist (recursively). The default value is `false`.
- **$context**: Optional. A valid stream context resource. If you're not using streams, you can omit this parameter.

### 2. **Basic Example: Creating a Simple Directory**

```php
<?php
$directory = "new_folder";  // Directory path

// Create the directory with default permissions (0777)
if (mkdir($directory)) {
    echo "Directory created successfully!";
} else {
    echo "Failed to create directory.";
}
?>
```
- **Explanation**: This example attempts to create a directory called `new_folder` in the current working directory. If successful, a success message is displayed.

---

### 3. **Creating a Directory with Custom Permissions**

You can also specify custom permissions for the directory using the `mode` parameter.

```php
<?php
$directory = "new_folder";  // Directory path

// Create the directory with permissions 0755 (rwxr-xr-x)
if (mkdir($directory, 0755)) {
    echo "Directory created successfully with 0755 permissions.";
} else {
    echo "Failed to create directory.";
}
?>
```
- **Explanation**: The directory is created with `0755` permissions, which means:
  - **Owner**: Read, write, and execute.
  - **Group**: Read and execute.
  - **Others**: Read and execute.

---

### 4. **Creating Nested Directories Using `recursive` Parameter**

To create a directory and any necessary parent directories, set the `recursive` parameter to `true`.

```php
<?php
$directory = "parent_folder/sub_folder";  // Nested directory path

// Create nested directories (parent_folder and sub_folder)
if (mkdir($directory, 0777, true)) {
    echo "Nested directories created successfully!";
} else {
    echo "Failed to create nested directories.";
}
?>
```
- **Explanation**: This example creates both `parent_folder` and `sub_folder` if they don't already exist. The `recursive` parameter ensures that all required parent directories are created.

---

### 5. **Checking If a Directory Exists Before Creating It**

It’s a good practice to check if the directory already exists to avoid errors.

```php
<?php
$directory = "new_folder";  // Directory path

// Check if the directory exists
if (!is_dir($directory)) {
    // Create the directory if it doesn't exist
    if (mkdir($directory, 0755)) {
        echo "Directory created successfully!";
    } else {
        echo "Failed to create directory.";
    }
} else {
    echo "Directory already exists.";
}
?>
```
- **Explanation**: This script checks whether the directory already exists using `is_dir()`. If it doesn't, it creates the directory. If it exists, a message is displayed.

---

### 6. **Error Handling**

You can use `error_get_last()` to retrieve the last error message if `mkdir()` fails.

```php
<?php
$directory = "new_folder";

// Try to create the directory
if (!mkdir($directory, 0755)) {
    // Retrieve and display the last error message
    echo "Failed to create directory: " . print_r(error_get_last(), true);
}
?>
```
- **Explanation**: If `mkdir()` fails, `error_get_last()` returns the last error message, which can help diagnose the issue (such as insufficient permissions).

---

### 7. **File Permissions**

After creating a directory, you might want to adjust its permissions. You can use `chmod()` to modify the directory's permissions.

```php
<?php
$directory = "new_folder";

// Create the directory with default permissions
if (mkdir($directory)) {
    // Set custom permissions (e.g., 0777)
    chmod($directory, 0777);
    echo "Directory created with custom permissions!";
} else {
    echo "Failed to create directory.";
}
?>
```
- **Explanation**: After the directory is created, `chmod()` sets the permissions to `0777`.

---

### Summary

- **`mkdir()`**: Use this function to create a new directory in PHP.
- **Custom Permissions**: You can specify the permissions with the `mode` parameter.
- **Nested Directories**: Use the `recursive` parameter to create nested directories.
- **Existence Check**: Always check if the directory already exists to avoid overwriting.
- **Error Handling**: Use `error_get_last()` to capture errors if the directory creation fails.

By understanding these options, you can efficiently create directories in PHP while managing permissions and handling errors.
