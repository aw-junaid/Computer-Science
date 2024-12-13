### TypeScript - `keyof` Type Operator

The `keyof` type operator in TypeScript is used to extract the **keys** of a given type (or object) as a union of string literal types. This operator allows you to get a type that represents the set of all property names (keys) of a type.

### **Syntax**
```typescript
type Keys = keyof Type;
```

- `Type` is any object type, and `keyof Type` results in a union type of all the keys of that object.

### **1. Basic Example:**

If you have an object type, you can use `keyof` to create a type that represents the keys of that object.

#### **Example:**
```typescript
type Person = {
  name: string;
  age: number;
  address: string;
};

type PersonKeys = keyof Person;  // "name" | "age" | "address"

let key: PersonKeys;
key = "name";  // Valid
key = "age";   // Valid
key = "address";  // Valid
key = "email";   // Error: Type '"email"' is not assignable to type 'PersonKeys'
```

- **Explanation**: 
  - `keyof Person` is a type that represents the union of all keys in the `Person` type, i.e., `"name" | "age" | "address"`.
  - The variable `key` can be assigned any of these keys but not any other string that is not part of `Person`.

### **2. Using `keyof` with Object Types**

The `keyof` operator is typically used with object types, where you want to reference or limit your keys dynamically based on the type.

#### **Example: Accessing Object Properties Using `keyof`**
```typescript
type Person = {
  name: string;
  age: number;
  address: string;
};

function getValue(obj: Person, key: keyof Person) {
  return obj[key];
}

const person = { name: "Alice", age: 30, address: "123 Main St" };

const personName = getValue(person, "name");  // "Alice"
const personAge = getValue(person, "age");    // 30
```

- **Explanation**: 
  - The `getValue` function accepts an object of type `Person` and a key of type `keyof Person`. This ensures that the key passed to the function must be one of the keys from the `Person` type.

### **3. Using `keyof` with Arrays**

Although `keyof` is typically used for objects, you can also use it with arrays to refer to the indices (keys) of the array type.

#### **Example:**
```typescript
type NumbersArray = number[];

type ArrayIndex = keyof NumbersArray;  // "0" | "1" | "2" | ...
```

- **Explanation**: 
  - When you use `keyof` on an array type, the result will be a union of numeric indices (the keys of the array). For example, `keyof number[]` will be the string literal type `"0" | "1" | "2" | ...`.

### **4. `keyof` and Generic Types**

The `keyof` operator works well with **generic types** when you want to extract the keys of the type that is passed as a generic parameter.

#### **Example: Using `keyof` with Generics**
```typescript
function getProperty<T>(obj: T, key: keyof T) {
  return obj[key];
}

const person = { name: "John", age: 25 };
const name = getProperty(person, "name");  // John
const age = getProperty(person, "age");    // 25
```

- **Explanation**: 
  - The function `getProperty` is generic, and it takes a type `T` which is inferred from the `obj` parameter.
  - The `keyof T` type ensures that the `key` parameter must be a valid key of the object passed as `obj`.

### **5. `keyof` with Union Types**

You can combine `keyof` with union types to work with objects that might be of different shapes, ensuring the correct keys are used.

#### **Example: Using `keyof` with Union Types**
```typescript
type Person = {
  name: string;
  age: number;
};

type Animal = {
  species: string;
  age: number;
};

type PersonOrAnimal = Person | Animal;

function getInfo(obj: PersonOrAnimal, key: keyof PersonOrAnimal) {
  return obj[key];
}

const person: Person = { name: "Alice", age: 30 };
const animal: Animal = { species: "Dog", age: 5 };

const personName = getInfo(person, "name");  // "Alice"
const animalSpecies = getInfo(animal, "species");  // "Dog"
```

- **Explanation**: 
  - The function `getInfo` works with a union type (`Person | Animal`), and `keyof PersonOrAnimal` gives a union of the valid keys from both `Person` and `Animal`. 
  - This ensures that `key` must be a valid property name from either `Person` or `Animal`.

### **6. Conditional Types and `keyof`**

You can also use `keyof` in combination with conditional types to create more flexible and dynamic types based on the keys of an object.

#### **Example: Conditional Types with `keyof`**
```typescript
type Person = {
  name: string;
  age: number;
};

type GetTypeOfKey<T, K extends keyof T> = T[K];

type NameType = GetTypeOfKey<Person, "name">;  // string
type AgeType = GetTypeOfKey<Person, "age">;    // number
```

- **Explanation**: 
  - The type `GetTypeOfKey` uses `keyof` to ensure that `K` is a valid key of `T`. 
  - It then returns the type of the property corresponding to that key. For `Person`, `"name"` corresponds to `string` and `"age"` corresponds to `number`.

### **7. `keyof` with `typeof` Operator**

You can combine `keyof` with the `typeof` operator to dynamically extract keys from a variable's type.

#### **Example: Using `keyof` with `typeof`**
```typescript
const person = { name: "Alice", age: 30 };

type PersonKeys = keyof typeof person;  // "name" | "age"

let key: PersonKeys;
key = "name";  // Valid
key = "age";   // Valid
key = "address";  // Error: Type '"address"' is not assignable to type 'PersonKeys'
```

- **Explanation**: 
  - The `typeof` operator gets the type of the `person` object, and then `keyof` extracts the keys (`"name"` and `"age"`).

### **8. Conclusion**

The `keyof` operator in TypeScript is powerful for extracting keys from object types. It can be used in a variety of scenarios, such as:

- Extracting keys from an object type.
- Restricting function parameters to only valid keys of a given object.
- Combining with generics to create reusable functions.
- Working with union types and conditional types.

By leveraging the `keyof` operator, you can ensure better type safety when working with keys and values in TypeScript, making your code more robust and maintainable.
