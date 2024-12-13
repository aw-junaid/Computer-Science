### TypeScript - Accessors

In TypeScript, **accessors** are special methods used to get or set the value of an object's properties. They allow you to define custom behavior for getting (`get`) or setting (`set`) a property, rather than directly accessing or modifying the property.

Accessors in TypeScript are defined using the `get` and `set` keywords. These are often used for encapsulation, validation, or computed properties, ensuring better control over how properties are accessed and mutated.

### **1. Getters (get)**

A **getter** is a method that retrieves the value of a property. You can use it to return the value of a property while hiding the underlying logic or data.

#### **Syntax:**

```typescript
class ClassName {
  private _property: type;

  get property(): type {
    return this._property;
  }
}
```

- The `get` method allows you to retrieve the value of a property using `object.property`, without explicitly calling a method.

#### **Example: Getter**

```typescript
class Circle {
  private _radius: number;

  constructor(radius: number) {
    this._radius = radius;
  }

  get radius(): number {
    return this._radius;
  }

  get area(): number {
    return Math.PI * this._radius * this._radius;
  }
}

const circle = new Circle(5);
console.log(circle.radius);   // Output: 5 (accessing the getter)
console.log(circle.area);     // Output: 78.53981633974483 (calculated area via getter)
```

- **Explanation**:
  - `radius` is a getter, allowing you to access the `_radius` property using `circle.radius` instead of directly accessing `_radius`.
  - `area` is a getter that calculates the area of the circle based on the radius.

---

### **2. Setters (set)**

A **setter** is a method that sets the value of a property. Setters are useful for validating or transforming data before it's assigned to a property.

#### **Syntax:**

```typescript
class ClassName {
  private _property: type;

  set property(value: type) {
    this._property = value;
  }
}
```

- The `set` method allows you to assign a value to a property using `object.property = value`, even though the property is private or protected.

#### **Example: Setter**

```typescript
class Rectangle {
  private _length: number;
  private _width: number;

  constructor(length: number, width: number) {
    this._length = length;
    this._width = width;
  }

  get length(): number {
    return this._length;
  }

  set length(value: number) {
    if (value <= 0) {
      console.log("Length must be positive");
    } else {
      this._length = value;
    }
  }

  get width(): number {
    return this._width;
  }

  set width(value: number) {
    if (value <= 0) {
      console.log("Width must be positive");
    } else {
      this._width = value;
    }
  }

  get area(): number {
    return this._length * this._width;
  }
}

const rectangle = new Rectangle(10, 5);
console.log(rectangle.area);  // Output: 50

rectangle.length = -5;        // Output: Length must be positive
rectangle.width = 8;          // Width is updated

console.log(rectangle.area);  // Output: 40 (updated area)
```

- **Explanation**:
  - `length` and `width` have setter methods that validate the values before assigning them to `_length` and `_width`.
  - If invalid values are provided (like negative numbers), the setters log an error message and do not update the property.

---

### **3. Accessors in Action (Combining get and set)**

Accessors are often used in combination, where both the getter and setter are implemented for the same property. This allows for controlled access to the property and validation of input values.

#### **Example: Using Both Getter and Setter**

```typescript
class Employee {
  private _name: string;

  constructor(name: string) {
    this._name = name;
  }

  get name(): string {
    return this._name;
  }

  set name(value: string) {
    if (value.length < 3) {
      console.log("Name must be at least 3 characters long.");
    } else {
      this._name = value;
    }
  }
}

const employee = new Employee("John");
console.log(employee.name);  // Output: John

employee.name = "Al";        // Output: Name must be at least 3 characters long.
employee.name = "Alice";     // Name is updated
console.log(employee.name);  // Output: Alice
```

- **Explanation**:
  - The `name` property has both a getter and a setter. The getter retrieves the `_name` value, while the setter ensures that the name is at least 3 characters long before updating the `_name` property.

---

### **4. Computed Properties Using Accessors**

In addition to using accessors for getting and setting values, they can be used to create computed properties that dynamically calculate values based on other properties in the class.

#### **Example: Computed Property Using Getter**

```typescript
class Circle {
  constructor(private _radius: number) {}

  get radius(): number {
    return this._radius;
  }

  set radius(value: number) {
    if (value < 0) {
      console.log("Radius must be positive.");
    } else {
      this._radius = value;
    }
  }

  get circumference(): number {
    return 2 * Math.PI * this._radius;
  }
}

const circle = new Circle(10);
console.log(circle.circumference);  // Output: 62.83185307179586 (calculated circumference)
```

- **Explanation**:
  - The `circumference` property is a computed property that calculates the circumference based on the radius. It is accessed like a regular property (`circle.circumference`), but its value is dynamically calculated.

---

### **5. Private and Public Accessors**

While accessors can be used to provide controlled access to private or protected properties, they can also be used with public properties for additional logic.

#### **Example: Using Accessors with Public Properties**

```typescript
class Temperature {
  private _celsius: number;

  constructor(celsius: number) {
    this._celsius = celsius;
  }

  get celsius(): number {
    return this._celsius;
  }

  set celsius(value: number) {
    if (value < -273.15) {
      console.log("Temperature cannot be below absolute zero.");
    } else {
      this._celsius = value;
    }
  }

  get fahrenheit(): number {
    return (this._celsius * 9/5) + 32;
  }
}

const temp = new Temperature(25);
console.log(temp.fahrenheit);  // Output: 77 (calculated Fahrenheit)

temp.celsius = -300;           // Output: Temperature cannot be below absolute zero.
console.log(temp.celsius);     // Output: 25 (value is not updated)
```

- **Explanation**:
  - The `Temperature` class uses both getter and setter for `celsius` to ensure that the temperature is not below absolute zero.
  - The `fahrenheit` property is computed based on the `celsius` value.

---

### **6. Key Points about Accessors**

| **Feature**              | **Description**                                                            |
|--------------------------|----------------------------------------------------------------------------|
| **Getter (`get`)**        | Defines how to get a property value, typically used for computed or protected data. |
| **Setter (`set`)**        | Defines how to set a property value, often used for validation before updating a property. |
| **Encapsulation**         | Accessors help encapsulate logic for property access and mutation.        |
| **Custom Logic**          | Getters and setters allow for custom logic (e.g., validation, computation) when accessing or modifying properties. |
| **Private/Protected Use** | Getters and setters allow for access to private or protected properties from outside the class. |

---

### **Conclusion**

Accessors in TypeScript (via `get` and `set`) provide a mechanism for controlling the access to object properties. They allow you to implement additional logic when getting or setting a property, such as validation, transformation, or calculated values. Accessors promote encapsulation and help you create robust, maintainable code by controlling how data is accessed and mutated.
