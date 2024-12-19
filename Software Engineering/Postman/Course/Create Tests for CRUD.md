### **Creating Tests for CRUD Operations in Postman**

Postman allows you to write tests for **CRUD** (Create, Read, Update, Delete) operations to validate that your API is working as expected. Tests are written in JavaScript and are executed after the request is made. You can write tests to check the response status code, headers, body content, and more.

Here’s how to create tests for each of the CRUD operations in Postman:

### **1. Create - POST Request Tests**

A **POST** request is used to create a new resource on the server. To test a **POST** request, you can check if the resource is created and whether the response body contains the correct data.

#### Example Workflow for POST (Create):

**Endpoint**: `https://api.example.com/users`

**Test Scenarios**:
- Check if the response status code is `201 Created` (indicating successful creation).
- Validate that the response body contains the expected data (e.g., ID, name).
- Ensure that the new resource is created with the correct attributes.

#### Example Test Code for POST Request:

```javascript
pm.test("Status code is 201", function() {
    pm.response.to.have.status(201);  // Verify that the status code is 201 (Created)
});

pm.test("Response body contains user ID", function() {
    var jsonData = pm.response.json();  // Parse the response body
    pm.expect(jsonData).to.have.property('id');  // Verify that 'id' is returned
});

pm.test("Created user has correct name", function() {
    var jsonData = pm.response.json();
    pm.expect(jsonData.name).to.eql("John Doe");  // Verify the user's name in the response
});
```

### **2. Read - GET Request Tests**

A **GET** request is used to retrieve data from the server. To test a **GET** request, you can verify that the correct resource is returned and that the response data matches the expected format.

#### Example Workflow for GET (Read):

**Endpoint**: `https://api.example.com/users/123`

**Test Scenarios**:
- Check if the response status code is `200 OK` (indicating successful retrieval).
- Validate that the response body contains the correct user data.
- Verify that the response format is JSON.

#### Example Test Code for GET Request:

```javascript
pm.test("Status code is 200", function() {
    pm.response.to.have.status(200);  // Verify that the status code is 200 (OK)
});

pm.test("Response body contains user data", function() {
    var jsonData = pm.response.json();
    pm.expect(jsonData).to.have.property('id', 123);  // Verify that 'id' matches the expected value
    pm.expect(jsonData).to.have.property('name', "John Doe");  // Verify that the 'name' field is correct
});

pm.test("Response is in JSON format", function() {
    pm.response.to.have.header("Content-Type", /application\/json/);  // Verify that the response content type is JSON
});
```

### **3. Update - PUT Request Tests**

A **PUT** request is used to update an existing resource. To test a **PUT** request, you can verify that the resource is updated and that the response body reflects the changes.

#### Example Workflow for PUT (Update):

**Endpoint**: `https://api.example.com/users/123`

**Test Scenarios**:
- Check if the response status code is `200 OK` or `204 No Content` (indicating a successful update).
- Validate that the updated data is reflected in the response body.
- Verify that the response body contains the updated resource data.

#### Example Test Code for PUT Request:

```javascript
pm.test("Status code is 200 or 204", function() {
    pm.response.to.have.status(200);  // Check if status code is 200 OK
    pm.response.to.have.status(204);  // Or check if status code is 204 No Content
});

pm.test("User data is updated", function() {
    var jsonData = pm.response.json();
    pm.expect(jsonData.name).to.eql("John Doe Updated");  // Verify that the user's name is updated
});

pm.test("Response contains updated user information", function() {
    var jsonData = pm.response.json();
    pm.expect(jsonData.email).to.eql("john.doe.updated@example.com");  // Verify the updated email address
});
```

### **4. Delete - DELETE Request Tests**

A **DELETE** request is used to remove a resource. To test a **DELETE** request, you can verify that the resource is successfully deleted and that the response indicates the deletion status.

#### Example Workflow for DELETE (Delete):

**Endpoint**: `https://api.example.com/users/123`

**Test Scenarios**:
- Check if the response status code is `200 OK` or `204 No Content` (indicating successful deletion).
- Validate that the response body contains a confirmation message or is empty.
- Verify that the resource is indeed deleted by performing a subsequent GET request.

#### Example Test Code for DELETE Request:

```javascript
pm.test("Status code is 200 or 204", function() {
    pm.response.to.have.status(200);  // Check if status code is 200 OK
    pm.response.to.have.status(204);  // Or check if status code is 204 No Content
});

pm.test("Resource is deleted", function() {
    var jsonData = pm.response.json();
    pm.expect(jsonData.message).to.eql("User with ID 123 has been deleted");  // Verify that the deletion message is returned
});

// Optional: Test to ensure the resource is deleted by sending a GET request
pm.test("GET request for deleted user returns 404", function() {
    pm.sendRequest({
        url: 'https://api.example.com/users/123',
        method: 'GET',
    }, function(err, res) {
        pm.expect(res.status).to.eql(404);  // Ensure the user is not found (404 Not Found)
    });
});
```

---

### **Combining CRUD Tests in a Collection**

In Postman, you can group all your tests for CRUD operations into a **Collection**. After creating the requests (GET, POST, PUT, DELETE), you can add them to a Collection and run them together using the **Collection Runner**.

#### Steps:
1. Create a new **Collection** in Postman.
2. Add the CRUD requests (POST, GET, PUT, DELETE) to the collection.
3. In the **Tests** tab of each request, write the appropriate test cases (as shown above).
4. Use the **Collection Runner** to run the tests together.

### **Conclusion**

Creating tests for CRUD operations in Postman ensures that your API behaves as expected for creating, reading, updating, and deleting resources. By leveraging Postman’s test scripting features, you can automate validation for each of these operations, ensuring the correctness and reliability of your API.
