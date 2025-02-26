# **Introduction to Microservices and RESTful APIs**  

Microservices and RESTful APIs are foundational concepts in modern **cloud-native development**, enabling **scalable, modular, and maintainable applications**.

---

## **1. What Are Microservices?**  
### **🔹 Definition**  
Microservices are an **architectural style** where an application is divided into **small, loosely coupled services**, each handling a specific business function.

### **🔹 Key Characteristics**  
✅ **Independent Deployment** – Each service can be deployed separately.  
✅ **Decentralized Data Management** – Each service has its own database.  
✅ **Technology Agnostic** – Services can be built using different languages.  
✅ **Resilience & Fault Isolation** – Failure in one service doesn’t crash the whole system.  
✅ **Scalability** – Services can scale independently based on demand.  

### **🔹 Monolithic vs. Microservices Architecture**  
| Feature | Monolithic Architecture | Microservices Architecture |
|---------|------------------------|---------------------------|
| **Scalability** | Scales as a whole | Scales per service |
| **Deployment** | One large deployment | Deploy services independently |
| **Technology** | Single stack | Can use different tech per service |
| **Maintenance** | Harder to maintain | Easier to update and extend |
| **Fault Tolerance** | One failure affects all | Failure is isolated |

### **🔹 Example of Microservices in E-commerce**  
An **e-commerce platform** could have:  
- **User Service** – Handles authentication and profiles.  
- **Product Service** – Manages product catalog.  
- **Order Service** – Handles order processing.  
- **Payment Service** – Manages payments and transactions.  
- **Notification Service** – Sends emails and alerts.  

Each service runs independently but communicates via **REST APIs or Message Brokers** (Kafka, RabbitMQ).

---

## **2. What Are RESTful APIs?**  
### **🔹 Definition**  
**REST (Representational State Transfer)** is an **architectural style** for designing networked applications. **RESTful APIs** enable communication between **microservices**.

### **🔹 Characteristics of RESTful APIs**  
✅ **Stateless** – Each request is independent; no session data is stored on the server.  
✅ **Client-Server Model** – Client and server are separate entities.  
✅ **Cacheable** – Responses can be cached to improve performance.  
✅ **Uniform Interface** – Follows standard HTTP methods and status codes.  
✅ **Layered System** – API can be behind gateways, load balancers, etc.  

---

## **3. HTTP Methods in REST APIs**  
| Method | Description | Example |
|--------|-------------|---------|
| **GET** | Retrieve a resource | `GET /users/1` |
| **POST** | Create a new resource | `POST /users` |
| **PUT** | Update an existing resource | `PUT /users/1` |
| **PATCH** | Partially update a resource | `PATCH /users/1` |
| **DELETE** | Remove a resource | `DELETE /users/1` |

---

## **4. Building a REST API in Spring Boot (Microservices)**  
### **✅ Step 1: Add Dependencies (Maven)**
```xml
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-web</artifactId>
</dependency>
```

---

### **✅ Step 2: Create a REST Controller**
```java
import org.springframework.web.bind.annotation.*;

import java.util.*;

@RestController
@RequestMapping("/users")
public class UserController {
    private final Map<Integer, String> users = new HashMap<>();

    @GetMapping("/{id}")
    public String getUser(@PathVariable int id) {
        return users.getOrDefault(id, "User not found");
    }

    @PostMapping
    public String createUser(@RequestParam String name) {
        int id = users.size() + 1;
        users.put(id, name);
        return "User created with ID: " + id;
    }
}
```

---

### **✅ Step 3: Test API Endpoints**  
**GET Request:**  
```sh
curl http://localhost:8080/users/1
```
**POST Request:**  
```sh
curl -X POST "http://localhost:8080/users?name=John"
```

---

## **5. API Gateway in Microservices**  
In a **microservices architecture**, an **API Gateway** acts as a single entry point to route requests to different services.

### **Popular API Gateway Solutions**  
✅ **Spring Cloud Gateway** – Java-based, integrates with Spring Boot.  
✅ **Kong API Gateway** – Lightweight, open-source API gateway.  
✅ **NGINX API Gateway** – High-performance, used for load balancing.  

### **Example: Spring Cloud Gateway**
```java
spring:
  cloud:
    gateway:
      routes:
        - id: user-service
          uri: http://localhost:8081
          predicates:
            - Path=/users/**
```
This routes all **`/users/**` requests to `http://localhost:8081`.

---

## **6. Communication Between Microservices**  
Microservices communicate via:  
🔹 **REST APIs** – Synchronous communication.  
🔹 **Message Brokers (Kafka, RabbitMQ)** – Asynchronous, event-driven communication.  
🔹 **gRPC** – High-performance, low-latency communication.  

---

## **7. When to Use Microservices?**  
✅ **Use Microservices if:**  
- The application needs to **scale dynamically**.  
- The system requires **independent deployments**.  
- Different teams work on **different features**.  
- You need **fault tolerance** and **high availability**.  

🚫 **Avoid Microservices if:**  
- The application is **small and simple**.  
- Your team lacks **DevOps expertise**.  
- Deployment complexity is a concern.  

---

## **8. Conclusion**  
✔ **Microservices** enable **scalability, modularity, and flexibility**.  
✔ **RESTful APIs** allow communication between microservices.  
✔ **Spring Boot & Spring Cloud** provide excellent tools for microservices development.  
✔ **API Gateways & Message Brokers** enhance **performance and reliability**.  
