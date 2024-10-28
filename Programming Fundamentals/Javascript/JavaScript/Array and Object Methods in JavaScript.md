Let's dive into some common array and object methods in JavaScript:

## Array Methods

JavaScript arrays have several built-in methods that make it easier to work with array data:

### Iteration Methods:

- **`forEach()`:**
  Executes a provided function once for each array element.

  ```javascript
  let numbers = [1, 2, 3, 4, 5];
  numbers.forEach(function(number) {
    console.log(number);
  });
  ```

- **`map()`:**
  Creates a new array by applying a function to each element of an existing array.

  ```javascript
  let squaredNumbers = numbers.map(function(number) {
    return number * number;
  });
  ```

### Filtering Methods:

- **`filter()`:**
  Creates a new array with elements that pass a test specified by a callback function.

  ```javascript
  let evenNumbers = numbers.filter(function(number) {
    return number % 2 === 0;
  });
  ```

### Reduction Methods:

- **`reduce()`:**
  Applies a function to each element of an array to reduce it to a single value.

  ```javascript
  let sum = numbers.reduce(function(accumulator, currentValue) {
    return accumulator + currentValue;
  }, 0);
  ```

### Searching and Sorting Methods:

- **`indexOf()` and `lastIndexOf()`:**
  Returns the index of the first/last occurrence of a specified element in an array.

  ```javascript
  let index = numbers.indexOf(3); // 2
  let lastIndex = numbers.lastIndexOf(3); // 2
  ```

- **`includes()`:**
  Determines whether an array includes a certain element.

  ```javascript
  let includesThree = numbers.includes(3); // true
  ```

- **`sort()`:**
  Sorts the elements of an array in place.

  ```javascript
  let sortedNumbers = numbers.sort(); // [1, 2, 3, 4, 5]
  ```

### Array Modification Methods:

- **`push()` and `pop()`:**
  Add/remove elements from the end of an array.

- **`unshift()` and `shift()`:**
  Add/remove elements from the beginning of an array.

- **`splice()`:**
  Add/remove elements from anywhere in an array.

## Object Methods

JavaScript objects also have useful built-in methods for object manipulation:

### Object.keys(), Object.values(), and Object.entries():

- **`Object.keys()`:**
  Returns an array of a given object's own enumerable property names.

- **`Object.values()`:**
  Returns an array of a given object's own enumerable property values.

- **`Object.entries()`:**
  Returns an array of a given object's own enumerable key-value pairs as arrays.

### Object.assign():

- **`Object.assign()`:**
  Copies the values of all enumerable own properties from one or more source objects to a target object.

  ```javascript
  let obj1 = { a: 1, b: 2 };
  let obj2 = { b: 3, c: 4 };
  let mergedObject = Object.assign({}, obj1, obj2);
  ```

### Object.keys().forEach():

You can combine `Object.keys()` with `forEach()` to iterate over an object's properties:

```javascript
Object.keys(obj).forEach(function(key) {
  console.log(key + ': ' + obj[key]);
});
```

These are just a few examples of the many methods available for working with arrays and objects in JavaScript. Each method serves a specific purpose, making it easier to manipulate and process data effectively.
