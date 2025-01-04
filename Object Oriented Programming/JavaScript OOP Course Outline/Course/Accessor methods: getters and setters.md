### **Accessor Methods: Getters and Setters in JavaScript**

In JavaScript, **accessor methods** (commonly referred to as **getters** and **setters**) allow you to interact with private or protected fields of a class while maintaining control over how the fields are accessed or modified. Getters and setters are methods that provide a way to read (get) or modify (set) the values of an object's properties, while encapsulating the logic behind the access and modification.

#### **1. Getters**

A **getter** is a method that gets the value of a property. It allows you to define a **custom behavior** for how a property is accessed, such as performing validation, logging, or transforming the value before returning it.

##### **Syntax:**
```javascript
get propertyName() {
  return this._property; // Custom behavior
}
```

- **`get` keyword**: Defines a getter method.
- **No parameters**: Getters do not take any arguments.
- **Accessed like a property**: You call a getter method as if you were accessing a property, not a function.

##### **Example: Getter Method**

```javascript
class Circle {
  constructor(radius) {
    this._radius = radius; // underscore to indicate private-like property
  }

  // Getter method
  get radius() {
    return this._radius; // Return the radius value
  }

  get area() {
    return Math.PI * this._radius ** 2; // Calculate area based on radius
  }
}

const circle = new Circle(5);
console.log(circle.radius);  // 5 (accessed via getter)
console.log(circle.area);    // 78.53981633974483 (accessed via getter)
```

- The `radius` and `area` properties are accessed via getters, providing a way to encapsulate the logic and return values without directly exposing the internal `_radius` field.

#### **2. Setters**

A **setter** is a method that sets or modifies the value of a property. It allows you to define a **custom behavior** for how the property is updated, such as validation or transformation before the value is set.

##### **Syntax:**
```javascript
set propertyName(value) {
  this._property = value; // Custom behavior to set the value
}
```

- **`set` keyword**: Defines a setter method.
- **Takes one argument**: The setter method receives the value to be assigned to the property.
- **Accessed like a property**: You call a setter method as if you're setting a property, not calling a function.

##### **Example: Setter Method**

```javascript
class Person {
  constructor(name, age) {
    this._name = name;
    this._age = age;
  }

  // Getter method
  get name() {
    return this._name;
  }

  // Setter method
  set name(newName) {
    if (newName.length > 0) {
      this._name = newName; // Only set the name if it's a valid string
    } else {
      console.log('Name must be a non-empty string.');
    }
  }

  // Getter method
  get age() {
    return this._age;
  }

  // Setter method
  set age(newAge) {
    if (newAge > 0 && newAge < 120) {
      this._age = newAge; // Only set the age if it's a valid number
    } else {
      console.log('Age must be between 1 and 120.');
    }
  }
}

const person = new Person('John', 30);
console.log(person.name);  // John (via getter)
person.name = 'Alice';     // Modifies the name via setter
console.log(person.name);  // Alice
person.name = '';          // Name must be a non-empty string.
console.log(person.name);  // Alice (no change)
person.age = 150;          // Age must be between 1 and 120.
console.log(person.age);   // 30 (no change)
person.age = 25;           // Modifies the age via setter
console.log(person.age);   // 25
```

- The setter method for `name` ensures that the name must be a non-empty string, while the setter method for `age` ensures the age is within a valid range.
- By using setters, you can enforce rules or validations on the properties being set.

---

### **Why Use Getters and Setters?**

1. **Encapsulation:**
   - Getters and setters provide a controlled way to access and modify private properties, helping to protect and encapsulate the internal state of an object.

2. **Validation and Transformation:**
   - You can implement custom logic inside setters to validate input or transform the data before it's stored.
   - Getters can be used to compute or transform the value before returning it.

3. **Readability and Maintainability:**
   - Getters and setters allow you to modify the internal implementation without changing the external interface. External code accessing or modifying the property doesn't need to know whether it's interacting with a field or a method.
   - They provide better control over how data is accessed and updated, improving maintainability.

4. **Debugging and Logging:**
   - You can add debugging or logging logic within getter and setter methods to trace when properties are accessed or modified.

---

### **Using Getters and Setters with Private Fields**

You can use **private fields** in combination with getters and setters to further control access to internal data. Here's an example of using private fields with getters and setters:

#### **Example: Getters and Setters with Private Fields**

```javascript
class Rectangle {
  #length;  // Private field
  #width;   // Private field

  constructor(length, width) {
    this.#length = length;
    this.#width = width;
  }

  // Getter for length
  get length() {
    return this.#length;
  }

  // Setter for length
  set length(newLength) {
    if (newLength > 0) {
      this.#length = newLength;
    } else {
      console.log('Length must be greater than zero.');
    }
  }

  // Getter for width
  get width() {
    return this.#width;
  }

  // Setter for width
  set width(newWidth) {
    if (newWidth > 0) {
      this.#width = newWidth;
    } else {
      console.log('Width must be greater than zero.');
    }
  }

  // Getter for area
  get area() {
    return this.#length * this.#width;
  }
}

const rectangle = new Rectangle(10, 5);
console.log(rectangle.area); // 50 (via getter)
rectangle.length = 20;       // Valid setter
rectangle.width = -10;       // Invalid setter (logs error)
console.log(rectangle.area); // 100 (updated area)
```

- The private fields `#length` and `#width` are encapsulated and protected from direct access.
- The setters for `length` and `width` validate the input before modifying the private fields.
- The getter for `area` computes the area based on the private properties.

---

### **Summary of Getters and Setters**

- **Getters** provide a way to retrieve the value of an object’s property, allowing you to define custom logic or transformation when the property is accessed.
- **Setters** provide a way to modify an object’s property, allowing you to define custom validation or transformation before the property is updated.
- **Encapsulation**: Getters and setters help maintain encapsulation by controlling how data is accessed and modified.
- **Custom Logic**: You can add validation, transformation, or debugging logic within getters and setters to ensure correct behavior and integrity of the object's state.
- **Syntax**: Getters use `get`, setters use `set`, and both are accessed like regular properties without parentheses.

By using getters and setters, you enhance the flexibility, maintainability, and integrity of your classes while providing a controlled interface for interacting with object properties.
