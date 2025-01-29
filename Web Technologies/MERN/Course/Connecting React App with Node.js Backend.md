# **Connecting a React App with a Node.js Backend 🚀**  

Integrating a **React frontend** with a **Node.js (Express) backend** is a common approach for **full-stack development**. This guide covers:  
✅ Setting up a **Node.js API** (backend)  
✅ Connecting **React (frontend)** to the API  
✅ Handling **CORS & API requests**  

---

## **1. Setting Up a Node.js Backend (Express API)**
### **Step 1: Initialize a Node.js Project**
```sh
mkdir backend && cd backend
npm init -y
```
### **Step 2: Install Dependencies**
```sh
npm install express cors dotenv
```

### **Step 3: Create `server.js`**
```javascript
const express = require("express");
const cors = require("cors");
require("dotenv").config();

const app = express();
const PORT = process.env.PORT || 5000;

// Middleware
app.use(cors()); // Allow cross-origin requests
app.use(express.json()); // Parse JSON data

// Routes
app.get("/api/message", (req, res) => {
  res.json({ message: "Hello from Node.js backend!" });
});

// Start server
app.listen(PORT, () => {
  console.log(`Server running on http://localhost:${PORT}`);
});
```
### **Step 4: Start the Server**
```sh
node server.js
```
✅ API should be running at **`http://localhost:5000/api/message`**

---

## **2. Creating a React Frontend**
### **Step 1: Create a React App**
```sh
npx create-react-app frontend
cd frontend
```
### **Step 2: Install Axios (for API requests)**
```sh
npm install axios
```
### **Step 3: Fetch API Data in React**
Open `src/App.js` and update it:
```javascript
import React, { useEffect, useState } from "react";
import axios from "axios";

const App = () => {
  const [message, setMessage] = useState("");

  useEffect(() => {
    axios.get("http://localhost:5000/api/message")
      .then(response => setMessage(response.data.message))
      .catch(error => console.error("Error fetching data:", error));
  }, []);

  return (
    <div>
      <h1>React + Node.js API</h1>
      <p>{message}</p>
    </div>
  );
};

export default App;
```
### **Step 4: Start React App**
```sh
npm start
```
✅ The React app should display:  
👉 `"Hello from Node.js backend!"`  

---

## **3. Handling CORS Issues**
If the React frontend is **blocked from accessing the backend**, enable **CORS** in `server.js`:

```javascript
app.use(cors({ origin: "http://localhost:3000" }));
```
✅ Allows only `http://localhost:3000` to access the API  

---

## **4. Proxy Configuration (Optional)**
To avoid specifying `http://localhost:5000` in every request, add a **proxy** in `frontend/package.json`:

```json
"proxy": "http://localhost:5000"
```
Then update the request in `App.js`:
```javascript
axios.get("/api/message") // No need for full URL
```
✅ Now, requests are automatically redirected to the backend  

---

## **5. Connecting React with a Secure Backend (JWT Authentication)**
🔹 **Backend (Generate JWT Token)**
```sh
npm install jsonwebtoken
```
```javascript
const jwt = require("jsonwebtoken");

app.post("/api/login", (req, res) => {
  const user = { id: 1, username: "admin" };
  const token = jwt.sign(user, "SECRET_KEY", { expiresIn: "1h" });
  res.json({ token });
});
```
🔹 **Frontend (Store and Use JWT)**
```javascript
axios.post("http://localhost:5000/api/login")
  .then(response => localStorage.setItem("token", response.data.token));

axios.get("/api/protected", {
  headers: { Authorization: `Bearer ${localStorage.getItem("token")}` }
});
```
✅ Secure **API access with JWT authentication**  

---

## **Conclusion**
🎯 **React + Node.js** integration enables **full-stack development**  
🎯 Use **Axios** to fetch API data  
🎯 Handle **CORS issues** for cross-origin requests  
🎯 Use **JWT authentication** for secure backend access  
