### TypeScript - Type Guards

**Type Guards** in TypeScript are techniques that allow you to narrow the type of a variable within a conditional block. They help TypeScript infer more specific types based on runtime checks, improving type safety and enabling more accurate code completion and error detection.

A type guard is any expression that narrows the type of a variable inside a conditional block, giving TypeScript more specific information about what type the variable is at that point in the code.

### **1. Basic Concept of Type Guards**

TypeScript allows you to write conditions that check the type of a variable and, based on that condition, narrows down the type of that variable. The type is narrowed inside the block that follows the type guard.

#### **Example: Using `typeof` for Type Guards**
One common type guard is using the `typeof` operator to check the type of a variable.

```typescript
function isString(value: any): boolean {
  return typeof value === "string";
}

let testValue: any = "Hello, TypeScript";

if (isString(testValue)) {
  console.log(testValue.toUpperCase()); // No error: testValue is inferred as a string
} else {
  console.log("Not a string.");
}
```

- **Explanation**: Inside the `if` block, TypeScript knows that `testValue` is a `string` because of the `typeof` check, and therefore, we can safely call `toUpperCase()` on it.
- The type guard function `isString` helps to narrow the type of `testValue` to `string` within the `if` block.

### **2. Type Guards with `instanceof`**

The `instanceof` operator is another type guard, typically used for checking whether an object is an instance of a particular class or subclass.

#### **Example: Using `instanceof` for Type Guards**

```typescript
class Dog {
  bark() {
    console.log("Woof!");
  }
}

class Cat {
  meow() {
    console.log("Meow!");
  }
}

function handleAnimal(animal: Dog | Cat) {
  if (animal instanceof Dog) {
    animal.bark();  // TypeScript knows `animal` is of type `Dog`
  } else if (animal instanceof Cat) {
    animal.meow();  // TypeScript knows `animal` is of type `Cat`
  }
}

let myPet = new Dog();
handleAnimal(myPet);  // Output: Woof!
```

- **Explanation**: The `instanceof` operator checks whether the `animal` is an instance of `Dog` or `Cat`. Based on the result, TypeScript narrows the type and allows us to call methods specific to each class.

### **3. User-defined Type Guards**

A user-defined type guard is a custom function that tells TypeScript how to narrow the type of a variable. This is done by defining a function that returns a type predicate (a boolean expression that also informs TypeScript about the type inside a conditional block).

#### **Example: Creating a User-defined Type Guard**

```typescript
interface Fish {
  swim(): void;
}

interface Bird {
  fly(): void;
}

function isFish(animal: Fish | Bird): animal is Fish {
  return (animal as Fish).swim !== undefined;
}

function move(animal: Fish | Bird) {
  if (isFish(animal)) {
    animal.swim();  // animal is narrowed to type `Fish`
  } else {
    animal.fly();   // animal is narrowed to type `Bird`
  }
}

let fish: Fish = { swim: () => console.log("Swimming!") };
let bird: Bird = { fly: () => console.log("Flying!") };

move(fish);  // Output: Swimming!
move(bird);  // Output: Flying!
```

- **Explanation**: The `isFish` function is a user-defined type guard. It checks whether an object has the `swim` method (which is a characteristic of a `Fish`).
- The return type of `isFish` is `animal is Fish`, which is a type predicate indicating that if `isFish(animal)` returns `true`, then the type of `animal` inside the `if` block is `Fish`.

### **4. Type Guards with `in` Operator**

The `in` operator can also be used to narrow types. It checks whether an object has a specific property. This can be particularly useful for distinguishing between object types in a union.

#### **Example: Using `in` for Type Guards**

```typescript
interface Car {
  drive(): void;
}

interface Boat {
  sail(): void;
}

function moveVehicle(vehicle: Car | Boat) {
  if ("drive" in vehicle) {
    vehicle.drive();  // `vehicle` is of type `Car`
  } else {
    vehicle.sail();   // `vehicle` is of type `Boat`
  }
}

let car: Car = { drive: () => console.log("Driving!") };
let boat: Boat = { sail: () => console.log("Sailing!") };

moveVehicle(car);  // Output: Driving!
moveVehicle(boat); // Output: Sailing!
```

- **Explanation**: The `in` operator checks if the `vehicle` has a `drive` property. If true, the type of `vehicle` is narrowed to `Car`; otherwise, it’s treated as a `Boat`.

### **5. Type Guards with Literal Types**

You can also use literal types to narrow the type of a variable. This is useful when you are working with union types consisting of specific literal values.

#### **Example: Using Literal Types as Type Guards**

```typescript
type Color = "red" | "green" | "blue";

function printColor(color: Color) {
  if (color === "red") {
    console.log("Color is red");
  } else if (color === "green") {
    console.log("Color is green");
  } else {
    console.log("Color is blue");
  }
}

let myColor: Color = "green";
printColor(myColor);  // Output: Color is green
```

- **Explanation**: The type guard `color === "red"` narrows the type of `color` to the literal type `"red"`, ensuring that the correct logic runs based on the value of `color`.

### **6. Return Types and Type Narrowing**

Type guards are often used in conjunction with return types to narrow down types in functions. TypeScript can infer the correct type in the scope of a conditional block when using type guards, which helps prevent errors.

#### **Example: Type Guards with Return Types**

```typescript
function process(value: string | number) {
  if (typeof value === "string") {
    return value.toUpperCase();  // Narrowed to string
  } else {
    return value.toFixed(2);      // Narrowed to number
  }
}

let result = process(10);
console.log(result);  // Output: 10.00

let result2 = process("hello");
console.log(result2); // Output: HELLO
```

- **Explanation**: The `typeof` operator narrows the type of `value` inside the `if` and `else` blocks, enabling the correct methods to be called (`toUpperCase` for `string` and `toFixed` for `number`).

### **7. Summary of Type Guard Techniques**

1. **`typeof`**: Used to narrow primitive types (`string`, `number`, `boolean`, etc.).
2. **`instanceof`**: Used to narrow object types or classes.
3. **User-defined Type Guards**: Functions that return a type predicate (`value is Type`), providing custom type narrowing.
4. **`in`**: Used to check whether an object has a specific property, helping to distinguish between types that share some common properties.
5. **Literal Types**: Using direct value checks to narrow union types consisting of specific literal values.

### **Conclusion**

Type Guards are a powerful feature in TypeScript that enable you to narrow types based on runtime checks, leading to more accurate type inference and better type safety. By using operators like `typeof`, `instanceof`, `in`, and custom user-defined guards, TypeScript can intelligently narrow the type of a variable, allowing you to safely interact with variables and avoid runtime errors.
