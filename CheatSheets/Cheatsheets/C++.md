An extended C++ cheat sheet covering essential syntax, concepts, and commands. This includes data types, operators, control structures, functions, classes, memory management, templates, and more. It’s designed to serve as a quick reference guide for C++ programming.

---

## **Basic Syntax**

### 1. **Structure of a C++ Program**

```cpp
#include <iostream>   // Include input-output stream

int main() {
    std::cout << "Hello, World!" << std::endl;  // Output to console
    return 0;  // Return statement
}
```

**Explanation**: Every C++ program starts with including necessary headers. The `main` function serves as the entry point, and `return 0` indicates successful execution.

---

## **Data Types and Variable Declaration**

### 2. **Primitive Data Types**

```cpp
int age = 25;          // Integer
float salary = 5500.5; // Floating point
double balance = 1.75; // Double precision floating point
char grade = 'A';      // Character
bool isEmployed = true; // Boolean
```

**Explanation**: C++ provides several data types for variables, including `int`, `float`, `double`, `char`, and `bool`.

### 3. **Modifiers for Data Types**

```cpp
short int s = 1;       // Short integer
long int l = 123456;   // Long integer
unsigned int u = 25;   // Unsigned integer (positive only)
```

**Explanation**: Modifiers like `short`, `long`, and `unsigned` change the range of the base data types.

### 4. **Constants**

```cpp
const double PI = 3.14159;  // Constant variable
```

**Explanation**: The `const` keyword defines constants that cannot be modified after initialization.

---

## **Operators**

### 5. **Arithmetic Operators**

```cpp
int a = 10 + 5;       // Addition
int b = 10 - 5;       // Subtraction
int c = 10 * 5;       // Multiplication
int d = 10 / 2;       // Division
int e = 10 % 3;       // Modulus (remainder)
```

**Explanation**: Basic arithmetic operators are used for calculations. `%` returns the remainder of division.

### 6. **Relational Operators**

```cpp
if (a == b) { }       // Equal to
if (a != b) { }       // Not equal to
if (a > b) { }        // Greater than
if (a < b) { }        // Less than
```

**Explanation**: Relational operators are used to compare values, often in conditional statements.

### 7. **Logical Operators**

```cpp
if (a > 5 && b < 10) { }   // Logical AND
if (a > 5 || b < 10) { }   // Logical OR
if (!(a == b)) { }         // Logical NOT
```

**Explanation**: Logical operators are used to combine multiple conditions in `if` statements.

---

## **Control Structures**

### 8. **If-Else Statements**

```cpp
if (a > 0) {
    std::cout << "Positive" << std::endl;
} else {
    std::cout << "Negative or zero" << std::endl;
}
```

**Explanation**: `if-else` statements allow conditional branching in the program based on conditions.

### 9. **Switch Case**

```cpp
int grade = 'A';
switch (grade) {
    case 'A':
        std::cout << "Excellent" << std::endl;
        break;
    case 'B':
        std::cout << "Good" << std::endl;
        break;
    default:
        std::cout << "Needs Improvement" << std::endl;
}
```

**Explanation**: `switch` is used when multiple possible values for a variable are checked, reducing multiple `if-else` conditions.

### 10. **Loops**

```cpp
// For loop
for (int i = 0; i < 5; i++) {
    std::cout << i << " ";
}

// While loop
int j = 0;
while (j < 5) {
    std::cout << j << " ";
    j++;
}

// Do-While loop
int k = 0;
do {
    std::cout << k << " ";
    k++;
} while (k < 5);
```

**Explanation**: `for`, `while`, and `do-while` loops are used for iterative operations. The `for` loop is often used when the number of iterations is known.

---

## **Functions**

### 11. **Defining and Calling Functions**

```cpp
#include <iostream>

void greet() {
    std::cout << "Hello!" << std::endl;
}

int add(int a, int b) {
    return a + b;
}

int main() {
    greet();                // Calling a function
    std::cout << add(5, 3) << std::endl;
    return 0;
}
```

**Explanation**: Functions in C++ can return a value or be `void` (no return). Parameters can be passed as arguments, enabling code reuse.

### 12. **Function Overloading**

```cpp
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}
```

**Explanation**: Function overloading allows multiple functions with the same name but different parameters.

---

## **Classes and Objects**

### 13. **Creating a Class**

```cpp
class Person {
public:
    std::string name;
    int age;

    void greet() {
        std::cout << "Hello, " << name << "!" << std::endl;
    }
};

int main() {
    Person person;            // Creating an object
    person.name = "Alice";   // Setting properties
    person.age = 25;
    person.greet();          // Calling a method
    return 0;
}
```

**Explanation**: Classes define a blueprint for objects with properties and methods. Objects are instances of classes.

### 14. **Constructors and Destructors**

```cpp
class Person {
public:
    std::string name;
    int age;

    // Constructor
    Person(std::string n, int a) : name(n), age(a) { }

    // Destructor
    ~Person() { }
};

int main() {
    Person person("Alice", 25);  // Constructor called
    return 0;                    // Destructor called
}
```

**Explanation**: Constructors initialize objects, while destructors are called when objects are destroyed, handling resource deallocation.

### 15. **Inheritance**

```cpp
class Animal {
public:
    void speak() {
        std::cout << "Animal speaks" << std::endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        std::cout << "Woof!" << std::endl;
    }
};

int main() {
    Dog dog;
    dog.speak();  // Inherited method
    dog.bark();   // Own method
    return 0;
}
```

**Explanation**: Inheritance allows a class to inherit properties and methods from another class, promoting code reuse.

### 16. **Polymorphism**

```cpp
class Base {
public:
    virtual void show() {
        std::cout << "Base class" << std::endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived class" << std::endl;
    }
};

int main() {
    Base* b = new Derived();
    b->show();  // Calls Derived class show()
    delete b;   // Clean up
    return 0;
}
```

**Explanation**: Polymorphism allows methods to be redefined in derived classes, enabling dynamic binding.

---

## **Memory Management**

### 17. **Dynamic Memory Allocation**

```cpp
int* arr = new int[5];  // Allocate memory for 5 integers
delete[] arr;           // Free memory
```

**Explanation**: `new` allocates memory on the heap, and `delete` releases it. Always match `new` with `delete`.

---

## **Templates**

### 18. **Function Templates**

```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(5, 3) << std::endl;       // Calls add<int>
    std::cout << add(5.5, 2.5) << std::endl;   // Calls add<double>
    return 0;
}
```

**Explanation**: Templates allow writing generic functions that can operate with any data type.

### 19. **Class Templates**

```cpp
template <class T>
class Box {
public:
    T data;
    Box(T d) : data(d) { }
};

int main() {
    Box<int> intBox(123);
    Box<std::string> strBox("Hello");
    std::cout << intBox.data << ", " << strBox.data << std::endl;
    return 0;
}
```

**Explanation**: Class templates allow creating classes that can handle any data type.

---

## **Standard Template Library (STL)**

### 20. **Vectors**

```cpp
#include <vector>

std::vector<int> numbers;
numbers.push_back(1);

  // Add an element
numbers.push_back(2);
std::cout << numbers[0] << std::endl;  // Access element
```

**Explanation**: `std::vector` is a dynamic array that can resize and is part of the STL.

### 21. **Maps**

```cpp
#include <map>

std::map<std::string, int> ageMap;
ageMap["Alice"] = 25;
ageMap["Bob"] = 30;
std::cout << ageMap["Alice"] << std::endl;  // Access value
```

**Explanation**: `std::map` is an associative container that stores key-value pairs.

### 22. **Sets**

```cpp
#include <set>

std::set<int> uniqueNumbers;
uniqueNumbers.insert(1);
uniqueNumbers.insert(2);
uniqueNumbers.insert(1);  // Duplicate is ignored
std::cout << uniqueNumbers.size() << std::endl;  // Size of set
```

**Explanation**: `std::set` stores unique elements and automatically sorts them.

---

## **Error Handling**

### 23. **Exception Handling**

```cpp
#include <stdexcept>

void mayThrow() {
    throw std::runtime_error("An error occurred");
}

int main() {
    try {
        mayThrow();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;  // Handle exception
    }
    return 0;
}
```

**Explanation**: C++ uses `try`, `catch`, and `throw` for exception handling to manage runtime errors.

---

## **Namespaces**

### 24. **Using Namespaces**

```cpp
namespace MyNamespace {
    void func() {
        std::cout << "Inside MyNamespace" << std::endl;
    }
}

int main() {
    MyNamespace::func();  // Call function in namespace
    return 0;
}
```

**Explanation**: Namespaces prevent name conflicts and allow organizing code into logical groups.

---

## **Preprocessor Directives**

### 25. **Basic Preprocessor Directives**

```cpp
#define PI 3.14      // Constant macro
#include <iostream>  // Library inclusion
#undef PI           // Undefine macro
```

**Explanation**: Preprocessor directives, starting with `#`, are instructions for the compiler. Common ones include `#define`, `#include`, and `#undef`.

### 26. **Conditional Compilation**

```cpp
#ifdef DEBUG
    std::cout << "Debug mode" << std::endl;
#endif
```

**Explanation**: `#ifdef`, `#ifndef`, and `#endif` conditionally include or exclude code during compilation, often used for debugging or platform-specific code.

---

This cheat sheet should provide a comprehensive overview of the essential commands and concepts in C++. Regular practice with these commands will help you become proficient in C++ programming.
