### TypeScript - `typeof` Type Operator

The `typeof` type operator in TypeScript is used to obtain the **type** of a value or an object. This allows you to reference the type of a variable or property directly and use it in other parts of your code, such as for function parameters or as part of a type alias.

The `typeof` operator works at **compile time** and allows you to infer types based on the actual value of a variable. It’s different from the JavaScript `typeof` operator (which returns a string representing the type of a value at runtime) because TypeScript's `typeof` allows you to refer to a value's type in a static context.

### **1. Basic Usage**

The `typeof` operator is used to refer to the type of a variable or expression.

#### **Example: Using `typeof` to Infer the Type of a Variable**
```typescript
let person = { name: "Alice", age: 30 };

// Using `typeof` to reference the type of `person`
type Person = typeof person;

const newPerson: Person = { name: "Bob", age: 25 };  // Valid
const invalidPerson: Person = { name: "Charlie" };  // Error: Property 'age' is missing.
```

- **Explanation**:
  - The `typeof person` gives the type of the `person` object, which is `{ name: string, age: number }`.
  - We can use this type `Person` to create new objects with the same structure as `person`.

### **2. `typeof` with Functions**

You can use `typeof` to get the type of a function and use it as the type of another variable or function.

#### **Example: Using `typeof` with a Function Type**
```typescript
function greet(name: string): string {
  return `Hello, ${name}`;
}

type GreetFunction = typeof greet;

const greetClone: GreetFunction = (name: string) => `Hi, ${name}`;  // Valid
const invalidGreet: GreetFunction = (name: string, age: number) => `Hello, ${name}`;  // Error: Too many arguments
```

- **Explanation**:
  - The `typeof greet` gives us the type of the `greet` function, which is `(name: string) => string`.
  - The variable `greetClone` must have the same signature as `greet`, i.e., it must accept a single `string` argument and return a `string`.

### **3. `typeof` with Arrays**

You can also use `typeof` to get the type of an array.

#### **Example: Using `typeof` with Arrays**
```typescript
let numbers = [1, 2, 3, 4];

type NumbersArray = typeof numbers;  // number[]

const validNumbers: NumbersArray = [5, 6, 7];  // Valid
const invalidNumbers: NumbersArray = ["five", "six", "seven"];  // Error: Type 'string' is not assignable to type 'number'
```

- **Explanation**:
  - The `typeof numbers` results in the type `number[]`, which means an array of numbers.
  - `validNumbers` is correctly typed, but `invalidNumbers` is an error because it contains `string` values instead of `number`.

### **4. `typeof` for Constant Values**

You can use `typeof` to create types based on constant values, which is particularly useful for defining values that should remain constant.

#### **Example: Using `typeof` with Constants**
```typescript
const fruit = "apple";
const vegetable = "carrot";

type FruitType = typeof fruit;  // "apple"
type VegetableType = typeof vegetable;  // "carrot"

const myFruit: FruitType = "apple";  // Valid
const myVegetable: VegetableType = "carrot";  // Valid
const wrongFruit: FruitType = "banana";  // Error: Type '"banana"' is not assignable to type '"apple"'
```

- **Explanation**:
  - The `typeof fruit` gives the literal type `"apple"`, and `typeof vegetable` gives the literal type `"carrot"`.
  - This ensures that the variables `myFruit` and `myVegetable` can only be assigned their respective values.

### **5. `typeof` with Object Types**

When you use `typeof` with an object, it will return the **shape** (type) of the object, including all its properties.

#### **Example: Using `typeof` with an Object**
```typescript
const car = {
  make: "Toyota",
  model: "Corolla",
  year: 2020
};

type CarType = typeof car;

const anotherCar: CarType = { make: "Honda", model: "Civic", year: 2022 };  // Valid
const wrongCar: CarType = { make: "Ford", model: "Focus" };  // Error: Property 'year' is missing.
```

- **Explanation**:
  - `typeof car` extracts the type of the `car` object, which is `{ make: string, model: string, year: number }`.
  - `anotherCar` conforms to this type, but `wrongCar` fails because it is missing the `year` property.

### **6. `typeof` with Type Inference**

TypeScript uses `typeof` to infer types of variables, so you don’t always have to explicitly define types.

#### **Example: Type Inference with `typeof`**
```typescript
let score = 100;

type ScoreType = typeof score;  // number

const myScore: ScoreType = 50;  // Valid
const invalidScore: ScoreType = "high";  // Error: Type 'string' is not assignable to type 'number'
```

- **Explanation**:
  - TypeScript infers that `score` is of type `number` because of the initial value `100`. `typeof score` then extracts that type.
  - The variable `invalidScore` causes an error because it tries to assign a `string` to a `number` type.

### **7. `typeof` with Indexed Access Types**

You can combine `typeof` with **indexed access types** to extract the type of a specific property from an object.

#### **Example: Using `typeof` with Indexed Access**
```typescript
const person = {
  name: "Alice",
  age: 25
};

type NameType = typeof person["name"];  // string
type AgeType = typeof person["age"];  // number

const personName: NameType = "Bob";  // Valid
const personAge: AgeType = 30;  // Valid
```

- **Explanation**:
  - `typeof person["name"]` extracts the type of the `name` property, which is `string`, and `typeof person["age"]` extracts the type of the `age` property, which is `number`.

### **8. Combining `typeof` with Generics**

You can combine `typeof` with **generic types** to refer to the type of a variable passed to a generic function.

#### **Example: `typeof` with Generics**
```typescript
function getProperty<T>(obj: T, key: keyof T) {
  return obj[key];
}

const person = { name: "Alice", age: 30 };

const personName = getProperty(person, "name");  // Type is string
const personAge = getProperty(person, "age");  // Type is number
```

- **Explanation**:
  - The `getProperty` function is generic, and the type `T` is inferred from the argument passed (`person`).
  - `keyof T` restricts the `key` to be one of the keys of `T`, and TypeScript automatically infers the correct type for the return value.

### **9. `typeof` and Type Narrowing**

The `typeof` operator can also be used in type narrowing to check the type of a variable at runtime.

#### **Example: Type Narrowing with `typeof`**
```typescript
function printLength(value: string | number) {
  if (typeof value === "string") {
    console.log(value.length);  // OK: value is narrowed to string
  } else {
    console.log(value.toFixed(2));  // OK: value is narrowed to number
  }
}

printLength("Hello");  // 5
printLength(123.456);  // 123.46
```

- **Explanation**:
  - The `typeof` operator narrows the type of `value` at runtime, so inside the `if` block, TypeScript knows that `value` is a `string`, and inside the `else` block, it is a `number`.

### **10. Conclusion**

The `typeof` operator in TypeScript is a powerful tool that allows you to:

- Extract the type of a variable or object.
- Use that type in type aliases, function signatures, and type assertions.
- Leverage type inference and narrowing techniques.

By using `typeof`, you can create more flexible and reusable code, improve type safety, and ensure that your code adheres to expected types.
