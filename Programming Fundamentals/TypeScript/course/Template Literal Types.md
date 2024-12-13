### TypeScript - Template Literal Types

**Template Literal Types** in TypeScript allow you to construct types using string templates, similar to how template literals work in JavaScript. These types provide a powerful way to create dynamic and reusable types based on string patterns, allowing you to express more precise type constraints and build flexible, type-safe APIs.

### **1. Basic Syntax of Template Literal Types**

Template literal types use the backtick syntax (`` ` ``) to interpolate types into strings, much like how JavaScript's template literals work with variables and expressions.

#### **Syntax:**
```typescript
type MyType = `${string} ${string}`;
```

- `${string}`: Represents a string literal type.
- You can use it to compose new string types dynamically.

### **2. Simple Example of Template Literal Types**

Let’s start with a basic example of using template literal types to construct a new string type.

#### **Example:**
```typescript
type Greeting = `Hello, ${string}`;

let greeting1: Greeting = "Hello, world";  // Valid
let greeting2: Greeting = "Hello, TypeScript";  // Valid
let greeting3: Greeting = "Hi, world";  // Error: Type 'Hi, world' is not assignable to type 'Hello, string'
```

- **Explanation**:
  - The `Greeting` type represents any string that starts with `"Hello, "`, followed by any string.
  - `greeting1` and `greeting2` are valid because they match the pattern `"Hello, <anything>"`, but `greeting3` is invalid because it does not start with `"Hello, "`.

### **3. Template Literal Types with Specific String Values**

You can define more specific string patterns using template literal types by combining string literals and variable parts.

#### **Example:**
```typescript
type Direction = "North" | "South" | "East" | "West";
type Compass = `Go ${Direction}`;

let direction1: Compass = "Go North";  // Valid
let direction2: Compass = "Go South";  // Valid
let direction3: Compass = "Go Up";  // Error: Type 'Go Up' is not assignable to type 'Go North' | 'Go South' | 'Go East' | 'Go West'
```

- **Explanation**:
  - The `Compass` type represents any string that starts with `"Go "` followed by one of the values from the `Direction` union (`"North" | "South" | "East" | "West"`).
  - `direction1` and `direction2` are valid because they match the pattern, but `direction3` is invalid because `"Go Up"` is not part of the `Direction` union.

### **4. Template Literal Types with Number Interpolation**

You can also combine template literals with numbers, creating patterns for numeric strings.

#### **Example:**
```typescript
type OrderNumber = `${number}-order`;

let order1: OrderNumber = "123-order";  // Valid
let order2: OrderNumber = "456-order";  // Valid
let order3: OrderNumber = "order-123";  // Error: Type 'order-123' is not assignable to type 'number-order'
```

- **Explanation**:
  - `OrderNumber` allows any string that follows the pattern `<number>-order`.
  - `order1` and `order2` are valid because they match the pattern, but `order3` is invalid because the number must precede `"-order"`.

### **5. Combining Multiple Template Literal Types**

You can combine multiple parts with template literal types, making them flexible for more complex string patterns.

#### **Example:**
```typescript
type UserName = `${string}-${number}`;
type Product = `${string}-${string}-${string}`;

let user1: UserName = "john-123";  // Valid
let product1: Product = "shirt-red-medium";  // Valid
let invalidUser: UserName = "john-abc";  // Error: Type 'john-abc' is not assignable to type 'string-number'
```

- **Explanation**:
  - `UserName` represents any string that follows the pattern `<string>-<number>`, and `Product` represents a string in the format `<string>-<string>-<string>`.
  - `user1` and `product1` are valid because they match their respective patterns, but `invalidUser` is invalid because it doesn't match the required pattern of a number after the hyphen.

### **6. Template Literal Types with Conditional Logic**

You can combine template literal types with **conditional types** to create more complex patterns that depend on conditions.

#### **Example:**
```typescript
type ConditionalString<T extends string> = T extends "admin" ? `Hello, ${T}` : `${T}, welcome!`;

let user1: ConditionalString<"admin"> = "Hello, admin";  // Valid
let user2: ConditionalString<"user"> = "user, welcome!";  // Valid
let user3: ConditionalString<"guest"> = "Hello, guest";  // Error: Type 'Hello, guest' is not assignable to type 'guest, welcome!'
```

- **Explanation**:
  - `ConditionalString<T>` creates a type where if `T` is `"admin"`, the string must start with `"Hello, admin"`. Otherwise, it must follow the pattern `<T>, welcome!`.
  - `user1` and `user2` are valid, but `user3` is invalid because it does not match the expected string pattern.

### **7. Template Literal Types with Object Keys**

You can use template literal types to create new types based on the keys of an object.

#### **Example:**
```typescript
type Colors = "red" | "green" | "blue";
type ColorObject = { [K in `${Colors}Color`]: string };

const colorObject: ColorObject = {
  redColor: "red",
  greenColor: "green",
  blueColor: "blue"
};
```

- **Explanation**:
  - The type `ColorObject` uses a template literal type for its keys, combining each color in `Colors` with the string `"Color"`.
  - The resulting type requires keys like `redColor`, `greenColor`, and `blueColor`, with string values.

### **8. Template Literal Types for Path Construction**

Template literal types are useful for constructing paths or URLs dynamically, especially when you have a predefined set of values.

#### **Example:**
```typescript
type Route = "home" | "about" | "contact";
type URL = `/page/${Route}`;

let route1: URL = "/page/home";  // Valid
let route2: URL = "/page/about";  // Valid
let route3: URL = "/page/other";  // Error: Type '/page/other' is not assignable to type '/page/home' | '/page/about' | '/page/contact'
```

- **Explanation**:
  - The `URL` type represents a string that starts with `"/page/"` followed by one of the values in the `Route` union (`"home"`, `"about"`, or `"contact"`).
  - `route1` and `route2` are valid, but `route3` is invalid because `"other"` is not part of the `Route` union.

### **9. Template Literal Types for Literal Key Construction**

Template literal types are also useful for constructing keys dynamically, where the keys have certain constraints.

#### **Example:**
```typescript
type Action = "create" | "update" | "delete";
type ActionTypes = `${Action}Action`;

let createAction: ActionTypes = "createAction";  // Valid
let updateAction: ActionTypes = "updateAction";  // Valid
let invalidAction: ActionTypes = "editAction";  // Error: Type 'editAction' is not assignable to type 'createAction' | 'updateAction' | 'deleteAction'
```

- **Explanation**:
  - The type `ActionTypes` is a template literal type that creates keys like `"createAction"`, `"updateAction"`, and `"deleteAction"` by combining an action with the string `"Action"`.
  - `createAction` and `updateAction` are valid, but `invalidAction` is invalid because `"editAction"` is not part of the predefined types.

### **10. Conclusion**

Template literal types in TypeScript are a powerful feature that enables dynamic and flexible type creation using string patterns. Some key takeaways:

- **Dynamic Type Construction**: Use template literal types to construct new types by combining string literals and variable parts, making your types more flexible and reusable.
- **Precise String Matching**: You can enforce specific string patterns in your types, which allows for more type-safe and robust code.
- **Combining with Other Features**: Template literal types can be used with conditional types, unions, intersections, and more, allowing you to define complex patterns for your types.
- **Useful for URLs, Routes, and Keys**: They are particularly useful for constructing paths, URLs, object keys, and other string patterns in your code.

By using template literal types, you can express constraints on string values more precisely and create more dynamic, flexible, and type-safe APIs in your TypeScript code.
