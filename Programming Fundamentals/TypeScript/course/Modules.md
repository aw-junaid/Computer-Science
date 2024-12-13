### TypeScript - Modules

Modules in TypeScript are a way to organize code into separate files and share functionality between them. They are based on the **ES Module** system and provide features like importing and exporting declarations. Using modules improves code maintainability, reusability, and encapsulation.

---

### **1. What Are Modules?**
Modules are files containing code that is executed in its own scope, not in the global scope. You can export classes, functions, variables, and objects from one file and import them into another file.

#### **Key Characteristics:**
- Modules are **static**; their structure is determined at compile time.
- Each file in TypeScript is treated as a module if it contains at least one `import` or `export` statement.

---

### **2. Exporting from a Module**

#### **Named Exports**
You can explicitly export multiple members from a module using the `export` keyword.

**Example:**
```typescript
// mathUtils.ts
export const PI = 3.14;

export function add(x: number, y: number): number {
  return x + y;
}

export function subtract(x: number, y: number): number {
  return x - y;
}
```

#### **Importing Named Exports**
```typescript
// main.ts
import { PI, add, subtract } from "./mathUtils";

console.log(PI); // Output: 3.14
console.log(add(10, 5)); // Output: 15
console.log(subtract(10, 5)); // Output: 5
```

#### **Renaming Exports**
You can rename imports for better clarity.
```typescript
import { add as addition } from "./mathUtils";

console.log(addition(10, 5)); // Output: 15
```

---

#### **Default Exports**
A module can export a single **default export**, making it the primary value exported.

**Example:**
```typescript
// logger.ts
export default function log(message: string): void {
  console.log(message);
}
```

#### **Importing Default Exports**
```typescript
// main.ts
import log from "./logger";

log("Hello, TypeScript!"); // Output: Hello, TypeScript!
```

- You can name the imported default export anything because it is the only exported value.

---

#### **Export All (`export *`)**
You can re-export everything from another module.

**Example:**
```typescript
// constants.ts
export const MAX_USERS = 100;
export const APP_NAME = "MyApp";

// index.ts
export * from "./constants";
```

#### **Importing Re-exports**
```typescript
import { MAX_USERS, APP_NAME } from "./index";

console.log(MAX_USERS, APP_NAME);
```

---

#### **Combining Default and Named Exports**
You can mix default and named exports in the same file.

**Example:**
```typescript
// math.ts
export default function multiply(x: number, y: number): number {
  return x * y;
}

export const divide = (x: number, y: number): number => x / y;
```

**Importing Both:**
```typescript
import multiply, { divide } from "./math";

console.log(multiply(2, 3)); // Output: 6
console.log(divide(6, 3)); // Output: 2
```

---

### **3. Module Resolution**

TypeScript uses a **module resolution strategy** to locate imported modules. There are two main strategies:

#### **a. Classic**
- Looks for the module only in the files specified in the `include` option of `tsconfig.json`.

#### **b. Node**
- Mimics Node.js module resolution.
- Searches in `node_modules` directories and resolves based on the `main` field in `package.json`.

---

### **4. Configuring Modules in `tsconfig.json`**

You can specify the module system TypeScript should use in `tsconfig.json`:

#### **Common Properties:**
- `module`: Specifies the module target (`"ESNext"`, `"CommonJS"`, `"AMD"`, etc.).
- `moduleResolution`: Controls how modules are resolved (`"node"` or `"classic"`).

**Example:**
```json
{
  "compilerOptions": {
    "module": "ESNext",
    "moduleResolution": "node"
  }
}
```

---

### **5. Dynamic Imports**

You can use dynamic `import()` to load modules at runtime. It returns a promise, allowing for conditional or lazy loading.

**Example:**
```typescript
if (condition) {
  import("./mathUtils").then((math) => {
    console.log(math.add(2, 3));
  });
}
```

---

### **6. Advantages of Modules**
- **Encapsulation**: Avoids polluting the global namespace.
- **Reusability**: Share code between different files and projects.
- **Scalability**: Manage large codebases effectively.
- **Compatibility**: Works seamlessly with modern JavaScript tools like Webpack or ESBuild.

---

### **7. Modules vs. Namespaces**

| **Aspect**           | **Modules**                                      | **Namespaces**                                |
|-----------------------|-------------------------------------------------|---------------------------------------------|
| **Definition**        | Based on the ES Module system.                  | A TypeScript-specific feature for grouping code. |
| **Scope**             | File-level encapsulation.                       | Global or local within the same file.        |
| **Usage**             | Preferred in modern TypeScript projects.        | Useful in legacy or non-module environments. |
| **Dependencies**      | Uses `import` and `export`.                     | Relies on `/// <reference path="..." />`.    |

---

### **8. Summary**

Modules are the backbone of modern TypeScript projects, enabling organized, scalable, and maintainable codebases. By leveraging `import` and `export`, you can create modular and reusable components while avoiding global scope pollution. Always prefer modules over namespaces in modern TypeScript projects, especially when working with bundlers like Webpack or in a Node.js environment.
