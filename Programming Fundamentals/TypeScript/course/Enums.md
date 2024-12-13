### TypeScript - Enums

In TypeScript, **enums** are a way to define a set of named constants. They are useful when you have a collection of related values that should be represented as a set of distinct options, making the code more readable and less error-prone. Enums can be used to represent options like days of the week, states of a process, colors, and other such groupings.

There are several types of enums in TypeScript, and they are categorized based on the kind of value they represent: numeric enums, string enums, and heterogeneous enums.

---

### 1. **Numeric Enums**

By default, TypeScript enums are **numeric enums**, where each member is assigned an incrementing numeric value starting from `0`. You can specify the value of the first member, and subsequent members will automatically increment from that value.

#### Example: Numeric Enum

```typescript
enum Direction {
  Up,      // 0
  Down,    // 1
  Left,    // 2
  Right    // 3
}

let direction: Direction = Direction.Up;
console.log(direction);  // Output: 0
```

- By default, `Direction.Up` will be assigned the value `0`, `Direction.Down` will be assigned `1`, and so on.
- Enums are useful when you need to represent a collection of related values and you want to work with both their names and corresponding values.

#### Example: Specifying the Starting Value

```typescript
enum Direction {
  Up = 1,
  Down,    // 2
  Left,    // 3
  Right    // 4
}

console.log(Direction.Up);    // Output: 1
console.log(Direction.Left);  // Output: 3
```

- You can specify the first value (`Up = 1`), and the subsequent values will be automatically incremented by `1`.

#### Example: Reversing Numeric Enums

Numeric enums allow you to map values back to their names using reverse mapping.

```typescript
enum Direction {
  Up = 1,
  Down,
  Left,
  Right
}

let directionName: string = Direction[2];  // Output: "Down"
console.log(directionName);  // "Down"
```

- **Reverse mapping** allows you to use the numeric value to get the name of the enum.

---

### 2. **String Enums**

In addition to numeric enums, TypeScript also supports **string enums**, where each member of the enum is assigned a string value. This is useful when the values in the enum are better represented as strings (e.g., for status codes, API responses, etc.).

#### Example: String Enum

```typescript
enum Status {
  Success = "SUCCESS",
  Failure = "FAILURE",
  Pending = "PENDING"
}

let currentStatus: Status = Status.Success;
console.log(currentStatus);  // Output: "SUCCESS"
```

- Each member of the `Status` enum has an explicit string value.
- String enums provide better readability and are useful when you need to represent statuses or labels that are strings rather than numbers.

---

### 3. **Heterogeneous Enums**

TypeScript allows you to mix string and numeric values in an enum, although this is generally discouraged because it can lead to confusion. These are called **heterogeneous enums**.

#### Example: Heterogeneous Enum

```typescript
enum MixedEnum {
  No = 0,
  Yes = "YES"
}

let answer: MixedEnum = MixedEnum.Yes;
console.log(answer);  // Output: "YES"
```

- **`No`** has a numeric value of `0`, and **`Yes`** has a string value `"YES"`.
- While possible, it's not common to mix string and numeric values in an enum because it can be confusing.

---

### 4. **Enum with Computed Members**

You can also assign computed values to enums, though TypeScript will only allow constant expressions (i.e., expressions that are evaluated at compile time).

#### Example: Computed Enum Values

```typescript
enum FileAccess {
  Read = 1,
  Write = Read * 2,    // 2
  Execute = Write * 2  // 4
}

console.log(FileAccess.Read);     // Output: 1
console.log(FileAccess.Write);    // Output: 2
console.log(FileAccess.Execute);  // Output: 4
```

- **`Write`** and **`Execute`** are computed based on the values of the previous enum members.

---

### 5. **Enum with Constant Members**

In TypeScript, you can also have **constant** enum members that are evaluated at compile-time for performance optimizations. You can declare a constant enum with the `const` keyword.

#### Example: Constant Enums

```typescript
const enum Direction {
  Up = 1,
  Down,
  Left,
  Right
}

let direction: Direction = Direction.Up;
console.log(direction);  // Output: 1
```

- `const enum` is a compile-time feature, meaning the enum values are inlined at the places where they are used, making the code more optimized.

- **`const enum`** is used when you want better performance in situations where you don’t need the enum to be available at runtime (i.e., you don’t need to perform reverse mapping or use reflection).

---

### 6. **Using Enums**

Enums are useful in various situations such as:
- **Switch statements**: Enums provide a clean way to write conditional logic based on a fixed set of options.
- **Configuring options**: You can use enums for configurations, such as setting user roles or error codes.
- **Readable and self-documenting code**: Enums give descriptive names to numeric or string values, making the code more readable.

#### Example: Using Enums in a Switch Statement

```typescript
enum Status {
  Success = "SUCCESS",
  Failure = "FAILURE",
  Pending = "PENDING"
}

function handleStatus(status: Status) {
  switch (status) {
    case Status.Success:
      console.log("Operation was successful.");
      break;
    case Status.Failure:
      console.log("Operation failed.");
      break;
    case Status.Pending:
      console.log("Operation is pending.");
      break;
  }
}

handleStatus(Status.Success);  // Output: "Operation was successful."
```

- In this example, the `handleStatus()` function uses a `switch` statement to check the value of the `Status` enum and execute appropriate logic based on the value.

---

### 7. **Enum as Types**

You can also use enums as types to restrict the allowed values for a variable to one of the members of the enum.

#### Example: Using Enum as a Type

```typescript
enum Direction {
  Up = 1,
  Down,
  Left,
  Right
}

let move: Direction = Direction.Up;  // Correct
// let move: Direction = 5;  // Error: Type '5' is not assignable to type 'Direction'
```

- Using enums as types ensures that only valid enum members are assigned to variables, providing better type safety.

---

### 8. **Enum as a Type Guard**

You can create a **type guard** to check whether a given value is a valid enum member.

#### Example: Enum Type Guard

```typescript
enum Direction {
  Up = 1,
  Down,
  Left,
  Right
}

function isValidDirection(value: any): value is Direction {
  return Object.values(Direction).includes(value);
}

let direction: any = 1;

if (isValidDirection(direction)) {
  console.log("Valid direction:", direction);  // "Valid direction: 1"
} else {
  console.log("Invalid direction");
}
```

- The `isValidDirection` function ensures that the value passed is a valid member of the `Direction` enum.

---

### Conclusion

Enums in TypeScript provide a powerful way to represent a set of related constants with strong type safety. You can use numeric enums, string enums, and heterogeneous enums depending on the type of data you need to represent. Enums also support features like reverse mapping, constant members, computed values, and more. They're ideal for making your code more readable, maintainable, and type-safe.
