Here’s a detailed explanation of the **principles of Object-Oriented Programming (OOP):**  

---

### **1. Encapsulation**
   - **Definition**: Encapsulation is the bundling of data (attributes) and methods (functions) that operate on the data into a single unit called a **class**.  
   - **Purpose**: Protects data from unauthorized access and allows controlled interaction using methods.  
   - **Key Features**:  
     - **Access Modifiers**: `private`, `protected`, `public`.  
     - Use of **getters and setters** to control data access.  

   **Example**:  
   ```cpp
   class BankAccount {
   private:
       double balance; // Private data cannot be accessed directly
   public:
       BankAccount(double initialBalance) {
           balance = initialBalance;
       }
       void deposit(double amount) {
           if (amount > 0) balance += amount;
       }
       double getBalance() {
           return balance; // Controlled access to private data
       }
   };
   ```

   **Benefits**:
   - Protects sensitive data.
   - Prevents unintended interference with the internal state of an object.

---

### **2. Inheritance**
   - **Definition**: Inheritance allows a new class (child class) to acquire properties and methods from an existing class (parent class).  
   - **Purpose**: Promotes code reuse and establishes a hierarchical relationship.  
   - **Types**:  
     - Single Inheritance  
     - Multilevel Inheritance  
     - Multiple Inheritance (using multiple base classes)  

   **Example**:  
   ```cpp
   class Animal {
   public:
       void eat() { cout << "Eating food." << endl; }
   };

   class Dog : public Animal { // Dog inherits Animal
   public:
       void bark() { cout << "Barking!" << endl; }
   };

   int main() {
       Dog dog;
       dog.eat(); // Inherited method
       dog.bark(); // Child class method
   }
   ```

   **Benefits**:
   - Reduces code duplication.
   - Simplifies the addition of new features.

---

### **3. Polymorphism**
   - **Definition**: Polymorphism means "many forms." It allows the same interface to be used for different underlying data types or behaviors.  
   - **Types**:
     - **Compile-time Polymorphism**: Achieved through **function overloading** and **operator overloading**.
     - **Runtime Polymorphism**: Achieved through **virtual functions** and **method overriding**.  

   **Example (Compile-time Polymorphism - Function Overloading)**:  
   ```cpp
   class Math {
   public:
       int add(int a, int b) {
           return a + b;
       }
       double add(double a, double b) {
           return a + b;
       }
   };
   ```

   **Example (Runtime Polymorphism - Virtual Function)**:  
   ```cpp
   class Shape {
   public:
       virtual void draw() { cout << "Drawing shape" << endl; }
   };

   class Circle : public Shape {
   public:
       void draw() override { cout << "Drawing circle" << endl; }
   };

   int main() {
       Shape* shape = new Circle();
       shape->draw(); // Calls the derived class method
   }
   ```

   **Benefits**:
   - Enhances flexibility and scalability.
   - Supports the use of interfaces for dynamic behavior.

---

### **4. Abstraction**
   - **Definition**: Abstraction hides the complex implementation details and only shows the essential features of an object.  
   - **Purpose**: Focuses on what an object does rather than how it does it.  
   - **Achieved Through**:
     - Abstract classes (with pure virtual functions).
     - Interfaces in some languages.  

   **Example**:  
   ```cpp
   class AbstractShape {
   public:
       virtual void draw() = 0; // Pure virtual function
   };

   class Rectangle : public AbstractShape {
   public:
       void draw() override { cout << "Drawing rectangle" << endl; }
   };

   int main() {
       AbstractShape* shape = new Rectangle();
       shape->draw(); // Calls Rectangle's draw method
   }
   ```

   **Benefits**:
   - Reduces complexity by focusing only on high-level functionalities.
   - Makes systems easier to extend and maintain.

---

### **Summary Table**

| Principle         | Definition                                                   | Key Features                                       |
|--------------------|-------------------------------------------------------------|---------------------------------------------------|
| **Encapsulation**  | Bundling data and methods into a class; data hiding.         | Access modifiers (`private`, `public`), getters, setters. |
| **Inheritance**    | Reuse properties/methods of a parent class in a child class. | Parent-child relationship, access modifiers.      |
| **Polymorphism**   | Ability to take many forms (same method, different behavior).| Function overloading, method overriding.          |
| **Abstraction**    | Hiding implementation details and exposing functionality.    | Pure virtual functions, abstract classes.         |

---

