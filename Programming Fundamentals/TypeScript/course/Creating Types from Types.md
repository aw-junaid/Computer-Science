### TypeScript - Creating Types from Types

In TypeScript, you can create new types by building upon existing ones. TypeScript offers various ways to transform, combine, or extend existing types, allowing you to construct complex types in a modular and flexible manner.

These approaches include **type aliases**, **mapped types**, **conditional types**, and **utility types**. Let's explore how you can create types from existing types in TypeScript.

### **1. Type Aliases**

Type aliases allow you to define a new name for an existing type or combination of types. A type alias can be used to create a custom type based on existing types, including primitive types, union types, object types, etc.

#### **Example: Type Alias for a Custom Type**
```typescript
type Point = {
  x: number;
  y: number;
};

let p1: Point = { x: 10, y: 20 };
```

- **Explanation**: The `Point` type alias defines an object with `x` and `y` as `number` properties. You can now use the `Point` type throughout your code to create objects with that shape.

#### **Example: Type Alias for Union Types**
```typescript
type Status = "active" | "inactive" | "pending";

let userStatus: Status = "active";  // Correct
// userStatus = "deleted";  // Error: Type '"deleted"' is not assignable to type 'Status'.
```

- **Explanation**: The `Status` type alias creates a union type, meaning `userStatus` can only be one of the three string values: `"active"`, `"inactive"`, or `"pending"`.

### **2. Intersection Types**

You can combine multiple types into one using the **intersection operator** (`&`). This creates a new type that contains all the properties of the original types.

#### **Example: Using Intersection Types**
```typescript
type Employee = {
  name: string;
  role: string;
};

type Address = {
  street: string;
  city: string;
};

type EmployeeWithAddress = Employee & Address;

const employee: EmployeeWithAddress = {
  name: "Alice",
  role: "Developer",
  street: "123 Main St",
  city: "New York"
};
```

- **Explanation**: The `EmployeeWithAddress` type combines the properties of both `Employee` and `Address` using the intersection type (`&`). The resulting type requires all properties from both types.

### **3. Mapped Types**

Mapped types allow you to create new types by transforming the properties of an existing type. This is especially useful for iterating over all properties of an object and changing their types or adding new properties.

#### **Example: Creating a Read-Only Type**
```typescript
type Person = {
  name: string;
  age: number;
};

type ReadOnlyPerson = {
  readonly [K in keyof Person]: Person[K];
};

const person: ReadOnlyPerson = { name: "John", age: 25 };
person.name = "Jane";  // Error: Cannot assign to 'name' because it is a read-only property.
```

- **Explanation**: The `ReadOnlyPerson` type is created using a mapped type. The `readonly` modifier makes all properties of `Person` immutable. The `keyof Person` extracts the keys from the `Person` type, and for each key `K`, it creates a `readonly` version of that property.

#### **Example: Optional Properties with Mapped Types**
```typescript
type Person = {
  name: string;
  age: number;
};

type OptionalPerson = {
  [K in keyof Person]?: Person[K];
};

const person: OptionalPerson = { name: "Alice" };  // Valid: `age` is optional
```

- **Explanation**: In the `OptionalPerson` type, each property is made optional using the `?` operator. The mapped type iterates over each key of `Person` and marks it as optional.

### **4. Conditional Types**

Conditional types allow you to create a new type based on a condition. This is useful for creating types that change depending on other types.

#### **Example: Conditional Types**
```typescript
type IsString<T> = T extends string ? "Yes" : "No";

type Test1 = IsString<string>;  // "Yes"
type Test2 = IsString<number>;  // "No"
```

- **Explanation**: The `IsString` type takes a type `T` and checks if it extends `string`. If `T` is a `string`, it resolves to `"Yes"`, otherwise, it resolves to `"No"`. This is an example of a conditional type.

#### **Example: Conditional Types with `infer`**
```typescript
type ExtractReturnType<T> = T extends (...args: any[]) => infer R ? R : never;

type Func = (x: number, y: number) => string;
type ReturnTypeOfFunc = ExtractReturnType<Func>;  // string
```

- **Explanation**: The `ExtractReturnType` type uses conditional types to extract the return type (`R`) from a function type. The `infer` keyword allows TypeScript to infer the type of the return value of the function.

### **5. Utility Types**

TypeScript includes several built-in **utility types** that help you create new types from existing ones. These utility types are predefined types that you can use in your code for common transformations.

#### **Example: `Partial<T>` Utility Type**

The `Partial<T>` utility type makes all properties of type `T` optional.

```typescript
type Person = {
  name: string;
  age: number;
};

type PartialPerson = Partial<Person>;

const person: PartialPerson = { name: "Alice" };  // Valid: `age` is optional
```

- **Explanation**: The `Partial` utility type makes all properties of `Person` optional, allowing you to create objects with only some of the properties.

#### **Example: `Pick<T, K>` Utility Type**

The `Pick<T, K>` utility type creates a new type by selecting a subset of properties from type `T`.

```typescript
type Person = {
  name: string;
  age: number;
  address: string;
};

type PersonNameAndAge = Pick<Person, "name" | "age">;

const person: PersonNameAndAge = { name: "Alice", age: 25 };
```

- **Explanation**: The `Pick` utility type allows you to create a new type (`PersonNameAndAge`) by picking specific properties (`name` and `age`) from the `Person` type.

#### **Example: `Omit<T, K>` Utility Type**

The `Omit<T, K>` utility type creates a new type by omitting certain properties from type `T`.

```typescript
type Person = {
  name: string;
  age: number;
  address: string;
};

type PersonWithoutAddress = Omit<Person, "address">;

const person: PersonWithoutAddress = { name: "Alice", age: 25 };
```

- **Explanation**: The `Omit` utility type creates a new type by excluding the `address` property from the `Person` type.

### **6. Combining All Techniques**

You can combine multiple techniques to create advanced types from existing ones.

#### **Example: Combining `Mapped Types`, `Conditional Types`, and Utility Types**
```typescript
type Person = {
  name: string;
  age: number;
  address: string;
};

// Use mapped types to make properties optional, and conditional types to exclude `address`
type OptionalPersonWithoutAddress = Omit<{ [K in keyof Person]?: Person[K] }, "address">;

const person: OptionalPersonWithoutAddress = { name: "Alice", age: 25 };
```

- **Explanation**: This example combines a mapped type (`[K in keyof Person]?: Person[K]`) to make all properties optional, and the `Omit` utility type to remove the `address` property from the final type.

### **7. Conclusion**

TypeScript provides various techniques to create new types from existing ones. You can:

1. **Create new types** using **type aliases** and **intersection types**.
2. **Transform existing types** with **mapped types** and **conditional types**.
3. Use **utility types** like `Partial`, `Pick`, and `Omit` to perform common type transformations easily.

By leveraging these tools, you can create flexible and reusable types in TypeScript that help improve type safety and maintainability in your code.
