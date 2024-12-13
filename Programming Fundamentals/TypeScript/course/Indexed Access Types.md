### TypeScript - Indexed Access Types

**Indexed Access Types** allow you to access the **type** of a specific property in an object type using a key (or index). This is useful when you want to extract the type of a property from a given object type dynamically, often in combination with other TypeScript features like generics.

### **1. Basic Syntax of Indexed Access Types**

The basic syntax of an indexed access type is:

```typescript
T[K]
```

- `T` is the object type.
- `K` is the key or index, which can be a string, number, or symbol that exists in `T`.
- `T[K]` extracts the **type** of the property `K` from `T`.

### **2. Basic Example**

Let’s say you have an object type, and you want to get the type of one of its properties.

#### **Example:**
```typescript
type Person = {
  name: string;
  age: number;
  address: string;
};

type NameType = Person["name"];  // string
type AgeType = Person["age"];    // number

const name: NameType = "Alice";  // Valid
const age: AgeType = 25;         // Valid
```

- **Explanation**:
  - `Person["name"]` gives the type `string`, and `Person["age"]` gives the type `number`.
  - `NameType` and `AgeType` are now types referring to `string` and `number`, respectively.

### **3. Indexed Access with Union Types**

If the type `T` is a union type, the result of the indexed access will also be a union of the types of the corresponding properties from all members of the union.

#### **Example:**
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

type AgeType = PersonOrAnimal["age"];  // number

const personAge: AgeType = 30;   // Valid
const animalAge: AgeType = 5;    // Valid
```

- **Explanation**:
  - In the union `Person | Animal`, both `Person` and `Animal` have an `age` property of type `number`.
  - `PersonOrAnimal["age"]` will result in the type `number`.

### **4. Using `keyof` with Indexed Access Types**

Indexed access types are often used with the `keyof` operator, which allows you to dynamically access the type of any key in an object.

#### **Example:**
```typescript
type Person = {
  name: string;
  age: number;
};

type PropertyName = keyof Person;  // "name" | "age"

type NameType = Person[PropertyName];  // string | number

const nameOrAge: NameType = "Alice";  // Valid
const nameOrAgeNumber: NameType = 30; // Valid
```

- **Explanation**:
  - `PropertyName` is a union of the keys of the `Person` type (`"name" | "age"`).
  - `Person[PropertyName]` creates a type that is a union of the types of `name` and `age`, i.e., `string | number`.

### **5. Indexed Access with Optional Properties**

If an object has optional properties, TypeScript will correctly infer the type when accessing the properties through an indexed access type.

#### **Example:**
```typescript
type Person = {
  name: string;
  age?: number;
};

type AgeType = Person["age"];  // number | undefined

const validAge: AgeType = 25;    // Valid
const invalidAge: AgeType = undefined;  // Valid
```

- **Explanation**:
  - Since the `age` property is optional, `Person["age"]` results in `number | undefined`.
  - Both `25` and `undefined` are valid values.

### **6. Indexed Access with Arrays**

You can use indexed access types to extract the type of an element in an array, just like how you can with object properties.

#### **Example:**
```typescript
const numbers = [1, 2, 3];

type FirstElementType = typeof numbers[0];  // number

const firstElement: FirstElementType = 10;  // Valid
```

- **Explanation**:
  - `typeof numbers[0]` extracts the type of the first element of the `numbers` array, which is `number`.

### **7. Indexed Access with Complex Types**

You can also use indexed access types to extract types from deeply nested structures.

#### **Example:**
```typescript
type Person = {
  name: string;
  contact: {
    phone: string;
    email: string;
  };
};

type PhoneType = Person["contact"]["phone"];  // string

const phone: PhoneType = "123-456-7890";  // Valid
```

- **Explanation**:
  - `Person["contact"]["phone"]` extracts the type of the `phone` property from the nested `contact` object, which is `string`.

### **8. Conditional Types with Indexed Access**

Indexed access types can be combined with **conditional types** to create more dynamic types based on the presence of certain properties.

#### **Example:**
```typescript
type Person = {
  name: string;
  age: number;
};

type IsString<T> = T extends string ? true : false;

type NameIsString = IsString<Person["name"]>;  // true
type AgeIsString = IsString<Person["age"]>;    // false
```

- **Explanation**:
  - `Person["name"]` is `string`, so `IsString<string>` results in `true`.
  - `Person["age"]` is `number`, so `IsString<number>` results in `false`.

### **9. Indexed Access with Readonly Types**

When using `Readonly` with objects, the indexed access will also give the type as readonly.

#### **Example:**
```typescript
type Person = {
  name: string;
  age: number;
};

type ReadonlyPerson = Readonly<Person>;

type NameType = ReadonlyPerson["name"];  // readonly string

const name: NameType = "Alice";  // Valid
// name = "Bob";  // Error: Cannot assign to 'name' because it is a read-only property.
```

- **Explanation**:
  - `Readonly<Person>` makes all properties of `Person` immutable.
  - `ReadonlyPerson["name"]` gives `readonly string`, making it impossible to reassign the `name` property.

### **10. Conclusion**

Indexed Access Types in TypeScript allow you to:

- Extract types of specific properties from an object using the syntax `T[K]`.
- Work dynamically with object properties and use them in complex types.
- Use `keyof` in combination with indexed access to dynamically extract union types from an object's keys.
- Combine with other advanced TypeScript features, such as conditional types and generics, to create flexible and type-safe code.

By using indexed access types, you can ensure that your TypeScript code has better type safety when working with dynamic property names and complex data structures.
