### **Simulating Abstract Classes Using Base Classes in JavaScript**

In JavaScript, **abstract classes** are not directly supported, but you can simulate them by creating **base classes** that enforce rules for subclasses. A base class in this case will serve as a template, ensuring that derived classes implement certain methods (abstract methods) while still allowing shared functionality (concrete methods).

We can achieve this by:

1. **Throwing an error** in the base class constructor if it's instantiated directly.
2. **Enforcing method implementation** by throwing errors in the base class methods if they are not overridden by subclasses.

This method ensures that the base class cannot be instantiated on its own and forces subclasses to implement the abstract methods.

### **Simulating Abstract Classes Using a Base Class**

Here’s how you can simulate abstract classes in JavaScript by using a base class that requires subclasses to implement certain methods.

---

### **Step 1: Create the Base Class (Abstract Class)**

The base class contains both concrete (implemented) and abstract (unimplemented) methods. We'll throw an error for the abstract methods to enforce that they must be implemented by subclasses.

```javascript
class Vehicle {
  constructor() {
    // Prevent instantiation of the base class
    if (new.target === Vehicle) {
      throw new Error("Cannot instantiate an abstract class.");
    }
  }

  // Abstract method (must be implemented by subclasses)
  startEngine() {
    throw new Error("Method 'startEngine()' must be implemented.");
  }

  // Concrete method (can be shared by subclasses)
  drive() {
    console.log("The vehicle is moving.");
  }
}
```

#### **Explanation**:
- The `Vehicle` class is a base class (abstract class). The constructor checks if the class is being instantiated directly, throwing an error if it is.
- The `startEngine()` method is an abstract method. Subclasses must implement this method.
- The `drive()` method is a concrete method that can be used by subclasses as is.

---

### **Step 2: Create Subclasses (Concrete Classes)**

Now, we create subclasses that extend the base class and implement the abstract method `startEngine()`.

```javascript
class Car extends Vehicle {
  constructor(make, model) {
    super(); // Call the parent constructor
    this.make = make;
    this.model = model;
  }

  // Implementing the abstract method from the base class
  startEngine() {
    console.log(`Starting the engine of the ${this.make} ${this.model} car.`);
  }
}

class Truck extends Vehicle {
  constructor(make, model) {
    super(); // Call the parent constructor
    this.make = make;
    this.model = model;
  }

  // Implementing the abstract method from the base class
  startEngine() {
    console.log(`Starting the engine of the ${this.make} ${this.model} truck.`);
  }
}
```

#### **Explanation**:
- `Car` and `Truck` are concrete classes that extend `Vehicle`.
- Each class implements the `startEngine()` method as required by the base class.

---

### **Step 3: Instantiate Subclasses**

You can now instantiate the subclasses (`Car` and `Truck`) and call their methods.

```javascript
const car = new Car("Toyota", "Corolla");
car.startEngine(); // Output: Starting the engine of the Toyota Corolla car.
car.drive();       // Output: The vehicle is moving.

const truck = new Truck("Ford", "F-150");
truck.startEngine(); // Output: Starting the engine of the Ford F-150 truck.
truck.drive();       // Output: The vehicle is moving.
```

#### **Explanation**:
- Both `Car` and `Truck` are instantiated correctly because they implement the `startEngine()` method.
- The `drive()` method is inherited from the `Vehicle` class, so it works for both `Car` and `Truck`.

---

### **Step 4: Prevent Instantiation of Base Class**

If you attempt to instantiate the base class `Vehicle` directly, it will throw an error.

```javascript
// Uncommenting the following line will throw an error
// const vehicle = new Vehicle(); // Error: Cannot instantiate an abstract class.
```

#### **Explanation**:
- The constructor of the `Vehicle` class prevents it from being instantiated directly, enforcing that `Vehicle` is an abstract class.

---

### **Complete Example**

```javascript
class Vehicle {
  constructor() {
    if (new.target === Vehicle) {
      throw new Error("Cannot instantiate an abstract class.");
    }
  }

  startEngine() {
    throw new Error("Method 'startEngine()' must be implemented.");
  }

  drive() {
    console.log("The vehicle is moving.");
  }
}

class Car extends Vehicle {
  constructor(make, model) {
    super();
    this.make = make;
    this.model = model;
  }

  startEngine() {
    console.log(`Starting the engine of the ${this.make} ${this.model} car.`);
  }
}

class Truck extends Vehicle {
  constructor(make, model) {
    super();
    this.make = make;
    this.model = model;
  }

  startEngine() {
    console.log(`Starting the engine of the ${this.make} ${this.model} truck.`);
  }
}

const car = new Car("Toyota", "Corolla");
car.startEngine(); // Output: Starting the engine of the Toyota Corolla car.
car.drive();       // Output: The vehicle is moving.

const truck = new Truck("Ford", "F-150");
truck.startEngine(); // Output: Starting the engine of the Ford F-150 truck.
truck.drive();       // Output: The vehicle is moving.

try {
  const vehicle = new Vehicle(); // Error: Cannot instantiate an abstract class.
} catch (error) {
  console.log(error.message); // Output: Cannot instantiate an abstract class.
}
```

---

### **Advantages of Simulating Abstract Classes in JavaScript**

1. **Clear Structure**: You can define a clear structure for your classes, ensuring that subclasses follow a certain contract by implementing specific methods.
2. **Code Reusability**: Shared functionality can be placed in the base class, avoiding code duplication and promoting code reusability.
3. **Enforcing Consistency**: Abstract methods enforce that subclasses implement certain functionality, which maintains consistency across different parts of your application.
4. **Error Prevention**: Preventing direct instantiation of the base class ensures that abstract classes are used only as intended — to be extended by concrete subclasses.

---

### **Conclusion**

While JavaScript doesn’t natively support abstract classes, you can easily simulate them using base classes with error handling and method enforcement. This allows you to design classes that provide both shared functionality (concrete methods) and a required structure (abstract methods) for subclasses.
