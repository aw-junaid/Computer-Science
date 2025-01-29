# **Handling Authentication in React 🚀**  

Authentication is crucial for protecting **user data** and ensuring **secure access** to your application. This guide explains how to handle authentication in a **React app**, including **login, registration, and token-based authentication** using **JWT (JSON Web Token)**.

---

## **1. Basic Authentication Flow**
### **Steps Involved:**
1. **User logs in** by providing credentials (e.g., username and password).
2. The **React app** sends the credentials to the backend (Node.js/Express).
3. The backend **validates the credentials** and, if correct, sends back a **JWT token**.
4. The React app **stores the token** (usually in **localStorage** or **sessionStorage**).
5. For **protected routes**, the token is sent along with API requests in the **Authorization header**.

---

## **2. Backend Setup (Node.js/Express with JWT)**

### **Install Dependencies**
```sh
npm install jsonwebtoken bcryptjs
```

### **Example: Backend Authentication**
```javascript
const express = require("express");
const jwt = require("jsonwebtoken");
const bcrypt = require("bcryptjs");
const app = express();

app.use(express.json()); // Parse JSON bodies

// Mock user database (for example purposes)
const users = [{ id: 1, username: "admin", password: "password123" }];

app.post("/login", async (req, res) => {
  const { username, password } = req.body;
  
  const user = users.find(u => u.username === username);
  if (!user) return res.status(400).json({ message: "User not found" });

  const isValidPassword = await bcrypt.compare(password, user.password);
  if (!isValidPassword) return res.status(400).json({ message: "Invalid credentials" });

  const token = jwt.sign({ id: user.id, username: user.username }, "SECRET_KEY", { expiresIn: "1h" });
  res.json({ token });
});

// Protected Route
app.get("/protected", (req, res) => {
  const token = req.headers.authorization?.split(" ")[1]; // Extract token from header
  if (!token) return res.status(401).json({ message: "Unauthorized" });

  jwt.verify(token, "SECRET_KEY", (err, user) => {
    if (err) return res.status(403).json({ message: "Forbidden" });
    res.json({ message: "Protected data", user });
  });
});

app.listen(5000, () => {
  console.log("Server running on port 5000");
});
```
✅ The backend sends back a **JWT** after successful login.  

---

## **3. Frontend Setup (React)**

### **Install Axios (for API requests)**
```sh
npm install axios
```

### **Handling Login and Storing JWT in LocalStorage**

```javascript
import React, { useState } from "react";
import axios from "axios";

const Login = () => {
  const [username, setUsername] = useState("");
  const [password, setPassword] = useState("");
  const [error, setError] = useState("");

  const handleSubmit = async (e) => {
    e.preventDefault();

    try {
      const response = await axios.post("http://localhost:5000/login", { username, password });
      const token = response.data.token;
      localStorage.setItem("token", token); // Store token in localStorage
      window.location.href = "/dashboard"; // Redirect to protected page
    } catch (err) {
      setError(err.response?.data.message || "Error logging in");
    }
  };

  return (
    <div>
      <h2>Login</h2>
      <form onSubmit={handleSubmit}>
        <input
          type="text"
          placeholder="Username"
          value={username}
          onChange={(e) => setUsername(e.target.value)}
        />
        <input
          type="password"
          placeholder="Password"
          value={password}
          onChange={(e) => setPassword(e.target.value)}
        />
        <button type="submit">Login</button>
      </form>
      {error && <p>{error}</p>}
    </div>
  );
};

export default Login;
```
✅ After successful login, the token is stored in **localStorage**.  

---

## **4. Protecting Routes with JWT**

You can protect certain routes by checking whether a **JWT token** is present and valid.

### **Protected Route Example**

```javascript
import React, { useEffect, useState } from "react";
import axios from "axios";

const ProtectedRoute = () => {
  const [message, setMessage] = useState("");

  useEffect(() => {
    const token = localStorage.getItem("token");

    if (!token) {
      window.location.href = "/login"; // Redirect to login if no token
      return;
    }

    axios.get("http://localhost:5000/protected", {
      headers: { Authorization: `Bearer ${token}` }
    })
      .then(response => setMessage(response.data.message))
      .catch(error => console.log(error));
  }, []);

  return (
    <div>
      <h1>Protected Route</h1>
      <p>{message}</p>
    </div>
  );
};

export default ProtectedRoute;
```
✅ This route is only accessible if the user is **authenticated** with a valid token.  

---

## **5. Logging Out and Clearing Token**

To log the user out, simply **clear the JWT token** from **localStorage**.

### **Logout Example**
```javascript
const handleLogout = () => {
  localStorage.removeItem("token"); // Remove token from localStorage
  window.location.href = "/login"; // Redirect to login page
};
```
✅ The user is logged out and redirected to the login page.  

---

## **6. Handling JWT Expiration**
JWT tokens are time-limited, and if the token expires, you'll need to ask the user to log in again. You can handle this by checking for **401 Unauthorized errors**.

```javascript
axios.get("/protected")
  .then(response => console.log(response.data))
  .catch(error => {
    if (error.response?.status === 401) {
      window.location.href = "/login"; // Redirect to login if unauthorized
    }
  });
```

---

## **Conclusion**
✅ Use **JWT** for authentication in React apps  
✅ Store JWT in **localStorage** or **sessionStorage**  
✅ Protect routes by verifying the **JWT token**  
✅ Handle **login, logout, and token expiration** gracefully  
✅ Use **Axios** for API requests and pass the token in **Authorization headers**  
