### **Creating Contract-Like Methods in Child Classes in JavaScript**

In object-oriented programming, a **contract** refers to a set of rules that a class must follow. These rules can be thought of as methods that must be implemented in the subclasses. In JavaScript, you can simulate contract-like behavior by defining **abstract methods** in a **base class** and requiring child classes to implement these methods. This creates a "contract" that all subclasses must adhere to.

JavaScript does not support traditional **interfaces** like some other languages (Java, C#, etc.), but you can enforce contract-like methods using some programming techniques.

### **How to Create Contract-Like Methods in Child Classes**

To create contract-like methods:
1. **Base class with abstract methods**: Define methods in the base class that child classes must implement.
2. **Throw errors for unimplemented methods**: If the method is not implemented in a subclass, throw an error.
3. **Child class implementation**: Ensure child classes implement these methods.

### **Simulating Contract-Like Methods Using a Base Class**

Here's a simple example to demonstrate how we can simulate contract-like methods in JavaScript using a base class and child classes:

---

### **Step 1: Define the Base Class with Contract-Like Methods**

In the base class, define methods that must be implemented by child classes. You can use error throwing in these methods to simulate an abstract contract.

```javascript
class Shape {
  constructor() {
    if (new.target === Shape) {
      throw new Error("Cannot instantiate an abstract class.");
    }
  }

  // Abstract method (contract method) to calculate the area of the shape
  calculateArea() {
    throw new Error("Method 'calculateArea()' must be implemented.");
  }

  // Abstract method (contract method) to calculate the perimeter of the shape
  calculatePerimeter() {
    throw new Error("Method 'calculatePerimeter()' must be implemented.");
  }
}
```

#### **Explanation**:
- The `Shape` class defines two contract-like methods: `calculateArea()` and `calculatePerimeter()`. These methods are not implemented in the base class, but they must be implemented in any child class.
- The constructor throws an error if someone tries to instantiate the `Shape` class directly, ensuring it is used only as a base class.

---

### **Step 2: Create Child Classes Implementing the Contract**

Now, let's create concrete classes (e.g., `Rectangle` and `Circle`) that implement the contract methods from the `Shape` class.

```javascript
class Rectangle extends Shape {
  constructor(width, height) {
    super(); // Call the parent constructor
    this.width = width;
    this.height = height;
  }

  // Implementing the contract method to calculate the area
  calculateArea() {
    return this.width * this.height;
  }

  // Implementing the contract method to calculate the perimeter
  calculatePerimeter() {
    return 2 * (this.width + this.height);
  }
}

class Circle extends Shape {
  constructor(radius) {
    super(); // Call the parent constructor
    this.radius = radius;
  }

  // Implementing the contract method to calculate the area
  calculateArea() {
    return Math.PI * this.radius ** 2;
  }

  // Implementing the contract method to calculate the perimeter
  calculatePerimeter() {
    return 2 * Math.PI * this.radius;
  }
}
```

#### **Explanation**:
- Both `Rectangle` and `Circle` classes inherit from the `Shape` class and implement the `calculateArea()` and `calculatePerimeter()` methods.
- These methods provide concrete implementations of the abstract methods defined in the `Shape` class.

---

### **Step 3: Instantiate and Use the Classes**

You can now instantiate the concrete classes and call the contract methods (`calculateArea` and `calculatePerimeter`).

```javascript
const rectangle = new Rectangle(10, 5);
console.log(`Rectangle Area: ${rectangle.calculateArea()}`); // Output: Rectangle Area: 50
console.log(`Rectangle Perimeter: ${rectangle.calculatePerimeter()}`); // Output: Rectangle Perimeter: 30

const circle = new Circle(7);
console.log(`Circle Area: ${circle.calculateArea()}`); // Output: Circle Area: 153.93804002589985
console.log(`Circle Perimeter: ${circle.calculatePerimeter()}`); // Output: Circle Perimeter: 43.982297150257104
```

#### **Explanation**:
- The `Rectangle` and `Circle` instances successfully call the contract methods `calculateArea()` and `calculatePerimeter()`, and they return the expected results.

---

### **Step 4: Enforcing the Contract**

If a child class doesn't implement the contract methods (i.e., doesn't implement `calculateArea()` or `calculatePerimeter()`), an error will be thrown when you try to call them.

For example, this will result in an error:

```javascript
class Triangle extends Shape {
  constructor(base, height) {
    super();
    this.base = base;
    this.height = height;
  }

  // The contract methods are missing here, so the error will be thrown
}

const triangle = new Triangle(10, 5);
triangle.calculateArea(); // Error: Method 'calculateArea()' must be implemented.
```

#### **Explanation**:
- In this case, the `Triangle` class does not implement `calculateArea()` or `calculatePerimeter()`. So when you try to call `calculateArea()`, an error will be thrown, ensuring the contract is enforced.

---

### **Conclusion**

In JavaScript, you can simulate **contract-like behavior** using base classes and abstract methods. By throwing errors in methods that are expected to be overridden, you enforce a contract that child classes must implement specific methods.

This approach:
- Creates a structure that ensures consistency across subclasses.
- Prevents errors due to missing method implementations.
- Provides flexibility in extending functionality in subclasses while adhering to the contract set by the base class.
