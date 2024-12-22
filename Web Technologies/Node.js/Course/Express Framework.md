### **Node.js - Express Framework**

**Express.js** is a minimal and flexible web application framework built on top of Node.js. It simplifies the process of creating web servers, handling HTTP requests, and routing, making it a popular choice for building web applications and APIs. Express provides a robust set of features for developing web and mobile applications, including routing, middleware support, template engines, and integration with databases.

---

### **Why Use Express?**

- **Simplified Routing**: Express simplifies the routing of HTTP requests. It allows you to handle different types of HTTP requests (GET, POST, PUT, DELETE) for specific URL paths in a clean and concise manner.
- **Middleware Support**: Express supports middleware, which can be used for logging, authentication, validation, error handling, and more.
- **Modular**: You can add functionality by including external libraries or plugins as middleware.
- **Template Engines**: Express supports templating engines like Pug, EJS, and Handlebars to render dynamic HTML pages.
- **Easy Integration**: It works well with various databases like MongoDB, MySQL, and PostgreSQL and integrates easily with tools like Passport for authentication.

---

### **Installing Express**

To get started with Express, you need to install it in your Node.js project. Follow these steps:

1. **Initialize a New Node.js Project**  
   If you haven't already, create a `package.json` file for your project by running:
   
   ```bash
   npm init -y
   ```

2. **Install Express**  
   Install Express via npm:
   
   ```bash
   npm install express --save
   ```

3. **Create a Simple Express Server**  
   Create an `app.js` file (or any other name you prefer) and write the following code to set up a basic Express server:
   
   ```javascript
   const express = require('express');
   const app = express();

   // Define a route for the home page
   app.get('/', (req, res) => {
       res.send('Hello, World!');
   });

   // Start the server
   const PORT = process.env.PORT || 3000;
   app.listen(PORT, () => {
       console.log(`Server is running on port ${PORT}`);
   });
   ```

4. **Run the Application**  
   Run the server with Node.js:
   
   ```bash
   node app.js
   ```

   Now, if you visit `http://localhost:3000`, you should see the message "Hello, World!"

---

### **Basic Concepts of Express**

#### **1. Routing**

Express allows you to define routes for handling different types of HTTP requests. These routes map HTTP methods (GET, POST, PUT, DELETE) and paths to functions that handle the requests.

Example:

```javascript
// Handle GET requests to the home page
app.get('/', (req, res) => {
    res.send('Hello from GET!');
});

// Handle POST requests
app.post('/submit', (req, res) => {
    res.send('Data received via POST!');
});
```

#### **2. Middleware**

Middleware functions are functions that have access to the request, response, and the next middleware function in the application’s request-response cycle. Middleware is typically used for logging, authentication, input validation, and error handling.

- **Built-in Middleware**: Express comes with some built-in middleware, like `express.json()` for parsing JSON bodies and `express.static()` for serving static files.

Example:

```javascript
// Middleware to log request method and URL
app.use((req, res, next) => {
    console.log(`${req.method} ${req.url}`);
    next(); // Pass control to the next middleware
});

// Middleware to parse incoming JSON
app.use(express.json());
```

- **Custom Middleware**: You can also define your own custom middleware:

```javascript
const myMiddleware = (req, res, next) => {
    console.log('This is my custom middleware');
    next();
};

app.use(myMiddleware);
```

#### **3. Handling Request Parameters**

Express provides easy access to query parameters, route parameters, and request bodies.

- **Route Parameters**: Used to capture values from the URL.

Example:

```javascript
// Capture a parameter from the URL (e.g., /user/123)
app.get('/user/:id', (req, res) => {
    const userId = req.params.id;
    res.send(`User ID is ${userId}`);
});
```

- **Query Parameters**: Passed as key-value pairs in the URL after the `?`.

Example:

```javascript
// Capture query parameters (e.g., /search?q=node)
app.get('/search', (req, res) => {
    const query = req.query.q;
    res.send(`Search query: ${query}`);
});
```

- **Request Body**: For handling POST, PUT, or PATCH requests with data in the body.

Example:

```javascript
// Capture request body (e.g., via POST request)
app.post('/submit', (req, res) => {
    const data = req.body;
    res.send(`Received data: ${JSON.stringify(data)}`);
});
```

To parse JSON in the request body, use the `express.json()` middleware.

#### **4. Serving Static Files**

Express can be used to serve static files such as HTML, CSS, JavaScript, images, etc., from a specified directory.

Example:

```javascript
// Serve static files from the 'public' directory
app.use(express.static('public'));
```

If you have a file `public/index.html`, it will be accessible at `http://localhost:3000/index.html`.

#### **5. Template Engines**

Express supports various template engines for rendering dynamic HTML pages. Some common ones include **EJS**, **Pug**, and **Handlebars**.

To use EJS, install it first:

```bash
npm install ejs
```

Then set it as the view engine:

```javascript
app.set('view engine', 'ejs');

// Render a template (views/home.ejs)
app.get('/', (req, res) => {
    res.render('home', { title: 'Express', message: 'Welcome to Express!' });
});
```

You need to create a `views` directory for the templates, and `home.ejs` would look like:

```html
<h1><%= title %></h1>
<p><%= message %></p>
```

---

### **6. Error Handling**

Handling errors in Express can be done using middleware. You can create a custom error-handling middleware that catches all errors and sends an appropriate response.

Example:

```javascript
// Error handling middleware (must be defined after all routes)
app.use((err, req, res, next) => {
    console.error(err.stack);
    res.status(500).send('Something went wrong!');
});
```

---

### **7. Routing with Express Router**

For larger applications, Express provides the `Router` to modularize routes into separate files, making the code cleaner and more maintainable.

Example of defining a route in a separate file (`routes/user.js`):

```javascript
const express = require('express');
const router = express.Router();

// Define route handlers for /user
router.get('/', (req, res) => {
    res.send('User route');
});

router.get('/:id', (req, res) => {
    const userId = req.params.id;
    res.send(`User ID: ${userId}`);
});

module.exports = router;
```

In the main `app.js` file, import and use the `Router`:

```javascript
const userRouter = require('./routes/user');
app.use('/user', userRouter);
```

Now, requests to `/user` will be handled by `routes/user.js`.

---

### **8. Connecting to a Database**

Express can be integrated with databases such as **MongoDB**, **MySQL**, and **PostgreSQL**. Here's a basic example using **MongoDB** and the **Mongoose** ORM:

1. **Install Mongoose**:

   ```bash
   npm install mongoose
   ```

2. **Connect to MongoDB**:

   ```javascript
   const mongoose = require('mongoose');
   mongoose.connect('mongodb://localhost/mydb', { useNewUrlParser: true, useUnifiedTopology: true });

   mongoose.connection.on('connected', () => {
       console.log('Connected to MongoDB');
   });
   ```

3. **Define a Model**:

   ```javascript
   const Schema = mongoose.Schema;
   const userSchema = new Schema({
       name: String,
       email: String
   });

   const User = mongoose.model('User', userSchema);
   ```

4. **Use the Model in Routes**:

   ```javascript
   app.post('/user', (req, res) => {
       const newUser = new User(req.body);
       newUser.save()
           .then(user => res.send(user))
           .catch(err => res.status(400).send(err));
   });
   ```

---

### **Conclusion**

Express.js is a powerful framework for building web applications and APIs with Node.js. It simplifies routing, middleware handling, and the management of request parameters, making it easier to develop robust and scalable applications. With support for template engines, static file serving, database integration, and error handling, Express is a go-to framework for many Node.js developers. Whether you are building simple APIs or full-fledged web applications, Express can help you streamline your development process.
