### **Common Design Patterns: Singleton, Factory, Observer**

Design patterns like **Singleton**, **Factory**, and **Observer** are among the most commonly used in software development, particularly in object-oriented programming (OOP). These patterns help solve common problems in software design and provide reusable solutions that can be applied in different scenarios.

---

### **1. Singleton Pattern**

#### **Definition:**
The **Singleton Pattern** ensures that a class has only one instance and provides a global point of access to that instance. This is particularly useful when exactly one instance of a class is needed to control actions, such as a configuration manager or a connection pool.

#### **Use Case:**
- Database connections.
- Logging systems.
- Configuration settings.

#### **Key Characteristics:**
- **Unique instance**: Only one instance of the class exists during the lifetime of the application.
- **Global access point**: The instance can be accessed globally via a static method.

#### **Example:**

```cpp
#include <iostream>

class Singleton {
private:
    static Singleton* instance;
    Singleton() {}  // Private constructor to prevent instantiation

public:
    // Static method to provide global access to the instance
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void showMessage() {
        std::cout << "Hello from Singleton!" << std::endl;
    }
};

// Initialize static member to null
Singleton* Singleton::instance = nullptr;

int main() {
    // Access Singleton instance
    Singleton* singleton = Singleton::getInstance();
    singleton->showMessage();
    
    return 0;
}
```

#### **Advantages of Singleton Pattern:**
- Guarantees that only one instance of a class exists.
- Provides a global access point to that instance.
- Useful for managing shared resources.

#### **Disadvantages of Singleton Pattern:**
- Can introduce hidden dependencies.
- Can make unit testing difficult.
- May lead to global state management issues.

---

### **2. Factory Pattern**

#### **Definition:**
The **Factory Pattern** defines an interface for creating objects, but it lets subclasses alter the type of objects that will be created. It allows for flexibility in choosing the concrete class to instantiate, which can help in managing object creation without specifying the exact class.

#### **Use Case:**
- GUI frameworks where different operating systems require different button classes.
- Game engines where different types of enemies or weapons are created.

#### **Key Characteristics:**
- **Object creation is deferred**: The decision of which class to instantiate is deferred to subclasses or external configuration.
- **Abstraction**: The pattern allows objects to be created without directly specifying their class.

#### **Example:**

```cpp
#include <iostream>

class Product {
public:
    virtual void use() = 0;
};

class ConcreteProductA : public Product {
public:
    void use() override {
        std::cout << "Using Product A" << std::endl;
    }
};

class ConcreteProductB : public Product {
public:
    void use() override {
        std::cout << "Using Product B" << std::endl;
    }
};

class Creator {
public:
    virtual Product* factoryMethod() = 0;
};

class ConcreteCreatorA : public Creator {
public:
    Product* factoryMethod() override {
        return new ConcreteProductA();
    }
};

class ConcreteCreatorB : public Creator {
public:
    Product* factoryMethod() override {
        return new ConcreteProductB();
    }
};

int main() {
    Creator* creatorA = new ConcreteCreatorA();
    Product* productA = creatorA->factoryMethod();
    productA->use();

    Creator* creatorB = new ConcreteCreatorB();
    Product* productB = creatorB->factoryMethod();
    productB->use();

    return 0;
}
```

#### **Advantages of Factory Pattern:**
- Encapsulates object creation logic.
- Promotes flexibility by allowing different types of products to be created.
- Simplifies client code by delegating object creation to a factory.

#### **Disadvantages of Factory Pattern:**
- Increases complexity, especially when the number of products increases.
- Can lead to proliferation of classes if not managed properly.

---

### **3. Observer Pattern**

#### **Definition:**
The **Observer Pattern** defines a one-to-many dependency between objects. When one object (the **subject**) changes its state, all of its dependents (the **observers**) are notified and updated automatically. This pattern is widely used for implementing distributed event-handling systems.

#### **Use Case:**
- Event-driven systems (e.g., GUI frameworks where the view observes the model).
- Publishing systems where multiple subscribers need to be notified of updates.

#### **Key Characteristics:**
- **One-to-many relationship**: A single subject notifies multiple observers.
- **Loose coupling**: The subject does not need to know the details about the observers, making it flexible and reusable.
- **Dynamic updates**: Observers are automatically updated when the subject’s state changes.

#### **Example:**

```cpp
#include <iostream>
#include <vector>

class Observer {
public:
    virtual void update(int value) = 0;
};

class Subject {
private:
    std::vector<Observer*> observers;
    int value;

public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void setValue(int v) {
        value = v;
        notify();
    }

    void notify() {
        for (auto* observer : observers) {
            observer->update(value);
        }
    }
};

class ConcreteObserver : public Observer {
private:
    std::string name;
public:
    ConcreteObserver(const std::string& name) : name(name) {}

    void update(int value) override {
        std::cout << "Observer " << name << " updated with value: " << value << std::endl;
    }
};

int main() {
    Subject subject;

    ConcreteObserver observer1("A");
    ConcreteObserver observer2("B");

    subject.addObserver(&observer1);
    subject.addObserver(&observer2);

    subject.setValue(10);  // Notifies all observers

    return 0;
}
```

#### **Advantages of Observer Pattern:**
- **Loose coupling**: The subject and observers are loosely coupled, allowing for flexibility.
- **Scalability**: New observers can be added easily without modifying the subject.
- **Real-time notifications**: Observers are notified instantly when the subject changes state.

#### **Disadvantages of Observer Pattern:**
- Can lead to performance issues if the number of observers is large.
- Managing complex observer chains may lead to debugging challenges.
- Difficult to manage circular dependencies between observers.

---

### **Conclusion**

The **Singleton**, **Factory**, and **Observer** patterns are fundamental design patterns that help solve common problems in software development:

- The **Singleton Pattern** ensures a class has only one instance and provides a global point of access.
- The **Factory Pattern** abstracts the object creation process, allowing subclasses to choose the type of object to instantiate.
- The **Observer Pattern** allows for a one-to-many dependency, where changes to the subject are automatically reflected in all dependent observers.

By understanding and applying these patterns, developers can create more flexible, maintainable, and scalable software solutions.
