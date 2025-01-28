### Routing and Middleware in Express.js

Routing and middleware are two of the most important concepts in Express.js. They allow you to define how your application handles incoming requests and how you can process those requests before sending a response.

---

### **1. Routing in Express.js**

Routing refers to how an application responds to client requests to specific endpoints (URIs) and HTTP methods (GET, POST, PUT, DELETE, etc.). In Express, you define routes using methods like `app.get()`, `app.post()`, `app.put()`, and `app.delete()`.

#### Basic Routing Example
```javascript
const express = require('express');
const app = express();

// Route for the root URL
app.get('/', (req, res) => {
  res.send('Welcome to the Home Page!');
});

// Route for /about
app.get('/about', (req, res) => {
  res.send('About Us');
});

// Route for /contact
app.get('/contact', (req, res) => {
  res.send('Contact Us');
});

// Start the server
const PORT = 3000;
app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});
```

#### Route Parameters
You can define dynamic routes using route parameters. These are placeholders in the URL that capture values specified in the request.

```javascript
app.get('/users/:userId', (req, res) => {
  const userId = req.params.userId;
  res.send(`User ID: ${userId}`);
});
```

#### Query Parameters
Query parameters are key-value pairs in the URL after the `?` symbol. They can be accessed using `req.query`.

```javascript
app.get('/search', (req, res) => {
  const query = req.query.q;
  res.send(`Search Query: ${query}`);
});
```

#### Handling Different HTTP Methods
Express supports all HTTP methods. Here’s an example of handling POST requests:

```javascript
app.post('/submit', (req, res) => {
  res.send('Form Submitted!');
});
```

---

### **2. Middleware in Express.js**

Middleware functions are functions that have access to the request (`req`), response (`res`), and the `next` function in the application’s request-response cycle. Middleware can:
- Execute any code.
- Modify the request or response objects.
- End the request-response cycle.
- Call the next middleware in the stack.

#### Types of Middleware
1. **Application-level Middleware**:
   - Applied to the entire application using `app.use()`.
   - Example:
     ```javascript
     app.use((req, res, next) => {
       console.log('Time:', Date.now());
       next();
     });
     ```

2. **Router-level Middleware**:
   - Applied to specific routes using `router.use()`.
   - Example:
     ```javascript
     const router = express.Router();
     router.use((req, res, next) => {
       console.log('Router Middleware');
       next();
     });
     ```

3. **Error-handling Middleware**:
   - Used to handle errors. It must have four arguments: `(err, req, res, next)`.
   - Example:
     ```javascript
     app.use((err, req, res, next) => {
       console.error(err.stack);
       res.status(500).send('Something broke!');
     });
     ```

4. **Built-in Middleware**:
   - Express provides built-in middleware like `express.json()` and `express.static()`.
   - Example:
     ```javascript
     app.use(express.json()); // Parse JSON request bodies
     app.use(express.static('public')); // Serve static files
     ```

5. **Third-party Middleware**:
   - Middleware provided by third-party libraries, such as `body-parser`, `cors`, and `morgan`.
   - Example:
     ```javascript
     const cors = require('cors');
     app.use(cors()); // Enable CORS
     ```

#### Middleware Example: Logging and Authentication
Here’s an example of using middleware for logging and authentication:

```javascript
// Logging Middleware
app.use((req, res, next) => {
  console.log(`${req.method} ${req.url}`);
  next();
});

// Authentication Middleware
const authenticate = (req, res, next) => {
  const authToken = req.headers['authorization'];
  if (authToken === 'secret-token') {
    next();
  } else {
    res.status(401).send('Unauthorized');
  }
};

// Protected Route
app.get('/protected', authenticate, (req, res) => {
  res.send('Welcome to the Protected Route!');
});
```

---

### **3. Combining Routing and Middleware**

You can combine routing and middleware to create modular and maintainable applications. For example, you can use the `express.Router` class to create modular route handlers.

#### Example: Modular Routing with Middleware
```javascript
const express = require('express');
const app = express();

// Middleware for logging
app.use((req, res, next) => {
  console.log(`${req.method} ${req.url}`);
  next();
});

// Router for /users
const userRouter = express.Router();
userRouter.get('/', (req, res) => {
  res.send('User List');
});

userRouter.get('/:userId', (req, res) => {
  res.send(`User ID: ${req.params.userId}`);
});

// Mount the router
app.use('/users', userRouter);

// Start the server
const PORT = 3000;
app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});
```

---

### **4. Common Middleware Libraries**

Here are some popular third-party middleware libraries for Express:
- **`body-parser`**: Parse incoming request bodies.
- **`cors`**: Enable Cross-Origin Resource Sharing (CORS).
- **`morgan`**: Log HTTP requests.
- **`helmet`**: Secure your app by setting HTTP headers.
- **`cookie-parser`**: Parse cookies.

To use these, install them via npm:
```bash
npm install body-parser cors morgan helmet cookie-parser
```

Example usage:
```javascript
const bodyParser = require('body-parser');
const cors = require('cors');
const morgan = require('morgan');
const helmet = require('helmet');
const cookieParser = require('cookie-parser');

app.use(bodyParser.json());
app.use(cors());
app.use(morgan('dev'));
app.use(helmet());
app.use(cookieParser());
```

---

### **Conclusion**

Routing and middleware are fundamental to building Express applications. Routing allows you to define how your application responds to client requests, while middleware enables you to process requests and responses in a modular and reusable way. By combining these concepts, you can create powerful and scalable web applications and APIs.
