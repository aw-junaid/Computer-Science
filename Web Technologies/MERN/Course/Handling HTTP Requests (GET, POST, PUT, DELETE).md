Handling HTTP requests is a core part of building web applications and APIs with Express.js. Express provides methods to handle different HTTP methods like **GET**, **POST**, **PUT**, and **DELETE**. Below is a detailed guide on how to handle these requests.

---

### **1. Handling GET Requests**

The `GET` method is used to retrieve data from the server. It is the most common HTTP method.

#### Example: Handling a GET Request
```javascript
const express = require('express');
const app = express();

// GET request to the root URL
app.get('/', (req, res) => {
  res.send('Welcome to the Home Page!');
});

// GET request with route parameters
app.get('/users/:userId', (req, res) => {
  const userId = req.params.userId;
  res.send(`User ID: ${userId}`);
});

// GET request with query parameters
app.get('/search', (req, res) => {
  const query = req.query.q;
  res.send(`Search Query: ${query}`);
});

// Start the server
const PORT = 3000;
app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});
```

---

### **2. Handling POST Requests**

The `POST` method is used to send data to the server, typically to create a new resource.

#### Example: Handling a POST Request
To handle POST requests, you need to parse the request body. Use the `express.json()` middleware to parse JSON data.

```javascript
const express = require('express');
const app = express();

// Middleware to parse JSON request bodies
app.use(express.json());

// POST request to create a new user
app.post('/users', (req, res) => {
  const userData = req.body; // Access the request body
  console.log('User Data:', userData);
  res.status(201).send('User created successfully!');
});

// Start the server
const PORT = 3000;
app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});
```

#### Testing the POST Request
You can test the POST request using tools like **Postman** or **curl**:
```bash
curl -X POST http://localhost:3000/users -H "Content-Type: application/json" -d '{"name": "John", "age": 30}'
```

---

### **3. Handling PUT Requests**

The `PUT` method is used to update an existing resource on the server.

#### Example: Handling a PUT Request
```javascript
const express = require('express');
const app = express();

// Middleware to parse JSON request bodies
app.use(express.json());

// Sample data (for demonstration)
let users = [
  { id: 1, name: 'John' },
  { id: 2, name: 'Jane' },
];

// PUT request to update a user
app.put('/users/:userId', (req, res) => {
  const userId = parseInt(req.params.userId);
  const updatedUser = req.body;

  // Find and update the user
  const userIndex = users.findIndex((user) => user.id === userId);
  if (userIndex !== -1) {
    users[userIndex] = { ...users[userIndex], ...updatedUser };
    res.send('User updated successfully!');
  } else {
    res.status(404).send('User not found');
  }
});

// Start the server
const PORT = 3000;
app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});
```

#### Testing the PUT Request
```bash
curl -X PUT http://localhost:3000/users/1 -H "Content-Type: application/json" -d '{"name": "John Doe"}'
```

---

### **4. Handling DELETE Requests**

The `DELETE` method is used to remove a resource from the server.

#### Example: Handling a DELETE Request
```javascript
const express = require('express');
const app = express();

// Sample data (for demonstration)
let users = [
  { id: 1, name: 'John' },
  { id: 2, name: 'Jane' },
];

// DELETE request to remove a user
app.delete('/users/:userId', (req, res) => {
  const userId = parseInt(req.params.userId);

  // Find and delete the user
  const userIndex = users.findIndex((user) => user.id === userId);
  if (userIndex !== -1) {
    users.splice(userIndex, 1);
    res.send('User deleted successfully!');
  } else {
    res.status(404).send('User not found');
  }
});

// Start the server
const PORT = 3000;
app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});
```

#### Testing the DELETE Request
```bash
curl -X DELETE http://localhost:3000/users/1
```

---

### **5. Handling All HTTP Methods**

You can use `app.all()` to handle all HTTP methods for a specific route.

#### Example: Handling All Methods
```javascript
app.all('/example', (req, res) => {
  res.send(`Handling ${req.method} request`);
});
```

---

### **6. Using Middleware for Request Handling**

Middleware can be used to preprocess requests before they reach the route handlers. For example, you can use middleware to log requests or validate data.

#### Example: Logging Middleware
```javascript
app.use((req, res, next) => {
  console.log(`${req.method} ${req.url}`);
  next();
});
```

#### Example: Validation Middleware
```javascript
const validateUser = (req, res, next) => {
  const userData = req.body;
  if (!userData.name || !userData.age) {
    return res.status(400).send('Name and age are required');
  }
  next();
};

app.post('/users', validateUser, (req, res) => {
  const userData = req.body;
  res.status(201).send('User created successfully!');
});
```

---

### **7. Complete Example**

Here’s a complete example that combines all the HTTP methods:

```javascript
const express = require('express');
const app = express();

// Middleware to parse JSON request bodies
app.use(express.json());

// Sample data (for demonstration)
let users = [
  { id: 1, name: 'John' },
  { id: 2, name: 'Jane' },
];

// GET all users
app.get('/users', (req, res) => {
  res.json(users);
});

// GET a specific user
app.get('/users/:userId', (req, res) => {
  const userId = parseInt(req.params.userId);
  const user = users.find((user) => user.id === userId);
  if (user) {
    res.json(user);
  } else {
    res.status(404).send('User not found');
  }
});

// POST a new user
app.post('/users', (req, res) => {
  const newUser = req.body;
  newUser.id = users.length + 1;
  users.push(newUser);
  res.status(201).json(newUser);
});

// PUT (update) a user
app.put('/users/:userId', (req, res) => {
  const userId = parseInt(req.params.userId);
  const updatedUser = req.body;
  const userIndex = users.findIndex((user) => user.id === userId);
  if (userIndex !== -1) {
    users[userIndex] = { ...users[userIndex], ...updatedUser };
    res.json(users[userIndex]);
  } else {
    res.status(404).send('User not found');
  }
});

// DELETE a user
app.delete('/users/:userId', (req, res) => {
  const userId = parseInt(req.params.userId);
  const userIndex = users.findIndex((user) => user.id === userId);
  if (userIndex !== -1) {
    users.splice(userIndex, 1);
    res.send('User deleted successfully!');
  } else {
    res.status(404).send('User not found');
  }
});

// Start the server
const PORT = 3000;
app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});
```

---

### **Conclusion**

Handling HTTP requests in Express.js is simple and intuitive. By using methods like `app.get()`, `app.post()`, `app.put()`, and `app.delete()`, you can build robust APIs and web applications. Middleware further enhances functionality by allowing you to preprocess requests and responses.
