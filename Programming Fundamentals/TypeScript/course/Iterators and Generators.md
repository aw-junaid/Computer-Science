### TypeScript - Iterators and Generators

Iterators and generators in TypeScript are tools that allow controlled iteration over collections of data or custom sequences. They are based on ECMAScript (JavaScript) specifications and provide a way to produce data on demand rather than all at once.

---

### **1. Iterators**

An **iterator** is an object that enables traversal over a collection (e.g., arrays, maps, sets). It must implement the `Iterator` interface, which includes a `next()` method.

#### **a. Iterator Interface**
The `Iterator` interface defines the structure for iterators in TypeScript:

```typescript
interface Iterator<T> {
  next(value?: any): IteratorResult<T>;
}

interface IteratorResult<T> {
  value: T;
  done: boolean;
}
```

- **`next()`**: Returns an `IteratorResult`.
- **`value`**: The current value.
- **`done`**: Indicates if the iteration is complete (`true`) or not (`false`).

---

#### **b. Example: Custom Iterator**

```typescript
class Counter implements Iterator<number> {
  private current: number = 0;
  private max: number;

  constructor(max: number) {
    this.max = max;
  }

  next(): IteratorResult<number> {
    if (this.current < this.max) {
      return { value: this.current++, done: false };
    } else {
      return { value: null, done: true };
    }
  }
}

const counter = new Counter(5);
console.log(counter.next()); // { value: 0, done: false }
console.log(counter.next()); // { value: 1, done: false }
console.log(counter.next()); // { value: 2, done: false }
console.log(counter.next()); // { value: null, done: true }
```

---

### **2. Iterable**

An **iterable** is an object that implements the `Iterable` interface and defines a method for retrieving its iterator. This allows it to be used in constructs like `for...of` loops.

#### **a. Iterable Interface**
The `Iterable` interface is defined as:

```typescript
interface Iterable<T> {
  [Symbol.iterator](): Iterator<T>;
}
```

---

#### **b. Example: Custom Iterable**

```typescript
class NumberRange implements Iterable<number> {
  private start: number;
  private end: number;

  constructor(start: number, end: number) {
    this.start = start;
    this.end = end;
  }

  [Symbol.iterator](): Iterator<number> {
    let current = this.start;
    let end = this.end;

    return {
      next(): IteratorResult<number> {
        if (current <= end) {
          return { value: current++, done: false };
        } else {
          return { value: null, done: true };
        }
      },
    };
  }
}

const range = new NumberRange(1, 5);
for (const num of range) {
  console.log(num); // Outputs: 1, 2, 3, 4, 5
}
```

---

### **3. Generators**

A **generator** is a special type of function that can be paused and resumed, enabling lazy evaluation. It is defined using the `function*` syntax.

#### **a. Generator Function Syntax**

- Use `function*` to declare a generator.
- Use the `yield` keyword to pause the function and return a value.

```typescript
function* generatorExample() {
  yield 1;
  yield 2;
  yield 3;
}

const gen = generatorExample();
console.log(gen.next()); // { value: 1, done: false }
console.log(gen.next()); // { value: 2, done: false }
console.log(gen.next()); // { value: 3, done: false }
console.log(gen.next()); // { value: undefined, done: true }
```

---

#### **b. Iterating Over a Generator**

Generators are automatically iterable, so they can be used with `for...of` loops.

```typescript
function* numbers() {
  yield 1;
  yield 2;
  yield 3;
}

for (const num of numbers()) {
  console.log(num); // Outputs: 1, 2, 3
}
```

---

### **4. Generator with Parameters and Return Values**

#### **a. Passing Parameters to Generators**
You can pass values back to the generator using the `next()` method.

```typescript
function* counter() {
  let count = 0;
  while (true) {
    const increment = yield count;
    count += increment || 1; // Default increment is 1
  }
}

const gen = counter();
console.log(gen.next()); // { value: 0, done: false }
console.log(gen.next(5)); // { value: 5, done: false }
console.log(gen.next(2)); // { value: 7, done: false }
```

#### **b. Returning a Value from a Generator**
A generator can use `return` to provide a final value.

```typescript
function* finiteCounter(limit: number) {
  for (let i = 0; i < limit; i++) {
    yield i;
  }
  return "Done!";
}

const gen = finiteCounter(3);
console.log(gen.next()); // { value: 0, done: false }
console.log(gen.next()); // { value: 1, done: false }
console.log(gen.next()); // { value: 2, done: false }
console.log(gen.next()); // { value: "Done!", done: true }
```

---

### **5. Async Generators**

An **async generator** can be used to handle asynchronous operations and data streams.

#### **a. Async Generator Syntax**
Use `async function*` to define an asynchronous generator.

```typescript
async function* asyncGenerator() {
  for (let i = 1; i <= 3; i++) {
    await new Promise((resolve) => setTimeout(resolve, 1000)); // Simulate async delay
    yield i;
  }
}

(async () => {
  for await (const num of asyncGenerator()) {
    console.log(num); // Outputs: 1, 2, 3 (with 1-second intervals)
  }
})();
```

---

### **6. Comparison: Iterator vs. Generator**

| Feature         | Iterator                                     | Generator                                      |
|------------------|----------------------------------------------|-----------------------------------------------|
| Declaration      | Implements `Iterator` interface manually    | Uses `function*` and `yield` syntax           |
| Laziness         | Requires custom implementation              | Built-in lazy evaluation                      |
| Complexity       | Requires more boilerplate code              | Simpler and more concise                      |
| Iterability      | Requires implementation of `[Symbol.iterator]` | Automatically iterable                        |

---

### **7. Use Cases**

- **Iterators:**
  - When you need fine-grained control over iteration logic.
  - For implementing custom data structures (e.g., linked lists, trees).
  
- **Generators:**
  - For creating infinite sequences (e.g., Fibonacci numbers).
  - For handling lazy evaluation or large data streams.
  - Asynchronous data processing using `async generators`.

---

### **8. Summary**

- **Iterators** provide a manual way to define iteration over a collection or sequence.
- **Generators** simplify the process with `yield` and allow pausing and resuming execution.
- Generators are often preferred for their simplicity and built-in iterability.
- Both tools play a crucial role in handling complex iteration scenarios in TypeScript.

Understanding iterators and generators equips you with powerful tools for creating custom, efficient, and maintainable data traversal mechanisms.
