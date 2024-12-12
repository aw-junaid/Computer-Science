### **Fetch API - Send Data Objects**

In the **Fetch API**, you can send a wide variety of data types in the request body, including **JavaScript objects**. However, since the request body is sent as a string, you need to convert the object to a format that can be understood by the server. Typically, this is done by converting the object into **JSON** (using `JSON.stringify()`). You can also send other formats, such as **FormData** or **URLSearchParams**, depending on the content type.

This guide will explain how to send **JavaScript objects** in various formats (JSON, FormData, URL-encoded data) using the **Fetch API**.

---

### **1. Sending JavaScript Objects as JSON**

The most common way to send data objects is by converting them into a **JSON string** using `JSON.stringify()`. This method works well with modern web services that expect JSON data.

#### **Example: Sending a JavaScript Object as JSON in a POST Request**

```javascript
const dataObject = {
  username: 'john_doe',
  email: 'john.doe@example.com'
};

fetch('https://api.example.com/users', {
  method: 'POST',  // HTTP method (POST for creating new resource)
  headers: {
    'Content-Type': 'application/json',  // Specify JSON content type
  },
  body: JSON.stringify(dataObject)  // Convert JavaScript object to JSON string
})
  .then(response => response.json())  // Parse JSON response from server
  .then(data => console.log(data))    // Handle the response
  .catch(error => console.error('Error:', error));  // Handle any errors
```

- **JSON.stringify()**: Converts the JavaScript object (`dataObject`) into a JSON string that can be sent in the `body` of the request.
- **Content-Type**: The `Content-Type: application/json` header tells the server that the request body contains JSON data.

---

### **2. Sending Data Objects Using FormData**

The **FormData** object allows you to easily construct a set of key/value pairs to send as `multipart/form-data` (e.g., when submitting a form). This is often used for uploading files or when the server expects data in the form of key-value pairs.

#### **Example: Sending a JavaScript Object Using FormData**

```javascript
const formData = new FormData();
formData.append('username', 'john_doe');
formData.append('email', 'john.doe@example.com');

fetch('https://api.example.com/users', {
  method: 'POST',
  body: formData  // Send the FormData object directly
})
  .then(response => response.json())  // Parse the JSON response
  .then(data => console.log(data))    // Handle the response data
  .catch(error => console.error('Error:', error));  // Handle any errors
```

- **FormData**: The `FormData` object is used to collect form data or other key-value pairs. It's automatically encoded as `multipart/form-data`.
- **No need to set `Content-Type`**: When using `FormData`, the browser automatically sets the correct content type (`multipart/form-data`).

---

### **3. Sending Data Objects Using URL-encoded Format**

Sometimes, data needs to be sent in a **URL-encoded** format (`application/x-www-form-urlencoded`). This format is used by traditional HTML forms and can be sent using the `URLSearchParams` object in JavaScript.

#### **Example: Sending a JavaScript Object Using URL-encoded Format**

```javascript
const dataObject = {
  username: 'john_doe',
  email: 'john.doe@example.com'
};

// Convert the object into URL-encoded format
const urlEncodedData = new URLSearchParams(dataObject);

fetch('https://api.example.com/users', {
  method: 'POST',
  headers: {
    'Content-Type': 'application/x-www-form-urlencoded',  // URL-encoded content type
  },
  body: urlEncodedData.toString()  // Convert to URL-encoded string
})
  .then(response => response.json())  // Parse the JSON response
  .then(data => console.log(data))    // Handle the response data
  .catch(error => console.error('Error:', error));  // Handle any errors
```

- **URLSearchParams**: The `URLSearchParams` constructor is used to create a query string from a JavaScript object, which is then URL-encoded.
- **Content-Type**: `Content-Type: application/x-www-form-urlencoded` is used to specify that the data is URL-encoded.

---

### **4. Sending Data Objects in GET Requests**

While `GET` requests generally do not include a body, you can still send data objects by encoding them as query parameters in the URL. The data is appended to the URL using query strings.

#### **Example: Sending Data Objects in a GET Request**

```javascript
const params = new URLSearchParams({
  username: 'john_doe',
  email: 'john.doe@example.com'
});

fetch(`https://api.example.com/users?${params.toString()}`, {
  method: 'GET',  // HTTP method (GET for retrieving data)
})
  .then(response => response.json())  // Parse the JSON response
  .then(data => console.log(data))    // Handle the response
  .catch(error => console.error('Error:', error));  // Handle any errors
```

- **URLSearchParams**: The `URLSearchParams` object is used to convert the data object into URL-encoded query parameters.
- **Appending Data to URL**: The data is appended to the URL using `params.toString()`, which converts the object into a valid query string (`?username=john_doe&email=john.doe@example.com`).

---

### **5. Handling Responses from Data Object Requests**

After sending the data object (whether in a `POST`, `PUT`, or `GET` request), you typically receive a response from the server, often in JSON format. You can handle the response by parsing it using `response.json()`, `response.text()`, `response.blob()`, or other methods depending on the response format.

#### **Example: Handling a JSON Response**

```javascript
fetch('https://api.example.com/users', {
  method: 'POST',
  headers: {
    'Content-Type': 'application/json',
  },
  body: JSON.stringify({ username: 'john_doe', email: 'john.doe@example.com' })
})
  .then(response => {
    if (!response.ok) {
      throw new Error('Failed to fetch');
    }
    return response.json();  // Parse JSON response
  })
  .then(data => console.log('Response Data:', data))  // Handle the JSON data
  .catch(error => console.error('Error:', error));  // Handle errors
```

---

### **6. Error Handling for Data Objects**

When working with any fetch request, it’s essential to handle errors, especially when sending data. As mentioned, `fetch()` does not automatically reject on HTTP errors (e.g., 404 or 500 status codes), so you need to check if the response is successful (e.g., using `response.ok`) and handle errors manually.

#### **Example: Error Handling for Data Object Requests**

```javascript
fetch('https://api.example.com/users', {
  method: 'POST',
  headers: {
    'Content-Type': 'application/json',
  },
  body: JSON.stringify({ username: 'john_doe', email: 'john.doe@example.com' })
})
  .then(response => {
    if (!response.ok) {
      throw new Error('Network response was not ok');  // Handle errors if the response is not OK
    }
    return response.json();  // Parse the response as JSON
  })
  .then(data => console.log('Success:', data))
  .catch(error => console.error('Error:', error));  // Catch network or parsing errors
```

- **`response.ok`**: This property checks whether the HTTP status code indicates success (status codes in the range 200-299).
- **Custom Error Handling**: If the response is unsuccessful, you can throw an error or handle it based on the status code.

---

### **Conclusion**

- **JSON Data**: The most common approach for sending JavaScript objects is to convert them into JSON using `JSON.stringify()` and send them in the request body with `Content-Type: application/json`.
- **FormData**: Use **FormData** when sending files or key-value pairs, especially when submitting forms.
- **URL-encoded Data**: Use **URLSearchParams** for sending data in the traditional `application/x-www-form-urlencoded` format, often used in form submissions.
- **GET Requests**: For `GET` requests, you typically send data as query parameters appended to the URL.
- **Error Handling**: Always check `response.ok` and handle errors to ensure the request was successful.

The **Fetch API** provides flexibility to send various types of data objects in your requests, including JSON, form data, or URL-encoded data, making it suitable for many different web application needs.
