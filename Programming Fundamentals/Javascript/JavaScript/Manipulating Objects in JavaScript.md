Manipulating objects in JavaScript involves working with key-value pairs and accessing or modifying their properties. Here's a guide to common operations with JavaScript objects:

## Creating Objects

You can create objects in JavaScript using object literal notation `{}`:

```javascript
let person = {
  name: 'John',
  age: 30,
  city: 'New York'
};
```

You can also create objects using the `new Object()` syntax or by defining object constructors and classes (for more complex scenarios).

## Accessing Object Properties

You can access object properties using dot notation (`object.property`) or bracket notation (`object['property']`):

```javascript
console.log(person.name); // Output: 'John'
console.log(person['age']); // Output: 30
```

Bracket notation is useful when the property name is dynamic or contains special characters.

## Modifying Object Properties

You can modify object properties by assigning new values:

```javascript
person.age = 35;
person['city'] = 'San Francisco';
```

## Adding and Removing Object Properties

You can add new properties to an object by simply assigning a value to a new key:

```javascript
person.job = 'Software Engineer';
```

To remove a property from an object, you can use the `delete` keyword:

```javascript
delete person.city;
```

## Checking if a Property Exists

You can check if an object has a specific property using the `in` operator or the `hasOwnProperty()` method:

```javascript
console.log('age' in person); // Output: true
console.log(person.hasOwnProperty('job')); // Output: true
```

## Looping Through Object Properties

You can iterate over an object's properties using `for...in` loop:

```javascript
for (let key in person) {
  console.log(key + ': ' + person[key]);
}
```

## Object Methods

Objects in JavaScript can also have methods, which are functions attached to object properties:

```javascript
let car = {
  brand: 'Toyota',
  model: 'Camry',
  start: function() {
    console.log('Engine started');
  }
};

car.start(); // Output: 'Engine started'
```

## Object Destructuring

ES6 introduced object destructuring, allowing you to extract object properties into variables:

```javascript
let { name, age } = person;
console.log(name); // Output: 'John'
console.log(age); // Output: 35
```

This extracts the `name` and `age` properties from the `person` object into separate variables.

JavaScript objects are versatile and can represent complex data structures. Understanding how to manipulate objects effectively is essential for building robust applications.
