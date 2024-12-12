### **Fetch API - Credentials**

In the **Fetch API**, the `credentials` option controls whether cookies and HTTP authentication information are sent with the request. This is especially useful when dealing with cross-origin requests (requests to a different domain) or when you need to send session cookies along with the request.

The `credentials` option can take one of three values:

1. **`same-origin`** (default)
2. **`include`**
3. **`omit`**

---

### **1. `same-origin` (default)**

The default value for `credentials` is `same-origin`. This means that cookies will be sent only if the request is made to the same origin as the calling script. If the request is cross-origin (to a different domain), no cookies or authentication information will be sent.

#### **Example: Same-Origin Request (default behavior)**

```javascript
fetch('https://api.example.com/data', {
  method: 'GET',
  credentials: 'same-origin',  // Default behavior: sends cookies only for same-origin requests
})
  .then(response => response.json())
  .then(data => console.log(data))
  .catch(error => console.error('Error:', error));
```

- **Same-origin** requests (requests to the same domain) will include any cookies set by the server, as long as they are within the same origin.

---

### **2. `include`**

When `credentials: 'include'` is used, cookies and authentication data are sent with both same-origin and cross-origin requests. This is useful for situations where you need to send cookies to another domain (such as when you're making requests to an API hosted on a different domain but want to preserve authentication states, such as session cookies).

#### **Example: Cross-Origin Request with Cookies (Using `include`)**

```javascript
fetch('https://api.example.com/data', {
  method: 'GET',
  credentials: 'include',  // Send cookies even for cross-origin requests
})
  .then(response => response.json())
  .then(data => console.log(data))
  .catch(error => console.error('Error:', error));
```

- **Cross-origin** requests will include cookies and authentication data (such as bearer tokens or session cookies) if the server allows it and the request includes `credentials: 'include'`.

- Note that for cross-origin requests, the server must include specific CORS (Cross-Origin Resource Sharing) headers to allow credentials. For example, the server must set the `Access-Control-Allow-Credentials` header to `true` and must also explicitly list allowed origins using `Access-Control-Allow-Origin` (wildcard `*` is not allowed when using `credentials: 'include'`).

---

### **3. `omit`**

When `credentials: 'omit'` is used, cookies and authentication data are never sent with the request, regardless of whether the request is cross-origin or same-origin. This is useful for making requests where you do not want to include any cookies or credentials for privacy or security reasons.

#### **Example: Request Without Cookies (Using `omit`)**

```javascript
fetch('https://api.example.com/data', {
  method: 'GET',
  credentials: 'omit',  // Do not send any cookies or credentials with the request
})
  .then(response => response.json())
  .then(data => console.log(data))
  .catch(error => console.error('Error:', error));
```

- **No credentials** will be sent with the request, whether it's cross-origin or same-origin.

---

### **How `credentials` Works with CORS**

For **cross-origin** requests, if you're using `credentials: 'include'`, the server must explicitly allow credentials by setting the `Access-Control-Allow-Credentials` header to `true` and must also specify an allowed origin. The `Access-Control-Allow-Origin` header cannot be set to a wildcard (`*`) in this case.

#### **Example: Server-Side CORS Headers (for `credentials: 'include'`)**

```http
Access-Control-Allow-Origin: https://example.com  // Specific origin (not '*')
Access-Control-Allow-Credentials: true  // Allow credentials
```

Without these headers, the browser will block the request and not send any cookies or authentication data.

---

### **Use Cases for `credentials`**

1. **Same-Origin Requests**:
   - You don't need to specify `credentials: 'same-origin'` as it is the default.
   - Cookies and authentication data are automatically included in requests to the same domain.

2. **Cross-Origin Requests with Cookies**:
   - Use `credentials: 'include'` when making requests to a different domain and you need to include cookies or authentication tokens (e.g., for APIs that rely on session cookies).

3. **Requests Without Credentials**:
   - Use `credentials: 'omit'` when you want to ensure no cookies or credentials are sent with the request (for example, when sending public API requests where authentication is not needed).

---

### **Conclusion**

- **`same-origin`** (default): Cookies and authentication data are sent only for same-origin requests.
- **`include`**: Cookies and credentials are sent for both same-origin and cross-origin requests (with CORS support on the server).
- **`omit`**: No cookies or credentials are sent with the request.

Choosing the appropriate `credentials` option ensures that you handle authentication and session management properly in your requests, especially when dealing with cross-origin scenarios.
