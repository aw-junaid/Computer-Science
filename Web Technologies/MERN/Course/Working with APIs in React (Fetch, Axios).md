Working with APIs in React is a crucial skill for fetching and sending data to a backend. Two common ways to make HTTP requests in React are using the **Fetch API** and **Axios**.

---

## **1. Fetch API**
The Fetch API is a built-in JavaScript feature for making HTTP requests.

### **Example: Fetching Data**
```jsx
import { useState, useEffect } from "react";

const FetchExample = () => {
  const [data, setData] = useState(null);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    fetch("https://jsonplaceholder.typicode.com/posts")
      .then((response) => response.json())
      .then((data) => {
        setData(data);
        setLoading(false);
      })
      .catch((error) => {
        console.error("Error fetching data:", error);
        setLoading(false);
      });
  }, []);

  return (
    <div>
      <h2>Fetch API Example</h2>
      {loading ? <p>Loading...</p> : <pre>{JSON.stringify(data, null, 2)}</pre>}
    </div>
  );
};

export default FetchExample;
```

### **Posting Data with Fetch**
```jsx
const postData = async () => {
  try {
    const response = await fetch("https://jsonplaceholder.typicode.com/posts", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({ title: "New Post", body: "This is a test post." }),
    });

    const result = await response.json();
    console.log(result);
  } catch (error) {
    console.error("Error:", error);
  }
};

postData();
```

---

## **2. Axios**
Axios is a popular library for making HTTP requests in React. It simplifies API calls with better error handling and built-in request/response transformations.

### **Installation**
```sh
npm install axios
```

### **Example: Fetching Data with Axios**
```jsx
import { useState, useEffect } from "react";
import axios from "axios";

const AxiosExample = () => {
  const [data, setData] = useState(null);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    axios.get("https://jsonplaceholder.typicode.com/posts")
      .then((response) => {
        setData(response.data);
        setLoading(false);
      })
      .catch((error) => {
        console.error("Error fetching data:", error);
        setLoading(false);
      });
  }, []);

  return (
    <div>
      <h2>Axios Example</h2>
      {loading ? <p>Loading...</p> : <pre>{JSON.stringify(data, null, 2)}</pre>}
    </div>
  );
};

export default AxiosExample;
```

### **Posting Data with Axios**
```jsx
const postData = async () => {
  try {
    const response = await axios.post("https://jsonplaceholder.typicode.com/posts", {
      title: "New Post",
      body: "This is a test post.",
    });

    console.log(response.data);
  } catch (error) {
    console.error("Error:", error);
  }
};

postData();
```

---

## **Fetch vs Axios: Which One to Use?**
| Feature         | Fetch API | Axios |
|----------------|----------|-------|
| Built-in       | ✅ Yes  | ❌ No (Needs installation) |
| JSON Parsing   | ❌ Manual (`response.json()`) | ✅ Automatic |
| Error Handling | ❌ Needs `response.ok` check | ✅ Built-in |
| Request Cancellation | ❌ No | ✅ Yes (via `CancelToken`) |
| Interceptors   | ❌ No | ✅ Yes |
| Timeout Support | ❌ No | ✅ Yes |

### **When to Use?**
- **Use Fetch** if you want a native, lightweight solution.
- **Use Axios** for advanced features like interceptors, automatic JSON handling, and request cancellation.
