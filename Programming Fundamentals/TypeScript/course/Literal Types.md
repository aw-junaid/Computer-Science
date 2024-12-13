### TypeScript - Literal Types

In TypeScript, **literal types** allow you to specify exact values that a variable can hold, rather than just a broader type like `string`, `number`, or `boolean`. Literal types are a powerful feature that provides more precise control over the values assigned to variables, function parameters, and return types.

A literal type is essentially a type that represents a specific value rather than a general type. It can be used for strings, numbers, booleans, or other types where you want to restrict the possible values to a particular set.

---

### 1. **String Literal Types**

A string literal type restricts the variable to hold only a specific string value.

#### Example: String Literal Type

```typescript
let direction: "up" | "down" | "left" | "right";
direction = "up";    // OK
direction = "down";  // OK
direction = "north"; // Error: Type '"north"' is not assignable to type '"up" | "down" | "left" | "right"'
```

- The `direction` variable is restricted to only the strings `"up"`, `"down"`, `"left"`, or `"right"`. Any other string value will result in an error.

---

### 2. **Numeric Literal Types**

Numeric literal types work similarly to string literals but apply to numbers. You can specify a specific number a variable can hold.

#### Example: Numeric Literal Type

```typescript
let age: 18 | 21 | 30;
age = 18;  // OK
age = 21;  // OK
age = 25;  // Error: Type '25' is not assignable to type '18 | 21 | 30'
```

- The `age` variable can only have the values `18`, `21`, or `30`. Any other number will result in a type error.

---

### 3. **Boolean Literal Types**

You can also define boolean literal types, although it's more common to use the general `boolean` type. But for specific control, you can restrict a variable to just `true` or `false`.

#### Example: Boolean Literal Type

```typescript
let isActive: true;
isActive = true;  // OK
isActive = false; // Error: Type 'false' is not assignable to type 'true'
```

- The `isActive` variable is restricted to the value `true`. If you try to assign `false`, TypeScript will throw an error.

---

### 4. **Literal Types with Objects**

You can use literal types in **object properties** to specify that a particular property must have a specific value.

#### Example: Literal Types in Object Properties

```typescript
type Status = {
  state: "active" | "inactive" | "pending";
};

let userStatus: Status = { state: "active" }; // OK
userStatus.state = "inactive";  // OK
userStatus.state = "completed"; // Error: Type '"completed"' is not assignable to type '"active" | "inactive" | "pending"'
```

- The `state` property of `userStatus` can only be `"active"`, `"inactive"`, or `"pending"`. Any other string value (like `"completed"`) will cause an error.

---

### 5. **Combining Literal Types with Other Types**

You can combine literal types with other types to define more complex structures. For instance, you can use unions of literal types, or combine literal types with more general types (like `string` or `number`).

#### Example: Combining Literal and General Types

```typescript
type Button = {
  label: string;
  disabled: true | false;  // Boolean literal type
};

let submitButton: Button = { label: "Submit", disabled: false }; // OK
let cancelButton: Button = { label: "Cancel", disabled: true }; // OK
```

- The `disabled` property in this example can only be `true` or `false`, while the `label` property can hold any string.

---

### 6. **Literal Types in Function Parameters**

You can also use literal types in **function parameters** to restrict the allowed values passed to the function.

#### Example: Literal Types in Function Parameters

```typescript
function setStatus(status: "loading" | "success" | "error"): void {
  console.log(`Status: ${status}`);
}

setStatus("loading");  // OK
setStatus("success");  // OK
setStatus("fail");     // Error: Argument of type '"fail"' is not assignable to parameter of type '"loading" | "success" | "error"'
```

- The `setStatus` function accepts only the literal string values `"loading"`, `"success"`, or `"error"`. Any other string will result in a compile-time error.

---

### 7. **Literal Types for Enums and Tagged Unions**

Literal types can be used in combination with **enums** or **tagged unions** (discriminated unions) to give more precise type control over possible values.

#### Example: Literal Types with Enums

```typescript
enum OrderStatus {
  Pending = "pending",
  Shipped = "shipped",
  Delivered = "delivered",
}

function trackOrder(status: OrderStatus): void {
  console.log(`Order status is: ${status}`);
}

trackOrder(OrderStatus.Shipped); // OK
trackOrder("shipped");           // Error: Type '"shipped"' is not assignable to type 'OrderStatus'
```

- In this example, `OrderStatus` is an enum with literal string values, and the `trackOrder` function only accepts these specific values as valid arguments.

---

### 8. **Literal Types in Unions**

Literal types are commonly used in **union types** to restrict a value to one of several specific values.

#### Example: Literal Types in Union Types

```typescript
type Direction = "up" | "down" | "left" | "right";

function move(direction: Direction): void {
  console.log(`Moving ${direction}`);
}

move("up");    // OK
move("left");  // OK
move("back");  // Error: Type '"back"' is not assignable to type 'Direction'
```

- The `move` function only accepts the literal values `"up"`, `"down"`, `"left"`, or `"right"`. It will throw an error if you attempt to pass a value like `"back"`.

---

### 9. **Literal Types with `as const`**

When you want to create a **literal type** from a value, you can use the `as const` assertion. This will treat the value as a constant and automatically infer its literal type.

#### Example: Using `as const` for Literal Types

```typescript
let userStatus = { status: "active" } as const;

userStatus.status = "inactive"; // Error: Type '"inactive"' is not assignable to type '"active"'
```

- By using `as const`, TypeScript infers the type of `status` as the literal type `"active"` instead of just `string`. This prevents the value from being changed to anything other than `"active"`.

---

### 10. **Advantages of Literal Types**

- **Type Safety**: By restricting variables or parameters to specific values, you reduce the risk of errors due to unexpected values being assigned.
- **Autocompletion**: Using literal types in code provides better autocompletion and type checking, making your code more predictable and easier to maintain.
- **Documentation**: Literal types can serve as a form of documentation, making the intended values clear to other developers reading the code.

---

### 11. **Summary**

- **String Literal Types**: Limit a variable to a specific string value.
- **Numeric Literal Types**: Limit a variable to a specific numeric value.
- **Boolean Literal Types**: Restrict a variable to the exact boolean value `true` or `false`.
- **Combining Literals with Other Types**: Use literal types in combination with other types like `string` or `number` for more complex definitions.
- **Function Parameters**: Restrict the input to a specific set of values.
- **Enums and Tagged Unions**: Literal types are commonly used in enums or discriminated unions to restrict values to a specific set.

By using literal types, TypeScript allows you to create more precise and controlled types, enhancing the safety and maintainability of your code.
