### **Using `super.method()` to Call Parent Methods**

In JavaScript, when you override a method in a child class, you can still access the parent class’s version of that method using `super.method()`. This allows you to call the parent method in addition to the new implementation in the child class, effectively combining the behavior from both classes.

Using `super.method()` is particularly useful when you want to:

- **Extend** the functionality of a method in the child class without completely replacing the parent method.
- **Retain behavior** from the parent class while adding new functionality specific to the child class.

---

### **Basic Syntax of `super.method()`**

```javascript
super.methodName(arguments);
```

- `super`: Refers to the parent class.
- `methodName`: The method you want to call from the parent class.
- `arguments`: Any arguments that need to be passed to the parent method (if applicable).

---

### **Example 1: Using `super.method()` to Extend Parent Method**

In this example, the `Dog` class overrides the `speak()` method from the `Animal` class but also retains the parent class’s behavior by calling `super.speak()`.

```javascript
class Animal {
  speak() {
    console.log('Animal makes a sound');
  }
}

class Dog extends Animal {
  speak() {
    super.speak();  // Call the parent class's speak method
    console.log('Dog barks');
  }
}

const dog = new Dog();
dog.speak();
// Output:
// Animal makes a sound
// Dog barks
```

- **Explanation**:
  - The `Dog` class overrides the `speak()` method of the `Animal` class.
  - `super.speak()` calls the `speak()` method from the `Animal` class, and then the `Dog` class adds its own behavior with `console.log('Dog barks')`.

---

### **Example 2: Using `super.method()` with Arguments**

You can pass arguments to the parent class's method when calling it with `super.method()`.

```javascript
class Vehicle {
  drive(speed) {
    console.log(`Driving at ${speed} km/h`);
  }
}

class Car extends Vehicle {
  drive(speed, gear) {
    super.drive(speed);  // Call the parent class's drive method
    console.log(`In gear ${gear}`);
  }
}

const car = new Car();
car.drive(100, 3);
// Output:
// Driving at 100 km/h
// In gear 3
```

- **Explanation**:
  - The `Car` class extends `Vehicle` and overrides the `drive()` method.
  - The overridden method calls the parent class’s `drive()` method using `super.drive(speed)` and then adds more functionality by logging the gear.

---

### **Example 3: Calling a Parent Class Static Method with `super`**

You can also use `super` to call static methods from the parent class in the child class.

```javascript
class Animal {
  static info() {
    console.log('This is an animal');
  }
}

class Dog extends Animal {
  static info() {
    super.info();  // Call the parent class's static info method
    console.log('This is a dog');
  }
}

Dog.info();
// Output:
// This is an animal
// This is a dog
```

- **Explanation**:
  - The `Dog` class calls the static method `info()` from the `Animal` class using `super.info()`. This allows the child class to first execute the behavior from the parent class and then add its own functionality.

---

### **When to Use `super.method()`**

- **To Retain Parent Behavior**: 
  If the parent class’s method provides essential functionality that you want to retain, but you need to add or modify its behavior in the child class, you can use `super.method()` to call the parent method.
  
- **Combining Parent and Child Logic**: 
  Sometimes, the child class's method might want to do some extra work (for example, logging, processing data) while still relying on the parent class's behavior. Using `super.method()` lets you combine both functionalities.

- **Polymorphism**: 
  Using `super.method()` in combination with overriding allows you to implement polymorphism, where a method in the child class can behave differently but still leverage functionality from the parent class.

---

### **Key Considerations**

1. **Accessing Parent Constructor with `super()`**:
   - `super()` is used to call the constructor of the parent class when creating an instance of a subclass. If you are calling methods, you use `super.method()` instead.
   
2. **Calling `super.method()` in Overridden Methods**:
   - If the child class has overridden a method, you can still call the parent’s method using `super.method()`. This is useful for combining behavior from both classes.
   
3. **`super` in Static Methods**:
   - `super.method()` can also be used in static methods to call the parent class’s static methods, allowing the child class to extend or modify the static behavior.

---

### **Example 4: Combining Multiple Parent Methods with `super.method()`**

In this example, we have two methods in the parent class, and the child class calls both using `super.method()`.

```javascript
class Shape {
  draw() {
    console.log('Drawing the shape');
  }
  
  resize() {
    console.log('Resizing the shape');
  }
}

class Circle extends Shape {
  draw() {
    super.draw();  // Call parent draw method
    console.log('Drawing the circle');
  }
  
  resize() {
    super.resize();  // Call parent resize method
    console.log('Resizing the circle');
  }
}

const circle = new Circle();
circle.draw();
// Output:
// Drawing the shape
// Drawing the circle

circle.resize();
// Output:
// Resizing the shape
// Resizing the circle
```

- **Explanation**:
  - The `Circle` class overrides both the `draw()` and `resize()` methods from the `Shape` class.
  - Each method in the `Circle` class first calls the corresponding parent method using `super.method()` and then adds additional behavior specific to the `Circle` class.

---

### **Conclusion**

Using `super.method()` allows a child class to **invoke methods** from its **parent class**, enabling the combination of inherited behavior with new behavior. It is an essential tool for method overriding and extending the functionality of base class methods.
