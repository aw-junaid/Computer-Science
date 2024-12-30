### **Base and Derived Classes in C++**

In object-oriented programming (OOP), **base** and **derived classes** are central concepts related to **inheritance**. Inheritance allows one class (the derived class) to inherit the properties and behaviors (methods) of another class (the base class), promoting code reusability and establishing a hierarchical relationship between classes.

---

### **1. Base Class**
A **base class** is a class that provides common properties and methods to one or more derived classes. The base class usually defines general behavior, which can be extended or modified by the derived class.

### **2. Derived Class**
A **derived class** is a class that inherits from a base class. It can access and modify the base class's properties and methods. Additionally, the derived class can have its own unique properties and methods or override inherited methods.

### **3. Syntax of Base and Derived Classes**

Here is the general syntax for defining base and derived classes in C++:

```cpp
// Base class
class BaseClass {
public:
    // Public member of the base class
    int baseMember;

    // Constructor of the base class
    BaseClass(int value) : baseMember(value) {}

    // A member function of the base class
    void baseFunction() {
        cout << "This is a base class function" << endl;
    }
};

// Derived class
class DerivedClass : public BaseClass {
public:
    // Constructor of the derived class
    DerivedClass(int value) : BaseClass(value) {}

    // A member function of the derived class
    void derivedFunction() {
        cout << "This is a derived class function" << endl;
    }
};
```

---

### **4. Example of Base and Derived Classes**

Let’s consider a simple example to demonstrate base and derived classes:

```cpp
#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    // Base class member function
    void speak() {
        cout << "Animal speaks" << endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    // Derived class member function
    void bark() {
        cout << "Dog barks" << endl;
    }
};

int main() {
    // Creating an object of the derived class
    Dog myDog;

    // Accessing the base class function through the derived class object
    myDog.speak();  // Inherited from Animal class
    myDog.bark();   // Specific to Dog class

    return 0;
}
```

**Output:**
```
Animal speaks
Dog barks
```

**Explanation**: 
- `Dog` is a **derived class** that inherits from the **base class** `Animal`.
- The `Dog` class can access the `speak()` method of the `Animal` class, demonstrating inheritance.
- The `bark()` method is specific to the `Dog` class.

---

### **5. Accessing Members of Base and Derived Classes**

A derived class can access the **public** and **protected** members of the base class, but not its **private** members. However, it can use public and protected methods to interact with the private members.

- **Public Members**: Accessible by both the base and derived class objects.
- **Protected Members**: Accessible by the derived class, but not by the outside world.
- **Private Members**: Not directly accessible by the derived class; can only be accessed via public or protected methods of the base class.

```cpp
#include <iostream>
using namespace std;

class Base {
private:
    int privateMember;  // Private member, not accessible by derived class

protected:
    int protectedMember;  // Protected member, accessible by derived class

public:
    int publicMember;  // Public member, accessible by both base and derived classes

    Base() : privateMember(0), protectedMember(0), publicMember(0) {}

    void setValues(int privateVal, int protectedVal, int publicVal) {
        privateMember = privateVal;
        protectedMember = protectedVal;
        publicMember = publicVal;
    }

    void showValues() {
        cout << "Private: " << privateMember << ", Protected: " << protectedMember << ", Public: " << publicMember << endl;
    }
};

class Derived : public Base {
public:
    void accessBaseMembers() {
        // privateMember = 10;  // Error: private member of base class is not accessible
        protectedMember = 20;  // Can access protected member
        publicMember = 30;     // Can access public member
    }
};

int main() {
    Derived derivedObject;

    derivedObject.setValues(1, 2, 3);
    derivedObject.accessBaseMembers();
    derivedObject.showValues();  // Outputs: Private: 0, Protected: 20, Public: 30

    return 0;
}
```

**Explanation**:
- The derived class `Derived` can access `protectedMember` and `publicMember` but not `privateMember` directly.
- The `setValues()` method is used to set all the values (including the private one) because it is accessible from the base class.

---

### **6. Constructor and Destructor in Base and Derived Classes**

When a derived class object is created, the constructor of the base class is called first (before the derived class constructor). Similarly, when a derived class object is destroyed, the destructor of the derived class is called first, followed by the base class destructor.

- **Constructor Call Order**: Base class constructor → Derived class constructor
- **Destructor Call Order**: Derived class destructor → Base class destructor

```cpp
#include <iostream>
using namespace std;

// Base class
class Base {
public:
    Base() {
        cout << "Base class constructor called" << endl;
    }

    ~Base() {
        cout << "Base class destructor called" << endl;
    }
};

// Derived class
class Derived : public Base {
public:
    Derived() {
        cout << "Derived class constructor called" << endl;
    }

    ~Derived() {
        cout << "Derived class destructor called" << endl;
    }
};

int main() {
    Derived d;
    return 0;
}
```

**Output:**
```
Base class constructor called
Derived class constructor called
Derived class destructor called
Base class destructor called
```

**Explanation**: 
- The constructor of the **base class** is called before the constructor of the **derived class**.
- The destructor of the **derived class** is called before the destructor of the **base class**.

---

### **7. Method Overriding in Base and Derived Classes**

In C++, a **derived class** can **override** the methods of the **base class** by providing a new implementation of a function that is already defined in the base class. To do this, the base class function should be marked as `virtual`, and the derived class should use the same function signature.

```cpp
#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    virtual void draw() {  // Virtual function
        cout << "Drawing a shape" << endl;
    }
};

// Derived class
class Circle : public Shape {
public:
    void draw() override {  // Overriding the base class method
        cout << "Drawing a circle" << endl;
    }
};

int main() {
    Shape* shape;  // Pointer to base class
    Circle circle;
    shape = &circle;

    shape->draw();  // Calls the derived class method

    return 0;
}
```

**Output:**
```
Drawing a circle
```

**Explanation**:
- The `draw()` method in the `Shape` class is marked as `virtual`, which allows the derived class `Circle` to override it.
- Even though the base class pointer `shape` is used, it calls the overridden `draw()` method in the `Circle` class due to **dynamic polymorphism**.

---

### **Summary**

- **Base Class**: Defines general properties and behaviors, which are inherited by derived classes.
- **Derived Class**: Inherits properties and behaviors from the base class, and can add its own specific properties and methods.
- **Access Modifiers**: Derived classes can access public and protected members of the base class, but not private members.
- **Constructor/Destructor**: The base class constructor is called before the derived class constructor, and the derived class destructor is called before the base class destructor.
- **Method Overriding**: Derived classes can override base class methods by providing their own implementation, often using `virtual` functions in the base class.

By leveraging inheritance, you can create more efficient and modular code that can be easily extended and modified.
