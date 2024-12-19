**Environment Variables** in Postman are placeholders used in requests, enabling dynamic API testing and automation. They allow you to store values that can change depending on the environment (such as development, testing, or production), which makes it easier to manage and reuse configurations without manually editing the request each time.

### Types of Variables in Postman:

1. **Global Variables**: 
   - Available across all environments and collections. They are not tied to a specific environment.
   - **Use Case**: Store values like API keys or common settings that should be used globally.
   
2. **Environment Variables**:
   - Available only within a specific environment.
   - **Use Case**: Store environment-specific values like API base URLs, tokens, or server configurations.

3. **Collection Variables**:
   - Available only within a particular collection and can be used across requests in that collection.
   - **Use Case**: Store variables that are relevant to a specific collection of API requests.

4. **Local Variables**:
   - Defined within a specific request and are only available for that request.
   - **Use Case**: Store temporary data used only within a single request.

### How to Create and Use Environment Variables in Postman:

#### 1. **Create Environment Variables:**
   - **Step 1**: Click on the gear icon (⚙️) in the top-right corner of Postman and select **Manage Environments**.
   - **Step 2**: Click **Add** or **Create New** to create a new environment.
   - **Step 3**: Add variables by specifying their name and initial/current values. For example:
     - `base_url`: `https://api.example.com`
     - `auth_token`: `abc123xyz`
   - **Step 4**: Save the environment after adding the necessary variables.

#### 2. **Use Variables in Requests:**
   - Variables are referenced using **double curly braces** (`{{variable_name}}`) in various parts of the request, such as the URL, headers, body, and query parameters.
   
   **Example**:
   - **URL**: `{{base_url}}/users`
   - **Authorization Header**: `Authorization: Bearer {{auth_token}}`
   - **Query Parameter**: `?user_id={{user_id}}`

   Postman will replace the `{{variable_name}}` with the corresponding value from the environment (or global variables, if set).

#### 3. **Setting and Getting Variables During Requests:**
   You can dynamically modify variables at runtime using **scripts** (written in JavaScript) within Postman.

   **Pre-request Scripts**: These run before the request is sent, allowing you to set or modify variables.
   - Example: Set the environment variable `auth_token` before sending the request:
     ```javascript
     pm.environment.set("auth_token", "new_generated_token");
     ```

   **Test Scripts**: These run after receiving the response. You can use them to extract data from the response and store it in variables.
   - Example: Extract a token from the response and set it as an environment variable:
     ```javascript
     let responseJson = pm.response.json();
     pm.environment.set("auth_token", responseJson.token);
     ```

#### 4. **Using Global Variables:**
   - Global variables are created and accessed through the **Globals** section in the environment manager. They can be referenced the same way as environment variables (`{{global_variable_name}}`), but they are accessible across all environments.

#### 5. **Managing Variables:**
   - You can edit, delete, or add variables to an environment by opening the environment manager and selecting the environment.
   - **Tip**: To prevent sharing sensitive information (like authentication tokens), ensure that sensitive variables are stored in **environment variables** instead of global ones.

### Example Scenario:

You have three different environments: `Development`, `Staging`, and `Production`. Each environment has a different API base URL and authentication token. Here’s how you can set up variables:

1. **Development Environment**:
   - `base_url`: `https://dev-api.example.com`
   - `auth_token`: `dev_token_123`

2. **Staging Environment**:
   - `base_url`: `https://staging-api.example.com`
   - `auth_token`: `staging_token_456`

3. **Production Environment**:
   - `base_url`: `https://api.example.com`
   - `auth_token`: `prod_token_789`

By switching between these environments in Postman, the API requests automatically adjust to use the corresponding values for `base_url` and `auth_token`.

### Advantages of Using Environment Variables:
- **Flexibility**: Easily switch between different environments (dev, staging, production) without modifying your requests.
- **Reusability**: Reuse requests across different environments or collections without rewriting values.
- **Simplified Testing**: Modify values once, and all requests using those variables automatically get updated.
- **Automation**: Use dynamic variables to set up complex workflows or scripts that change based on the context.

### Conclusion:
Environment variables in Postman make API testing more efficient by reducing the need to manually update values for different configurations. They provide a flexible, scalable way to handle various API environments and facilitate the automation and testing of API endpoints across multiple stages of development.
