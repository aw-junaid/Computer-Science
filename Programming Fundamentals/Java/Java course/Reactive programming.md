# **Reactive Programming in Java**
Reactive programming is a programming paradigm focused on **asynchronous**, **event-driven**, and **non-blocking** data streams. It is designed to handle **high-concurrency** scenarios efficiently, making it ideal for **modern, scalable applications**.

---

## **1. Why Use Reactive Programming?**
Traditional blocking (imperative) programming struggles with:
❌ **Blocking threads** – Wasting resources while waiting for I/O.  
❌ **High latency** – Slower response times in heavy-load systems.  
❌ **Poor scalability** – Inefficient CPU utilization in multi-threaded apps.  

Reactive programming solves these by:
✅ **Asynchronous processing** – Non-blocking execution.  
✅ **Event-driven model** – Handles events like UI updates, API calls, and database queries.  
✅ **Better resource utilization** – Scales efficiently in cloud and microservices.  

---

## **2. Key Concepts in Reactive Programming**
| Concept | Description |
|---------|------------|
| **Reactive Streams** | Standard for handling asynchronous data streams. |
| **Publisher** | Emits a sequence of data (e.g., database records, API responses). |
| **Subscriber** | Receives and processes the emitted data. |
| **Flowable & Observable** | Streams in **RxJava** and **Project Reactor**. |
| **Mono & Flux** | Reactive types in **Project Reactor** (Spring WebFlux). |
| **Backpressure** | Controls data flow between **Publisher** and **Subscriber** to prevent overload. |

---

## **3. Popular Reactive Libraries**
### **1️⃣ RxJava (Reactive Extensions for Java)**
- The most widely used **Reactive Programming** library in Java.
- Provides **Observable**, **Flowable**, **Single**, **Maybe**, and **Completable**.
- Supports **backpressure**, **schedulers**, and **functional composition**.

### **2️⃣ Project Reactor (Spring WebFlux)**
- **Spring's official reactive library** (built on Reactive Streams).
- Provides **Mono** (0-1 item) and **Flux** (0-N items).
- Used in **Spring WebFlux** for reactive web applications.

---

# **4. RxJava: Getting Started**
### **✅ Adding RxJava Dependency (Maven)**
```xml
<dependency>
    <groupId>io.reactivex.rxjava3</groupId>
    <artifactId>rxjava</artifactId>
    <version>3.1.5</version>
</dependency>
```

---

### **✅ Example: Creating an Observable**
```java
import io.reactivex.rxjava3.core.Observable;

public class RxJavaExample {
    public static void main(String[] args) {
        Observable<String> observable = Observable.just("Hello", "RxJava", "World");

        observable.subscribe(
            item -> System.out.println("Received: " + item),  // onNext
            error -> System.err.println("Error: " + error),   // onError
            () -> System.out.println("Completed!")           // onComplete
        );
    }
}
```
**Output:**
```
Received: Hello
Received: RxJava
Received: World
Completed!
```
---

### **✅ Example: Using `Flowable` for Backpressure Handling**
```java
import io.reactivex.rxjava3.core.Flowable;

public class FlowableExample {
    public static void main(String[] args) {
        Flowable.range(1, 1000)
            .map(i -> "Item " + i)
            .subscribe(System.out::println);
    }
}
```

---

# **5. Project Reactor (Spring WebFlux)**
Project Reactor is used in **Spring WebFlux**, a **reactive alternative to Spring MVC**.

### **✅ Adding Project Reactor Dependency (Maven)**
```xml
<dependency>
    <groupId>io.projectreactor</groupId>
    <artifactId>reactor-core</artifactId>
    <version>3.5.5</version>
</dependency>
```

---

### **✅ Example: Mono (0-1 Item)**
```java
import reactor.core.publisher.Mono;

public class MonoExample {
    public static void main(String[] args) {
        Mono<String> mono = Mono.just("Hello, Reactive World!");

        mono.subscribe(
            item -> System.out.println("Received: " + item),
            error -> System.err.println("Error: " + error),
            () -> System.out.println("Completed!")
        );
    }
}
```

**Output:**
```
Received: Hello, Reactive World!
Completed!
```
---

### **✅ Example: Flux (0-N Items)**
```java
import reactor.core.publisher.Flux;

public class FluxExample {
    public static void main(String[] args) {
        Flux<String> flux = Flux.just("Java", "Spring", "Reactor");

        flux.subscribe(
            item -> System.out.println("Received: " + item),
            error -> System.err.println("Error: " + error),
            () -> System.out.println("Completed!")
        );
    }
}
```
---

### **✅ Example: Spring WebFlux REST Controller**
```java
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import reactor.core.publisher.Flux;
import reactor.core.publisher.Mono;

@RestController
@RequestMapping("/reactive")
public class ReactiveController {

    @GetMapping("/mono")
    public Mono<String> getMono() {
        return Mono.just("Hello from Mono!");
    }

    @GetMapping("/flux")
    public Flux<String> getFlux() {
        return Flux.just("Item 1", "Item 2", "Item 3");
    }
}
```
### **Run and Test**
**Run the Spring Boot app** and test with:
```
http://localhost:8080/reactive/mono
http://localhost:8080/reactive/flux
```

---

# **6. Backpressure Handling**
Reactive systems process data **asynchronously** but may produce more data than consumers can handle. **Backpressure** helps prevent overwhelming the subscriber.

✅ **Backpressure Strategies in RxJava**
```java
Flowable.range(1, 1000)
    .onBackpressureDrop()
    .subscribe(System.out::println);
```
✅ **Backpressure Handling in WebFlux**
```java
Flux.range(1, 1000)
    .limitRate(100)
    .subscribe(System.out::println);
```

---

# **7. When to Use Reactive Programming?**
✅ **Use Reactive Programming when:**
- You need **non-blocking**, high-throughput applications.
- Handling **I/O-bound** tasks (DB calls, API requests).
- Building **real-time applications** (chat apps, stock updates).
- Creating **microservices** using **Spring WebFlux**.

🚫 **Avoid Reactive Programming if:**
- Your application is simple (e.g., CRUD APIs).
- Your app is **CPU-intensive** (machine learning, cryptography).
- You're unfamiliar with reactive paradigms (it has a learning curve).

---

# **8. Conclusion**
🔹 **RxJava** and **Project Reactor** provide powerful **reactive programming** tools.  
🔹 **Mono & Flux** are key **Reactor types** for reactive streams.  
🔹 **Backpressure** prevents system overload in high-traffic scenarios.  
🔹 **Spring WebFlux** enables **fully reactive web applications**.  
