### TypeScript - Arrays

Arrays in TypeScript are used to store multiple values in a single variable. They can hold values of any type, including primitive types, objects, and other arrays. TypeScript adds type safety to arrays, which means you can specify what types of elements an array can contain.

---

### 1. **Declaring Arrays**

There are several ways to declare arrays in TypeScript. You can either use the `Array<type>` syntax or the shorthand `type[]` notation.

#### Example: Array Declarations

```typescript
let numbers: number[] = [1, 2, 3, 4];      // Array of numbers
let strings: Array<string> = ["apple", "banana"];  // Array of strings
let mixed: (string | number)[] = [1, "two", 3, "four"];  // Array of mixed types
```

- **`numbers`** is an array of type `number[]` (only numbers).
- **`strings`** is an array of type `Array<string>` (only strings).
- **`mixed`** is an array that can contain either strings or numbers.

You can also specify multidimensional arrays or arrays of arrays.

#### Example: Multidimensional Arrays

```typescript
let matrix: number[][] = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
];
```

- **`matrix`** is a 2D array where each element is an array of numbers.

---

### 2. **Array Methods**

TypeScript supports all the standard JavaScript array methods. Here are some commonly used ones:

#### Example: Array Methods

```typescript
let fruits: string[] = ["apple", "banana", "cherry"];

// Push (Add an element to the end)
fruits.push("orange");  // ["apple", "banana", "cherry", "orange"]

// Pop (Remove the last element)
let lastFruit = fruits.pop();  // "orange", fruits = ["apple", "banana", "cherry"]

// Shift (Remove the first element)
let firstFruit = fruits.shift();  // "apple", fruits = ["banana", "cherry"]

// Unshift (Add an element to the beginning)
fruits.unshift("grape");  // ["grape", "banana", "cherry"]

// Find the index of an element
let index = fruits.indexOf("banana");  // 1

// Slice (Extract a portion of the array)
let slicedFruits = fruits.slice(1, 3);  // ["banana", "cherry"]

// Splice (Add or remove elements from an array)
fruits.splice(1, 1, "blueberry");  // Removes "banana", adds "blueberry"; fruits = ["grape", "blueberry", "cherry"]
```

- **`push()`** adds an element to the end of the array.
- **`pop()`** removes the last element from the array.
- **`shift()`** removes the first element from the array.
- **`unshift()`** adds an element to the beginning of the array.
- **`indexOf()`** finds the index of an element.
- **`slice()`** returns a shallow copy of a portion of the array.
- **`splice()`** modifies the array by adding/removing elements.

---

### 3. **Accessing and Modifying Arrays**

You can access and modify array elements using zero-based indexing.

#### Example: Accessing and Modifying Elements

```typescript
let colors: string[] = ["red", "green", "blue"];

// Access elements
let firstColor = colors[0];  // "red"
let lastColor = colors[colors.length - 1];  // "blue"

// Modify elements
colors[1] = "yellow";  // ["red", "yellow", "blue"]
```

- **Indexing** starts from `0`, so `colors[0]` refers to the first element.
- **Modification** is done by directly assigning a new value to the desired index.

---

### 4. **Iterating Over Arrays**

You can use several methods to iterate over arrays, such as `for`, `forEach()`, `map()`, `filter()`, and more.

#### Example: Iterating with `for` and `forEach()`

```typescript
let numbers: number[] = [1, 2, 3, 4];

// Using for loop
for (let i = 0; i < numbers.length; i++) {
    console.log(numbers[i]);  // Output: 1, 2, 3, 4
}

// Using forEach
numbers.forEach((num) => {
    console.log(num);  // Output: 1, 2, 3, 4
});
```

- **`for`** loop allows you to manually control the loop counter.
- **`forEach()`** iterates over each element in the array and executes a callback function for each.

#### Example: Using `map()` and `filter()`

```typescript
let numbers: number[] = [1, 2, 3, 4, 5];

// map() - Create a new array with transformed elements
let doubled = numbers.map((num) => num * 2);  // [2, 4, 6, 8, 10]

// filter() - Create a new array with elements that satisfy a condition
let evenNumbers = numbers.filter((num) => num % 2 === 0);  // [2, 4]
```

- **`map()`** creates a new array by applying a function to each element.
- **`filter()`** creates a new array with elements that pass a test.

---

### 5. **Array Type Annotations**

TypeScript allows you to specify the types of the elements in an array using type annotations. This adds type safety, ensuring only values of the specified type are allowed in the array.

#### Example: Array Type Annotations

```typescript
let numbers: number[] = [1, 2, 3, 4];      // Only numbers allowed
let strings: string[] = ["apple", "banana"];  // Only strings allowed
let mixed: (string | number)[] = [1, "two", 3]; // Mixed types allowed
```

- **`number[]`** ensures only numbers are added to the array.
- **`string[]`** ensures only strings are added.
- **`(string | number)[]`** allows both strings and numbers.

---

### 6. **Tuples (Arrays with Fixed Length and Types)**

In TypeScript, a **tuple** is an array with a fixed number of elements where each element can have a different type. Tuples are useful when you want to represent a collection of different values with a fixed length.

#### Example: Tuples

```typescript
let tuple: [string, number, boolean] = ["Alice", 25, true];  // Tuple with 3 elements

let name: string = tuple[0];  // "Alice"
let age: number = tuple[1];   // 25
let isActive: boolean = tuple[2];  // true
```

- The type `[string, number, boolean]` ensures the array has exactly three elements, with the first being a string, the second a number, and the third a boolean.
- You can access tuple elements using indices, similar to arrays, but their types are constrained.

---

### 7. **Readonly Arrays**

TypeScript also provides a `ReadonlyArray<T>` type that prevents modification of an array's contents. This is useful when you want to ensure that an array remains unchanged.

#### Example: Readonly Arrays

```typescript
let numbers: ReadonlyArray<number> = [1, 2, 3, 4];

// The following operations will result in errors:
numbers.push(5);       // Error: Property 'push' does not exist on type 'readonly number[]'
numbers[0] = 10;       // Error: Index signature in type 'readonly number[]' only permits reading
```

- **`ReadonlyArray<T>`** makes the array immutable, meaning you cannot modify its elements or structure.

---

### 8. **Array Destructuring**

You can use destructuring to extract values from an array into individual variables.

#### Example: Array Destructuring

```typescript
let arr: number[] = [1, 2, 3];

let [first, second, third] = arr;  // first = 1, second = 2, third = 3

console.log(first);  // 1
console.log(second); // 2
console.log(third);  // 3
```

- Destructuring allows you to assign values from an array directly to variables in a concise way.

---

### 9. **Multi-dimensional Arrays**

TypeScript supports arrays that contain other arrays, such as 2D, 3D arrays, etc.

#### Example: 2D Array

```typescript
let matrix: number[][] = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
];

let element = matrix[1][2];  // 6
```

- **`matrix[1][2]`** accesses the element in the second row and third column of the 2D array.

---

### Conclusion

Arrays in TypeScript offer a rich set of features, including type safety, flexible declaration styles, built-in methods, and powerful iteration tools. You can use arrays to store multiple values of the same or mixed types, as well as utilize features like tuple

 types, readonly arrays, and array destructuring to enhance your code's safety and clarity.
