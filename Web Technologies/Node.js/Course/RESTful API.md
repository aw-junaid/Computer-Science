### **Node.js - RESTful API**

A **RESTful API** (Representational State Transfer) is a popular architecture style for building web services. It uses standard HTTP methods (GET, POST, PUT, DELETE) to perform CRUD operations (Create, Read, Update, Delete) on resources, which are typically represented by URLs (Uniform Resource Locators).

**Node.js** with **Express.js** is commonly used to build RESTful APIs due to its simplicity, performance, and asynchronous nature.

---

### **Key Principles of RESTful API**

- **Stateless**: Each HTTP request from the client to the server must contain all information the server needs to fulfill the request (e.g., authentication, data).
- **Client-Server Architecture**: The client and server are separate entities that communicate over HTTP. The client sends requests and the server responds with the data.
- **Uniform Interface**: A standardized way of interacting with resources (e.g., using standard HTTP methods for CRUD operations).
- **Resource-Based**: Resources (data entities) are identified by URLs, and each resource can have different representations (e.g., JSON, XML).
- **Cacheable**: Responses from the server can be marked as cacheable or non-cacheable to optimize performance.

---

### **Steps to Build a RESTful API in Node.js with Express**

Here’s a simple example of building a RESTful API with Node.js and Express.

---

### **1. Set Up the Project**

First, create a new project and install Express.

```bash
mkdir node-rest-api
cd node-rest-api
npm init -y
npm install express --save
```

---

### **2. Create the Express Server**

Create an `app.js` file where you will define the Express app and its routes.

```javascript
const express = require('express');
const app = express();

// Middleware to parse JSON bodies
app.use(express.json());

// A simple in-memory array to act as a database
let users = [
    { id: 1, name: 'John Doe', email: 'john.doe@example.com' },
    { id: 2, name: 'Jane Doe', email: 'jane.doe@example.com' }
];

// Define routes

// GET: Fetch all users
app.get('/api/users', (req, res) => {
    res.json(users);
});

// GET: Fetch a user by ID
app.get('/api/users/:id', (req, res) => {
    const user = users.find(u => u.id === parseInt(req.params.id));
    if (!user) {
        return res.status(404).send('User not found');
    }
    res.json(user);
});

// POST: Create a new user
app.post('/api/users', (req, res) => {
    const { name, email } = req.body;
    if (!name || !email) {
        return res.status(400).send('Name and email are required');
    }

    const newUser = {
        id: users.length + 1,
        name,
        email
    };
    users.push(newUser);
    res.status(201).json(newUser);
});

// PUT: Update a user by ID
app.put('/api/users/:id', (req, res) => {
    const user = users.find(u => u.id === parseInt(req.params.id));
    if (!user) {
        return res.status(404).send('User not found');
    }

    const { name, email } = req.body;
    user.name = name || user.name;
    user.email = email || user.email;

    res.json(user);
});

// DELETE: Delete a user by ID
app.delete('/api/users/:id', (req, res) => {
    const userIndex = users.findIndex(u => u.id === parseInt(req.params.id));
    if (userIndex === -1) {
        return res.status(404).send('User not found');
    }

    const deletedUser = users.splice(userIndex, 1);
    res.json(deletedUser);
});

// Start the server
const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
    console.log(`Server is running on port ${PORT}`);
});
```

---

### **3. Explanation of the Code**

- **Express Setup**: We first require `express` and create an instance of the application using `express()`.
- **Middleware**: We use `express.json()` middleware to parse incoming JSON requests, allowing us to handle `POST` and `PUT` requests with JSON bodies.
- **Routes**:
  - `GET /api/users`: Returns all users as a JSON array.
  - `GET /api/users/:id`: Fetches a specific user by their `id`. If the user does not exist, it returns a 404 error.
  - `POST /api/users`: Accepts a `name` and `email` in the request body, creates a new user, and returns the created user with a 201 status.
  - `PUT /api/users/:id`: Updates a user's information by their `id`. If no user is found, it returns a 404 error.
  - `DELETE /api/users/:id`: Deletes a user by their `id` and returns the deleted user.
  
- **In-Memory Data**: We use an in-memory array (`users`) to simulate a simple database. In a real-world scenario, this data would likely be stored in a database like MongoDB, PostgreSQL, or MySQL.

---

### **4. Testing the API**

To test your RESTful API, run the server:

```bash
node app.js
```

You can now interact with the API using tools like **Postman**, **cURL**, or **HTTPie**.

#### **Sample API Requests:**

- **GET all users**:
  - `GET http://localhost:3000/api/users`
  
- **GET a user by ID**:
  - `GET http://localhost:3000/api/users/1`
  
- **POST create a new user**:
  - `POST http://localhost:3000/api/users`
  - Body (JSON):
    ```json
    {
      "name": "Alice Smith",
      "email": "alice.smith@example.com"
    }
    ```

- **PUT update a user**:
  - `PUT http://localhost:3000/api/users/1`
  - Body (JSON):
    ```json
    {
      "name": "John Smith",
      "email": "john.smith@example.com"
    }
    ```

- **DELETE a user**:
  - `DELETE http://localhost:3000/api/users/2`

---

### **5. Using MongoDB for Data Storage**

In a production environment, you would typically use a database like **MongoDB** to store and retrieve data instead of an in-memory array.

Here’s a basic setup for integrating **MongoDB** with your RESTful API using **Mongoose**:

1. **Install Mongoose**:

   ```bash
   npm install mongoose --save
   ```

2. **Update the Code**:

```javascript
const mongoose = require('mongoose');

// Connect to MongoDB
mongoose.connect('mongodb://localhost/nodeapi', { useNewUrlParser: true, useUnifiedTopology: true });

// Define a user schema
const userSchema = new mongoose.Schema({
    name: String,
    email: String
});

// Create a user model
const User = mongoose.model('User', userSchema);

// Replace the in-memory `users` array with MongoDB queries
app.get('/api/users', async (req, res) => {
    try {
        const users = await User.find();
        res.json(users);
    } catch (err) {
        res.status(500).send('Error retrieving users');
    }
});

app.get('/api/users/:id', async (req, res) => {
    try {
        const user = await User.findById(req.params.id);
        if (!user) {
            return res.status(404).send('User not found');
        }
        res.json(user);
    } catch (err) {
        res.status(500).send('Error retrieving user');
    }
});

app.post('/api/users', async (req, res) => {
    const { name, email } = req.body;
    const newUser = new User({ name, email });
    try {
        await newUser.save();
        res.status(201).json(newUser);
    } catch (err) {
        res.status(400).send('Error creating user');
    }
});

app.put('/api/users/:id', async (req, res) => {
    const { name, email } = req.body;
    try {
        const updatedUser = await User.findByIdAndUpdate(
            req.params.id, 
            { name, email }, 
            { new: true }
        );
        if (!updatedUser) {
            return res.status(404).send('User not found');
        }
        res.json(updatedUser);
    } catch (err) {
        res.status(400).send('Error updating user');
    }
});

app.delete('/api/users/:id', async (req, res) => {
    try {
        const deletedUser = await User.findByIdAndDelete(req.params.id);
        if (!deletedUser) {
            return res.status(404).send('User not found');
        }
        res.json(deletedUser);
    } catch (err) {
        res.status(500).send('Error deleting user');
    }
});
```

Now the API will store and retrieve users from MongoDB, making it more persistent and scalable.

---

### **6. Conclusion**

Building a RESTful API with Node.js and Express is straightforward. You can easily handle CRUD operations with routing and middleware, manage data using databases like MongoDB, and apply RESTful principles to build scalable and efficient APIs. As your API grows, you can enhance it with authentication, validation, and other features to improve security and performance.
