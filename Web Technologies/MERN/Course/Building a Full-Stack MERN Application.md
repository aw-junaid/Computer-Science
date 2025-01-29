# **Building a Full-Stack MERN Application** 🚀

The **MERN** stack is a powerful combination of technologies that allows you to build robust, scalable, and full-featured web applications. The stack includes:

- **MongoDB**: A NoSQL database for storing data.
- **Express.js**: A lightweight web framework for Node.js that handles backend HTTP requests.
- **React.js**: A front-end JavaScript library for building user interfaces.
- **Node.js**: A JavaScript runtime that allows you to run JavaScript on the server side.

In this guide, we'll walk through how to build a full-stack MERN application. The example will include a simple to-do list app that allows users to add, view, and delete tasks.

---

## **1. Setting Up the Project**

### **Step 1: Initialize the Project**
Start by creating the project directory and initializing both the frontend (React) and backend (Node/Express) parts of your app.

#### **Backend Setup (Node.js + Express)**

1. Create a directory for the backend and navigate into it.
   ```bash
   mkdir mern-todo-app-backend
   cd mern-todo-app-backend
   ```

2. Initialize the Node.js project:
   ```bash
   npm init -y
   ```

3. Install required dependencies for Express, MongoDB, and other utilities:
   ```bash
   npm install express mongoose cors dotenv
   ```

4. Create the necessary file structure:
   ```
   mern-todo-app-backend/
   ├── models/
   ├── routes/
   ├── server.js
   └── .env
   ```

5. In `server.js`, set up the Express server and connect to MongoDB using Mongoose.

   ```javascript
   const express = require('express');
   const mongoose = require('mongoose');
   const cors = require('cors');
   require('dotenv').config();

   const app = express();
   const PORT = process.env.PORT || 5000;

   // Middleware
   app.use(cors());
   app.use(express.json());

   // MongoDB connection
   mongoose.connect(process.env.MONGODB_URI, { useNewUrlParser: true, useUnifiedTopology: true })
     .then(() => console.log('Connected to MongoDB'))
     .catch((err) => console.log('Error connecting to MongoDB:', err));

   // Routes
   app.use('/api/todos', require('./routes/todoRoutes'));

   app.listen(PORT, () => {
     console.log(`Server is running on port ${PORT}`);
   });
   ```

6. Create the `.env` file to store your MongoDB URI and other sensitive information:
   ```
   MONGODB_URI=mongodb://localhost:27017/mern-todo-app
   ```

#### **Frontend Setup (React)**

1. Create a new React app using Create React App:
   ```bash
   npx create-react-app mern-todo-app-frontend
   cd mern-todo-app-frontend
   ```

2. Install dependencies for Axios (to make API requests) and CORS handling:
   ```bash
   npm install axios
   ```

3. Create the necessary components and file structure:
   ```
   mern-todo-app-frontend/
   ├── src/
   │   ├── components/
   │   │   ├── TodoList.js
   │   │   └── TodoItem.js
   │   └── App.js
   └── package.json
   ```

---

## **2. Building the Backend API**

### **Step 2: Create the To-Do Model**

Inside the `models` folder, create a file called `Todo.js` to define the MongoDB schema for a to-do item.

```javascript
const mongoose = require('mongoose');

const todoSchema = new mongoose.Schema({
  text: {
    type: String,
    required: true,
  },
  completed: {
    type: Boolean,
    default: false,
  },
});

const Todo = mongoose.model('Todo', todoSchema);

module.exports = Todo;
```

### **Step 3: Create the To-Do Routes**

In the `routes` folder, create a file called `todoRoutes.js` to define the routes for adding, getting, and deleting to-dos.

```javascript
const express = require('express');
const Todo = require('../models/Todo');
const router = express.Router();

// Get all to-dos
router.get('/', async (req, res) => {
  try {
    const todos = await Todo.find();
    res.json(todos);
  } catch (err) {
    res.status(500).json({ message: err.message });
  }
});

// Create a new to-do
router.post('/', async (req, res) => {
  const todo = new Todo({
    text: req.body.text,
    completed: false,
  });
  try {
    const newTodo = await todo.save();
    res.status(201).json(newTodo);
  } catch (err) {
    res.status(400).json({ message: err.message });
  }
});

// Delete a to-do
router.delete('/:id', async (req, res) => {
  try {
    const todo = await Todo.findByIdAndDelete(req.params.id);
    if (!todo) {
      return res.status(404).json({ message: 'Todo not found' });
    }
    res.json({ message: 'Todo deleted' });
  } catch (err) {
    res.status(500).json({ message: err.message });
  }
});

module.exports = router;
```

---

## **3. Building the Frontend UI**

### **Step 4: Create the Todo Components**

In the `src/components/` folder, create two components: `TodoList.js` and `TodoItem.js`.

#### **TodoItem.js**:

This component will display an individual to-do item and provide a delete button.

```javascript
import React from 'react';

const TodoItem = ({ todo, onDelete }) => {
  return (
    <div>
      <span>{todo.text}</span>
      <button onClick={() => onDelete(todo._id)}>Delete</button>
    </div>
  );
};

export default TodoItem;
```

#### **TodoList.js**:

This component will fetch and display all to-dos, allowing the user to add new to-dos.

```javascript
import React, { useState, useEffect } from 'react';
import axios from 'axios';
import TodoItem from './TodoItem';

const TodoList = () => {
  const [todos, setTodos] = useState([]);
  const [newTodo, setNewTodo] = useState('');

  // Fetch todos from the backend
  useEffect(() => {
    axios.get('http://localhost:5000/api/todos')
      .then((response) => setTodos(response.data))
      .catch((error) => console.error('There was an error fetching the todos:', error));
  }, []);

  // Add a new todo
  const handleAddTodo = () => {
    if (newTodo.trim()) {
      axios.post('http://localhost:5000/api/todos', { text: newTodo })
        .then((response) => setTodos([...todos, response.data]))
        .catch((error) => console.error('There was an error adding the todo:', error));
      setNewTodo('');
    }
  };

  // Delete a todo
  const handleDeleteTodo = (id) => {
    axios.delete(`http://localhost:5000/api/todos/${id}`)
      .then(() => setTodos(todos.filter(todo => todo._id !== id)))
      .catch((error) => console.error('There was an error deleting the todo:', error));
  };

  return (
    <div>
      <h1>To-Do List</h1>
      <input
        type="text"
        value={newTodo}
        onChange={(e) => setNewTodo(e.target.value)}
        placeholder="Add a new task"
      />
      <button onClick={handleAddTodo}>Add</button>

      {todos.map((todo) => (
        <TodoItem key={todo._id} todo={todo} onDelete={handleDeleteTodo} />
      ))}
    </div>
  );
};

export default TodoList;
```

#### **App.js**:

In the `App.js` file, import and render the `TodoList` component.

```javascript
import React from 'react';
import TodoList from './components/TodoList';

const App = () => {
  return (
    <div>
      <TodoList />
    </div>
  );
};

export default App;
```

---

## **4. Running the Application**

### **Step 5: Run the Backend and Frontend**

1. **Start the Backend**:
   In the `mern-todo-app-backend` folder, run the server:
   ```bash
   node server.js
   ```

2. **Start the Frontend**:
   In the `mern-todo-app-frontend` folder, start the React development server:
   ```bash
   npm start
   ```

3. **Test the Application**:
   - Visit `http://localhost:3000` to interact with the to-do list app.
   - You can add new tasks, view them, and delete them.

---

## **5. Conclusion**

You've now built a basic **MERN** full-stack application! This app allows users to add, view, and delete to-dos, with MongoDB storing the data and React rendering the frontend.

### **Next Steps**:
- Add user authentication (JWT, OAuth).
- Enhance the UI with libraries like **Material-UI** or **Bootstrap**.
- Add more features, like task completion, filtering, and sorting.
- Deploy the app to services like **Heroku** for the backend and **Netlify** for the frontend. 

With MERN, you have all the tools needed to build modern web applications that are scalable and maintainable.
