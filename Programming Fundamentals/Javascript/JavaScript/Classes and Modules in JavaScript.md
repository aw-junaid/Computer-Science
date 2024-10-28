Classes and modules are key features introduced in ECMAScript 6 (ES6) that enhance the structure and organization of JavaScript code, making it more maintainable and scalable. Let's delve into each of them in detail:

## Classes

Classes in JavaScript provide a way to define blueprints for creating objects with shared properties and methods. They follow a syntax similar to classes in other object-oriented programming languages.

### Class Declaration:

```javascript
class Person {
  constructor(name, age) {
    this.name = name;
    this.age = age;
  }

  greet() {
    console.log(`Hello, my name is ${this.name} and I am ${this.age} years old.`);
  }
}

const person1 = new Person('Alice', 30);
person1.greet(); // Output: 'Hello, my name is Alice and I am 30 years old.'
```

In the example above:
- `Person` is a class with a constructor for initializing properties (`name` and `age`) when objects are created.
- `greet()` is a method of the class that logs a greeting message.

### Class Inheritance:

Classes support inheritance, allowing you to create subclasses that inherit properties and methods from a parent class.

```javascript
class Student extends Person {
  constructor(name, age, grade) {
    super(name, age); // Call the parent class constructor
    this.grade = grade;
  }

  study() {
    console.log(`${this.name} is studying in grade ${this.grade}.`);
  }
}

const student1 = new Student('Bob', 12, '7th');
student1.greet(); // Output: 'Hello, my name is Bob and I am 12 years old.'
student1.study(); // Output: 'Bob is studying in grade 7th.'
```

Inheritance is achieved using the `extends` keyword, and `super` is used to call the constructor of the parent class.

## Modules

Modules in JavaScript allow you to organize code into separate files, making it easier to manage large codebases and promote code reusability.

### Exporting Modules:

```javascript
// person.js
export class Person {
  constructor(name, age) {
    this.name = name;
    this.age = age;
  }

  greet() {
    console.log(`Hello, my name is ${this.name} and I am ${this.age} years old.`);
  }
}
```

### Importing Modules:

```javascript
// main.js
import { Person } from './person.js';

const person1 = new Person('Alice', 30);
person1.greet(); // Output: 'Hello, my name is Alice and I am 30 years old.'
```

In the example above, `person.js` exports the `Person` class using the `export` keyword, and `main.js` imports it using the `import` statement.

### Default Exports:

You can also use default exports for modules that export a single value:

```javascript
// math.js
const PI = 3.14159;

export default PI;
```

```javascript
// main.js
import piValue from './math.js';

console.log(piValue); // Output: 3.14159
```

Default exports are imported without braces `{}` and can be given any name during import.

Classes and modules are essential features in modern JavaScript development, enabling developers to write more organized, maintainable, and scalable code. They are widely used in ES6+ and are fundamental for building complex applications.
