### TypeScript - Type Compatibility

Type compatibility in TypeScript determines whether one type can be assigned to another. It is based on a structural type system, where compatibility is determined by the shape or structure of the types rather than their names.

---

### **1. Structural Type System**

In a structural type system, two types are compatible if they have the same structure. This means that as long as an object or type satisfies the required shape, it is considered compatible.

---

### **2. Assignability Rules**

TypeScript uses the following rules to check compatibility:

- **A value of one type can be assigned to another type if it has the same or a superset of required properties.**
- The target type must include all the properties of the source type.

---

### **3. Basic Type Compatibility**

#### **a. Primitive Types**
Compatible types can be assigned to each other.

```typescript
let num: number = 10;
let str: string = "Hello";

num = 20; // Valid
// num = "Hello"; // Error: Type 'string' is not assignable to type 'number'.
```

#### **b. Any**
The `any` type is compatible with any other type.

```typescript
let anyVar: any;
let num: number = 42;

anyVar = num; // Valid
num = anyVar; // Valid
```

#### **c. Unknown**
`unknown` is more restrictive than `any`. It can only be assigned to `unknown` or `any`.

```typescript
let unknownVar: unknown;
let num: number;

// num = unknownVar; // Error
unknownVar = 42; // Valid
```

---

### **4. Object Type Compatibility**

Type compatibility between objects depends on their structure.

#### **Example:**
```typescript
interface Person {
  name: string;
  age: number;
}

let p1: Person = { name: "Alice", age: 30 };
let p2 = { name: "Bob", age: 25, city: "New York" };

p1 = p2; // Valid: p2 has at least the same properties as Person
// p2 = p1; // Error: p1 is missing the 'city' property
```

---

### **5. Function Compatibility**

#### **a. Parameter Compatibility**
A function can accept another function as an argument if its parameters are compatible.

```typescript
let add = (a: number, b: number): number => a + b;
let log = (a: number): void => console.log(a);

add = log; // Error: Parameter counts do not match
log = add; // Valid: add can ignore the second parameter
```

#### **b. Return Type Compatibility**
The return type of a function must be compatible with the expected type.

```typescript
let getNumber = (): number => 42;
let getString = (): string => "Hello";

// getNumber = getString; // Error: Type 'string' is not assignable to type 'number'
```

---

### **6. Enum Compatibility**

Enums are compatible with numbers but not with other enums.

```typescript
enum Color {
  Red,
  Blue,
}
enum Size {
  Small,
  Large,
}

let c: Color = Color.Red;
let num: number = 0;

c = num; // Valid
// num = Size.Small; // Error: Size is not compatible with Color
```

---

### **7. Union and Intersection Types**

#### **a. Union Compatibility**
A union type is compatible with another type if at least one of the union's member types is compatible.

```typescript
let unionVar: string | number;

unionVar = "Hello"; // Valid
unionVar = 42;      // Valid
// unionVar = true;   // Error
```

#### **b. Intersection Compatibility**
An intersection type must satisfy all constituent types.

```typescript
interface A {
  a: string;
}
interface B {
  b: number;
}

let obj: A & B = { a: "Hello", b: 42 }; // Valid
// let obj: A & B = { a: "Hello" }; // Error
```

---

### **8. Class Compatibility**

Classes are structurally typed, similar to interfaces.

#### **Example:**
```typescript
class Animal {
  name: string = "";
}

class Dog extends Animal {
  breed: string = "";
}

let a: Animal;
let d: Dog;

a = d; // Valid
// d = a; // Error: 'a' lacks the 'breed' property
```

---

### **9. Generics Compatibility**

Generic types are compatible if their constraints are compatible.

#### **Example:**
```typescript
interface Box<T> {
  value: T;
}

let box1: Box<number> = { value: 42 };
let box2: Box<string> = { value: "Hello" };

// box1 = box2; // Error: Type 'string' is not assignable to type 'number'
```

---

### **10. Covariance and Contravariance**

- **Covariance**: When a type can be substituted by its subtype (e.g., in return types).
- **Contravariance**: When a type can be substituted by its supertype (e.g., in function parameters).

#### **Example:**
```typescript
interface Animal {
  name: string;
}

interface Dog extends Animal {
  breed: string;
}

let dogFn: (dog: Dog) => void;
let animalFn: (animal: Animal) => void;

dogFn = animalFn; // Valid: Animal is more general
// animalFn = dogFn; // Error: Dog is more specific
```

---

### **11. Key Takeaways**

1. TypeScript's structural typing ensures compatibility based on shapes, not names.
2. Objects are compatible if they have the same or a superset of required properties.
3. Functions are compatible if their parameter types and return types match (or are more general/specific based on variance rules).
4. Generics and union/intersection types follow compatibility rules based on their constraints.
5. Use `unknown` and `any` cautiously, as they bypass strict type checks.

Understanding type compatibility helps prevent errors and enables better design of reusable and type-safe code.
