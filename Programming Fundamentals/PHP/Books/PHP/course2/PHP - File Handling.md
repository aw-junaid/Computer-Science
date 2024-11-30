### PHP - File Handling

PHP provides a set of functions to perform file handling operations, allowing you to read from and write to files on the server. These operations are essential when dealing with tasks such as saving user data, creating log files, processing CSV files, or storing user-uploaded content.

The basic file handling operations in PHP include opening, reading, writing, and closing files, as well as checking the status of files and directories.

---

### Common File Handling Functions in PHP

1. **`fopen()`**: Opens a file for reading or writing.
2. **`fclose()`**: Closes an open file.
3. **`fread()`**: Reads data from a file.
4. **`fwrite()`**: Writes data to a file.
5. **`file_get_contents()`**: Reads the entire file into a string.
6. **`file_put_contents()`**: Writes data to a file.
7. **`file_exists()`**: Checks if a file or directory exists.
8. **`is_file()`**: Checks if the given path is a file.
9. **`is_dir()`**: Checks if the given path is a directory.
10. **`unlink()`**: Deletes a file.
11. **`rename()`**: Renames a file or directory.
12. **`filesize()`**: Returns the size of a file in bytes.
13. **`file()`**: Reads a file into an array.

---

### 1. **Opening a File with `fopen()`**

The `fopen()` function is used to open a file. You can open a file for reading, writing, or appending. The second argument to `fopen()` defines the mode in which the file should be opened.

**Syntax**:
```php
fopen(filename, mode);
```

**Common Modes**:
- `'r'`: Open a file for reading (file must exist).
- `'w'`: Open a file for writing (creates a new file or truncates an existing one).
- `'a'`: Open a file for appending (creates a new file if it doesn’t exist).
- `'r+'`: Open a file for reading and writing.
- `'w+'`: Open a file for reading and writing (creates a new file or truncates an existing one).
- `'a+'`: Open a file for reading and appending.

**Example**:
```php
<?php
$file = fopen("example.txt", "w"); // Open file for writing
if ($file) {
    fwrite($file, "Hello, world!"); // Write content to the file
    fclose($file);  // Close the file
}
?>
```

---

### 2. **Reading from a File with `fread()`**

The `fread()` function is used to read a specific number of bytes from an open file. You need to first open the file in read mode before using `fread()`.

**Syntax**:
```php
fread(resource, length);
```
- **resource**: The file resource obtained from `fopen()`.
- **length**: The number of bytes to read.

**Example**:
```php
<?php
$file = fopen("example.txt", "r");  // Open file for reading
if ($file) {
    $content = fread($file, filesize("example.txt"));  // Read entire content
    echo $content;
    fclose($file);  // Close the file
}
?>
```

In this example, `fread()` reads the entire file, and `filesize()` is used to determine the length of the file.

---

### 3. **Writing to a File with `fwrite()`**

The `fwrite()` function writes data to a file. You need to open the file in write or append mode before using this function.

**Syntax**:
```php
fwrite(resource, string);
```
- **resource**: The file resource obtained from `fopen()`.
- **string**: The string to write to the file.

**Example**:
```php
<?php
$file = fopen("example.txt", "w");  // Open file for writing
if ($file) {
    fwrite($file, "This is some text.");  // Write content to the file
    fclose($file);  // Close the file
}
?>
```

In this example, the content "This is some text." is written to the file. If the file already exists, it will be truncated before writing.

---

### 4. **Reading Entire File with `file_get_contents()`**

The `file_get_contents()` function reads the entire contents of a file into a string. It is simpler than using `fopen()` and `fread()` for reading small files.

**Syntax**:
```php
file_get_contents(filename);
```

**Example**:
```php
<?php
$content = file_get_contents("example.txt");
echo $content;
?>
```

This function is useful when you want to quickly retrieve all contents of a file and manipulate it as a string.

---

### 5. **Writing to a File with `file_put_contents()`**

The `file_put_contents()` function writes a string to a file. It can also be used to create a new file or overwrite an existing one. By default, it writes the content in a new file or overwrites the existing file.

**Syntax**:
```php
file_put_contents(filename, data);
```
- **filename**: The name of the file.
- **data**: The data to write to the file.

**Example**:
```php
<?php
file_put_contents("example.txt", "This is the new content.");
?>
```

This will overwrite the contents of `example.txt` with the new string. If the file doesn't exist, it will be created.

---

### 6. **Checking If a File Exists with `file_exists()`**

The `file_exists()` function checks whether a file or directory exists.

**Syntax**:
```php
file_exists(filename);
```

**Example**:
```php
<?php
if (file_exists("example.txt")) {
    echo "The file exists.";
} else {
    echo "The file does not exist.";
}
?>
```

---

### 7. **Deleting a File with `unlink()`**

The `unlink()` function deletes a file. It returns `true` on success and `false` on failure.

**Syntax**:
```php
unlink(filename);
```

**Example**:
```php
<?php
if (unlink("example.txt")) {
    echo "File deleted successfully.";
} else {
    echo "Error deleting file.";
}
?>
```

---

### 8. **Renaming a File with `rename()`**

The `rename()` function renames or moves a file or directory.

**Syntax**:
```php
rename(oldname, newname);
```

**Example**:
```php
<?php
if (rename("oldfile.txt", "newfile.txt")) {
    echo "File renamed successfully.";
} else {
    echo "Error renaming file.";
}
?>
```

---

### 9. **Getting File Size with `filesize()`**

The `filesize()` function returns the size of a file in bytes.

**Syntax**:
```php
filesize(filename);
```

**Example**:
```php
<?php
echo "File size: " . filesize("example.txt") . " bytes.";
?>
```

---

### 10. **Reading a File into an Array with `file()`**

The `file()` function reads a file into an array, where each line of the file is an element in the array.

**Syntax**:
```php
file(filename);
```

**Example**:
```php
<?php
$lines = file("example.txt");
foreach ($lines as $line) {
    echo $line . "<br>";
}
?>
```

---

### File Permissions

When performing file operations, it's important to make sure that the web server has the appropriate permissions to access and modify the file. If a file is read-only, you won't be able to write to it, and if a directory doesn't allow write permissions, you won't be able to create or modify files in it.

You can change file permissions using the `chmod()` function in PHP.

```php
chmod("example.txt", 0644); // Set file permissions (read-write for owner, read-only for others)
```

---

### Summary

- **`fopen()`**: Opens a file for reading, writing, or appending.
- **`fclose()`**: Closes an open file.
- **`fread()`**: Reads data from a file.
- **`fwrite()`**: Writes data to a file.
- **`file_get_contents()`**: Reads the entire file into a string.
- **`file_put_contents()`**: Writes data to a file.
- **`file_exists()`**: Checks if a file exists.
- **`unlink()`**: Deletes a file.
- **`rename()`**: Renames a file or directory.
- **`filesize()`**: Returns the size of a file.
- **`file()`**: Reads a file into an array.

PHP provides a comprehensive set of file handling functions to work with files, from reading and writing to checking and deleting files. Always ensure you have proper file permissions to avoid errors when working with file operations.
