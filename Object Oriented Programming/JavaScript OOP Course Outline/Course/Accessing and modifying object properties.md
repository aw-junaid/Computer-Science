### **Creating Objects Using Object Literals**

An **object literal** is the simplest and most common way to create objects in JavaScript. It involves defining an object by directly specifying its properties and methods within curly braces `{}`.

---

### **Syntax**
```javascript
const objectName = {
  key1: value1,
  key2: value2,
  // method
  key3: function () {
    // code
  },
};
```

---

### **Example: Basic Object Literal**
```javascript
const person = {
  name: 'Alice',
  age: 25,
  isStudent: false,
  greet: function () {
    console.log(`Hello, my name is ${this.name}.`);
  },
};

console.log(person.name); // Alice
console.log(person.age); // 25
person.greet(); // Hello, my name is Alice.
```

---

### **Features of Object Literals**

#### 1. **Defining Properties**
Properties are defined as key-value pairs:
- Keys are strings or symbols.
- Values can be any valid JavaScript data type (string, number, boolean, function, array, another object, etc.).

#### Example:
```javascript
const car = {
  brand: 'Toyota',       // String
  model: 2021,           // Number
  isElectric: false,     // Boolean
  features: ['Airbags', 'GPS'], // Array
  owner: {               // Nested object
    name: 'John',
    age: 30,
  },
};
console.log(car.features[1]); // GPS
console.log(car.owner.name);  // John
```

---

#### 2. **Defining Methods**
You can define functions as object properties (referred to as methods).

##### Example:
```javascript
const calculator = {
  add: function (a, b) {
    return a + b;
  },
  subtract: function (a, b) {
    return a - b;
  },
};

console.log(calculator.add(5, 3));      // 8
console.log(calculator.subtract(10, 4)); // 6
```

---

#### 3. **Shorthand Syntax (ES6)**
If the key and the value have the same name, you can use the shorthand syntax.

##### Example:
```javascript
const name = 'Alice';
const age = 25;

const person = {
  name, // Equivalent to name: name
  age,  // Equivalent to age: age
};

console.log(person); // { name: 'Alice', age: 25 }
```

---

#### 4. **Computed Property Names (ES6)**
You can dynamically set property names using square brackets `[]`.

##### Example:
```javascript
const property = 'age';

const person = {
  name: 'Alice',
  [property]: 25, // The key will be "age"
};

console.log(person.age); // 25
```

---

#### 5. **Concise Methods (ES6)**
You can define methods without the `function` keyword.

##### Example:
```javascript
const person = {
  name: 'Alice',
  greet() { // Concise method syntax
    console.log(`Hello, my name is ${this.name}.`);
  },
};

person.greet(); // Hello, my name is Alice.
```

---

### **Advantages of Object Literals**

1. **Simplicity:** Easy to create and use without needing constructors or classes.
2. **Readability:** Clear and concise syntax.
3. **Flexibility:** Allows properties and methods of various types, including nested objects.
4. **Dynamic Keys:** Supports computed property names for flexibility in property naming.

---

### **Limitations of Object Literals**

1. **Shared Structure:** No template for multiple objects with the same structure. You must manually create each object.
   - Solution: Use **constructor functions** or **classes** for reusable structures.
2. **No Inheritance:** Object literals do not inherently support inheritance.
   - Solution: Use prototypes or `Object.create()` for inheritance.

---

### **Practical Example**
#### Example: Creating a Product Object
```javascript
const product = {
  id: 101,
  name: 'Laptop',
  price: 1500,
  inStock: true,
  details: function () {
    console.log(`Product: ${this.name}, Price: $${this.price}`);
  },
};

product.details(); // Product: Laptop, Price: $1500
```

---
