### **Getters and Setters in C++**

**Getters** and **setters** are special member functions used to access and modify the private data members of a class. These methods are commonly used to implement **data hiding** and **encapsulation**, ensuring that the internal state of an object is controlled and modified only in a controlled manner.

---

### **1. What are Getters and Setters?**

- **Getter** (also known as an **accessor**): A function that returns the value of a private data member. It allows read-only access to the object's internal state.
- **Setter** (also known as a **mutator**): A function that modifies the value of a private data member. It provides controlled write access to the internal state of an object.

By using getters and setters, you can control how data is accessed or modified, enforce validation, and prevent unauthorized changes.

---

### **2. Why Use Getters and Setters?**

- **Encapsulation**: You can hide the internal representation of an object while exposing a controlled interface for interacting with it.
- **Validation**: Setters can include validation logic to ensure that the data remains in a valid state.
- **Security**: Getters and setters allow you to control access to sensitive data, limiting how and where the data can be accessed or modified.

---

### **3. Syntax of Getters and Setters**

Here’s the general syntax for creating getters and setters in C++:

```cpp
class ClassName {
private:
    // Private data member
    int variable;

public:
    // Getter function (accessor)
    int getVariable() const {
        return variable;
    }

    // Setter function (mutator)
    void setVariable(int value) {
        if (value >= 0) {  // Validation logic
            variable = value;
        } else {
            cout << "Invalid value!" << endl;
        }
    }
};
```

---

### **4. Example of Getters and Setters**

Let’s consider a `Person` class that uses getters and setters to manage the `age` data member:

```cpp
#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    // Getter for name
    string getName() const {
        return name;
    }

    // Setter for name
    void setName(const string& newName) {
        name = newName;
    }

    // Getter for age
    int getAge() const {
        return age;
    }

    // Setter for age with validation
    void setAge(int newAge) {
        if (newAge >= 0 && newAge <= 120) {  // Valid age range
            age = newAge;
        } else {
            cout << "Invalid age!" << endl;
        }
    }
};

int main() {
    Person person;
    
    // Set name and age using setters
    person.setName("John Doe");
    person.setAge(25);
    
    // Get name and age using getters
    cout << "Name: " << person.getName() << endl;
    cout << "Age: " << person.getAge() << endl;

    // Attempt to set invalid age
    person.setAge(130);  // Invalid age

    return 0;
}
```

**Output:**
```
Name: John Doe
Age: 25
Invalid age!
```

### **Key Points in the Example:**
- The `name` and `age` data members are **private**, which means they can't be accessed directly from outside the class.
- The `getName()` and `getAge()` methods allow access to the values of `name` and `age`, but only in a read-only manner.
- The `setName()` and `setAge()` methods allow modification of `name` and `age`, with `setAge()` including validation to ensure the age is within a valid range.

---

### **5. Advantages of Using Getters and Setters**

- **Encapsulation**: The internal representation of the object is hidden, and only controlled access through getter and setter methods is provided.
- **Data Validation**: Setters can enforce rules or validations before updating the internal state. For example, in the `setAge()` method above, we check if the age is a valid number before updating it.
- **Read-Only or Write-Only Properties**: Getters and setters allow you to create read-only or write-only properties. For example, you could have a class with a getter for a property but no setter, making it a read-only property.
- **Changing Internal Implementation**: If the internal data representation needs to change (e.g., switching from an `int` to `float` for age), you can do so without changing the interface of the class, as long as the getter and setter methods remain the same.
- **Security**: You can control access to sensitive data by applying security checks in setters and getters.

---

### **6. Getters and Setters with `const` Keyword**

If a getter method is meant to only retrieve data without modifying it, it should be marked as `const`. This indicates that the method will not modify any class members and can be called on **const objects**.

```cpp
class Rectangle {
private:
    double width;
    double height;

public:
    // Getter method with const
    double getArea() const {
        return width * height;
    }

    // Setter method
    void setWidth(double w) {
        width = w;
    }

    void setHeight(double h) {
        height = h;
    }
};

int main() {
    Rectangle rect;
    rect.setWidth(5.0);
    rect.setHeight(10.0);
    
    cout << "Area: " << rect.getArea() << endl;  // Calls const getter
    return 0;
}
```

### **7. Read-Only Data with Getters**

You may use getters to expose data as read-only. For example, providing only getter methods for `width` and `height` but no setter methods ensures the values can only be read, not modified.

```cpp
class Rectangle {
private:
    double width;
    double height;

public:
    // Getter methods for read-only access
    double getWidth() const {
        return width;
    }

    double getHeight() const {
        return height;
    }

    // Constructor to initialize width and height
    Rectangle(double w, double h) : width(w), height(h) {}
};

int main() {
    Rectangle rect(5.0, 10.0);

    cout << "Width: " << rect.getWidth() << endl;
    cout << "Height: " << rect.getHeight() << endl;

    // rect.width = 10.0;  // Error: cannot assign to 'width' because it's private

    return 0;
}
```

---

### **8. Summary of Getters and Setters**

- **Getters** are methods that allow controlled access to private data members of a class.
- **Setters** are methods that allow controlled modification of private data members.
- Using getters and setters allows for **data encapsulation**, **validation**, and **error prevention**.
- They help in maintaining flexibility, as internal implementation can be changed without affecting external code using the class.

