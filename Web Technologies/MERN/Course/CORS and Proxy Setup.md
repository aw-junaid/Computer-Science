# **CORS & Proxy Setup in React + Node.js 🚀**  

When connecting a **React frontend** with a **Node.js backend**, you may run into **CORS (Cross-Origin Resource Sharing) errors**. This guide explains how to **fix CORS issues** and use a **proxy** to simplify API requests.  

---

## **1. Understanding CORS Errors**  
CORS errors occur when a frontend running on `http://localhost:3000` tries to access a backend on `http://localhost:5000`. Browsers block these **cross-origin requests** for security reasons.  

🔴 **Example CORS Error in Console:**  
```
Access to fetch at 'http://localhost:5000/api/data' from origin 'http://localhost:3000' has been blocked by CORS policy.
```
✅ **Solution:** Enable CORS on the backend.

---

## **2. Fixing CORS in Node.js (Express)**
### **Step 1: Install CORS Middleware**
```sh
npm install cors
```
### **Step 2: Use CORS in `server.js`**
```javascript
const express = require("express");
const cors = require("cors");

const app = express();
app.use(express.json());

// Allow all origins (Not recommended for production)
app.use(cors());

// Allow specific origins
app.use(cors({
  origin: "http://localhost:3000",
  methods: "GET,POST,PUT,DELETE",
  allowedHeaders: "Content-Type,Authorization"
}));

app.get("/api/data", (req, res) => {
  res.json({ message: "CORS enabled!" });
});

app.listen(5000, () => console.log("Server running on port 5000"));
```
✅ Now, React can access the API without CORS errors.  

---

## **3. Proxy Setup in React (Avoiding Full URLs)**
Instead of writing full URLs (`http://localhost:5000/api/data`) in React, use a **proxy** to automatically redirect API requests.

### **Step 1: Add Proxy in `package.json`**
Inside your React app (`frontend/package.json`):
```json
"proxy": "http://localhost:5000"
```
### **Step 2: Update API Calls**
Before Proxy:
```javascript
axios.get("http://localhost:5000/api/data")
  .then(res => console.log(res.data));
```
After Proxy:
```javascript
axios.get("/api/data") // No need for full URL
  .then(res => console.log(res.data));
```
✅ Requests to `/api/data` automatically go to `http://localhost:5000/api/data`.  

---

## **4. CORS with JWT Authentication**
If your API requires authentication, allow the `Authorization` header.

### **Backend (`server.js`)**
```javascript
app.use(cors({
  origin: "http://localhost:3000",
  methods: "GET,POST",
  allowedHeaders: "Content-Type,Authorization"
}));
```
### **Frontend API Call**
```javascript
axios.get("/api/protected", {
  headers: { Authorization: `Bearer ${localStorage.getItem("token")}` }
});
```
✅ Allows secure authentication with JWT tokens.  

---

## **5. Handling CORS in Production**
In production, use **Nginx or API Gateway** to handle CORS.  

Example **Nginx Config (Reverse Proxy)**:
```nginx
server {
  location / {
    proxy_pass http://localhost:5000;
    add_header 'Access-Control-Allow-Origin' '*' always;
  }
}
```
✅ This ensures **CORS is managed at the server level** instead of the application.  

---

## **Conclusion**
✅ **Enable CORS** in Express using middleware  
✅ **Use a proxy** in React to simplify API calls  
✅ **Allow authentication headers** for secure APIs  
✅ **Use Nginx or API Gateway** for production CORS handling  
