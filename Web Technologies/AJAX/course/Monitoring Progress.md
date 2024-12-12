### **AJAX - Monitoring Progress**

Monitoring progress is crucial in applications that involve sending or receiving large files, such as when uploading images, videos, or large data files. AJAX provides ways to track the progress of these operations using the **`XMLHttpRequest`** object and **`ProgressEvent`**. By monitoring progress, you can provide feedback to the user, such as a progress bar, which improves the user experience.

### **1. Monitoring Progress with `XMLHttpRequest`**

To monitor the progress of a request, you can use the **`onprogress`** event. This event is fired periodically as data is transferred between the client and server.

#### **Example: Monitoring Upload Progress with `XMLHttpRequest`**

```html
<form id="uploadForm">
  <label for="file">Select a file to upload:</label>
  <input type="file" id="file" name="file" required><br><br>
  
  <button type="submit">Upload File</button>
</form>

<div id="response"></div>
<div id="progress">
  <progress id="fileProgress" value="0" max="100"></progress>
  <span id="progressText">0%</span>
</div>

<script>
document.getElementById("uploadForm").addEventListener("submit", function(event) {
  event.preventDefault(); // Prevent default form submission

  var file = document.getElementById("file").files[0]; // Get the selected file
  var formData = new FormData(); // Create a new FormData object
  formData.append("file", file); // Append the file to the FormData object

  var xhr = new XMLHttpRequest(); // Create a new XMLHttpRequest object
  xhr.open("POST", "upload_file.php", true); // Open a POST request

  // Monitor the progress of the file upload
  xhr.upload.onprogress = function(event) {
    if (event.lengthComputable) {
      // Calculate the percentage of the upload completed
      var percent = (event.loaded / event.total) * 100;
      document.getElementById("fileProgress").value = percent; // Update the progress bar
      document.getElementById("progressText").innerText = Math.round(percent) + "%"; // Update the progress text
    }
  };

  // Handle the response from the server
  xhr.onload = function() {
    if (xhr.status === 200) {
      document.getElementById("response").innerHTML = "File uploaded successfully!";
    } else {
      document.getElementById("response").innerHTML = "Error uploading file.";
    }
  };

  xhr.onerror = function() {
    document.getElementById("response").innerHTML = "Network error.";
  };

  // Send the FormData object with the file
  xhr.send(formData);
});
</script>
```

#### **Explanation**:
- **`xhr.upload.onprogress`**: This event is fired periodically as the file is uploaded. The `event` object contains the properties `event.loaded` (bytes uploaded so far) and `event.total` (total size of the file).
- **Progress Calculation**: The percentage of completion is calculated using `event.loaded / event.total * 100` and used to update both the progress bar and the percentage text.
- **`xhr.onload`**: This is called when the request is complete, and you can use it to handle the response, such as confirming a successful upload.

---

### **2. Monitoring Progress with `fetch()`**

The `fetch()` API does not directly support progress monitoring for file uploads or downloads. However, you can achieve progress monitoring with `fetch()` by using the **`ReadableStream`** API (for downloads) or by combining **`FormData`** with `XMLHttpRequest` for uploads, since `fetch()` alone doesn't provide access to upload progress events.

Here's an alternative using **`XMLHttpRequest`** for the upload while using `fetch()` for the response.

---

### **3. Monitoring Download Progress with `XMLHttpRequest`**

Similarly, you can monitor the progress of a file download by using the **`onprogress`** event, but this time, it will be tied to the download stream.

#### **Example: Monitoring Download Progress with `XMLHttpRequest`**

```html
<button id="downloadBtn">Download File</button>

<div id="downloadProgress">
  <progress id="downloadProgressBar" value="0" max="100"></progress>
  <span id="downloadProgressText">0%</span>
</div>

<script>
document.getElementById("downloadBtn").addEventListener("click", function() {
  var xhr = new XMLHttpRequest(); // Create a new XMLHttpRequest object
  xhr.open("GET", "largefile.zip", true); // Open a GET request to the file
  xhr.responseType = "blob"; // Set the response type to blob for file download

  // Monitor the progress of the file download
  xhr.onprogress = function(event) {
    if (event.lengthComputable) {
      var percent = (event.loaded / event.total) * 100; // Calculate download progress
      document.getElementById("downloadProgressBar").value = percent; // Update progress bar
      document.getElementById("downloadProgressText").innerText = Math.round(percent) + "%"; // Update progress text
    }
  };

  // Handle the download when complete
  xhr.onload = function() {
    if (xhr.status === 200) {
      var blob = xhr.response;
      var link = document.createElement("a");
      link.href = URL.createObjectURL(blob); // Create a download link
      link.download = "largefile.zip"; // Set the file name for download
      link.click(); // Trigger download
    } else {
      alert("Download failed.");
    }
  };

  xhr.onerror = function() {
    alert("Network error.");
  };

  // Send the request
  xhr.send();
});
</script>
```

#### **Explanation**:
- **`xhr.onprogress`**: As with uploads, this event tracks the download progress, using `event.loaded` and `event.total` to calculate the percentage downloaded.
- **`xhr.responseType = "blob"`**: This is necessary when downloading binary files, as it instructs `XMLHttpRequest` to treat the response as a blob.
- **`xhr.onload`**: Once the file is fully downloaded, a link is created to download the file locally.

---

### **4. Monitoring Progress with `fetch()` for Download**

`fetch()` does not provide direct progress monitoring, but you can use the **`ReadableStream`** API to achieve this. Here's an example using `fetch()` to download large files with progress tracking.

#### **Example: Monitoring Download Progress with `fetch()`**

```html
<button id="downloadBtn">Download File</button>

<div id="downloadProgress">
  <progress id="downloadProgressBar" value="0" max="100"></progress>
  <span id="downloadProgressText">0%</span>
</div>

<script>
document.getElementById("downloadBtn").addEventListener("click", function() {
  fetch("largefile.zip")
    .then(response => {
      const contentLength = response.headers.get("Content-Length");

      if (!contentLength) {
        console.error("Content-Length not available");
        return;
      }

      const total = parseInt(contentLength, 10);
      let loaded = 0;

      // Create a stream to handle the download progress
      const reader = response.body.getReader();
      const stream = new ReadableStream({
        start(controller) {
          function push() {
            reader.read().then(({ done, value }) => {
              if (done) {
                controller.close();
                return;
              }

              loaded += value.length;
              const percent = (loaded / total) * 100;

              // Update the progress bar and text
              document.getElementById("downloadProgressBar").value = percent;
              document.getElementById("downloadProgressText").innerText = Math.round(percent) + "%";

              controller.enqueue(value);
              push();
            });
          }

          push();
        }
      });

      return new Response(stream);
    })
    .then(response => response.blob())
    .then(blob => {
      const link = document.createElement("a");
      link.href = URL.createObjectURL(blob);
      link.download = "largefile.zip";
      link.click();
    })
    .catch(error => {
      console.error("Error:", error);
    });
});
</script>
```

#### **Explanation**:
- **`fetch()`**: Initiates the request to download the file.
- **`ReadableStream`**: Provides access to the download's progress by reading chunks of the file as they are downloaded.
- **`response.body.getReader()`**: Allows reading the response body in chunks and tracking progress using `loaded` and `total`.
- **Progress Bar**: Updates the download progress as chunks are received.

---

### **Conclusion**

Monitoring progress in AJAX requests is useful for providing feedback to users, especially when uploading or downloading large files. The `XMLHttpRequest` object provides built-in support for progress monitoring, both for uploads and downloads. With `fetch()`, you can achieve progress monitoring for downloads using the `ReadableStream` API, though `fetch()` does not natively support upload progress.

- **Upload Progress**: Use the `xhr.upload.onprogress` event to track file uploads.
- **Download Progress**: Use `xhr.onprogress` or the `ReadableStream` API with `fetch()` for download progress.
  
With progress monitoring, you can show users a progress bar or percentage to improve the experience when dealing with large files.
