### **Runtime Polymorphism and Function Overriding in C++**

**Runtime polymorphism** in C++ refers to the ability of a program to decide which method (or function) to invoke at runtime based on the object type (rather than the pointer or reference type). This is achieved through **function overriding** and the use of **virtual functions**.

When a function in a base class is overridden by a function in a derived class, and the function is called through a base class pointer or reference, the **derived class's function** is invoked instead of the base class's function. This is possible due to **dynamic binding** (or late binding), which C++ achieves using virtual functions.

### **Key Concepts:**
1. **Virtual Functions**: Functions that are declared in a base class and are meant to be overridden in derived classes. When invoked on a pointer/reference of the base class type, the version of the function defined in the derived class is called, if overridden.
2. **Function Overriding**: Involves a derived class providing its specific implementation of a function that is already defined in the base class. It is only effective when the base class function is virtual.
3. **Dynamic Binding**: The mechanism by which the C++ runtime determines the correct function to invoke based on the actual object type (rather than the reference or pointer type) at runtime.

---

### **Syntax for Function Overriding and Runtime Polymorphism**

Here’s the basic syntax for overriding a virtual function:

```cpp
class Base {
public:
    virtual void functionName() {
        // Base class implementation
    }
};

class Derived : public Base {
public:
    void functionName() override { // override keyword is optional but recommended
        // Derived class implementation
    }
};
```

---

### **Example: Runtime Polymorphism and Function Overriding**

Let’s look at a simple example of function overriding with runtime polymorphism.

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    // Virtual function
    virtual void sound() {
        cout << "Some generic animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    // Overriding the virtual function in derived class
    void sound() override {
        cout << "Bark" << endl;
    }
};

class Cat : public Animal {
public:
    // Overriding the virtual function in derived class
    void sound() override {
        cout << "Meow" << endl;
    }
};

int main() {
    // Creating base class pointer and derived class objects
    Animal* animalPtr;

    Dog dog;
    Cat cat;

    // Runtime polymorphism, the correct function is called based on the actual object type
    animalPtr = &dog;
    animalPtr->sound();  // Output: Bark

    animalPtr = &cat;
    animalPtr->sound();  // Output: Meow

    return 0;
}
```

**Output:**
```
Bark
Meow
```

### **Explanation:**
- **Base Class** (`Animal`): The `sound()` function is declared as `virtual` in the base class. This ensures that the function call is resolved at runtime.
- **Derived Classes** (`Dog` and `Cat`): Both classes override the `sound()` function to provide their own implementation.
- **Runtime Polymorphism**: Even though `animalPtr` is of type `Animal*`, it calls the `sound()` function from the `Dog` or `Cat` class depending on the actual object (`dog` or `cat`) it points to.
  - When `animalPtr = &dog` is set, `dog.sound()` is called.
  - When `animalPtr = &cat` is set, `cat.sound()` is called.

### **Virtual Function and Object Lifetime**

It’s important to note that for runtime polymorphism to work, the object being pointed to must exist throughout the scope of the pointer/reference. If an object is destroyed before the pointer/reference, the program may encounter undefined behavior (like segmentation faults).

---

### **Pure Virtual Functions and Abstract Classes**

A **pure virtual function** makes a class **abstract** and forces derived classes to implement the function. A class with pure virtual functions cannot be instantiated directly.

#### **Example of Pure Virtual Functions:**

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    // Pure virtual function (abstract function)
    virtual void draw() = 0;

    // A regular function (not pure virtual)
    void display() {
        cout << "Displaying Shape" << endl;
    }
};

class Circle : public Shape {
public:
    // Override pure virtual function
    void draw() override {
        cout << "Drawing a Circle" << endl;
    }
};

class Square : public Shape {
public:
    // Override pure virtual function
    void draw() override {
        cout << "Drawing a Square" << endl;
    }
};

int main() {
    // Shape shape;  // Error: cannot instantiate abstract class

    Shape* shapePtr;

    Circle circle;
    Square square;

    shapePtr = &circle;
    shapePtr->draw();  // Output: Drawing a Circle

    shapePtr = &square;
    shapePtr->draw();  // Output: Drawing a Square

    return 0;
}
```

**Output:**
```
Drawing a Circle
Drawing a Square
```

### **Explanation:**
- **Pure Virtual Function**: The `draw()` function is pure virtual, making `Shape` an abstract class.
- **Abstract Class**: `Shape` cannot be instantiated directly. It is only used as a base class for other classes like `Circle` and `Square`.
- **Polymorphism**: The `draw()` function is called based on the actual type of object (`circle` or `square`) at runtime, even though `shapePtr` is a pointer to the base class `Shape`.

---

### **Function Overriding with Virtual Destructor**

If the base class has a **virtual destructor**, it ensures that when a derived class object is deleted through a base class pointer, the destructor of the derived class is called first, followed by the destructor of the base class.

#### **Example of Virtual Destructor:**

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

    ~Derived() override {
        cout << "Derived class destructor" << endl;
    }
};

int main() {
    Base* ptr = new Derived();
    
    // When deleting via base class pointer, the virtual destructor ensures the derived class destructor is called
    delete ptr;  // Output will call destructors in derived class first, then base class

    return 0;
}
```

**Output:**
```
Base class constructor
Derived class constructor
Derived class destructor
Base class destructor
```

### **Explanation:**
- The destructor is virtual, so when `delete ptr` is executed, the `Derived` class's destructor is called first, followed by the `Base` class destructor.
- If the destructor were not virtual, only the `Base` class destructor would be called, potentially leading to resource leaks or incomplete cleanup of the derived class.

---

### **Important Considerations**

1. **Virtual Function Overriding**:
   - When overriding a virtual function, use the `override` keyword (optional, but recommended) to indicate that the function is intended to override a base class method.
   
2. **Virtual Destructor**:
   - Always declare destructors as virtual in base classes when dealing with inheritance. This ensures that destructors in derived classes are called properly during object deletion.

3. **Performance Overhead**:
   - Virtual functions introduce a small runtime overhead due to dynamic dispatch. This is generally minimal but should be considered in performance-critical applications.

4. **Abstract Classes**:
   - A class with pure virtual functions is an **abstract class** and cannot be instantiated. Derived classes are required to implement all pure virtual functions to be instantiable.

---

### **Conclusion**

**Runtime polymorphism** and **function overriding** are fundamental concepts in object-oriented programming that enable dynamic behavior in C++ programs. Virtual functions facilitate this by allowing derived classes to provide specific implementations of functions defined in base classes. This mechanism is key to achieving flexibility and reusability in object-oriented designs, particularly in the context of inheritance hierarchies and abstract classes.
