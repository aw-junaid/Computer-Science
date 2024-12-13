### TypeScript - Namespaces

**Namespaces** in TypeScript are a way to organize and group related code together under a single name. They are primarily used to avoid naming conflicts in large codebases by providing a logical grouping of variables, functions, classes, and interfaces.

Namespaces are ideal for applications that do not use a module system like ES modules, especially when multiple scripts are combined into a single global scope.

---

### **1. Defining a Namespace**

Namespaces are declared using the `namespace` keyword. All code within a namespace is encapsulated and accessed using the namespace's name as a prefix.

#### **Basic Syntax:**
```typescript
namespace NamespaceName {
  // Code here
}
```

---

### **2. Example: Simple Namespace**

```typescript
namespace MathOperations {
  export function add(x: number, y: number): number {
    return x + y;
  }

  export function subtract(x: number, y: number): number {
    return x - y;
  }
}

console.log(MathOperations.add(10, 5)); // Output: 15
console.log(MathOperations.subtract(10, 5)); // Output: 5
```

- **Key Points:**
  - Use the `export` keyword to expose functions, classes, or variables outside the namespace.
  - Without `export`, members are private to the namespace and cannot be accessed externally.

---

### **3. Nested Namespaces**

You can create nested namespaces to group related functionalities hierarchically.

#### **Example:**
```typescript
namespace Geometry {
  export namespace Circle {
    const PI = 3.14;

    export function area(radius: number): number {
      return PI * radius * radius;
    }
  }

  export namespace Rectangle {
    export function area(length: number, width: number): number {
      return length * width;
    }
  }
}

console.log(Geometry.Circle.area(5)); // Output: 78.5
console.log(Geometry.Rectangle.area(10, 5)); // Output: 50
```

- Access nested namespaces using dot notation (e.g., `Geometry.Circle.area`).

---

### **4. Namespace Aliases**

Long namespaces can be simplified using aliases.

#### **Example:**
```typescript
namespace Utilities {
  export function greet(name: string): string {
    return `Hello, ${name}!`;
  }
}

import U = Utilities;

console.log(U.greet("TypeScript")); // Output: Hello, TypeScript!
```

- **`import` keyword**: Creates an alias for a namespace to reduce verbosity.

---

### **5. Merging Namespaces**

TypeScript allows merging namespaces with classes, functions, or enums that share the same name. This is useful for augmenting an existing namespace.

#### **Example: Merging a Namespace with a Class**
```typescript
class Employee {
  constructor(public name: string, public age: number) {}
}

namespace Employee {
  export function details(emp: Employee): string {
    return `Name: ${emp.name}, Age: ${emp.age}`;
  }
}

const emp = new Employee("John", 30);
console.log(Employee.details(emp)); // Output: Name: John, Age: 30
```

- The `Employee` class and `Employee` namespace coexist and complement each other.

---

### **6. Namespaces vs. Modules**

Namespaces and modules serve similar purposes but are used in different contexts:

| **Aspect**              | **Namespaces**                                | **Modules**                               |
|-------------------------|-----------------------------------------------|------------------------------------------|
| **Definition**          | Use the `namespace` keyword.                 | Use ES `import`/`export` statements.     |
| **Scope**               | Used to organize code within a single file.  | Used for code that spans multiple files. |
| **Dependencies**        | No dependency resolution is required.         | Requires module loaders or bundlers.    |
| **Use Case**            | Best for non-modular codebases.               | Preferred for modern modular projects.   |

#### **Namespace Example:**
```typescript
namespace ExampleNamespace {
  export const value = 42;
}
console.log(ExampleNamespace.value); // Output: 42
```

#### **Module Example:**
```typescript
// utils.ts
export const value = 42;

// main.ts
import { value } from "./utils";
console.log(value); // Output: 42
```

---

### **7. Practical Use of Namespaces**

Namespaces are commonly used in:
1. Legacy TypeScript projects.
2. Combining scripts in a non-modular environment (e.g., `<script>` tags).
3. Defining large libraries or frameworks with a single global object.

---

### **8. Advantages of Namespaces**
- Avoids global scope pollution.
- Logical grouping of related functionalities.
- Reduces name collisions in larger applications.

---

### **9. Disadvantages of Namespaces**
- Less popular in modern TypeScript due to module-based systems.
- Can become verbose in deeply nested namespaces.
- Requires manual script management compared to module loaders.

---

### **10. Conclusion**

Namespaces in TypeScript provide a way to organize and encapsulate code within a single global scope, making it easier to manage dependencies in non-module environments. While they are still useful in specific scenarios, modules are now the preferred approach for modern, scalable TypeScript projects. 

When to use namespaces:
- In non-module environments.
- To create logically grouped, self-contained code.
