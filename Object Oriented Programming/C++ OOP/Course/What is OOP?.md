Object-Oriented Programming (OOP) is a programming paradigm that organizes software design around **objects**, rather than **functions** or **logic**. An object is an instance of a class, and it contains both **data** (attributes) and **behavior** (methods).  

OOP is based on four fundamental principles:  

---

### **1. Encapsulation**
   - **Definition**: Encapsulation is the bundling of data (variables) and methods (functions) that operate on the data into a single unit called a class.
   - **Purpose**: To restrict direct access to certain components and protect the integrity of the object’s state.
   - **Example**: 
     ```cpp
     class BankAccount {
         private:
             double balance; // Encapsulated data
         public:
             void deposit(double amount) { balance += amount; }
             double getBalance() { return balance; }
     };
     ```

---

### **2. Inheritance**
   - **Definition**: Inheritance allows one class (child class) to inherit attributes and methods from another class (parent class).
   - **Purpose**: To promote code reuse and create a hierarchical relationship between classes.
   - **Example**:
     ```cpp
     class Animal {
         public:
             void eat() { cout << "Eating..."; }
     };

     class Dog : public Animal {
         public:
             void bark() { cout << "Barking..."; }
     };
     ```

---

### **3. Polymorphism**
   - **Definition**: Polymorphism allows objects of different classes to be treated as objects of a common superclass. It enables the same function or operator to behave differently based on the context.
   - **Types**:
     - **Compile-time Polymorphism**: Function overloading and operator overloading.
     - **Runtime Polymorphism**: Virtual functions and overriding.
   - **Example**:
     ```cpp
     class Shape {
         public:
             virtual void draw() { cout << "Drawing shape"; }
     };

     class Circle : public Shape {
         public:
             void draw() override { cout << "Drawing circle"; }
     };
     ```

---

### **4. Abstraction**
   - **Definition**: Abstraction hides complex implementation details and shows only the necessary features of an object.
   - **Purpose**: To reduce complexity and increase efficiency.
   - **Example**:
     ```cpp
     class AbstractShape {
         public:
             virtual void draw() = 0; // Pure virtual function
     };

     class Rectangle : public AbstractShape {
         public:
             void draw() override { cout << "Drawing rectangle"; }
     };
     ```

---

### **Advantages of OOP**
   - **Modularity**: Makes the code more manageable by breaking it into smaller, reusable objects.
   - **Reusability**: Code can be reused through inheritance and polymorphism.
   - **Maintainability**: Encapsulation ensures better control over data and reduces the impact of changes.
   - **Scalability**: Easier to scale large projects using OOP principles.

---
