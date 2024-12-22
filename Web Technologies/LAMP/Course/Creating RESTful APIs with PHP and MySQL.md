### **Creating RESTful APIs with PHP and MySQL**

A RESTful API (Representational State Transfer) is a widely used architectural style for web services. In this guide, we will create a simple RESTful API in PHP that interacts with a MySQL database.

#### **Overview:**
- **HTTP Methods**: The API will use HTTP methods like `GET`, `POST`, `PUT`, and `DELETE` to interact with resources (data).
- **JSON**: The API will send and receive data in JSON format.
- **Database**: We'll use MySQL to store the data (e.g., users or products).

---

### **1. Setting Up the MySQL Database**

First, create a MySQL database and table to store the data. For this example, we will create a `users` table to store user information.

#### **Step 1: Create the Database and Table**

```sql
-- Create the database
CREATE DATABASE api_db;

-- Use the database
USE api_db;

-- Create the users table
CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(100) NOT NULL UNIQUE,
    password VARCHAR(255) NOT NULL
);

-- Insert some sample data
INSERT INTO users (name, email, password) VALUES
('John Doe', 'john@example.com', 'password123'),
('Jane Smith', 'jane@example.com', 'mypassword');
```

---

### **2. Creating the PHP API**

#### **Step 1: Database Connection (db.php)**

Create a `db.php` file to handle the database connection.

```php
<?php
// db.php

$host = "localhost";       // Database host
$username = "root";        // Database username
$password = "";            // Database password (default is empty for localhost)
$dbname = "api_db";        // Database name

// Create a new PDO instance to interact with the database
try {
    $pdo = new PDO("mysql:host=$host;dbname=$dbname", $username, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
    die("Connection failed: " . $e->getMessage());
}
?>
```

This `db.php` file connects to the MySQL database using PDO, which is a secure way of interacting with databases in PHP.

---

#### **Step 2: API Class (Api.php)**

Create a class `Api.php` to handle the HTTP requests and return JSON responses.

```php
<?php
// api.php
require_once 'db.php';  // Include the database connection

class API {
    // Function to get all users
    public function getUsers() {
        global $pdo;
        $stmt = $pdo->query("SELECT * FROM users");
        $users = $stmt->fetchAll(PDO::FETCH_ASSOC);
        echo json_encode($users);
    }

    // Function to get a single user by ID
    public function getUser($id) {
        global $pdo;
        $stmt = $pdo->prepare("SELECT * FROM users WHERE id = ?");
        $stmt->execute([$id]);
        $user = $stmt->fetch(PDO::FETCH_ASSOC);
        if ($user) {
            echo json_encode($user);
        } else {
            echo json_encode(["message" => "User not found"]);
        }
    }

    // Function to create a new user
    public function createUser($data) {
        global $pdo;
        $stmt = $pdo->prepare("INSERT INTO users (name, email, password) VALUES (?, ?, ?)");
        if ($stmt->execute([$data['name'], $data['email'], password_hash($data['password'], PASSWORD_DEFAULT)])) {
            echo json_encode(["message" => "User created successfully"]);
        } else {
            echo json_encode(["message" => "Error creating user"]);
        }
    }

    // Function to update user details
    public function updateUser($id, $data) {
        global $pdo;
        $stmt = $pdo->prepare("UPDATE users SET name = ?, email = ?, password = ? WHERE id = ?");
        if ($stmt->execute([$data['name'], $data['email'], password_hash($data['password'], PASSWORD_DEFAULT), $id])) {
            echo json_encode(["message" => "User updated successfully"]);
        } else {
            echo json_encode(["message" => "Error updating user"]);
        }
    }

    // Function to delete a user
    public function deleteUser($id) {
        global $pdo;
        $stmt = $pdo->prepare("DELETE FROM users WHERE id = ?");
        if ($stmt->execute([$id])) {
            echo json_encode(["message" => "User deleted successfully"]);
        } else {
            echo json_encode(["message" => "Error deleting user"]);
        }
    }

    // Handle incoming requests
    public function handleRequest() {
        $requestMethod = $_SERVER['REQUEST_METHOD'];
        $endpoint = isset($_GET['endpoint']) ? $_GET['endpoint'] : null;
        $id = isset($_GET['id']) ? $_GET['id'] : null;

        // Switch based on the HTTP request method
        switch ($requestMethod) {
            case 'GET':
                if ($id) {
                    $this->getUser($id);  // Get a specific user
                } else {
                    $this->getUsers();  // Get all users
                }
                break;

            case 'POST':
                $data = json_decode(file_get_contents('php://input'), true);
                if ($data) {
                    $this->createUser($data);  // Create a new user
                } else {
                    echo json_encode(["message" => "Invalid input"]);
                }
                break;

            case 'PUT':
                if ($id) {
                    $data = json_decode(file_get_contents('php://input'), true);
                    if ($data) {
                        $this->updateUser($id, $data);  // Update user details
                    } else {
                        echo json_encode(["message" => "Invalid input"]);
                    }
                } else {
                    echo json_encode(["message" => "ID is required"]);
                }
                break;

            case 'DELETE':
                if ($id) {
                    $this->deleteUser($id);  // Delete a user
                } else {
                    echo json_encode(["message" => "ID is required"]);
                }
                break;

            default:
                echo json_encode(["message" => "Method not allowed"]);
                break;
        }
    }
}
?>
```

### **Explanation:**
1. **Methods**:
   - **GET**: Retrieves all users (`getUsers()`) or a specific user by ID (`getUser()`).
   - **POST**: Creates a new user using data sent in the request body (`createUser()`).
   - **PUT**: Updates an existing user by ID with new data (`updateUser()`).
   - **DELETE**: Deletes a user by ID (`deleteUser()`).

2. **Request Handling**: The `handleRequest()` method processes the incoming HTTP request. Depending on the HTTP method (`GET`, `POST`, `PUT`, `DELETE`), it calls the corresponding function.

3. **Input Handling**: Data is received and sent in JSON format using `file_get_contents('php://input')`.

---

#### **Step 3: Routing the API (index.php)**

Create a `index.php` file to route requests to the appropriate methods of the `API` class.

```php
<?php
// index.php
require_once 'api.php';  // Include the API class

$api = new API();  // Instantiate the API class
$api->handleRequest();  // Handle the incoming request
?>
```

---

### **3. Testing the API**

You can now test the API using tools like **Postman** or **cURL**.

#### **Example API Endpoints:**

1. **GET /users**: Retrieve all users.
   - **Request**: `GET http://localhost/api/index.php?endpoint=users`
   - **Response**: JSON array of all users.

2. **GET /users/{id}**: Retrieve a user by ID.
   - **Request**: `GET http://localhost/api/index.php?endpoint=users&id=1`
   - **Response**: JSON object of the user with ID 1.

3. **POST /users**: Create a new user.
   - **Request**: 
     ```json
     POST http://localhost/api/index.php?endpoint=users
     {
         "name": "New User",
         "email": "newuser@example.com",
         "password": "newpassword"
     }
     ```
   - **Response**: JSON message confirming user creation.

4. **PUT /users/{id}**: Update a user by ID.
   - **Request**: 
     ```json
     PUT http://localhost/api/index.php?endpoint=users&id=1
     {
         "name": "Updated Name",
         "email": "updatedemail@example.com",
         "password": "updatedpassword"
     }
     ```
   - **Response**: JSON message confirming user update.

5. **DELETE /users/{id}**: Delete a user by ID.
   - **Request**: `DELETE http://localhost/api/index.php?endpoint=users&id=1`
   - **Response**: JSON message confirming user deletion.

---

### **4. Security Considerations**

- **Authentication**: For real-world applications, you should implement authentication (e.g., JWT or OAuth) to protect sensitive endpoints.
- **Validation**: Always validate user input before interacting with the database to prevent SQL injection and other attacks.
- **Error Handling**: Implement proper error handling and send meaningful error messages in the response.
- **Sanitization**: Ensure that user input is sanitized before using it in SQL queries or other sensitive operations.

---

### **Conclusion**

You’ve now created a simple RESTful API using PHP and MySQL. This API supports basic CRUD (Create, Read, Update, Delete) operations for managing users. You can expand this by adding more endpoints, authentication, or other advanced features depending on your application's needs.
