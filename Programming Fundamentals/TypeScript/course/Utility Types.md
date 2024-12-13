### TypeScript - Utility Types

Utility types in TypeScript are built-in generic types that help manipulate types and improve the reusability and flexibility of your code. These types provide powerful, concise ways to transform and work with types in various scenarios.

---

### **1. `Partial<T>`**

The `Partial<T>` utility type creates a new type by making all properties of the given type `T` optional.

#### **Example:**

```typescript
interface User {
  name: string;
  age: number;
  email: string;
}

const updateUser = (user: User, updates: Partial<User>) => {
  return { ...user, ...updates };
};

const user: User = { name: "John", age: 30, email: "john@example.com" };
const updatedUser = updateUser(user, { age: 31 });
console.log(updatedUser); // { name: 'John', age: 31, email: 'john@example.com' }
```

---

### **2. `Required<T>`**

The `Required<T>` utility type creates a new type by making all properties of the given type `T` required (removes optional properties).

#### **Example:**

```typescript
interface User {
  name: string;
  age?: number;
}

const user: Required<User> = { name: "Alice", age: 25 }; 
// Error: Property 'age' is required, so it is not optional anymore.
```

---

### **3. `Readonly<T>`**

The `Readonly<T>` utility type creates a new type by making all properties of the given type `T` read-only, preventing modification.

#### **Example:**

```typescript
interface User {
  name: string;
  age: number;
}

const user: Readonly<User> = { name: "Bob", age: 40 };
// user.age = 41; // Error: Cannot assign to 'age' because it is a read-only property.
```

---

### **4. `Record<K, T>`**

The `Record<K, T>` utility type constructs an object type with keys of type `K` and values of type `T`.

#### **Example:**

```typescript
type Status = "success" | "error" | "loading";
const statusMessages: Record<Status, string> = {
  success: "Operation was successful.",
  error: "There was an error.",
  loading: "Loading, please wait...",
};
```

This creates an object where the keys are restricted to `"success" | "error" | "loading"`, and the values are of type `string`.

---

### **5. `Pick<T, K>`**

The `Pick<T, K>` utility type creates a new type by picking a subset of properties from the type `T`. The second type parameter `K` is a union of property keys you want to include in the new type.

#### **Example:**

```typescript
interface User {
  name: string;
  age: number;
  email: string;
}

type UserNameAndEmail = Pick<User, "name" | "email">;

const user: UserNameAndEmail = { name: "Charlie", email: "charlie@example.com" };
```

---

### **6. `Omit<T, K>`**

The `Omit<T, K>` utility type creates a new type by omitting a subset of properties from type `T`. The second type parameter `K` is a union of property keys you want to exclude.

#### **Example:**

```typescript
interface User {
  name: string;
  age: number;
  email: string;
}

type UserWithoutEmail = Omit<User, "email">;

const user: UserWithoutEmail = { name: "David", age: 35 };
// Error: Property 'email' does not exist on type 'UserWithoutEmail'.
```

---

### **7. `Exclude<T, U>`**

The `Exclude<T, U>` utility type constructs a type by excluding from type `T` all properties that are assignable to type `U`.

#### **Example:**

```typescript
type A = "a" | "b" | "c";
type B = "a" | "b";
type C = Exclude<A, B>; // Result is "c"

const value: C = "c"; // Works fine
// const value2: C = "a"; // Error: Type 'a' is not assignable to type 'c'
```

---

### **8. `Extract<T, U>`**

The `Extract<T, U>` utility type constructs a type by extracting from type `T` all properties that are assignable to type `U`.

#### **Example:**

```typescript
type A = "a" | "b" | "c";
type B = "a" | "b";
type C = Extract<A, B>; // Result is "a" | "b"

const value: C = "a"; // Works fine
```

---

### **9. `NonNullable<T>`**

The `NonNullable<T>` utility type removes `null` and `undefined` from the type `T`.

#### **Example:**

```typescript
type NullableString = string | null | undefined;
type NonNullableString = NonNullable<NullableString>; // Result is string

const name: NonNullableString = "Alice"; // Works fine
// const name2: NonNullableString = null; // Error: Type 'null' is not assignable to type 'string'
```

---

### **10. `InstanceType<T>`**

The `InstanceType<T>` utility type extracts the type of an instance from a constructor type `T`.

#### **Example:**

```typescript
class Person {
  constructor(public name: string) {}
}

type PersonInstance = InstanceType<typeof Person>; // Person

const person: PersonInstance = new Person("John"); // Works fine
```

---

### **11. `ReturnType<T>`**

The `ReturnType<T>` utility type extracts the return type of a function type `T`.

#### **Example:**

```typescript
function getUser() {
  return { name: "Jane", age: 28 };
}

type UserType = ReturnType<typeof getUser>; // { name: string, age: number }

const user: UserType = { name: "Alice", age: 30 }; // Works fine
```

---

### **12. `Parameters<T>`**

The `Parameters<T>` utility type extracts the types of parameters from a function type `T`.

#### **Example:**

```typescript
function greet(name: string, age: number) {
  return `Hello ${name}, you are ${age} years old.`;
}

type GreetParams = Parameters<typeof greet>; // [string, number]

const params: GreetParams = ["John", 25]; // Works fine
```

---

### **13. `ConstructorParameters<T>`**

The `ConstructorParameters<T>` utility type extracts the parameter types of a class constructor.

#### **Example:**

```typescript
class Person {
  constructor(public name: string, public age: number) {}
}

type PersonConstructorParams = ConstructorParameters<typeof Person>; // [string, number]

const params: PersonConstructorParams = ["John", 25]; // Works fine
```

---

### **14. `ThisType<T>`**

The `ThisType<T>` utility type is used to define the `this` type in object types, particularly useful in scenarios involving object literals and mixins.

#### **Example:**

```typescript
interface Counter {
  count: number;
  increment(this: ThisType<Counter>): void;
}

const counter: Counter = {
  count: 0,
  increment() {
    this.count++;
  },
};
counter.increment();
console.log(counter.count); // 1
```

---

### **15. Summary of Common Utility Types**

| Utility Type        | Description                                                |
|---------------------|------------------------------------------------------------|
| `Partial<T>`         | Makes all properties optional                              |
| `Required<T>`        | Makes all properties required                              |
| `Readonly<T>`        | Makes all properties read-only                             |
| `Record<K, T>`       | Constructs an object type with keys of type `K` and values of type `T` |
| `Pick<T, K>`         | Picks a subset of properties from `T`                       |
| `Omit<T, K>`         | Omits properties `K` from type `T`                          |
| `Exclude<T, U>`      | Excludes types from `T` that are assignable to `U`          |
| `Extract<T, U>`      | Extracts types from `T` that are assignable to `U`          |
| `NonNullable<T>`     | Excludes `null` and `undefined` from type `T`               |
| `InstanceType<T>`    | Extracts the type of instances created by the constructor `T` |
| `ReturnType<T>`      | Extracts the return type of a function type `T`             |
| `Parameters<T>`      | Extracts the parameter types of a function type `T`         |
| `ConstructorParameters<T>` | Extracts the constructor parameters of a class `T`   |
| `ThisType<T>`        | Specifies the `this` type for object literals or mixins    |

---

### **Conclusion**

Utility types in TypeScript are powerful tools that allow developers to manipulate and enhance types easily. They simplify type transformations, making your code more flexible, reusable, and maintainable. By understanding and leveraging these utility types, you can handle complex scenarios efficiently while maintaining type safety in your codebase.
