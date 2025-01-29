# **Rate Limiting & Security Best Practices in APIs 🚀**  

APIs must be **secured** to prevent **abuse, data breaches, and performance issues**. **Rate limiting** is a key technique to **control API usage** and **prevent DDoS attacks**.  

---

## **1. What is Rate Limiting?**
Rate limiting controls **how many requests** a client can send to an API within a specific time.  

🔹 **Prevents:**  
✅ DDoS (Distributed Denial of Service) attacks  
✅ API abuse & scraping  
✅ Overloading the server  

🔹 **Example:**  
👉 Limit **100 requests per minute** for a user  
👉 Block if exceeded, then reset after 60 seconds  

---

## **2. Implementing Rate Limiting in Express (Node.js)**
### **Using Express-Rate-Limit Middleware**
```sh
npm install express-rate-limit
```

### **Basic Rate Limit (100 requests per 15 minutes)**
```javascript
const rateLimit = require("express-rate-limit");

const limiter = rateLimit({
  windowMs: 15 * 60 * 1000, // 15 minutes
  max: 100, // Limit each IP to 100 requests per window
  message: "Too many requests, please try again later.",
});

app.use(limiter); // Apply to all routes
```

📌 **Key Configurations:**  
- `windowMs`: Time window (milliseconds)  
- `max`: Max requests allowed  
- `message`: Custom response when the limit is exceeded  

---

## **3. IP-Based Rate Limiting**
### **Block by IP Address**
```javascript
const limiter = rateLimit({
  windowMs: 10 * 60 * 1000, // 10 minutes
  max: 50, // Max 50 requests per IP
  standardHeaders: true, // Returns rate limit info in headers
  legacyHeaders: false,
});

app.use("/api", limiter);
```

✅ Ensures **fair usage**  
✅ Mitigates **brute-force attacks**  

---

## **4. Advanced Rate Limiting (User-Based)**
🔹 **Better than IP-based limits** (as users can switch IPs)  
🔹 Use **JWT or API keys** for rate limiting **per user**  

### **User-Specific Limit (Using Redis)**
```javascript
const Redis = require("ioredis");
const redisClient = new Redis();

const userLimiter = async (req, res, next) => {
  const userId = req.user.id; // Assuming JWT authentication
  const key = `rate_limit:${userId}`;
  const requests = await redisClient.incr(key);

  if (requests === 1) {
    await redisClient.expire(key, 60); // 60 seconds window
  }

  if (requests > 10) {
    return res.status(429).json({ message: "Rate limit exceeded" });
  }

  next();
};

app.use("/api/protected", userLimiter);
```
📌 **Why Redis?**  
✅ **Fast & Scalable** – Handles high traffic  
✅ **Persistent tracking** – Works across multiple servers  

---

## **5. Security Best Practices**
### **A. API Authentication**
🔹 **Use Strong Authentication**  
- JWT (JSON Web Tokens)  
- OAuth 2.0  

🔹 **Example: Protecting Routes with JWT**
```javascript
const jwt = require("jsonwebtoken");

const authenticateToken = (req, res, next) => {
  const token = req.headers["authorization"];
  if (!token) return res.status(401).json({ message: "Unauthorized" });

  jwt.verify(token, "SECRET_KEY", (err, user) => {
    if (err) return res.status(403).json({ message: "Invalid token" });
    req.user = user;
    next();
  });
};

app.use("/api/secure", authenticateToken);
```

✅ Prevents **unauthorized access**  
✅ Validates **token before processing requests**  

---

### **B. API Key Security**
🔹 **Generate API Keys** for clients  
🔹 **Restrict by IP & Domain**  
🔹 **Example API Key Middleware**
```javascript
const validKeys = ["abc123", "xyz789"]; // Store securely in DB

const apiKeyMiddleware = (req, res, next) => {
  const key = req.headers["x-api-key"];
  if (!key || !validKeys.includes(key)) {
    return res.status(403).json({ message: "Invalid API key" });
  }
  next();
};

app.use("/api", apiKeyMiddleware);
```
✅ **Only authorized clients** can access the API  

---

### **C. Input Validation & Sanitization**
🔹 **Prevent SQL Injection & XSS**  
🔹 **Use Libraries: express-validator, DOMPurify**  

```javascript
const { body, validationResult } = require("express-validator");

app.post("/register", [
  body("email").isEmail(),
  body("password").isLength({ min: 8 }),
], (req, res) => {
  const errors = validationResult(req);
  if (!errors.isEmpty()) return res.status(400).json({ errors: errors.array() });

  res.json({ message: "User registered!" });
});
```
✅ **Ensures only valid data** is processed  

---

### **D. HTTPS & Secure Headers**
🔹 **Force HTTPS**  
```javascript
app.use((req, res, next) => {
  if (!req.secure) return res.redirect(`https://${req.headers.host}${req.url}`);
  next();
});
```
🔹 **Set Security Headers with Helmet**
```sh
npm install helmet
```
```javascript
const helmet = require("helmet");
app.use(helmet());
```
✅ **Prevents clickjacking, XSS, and data leaks**  

---

## **6. Logging & Monitoring**
🔹 **Use logging tools**: Winston, Morgan  
🔹 **Monitor API traffic**: Prometheus, Grafana  

```sh
npm install morgan
```
```javascript
const morgan = require("morgan");
app.use(morgan("combined"));
```
✅ **Tracks suspicious activities**  
✅ **Logs failed authentication attempts**  

---

## **Conclusion**
✅ **Rate limiting** prevents API abuse  
✅ **Authentication** secures sensitive endpoints  
✅ **Input validation** blocks SQL/XSS attacks  
✅ **HTTPS & Security Headers** prevent exploits  
✅ **Logging & Monitoring** helps detect threats  
