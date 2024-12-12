### **Fetch API - Send JSON Data**

Sending **JSON data** in a `POST` or `PUT` request is one of the most common tasks in web development. The **Fetch API** provides an easy way to send JSON data to a server. To send JSON data, you need to use the `body` property in the `fetch` options to include the data, and the `Content-Type` header should be set to `application/json` to indicate that you're sending JSON.

### **Steps to Send JSON Data Using Fetch API**

1. **Set the HTTP Method**: Use `POST` or `PUT` depending on whether you're creating a new resource or updating an existing one.
2. **Set Headers**: Set the `Content-Type` header to `application/json` to inform the server that the body of the request contains JSON.
3. **Prepare the Body**: Convert the JavaScript object to a JSON string using `JSON.stringify()`.
4. **Handle the Response**: Process the server's response, usually in JSON format.

---

### **Basic Syntax to Send JSON Data**

```javascript
fetch(url, {
  method: 'POST',  // or 'PUT' for updating
  headers: {
    'Content-Type': 'application/json',  // Inform the server about the content type
  },
  body: JSON.stringify(data)  // Convert the JavaScript object to a JSON string
})
  .then(response => response.json())  // Parse the JSON response from the server
  .then(data => console.log(data))    // Handle the response data
  .catch(error => console.error('Error:', error));  // Handle errors
```

---

### **1. Sending JSON Data with a POST Request**

In a `POST` request, the `body` is where the data you want to send to the server goes. Here, you send a JavaScript object that is converted to a JSON string using `JSON.stringify()`.

#### **Example: Sending JSON Data in a POST Request**

```javascript
const postData = {
  name: 'John Doe',
  email: 'john.doe@example.com'
};

fetch('https://api.example.com/users', {
  method: 'POST',  // Use POST to create a new resource
  headers: {
    'Content-Type': 'application/json',  // Indicate JSON content type
  },
  body: JSON.stringify(postData)  // Convert JavaScript object to JSON
})
  .then(response => response.json())  // Parse the JSON response
  .then(data => console.log(data))    // Handle the response data
  .catch(error => console.error('Error:', error));  // Handle any errors
```

- **Request Body**: The JavaScript object `postData` is converted into a JSON string using `JSON.stringify()`.
- **Content-Type**: The `Content-Type: application/json` header informs the server that the body of the request contains JSON.

---

### **2. Sending JSON Data with a PUT Request**

A `PUT` request is used to update an existing resource. The process of sending JSON data in a `PUT` request is similar to `POST`, but the HTTP method is set to `'PUT'`.

#### **Example: Sending JSON Data in a PUT Request**

```javascript
const updatedData = {
  name: 'Jane Doe',
  email: 'jane.doe@example.com'
};

fetch('https://api.example.com/users/123', {  // Assuming the resource ID is 123
  method: 'PUT',  // Use PUT to update an existing resource
  headers: {
    'Content-Type': 'application/json',  // Inform the server that the body is JSON
  },
  body: JSON.stringify(updatedData)  // Convert the updated data to JSON
})
  .then(response => response.json())  // Parse the JSON response
  .then(data => console.log(data))    // Handle the response data
  .catch(error => console.error('Error:', error));  // Handle any errors
```

- **Updated Data**: The JavaScript object `updatedData` is sent as JSON to update the resource identified by `123`.

---

### **3. Handling Non-JSON Responses**

Sometimes, the server might not return JSON. In such cases, you can use the appropriate method to handle the response, such as `response.text()`, `response.blob()`, or `response.arrayBuffer()`.

#### **Example: Handling a Plain Text Response**

```javascript
fetch('https://api.example.com/submit', {
  method: 'POST',
  headers: {
    'Content-Type': 'application/json',
  },
  body: JSON.stringify({ name: 'John Doe' })
})
  .then(response => response.text())  // If the response is plain text
  .then(data => console.log(data))    // Handle plain text response
  .catch(error => console.error('Error:', error));
```

- **`response.text()`**: This method is used when the server returns plain text or HTML.

---

### **4. Error Handling for JSON Requests**

It is important to handle errors, especially when sending JSON data. The `fetch()` API does not reject on HTTP errors (e.g., 404 or 500 status codes), so it's necessary to manually check the `response.ok` property and handle errors accordingly.

#### **Example: Error Handling**

```javascript
fetch('https://api.example.com/users', {
  method: 'POST',
  headers: {
    'Content-Type': 'application/json',
  },
  body: JSON.stringify({ name: 'John Doe' })
})
  .then(response => {
    if (!response.ok) {  // Check if the response is successful (status code 2xx)
      throw new Error('Network response was not ok');
    }
    return response.json();  // Parse the response as JSON
  })
  .then(data => console.log(data))
  .catch(error => console.error('Error:', error));  // Handle network or parsing errors
```

- **`response.ok`**: This property indicates whether the response status code is in the range 200–299.
- **Custom Error Handling**: If the response status is not OK, you can throw an error or handle it in a different way.

---

### **5. Sending JSON Data with Authentication (Bearer Token)**

When working with APIs that require authentication, you may need to include an **Authorization** header along with your JSON data, often in the form of a **Bearer token**.

#### **Example: Sending JSON Data with Authorization**

```javascript
const postData = {
  name: 'John Doe',
  email: 'john.doe@example.com'
};

fetch('https://api.example.com/users', {
  method: 'POST',
  headers: {
    'Content-Type': 'application/json',
    'Authorization': 'Bearer YOUR_ACCESS_TOKEN',  // Send authorization token in header
  },
  body: JSON.stringify(postData)
})
  .then(response => response.json())
  .then(data => console.log(data))
  .catch(error => console.error('Error:', error));
```

- **Authorization Header**: The `Authorization` header includes the **Bearer token** used to authenticate the request.

---

### **Conclusion**

- **JSON Data**: Use `JSON.stringify()` to convert JavaScript objects into JSON format before sending them in the `body`.
- **Content-Type**: Always set the `Content-Type: application/json` header to indicate the type of data being sent.
- **Error Handling**: Check `response.ok` to handle any errors related to the request.
- **Authorization**: Include the `Authorization` header if your request requires authentication (e.g., with a Bearer token).

The **Fetch API** makes it straightforward to send JSON data in HTTP requests, whether you're creating new resources (`POST`) or updating existing ones (`PUT`). The process is simple, with JSON being the most common format for data exchange in modern web APIs.
