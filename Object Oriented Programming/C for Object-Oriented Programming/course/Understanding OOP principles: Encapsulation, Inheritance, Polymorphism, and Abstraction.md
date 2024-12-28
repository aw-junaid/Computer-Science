### **Understanding OOP Principles**

Object-Oriented Programming (OOP) organizes software design around objects and data rather than actions and logic. The four key principles of OOP—**Encapsulation**, **Inheritance**, **Polymorphism**, and **Abstraction**—help developers create modular, reusable, and maintainable code.

---

### **1. Encapsulation**
**Definition:**  
Encapsulation is the process of bundling data (attributes) and methods (functions) that operate on the data into a single unit, typically a class. It restricts direct access to some components, promoting control over the data.

**Key Features:**  
- **Access Modifiers:** Control visibility of data and methods (`public`, `private`, `protected` in C++, etc.).  
- **Getter and Setter Methods:** Allow controlled access to private variables.  

**Real-World Analogy:**  
Think of a car. You don’t need to know how the engine works internally; you just use methods like `start()` or `stop()`.  

**In Code (C++ Example):**
```cpp
class Car {
private:
    int speed; // Private variable

public:
    // Setter for speed
    void setSpeed(int s) {
        if (s >= 0) speed = s;
    }

    // Getter for speed
    int getSpeed() {
        return speed;
    }
};
```

---

### **2. Inheritance**
**Definition:**  
Inheritance is the mechanism by which a class (child/derived class) can acquire properties and behaviors of another class (parent/base class). This promotes code reuse and establishes a hierarchy.

**Key Features:**  
- **Single Inheritance:** One child inherits from one parent.  
- **Multiple Inheritance:** A child inherits from multiple parents (supported in some languages like C++).  
- **Overriding:** A derived class can provide its own implementation of a parent method.  

**Real-World Analogy:**  
A "Bird" class can serve as a base class for specific birds like "Sparrow" or "Penguin," inheriting common features like wings but customizing behaviors like flying.  

**In Code (C++ Example):**
```cpp
class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "This dog barks." << endl;
    }
};

int main() {
    Dog myDog;
    myDog.eat();  // Inherited method
    myDog.bark(); // Specific to Dog
    return 0;
}
```

---

### **3. Polymorphism**
**Definition:**  
Polymorphism allows the same method or operator to behave differently based on the context, enhancing flexibility and scalability.

**Types of Polymorphism:**  
- **Compile-Time (Static) Polymorphism:** Achieved using method overloading or operator overloading.  
- **Run-Time (Dynamic) Polymorphism:** Achieved using method overriding with inheritance and virtual functions.  

**Real-World Analogy:**  
A person can behave as a teacher at school, a customer at a store, or a parent at home. The behavior changes based on context.  

**In Code (C++ Example):**
```cpp
// Compile-Time Polymorphism
class Math {
public:
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
};

// Run-Time Polymorphism
class Shape {
public:
    virtual void draw() { cout << "Drawing a shape." << endl; }
};

class Circle : public Shape {
public:
    void draw() override { cout << "Drawing a circle." << endl; }
};
```

---

### **4. Abstraction**
**Definition:**  
Abstraction hides the implementation details of a class, exposing only the essential features. This reduces complexity and increases efficiency.  

**Key Features:**  
- Implemented using **abstract classes** or **interfaces**.  
- Allows focusing on **what** an object does, rather than **how** it does it.  

**Real-World Analogy:**  
Using an ATM, you interact with a machine that provides an interface (withdrawal, deposit) but hides internal operations.  

**In Code (C++ Example):**
```cpp
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override { cout << "Drawing a circle." << endl; }
};

int main() {
    Shape* shape = new Circle();
    shape->draw(); // Calls Circle's implementation
    delete shape;
}
```

---

### **Summary of Principles**
| Principle       | Key Concept                                | Example Scenario                 |
|-----------------|--------------------------------------------|----------------------------------|
| **Encapsulation** | Hides internal data, provides methods for controlled access. | Car with `start()` and `stop()` methods. |
| **Inheritance**   | Reuse properties and methods of a base class. | Dog inherits `eat()` from Animal. |
| **Polymorphism**  | Same action behaves differently based on the context. | `draw()` behaves differently for Circle or Rectangle. |
| **Abstraction**   | Hides details, focuses on essential features. | ATM providing transaction options. |

