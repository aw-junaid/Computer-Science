### TypeScript - Mapped Types

**Mapped Types** in TypeScript allow you to create new types by transforming the properties of an existing type. Mapped types are particularly useful for modifying the properties of a type in a systematic way, such as making all properties optional, readonly, or renaming them.

### **1. Basic Syntax of Mapped Types**

The basic syntax of a mapped type looks like this:

```typescript
type NewType = {
  [P in K]: T;
};
```

- `P`: A placeholder for each property key (it’s like a loop variable).
- `K`: The set of keys (either a specific set or all keys of an object type).
- `T`: The type that will be applied to each property.

### **2. Mapped Types with `keyof`**

You can use `keyof` in combination with mapped types to create types where the keys are based on the properties of another type.

#### **Example:**
```typescript
type Person = {
  name: string;
  age: number;
};

type PersonKeys = keyof Person;  // "name" | "age"

type MappedPerson = {
  [K in PersonKeys]: string;
};

// Resulting type: { name: string; age: string; }
```

- **Explanation**:
  - `MappedPerson` takes the keys from `Person` (which are `"name"` and `"age"`) and makes them both of type `string`.
  - The resulting type is `{ name: string; age: string; }`.

### **3. Making Properties Optional with Mapped Types**

You can use mapped types to modify the properties of a type, such as making all properties **optional**.

#### **Example:**
```typescript
type Person = {
  name: string;
  age: number;
};

type Optional<T> = {
  [K in keyof T]?: T[K];
};

type OptionalPerson = Optional<Person>;

// Resulting type: { name?: string; age?: number; }
```

- **Explanation**:
  - The `Optional<T>` mapped type makes all properties in `T` optional by adding `?` to each property.
  - `OptionalPerson` will have `name` and `age` as optional properties.

### **4. Making Properties Readonly with Mapped Types**

You can create a type where all properties are **readonly** using mapped types.

#### **Example:**
```typescript
type Person = {
  name: string;
  age: number;
};

type ReadonlyPerson = {
  readonly [K in keyof Person]: Person[K];
};

// Resulting type: { readonly name: string; readonly age: number; }
```

- **Explanation**:
  - The `ReadonlyPerson` type makes all properties of `Person` immutable by adding `readonly` before each property.
  - This means you can’t change the values of `name` or `age` after the object is created.

### **5. Mapping Over Union Types**

Mapped types can also work with union types to apply transformations to each member of the union.

#### **Example:**
```typescript
type Fruit = "apple" | "orange" | "banana";

type FruitDetails = {
  [K in Fruit]: string;
};

// Resulting type: { apple: string; orange: string; banana: string; }
```

- **Explanation**:
  - The type `FruitDetails` uses a mapped type to create a new type where each value of the `Fruit` union (e.g., `"apple"`, `"orange"`, and `"banana"`) becomes a property with a `string` type.

### **6. Conditional Mapped Types**

You can combine **conditional types** with mapped types to create more complex transformations.

#### **Example:**
```typescript
type Person = {
  name: string;
  age: number;
  isAdmin: boolean;
};

type ConditionalMappedType<T> = {
  [K in keyof T]: T[K] extends boolean ? "yes" : T[K];
};

type PersonMapped = ConditionalMappedType<Person>;

// Resulting type: { name: string; age: number; isAdmin: "yes"; }
```

- **Explanation**:
  - In the `ConditionalMappedType` type, we check if a property is of type `boolean`. If it is, we change its type to `"yes"`. Otherwise, we retain the original type.

### **7. Excluding or Including Specific Properties**

Mapped types can also be combined with other utility types like `Exclude` or `Pick` to exclude or include specific properties from the original type.

#### **Example:**
```typescript
type Person = {
  name: string;
  age: number;
  address: string;
};

type PickPerson = {
  [K in keyof Person as K extends "name" | "age" ? K : never]: Person[K];
};

// Resulting type: { name: string; age: number; }
```

- **Explanation**:
  - `PickPerson` uses a mapped type to include only the properties `"name"` and `"age"` from the original `Person` type, excluding `address`.
  - The `as` keyword is used to remap keys in a mapped type, and `K extends "name" | "age" ? K : never` ensures that only the `name` and `age` properties are included.

### **8. Mapped Types with `in` to Create New Types**

You can use the `in` keyword to iterate over a set of strings or keys when creating a mapped type.

#### **Example:**
```typescript
type Fruit = "apple" | "orange" | "banana";

type FruitInfo = {
  [K in Fruit]: { color: string; taste: string };
};

// Resulting type:
// {
//   apple: { color: string; taste: string };
//   orange: { color: string; taste: string };
//   banana: { color: string; taste: string };
// }
```

- **Explanation**:
  - `FruitInfo` is a mapped type that creates an object where each fruit is a key, and the value is an object containing `color` and `taste` properties.
  - The type will be `{ apple: { color: string; taste: string }; orange: { color: string; taste: string }; banana: { color: string; taste: string }; }`.

### **9. Removing Properties with `Exclude` and Mapped Types**

You can use mapped types in combination with the `Exclude` utility type to remove certain properties from an existing type.

#### **Example:**
```typescript
type Person = {
  name: string;
  age: number;
  address: string;
};

type ExcludeAddress<T> = {
  [K in Exclude<keyof T, "address">]: T[K];
};

type PersonWithoutAddress = ExcludeAddress<Person>;
// Resulting type: { name: string; age: number; }
```

- **Explanation**:
  - `ExcludeAddress<T>` uses the `Exclude` utility type to remove the `address` property from the type `T`.
  - `PersonWithoutAddress` will have the `name` and `age` properties, but not `address`.

### **10. Conclusion**

Mapped types in TypeScript are an incredibly powerful tool for transforming and manipulating types in a flexible and reusable way. Here are some key takeaways:

- You can create new types by iterating over the properties of an existing type and applying transformations.
- Mapped types can be used to make properties optional (`?`), readonly (`readonly`), or apply conditional changes based on the property types.
- They can be combined with other TypeScript utility types (like `keyof`, `Exclude`, `Pick`, etc.) to create complex and dynamic type transformations.
- Mapped types enable you to work with union types, recursive structures, and more, providing the full flexibility of TypeScript’s type system.

By leveraging mapped types, you can write cleaner, more maintainable code with advanced type safety features.
