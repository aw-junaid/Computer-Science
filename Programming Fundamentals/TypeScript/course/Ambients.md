### TypeScript - Ambient Declarations

Ambient declarations in TypeScript allow you to describe the shape of code that exists elsewhere, such as third-party libraries or global variables, without defining its implementation. These declarations enable the TypeScript compiler to recognize the types and structures of external code.

Ambient declarations are primarily used in scenarios where TypeScript interacts with non-TypeScript codebases, such as JavaScript libraries or APIs.

---

### **1. Ambient Declaration Syntax**

Ambient declarations are introduced using the `declare` keyword. The `declare` keyword tells TypeScript that the implementation exists elsewhere, and you are only providing type information.

#### **Basic Syntax:**
```typescript
declare <declaration>;
```

---

### **2. Declaring Variables, Functions, and Classes**

#### **a. Variables**
Declare global variables that exist in the runtime environment.

**Example:**
```typescript
declare const API_URL: string;

console.log(API_URL); // TypeScript knows API_URL is a string
```

---

#### **b. Functions**
Declare functions that are defined in the global scope.

**Example:**
```typescript
declare function fetchData(endpoint: string): Promise<any>;

fetchData("/api/data").then((data) => console.log(data));
```

---

#### **c. Classes**
Declare global classes without defining their implementation.

**Example:**
```typescript
declare class Person {
  constructor(name: string, age: number);
  name: string;
  age: number;
  greet(): void;
}

const john = new Person("John", 30);
john.greet();
```

---

### **3. Ambient Modules**

When working with external libraries, ambient modules describe their structure. These are used when TypeScript cannot locate type definitions.

#### **Example:**
```typescript
declare module "my-library" {
  export function myFunction(param: string): void;
}
```

**Usage:**
```typescript
import { myFunction } from "my-library";

myFunction("Hello!");
```

---

### **4. Ambient Namespaces**

Ambient namespaces describe globally available objects and their members, often used for libraries like `jQuery` or the DOM.

**Example:**
```typescript
declare namespace jQuery {
  function ajax(url: string, settings?: any): void;
}
```

**Usage:**
```typescript
jQuery.ajax("/api/data");
```

---

### **5. Adding Types for Existing JavaScript Libraries**

#### **a. Using `declare` with Global Libraries**
If you are using a JavaScript library like `jQuery`, you can provide type declarations:

```typescript
declare var $: (selector: string) => any;

$("#app").css("color", "red");
```

#### **b. Using DefinitelyTyped**
Most popular libraries already have type definitions available in the [DefinitelyTyped](https://github.com/DefinitelyTyped/DefinitelyTyped) repository. These can be installed via `npm`.

**Example:**
```bash
npm install --save-dev @types/jquery
```

This eliminates the need to manually write `declare` statements.

---

### **6. Ambient Files (`.d.ts`)**

Ambient declarations are typically stored in **declaration files** with the `.d.ts` extension. These files contain only type declarations and no actual implementations.

#### **Example:**

**file.d.ts**
```typescript
declare const API_KEY: string;
declare function fetchData(endpoint: string): Promise<any>;
```

**main.ts**
```typescript
console.log(API_KEY); // Recognized as a string
fetchData("/endpoint").then((data) => console.log(data));
```

- `.d.ts` files are automatically included by the TypeScript compiler if they are in the project.

---

### **7. Ambient Declaration Use Cases**

1. **Global Variables and Functions**:
   - Declaring runtime globals provided by the environment or external libraries.
   - Example: `declare const window: Window;`

2. **JavaScript Libraries**:
   - Adding type information for JavaScript libraries that do not ship with their own type definitions.

3. **Backward Compatibility**:
   - Supporting legacy codebases or applications where TypeScript interacts with plain JavaScript.

---

### **8. Key Points**

- **`declare`**: Used for declaring types that exist elsewhere.
- **No Implementation**: Ambient declarations only provide type information, not actual implementation.
- **Scoped Declarations**: Place declarations inside `declare module`, `declare namespace`, or `.d.ts` files depending on the context.

---

### **9. Examples of Common Scenarios**

#### **a. Declaring a Global Variable**
```typescript
declare const VERSION: string;

console.log(`App Version: ${VERSION}`);
```

#### **b. Declaring a Module**
```typescript
declare module "custom-module" {
  export const name: string;
  export function greet(): void;
}
```

#### **c. Declaring DOM Globals**
```typescript
declare var document: Document;

const element = document.getElementById("app");
```

---

### **10. Summary**

Ambient declarations are essential for integrating TypeScript with non-TypeScript codebases, external libraries, or global environments. By defining the shape of external entities using the `declare` keyword, you can enable TypeScript to provide type-checking and IntelliSense for otherwise untyped code. 

For libraries with existing type definitions, prefer installing them via `@types` packages instead of writing manual declarations.
