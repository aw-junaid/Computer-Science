### **Encapsulation in JavaScript Classes**

**Encapsulation** is one of the core principles of object-oriented programming (OOP). It refers to the concept of **bundling** the data (properties) and the methods that operate on the data into a single unit or class, and restricting access to certain components of the object to ensure the integrity of its state.

Encapsulation typically involves:
1. **Private properties and methods**: Properties that are not directly accessible outside the class.
2. **Public methods**: Methods that provide controlled access to the private properties.

In JavaScript, **encapsulation** is achieved using:
- **Private fields** (using `#` syntax, introduced in ES2022)
- **Getters and setters** for controlled access to properties.

---

### **1. Working with Properties**

#### **Public Properties**

By default, properties in a JavaScript class are public. This means they can be accessed directly from outside the class, like so:

#### **Example: Public Properties**
```javascript
class Car {
  constructor(make, model) {
    this.make = make; // Public property
    this.model = model; // Public property
  }

  displayInfo() {
    console.log(`${this.make} ${this.model}`);
  }
}

const myCar = new Car('Toyota', 'Corolla');
console.log(myCar.make);  // Toyota
console.log(myCar.model); // Corolla
```

- In the example, `make` and `model` are public properties and can be accessed directly from the instance `myCar`.

---

### **2. Private Properties (Using `#` Syntax)**

JavaScript (since ES2022) allows you to define **private fields** within classes using the `#` syntax. Private properties cannot be accessed directly from outside the class and are only available to methods inside the class.

#### **Example: Private Properties**
```javascript
class BankAccount {
  #balance; // Private property

  constructor(owner, balance) {
    this.owner = owner;
    this.#balance = balance; // Private field initialized in the constructor
  }

  getBalance() {
    return this.#balance; // Public method to access private field
  }

  deposit(amount) {
    if (amount > 0) {
      this.#balance += amount; // Modify private field
    }
  }

  withdraw(amount) {
    if (amount <= this.#balance && amount > 0) {
      this.#balance -= amount; // Modify private field
    } else {
      console.log('Insufficient funds or invalid amount.');
    }
  }
}

const account = new BankAccount('John Doe', 1000);
console.log(account.getBalance()); // 1000
account.deposit(500);
console.log(account.getBalance()); // 1500
account.withdraw(200);
console.log(account.getBalance()); // 1300

// Trying to access private field directly (will throw an error)
console.log(account.#balance);  // SyntaxError: Private field '#balance' must be declared in an enclosing class
```

- **Private fields** are marked with a `#` and can only be accessed within the class using `this.#propertyName`.
- Attempting to access a private field directly from outside the class results in a syntax error.

---

### **3. Using Getters and Setters for Controlled Access**

Instead of exposing the internal properties directly, you can use **getters** and **setters** to control how properties are accessed or modified. This allows for more controlled access to the object’s internal state.

#### **Example: Getters and Setters**
```javascript
class Person {
  constructor(name, age) {
    this.name = name;
    this._age = age; // Conventionally treating `_age` as private (not enforced)
  }

  // Getter method
  get age() {
    return this._age;
  }

  // Setter method
  set age(newAge) {
    if (newAge > 0) {
      this._age = newAge;
    } else {
      console.log('Age must be positive.');
    }
  }

  greet() {
    console.log(`Hello, my name is ${this.name} and I am ${this._age} years old.`);
  }
}

const person = new Person('Alice', 30);
console.log(person.age);  // 30 (accessing through getter)
person.age = 35;          // Using setter
console.log(person.age);  // 35 (updated value)
person.age = -5;          // Age must be positive.
console.log(person.age);  // 35 (age remains unchanged)
```

- **Getter (`get`)**: The `age` getter allows you to access the internal `_age` property in a controlled way. The getter is used like a property, so `person.age` will call the getter method.
- **Setter (`set`)**: The `age` setter allows you to modify the internal `_age` property, but you can add logic to ensure only valid values are set.

---

### **4. Getter and Setter for Private Fields (Private Fields + Access Control)**

If you use private fields and want to provide controlled access to them, you can define getter and setter methods for private properties as well.

#### **Example: Private Fields with Getters and Setters**
```javascript
class Employee {
  #salary; // Private property

  constructor(name, salary) {
    this.name = name;
    this.#salary = salary;
  }

  // Getter for private salary
  get salary() {
    return this.#salary;
  }

  // Setter for private salary
  set salary(value) {
    if (value > 0) {
      this.#salary = value;
    } else {
      console.log('Salary must be positive.');
    }
  }

  displayInfo() {
    console.log(`${this.name} earns $${this.#salary} per year.`);
  }
}

const employee = new Employee('John', 50000);
employee.displayInfo();  // John earns $50000 per year.
console.log(employee.salary);  // 50000 (using getter)
employee.salary = 60000;       // Using setter
console.log(employee.salary);  // 60000 (updated value)
employee.salary = -1000;       // Salary must be positive.
```

- **Private fields** are used in the class, and access is controlled via **getters and setters**.

---

### **5. Benefits of Encapsulation**

Encapsulation provides several benefits:
1. **Data Protection:** You can protect object properties from being modified directly, ensuring the integrity of the object.
2. **Controlled Access:** Using getters and setters, you can add validation logic and control how data is accessed and modified.
3. **Abstraction:** Encapsulation allows you to abstract the internal implementation details of an object, exposing only necessary functionality to the outside world.
4. **Maintainability:** If you change the internal implementation of an object, the external interface (getter/setter methods) can remain the same, making the code easier to maintain.

---

### **Summary**

- **Public Properties:** These properties can be accessed and modified directly from outside the class.
- **Private Properties:** These are inaccessible from outside the class and are only used within the class.
- **Getters and Setters:** These provide controlled access to private properties, allowing you to define logic for retrieving or modifying data.
- **Private Fields (Using `#`):** With ES2022, JavaScript supports true private fields that cannot be accessed outside the class.

Encapsulation helps in keeping the internal state of an object safe and ensures that it can only be modified in controlled ways. It is one of the foundational principles that help create robust and maintainable OOP designs in JavaScript.
