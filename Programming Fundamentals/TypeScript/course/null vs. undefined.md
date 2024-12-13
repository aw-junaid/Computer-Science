### TypeScript - `null` vs. `undefined`

In TypeScript, **`null`** and **`undefined`** are two distinct types that are often used to represent the absence of a value. Although they are related, they have different meanings and are treated differently in TypeScript.

#### **1. `null`**
- `null` is a special value that represents the intentional absence of any object value. It is an object type in JavaScript (though this is considered a historical bug).
- In TypeScript, `null` is treated as a **type** and can be explicitly assigned to variables, usually indicating that a variable will later hold an object, but is currently not initialized.

#### **2. `undefined`**
- `undefined` is a primitive value that represents the absence of a defined value. It typically means a variable has been declared but has not yet been assigned a value.
- In TypeScript, `undefined` is the default value for uninitialized variables or function parameters that have not been provided a value.

---

### **Key Differences**

| Feature                 | `null`                                      | `undefined`                                  |
|-------------------------|---------------------------------------------|----------------------------------------------|
| **Meaning**             | Represents an intentional absence of a value (usually an object). | Represents an uninitialized or undefined value. |
| **Type**                | `null` is its own type.                     | `undefined` is its own type.                 |
| **Default value**       | Not assigned by default.                    | Default value for uninitialized variables or missing function arguments. |
| **Common use**          | Used when you want to explicitly indicate that a value is absent or unknown (e.g., object properties that are missing). | Typically used by JavaScript when a variable is declared but not assigned a value, or a function parameter is not provided. |
| **Equality (`==`)**     | `null == undefined` is `true`.              | `undefined == null` is `true`.               |
| **Strict Equality (`===`)** | `null === null` is `true`.             | `undefined === undefined` is `true`.         |
| **Assignability**       | Can be assigned to any variable of type `null`. | Can be assigned to any variable of type `undefined`. |

---

### **Examples**

#### **`null` Example**

```typescript
let person: string | null = null;

if (person === null) {
  console.log("The person is absent.");
} else {
  console.log(person);
}
```

- In this example, `person` is explicitly set to `null` to represent that the person's name is intentionally absent.

#### **`undefined` Example**

```typescript
let personName: string;

if (personName === undefined) {
  console.log("The person name is not defined.");
} else {
  console.log(personName);
}
```

- Here, the `personName` variable is **implicitly undefined**, because it is declared but not initialized. If the variable were assigned a value, it would no longer be `undefined`.

---

### **Assignability in TypeScript**

TypeScript allows `null` and `undefined` to be assigned to variables, but there are some rules that control how and where they can be used.

#### **Strict Null Checking**

TypeScript has a strict null checking option (`--strictNullChecks`), which changes how `null` and `undefined` behave in the type system. With this option enabled, `null` and `undefined` are **not assignable** to other types unless explicitly specified.

##### **Without `--strictNullChecks`** (Default Behavior):

```typescript
let myString: string;
myString = null;        // OK
myString = undefined;   // OK
```

- By default, TypeScript allows assigning `null` or `undefined` to a variable of type `string`.

##### **With `--strictNullChecks`** (Recommended for Type Safety):

```typescript
let myString: string;
myString = null;        // Error: Type 'null' is not assignable to type 'string'.
myString = undefined;   // Error: Type 'undefined' is not assignable to type 'string'.
```

- When `--strictNullChecks` is enabled, TypeScript treats `null` and `undefined` as distinct types that cannot be assigned to a `string` unless the type is explicitly made to accept `null` or `undefined` (e.g., `string | null` or `string | undefined`).

---

### **Function Parameters and Return Types**

Both `null` and `undefined` can also play roles in function parameters and return types.

#### **Function with `undefined` as a Parameter**

```typescript
function greet(name: string | undefined): string {
  if (name === undefined) {
    return "Hello, Guest!";
  }
  return `Hello, ${name}!`;
}

console.log(greet("Alice"));    // "Hello, Alice!"
console.log(greet(undefined)); // "Hello, Guest!"
```

- In this case, the `greet` function accepts `name` as either a `string` or `undefined`. The function checks for `undefined` to handle cases where the `name` parameter is not provided.

#### **Function with `null` as a Parameter**

```typescript
function setAge(age: number | null): string {
  if (age === null) {
    return "Age is not provided";
  }
  return `Age is ${age}`;
}

console.log(setAge(30));    // "Age is 30"
console.log(setAge(null));  // "Age is not provided"
```

- In this example, `setAge` can accept a `null` value to indicate that the age is intentionally not provided.

---

### **Equality and Comparison**

In JavaScript (and TypeScript), `null` and `undefined` are loosely equal to each other (`==`), but **not strictly equal** (`===`).

#### **Loose Equality (`==`)**

```typescript
console.log(null == undefined); // true
```

- `null` and `undefined` are considered equal with loose equality.

#### **Strict Equality (`===`)**

```typescript
console.log(null === undefined); // false
```

- `null` and `undefined` are **not strictly equal** because they are different types (`null` is an object and `undefined` is a primitive).

---

### **Best Practices**

1. **Use `undefined` for Uninitialized Values**: It's best to use `undefined` for variables that have not been assigned a value, such as function parameters that are optional or fields that are not yet initialized.
2. **Use `null` for Explicit Nullification**: Use `null` when you explicitly want to represent the intentional absence of a value, like when resetting an object or variable.
3. **Enable `--strictNullChecks`**: Enabling this compiler option helps make your code safer by preventing `null` and `undefined` from being assigned to variables unless you explicitly allow it.

---

### **Summary**

- **`null`**: Represents the intentional absence of any object value. It is an object type and used when you want to explicitly indicate that a variable or object is absent.
- **`undefined`**: Represents a variable that has been declared but not assigned a value. It is the default value for uninitialized variables and missing function arguments.
- **Strict Null Checking**: When `--strictNullChecks` is enabled, `null` and `undefined` are treated as distinct types and cannot be assigned to other types unless explicitly allowed.

Understanding the difference between `null` and `undefined` is crucial for writing clear, predictable code in TypeScript.
