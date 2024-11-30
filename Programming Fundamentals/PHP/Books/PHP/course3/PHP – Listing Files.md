### PHP – Listing Files

In PHP, you can list the files in a directory using several functions, including `scandir()`, `opendir()`, `readdir()`, and `glob()`. These functions allow you to retrieve files and directories in a specific directory, which can be useful for tasks like displaying directory contents or processing files.

### 1. **Using `scandir()` Function**

The `scandir()` function retrieves an array of filenames from a specified directory. By default, it includes the special directories `.` (current directory) and `..` (parent directory).

#### Syntax:
```php
scandir(string $directory, int $sorting_order = SCANDIR_SORT_ASCENDING): array|false
```
- **$directory**: The path to the directory you want to list.
- **$sorting_order**: Optional. Defines the order of the returned array. You can use `SCANDIR_SORT_ASCENDING`, `SCANDIR_SORT_DESCENDING`, or leave it out for ascending order.

#### Example: Listing Files in a Directory

```php
<?php
$directory = "uploads";  // Directory path

// Get an array of files and directories in the specified path
$files = scandir($directory);

// Display the files in the directory
foreach ($files as $file) {
    echo $file . "<br>";
}
?>
```
- **Explanation**: The `scandir()` function returns an array of all files and directories in the `uploads` folder. The `foreach` loop then displays each item in the directory.

### 2. **Using `opendir()` and `readdir()`**

The `opendir()` function opens a directory, and `readdir()` reads each file or directory in it one by one. This approach is useful when you want to process files without loading all filenames into memory at once.

#### Syntax:
```php
opendir(string $path): resource|false
readdir(resource $dir_handle): string|false
```
- **`opendir()`**: Opens the directory for reading.
- **`readdir()`**: Returns the next entry in the directory or `false` when no more entries are found.

#### Example: Listing Files Using `opendir()` and `readdir()`

```php
<?php
$directory = "uploads";  // Directory path

// Open the directory
if ($handle = opendir($directory)) {

    // Loop through the directory
    while (($file = readdir($handle)) !== false) {
        // Skip current and parent directories ('.' and '..')
        if ($file != "." && $file != "..") {
            echo $file . "<br>";
        }
    }

    // Close the directory handle
    closedir($handle);
}
?>
```
- **Explanation**: The directory is opened using `opendir()`, and the files are read using `readdir()`. The loop continues until `readdir()` returns `false`, indicating no more files are left. The `closedir()` function closes the directory handle.

### 3. **Using `glob()` Function**

The `glob()` function finds pathnames matching a pattern. It is useful if you need to search for files with a specific pattern, such as all `.txt` files or files with a specific prefix.

#### Syntax:
```php
glob(string $pattern, int $flags = 0): array|false
```
- **$pattern**: A pattern to match. You can use wildcard characters like `*` for multiple characters or `?` for a single character.
- **$flags**: Optional flags that modify the behavior of the search.

#### Example: Listing Specific File Types Using `glob()`

```php
<?php
$directory = "uploads";  // Directory path

// Get all .jpg files in the directory
$files = glob($directory . "/*.jpg");

// Display the .jpg files
foreach ($files as $file) {
    echo basename($file) . "<br>";
}
?>
```
- **Explanation**: The `glob()` function returns an array of all `.jpg` files in the `uploads` directory. The `basename()` function is used to extract the filename from the full path.

### 4. **Using `DirectoryIterator` Class**

The `DirectoryIterator` class provides an object-oriented way to iterate through the contents of a directory. It provides various methods for filtering and accessing directory entries.

#### Example: Listing Files Using `DirectoryIterator`

```php
<?php
$directory = "uploads";  // Directory path

// Create a DirectoryIterator object
$iterator = new DirectoryIterator($directory);

// Loop through the directory contents
foreach ($iterator as $fileInfo) {
    // Skip the current (.) and parent (..) directories
    if ($fileInfo->isDot()) {
        continue;
    }
    echo $fileInfo->getFilename() . "<br>";
}
?>
```
- **Explanation**: The `DirectoryIterator` object is created for the `uploads` directory. The `foreach` loop iterates over each file or directory, and `isDot()` checks for the special `.` and `..` directories.

### 5. **Using `scandir()` with Sorting Order**

You can customize the sorting of the returned list of files using the `SCANDIR_SORT_*` constants.

#### Example: Listing Files in Descending Order

```php
<?php
$directory = "uploads";  // Directory path

// Get an array of files in descending order
$files = scandir($directory, SCANDIR_SORT_DESCENDING);

// Display the files
foreach ($files as $file) {
    echo $file . "<br>";
}
?>
```
- **Explanation**: This example uses `scandir()` with the `SCANDIR_SORT_DESCENDING` flag to sort the files in descending order.

### 6. **Listing Files Recursively**

If you want to list files in subdirectories as well, you can use a recursive approach. One way to do this is with a recursive function.

#### Example: Recursively Listing Files

```php
<?php
function listFilesRecursively($directory) {
    // Open the directory
    if ($handle = opendir($directory)) {

        // Loop through the directory
        while (($file = readdir($handle)) !== false) {
            // Skip current and parent directories
            if ($file == "." || $file == "..") {
                continue;
            }

            // Get full path of the file
            $fullPath = $directory . DIRECTORY_SEPARATOR . $file;

            // If it's a directory, recurse
            if (is_dir($fullPath)) {
                listFilesRecursively($fullPath);
            } else {
                echo $fullPath . "<br>";
            }
        }

        // Close the directory handle
        closedir($handle);
    }
}

$directory = "uploads";  // Directory path
listFilesRecursively($directory);  // Call the recursive function
?>
```
- **Explanation**: The function `listFilesRecursively()` recursively lists all files in the specified directory and its subdirectories. It skips the `.` and `..` entries and checks if the current item is a directory, calling the function again if necessary.

---

### Summary

- **`scandir()`**: Retrieves all files and directories in a specified directory and returns them as an array.
- **`opendir()` and `readdir()`**: Open a directory and read its contents one by one.
- **`glob()`**: Matches files in a directory based on a pattern (e.g., `.txt`, `.jpg`).
- **`DirectoryIterator`**: An object-oriented approach to iterating through directory contents.
- **Recursive Listing**: You can list files in subdirectories using a recursive approach.

These functions allow you to list and manipulate files in directories based on your needs in PHP.
