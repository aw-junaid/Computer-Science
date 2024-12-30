### **Member Functions in C++**

In C++, **member functions** are functions that are defined inside a class and are used to operate on the data members (variables) of the class. These functions can be used to manipulate the object's state or perform specific operations related to the object.

---

### **1. Definition of Member Functions**

A **member function** is defined within a class and operates on the class's data members. It can be defined inside or outside the class declaration.

#### **Syntax:**

```cpp
class ClassName {
public:
    // Member function declaration
    returnType functionName(parameters) {
        // Function body
    }
};
```

- **`returnType`**: The return type of the function (e.g., `int`, `void`, etc.).
- **`functionName`**: The name of the function.
- **`parameters`**: The parameters that the function takes (if any).
- **`function body`**: The actual implementation of the function.

---

### **2. Example of Member Functions**

Let's define a simple class `Rectangle` with member functions to calculate the area and display its details.

```cpp
#include <iostream>
using namespace std;

class Rectangle {
private:
    double width, height;  // Data members

public:
    // Constructor to initialize width and height
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }

    // Member function to calculate area
    double area() {
        return width * height;
    }

    // Member function to display rectangle details
    void display() {
        cout << "Width: " << width << ", Height: " << height << endl;
        cout << "Area: " << area() << endl;  // Calling another member function
    }
};

int main() {
    Rectangle rect(5.0, 3.0);
    rect.display();  // Calling member function to display details

    return 0;
}
```

**Output:**
```
Width: 5, Height: 3
Area: 15
```

In this example:
- `area()` is a member function that calculates the area of the rectangle.
- `display()` is a member function that shows the dimensions and area of the rectangle.

---

### **3. Types of Member Functions**

#### **a. Regular Member Functions**

These are the normal functions defined inside a class, as shown in the example above. They can modify object data or perform operations based on it.

#### **b. Constant Member Functions**

A **constant member function** is one that does not modify any member variables of the object. It is declared using the `const` keyword after the function signature.

```cpp
class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Constant member function
    double getRadius() const {
        return radius;
    }

    void setRadius(double r) {
        radius = r;
    }
};
```

- `getRadius()` is a **constant member function** because it does not modify the state of the object.
- **Important**: You cannot call non-const member functions from within a const member function.

#### **Example of constant member function:**

```cpp
#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) {
        balance = initialBalance;
    }

    // Constant member function
    double getBalance() const {
        return balance;
    }

    // Non-constant member function
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }
};

int main() {
    BankAccount account(1000.0);

    cout << "Initial balance: $" << account.getBalance() << endl;  // Calling const member function
    account.deposit(500.0);  // Calling non-const member function
    cout << "Updated balance: $" << account.getBalance() << endl;

    return 0;
}
```

**Output:**
```
Initial balance: $1000
Updated balance: $1500
```

#### **c. Static Member Functions**

A **static member function** is a function that can be called on the class itself rather than on an instance of the class. Static member functions can only access static data members or other static member functions.

- **Static member functions** are declared using the `static` keyword.
- Static member functions cannot access non-static data members or member functions.

```cpp
class Counter {
private:
    static int count;  // Static data member

public:
    // Static member function
    static void increment() {
        count++;
    }

    static void displayCount() {
        cout << "Count: " << count << endl;
    }
};

// Initializing static member variable outside the class
int Counter::count = 0;

int main() {
    // Calling static member function without creating an object
    Counter::increment();
    Counter::displayCount();

    Counter::increment();
    Counter::displayCount();

    return 0;
}
```

**Output:**
```
Count: 1
Count: 2
```

In this example:
- `count` is a **static data member**.
- `increment()` and `displayCount()` are **static member functions** that modify and display the static variable `count`.

#### **d. Friend Functions**

A **friend function** is a function that is not a member of the class but has access to its private and protected members. It is declared inside the class using the `friend` keyword.

```cpp
class Box {
private:
    double width, height;

public:
    // Constructor to initialize dimensions
    Box(double w, double h) : width(w), height(h) {}

    // Declaring a friend function
    friend double calculateArea(Box b);
};

// Friend function definition
double calculateArea(Box b) {
    return b.width * b.height;  // Can access private members of Box
}

int main() {
    Box b(10.0, 5.0);
    cout << "Area: " << calculateArea(b) << endl;  // Accessing private members using friend function

    return 0;
}
```

**Output:**
```
Area: 50
```

In this example, the function `calculateArea()` is a **friend function** and can access the private members (`width` and `height`) of the `Box` class.

---

### **4. Calling Member Functions**

You can call member functions using the dot operator (`.`) for normal objects or the arrow operator (`->`) for objects through pointers.

#### **Example:**

```cpp
int main() {
    // Creating an object
    Rectangle rect(10, 5);

    // Calling member function using dot operator
    rect.display();

    // Creating a pointer to an object
    Rectangle* rectPtr = new Rectangle(15, 7);

    // Calling member function using arrow operator
    rectPtr->display();

    // Cleaning up dynamically allocated memory
    delete rectPtr;

    return 0;
}
```

**Output:**
```
Width: 10, Height: 5
Area: 50
Width: 15, Height: 7
Area: 105
```

---

### **5. Summary**

- **Member functions** are functions defined inside a class and operate on its data members.
- They can be **regular**, **constant**, **static**, or **friend functions**.
- **Regular member functions** are used to modify or retrieve data members of an object.
- **Constant member functions** do not modify the object's state.
- **Static member functions** can be called without an instance of the class and can only access static members.
- **Friend functions** are non-member functions that can access private or protected members of a class.

