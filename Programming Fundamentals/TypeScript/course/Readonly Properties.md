### TypeScript - Readonly Properties

In TypeScript, **readonly** properties are used to create class members (properties) that can only be assigned a value once, either during the initialization or in the constructor, but cannot be modified afterward. This helps to create immutable data and ensures that certain properties remain constant throughout the object's lifecycle.

### **1. Readonly in Classes**

When you declare a property with the `readonly` modifier, it ensures that the property cannot be reassigned after its initial value has been set. This can be useful for things like constants or values that should not change after the object is created.

#### **Syntax:**

```typescript
class ClassName {
  readonly property: type;

  constructor(value: type) {
    this.property = value;
  }
}
```

#### **Example 1: Readonly Property in a Class**

```typescript
class Car {
  readonly make: string;
  readonly model: string;

  constructor(make: string, model: string) {
    this.make = make;
    this.model = model;
  }

  displayDetails(): void {
    console.log(`Car Make: ${this.make}, Model: ${this.model}`);
  }
}

const myCar = new Car("Toyota", "Corolla");
console.log(myCar.make);  // Output: Toyota
myCar.make = "Honda";     // Error: Cannot assign to 'make' because it is a read-only property.
```

- **Explanation**:
  - The `make` and `model` properties are marked as `readonly`, so they can only be assigned a value once—during construction.
  - Trying to modify them later (e.g., `myCar.make = "Honda"`) results in a compile-time error.

---

### **2. Readonly Arrays**

You can also use the `readonly` modifier to create immutable arrays. The array itself cannot be modified, meaning no elements can be added, removed, or changed.

#### **Syntax:**

```typescript
let arrayName: readonly type[] = [value1, value2, ...];
```

#### **Example 2: Readonly Array**

```typescript
let numbers: readonly number[] = [1, 2, 3];
console.log(numbers[0]);  // Output: 1

numbers[1] = 10;  // Error: Index signature in type 'readonly number[]' only permits reading.
numbers.push(4);  // Error: Property 'push' does not exist on type 'readonly number[]'.
```

- **Explanation**:
  - The `numbers` array is marked as `readonly`, so it cannot be modified by reassigning elements or using array methods like `push`, `pop`, `shift`, etc.
  - The array can still be read (i.e., you can access the values), but it cannot be altered.

---

### **3. Readonly with Objects**

The `readonly` modifier can also be applied to individual properties of objects, preventing their modification after initialization. This can be useful for creating immutable objects.

#### **Syntax:**

```typescript
let obj: { readonly property: type } = {
  property: value,
};
```

#### **Example 3: Readonly Property in an Object**

```typescript
let product = {
  readonly id: number,
  name: string
};

product.id = 101;  // Error: Cannot assign to 'id' because it is a read-only property.
product.name = "Laptop";  // This works because 'name' is not readonly
```

- **Explanation**:
  - The `id` property is `readonly`, so it cannot be reassigned after its initial value is set.
  - The `name` property is not `readonly`, so it can still be changed.

---

### **4. Readonly with Type Aliases**

You can use the `readonly` modifier in type aliases to define the type of objects with immutable properties.

#### **Syntax:**

```typescript
type TypeName = {
  readonly property: type;
};
```

#### **Example 4: Readonly Type Alias**

```typescript
type Product = {
  readonly id: number;
  name: string;
};

const item: Product = { id: 1, name: "Phone" };
item.id = 2;  // Error: Cannot assign to 'id' because it is a read-only property.
item.name = "Smartphone";  // This works
```

- **Explanation**:
  - The `Product` type alias defines `id` as a `readonly` property, ensuring that it cannot be modified after initialization.
  - The `name` property is mutable.

---

### **5. Readonly in Interfaces**

In TypeScript, you can also use `readonly` with interfaces to define objects that cannot have certain properties modified after they are initialized.

#### **Syntax:**

```typescript
interface InterfaceName {
  readonly property: type;
}
```

#### **Example 5: Readonly in Interfaces**

```typescript
interface Point {
  readonly x: number;
  readonly y: number;
}

let point: Point = { x: 5, y: 10 };
point.x = 20;  // Error: Cannot assign to 'x' because it is a read-only property.
```

- **Explanation**:
  - The `Point` interface defines `x` and `y` as `readonly`, so they cannot be reassigned after the object is created.
  - Any attempt to modify these properties will result in a compile-time error.

---

### **6. Readonly Tuple**

You can also use `readonly` with tuples to ensure that the elements of a tuple cannot be changed after the tuple is created.

#### **Syntax:**

```typescript
let tuple: readonly [type1, type2, ...] = [value1, value2, ...];
```

#### **Example 6: Readonly Tuple**

```typescript
let tuple: readonly [string, number] = ["apple", 42];

tuple[0] = "banana";  // Error: Index signature in type 'readonly [string, number]' only permits reading.
tuple.push(100);       // Error: Property 'push' does not exist on type 'readonly [string, number]'.
```

- **Explanation**:
  - The `tuple` is a readonly tuple, meaning that the values cannot be modified, added, or removed.
  - Attempts to change any element or use methods like `push` will result in an error.

---

### **7. Using `Readonly` Utility Type**

TypeScript also provides the built-in `Readonly` utility type, which makes all properties of an object `readonly`. This is especially useful when you want to apply the `readonly` modifier to an entire object dynamically.

#### **Syntax:**

```typescript
type Readonly<Type> = {
  readonly [P in keyof Type]: Type[P];
};
```

#### **Example 7: Using the `Readonly` Utility Type**

```typescript
interface Car {
  make: string;
  model: string;
}

const myCar: Readonly<Car> = {
  make: "Tesla",
  model: "Model 3"
};

myCar.make = "BMW";  // Error: Cannot assign to 'make' because it is a read-only property.
```

- **Explanation**:
  - The `Readonly<Car>` utility type makes both `make` and `model` properties immutable.
  - You cannot modify any property of `myCar` after it is initialized.

---

### **Summary**

| **Concept**                | **Description**                                                                 |
|----------------------------|---------------------------------------------------------------------------------|
| **`readonly` in classes**   | Restricts modification of class properties after initialization.               |
| **`readonly` in arrays**    | Prevents modification of array elements and array methods (e.g., `push`).      |
| **`readonly` in objects**   | Makes individual properties of objects immutable after initialization.         |
| **`readonly` in type aliases** | Applies immutability to object types created with type aliases.           |
| **`readonly` in interfaces** | Ensures that properties in interfaces are immutable once assigned.           |
| **`readonly` with tuples**  | Prevents modification of tuple elements and array methods.                    |
| **`Readonly` Utility Type** | A TypeScript utility type that makes all properties of an object immutable.    |

---

### **Conclusion**

The `readonly` modifier in TypeScript is a powerful feature that helps to create immutable data structures. It can be applied to:
- Properties of a class or object
- Arrays, tuples, and their elements
- Types and interfaces to ensure immutability

By using `readonly`, you can safeguard your code from accidental changes to critical data and improve the integrity of your objects.
