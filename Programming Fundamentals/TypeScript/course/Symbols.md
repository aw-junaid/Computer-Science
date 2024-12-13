### TypeScript - Symbols

In TypeScript (and JavaScript), **Symbols** are a primitive data type that represents a unique and immutable value. They are often used as identifiers for object properties, ensuring that property names are unique and preventing name collisions. A symbol is guaranteed to be unique, even if it has the same description.

Symbols were introduced in ECMAScript 2015 (ES6), and TypeScript fully supports them. They provide a way to create unique keys for object properties that won't clash with other keys, even if they share the same description.

---

### 1. **Creating a Symbol**

You can create a symbol using the `Symbol` function. Optionally, you can provide a description (label) to the symbol to help with debugging, but the description doesn't affect the uniqueness of the symbol.

#### Example: Creating a Symbol

```typescript
let sym1 = Symbol();
let sym2 = Symbol();

console.log(sym1 === sym2); // Output: false, symbols are unique
```

- Even though `sym1` and `sym2` are created without descriptions, they are still unique and not equal to each other.

---

### 2. **Symbol with Description**

While symbols are unique, you can also provide an optional **description** for easier debugging.

#### Example: Symbol with Description

```typescript
let sym1 = Symbol("description1");
let sym2 = Symbol("description1");

console.log(sym1 === sym2); // Output: false, they are still different symbols
```

- The description `description1` is for debugging purposes and does not make the symbols equal.

---

### 3. **Symbols as Object Property Keys**

Symbols are often used as unique keys for object properties. This ensures that the properties won't clash with other property names, even if the same string is used for the name.

#### Example: Using Symbols as Object Keys

```typescript
let sym = Symbol("uniqueKey");

let obj = {
  [sym]: "Hello, world!"
};

console.log(obj[sym]);  // Output: "Hello, world!"
```

- In this case, `sym` is used as a unique property key in the `obj` object. You can retrieve the value using the symbol itself.

---

### 4. **Global Symbols**

You can create global symbols using the `Symbol.for()` method. This method looks for a symbol with the given key in a global registry and returns it if found. If the symbol doesn't exist, it creates a new one with the specified key.

#### Example: Global Symbol

```typescript
let globalSym1 = Symbol.for("globalKey");
let globalSym2 = Symbol.for("globalKey");

console.log(globalSym1 === globalSym2); // Output: true, both refer to the same global symbol
```

- `Symbol.for("globalKey")` allows you to create a symbol that is shared across different parts of the code or even across different sessions in the same environment (e.g., across different scripts in the same browser).

---

### 5. **Well-Known Symbols**

TypeScript (and JavaScript) includes a set of built-in **well-known symbols** that are used by internal JavaScript operations. These symbols have specific roles and are typically used for custom behavior for objects.

#### Example: Well-Known Symbols

Some of the most common well-known symbols are:

- `Symbol.iterator`: Defines the default iterator for an object.
- `Symbol.asyncIterator`: Defines the default asynchronous iterator.
- `Symbol.hasInstance`: Customizes the behavior of the `instanceof` operator.
- `Symbol.toPrimitive`: Defines how an object is converted to a primitive value.

##### Example: Using `Symbol.iterator`

```typescript
let obj = {
  [Symbol.iterator]: function () {
    let i = 0;
    let data = [10, 20, 30];
    return {
      next: function () {
        if (i < data.length) {
          return { value: data[i++], done: false };
        } else {
          return { done: true };
        }
      }
    };
  }
};

for (let value of obj) {
  console.log(value); // Output: 10, 20, 30
}
```

- In this example, `Symbol.iterator` is used to define a custom iterator for the `obj` object, enabling it to be iterated over in a `for...of` loop.

##### Example: Using `Symbol.hasInstance`

```typescript
class MyClass {
  static [Symbol.hasInstance](instance: any) {
    return instance instanceof MyClass || instance.someProperty === "special";
  }
}

let obj = { someProperty: "special" };

console.log(obj instanceof MyClass); // Output: true
```

- The `Symbol.hasInstance` symbol allows you to customize the behavior of the `instanceof` operator. In this case, we define that an object can be considered an instance of `MyClass` if it has a specific property (`someProperty`).

---

### 6. **Symbols and Object Property Enumeration**

By default, symbols are not included in `for...in` loops or `Object.keys()`/`Object.getOwnPropertyNames()` methods, which are used to enumerate object properties. However, they can be retrieved using `Object.getOwnPropertySymbols()`.

#### Example: Accessing Symbol Properties

```typescript
let sym1 = Symbol("property1");
let sym2 = Symbol("property2");

let obj = {
  [sym1]: "value1",
  [sym2]: "value2"
};

console.log(Object.getOwnPropertySymbols(obj));  // Output: [Symbol(property1), Symbol(property2)]
console.log(Object.getOwnPropertyNames(obj));    // Output: []
```

- `Object.getOwnPropertySymbols()` returns an array of symbols that are used as property keys on an object, while `Object.getOwnPropertyNames()` does not include symbols.

---

### 7. **Symbols and Privacy**

Symbols can be used to simulate **privacy** for object properties. Since symbols are unique, they make it hard to accidentally access or modify private properties of an object, offering a form of encapsulation.

#### Example: Simulating Privacy with Symbols

```typescript
const privateProp = Symbol("private");

class MyClass {
  [privateProp] = "I am private";

  getPrivateProp() {
    return this[privateProp];
  }
}

let obj = new MyClass();
console.log(obj.getPrivateProp()); // Output: "I am private"
console.log(obj[privateProp]);     // Error: Property 'Symbol(private)' is private and only accessible within class 'MyClass'.
```

- Here, the `privateProp` symbol is used to define a private-like property that cannot be accessed directly from outside the class, providing a form of data encapsulation.

---

### 8. **Advantages of Using Symbols**

- **Uniqueness**: Symbols are always unique, which is useful when you need unique object property keys or identifiers.
- **Avoid Name Collisions**: By using symbols, you can avoid property name collisions in objects, especially in large codebases or libraries.
- **Privacy**: Symbols can be used to simulate privacy for object properties, making it harder for external code to accidentally access or modify private data.
- **Custom Behavior**: Well-known symbols allow you to customize built-in JavaScript behavior (e.g., iteration, instance checking) for your objects.

---

### 9. **Summary**

- **Creating Symbols**: You can create symbols using the `Symbol()` function. They are always unique, even if they have the same description.
- **Symbol Descriptions**: Descriptions are for debugging purposes and do not affect the uniqueness of symbols.
- **Symbols as Object Keys**: Symbols are often used as object property keys to avoid name collisions.
- **Global Symbols**: You can create shared symbols using `Symbol.for()` and access them globally.
- **Well-Known Symbols**: TypeScript provides a set of built-in symbols like `Symbol.iterator`, `Symbol.asyncIterator`, and `Symbol.hasInstance` for customizing behavior.
- **Symbols and Privacy**: Symbols can help simulate private properties in objects, improving encapsulation.

Symbols provide a unique and powerful tool for managing object properties and customizing JavaScript behavior in TypeScript, making them an important feature in more advanced object-oriented and functional programming patterns.
