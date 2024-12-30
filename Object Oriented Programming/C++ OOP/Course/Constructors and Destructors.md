### **Constructors and Destructors in C++**

In C++, **constructors** and **destructors** are special member functions that help manage the initialization and cleanup of objects.

---

### **1. Constructors**

A **constructor** is a special member function that is called **automatically** when an object of a class is created. Its primary role is to initialize the object, i.e., set the values of its data members when an object is instantiated.

#### **Key Features of Constructors:**
- They have the same name as the class.
- They do not have a return type (not even `void`).
- They are called automatically when an object is created.
- Constructors can be **overloaded** (i.e., multiple constructors with different parameter lists).
- If no constructor is defined, a **default constructor** is provided by the compiler.

#### **Syntax:**

```cpp
class ClassName {
public:
    ClassName() {  // Default constructor
        // Initialization code
    }

    ClassName(parameters) {  // Parameterized constructor
        // Initialization code using parameters
    }
};
```

---

### **2. Types of Constructors**

#### **a. Default Constructor**

A **default constructor** is one that takes no arguments. If no constructor is explicitly defined, the compiler generates a default constructor automatically, which initializes the data members to default values (such as 0 or `nullptr` for pointers).

```cpp
class Rectangle {
private:
    double width, height;

public:
    // Default constructor
    Rectangle() {
        width = 0;
        height = 0;
    }

    void display() {
        cout << "Width: " << width << ", Height: " << height << endl;
    }
};

int main() {
    Rectangle rect;  // Calls the default constructor
    rect.display();  // Outputs: Width: 0, Height: 0
    return 0;
}
```

#### **b. Parameterized Constructor**

A **parameterized constructor** is one that takes arguments to initialize the object's data members.

```cpp
class Rectangle {
private:
    double width, height;

public:
    // Parameterized constructor
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }

    void display() {
        cout << "Width: " << width << ", Height: " << height << endl;
    }
};

int main() {
    Rectangle rect(5.0, 3.0);  // Calls the parameterized constructor
    rect.display();  // Outputs: Width: 5, Height: 3
    return 0;
}
```

---

### **3. Constructor Overloading**

You can have multiple constructors in the same class, provided they have different parameter lists (i.e., different number or types of parameters).

```cpp
class Box {
private:
    double length, width, height;

public:
    // Default constructor
    Box() {
        length = width = height = 0;
    }

    // Parameterized constructor
    Box(double l, double w, double h) {
        length = l;
        width = w;
        height = h;
    }

    void display() {
        cout << "Length: " << length << ", Width: " << width << ", Height: " << height << endl;
    }
};

int main() {
    Box box1;  // Default constructor
    Box box2(5.0, 3.0, 2.0);  // Parameterized constructor

    box1.display();  // Outputs: Length: 0, Width: 0, Height: 0
    box2.display();  // Outputs: Length: 5, Width: 3, Height: 2

    return 0;
}
```

---

### **4. Destructor**

A **destructor** is a special member function that is called automatically when an object goes out of scope or is explicitly deleted. The destructor's main job is to perform **cleanup tasks** (e.g., releasing dynamically allocated memory, closing file handles, etc.).

#### **Key Features of Destructors:**
- A destructor has the same name as the class but with a tilde (`~`) prefix.
- It does not take any arguments, nor does it return any value.
- It is called automatically when an object goes out of scope or is explicitly destroyed using `delete` for objects created with `new`.
- A class can only have **one destructor** (cannot be overloaded).
- Destructors are usually used to release resources, such as memory or file handles, that were acquired during the lifetime of the object.

#### **Syntax:**

```cpp
class ClassName {
public:
    ~ClassName() {
        // Cleanup code
    }
};
```

---

### **5. Destructor Example**

Here's an example demonstrating the use of a destructor to release dynamically allocated memory:

```cpp
#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int* grades;  // Pointer to dynamically allocated array

public:
    // Constructor: Dynamically allocate memory
    Student(string n, int numGrades) {
        name = n;
        grades = new int[numGrades];  // Dynamically allocate memory for grades
    }

    // Destructor: Release dynamically allocated memory
    ~Student() {
        delete[] grades;  // Deallocate memory
        cout << "Memory for grades released." << endl;
    }

    // Function to set grade
    void setGrade(int index, int grade) {
        grades[index] = grade;
    }

    // Function to display grades
    void display() {
        cout << "Grades for " << name << ": ";
        for (int i = 0; i < 5; i++) {
            cout << grades[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Student student("John", 5);  // Constructor is called, memory allocated
    student.setGrade(0, 85);
    student.setGrade(1, 90);
    student.setGrade(2, 88);
    student.setGrade(3, 92);
    student.setGrade(4, 95);
    
    student.display();  // Display grades

    // Destructor will be called automatically when the object goes out of scope
    return 0;
}
```

**Output:**
```
Grades for John: 85 90 88 92 95 
Memory for grades released.
```

In this example:
- The `Student` constructor allocates memory for an array of grades dynamically.
- The `Student` destructor is called automatically when the object goes out of scope, and it releases the allocated memory using `delete[]`.

---

### **6. Destructor in Dynamic Memory Allocation**

If you allocate memory for an object dynamically using `new`, the destructor can be used to deallocate memory.

```cpp
#include <iostream>
using namespace std;

class Box {
private:
    double* length;
    double* width;

public:
    // Constructor: Dynamically allocate memory
    Box(double l, double w) {
        length = new double;
        width = new double;
        *length = l;
        *width = w;
    }

    // Destructor: Release dynamically allocated memory
    ~Box() {
        delete length;
        delete width;
        cout << "Memory for length and width released." << endl;
    }

    void display() {
        cout << "Length: " << *length << ", Width: " << *width << endl;
    }
};

int main() {
    Box* box = new Box(10.0, 5.0);  // Dynamically created object
    box->display();

    delete box;  // Destructor will be called, memory released

    return 0;
}
```

**Output:**
```
Length: 10, Width: 5
Memory for length and width released.
```

---

### **7. Summary**

- **Constructors**:
  - Automatically called when an object is created.
  - Used for initializing objects.
  - Can be **default** (no parameters) or **parameterized** (with parameters).
  - Can be **overloaded**.
  
- **Destructors**:
  - Automatically called when an object goes out of scope or is deleted.
  - Used for cleaning up resources, like deallocating memory.
  - Only one destructor per class.
  - Cannot take parameters or return values.

