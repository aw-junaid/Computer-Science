### **Designing RESTful APIs**  
REST (Representational State Transfer) is an architectural style for designing networked applications. A well-designed RESTful API is **scalable, maintainable, and user-friendly**.  

---

## **1. Principles of RESTful API Design**  
1. **Stateless** – Each request is independent and does not store client state on the server.  
2. **Client-Server Separation** – The frontend (client) and backend (server) should be separate entities.  
3. **Uniform Interface** – Consistent resource URLs, HTTP methods, and responses.  
4. **Resource-Based** – Focus on **nouns** (e.g., `/users`, `/orders`) rather than verbs.  
5. **Use HTTP Methods Properly** – Use appropriate HTTP methods for different actions.  

---

## **2. HTTP Methods and Their Usage**  
| HTTP Method | Action | Example |
|------------|--------|---------|
| **GET** | Retrieve data | `GET /users` (Get all users) |
| **POST** | Create a resource | `POST /users` (Create a new user) |
| **PUT** | Update a resource | `PUT /users/1` (Update user with ID 1) |
| **PATCH** | Partial update | `PATCH /users/1` (Update user’s email only) |
| **DELETE** | Remove a resource | `DELETE /users/1` (Delete user with ID 1) |

---

## **3. API Endpoint Design**  
A well-structured API uses **resource-based** endpoints:  
```plaintext
/users          → GET (List all users), POST (Create user)
/users/{id}     → GET (Retrieve user), PUT (Update user), DELETE (Delete user)
/orders         → GET (List all orders), POST (Create order)
/orders/{id}    → GET (Retrieve order), PUT (Update order), DELETE (Delete order)
```

### **Avoid Bad Practices**
❌ `GET /getUsers` (Don’t use verbs in URLs)  
✅ `GET /users` (Use nouns instead)  

❌ `POST /users/1/updateName` (No actions in URLs)  
✅ `PATCH /users/1` (Use HTTP methods correctly)  

---

## **4. Response Structure & Status Codes**  
A RESTful API should return **meaningful status codes** with a **structured response format**.

### **Common HTTP Status Codes**
| Status Code | Meaning |
|------------|---------|
| **200 OK** | Successful request |
| **201 Created** | Resource created |
| **204 No Content** | Successful request with no response body |
| **400 Bad Request** | Invalid request |
| **401 Unauthorized** | Authentication required |
| **403 Forbidden** | Access denied |
| **404 Not Found** | Resource not found |
| **500 Internal Server Error** | Unexpected server issue |

### **Example JSON Response**
```json
{
  "status": "success",
  "data": {
    "id": 1,
    "name": "John Doe",
    "email": "john@example.com"
  }
}
```

---

## **5. Authentication & Security**  
Security is crucial in API design. Common authentication methods include:  

### **1️⃣ API Keys** (Not very secure)  
- Users send an API key in the request headers:  
  ```http
  GET /users
  Authorization: Api-Key YOUR_API_KEY
  ```
  
### **2️⃣ OAuth 2.0 & JWT (Recommended)**  
- Use **JWT (JSON Web Tokens)** for authentication.
- Example JWT Token-based authentication:  
  ```http
  Authorization: Bearer YOUR_ACCESS_TOKEN
  ```
  
### **Security Best Practices**
✅ **Use HTTPS** (Encrypt requests)  
✅ **Validate & Sanitize Input** (Prevent SQL injection, XSS)  
✅ **Limit Rate of Requests** (Prevent abuse using rate limiting)  
✅ **Use Secure Headers** (`Content-Security-Policy`, `X-XSS-Protection`)  

---

## **6. Versioning Your API**  
APIs evolve over time, so versioning is essential.  

### **Common Versioning Strategies**
1️⃣ **URI Versioning** (Most common)  
   ```plaintext
   GET /v1/users
   GET /v2/users
   ```

2️⃣ **Header Versioning**  
   ```http
   Accept: application/vnd.myapi.v1+json
   ```

3️⃣ **Query Parameter Versioning**  
   ```plaintext
   GET /users?version=1
   ```

---

## **7. Pagination, Filtering, and Sorting**  
For large datasets, use pagination and filters to optimize performance.

### **Example: Paginated Requests**
```plaintext
GET /users?page=2&limit=10
```

### **Example: Filtering**
```plaintext
GET /users?role=admin
```

### **Example: Sorting**
```plaintext
GET /users?sort=name_asc
```

---

## **8. Rate Limiting & Caching**
To prevent abuse and optimize performance:

✅ **Rate Limiting** (e.g., Allow 100 requests per minute per user)  
✅ **Use Caching** (Store responses in memory or Redis)  
✅ **Use ETags for Efficient Data Fetching**  
```http
If-None-Match: "34dsffdfd45"
```

---

## **9. API Documentation**
Good documentation makes your API easy to use.

### **Tools for API Documentation**
- **Swagger (OpenAPI)** – `swagger.json` for API docs  
- **Postman** – API testing and documentation  
- **Redoc** – Auto-generate documentation  

Example **Swagger API Docs**:
```yaml
openapi: 3.0.0
info:
  title: User API
  version: 1.0.0
paths:
  /users:
    get:
      summary: Get all users
      responses:
        200:
          description: Success
```

---

## **Conclusion**
A well-designed RESTful API follows **resource-oriented design**, **proper HTTP methods**, and **secure authentication** while maintaining **good documentation**.  
