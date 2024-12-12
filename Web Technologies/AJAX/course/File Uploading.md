### **AJAX - File Uploading**

AJAX provides a way to upload files asynchronously, meaning files can be sent to the server without the need to reload the page. This leads to a smoother user experience because the file is uploaded in the background, allowing users to continue interacting with the page.

In AJAX file uploading, we typically use the `FormData` object to handle the file(s) and send them via an AJAX request. This object simplifies working with form data, including files.

Here's how to implement file uploads using AJAX with `XMLHttpRequest` or `fetch()`.

---

### **1. File Uploading Using `XMLHttpRequest`**

#### **Steps for File Upload:**
1. **Create a form with a file input field**.
2. **Use JavaScript to prevent the default form submission** and trigger an AJAX request instead.
3. **Send the file via `XMLHttpRequest`** using the `FormData` object.
4. **Handle the response from the server** (e.g., success or error).

#### **Example: File Upload with `XMLHttpRequest`**

```html
<form id="uploadForm" enctype="multipart/form-data">
  <label for="file">Choose a file:</label>
  <input type="file" id="file" name="file" required><br><br>
  <button type="submit">Upload</button>
</form>

<div id="response"></div>

<script>
document.getElementById("uploadForm").addEventListener("submit", function(event) {
  event.preventDefault(); // Prevent the default form submission
  
  var formData = new FormData();
  var fileInput = document.getElementById("file");
  
  if (fileInput.files.length > 0) {
    formData.append("file", fileInput.files[0]); // Append the selected file to FormData

    var xhr = new XMLHttpRequest();
    xhr.open("POST", "upload_file.php", true); // Specify server script that will handle the upload
    
    // Define what to do when the request finishes
    xhr.onload = function() {
      if (xhr.status === 200) {
        document.getElementById("response").innerHTML = "File uploaded successfully!";
      } else {
        document.getElementById("response").innerHTML = "Error uploading file!";
      }
    };

    // Define what to do in case of an error
    xhr.onerror = function() {
      document.getElementById("response").innerHTML = "Network error.";
    };
    
    xhr.send(formData); // Send the FormData (which includes the file)
  } else {
    alert("Please select a file.");
  }
});
</script>
```

#### **Explanation**:
- **`FormData()`**: This object is used to construct a set of key/value pairs representing the form fields, including the file input. It automatically handles file data and encodes it correctly.
- **`xhr.onload`**: This event listener is called when the request is successful, and the server responds. You can handle the server's response (e.g., a success message).
- **`xhr.onerror`**: Handles any network errors during the upload.
- **`xhr.send(formData)`**: Sends the form data, including the file, to the server.

### **2. File Uploading Using `fetch()` API**

The `fetch()` API provides a more modern and cleaner way to handle file uploads using JavaScript, especially with its support for promises.

#### **Example: File Upload with `fetch()`**

```html
<form id="uploadForm" enctype="multipart/form-data">
  <label for="file">Choose a file:</label>
  <input type="file" id="file" name="file" required><br><br>
  <button type="submit">Upload</button>
</form>

<div id="response"></div>

<script>
document.getElementById("uploadForm").addEventListener("submit", function(event) {
  event.preventDefault(); // Prevent the default form submission

  var fileInput = document.getElementById("file");
  if (fileInput.files.length > 0) {
    var formData = new FormData();
    formData.append("file", fileInput.files[0]); // Append the selected file

    fetch("upload_file.php", {
      method: "POST",
      body: formData // Send form data (file) via POST request
    })
    .then(response => response.text()) // Convert response to text (could be JSON or other format)
    .then(data => {
      document.getElementById("response").innerHTML = data; // Show response message
    })
    .catch(error => {
      document.getElementById("response").innerHTML = "Error uploading file!";
      console.error("Error:", error); // Log any errors to the console
    });
  } else {
    alert("Please select a file.");
  }
});
</script>
```

#### **Explanation**:
- **`fetch()`**: Sends an AJAX request asynchronously to the server. The body of the request contains the `FormData` object, which includes the file to upload.
- **`.then(response => response.text())`**: Handles the server’s response, assuming it's a text message (could be JSON or other formats).
- **`.catch(error)`**: Catches any errors that occur during the upload process and logs them or displays a message.

### **3. Handling File Upload Progress**

For larger files, it's important to show the upload progress to the user. `XMLHttpRequest` has a built-in method to track upload progress.

#### **Example: File Upload with Progress Bar Using `XMLHttpRequest`**

```html
<form id="uploadForm" enctype="multipart/form-data">
  <label for="file">Choose a file:</label>
  <input type="file" id="file" name="file" required><br><br>
  <button type="submit">Upload</button>
</form>

<div id="response"></div>
<div id="progress">
  <progress id="progressBar" value="0" max="100"></progress>
</div>

<script>
document.getElementById("uploadForm").addEventListener("submit", function(event) {
  event.preventDefault(); // Prevent the default form submission

  var fileInput = document.getElementById("file");
  var progressBar = document.getElementById("progressBar");

  if (fileInput.files.length > 0) {
    var formData = new FormData();
    formData.append("file", fileInput.files[0]); // Append the selected file

    var xhr = new XMLHttpRequest();
    xhr.open("POST", "upload_file.php", true);

    // Track progress of the upload
    xhr.upload.onprogress = function(event) {
      if (event.lengthComputable) {
        var percent = (event.loaded / event.total) * 100;
        progressBar.value = percent; // Update the progress bar
      }
    };

    xhr.onload = function() {
      if (xhr.status === 200) {
        document.getElementById("response").innerHTML = "File uploaded successfully!";
      } else {
        document.getElementById("response").innerHTML = "Error uploading file!";
      }
    };

    xhr.onerror = function() {
      document.getElementById("response").innerHTML = "Network error.";
    };

    xhr.send(formData); // Send the form data (file) to the server
  } else {
    alert("Please select a file.");
  }
});
</script>
```

#### **Explanation**:
- **`xhr.upload.onprogress`**: This event is fired during the file upload process. You can use it to update a progress bar (or any other UI element) based on how much data has been uploaded.
- **`progressBar.value = percent`**: Updates the value of a `<progress>` element to visually indicate how much of the file has been uploaded.

### **4. Handling Multiple File Uploads**

If you need to upload multiple files, you can use the same approach but loop through the selected files and append them to the `FormData` object.

#### **Example: Multiple File Upload Using `FormData` and `fetch()`**

```html
<form id="uploadForm" enctype="multipart/form-data">
  <label for="file">Choose files:</label>
  <input type="file" id="file" name="file" multiple required><br><br>
  <button type="submit">Upload</button>
</form>

<div id="response"></div>

<script>
document.getElementById("uploadForm").addEventListener("submit", function(event) {
  event.preventDefault(); // Prevent default form submission

  var fileInput = document.getElementById("file");
  var formData = new FormData();

  // Loop through all selected files and append them to the FormData
  Array.from(fileInput.files).forEach(function(file) {
    formData.append("files[]", file);
  });

  fetch("upload_file.php", {
    method: "POST",
    body: formData // Send form data (multiple files)
  })
  .then(response => response.text()) // Handle response
  .then(data => {
    document.getElementById("response").innerHTML = data; // Display response message
  })
  .catch(error => {
    document.getElementById("response").innerHTML = "Error uploading files!";
    console.error("Error:", error);
  });
});
</script>
```

#### **Explanation**:
- **`fileInput.files`**: Returns a `FileList` object containing all selected files.
- **`Array.from(fileInput.files)`**: Converts the `FileList` object into an array for easier iteration.


- **`formData.append("files[]", file)`**: Appends each file to the `FormData` object under the name `"files[]"`. On the server side, the files can be accessed via this array notation.

---

### **Conclusion**

AJAX-based file uploading enhances the user experience by allowing files to be uploaded in the background without a page reload. Using `XMLHttpRequest` or `fetch()`, you can:
- Upload single or multiple files asynchronously.
- Provide real-time progress updates for large files.
- Handle server responses dynamically, displaying success or error messages.

This approach enables more interactive and seamless web applications.
