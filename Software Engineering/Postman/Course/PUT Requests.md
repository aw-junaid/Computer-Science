### **PUT Requests in Postman**

A **PUT** request is used to send data to a server to update an existing resource. Unlike the **POST** request, which is typically used to create new resources, the **PUT** request is specifically designed for **updating** an existing resource. In a PUT request, you generally send the complete data for the resource you want to update, replacing the current state with the new data.

### Key Concepts for PUT Requests in Postman:

1. **PUT Request Syntax**:
   - A **PUT** request is typically used to update a resource at a specific URL. The request includes the updated data in the body of the request.
   - **Example URL**: 
     ```
     https://api.example.com/users/123
     ```
     This would update the user with ID `123` at the `/users/123` endpoint.

2. **Setting up a PUT Request in Postman**:
   To send a PUT request in Postman:
   1. **Select PUT Method**:
      - Open Postman and create a new request.
      - In the dropdown next to the URL field, select **PUT** from the HTTP method options.
   2. **Enter the API Endpoint URL**:
      - Enter the endpoint you want to send the PUT request to (e.g., `https://api.example.com/users/123` to update the user with ID `123`).
   3. **Set the Request Body**:
      - Go to the **Body** tab to define the data you want to send in the PUT request. 
      - Depending on the API, the body can be in different formats like **JSON**, **form-data**, **x-www-form-urlencoded**, or **raw**.
   4. **Add Headers (if required)**:
      - For PUT requests, you may need to specify headers such as `Content-Type`, `Authorization`, or any other custom headers required by the API.
      - For example, to send JSON data, the `Content-Type` header would be `application/json`.
   5. **Add Authorization (if required)**:
      - If the API requires authentication, go to the **Authorization** tab and select the appropriate authorization method (e.g., **Bearer Token**, **Basic Auth**, etc.).

3. **Types of Request Bodies for PUT Requests**:
   Similar to POST requests, PUT requests can send data in various formats depending on the server’s requirements.

   - **JSON**:
     - JSON is the most common format for PUT requests. You typically send the updated resource data as JSON.
     - **Example** (updating a user):
       ```json
       {
         "username": "john_doe_updated",
         "email": "john.doe.updated@example.com",
         "password": "newpassword123"
       }
       ```
     - **Postman Setup**: 
       - In the **Body** tab, select **raw** and choose `JSON` from the dropdown. Then, enter your updated JSON data.
   
   - **Form-data**:
     - You can also use **form-data** for sending data in key-value pairs (often used for uploading files or submitting complex form data).
     - **Postman Setup**: 
       - In the **Body** tab, select **form-data** and enter your key-value pairs. You can also upload files if needed.

   - **x-www-form-urlencoded**:
     - Similar to `form-data`, but the data is encoded as key-value pairs, and the content is URL-encoded.
     - **Postman Setup**: 
       - In the **Body** tab, select **x-www-form-urlencoded** and enter key-value pairs.

4. **Headers in PUT Requests**:
   Just like with POST requests, headers play a significant role in PUT requests:
   - **Content-Type**: Specifies the format of the data you are sending (e.g., `application/json`, `application/x-www-form-urlencoded`).
   - **Authorization**: If the API requires authentication, you may need to provide an authorization header (e.g., `Authorization: Bearer <access_token>`).
   
   **Example**:
   ```
   Content-Type: application/json
   Authorization: Bearer <your_access_token>
   ```

5. **Handling Responses in PUT Requests**:
   After sending a PUT request, you will receive a response from the server. The response typically contains:
   - **Status Code**: The HTTP status code (e.g., `200 OK`, `204 No Content`, `400 Bad Request`).
   - **Response Body**: The updated data or confirmation of the update, often with the updated resource's details.
   - **Response Headers**: Metadata about the response.

   **Example Response** (updating a user):
   ```json
   {
     "user_id": 123,
     "username": "john_doe_updated",
     "email": "john.doe.updated@example.com"
   }
   ```
   - A **204 No Content** response means the update was successful, but no additional data is returned.
   - A **200 OK** response means the resource was successfully updated and the updated data is returned.

6. **Writing Tests for PUT Requests**:
   You can write tests in the **Tests** tab in Postman to validate the response of a PUT request.
   - **Example Test**: To check if the status code is `200 OK` and verify that the response body contains the updated user details:
     ```javascript
     pm.test("Status is 200", function() {
         pm.response.to.have.status(200);
     });

     pm.test("Username is updated", function() {
         var jsonData = pm.response.json();
         pm.expect(jsonData.username).to.eql("john_doe_updated");
     });
     ```

### Example Workflow of a PUT Request in Postman:

#### Scenario: Updating User Details via PUT Request

1. **Step 1: Set up the PUT Request**:
   - Open Postman and create a new request.
   - Select **PUT** from the method dropdown.
   - Enter the endpoint URL:
     ```
     https://api.example.com/users/123
     ```

2. **Step 2: Add Request Body**:
   - Go to the **Body** tab, select **raw**, and choose `JSON` from the dropdown.
   - Enter the updated JSON data for the user:
     ```json
     {
       "username": "john_doe_updated",
       "email": "john.doe.updated@example.com",
       "password": "newpassword123"
     }
     ```

3. **Step 3: Add Headers**:
   - Go to the **Headers** tab and add the `Content-Type` header:
     ```
     Content-Type: application/json
     ```

4. **Step 4: Add Authorization** (if required):
   - If authentication is required, go to the **Authorization** tab and add the necessary authorization (e.g., Bearer Token, Basic Auth).
   - Example (Bearer Token):
     ```
     Authorization: Bearer <your_access_token>
     ```

5. **Step 5: Send the Request**:
   - Click **Send** to execute the PUT request. The response will appear in the lower section of the Postman window.

6. **Step 6: Validate the Response**:
   - Check the response status code (e.g., `200 OK` or `204 No Content`).
   - Verify that the response body contains the updated data (e.g., the updated username, email, etc.).
   - Optionally, write tests to validate the response in the **Tests** tab.

7. **Step 7: Automate with Collection Runner (optional)**:
   - If you need to update multiple resources, you can use the **Collection Runner** to automate multiple PUT requests.

### Best Practices for PUT Requests in Postman:

- **Use Environment Variables**: For dynamic data such as URLs, tokens, or resource IDs, use environment variables in Postman. This makes it easy to switch between environments (e.g., development, staging, production).
- **Test Responses**: Always validate the response to ensure that the update was successful and that the resource was correctly modified.
- **Handle Authorization**: Ensure that the appropriate authorization is included in the PUT request, especially if the API requires authentication or permissions to update resources.
- **Send Complete Data**: With PUT requests, it's typical to send the complete data for the resource you're updating. If only partial data is provided, the server might replace the resource entirely or fail to update it correctly.
- **Check for Idempotency**: PUT requests are **idempotent**, meaning that sending the same PUT request multiple times should always produce the same result (no side effects). Ensure the API adheres to this principle.

### Conclusion:
PUT requests in Postman are essential for updating existing resources on a server. By setting up the correct endpoint, request body, headers, and authorization, you can efficiently test and interact with APIs that support resource updates. Postman’s features like request validation, automated tests, and environment variables make it easier to manage and test PUT requests, ensuring the updates are processed correctly.
