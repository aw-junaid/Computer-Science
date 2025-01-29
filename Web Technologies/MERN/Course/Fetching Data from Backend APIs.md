# **Fetching Data from Backend APIs in React 🚀**  

Fetching data from a **Node.js backend API** into a **React frontend** is a core part of full-stack development. In this guide, you'll learn how to:  
✅ Fetch data using **Fetch API & Axios**  
✅ Handle **errors, loading states, and dependencies**  
✅ Use **async/await** for cleaner API calls  

---

## **1. Fetching Data with Fetch API**
The `fetch()` method is a built-in way to make HTTP requests in JavaScript.

### **Example: Fetching Data in `useEffect`**
```javascript
import React, { useEffect, useState } from "react";

const App = () => {
  const [data, setData] = useState(null);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);

  useEffect(() => {
    fetch("http://localhost:5000/api/data")
      .then(response => {
        if (!response.ok) throw new Error("Network response was not ok");
        return response.json();
      })
      .then(data => {
        setData(data);
        setLoading(false);
      })
      .catch(error => {
        setError(error.message);
        setLoading(false);
      });
  }, []);

  if (loading) return <p>Loading...</p>;
  if (error) return <p>Error: {error}</p>;

  return (
    <div>
      <h1>Fetched Data</h1>
      <p>{data?.message}</p>
    </div>
  );
};

export default App;
```
✅ Handles **loading states**, **errors**, and **successful API responses**.  

---

## **2. Fetching Data with Axios (Recommended)**
### **Why Use Axios?**
✅ **Automatic JSON parsing**  
✅ **Better error handling**  
✅ **Supports request cancellation**  

### **Install Axios**
```sh
npm install axios
```

### **Example: Using Axios in `useEffect`**
```javascript
import React, { useEffect, useState } from "react";
import axios from "axios";

const App = () => {
  const [data, setData] = useState(null);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);

  useEffect(() => {
    axios.get("http://localhost:5000/api/data")
      .then(response => {
        setData(response.data);
        setLoading(false);
      })
      .catch(error => {
        setError(error.message);
        setLoading(false);
      });
  }, []);

  if (loading) return <p>Loading...</p>;
  if (error) return <p>Error: {error}</p>;

  return (
    <div>
      <h1>Fetched Data</h1>
      <p>{data?.message}</p>
    </div>
  );
};

export default App;
```
✅ **Cleaner and simpler** than `fetch()`.  

---

## **3. Using `async/await` for Fetching Data**
### **Example: Fetching with `async/await` in Axios**
```javascript
const fetchData = async () => {
  try {
    const response = await axios.get("http://localhost:5000/api/data");
    setData(response.data);
  } catch (error) {
    setError(error.message);
  } finally {
    setLoading(false);
  }
};
```
✅ **More readable** than `.then()`  

---

## **4. Fetching with API Headers (JWT Authentication)**
If your API requires **JWT authentication**, include the token in headers.

### **Backend (Express.js)**
```javascript
app.get("/api/protected", (req, res) => {
  const token = req.headers.authorization;
  if (!token) return res.status(401).json({ message: "Unauthorized" });

  res.json({ message: "Protected data" });
});
```

### **Frontend (React)**
```javascript
axios.get("http://localhost:5000/api/protected", {
  headers: { Authorization: `Bearer ${localStorage.getItem("token")}` }
})
  .then(response => console.log(response.data))
  .catch(error => console.error("Error fetching data:", error));
```
✅ **Securely fetch protected API data**  

---

## **5. Handling API Loading & Errors Gracefully**
```javascript
if (loading) return <p>Loading...</p>;
if (error) return <p style={{ color: "red" }}>Error: {error}</p>;
```
✅ Ensures **smooth user experience**  

---

## **6. Fetching Data with a Proxy**
Instead of writing full API URLs (`http://localhost:5000/api/data`), set up a **proxy**.

### **React `package.json`**
```json
"proxy": "http://localhost:5000"
```
### **Updated API Call**
```javascript
axios.get("/api/data"); // No need for full URL
```
✅ **Shorter & cleaner API calls**  

---

## **7. Optimizing API Calls (Use SWR or React Query)**
For **better performance** and **caching**, use **SWR or React Query**.

### **Install SWR**
```sh
npm install swr
```
### **Example: Fetching Data with SWR**
```javascript
import useSWR from "swr";
import axios from "axios";

const fetcher = url => axios.get(url).then(res => res.data);

const App = () => {
  const { data, error } = useSWR("/api/data", fetcher);

  if (!data) return <p>Loading...</p>;
  if (error) return <p>Error loading data</p>;

  return <p>{data.message}</p>;
};
```
✅ **Automatic caching, refetching, and fast UI updates**  

---

## **Conclusion**
✅ **Use Fetch API or Axios** for API requests  
✅ **Handle loading & errors properly**  
✅ **Use JWT headers for authentication**  
✅ **Set up a proxy to simplify API URLs**  
✅ **Optimize with SWR or React Query**  
