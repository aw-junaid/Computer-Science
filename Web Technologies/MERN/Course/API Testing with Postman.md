# **API Testing with Postman 🚀**  

Postman is a popular tool for **testing, debugging, and documenting APIs**. It allows developers to send HTTP requests, inspect responses, and automate testing.  

---

## **1. Installing Postman**
🔹 **Download & Install** → [Postman Official Site](https://www.postman.com/downloads/)  
🔹 Available on **Windows, macOS, Linux, and Web**  

---

## **2. Sending API Requests in Postman**
### **Step 1: Open Postman & Create a New Request**
- Click **"New" → "Request"**
- Select **HTTP Method** (GET, POST, PUT, DELETE, etc.)
- Enter API URL (e.g., `http://localhost:5000/api/users`)
- Click **"Send"** to execute the request

### **Step 2: Understanding HTTP Methods**
| Method  | Purpose |
|---------|---------|
| **GET**  | Retrieve data |
| **POST** | Send new data |
| **PUT**  | Update existing data |
| **DELETE** | Remove data |

📌 Example: Sending a **GET request** to retrieve users  
1️⃣ Set **Method** → `GET`  
2️⃣ Enter URL → `http://localhost:5000/api/users`  
3️⃣ Click **Send**  

✅ Response Example:  
```json
[
  { "id": 1, "name": "John Doe" },
  { "id": 2, "name": "Jane Doe" }
]
```

---

## **3. Sending POST Requests (JSON Payload)**
For `POST` requests, we send **JSON data** in the request **body**.

### **Example: Creating a User**
1️⃣ Set **Method** → `POST`  
2️⃣ URL → `http://localhost:5000/api/users`  
3️⃣ Click **Body → raw → JSON**  
4️⃣ Enter JSON data:  
```json
{
  "name": "Alice",
  "email": "alice@example.com"
}
```
5️⃣ Click **Send**  

✅ Example Response:  
```json
{
  "id": 3,
  "name": "Alice",
  "email": "alice@example.com"
}
```

---

## **4. Setting Headers (Authentication)**
For APIs requiring authentication, add **Headers**.

🔹 **Common Headers:**
| Header | Purpose |
|--------|---------|
| `Content-Type: application/json` | Sends JSON data |
| `Authorization: Bearer <TOKEN>` | Uses JWT authentication |

📌 Example: Sending a **JWT token** in headers  
1️⃣ Go to **Headers**  
2️⃣ Add → `Authorization: Bearer YOUR_JWT_TOKEN`  
3️⃣ Click **Send**  

---

## **5. Automating Tests in Postman**
Postman allows **writing tests** using JavaScript to validate API responses.

### **Example Test: Checking Response Status**
1️⃣ Click **Tests** tab  
2️⃣ Add this script:
```javascript
pm.test("Status code is 200", function () {
  pm.response.to.have.status(200);
});
```
3️⃣ Click **Send**  

✅ If status is `200`, the test **passes**!  

---

## **6. Using Postman Environment Variables**
🔹 **Variables** allow reusing values across requests.  
🔹 **Example:** Set `{{base_url}} = http://localhost:5000`  
🔹 Use `{{base_url}}/api/users` instead of hardcoding URLs.

### **Creating Variables**
1️⃣ Click **"Environments" → "New"**  
2️⃣ Add `base_url = http://localhost:5000`  
3️⃣ Use `{{base_url}}/api/users` in requests  

✅ This makes it **easy to switch environments** (Development, Staging, Production).  

---

## **7. Running API Collections (Automation)**
Postman **Collections** allow grouping multiple API requests.  

🔹 **How to Run a Collection?**  
1️⃣ Save requests into a collection  
2️⃣ Click **Runner** → Select collection  
3️⃣ Set iterations & environment  
4️⃣ Click **Run**  

✅ Useful for **CI/CD pipelines** & automated testing!  

---

## **8. Generating API Documentation**
Postman can generate **API documentation** automatically.  

1️⃣ Click **"View in Web" → "API Documentation"**  
2️⃣ Customize & share with team  
3️⃣ Users can **try APIs directly** from the docs  

✅ Makes API collaboration **super easy**!  

---

## **Conclusion**
✅ **Test API endpoints** (GET, POST, PUT, DELETE)  
✅ **Automate API testing** with JavaScript  
✅ **Use authentication headers** (JWT, API Keys)  
✅ **Set environment variables** for flexibility  
✅ **Run collections** for automation  
