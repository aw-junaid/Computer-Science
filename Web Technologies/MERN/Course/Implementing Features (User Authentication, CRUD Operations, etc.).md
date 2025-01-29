# **Implementing Features in a Full-Stack MERN Application** 🚀

Once your project planning and design phase is complete, it's time to start implementing the core features of your application. In this guide, we'll go over how to implement essential features such as **User Authentication**, **CRUD Operations**, and other critical functionality in a full-stack **MERN** application.

We'll build on the **To-Do List Application** example, adding user authentication and allowing users to perform CRUD operations on their to-do items.

---

## **1. User Authentication with JWT**

### **Step 1: Setup User Model**

To enable user authentication, we first need to create a **User model** in the backend (Express/MongoDB).

In `models/User.js`:

```javascript
const mongoose = require('mongoose');
const bcrypt = require('bcryptjs'); // For hashing passwords
const jwt = require('jsonwebtoken'); // For creating JSON Web Tokens

const userSchema = new mongoose.Schema({
  email: {
    type: String,
    required: true,
    unique: true,
  },
  password: {
    type: String,
    required: true,
  },
});

// Hash password before saving the user
userSchema.pre('save', async function (next) {
  if (!this.isModified('password')) {
    return next();
  }

  const salt = await bcrypt.genSalt(10);
  this.password = await bcrypt.hash(this.password, salt);
  next();
});

// Compare the entered password with the stored hash
userSchema.methods.matchPassword = async function (enteredPassword) {
  return await bcrypt.compare(enteredPassword, this.password);
};

// Generate a JSON Web Token
userSchema.methods.generateAuthToken = function () {
  const token = jwt.sign({ id: this._id }, process.env.JWT_SECRET, { expiresIn: '1h' });
  return token;
};

const User = mongoose.model('User', userSchema);

module.exports = User;
```

### **Step 2: Create Authentication Routes**

Create routes for **registering**, **logging in**, and **protected routes** that require authentication.

In `routes/authRoutes.js`:

```javascript
const express = require('express');
const User = require('../models/User');
const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');
const router = express.Router();

// Register a new user
router.post('/register', async (req, res) => {
  const { email, password } = req.body;
  try {
    const userExists = await User.findOne({ email });
    if (userExists) {
      return res.status(400).json({ message: 'User already exists' });
    }
    const user = new User({ email, password });
    await user.save();
    const token = user.generateAuthToken();
    res.status(201).json({ token });
  } catch (err) {
    res.status(500).json({ message: 'Server error' });
  }
});

// Login a user
router.post('/login', async (req, res) => {
  const { email, password } = req.body;
  try {
    const user = await User.findOne({ email });
    if (!user || !(await user.matchPassword(password))) {
      return res.status(400).json({ message: 'Invalid credentials' });
    }
    const token = user.generateAuthToken();
    res.json({ token });
  } catch (err) {
    res.status(500).json({ message: 'Server error' });
  }
});

// Middleware to protect routes
const protect = async (req, res, next) => {
  const token = req.header('Authorization')?.replace('Bearer ', '');
  if (!token) {
    return res.status(401).json({ message: 'No token, authorization denied' });
  }

  try {
    const decoded = jwt.verify(token, process.env.JWT_SECRET);
    req.user = await User.findById(decoded.id).select('-password');
    next();
  } catch (err) {
    res.status(401).json({ message: 'Token is not valid' });
  }
};

module.exports = { router, protect };
```

### **Step 3: Update `server.js`**

Import and use the new authentication routes in your `server.js`.

```javascript
const express = require('express');
const mongoose = require('mongoose');
const cors = require('cors');
require('dotenv').config();
const authRoutes = require('./routes/authRoutes');
const { router: authRouter, protect } = authRoutes;

const app = express();
const PORT = process.env.PORT || 5000;

app.use(cors());
app.use(express.json());

// MongoDB connection
mongoose.connect(process.env.MONGODB_URI, { useNewUrlParser: true, useUnifiedTopology: true })
  .then(() => console.log('Connected to MongoDB'))
  .catch((err) => console.log('Error connecting to MongoDB:', err));

// Use authentication routes
app.use('/api/auth', authRouter);

// Other routes...
app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});
```

### **Step 4: Frontend Authentication**

In your React app, you'll need to handle authentication by allowing users to register, log in, and store their JWT in localStorage or context.

#### **AuthContext.js** (for context-based authentication)

```javascript
import { createContext, useState, useEffect } from 'react';

export const AuthContext = createContext();

export const AuthProvider = ({ children }) => {
  const [user, setUser] = useState(null);

  useEffect(() => {
    const token = localStorage.getItem('authToken');
    if (token) {
      // Set the user from the token or make an API call to fetch user data
      setUser({ token });
    }
  }, []);

  const login = (token) => {
    localStorage.setItem('authToken', token);
    setUser({ token });
  };

  const logout = () => {
    localStorage.removeItem('authToken');
    setUser(null);
  };

  return (
    <AuthContext.Provider value={{ user, login, logout }}>
      {children}
    </AuthContext.Provider>
  );
};
```

---

## **2. CRUD Operations (Create, Read, Update, Delete)**

Now, let’s focus on adding CRUD functionality for managing **to-do items**.

### **Step 1: Create the To-Do Model**

In `models/Todo.js`, create a schema for a to-do:

```javascript
const mongoose = require('mongoose');

const todoSchema = new mongoose.Schema({
  userId: {
    type: mongoose.Schema.Types.ObjectId,
    ref: 'User',
    required: true,
  },
  title: {
    type: String,
    required: true,
  },
  description: {
    type: String,
    required: false,
  },
  completed: {
    type: Boolean,
    default: false,
  },
}, { timestamps: true });

const Todo = mongoose.model('Todo', todoSchema);

module.exports = Todo;
```

### **Step 2: Create the To-Do Routes**

Define routes for **CRUD operations**:

In `routes/todoRoutes.js`:

```javascript
const express = require('express');
const Todo = require('../models/Todo');
const { protect } = require('./authRoutes');  // Protect routes with authentication
const router = express.Router();

// Create a new to-do
router.post('/', protect, async (req, res) => {
  const { title, description } = req.body;
  try {
    const newTodo = new Todo({
      userId: req.user._id,
      title,
      description,
    });
    await newTodo.save();
    res.status(201).json(newTodo);
  } catch (err) {
    res.status(500).json({ message: 'Server error' });
  }
});

// Get all to-dos for a user
router.get('/', protect, async (req, res) => {
  try {
    const todos = await Todo.find({ userId: req.user._id });
    res.json(todos);
  } catch (err) {
    res.status(500).json({ message: 'Server error' });
  }
});

// Update a to-do
router.put('/:id', protect, async (req, res) => {
  const { title, description, completed } = req.body;
  try {
    const todo = await Todo.findOneAndUpdate(
      { _id: req.params.id, userId: req.user._id },
      { title, description, completed },
      { new: true }
    );
    if (!todo) {
      return res.status(404).json({ message: 'Todo not found' });
    }
    res.json(todo);
  } catch (err) {
    res.status(500).json({ message: 'Server error' });
  }
});

// Delete a to-do
router.delete('/:id', protect, async (req, res) => {
  try {
    const todo = await Todo.findOneAndDelete({ _id: req.params.id, userId: req.user._id });
    if (!todo) {
      return res.status(404).json({ message: 'Todo not found' });
    }
    res.json({ message: 'Todo deleted' });
  } catch (err) {
    res.status(500).json({ message: 'Server error' });
  }
});

module.exports = router;
```

### **Step 3: Update `server.js` to Use To-Do Routes**

```javascript
const todoRoutes = require('./routes/todoRoutes');

// Use todo routes
app.use('/api/todos', todoRoutes);
```

### **Step 4: Frontend CRUD Operations**

In your React app, you will need to integrate the CRUD API calls using **Axios** for making requests.

For example, in `TodoList.js`, you can create, update, and delete to-dos by calling the backend API endpoints.

---

## **3. Final Thoughts**

- **User Authentication**: We used **JWT** for stateless authentication and protected routes by checking the token in the request headers.
- **CRUD Operations**: We added routes for creating, reading, updating, and deleting to-do items, ensuring they are only accessible by authenticated users.
- **Frontend Integration**: We connected the backend functionality with the frontend using React context and Axios for API calls.

These steps give you the building blocks to implement features like user authentication and CRUD operations in your full-stack MERN application. You can extend these features to add more complex functionality like role-based access, password reset, and more!
