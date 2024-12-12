### **AJAX - Examples**

Here are several examples demonstrating how AJAX is used to handle different tasks such as fetching data from the server, submitting forms, updating content dynamically, and working with JSON and other formats.

---

### **1. Basic AJAX GET Request**
This simple example demonstrates how to use AJAX to send a GET request to the server and retrieve data asynchronously.

#### **Example: Fetching Data from the Server**
```javascript
var xhr = new XMLHttpRequest();
xhr.open("GET", "data.json", true); // Open a GET request for the data.json file
xhr.onreadystatechange = function() {
  if (xhr.readyState === 4 && xhr.status === 200) {
    var data = JSON.parse(xhr.responseText); // Parse the JSON response
    console.log(data); // Display the response in the console
  }
};
xhr.send(); // Send the request
```

---

### **2. Sending Data with POST Request**
In this example, we use AJAX to send form data to the server without reloading the page using a POST request.

#### **Example: Sending Form Data to the Server**
```javascript
var xhr = new XMLHttpRequest();
xhr.open("POST", "submit-form.php", true); // Open a POST request
xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded"); // Set content type for form data
xhr.onreadystatechange = function() {
  if (xhr.readyState === 4 && xhr.status === 200) {
    var response = JSON.parse(xhr.responseText); // Parse the server response
    if (response.success) {
      alert("Form submitted successfully!");
    } else {
      alert("Error: " + response.error);
    }
  }
};
xhr.send("name=JohnDoe&email=john@example.com&message=Hello"); // Send the form data
```

---

### **3. Updating Content Dynamically**
This example demonstrates how AJAX can be used to update parts of a web page dynamically without reloading the entire page.

#### **Example: Dynamically Loading Content**
```javascript
var xhr = new XMLHttpRequest();
xhr.open("GET", "latest-articles.html", true); // Request new content (HTML file)
xhr.onreadystatechange = function() {
  if (xhr.readyState === 4 && xhr.status === 200) {
    document.getElementById("content").innerHTML = xhr.responseText; // Update the page content
  }
};
xhr.send(); // Send the request
```

---

### **4. JSON Request and Response**
AJAX is frequently used to send and receive JSON data. This example fetches a JSON object from the server and processes it in the browser.

#### **Example: Fetching JSON Data**
```javascript
var xhr = new XMLHttpRequest();
xhr.open("GET", "data.json", true); // Request JSON data
xhr.onreadystatechange = function() {
  if (xhr.readyState === 4 && xhr.status === 200) {
    var data = JSON.parse(xhr.responseText); // Parse the JSON response
    console.log(data); // Log the parsed JSON object
  }
};
xhr.send(); // Send the request
```

---

### **5. Submitting Forms Without Page Reload**
This example uses AJAX to submit a form asynchronously and display the result on the same page.

#### **Example: Async Form Submission**
```html
<!-- HTML Form -->
<form id="myForm">
  <input type="text" id="username" name="username" placeholder="Enter username" required>
  <input type="email" id="email" name="email" placeholder="Enter email" required>
  <button type="submit">Submit</button>
</form>
<div id="result"></div>

<script>
document.getElementById("myForm").addEventListener("submit", function(event) {
  event.preventDefault(); // Prevent form submission
  var xhr = new XMLHttpRequest();
  xhr.open("POST", "submit-form.php", true);
  xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
  xhr.onreadystatechange = function() {
    if (xhr.readyState === 4 && xhr.status === 200) {
      var response = xhr.responseText;
      document.getElementById("result").innerHTML = response; // Show the result in the 'result' div
    }
  };
  var formData = new FormData(document.getElementById("myForm"));
  xhr.send(new URLSearchParams(formData).toString()); // Send the form data
});
</script>
```

---

### **6. Autocomplete/Search Suggestions**
This example shows how AJAX can be used to implement a live search feature where search suggestions are displayed as the user types.

#### **Example: Autocomplete Search**
```html
<input type="text" id="searchBox" placeholder="Search...">
<ul id="suggestionsList"></ul>

<script>
document.getElementById("searchBox").addEventListener("input", function() {
  var query = this.value;
  if (query.length > 2) { // Start search after 3 characters
    var xhr = new XMLHttpRequest();
    xhr.open("GET", "search-suggestions.php?q=" + query, true);
    xhr.onreadystatechange = function() {
      if (xhr.readyState === 4 && xhr.status === 200) {
        var suggestions = JSON.parse(xhr.responseText); // Parse the JSON response
        var suggestionsList = document.getElementById("suggestionsList");
        suggestionsList.innerHTML = ""; // Clear previous suggestions
        suggestions.forEach(function(suggestion) {
          var li = document.createElement("li");
          li.textContent = suggestion;
          suggestionsList.appendChild(li);
        });
      }
    };
    xhr.send(); // Send the search query to the server
  }
});
</script>
```

---

### **7. Handling File Upload with Progress**
This example shows how AJAX can be used to handle file uploads with a progress bar.

#### **Example: File Upload with Progress Bar**
```html
<form id="uploadForm">
  <input type="file" id="fileInput" name="file">
  <button type="submit">Upload</button>
</form>
<div id="progress"></div>

<script>
document.getElementById("uploadForm").addEventListener("submit", function(event) {
  event.preventDefault(); // Prevent default form submission
  var formData = new FormData();
  formData.append("file", document.getElementById("fileInput").files[0]);

  var xhr = new XMLHttpRequest();
  xhr.open("POST", "upload-file.php", true);

  // Show progress
  xhr.upload.onprogress = function(event) {
    if (event.lengthComputable) {
      var percent = (event.loaded / event.total) * 100;
      document.getElementById("progress").innerText = "Progress: " + percent.toFixed(2) + "%";
    }
  };

  xhr.onreadystatechange = function() {
    if (xhr.readyState === 4 && xhr.status === 200) {
      alert("File uploaded successfully!");
    }
  };

  xhr.send(formData); // Send the form data (file)
});
</script>
```

---

### **8. Infinite Scroll (Loading More Content)**
AJAX can be used to implement infinite scrolling, where new content is automatically loaded as the user scrolls down.

#### **Example: Infinite Scroll**
```javascript
window.addEventListener("scroll", function() {
  if (window.innerHeight + window.scrollY >= document.body.offsetHeight) {
    var xhr = new XMLHttpRequest();
    xhr.open("GET", "load-more-posts.php", true);
    xhr.onload = function() {
      if (xhr.status === 200) {
        var posts = JSON.parse(xhr.responseText);
        var postsContainer = document.getElementById("postsContainer");
        posts.forEach(function(post) {
          var postElement = document.createElement("div");
          postElement.classList.add("post");
          postElement.innerHTML = "<h2>" + post.title + "</h2><p>" + post.content + "</p>";
          postsContainer.appendChild(postElement);
        });
      }
    };
    xhr.send(); // Fetch more posts
  }
});
```

---

### **Conclusion**
These examples demonstrate the versatility of AJAX in web development. Whether it's fetching data, submitting forms, displaying search suggestions, or handling file uploads, AJAX allows developers to create dynamic and responsive web applications that improve the overall user experience by reducing the need for full-page reloads.
