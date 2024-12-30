Here's a comparison of **Procedural Programming** and **Object-Oriented Programming (OOP):**

---

### **1. Programming Paradigm**
   - **Procedural Programming**: Focuses on **functions** and their execution. The program is divided into a sequence of procedures or steps.
   - **Object-Oriented Programming (OOP)**: Focuses on **objects** and their interactions. The program is organized around classes and objects.

---

### **2. Approach**
   - **Procedural Programming**: Follows a **top-down** approach, starting from the main function and breaking the problem into smaller sub-problems (functions).
   - **OOP**: Follows a **bottom-up** approach, designing reusable and modular classes first, which are later used to solve the problem.

---

### **3. Key Components**
   - **Procedural Programming**: 
     - Functions
     - Variables
     - Data structures
   - **OOP**: 
     - Classes
     - Objects
     - Methods
     - Attributes

---

### **4. Data Handling**
   - **Procedural Programming**: Data is separate from the functions. Functions operate on global or local data.
     - Example:
       ```cpp
       int x = 10;
       void increment() { x++; }
       ```
   - **OOP**: Data and functions are bundled together in classes (encapsulation).
     - Example:
       ```cpp
       class Counter {
           private:
               int x;
           public:
               void increment() { x++; }
       };
       ```

---

### **5. Code Reusability**
   - **Procedural Programming**: Reusability is achieved through functions, but it can be limited for large-scale systems.
   - **OOP**: Reusability is achieved through **inheritance** and **polymorphism**, making it easier to extend functionality.

---

### **6. Security**
   - **Procedural Programming**: Data is less secure as global variables can be accessed and modified by any function.
   - **OOP**: Data security is higher because access to data is controlled using access modifiers (e.g., private, protected, public).

---

### **7. Maintainability**
   - **Procedural Programming**: Becomes harder to maintain as the project grows in size due to lack of modularization.
   - **OOP**: Easier to maintain because the code is organized into objects and classes.

---

### **8. Real-Life Analogies**
   - **Procedural Programming**: A recipe with step-by-step instructions. Each step performs a task but doesn't encapsulate data.
   - **OOP**: A car. Each car object has its own data (color, speed) and functions (accelerate, brake).

---

### **Example in C++**

#### Procedural Programming:
```cpp
#include <iostream>
using namespace std;

int x = 10;

void increment() {
    x++;
    cout << "Value: " << x << endl;
}

int main() {
    increment();
    return 0;
}
```

#### Object-Oriented Programming:
```cpp
#include <iostream>
using namespace std;

class Counter {
    private:
        int x;
    public:
        Counter(int value) : x(value) {}
        void increment() {
            x++;
            cout << "Value: " << x << endl;
        }
};

int main() {
    Counter counter(10);
    counter.increment();
    return 0;
}
```

---

### **When to Use?**
   - Use **Procedural Programming** for small programs with a clear sequence of steps.
   - Use **OOP** for large, complex projects requiring modularity, scalability, and better maintainability.

