# **Common Design Patterns in Java**  

Design patterns are **proven solutions** to common software development problems. They improve **code reusability, scalability, and maintainability**.  

---

## **1. Singleton Pattern** (Creational)  
Ensures that a class has **only one instance** and provides a **global access point** to it.

### **✅ Example**
```java
public class Singleton {
    private static Singleton instance;

    private Singleton() {}  // Private constructor

    public static Singleton getInstance() {
        if (instance == null) {
            instance = new Singleton();
        }
        return instance;
    }
}
```
### **✅ Usage**
Used in **database connections, logging, configuration management, caching**.

---

## **2. Factory Pattern** (Creational)  
Encapsulates object creation logic and returns instances based on **runtime conditions**.

### **✅ Example**
```java
interface Vehicle {
    void drive();
}

class Car implements Vehicle {
    public void drive() { System.out.println("Driving a car"); }
}

class Bike implements Vehicle {
    public void drive() { System.out.println("Riding a bike"); }
}

class VehicleFactory {
    public static Vehicle getVehicle(String type) {
        if (type.equalsIgnoreCase("car")) return new Car();
        if (type.equalsIgnoreCase("bike")) return new Bike();
        return null;
    }
}
```
### **✅ Usage**
```java
Vehicle vehicle = VehicleFactory.getVehicle("car");
vehicle.drive();  // Output: Driving a car
```
### **✅ Usage Scenarios**
Used in **dependency injection, object pooling, GUI toolkits**.

---

## **3. Observer Pattern** (Behavioral)  
Defines a **one-to-many** dependency where **multiple objects (observers)** get notified of state changes.

### **✅ Example**
```java
import java.util.*;

interface Observer {
    void update(String message);
}

class Subscriber implements Observer {
    private String name;

    public Subscriber(String name) { this.name = name; }

    public void update(String message) {
        System.out.println(name + " received: " + message);
    }
}

class Publisher {
    private List<Observer> observers = new ArrayList<>();

    public void subscribe(Observer observer) { observers.add(observer); }
    public void unsubscribe(Observer observer) { observers.remove(observer); }
    public void notifyObservers(String message) {
        for (Observer observer : observers) observer.update(message);
    }
}
```
### **✅ Usage**
```java
Publisher publisher = new Publisher();
Subscriber user1 = new Subscriber("Alice");
Subscriber user2 = new Subscriber("Bob");

publisher.subscribe(user1);
publisher.subscribe(user2);

publisher.notifyObservers("New video uploaded!"); 
// Output:
// Alice received: New video uploaded!
// Bob received: New video uploaded!
```
### **✅ Usage Scenarios**
Used in **event-driven programming, GUI listeners, messaging systems**.

---

## **4. Builder Pattern** (Creational)  
Used for constructing complex objects **step by step**.

### **✅ Example**
```java
class Car {
    private String engine;
    private int wheels;
    private boolean sunroof;

    public static class Builder {
        private String engine;
        private int wheels;
        private boolean sunroof;

        public Builder setEngine(String engine) { this.engine = engine; return this; }
        public Builder setWheels(int wheels) { this.wheels = wheels; return this; }
        public Builder setSunroof(boolean sunroof) { this.sunroof = sunroof; return this; }

        public Car build() { return new Car(this); }
    }

    private Car(Builder builder) {
        this.engine = builder.engine;
        this.wheels = builder.wheels;
        this.sunroof = builder.sunroof;
    }

    public String toString() {
        return "Car with " + engine + ", " + wheels + " wheels, Sunroof: " + sunroof;
    }
}
```
### **✅ Usage**
```java
Car car = new Car.Builder()
    .setEngine("V8")
    .setWheels(4)
    .setSunroof(true)
    .build();

System.out.println(car);
// Output: Car with V8, 4 wheels, Sunroof: true
```
### **✅ Usage Scenarios**
Used in **object creation when there are multiple parameters**, such as **configuration objects, complex constructors**.

---

## **5. Adapter Pattern** (Structural)  
Allows incompatible interfaces to **work together** by acting as a **bridge**.

### **✅ Example**
```java
interface OldCharger {
    void chargeOldPhone();
}

class OldPhone implements OldCharger {
    public void chargeOldPhone() { System.out.println("Charging old phone"); }
}

interface NewCharger {
    void chargeNewPhone();
}

// Adapter class
class ChargerAdapter implements NewCharger {
    private OldCharger oldCharger;

    public ChargerAdapter(OldCharger oldCharger) {
        this.oldCharger = oldCharger;
    }

    public void chargeNewPhone() {
        oldCharger.chargeOldPhone();
        System.out.println("Converted to charge new phone");
    }
}
```
### **✅ Usage**
```java
OldCharger oldPhone = new OldPhone();
NewCharger adapter = new ChargerAdapter(oldPhone);
adapter.chargeNewPhone();
// Output:
// Charging old phone
// Converted to charge new phone
```
### **✅ Usage Scenarios**
Used in **legacy code integration, API conversion, third-party library adaptation**.

---

## **6. Proxy Pattern** (Structural)  
Provides a **placeholder object** to control access to another object.

### **✅ Example**
```java
interface Internet {
    void connect(String site);
}

class RealInternet implements Internet {
    public void connect(String site) {
        System.out.println("Connecting to " + site);
    }
}

class ProxyInternet implements Internet {
    private RealInternet realInternet = new RealInternet();
    private static List<String> blockedSites = Arrays.asList("blocked.com", "malware.com");

    public void connect(String site) {
        if (blockedSites.contains(site)) {
            System.out.println("Access denied to " + site);
        } else {
            realInternet.connect(site);
        }
    }
}
```
### **✅ Usage**
```java
Internet internet = new ProxyInternet();
internet.connect("google.com");  // Output: Connecting to google.com
internet.connect("blocked.com"); // Output: Access denied to blocked.com
```
### **✅ Usage Scenarios**
Used in **security layers, lazy loading, caching**.

---

## **7. Strategy Pattern** (Behavioral)  
Allows a **class behavior to be changed dynamically** by switching between different strategies.

### **✅ Example**
```java
interface PaymentStrategy {
    void pay(int amount);
}

class CreditCardPayment implements PaymentStrategy {
    public void pay(int amount) {
        System.out.println("Paid $" + amount + " using Credit Card");
    }
}

class PayPalPayment implements PaymentStrategy {
    public void pay(int amount) {
        System.out.println("Paid $" + amount + " using PayPal");
    }
}

class ShoppingCart {
    private PaymentStrategy paymentStrategy;

    public void setPaymentStrategy(PaymentStrategy paymentStrategy) {
        this.paymentStrategy = paymentStrategy;
    }

    public void checkout(int amount) {
        paymentStrategy.pay(amount);
    }
}
```
### **✅ Usage**
```java
ShoppingCart cart = new ShoppingCart();
cart.setPaymentStrategy(new CreditCardPayment());
cart.checkout(100);  // Output: Paid $100 using Credit Card

cart.setPaymentStrategy(new PayPalPayment());
cart.checkout(200);  // Output: Paid $200 using PayPal
```
### **✅ Usage Scenarios**
Used in **payment processing, sorting algorithms, encryption strategies**.

---

## **Conclusion**  
✔ **Singleton** → One instance across the app.  
✔ **Factory** → Centralized object creation.  
✔ **Observer** → Event-driven notifications.  
✔ **Builder** → Step-by-step object creation.  
✔ **Adapter** → Bridge between incompatible interfaces.  
✔ **Proxy** → Controls access to another object.  
✔ **Strategy** → Change behavior at runtime.  
