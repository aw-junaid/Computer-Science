## **Authentication and Authorization (JWT, OAuth)**  
Authentication and authorization are essential security mechanisms in modern web applications.  

- **Authentication** → Verifies **who** the user is (e.g., login).  
- **Authorization** → Determines **what** the user can do (e.g., admin vs regular user).  

### **Common Authentication Methods**  
✅ **JWT (JSON Web Token)** – Token-based authentication  
✅ **OAuth 2.0** – Secure authorization for third-party applications  
✅ **Session-Based Authentication** – Traditional method using cookies  

---

# **1. JSON Web Token (JWT) Authentication**  
JWT is a stateless, token-based authentication method where the client receives a token after login and uses it for subsequent requests.  

### **How JWT Works?**  
1️⃣ User logs in with **email/password**.  
2️⃣ Server verifies credentials and generates a **JWT token**.  
3️⃣ Client stores the token (e.g., **localStorage** or **HTTP headers**).  
4️⃣ On each request, the client sends the **JWT token**.  
5️⃣ Server verifies the token and grants access.  

### **JWT Token Structure**  
A JWT consists of three parts:  
```plaintext
HEADER.PAYLOAD.SIGNATURE
```

#### **Example JWT Token**  
```plaintext
eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.
eyJ1c2VySWQiOiIxMjMiLCJyb2xlIjoiYWRtaW4iLCJleHAiOjE2ODQwMDAwMDB9.
Q1pU5n4Qx7XeFy9dfJ3EJL3tPFFxOoZy2U3zFL8vPZs
```

### **JWT Example in Node.js (Express.js)**  
#### **1️⃣ Generate JWT Token on Login**
```javascript
const jwt = require("jsonwebtoken");

const generateToken = (user) => {
  return jwt.sign(
    { userId: user.id, role: user.role },
    "your_secret_key", // Use environment variables for security
    { expiresIn: "1h" }
  );
};
```

#### **2️⃣ Protect Routes with JWT Middleware**  
```javascript
const authenticateJWT = (req, res, next) => {
  const token = req.header("Authorization")?.split(" ")[1];

  if (!token) return res.status(401).json({ message: "Unauthorized" });

  jwt.verify(token, "your_secret_key", (err, user) => {
    if (err) return res.status(403).json({ message: "Forbidden" });
    req.user = user;
    next();
  });
};

// Protect route
app.get("/dashboard", authenticateJWT, (req, res) => {
  res.json({ message: "Welcome to the dashboard!" });
});
```

### **Where to Store JWT Tokens?**  
✅ **Secure Storage** – `httpOnly` cookies (prevents XSS attacks)  
❌ **Avoid Local Storage** – Vulnerable to **XSS attacks**  

---

# **2. OAuth 2.0 (Open Authorization)**  
OAuth 2.0 is an authorization framework that allows third-party apps to access user data without exposing passwords.  

### **OAuth 2.0 Flow (Example: Google Login)**  
1️⃣ User clicks "Login with Google".  
2️⃣ Redirects to Google’s OAuth page.  
3️⃣ User grants permissions.  
4️⃣ Google sends an **Authorization Code**.  
5️⃣ Backend exchanges the **code** for an **Access Token**.  
6️⃣ API requests include the **Access Token**.  

### **OAuth Roles**  
| Role | Description |
|------|------------|
| **Resource Owner** | The user (e.g., you logging in with Google) |
| **Client** | The application requesting access (e.g., a web app) |
| **Authorization Server** | Issues access tokens (e.g., Google, Facebook) |
| **Resource Server** | API that stores user data (e.g., Google APIs) |

### **OAuth 2.0 Grant Types**  
| Grant Type | Use Case |
|-----------|---------|
| **Authorization Code** | Secure, used for web apps (frontend + backend) |
| **Implicit Grant** | Less secure, mainly for single-page apps (deprecated) |
| **Client Credentials** | Used for machine-to-machine authentication |
| **Password Grant** | Used for direct username/password authentication (not recommended) |
| **Refresh Token** | Used to get a new access token without logging in again |

---

# **3. Implementing OAuth 2.0 in a React App (Google Login)**
### **1️⃣ Register App on Google Cloud**  
- Go to **Google Cloud Console** → OAuth 2.0 → Create Credentials  
- Get **Client ID** and **Client Secret**  

### **2️⃣ Install Google OAuth Library**
```sh
npm install react-google-login
```

### **3️⃣ Implement Google Login in React**
```jsx
import { GoogleLogin } from "react-google-login";

const clientId = "YOUR_GOOGLE_CLIENT_ID";

const GoogleAuth = () => {
  const onSuccess = (response) => {
    console.log("Login Success:", response.profileObj);
  };

  const onFailure = (response) => {
    console.log("Login Failed:", response);
  };

  return (
    <GoogleLogin
      clientId={clientId}
      buttonText="Login with Google"
      onSuccess={onSuccess}
      onFailure={onFailure}
      cookiePolicy={"single_host_origin"}
    />
  );
};

export default GoogleAuth;
```

---

# **4. Authentication vs Authorization**  
| Feature | Authentication | Authorization |
|---------|---------------|--------------|
| **Definition** | Verifies identity | Determines access rights |
| **Example** | Logging in with email & password | Admin vs regular user |
| **Tech Used** | JWT, OAuth, API Keys | Role-based access (RBAC), OAuth scopes |
| **Who handles it?** | Authentication server | Application logic |

---

# **5. Role-Based Access Control (RBAC)**
Once authenticated, users should only access allowed resources.

### **Example: Middleware for Role-Based Access**
```javascript
const authorize = (role) => (req, res, next) => {
  if (req.user.role !== role) {
    return res.status(403).json({ message: "Forbidden" });
  }
  next();
};

// Protect Admin Route
app.get("/admin", authenticateJWT, authorize("admin"), (req, res) => {
  res.json({ message: "Welcome Admin!" });
});
```

---

# **6. Security Best Practices**
✅ **Use HTTPS** – Prevents man-in-the-middle attacks  
✅ **Store Tokens Securely** – Use `httpOnly` cookies instead of localStorage  
✅ **Use Refresh Tokens** – Avoid frequent logins  
✅ **Limit API Requests** – Prevent abuse using **rate limiting**  
✅ **Use Strong Password Hashing** – Use **bcrypt** for storing passwords  

---

# **Conclusion**  
- **JWT** is great for **authentication** in web apps.  
- **OAuth 2.0** is best for **third-party authorization**.  
- Use **RBAC** to **restrict access** based on user roles.  
