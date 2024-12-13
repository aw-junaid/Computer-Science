### TypeScript - Default Parameters

In TypeScript, **default parameters** allow you to specify a default value for a parameter if no argument is passed for that parameter when calling the function. This ensures that the parameter has a valid value, even if it's omitted, making the function call more flexible and reducing the need for extra checks inside the function body.

### **Syntax for Default Parameters**

You can provide a default value for a parameter by using the assignment (`=`) operator in the function signature.

```typescript
function functionName(param1: type = defaultValue): returnType {
  // function body
}
```

- **`param1: type = defaultValue`**: The `=` sign assigns a default value to the parameter if no value is provided when the function is called.

### **Example 1: Basic Default Parameter**

```typescript
function greet(name: string, age: number = 30): string {
  return `Hello, ${name}. You are ${age} years old.`;
}

console.log(greet("Alice"));        // Output: Hello, Alice. You are 30 years old.
console.log(greet("Bob", 25));      // Output: Hello, Bob. You are 25 years old.
```

- **Explanation**:
  - In this example, if the `age` parameter is not passed when calling the function, it defaults to `30`. If `age` is provided, that value will be used.

### **Example 2: Default Parameter with Different Data Types**

You can use default parameters with various types such as `number`, `string`, `boolean`, or even more complex types.

```typescript
function logMessage(message: string, prefix: string = "Info"): void {
  console.log(`${prefix}: ${message}`);
}

logMessage("System is running");        // Output: Info: System is running
logMessage("System is down", "Error");  // Output: Error: System is down
```

- **Explanation**:
  - The `prefix` parameter is optional. If it’s not provided, it defaults to `"Info"`. If supplied, the function uses the provided value.

### **Example 3: Default Parameter with Expressions**

You can also assign default values using expressions or even functions.

```typescript
function calculateTotal(price: number, taxRate: number = 0.05): number {
  return price + (price * taxRate);
}

console.log(calculateTotal(100));         // Output: 105 (default tax rate of 5%)
console.log(calculateTotal(100, 0.1));    // Output: 110 (custom tax rate of 10%)
```

- **Explanation**:
  - The `taxRate` parameter defaults to `0.05` (5%), but you can override it by passing a different value when calling the function.

### **Example 4: Multiple Parameters with Default Values**

You can define multiple parameters with default values.

```typescript
function createUser(username: string, role: string = "user", isActive: boolean = true): string {
  return `User: ${username}, Role: ${role}, Active: ${isActive}`;
}

console.log(createUser("alice"));               // Output: User: alice, Role: user, Active: true
console.log(createUser("bob", "admin"));         // Output: User: bob, Role: admin, Active: true
console.log(createUser("charlie", "guest", false));  // Output: User: charlie, Role: guest, Active: false
```

- **Explanation**:
  - Here, `role` and `isActive` have default values. If not provided, `role` will default to `"user"`, and `isActive` will default to `true`.

### **Example 5: Default Parameters with Functions**

You can even use functions as default values for parameters.

```typescript
function getCurrentYear(defaultYear: number = new Date().getFullYear()): number {
  return defaultYear;
}

console.log(getCurrentYear());         // Output: Current year, e.g., 2024
console.log(getCurrentYear(2023));     // Output: 2023
```

- **Explanation**:
  - The default value for `defaultYear` is set to the current year using `new Date().getFullYear()`. If no argument is provided, the function uses this default value.

### **Important Points about Default Parameters**

1. **Default Parameters Can Be Used with Optional Parameters**:
   Default parameters and optional parameters can be combined. If a parameter has both `?` (optional) and `=` (default value), the default value will be used when the parameter is not provided.

   ```typescript
   function greet(name: string, age?: number, country: string = "USA"): string {
     return `Hello, ${name}. Age: ${age ?? "N/A"}, Country: ${country}.`;
   }

   console.log(greet("Alice"));                // Output: Hello, Alice. Age: N/A, Country: USA.
   console.log(greet("Bob", 30));              // Output: Hello, Bob. Age: 30, Country: USA.
   console.log(greet("Charlie", undefined, "Canada"));  // Output: Hello, Charlie. Age: N/A, Country: Canada.
   ```

   - **Explanation**:
     - `country` has a default value, but `age` is optional.
     - If no value for `age` is passed, it will be treated as `undefined`, and the default for `country` is applied.

2. **Order of Parameters**:
   In TypeScript, parameters with default values should be placed after required parameters. This is because, when calling a function, you can't skip a parameter and expect the next one to be used as a default.

   ```typescript
   // Correct:
   function greet(name: string, age: number = 30): string { ... }

   // Incorrect: This will result in an error.
   function greet(age: number = 30, name: string): string { ... }
   ```

   - **Explanation**:
     - The parameter with the default value must appear after the required parameters in the function signature.

3. **Default Parameters Are Evaluated at Call Time**:
   Default parameter values are evaluated each time the function is called, not at the time of definition. This means if the default value involves a function call or computation, it will be re-evaluated every time the function is called.

   ```typescript
   function randomGreeting(message: string, greeting: string = Math.random() > 0.5 ? "Hello" : "Hi"): string {
     return `${greeting}, ${message}!`;
   }

   console.log(randomGreeting("Alice"));  // Output: either "Hello, Alice!" or "Hi, Alice!" depending on random evaluation
   ```

### **Summary of Default Parameters in TypeScript**

1. **Default Values**: You can specify default values for parameters using the `=` operator.
2. **Flexibility**: If an argument is not provided, the default value will be used, making your functions more flexible.
3. **Order of Parameters**: Default parameters must come after required parameters in the function signature.
4. **Default Parameter Types**: Default parameters can use any valid type, including strings, numbers, booleans, or even functions.
5. **Evaluation at Call Time**: Default values are evaluated every time the function is called, not when the function is defined.

Default parameters are a powerful feature in TypeScript that allows you to make your functions more robust and easier to use without forcing users to pass every argument each time they call the function.
