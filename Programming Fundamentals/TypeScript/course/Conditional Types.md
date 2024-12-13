### TypeScript - Conditional Types

**Conditional Types** in TypeScript are a powerful tool that allow you to define types based on a condition. They provide a way to express relationships between types in a more flexible and dynamic manner. Conditional types follow the pattern of `T extends U ? X : Y`, which means:

- If `T` is assignable to `U`, the type resolves to `X`.
- If `T` is **not** assignable to `U`, the type resolves to `Y`.

Conditional types can be extremely useful in many scenarios, such as for creating type-safe utilities, dealing with unions and intersections, and customizing types based on generic parameters.

### **1. Basic Syntax**

The basic syntax of a conditional type looks like this:

```typescript
T extends U ? X : Y
```

- `T`: The type that you are checking.
- `U`: The type you're checking `T` against.
- `X`: The type to resolve if `T` is assignable to `U`.
- `Y`: The type to resolve if `T` is **not** assignable to `U`.

### **2. Basic Example**

Let’s look at a simple example where we create a conditional type that resolves to a different type based on the input type.

#### **Example:**
```typescript
type IsString<T> = T extends string ? "Yes" : "No";

type Result1 = IsString<string>;  // "Yes"
type Result2 = IsString<number>;  // "No"
```

- **Explanation**:
  - `IsString<T>` is a conditional type.
  - If `T` extends `string`, the type resolves to `"Yes"`, otherwise it resolves to `"No"`.
  - `Result1` is `"Yes"` because `string` extends `string`, and `Result2` is `"No"` because `number` does not extend `string`.

### **3. Conditional Types with Generics**

Conditional types are often used in **generics** to create more flexible and reusable types.

#### **Example:**
```typescript
type IsArray<T> = T extends any[] ? "Array" : "Not an Array";

type ArrayResult = IsArray<number[]>;  // "Array"
type NotArrayResult = IsArray<string>;  // "Not an Array"
```

- **Explanation**:
  - `IsArray<T>` checks if the type `T` is an array.
  - If `T` extends `any[]`, it resolves to `"Array"`, otherwise to `"Not an Array"`.
  - `ArrayResult` resolves to `"Array"`, and `NotArrayResult` resolves to `"Not an Array"`.

### **4. Conditional Types with Multiple Conditions**

You can use multiple `extends` clauses to check more than one condition in a conditional type.

#### **Example:**
```typescript
type CheckType<T> = T extends string
  ? "String"
  : T extends number
  ? "Number"
  : "Other";

type Result1 = CheckType<string>;  // "String"
type Result2 = CheckType<number>;  // "Number"
type Result3 = CheckType<boolean>; // "Other"
```

- **Explanation**:
  - `CheckType<T>` checks if `T` extends `string`, and if not, checks if `T` extends `number`. If neither, it resolves to `"Other"`.
  - `Result1` resolves to `"String"`, `Result2` resolves to `"Number"`, and `Result3` resolves to `"Other"`.

### **5. Conditional Types with `infer`**

You can use the `infer` keyword inside a conditional type to **infer a type** based on another type.

#### **Example:**
```typescript
type ReturnType<T> = T extends (...args: any[]) => infer R ? R : never;

type Func1 = (a: number, b: string) => boolean;
type Func2 = (x: string) => void;

type ReturnType1 = ReturnType<Func1>;  // boolean
type ReturnType2 = ReturnType<Func2>;  // void
```

- **Explanation**:
  - `ReturnType<T>` is a conditional type that checks if `T` is a function. If it is, it uses `infer R` to infer the return type of the function. Otherwise, it resolves to `never`.
  - `ReturnType1` is `boolean` because `Func1` returns a boolean, and `ReturnType2` is `void` because `Func2` returns `void`.

### **6. Distributive Conditional Types**

When conditional types are applied to **union types**, TypeScript distributes the type condition over the union. This is known as **distributive conditional types**.

#### **Example:**
```typescript
type IsString<T> = T extends string ? "Yes" : "No";

type Result = IsString<string | number>;  // "Yes" | "No"
```

- **Explanation**:
  - `IsString<string | number>` resolves to `"Yes" | "No"`. TypeScript applies the conditional type separately to each type in the union (`string` and `number`).
  
### **7. Conditional Types with `extends` in Object Types**

Conditional types can also be used to check whether an object type extends another object type.

#### **Example:**
```typescript
type IsPerson<T> = T extends { name: string } ? "Person" : "Not a Person";

type PersonType = { name: string; age: number };
type AnimalType = { species: string };

type Result1 = IsPerson<PersonType>;  // "Person"
type Result2 = IsPerson<AnimalType>;  // "Not a Person"
```

- **Explanation**:
  - `IsPerson<T>` checks if `T` has a property `name` of type `string`. If it does, the type resolves to `"Person"`, otherwise to `"Not a Person"`.
  - `Result1` resolves to `"Person"`, and `Result2` resolves to `"Not a Person"`.

### **8. Using Conditional Types for Overloading**

Conditional types can also be used to implement function overloading, where the return type depends on the type of the arguments passed.

#### **Example:**
```typescript
type MyFunction<T> = T extends string ? "String function" : "Other function";

function callFunction<T>(arg: T): MyFunction<T> {
  if (typeof arg === "string") {
    return "String function" as MyFunction<T>;
  }
  return "Other function" as MyFunction<T>;
}

const result1 = callFunction("hello");  // "String function"
const result2 = callFunction(123);     // "Other function"
```

- **Explanation**:
  - `MyFunction<T>` is a conditional type that resolves to `"String function"` if `T` is `string`, and `"Other function"` for other types.
  - The return type of `callFunction` changes based on whether `T` is a `string` or not.

### **9. Conditional Types for Recursive Types**

You can use conditional types to create **recursive types** by checking whether a type is a certain structure and then calling the conditional type on its properties.

#### **Example:**
```typescript
type Flatten<T> = T extends (infer U)[] ? U : T;

type ArrayFlattened = Flatten<number[]>;  // number
type NumberFlattened = Flatten<number>;   // number
```

- **Explanation**:
  - `Flatten<T>` checks if `T` is an array. If it is, it flattens the array type (`U` is the element type of the array). If `T` is not an array, it simply returns `T` as is.
  - `ArrayFlattened` resolves to `number` because the type is an array of numbers (`number[]`), and `NumberFlattened` resolves to `number` because `T` is already a `number`.

### **10. Conclusion**

Conditional types in TypeScript provide a powerful mechanism for writing more flexible and type-safe code. Some key takeaways include:

- Conditional types allow you to create dynamic types that depend on conditions (`T extends U ? X : Y`).
- You can use conditional types with generics, `infer`, union types, and more.
- They are particularly useful for writing utility types, overloading functions, and refining types based on structure or specific conditions.
  
By mastering conditional types, you can take advantage of TypeScript’s full potential for type safety and expressiveness, making your code more maintainable and flexible.
