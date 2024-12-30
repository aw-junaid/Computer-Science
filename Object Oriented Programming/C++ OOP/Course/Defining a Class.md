### **Defining a Class in C++**

A **class** in C++ is a blueprint for creating objects. It defines the properties (data members) and behaviors (member functions or methods) that an object created from the class will have.

---

### **1. Syntax of a Class**

A class is defined using the `class` keyword followed by the class name and a set of curly braces `{}` containing data members and member functions.

```cpp
class ClassName {
    // Data members (variables)
    type member1;
    type member2;

    // Member functions (methods)
    return_type function_name(parameters) {
        // Code to execute
    }
};
```

- **`class`**: Keyword to define a class.
- **`ClassName`**: The name of the class (by convention, class names begin with a capital letter).
- **Data members**: Variables that hold the properties or state of the class.
- **Member functions**: Functions that define the behaviors or actions of the class.

---

### **2. Example of a Class**

Here’s an example of a simple class `Car` that has data members (properties) like `make`, `model`, and `year`, and a member function `displayDetails` that prints these details.

```cpp
#include <iostream>
using namespace std;

class Car {
    // Data members
    string make;
    string model;
    int year;

public:
    // Constructor to initialize the data members
    Car(string m, string mod, int y) {
        make = m;
        model = mod;
        year = y;
    }

    // Member function to display car details
    void displayDetails() {
        cout << "Car Details: " << endl;
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

int main() {
    // Creating an object of class Car
    Car myCar("Toyota", "Corolla", 2020);

    // Calling the member function
    myCar.displayDetails();

    return 0;
}
```

**Output**:
```
Car Details: 
Make: Toyota
Model: Corolla
Year: 2020
```

---

### **3. Components of a Class**

#### **A. Data Members**
These are variables that hold the state of an object. They are defined inside the class but outside any member functions.

```cpp
class Person {
public:
    string name;
    int age;
};
```

#### **B. Member Functions**
These are functions that define the behaviors or actions that an object can perform. Member functions are typically defined inside the class or outside using the scope resolution operator `::`.

```cpp
class Person {
public:
    string name;
    int age;

    // Member function to print details
    void printDetails() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};
```

---

### **4. Access Modifiers**

C++ supports three types of access modifiers that control the visibility and accessibility of class members:

1. **`public`**: Members declared as `public` can be accessed from outside the class.
2. **`private`**: Members declared as `private` can only be accessed from within the class or by its friend functions.
3. **`protected`**: Members declared as `protected` can be accessed in the class and by derived (child) classes.

**Example with Access Modifiers**:
```cpp
class Person {
private:
    string name;   // Cannot be accessed from outside the class
    int age;

public:
    // Public setter functions to access private data members
    void setName(string n) {
        name = n;
    }

    void setAge(int a) {
        age = a;
    }

    // Public getter functions to access private data members
    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Person p;
    p.setName("John");
    p.setAge(30);
    p.display();  // Accessing public function

    return 0;
}
```

**Output**:
```
Name: John, Age: 30
```

---

### **5. Constructor**

A **constructor** is a special member function that is automatically called when an object of the class is created. It is used to initialize the object’s data members.

- **Default Constructor**: A constructor that takes no arguments.
- **Parameterized Constructor**: A constructor that takes arguments to initialize data members with specific values.

**Example of a Parameterized Constructor**:
```cpp
class Rectangle {
    int width, height;

public:
    // Parameterized constructor
    Rectangle(int w, int h) {
        width = w;
        height = h;
    }

    void displayArea() {
        cout << "Area: " << width * height << endl;
    }
};

int main() {
    Rectangle rect(10, 5);  // Creating object with parameters
    rect.displayArea();     // Calling member function

    return 0;
}
```

**Output**:
```
Area: 50
```

---

### **6. Destructor**

A **destructor** is a special member function that is automatically called when an object goes out of scope or is deleted. It is used to clean up resources (e.g., memory) allocated by the object.

```cpp
class MyClass {
public:
    // Destructor
    ~MyClass() {
        cout << "Destructor called" << endl;
    }
};

int main() {
    MyClass obj;  // Destructor will be called when the object goes out of scope
    return 0;
}
```

**Output**:
```
Destructor called
```

---

### **7. Example: A Class with Data Members, Member Functions, and Constructor**

```cpp
#include <iostream>
using namespace std;

class Circle {
    double radius;

public:
    // Constructor to initialize radius
    Circle(double r) {
        radius = r;
    }

    // Member function to calculate area
    double calculateArea() {
        return 3.14159 * radius * radius;
    }

    // Member function to display area
    void display() {
        cout << "Area of Circle: " << calculateArea() << endl;
    }
};

int main() {
    Circle c1(5.0);  // Creating an object with a radius of 5.0
    c1.display();    // Calling the display function

    return 0;
}
```

**Output**:
```
Area of Circle: 78.5398
```

---

### **8. Summary**

- **Class Definition**: A class is defined with the `class` keyword and contains data members and member functions.
- **Constructor**: Initializes objects of the class when they are created.
- **Destructor**: Cleans up when an object is destroyed.
- **Access Modifiers**: Control visibility (`public`, `private`, `protected`).
- **Member Functions**: Functions that define the behavior of the class.
  
