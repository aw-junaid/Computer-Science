### PHP - `$_FILES`

In PHP, **`$_FILES`** is a superglobal array that is used to handle file uploads. When a user submits a form with file input fields, the file data is not sent via `$_GET` or `$_POST` but through a special **multipart/form-data** encoding. The `$_FILES` array allows you to access and manage uploaded files.

Each uploaded file's information, such as its name, temporary location, type, size, and any errors during the upload, is stored in the `$_FILES` array.

---

### How `$_FILES` Works

When a form is submitted with a file input field, the file is uploaded to the server and temporarily stored in a special directory. After the upload, the details of the file are available in the `$_FILES` array. This array contains one entry for each file input field in the form.

The data in the `$_FILES` array includes:
- **`name`**: The original name of the uploaded file.
- **`type`**: The MIME type of the uploaded file (e.g., `image/jpeg`).
- **`tmp_name`**: The temporary file name on the server where the uploaded file is stored.
- **`error`**: Any errors that occurred during the upload (e.g., `UPLOAD_ERR_OK` or `UPLOAD_ERR_NO_FILE`).
- **`size`**: The size of the uploaded file in bytes.

---

### Example of Handling File Uploads with `$_FILES`

#### HTML Form (upload_form.php)

```html
<form action="upload.php" method="POST" enctype="multipart/form-data">
    <label for="file">Choose a file:</label>
    <input type="file" id="file" name="file" required><br><br>
    
    <input type="submit" value="Upload File">
</form>
```

#### PHP Script to Handle the File Upload (upload.php)

```php
<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Check if the file is uploaded without any errors
    if (isset($_FILES['file']) && $_FILES['file']['error'] == 0) {
        // Get file details
        $fileName = $_FILES['file']['name'];
        $fileTmpName = $_FILES['file']['tmp_name'];
        $fileSize = $_FILES['file']['size'];
        $fileType = $_FILES['file']['type'];
        
        // Define upload directory
        $uploadDir = 'uploads/';
        
        // Check if the upload directory exists, if not, create it
        if (!is_dir($uploadDir)) {
            mkdir($uploadDir, 0777, true);
        }

        // Define the path to store the uploaded file
        $uploadPath = $uploadDir . basename($fileName);

        // Move the uploaded file from the temporary location to the desired directory
        if (move_uploaded_file($fileTmpName, $uploadPath)) {
            echo "File uploaded successfully: " . htmlspecialchars($fileName) . "<br>";
        } else {
            echo "Error in uploading file.<br>";
        }
    } else {
        echo "No file uploaded or there was an error.<br>";
    }
}
?>
```

---

### Explanation

1. **Form Setup (`enctype="multipart/form-data"`)**: The form needs the `enctype="multipart/form-data"` attribute to properly handle file uploads.
   
2. **Accessing File Data**:
   - `$_FILES['file']` accesses the uploaded file data. The key `'file'` corresponds to the `name` attribute of the file input field in the form.
   - The array `$_FILES['file']` contains multiple values: 
     - `'name'`: The original file name.
     - `'tmp_name'`: The temporary file name (location) where the file is stored on the server.
     - `'size'`: The size of the file in bytes.
     - `'type'`: The MIME type of the file.
     - `'error'`: An error code indicating if there was an issue during the upload (e.g., `UPLOAD_ERR_OK`, `UPLOAD_ERR_INI_SIZE`, etc.).

3. **Error Checking**:
   - You can check for errors during the file upload using the `'error'` key. A value of `0` means the file was uploaded successfully.
   
4. **Storing the File**:
   - The file is stored temporarily in the server's `$_FILES['file']['tmp_name']`.
   - To move the file to a permanent location, you can use the `move_uploaded_file()` function, which takes the temporary file's path (`$_FILES['file']['tmp_name']`) and the destination path as parameters.

---

### Example of `$_FILES` Data

Let's say the user uploads a file called `image.jpg` and the server stores it in a temporary location like `/tmp/php3b9wq2`. After the form is submitted, the `$_FILES['file']` array would look like this:

```php
$_FILES['file'] = [
    'name' => 'image.jpg',
    'type' => 'image/jpeg',
    'tmp_name' => '/tmp/php3b9wq2',
    'error' => 0,
    'size' => 2048000
];
```

- **`name`**: `'image.jpg'` - The original name of the uploaded file.
- **`type`**: `'image/jpeg'` - The MIME type of the file.
- **`tmp_name`**: `'/tmp/php3b9wq2'` - The temporary location of the uploaded file on the server.
- **`error`**: `0` - Indicates that the file was uploaded successfully (no errors).
- **`size`**: `2048000` - The size of the file in bytes (approximately 2 MB).

---

### Common File Upload Errors

The `'error'` key in `$_FILES` can have the following values, indicating different types of upload errors:

- **`UPLOAD_ERR_OK` (0)**: The file was uploaded successfully.
- **`UPLOAD_ERR_INI_SIZE` (1)**: The uploaded file exceeds the `upload_max_filesize` directive in php.ini.
- **`UPLOAD_ERR_FORM_SIZE` (2)**: The uploaded file exceeds the `MAX_FILE_SIZE` directive specified in the HTML form.
- **`UPLOAD_ERR_PARTIAL` (3)**: The file was only partially uploaded.
- **`UPLOAD_ERR_NO_FILE` (4)**: No file was uploaded.
- **`UPLOAD_ERR_NO_TMP_DIR` (6)**: Missing a temporary folder on the server.
- **`UPLOAD_ERR_CANT_WRITE` (7)**: Failed to write file to disk.
- **`UPLOAD_ERR_EXTENSION` (8)**: A PHP extension stopped the file upload.

Example of handling errors:
```php
<?php
if ($_FILES['file']['error'] !== UPLOAD_ERR_OK) {
    echo "Error during file upload: " . $_FILES['file']['error'];
}
?>
```

---

### File Validation

To prevent malicious files from being uploaded, you should validate the file's type, size, and any other relevant properties before processing it. For example:

- **Check the file extension** to ensure it matches the expected types.
- **Check the file size** to ensure it doesn't exceed a maximum size.
- **Check the MIME type** to ensure it is a valid image, video, etc.

```php
<?php
// Example file validation
$allowedTypes = ['image/jpeg', 'image/png'];
$fileType = $_FILES['file']['type'];
$fileSize = $_FILES['file']['size'];

if (!in_array($fileType, $allowedTypes)) {
    echo "Invalid file type.";
    exit;
}

if ($fileSize > 5000000) {  // Max 5MB
    echo "File size exceeds limit.";
    exit;
}
?>
```

---

### Summary

- **`$_FILES`** is a superglobal array used to handle file uploads in PHP.
- The **`$_FILES`** array contains multiple fields (`name`, `type`, `tmp_name`, `error`, `size`) for each uploaded file.
- Use the **`move_uploaded_file()`** function to move the uploaded file from its temporary location to a permanent directory.
- Always **validate** file uploads for security purposes, including checking file types, sizes, and errors.
