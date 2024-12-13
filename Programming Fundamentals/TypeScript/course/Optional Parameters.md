### TypeScript - Optional Parameters

In TypeScript, **optional parameters** allow you to define parameters that may or may not be passed when calling a function. Optional parameters are denoted by appending a `?` to the parameter name. When you define a parameter as optional, TypeScript ensures that the parameter is either provided or left out, and the function will still work correctly.

### **Syntax for Optional Parameters**

```typescript
function functionName(param1: type, param2?: type): returnType {
  // function body
}
```

- **`param2?: type`**: The `?` after `param2` indicates that this parameter is optional. This means the function can be called with or without `param2`.

### **Example 1: Function with Optional Parameter**

```typescript
function greet(name: string, age?: number): string {
  if (age) {
    return `Hello, ${name}. You are ${age} years old.`;
  } else {
    return `Hello, ${name}.`;
  }
}

console.log(greet("Alice"));        // Output: Hello, Alice.
console.log(greet("Bob", 30));      // Output: Hello, Bob. You are 30 years old.
```

- **Explanation**:
  - In this example, `age` is an optional parameter. If it is not provided, the function still works, just omitting the age part of the message.
  - The `greet` function can be called with just `name`, or with both `name` and `age`.

### **Example 2: Optional Parameter with Default Value**

You can also provide a **default value** for optional parameters. If the argument is not passed, the default value will be used.

```typescript
function greet(name: string, age: number = 25): string {
  return `Hello, ${name}. You are ${age} years old.`;
}

console.log(greet("Alice"));        // Output: Hello, Alice. You are 25 years old.
console.log(greet("Bob", 30));      // Output: Hello, Bob. You are 30 years old.
```

- **Explanation**:
  - In this case, if the `age` parameter is not provided, it defaults to `25`.

### **Example 3: Multiple Optional Parameters**

You can have multiple optional parameters in a function.

```typescript
function describePerson(name: string, age?: number, city?: string): string {
  let description = `Name: ${name}`;
  
  if (age) {
    description += `, Age: ${age}`;
  }
  
  if (city) {
    description += `, City: ${city}`;
  }
  
  return description;
}

console.log(describePerson("Alice"));                 // Output: Name: Alice
console.log(describePerson("Bob", 30));               // Output: Name: Bob, Age: 30
console.log(describePerson("Charlie", 25, "Paris"));  // Output: Name: Charlie, Age: 25, City: Paris
```

- **Explanation**:
  - Both `age` and `city` are optional. The function constructs the description string only if the corresponding parameter is passed.

### **Important Notes about Optional Parameters**

1. **Optional Parameters Must Be Last**:
   In TypeScript, all optional parameters must be placed after required parameters in the function signature. This is because if an optional parameter appears before a required one, it would not be clear which parameters are omitted.

   ```typescript
   // Correct:
   function greet(name: string, age?: number): string { ... }

   // Incorrect:
   function greet(age?: number, name: string): string { ... }  // Error: Optional parameters must follow required ones
   ```

2. **`undefined` and `null`**:
   - If an optional parameter is not passed, it is treated as `undefined`. However, `null` is not automatically treated as `undefined`, so if you explicitly pass `null` as the argument, it will be treated as a valid value for the parameter.

   ```typescript
   function greet(name: string, age?: number): string {
     if (age === undefined) {
       return `Hello, ${name}. Age is not provided.`;
     }
     return `Hello, ${name}. You are ${age} years old.`;
   }

   console.log(greet("Alice"));        // Output: Hello, Alice. Age is not provided.
   console.log(greet("Bob", null));    // Output: Hello, Bob. You are null years old.
   ```

3. **Type Inference with Optional Parameters**:
   TypeScript can infer that an optional parameter may be `undefined`. Therefore, the type of an optional parameter is automatically considered to be a union of the specified type and `undefined`.

   ```typescript
   function greet(name: string, age?: number): string {
     return age ? `Hello, ${name}. You are ${age} years old.` : `Hello, ${name}.`;
   }

   let age: number | undefined;
   console.log(greet("Alice", age));  // Output: Hello, Alice.
   ```

   - **Explanation**:
     - The type of `age` is inferred as `number | undefined`, which means `age` can either be a `number` or `undefined` when it's not provided.

### **Example 4: Function Type with Optional Parameters**

When defining function types with optional parameters, the same rules apply. Here’s how to define a function type with optional parameters:

```typescript
type GreetFunction = (name: string, age?: number) => string;

let greet: GreetFunction = (name, age) => {
  return age ? `Hello, ${name}. You are ${age} years old.` : `Hello, ${name}.`;
};

console.log(greet("Alice"));       // Output: Hello, Alice.
console.log(greet("Bob", 30));     // Output: Hello, Bob. You are 30 years old.
```

- **Explanation**:
  - The `GreetFunction` type allows for an optional `age` parameter, so you can call the function with just a `name` or both `name` and `age`.

### **Summary of Optional Parameters in TypeScript**

1. **Syntax**: Optional parameters are denoted by adding a `?` after the parameter name.
2. **Default Values**: Optional parameters can also have default values, which are used when the parameter is not passed.
3. **Placement**: Optional parameters must appear after required parameters in the function signature.
4. **Type Inference**: TypeScript infers that optional parameters can be `undefined`.
5. **Function Types**: You can define function types with optional parameters using the same `?` syntax.

Optional parameters allow flexibility in function calls and help you write functions that are adaptable to different use cases without needing to specify every parameter each time.
