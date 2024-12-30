### **Virtual Functions in C++**

**Virtual functions** in C++ are member functions that are declared in a base class and are meant to be overridden in derived classes. When a function is declared as **virtual**, C++ ensures that the correct function is called for an object, regardless of the type of reference (or pointer) used for the call. This mechanism is known as **polymorphism** and is a key feature of object-oriented programming.

### **Key Points of Virtual Functions**
1. **Dynamic Binding**: Virtual functions enable dynamic (runtime) polymorphism, meaning the function call is resolved at runtime rather than at compile time.
2. **Base Class Declaration**: A virtual function is declared in the base class using the keyword `virtual`.
3. **Function Overriding**: Derived classes override the virtual function to provide their specific implementation.
4. **Base Class Pointer/Reference**: Virtual functions work when you use a base class pointer or reference to call the function, but the actual function that gets called is from the derived class (if overridden).

---

### **Syntax for Virtual Function**

In the base class:

```cpp
class Base {
public:
    virtual void display() { // virtual function
        cout << "Base class display" << endl;
    }
};
```

In the derived class:

```cpp
class Derived : public Base {
public:
    void display() override { // overriding the virtual function
        cout << "Derived class display" << endl;
    }
};
```

---

### **Example of Virtual Functions**

Consider the following example to understand how virtual functions work in C++:

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    // Declare the function as virtual in the base class
    virtual void show() {
        cout << "Base class show function" << endl;
    }

    // A non-virtual function
    void display() {
        cout << "Base class display function" << endl;
    }
};

class Derived : public Base {
public:
    // Override the virtual function in the derived class
    void show() override {
        cout << "Derived class show function" << endl;
    }

    // You can also add additional functions
    void display() {
        cout << "Derived class display function" << endl;
    }
};

int main() {
    Base* basePtr;
    Derived derivedObj;

    basePtr = &derivedObj;

    // Calling virtual function (polymorphism)
    basePtr->show(); // Calls Derived class's show function

    // Calling non-virtual function
    basePtr->display(); // Calls Base class's display function

    return 0;
}
```

**Output**:
```
Derived class show function
Base class display function
```

### **Explanation**:
- **Virtual Function (`show`)**: 
  - The `show` function is declared as `virtual` in the base class, which means that the function call will be resolved at runtime.
  - When `basePtr->show()` is called, the function of the **Derived class** is executed, even though `basePtr` is a pointer to the base class.
  
- **Non-Virtual Function (`display`)**:
  - The `display` function is not marked as `virtual`. Hence, when `basePtr->display()` is called, the **Base class** version of the `display` function is executed.

---

### **Pure Virtual Functions**

A **pure virtual function** is a function that has no implementation in the base class and must be overridden in derived classes. A class that contains at least one pure virtual function becomes an **abstract class** and cannot be instantiated.

To declare a pure virtual function, use the following syntax:

```cpp
virtual return_type function_name() = 0;
```

### **Example of Pure Virtual Function**

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    // Pure virtual function (abstract function)
    virtual void draw() = 0;

    // Regular function
    void display() {
        cout << "Displaying shape" << endl;
    }
};

class Circle : public Shape {
public:
    // Overriding the pure virtual function
    void draw() override {
        cout << "Drawing a Circle" << endl;
    }
};

class Square : public Shape {
public:
    // Overriding the pure virtual function
    void draw() override {
        cout << "Drawing a Square" << endl;
    }
};

int main() {
    // Shape shape; // Error: cannot instantiate abstract class
    Circle circle;
    Square square;

    Shape* shapePtr;

    shapePtr = &circle;
    shapePtr->draw(); // Output: Drawing a Circle

    shapePtr = &square;
    shapePtr->draw(); // Output: Drawing a Square

    return 0;
}
```

**Output**:
```
Drawing a Circle
Drawing a Square
```

### **Explanation**:
- **Pure Virtual Function (`draw`)**: 
  - `draw` is a pure virtual function, meaning the `Shape` class is abstract and cannot be instantiated.
  - The derived classes `Circle` and `Square` must override the `draw` function to provide their own implementation.
  
- **Polymorphism**:
  - Even though `shapePtr` is a pointer of type `Shape*`, it correctly calls the `draw` function from the appropriate derived class (`Circle` or `Square`) because `draw` is a virtual function.

---

### **Virtual Destructor**

In C++, destructors can also be virtual. This ensures that the correct destructor is called for objects created via base class pointers. If a class has virtual functions, it is a good practice to make its destructor virtual as well.

#### **Why Virtual Destructor?**

If a derived class object is deleted using a base class pointer without a virtual destructor, the destructor of the base class is called, and the destructor of the derived class is not executed, which can result in resource leaks.

### **Example of Virtual Destructor**

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base class constructor" << endl;
    }

    // Virtual destructor
    virtual ~Base() {
        cout << "Base class destructor" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived class constructor" << endl;
    }

    // Destructor
    ~Derived() override {
        cout << "Derived class destructor" << endl;
    }
};

int main() {
    Base* ptr = new Derived();

    // When deleting via base class pointer, the virtual destructor ensures the derived class destructor is called
    delete ptr;

    return 0;
}
```

**Output**:
```
Base class constructor
Derived class constructor
Derived class destructor
Base class destructor
```

### **Explanation**:
- **Virtual Destructor**: The destructor in the base class is virtual, ensuring that when the object is deleted using a base class pointer (`delete ptr`), both the derived and base class destructors are called.
- Without a virtual destructor, only the base class destructor would be called, leading to resource leaks or undefined behavior.

---

### **Important Considerations**

1. **Virtual Function Overhead**: 
   - Virtual functions involve a slight performance overhead due to dynamic dispatch (runtime polymorphism). This is typically negligible unless used in performance-critical code.
   
2. **Destructors**: 
   - Always declare destructors as virtual in base classes, especially when dealing with inheritance hierarchies.
   
3. **Virtual Function and Constructor**:
   - Constructors cannot be virtual because they are called before an object is fully created.
   
4. **Override Keyword**:
   - While not strictly necessary, using the `override` keyword helps to avoid errors by ensuring that you are correctly overriding a virtual function from a base class.

---

### **Conclusion**

Virtual functions are a cornerstone of polymorphism in C++. They allow derived classes to provide specific implementations for functions declared in a base class, enabling dynamic binding at runtime. This is essential for writing flexible and reusable code. Additionally, virtual destructors ensure that objects are properly cleaned up, preventing resource leaks.
