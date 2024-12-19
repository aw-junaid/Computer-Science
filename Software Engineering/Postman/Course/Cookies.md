### **Postman Cookies**

Cookies are small pieces of data that are stored on the client side (usually in the browser or app) and sent with HTTP requests to maintain state between the client and server. In the context of Postman, cookies are essential for managing session states, authentication, and tracking user-specific information across requests.

Postman provides a built-in feature to manage cookies, enabling you to inspect, delete, or modify cookies for your requests. This is particularly useful for testing scenarios that involve authentication, session management, and ensuring that your API behaves correctly when interacting with cookies.

### **How to Use Cookies in Postman**

#### **1. Viewing Cookies in Postman**

When you send an HTTP request in Postman, the response may contain cookies that are set by the server. These cookies are stored by Postman and automatically included in subsequent requests to the same domain.

To view the cookies:
1. Send a request (e.g., a login request or any request that sets cookies).
2. In the **Response** tab, look for the **Cookies** tab, which will list all cookies sent by the server.
3. You can view the **Name**, **Value**, **Domain**, **Path**, **Expires**, and other properties of the cookies here.

#### **Example: Viewing Cookies After Sending a Request**
- Suppose you make a `POST` request to login (e.g., `/login`).
- After the request, the response might include a `Set-Cookie` header that instructs Postman to store a cookie.
  
Postman will capture this cookie and display it in the **Cookies** tab of the **Response** section.

#### **2. Managing Cookies in Postman**

Postman provides options to manage cookies manually, allowing you to set, delete, or modify cookies for a specific request or across sessions.

##### **Accessing the Cookie Manager**
1. Open Postman and click on the **Cookies** link located under the **Send** button.
2. This will open the **Cookies Manager**, where you can see and manage cookies for various domains.

##### **Setting Cookies in Postman**
1. In the **Cookies Manager**, click **Add Cookie**.
2. Enter the required details such as:
   - **Name**: Name of the cookie.
   - **Value**: Value of the cookie.
   - **Domain**: Domain that the cookie is associated with.
   - **Path**: Path on the server where the cookie is valid.
   - **Expires**: Expiration time for the cookie (optional).
   - **Secure**: Whether the cookie should only be sent over HTTPS.
   - **HttpOnly**: Whether the cookie is accessible via JavaScript or just HTTP requests.

##### **Modifying Cookies**
You can edit existing cookies by clicking on a specific cookie in the **Cookies Manager**, changing its values, and saving the changes.

##### **Deleting Cookies**
To delete a cookie, click on the **trash bin** icon next to the cookie you want to remove. You can delete cookies for a specific domain or remove all cookies.

#### **3. Sending Cookies with Requests**

Postman automatically includes cookies in subsequent requests to the same domain (based on the domain and path). You don’t need to manually add cookies to requests unless you want to override or modify the default behavior.

However, you can manually add cookies to requests by following these steps:
1. Go to the **Headers** tab for a request.
2. Add a `Cookie` header with the name and value of the cookie.

For example, if you have a cookie named `sessionid`, you can add it manually:
```plaintext
Cookie: sessionid=123456789
```

This is useful when simulating specific session states or overriding cookies set by the server.

---

### **4. Testing Authentication with Cookies**

Cookies are often used in authentication processes, such as session-based authentication. For example:
- When a user logs in, the server might respond with a `Set-Cookie` header to store a session identifier.
- In subsequent requests, the client (Postman) sends the session cookie to maintain the user's logged-in state.

#### **Example: Testing Authentication with Cookies**

1. **Login Request**:
   - Make a `POST` request to a login endpoint (e.g., `/login`).
   - The server responds with a `Set-Cookie` header, which Postman stores.
  
   Example of a `Set-Cookie` header in the response:
   ```
   Set-Cookie: sessionid=123456789; Path=/; HttpOnly
   ```

2. **Subsequent Requests**:
   - In subsequent requests to the same domain, Postman automatically includes the `sessionid` cookie in the `Cookie` header:
   ```
   Cookie: sessionid=123456789
   ```

3. **Verify Session Persistence**:
   - You can verify that the session is maintained by sending further requests (e.g., `GET /profile` or `GET /dashboard`) and checking if the server responds with the correct data for the logged-in user.

---

### **5. Cookie Persistence and Scope**

By default, Postman stores cookies for each environment or collection separately. This allows you to test APIs with different session states in different environments or collections without interference.

#### **Cookie Persistence Across Requests**
Cookies in Postman are persistent across requests in a given session:
- Cookies set by the server are stored and automatically sent with subsequent requests to the same domain.
- If a cookie has an expiration date, it will be deleted when it expires.

#### **Deleting All Cookies**
If you want to clear all cookies:
1. Click on the **Cookies** link in the request section.
2. In the **Cookies Manager**, click **Clear All** to delete all cookies for the active environment.

---

### **6. Cookie Automation and Scripting**

Postman also supports cookie manipulation using **Pre-request scripts** and **Tests**.

#### **Pre-request Script Example**:
You can set a cookie value dynamically before sending a request. For instance:
```javascript
pm.cookies.set("my_cookie", "cookie_value");
```
This will set a cookie named `my_cookie` with the value `cookie_value` before sending the request.

#### **Tests Example**:
You can validate cookies in the **Tests** section after receiving a response.

**Example: Validate a Cookie in the Response**
```javascript
pm.test("Check if session cookie is set", function () {
    var cookies = pm.cookies.get("sessionid");
    pm.expect(cookies).to.not.be.null;
});
```
This test checks if the `sessionid` cookie is set after a request.

---

### **7. Advanced Cookie Features**

#### **Cookie Jar**:
Postman uses a **cookie jar** to store cookies, which is isolated per domain. The cookie jar automatically manages cookies for requests sent to different domains, ensuring cookies are only sent to the appropriate servers.

#### **Secure Cookies**:
Cookies marked as `Secure` are only sent over HTTPS connections. If you're testing an API that uses `Secure` cookies, make sure your request is made over HTTPS, or else the cookie won't be sent.

#### **HttpOnly Cookies**:
Cookies marked as `HttpOnly` cannot be accessed through JavaScript, and they are only sent in HTTP requests (not accessible via `document.cookie` in the browser). In Postman, `HttpOnly` cookies are automatically handled and stored, but they are not accessible in scripts.

---

### **Conclusion**

Cookies in Postman are an essential feature for testing and simulating session management, authentication, and tracking user-specific data in your API requests. With Postman’s powerful cookie management tools, you can:
- View, add, modify, and delete cookies.
- Automatically send cookies with requests to simulate authentication or session states.
- Use cookies in scripts to automate and validate API behavior.

By leveraging cookies effectively, you can ensure your API behaves correctly under different session conditions, making it easier to test session-based authentication, tracking, and other cookie-dependent features.
