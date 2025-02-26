# **Writing Clean and Maintainable Code**  

Clean and maintainable code is **easy to read, understand, and modify**. It reduces technical debt, improves collaboration, and makes debugging easier. Here’s how you can write high-quality code.  

---

## **1. Follow Proper Naming Conventions**  
### ✅ **Use Meaningful and Descriptive Names**
Bad ❌  
```java
int d;  // What does 'd' represent?
String str; // Vague name
```
Good ✅  
```java
int daysUntilExpiration;
String customerName;
```

### ✅ **Use Consistent Naming Conventions**  
- **Variables & methods**: `camelCase` → `getUserInfo()`  
- **Classes & interfaces**: `PascalCase` → `UserService`  
- **Constants**: `UPPER_CASE_SNAKE_CASE` → `MAX_RETRIES`  

---

## **2. Keep Functions and Methods Small**  
**Follow the "Single Responsibility Principle" (SRP):** A method should do **one thing only**.  

Bad ❌ (Multiple responsibilities)  
```java
public void processOrder(Order order) {
    validateOrder(order);
    calculateTotal(order);
    sendEmail(order);
}
```
Good ✅ (Separation of concerns)  
```java
public void validateOrder(Order order) { /* Validation logic */ }
public void calculateTotal(Order order) { /* Calculation logic */ }
public void sendEmail(Order order) { /* Email logic */ }
```

---

## **3. Avoid Magic Numbers and Strings**  
Magic numbers make code **hard to understand and maintain**.  

Bad ❌  
```java
if (status == 3) { /* Process order */ }
```
Good ✅  
```java
final int ORDER_PROCESSED = 3;
if (status == ORDER_PROCESSED) { /* Process order */ }
```

---

## **4. Use Comments Wisely**  
### ✅ **Explain Why, Not What**  
Bad ❌  
```java
// Loop through the list
for (int i = 0; i < list.size(); i++) {
    // Print each element
    System.out.println(list.get(i));
}
```
Good ✅  
```java
// Process each customer and send a notification
for (Customer customer : customers) {
    sendNotification(customer);
}
```

### ❌ **Avoid Redundant Comments**  
```java
// Increment the counter
counter++;
```
The code **already** explains itself!

---

## **5. Write Self-Documenting Code**  
Bad ❌  
```java
if (d < 18) {
    System.out.println("Not allowed");
}
```
Good ✅  
```java
final int MIN_AGE = 18;
if (age < MIN_AGE) {
    System.out.println("User is underage and cannot proceed.");
}
```

---

## **6. Use Proper Exception Handling**  
Bad ❌  
```java
try {
    int result = 10 / 0;
} catch (Exception e) {
    e.printStackTrace();
}
```
Good ✅  
```java
try {
    int result = 10 / 0;
} catch (ArithmeticException e) {
    System.err.println("Error: Division by zero is not allowed.");
}
```

---

## **7. Follow DRY Principle (Don't Repeat Yourself)**  
Avoid **duplicating** code—refactor it into reusable methods.

Bad ❌  
```java
public int add(int a, int b) {
    return a + b;
}
public int addThree(int a, int b, int c) {
    return a + b + c;
}
```
Good ✅  
```java
public int add(int... numbers) {
    return Arrays.stream(numbers).sum();
}
```

---

## **8. Use Design Patterns**  
**Common design patterns** improve **code structure and maintainability**:  
- **Singleton** → Ensures a class has only one instance.  
- **Factory** → Creates objects without specifying the exact class.  
- **Observer** → Implements event-driven programming.  

Example: **Singleton Pattern**
```java
public class Database {
    private static Database instance;

    private Database() {}

    public static Database getInstance() {
        if (instance == null) {
            instance = new Database();
        }
        return instance;
    }
}
```

---

## **9. Keep Code Modular and Decoupled**  
Use **interfaces** and **dependency injection** to make code **flexible and testable**.  

Bad ❌ (Tightly coupled)  
```java
public class NotificationService {
    private EmailService emailService = new EmailService();
}
```
Good ✅ (Loosely coupled)  
```java
public class NotificationService {
    private final NotificationSender sender;
    
    public NotificationService(NotificationSender sender) {
        this.sender = sender;
    }
}
```
Now, we can **easily switch** between `EmailService` and `SMSService`.

---

## **10. Write Unit Tests**  
Testing ensures **code reliability** and prevents future bugs.  

**JUnit Example:**
```java
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

public class CalculatorTest {
    @Test
    public void testAddition() {
        Calculator calc = new Calculator();
        assertEquals(10, calc.add(5, 5));
    }
}
```

---

## **11. Follow Code Formatting and Style Guides**  
- Use **consistent indentation** (`4 spaces` is standard in Java).  
- Keep **line length below 80–120 characters**.  
- Follow **Java style guides** like Google's Java Style Guide.  

---

## **12. Keep Dependencies Updated**  
Regularly update dependencies to **avoid security vulnerabilities** and **performance issues**.  

Check outdated dependencies in Maven:  
```sh
mvn versions:display-dependency-updates
```

---

## **Conclusion**  
✔ **Readable Code** → Meaningful names, small functions.  
✔ **Maintainable Code** → DRY principle, modular structure.  
✔ **Efficient Code** → Avoid redundant logic, use design patterns.  
✔ **Reliable Code** → Exception handling, unit tests.  
