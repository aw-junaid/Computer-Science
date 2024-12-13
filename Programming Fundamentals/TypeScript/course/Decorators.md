### TypeScript - Decorators

Decorators are a powerful feature in TypeScript that allow you to modify or annotate classes, methods, accessors, properties, or parameters at runtime. They are a form of metadata that can be applied to various elements in your code to extend their functionality.

Decorators are widely used in frameworks like Angular to define metadata for components, services, and modules.

---

### **1. Prerequisites**

To use decorators in TypeScript, enable the `experimentalDecorators` compiler option in your `tsconfig.json`:

```json
{
  "compilerOptions": {
    "experimentalDecorators": true"
  }
}
```

---

### **2. Types of Decorators**

There are five main types of decorators in TypeScript:

1. **Class Decorators**
2. **Method Decorators**
3. **Accessor Decorators**
4. **Property Decorators**
5. **Parameter Decorators**

---

### **3. Class Decorators**

A class decorator is applied to the constructor of a class. It can modify or replace the class definition.

#### **Example:**
```typescript
function Logger(constructor: Function) {
  console.log(`Class ${constructor.name} is being created.`);
}

@Logger
class MyClass {
  constructor() {
    console.log("MyClass instance created.");
  }
}
```

**Output:**
```
Class MyClass is being created.
MyClass instance created.
```

- The `@Logger` decorator logs a message when the class is defined.

---

### **4. Method Decorators**

A method decorator is applied to a class method. It can modify the behavior of the method.

#### **Example:**
```typescript
function Log(target: Object, propertyKey: string, descriptor: PropertyDescriptor) {
  const originalMethod = descriptor.value;

  descriptor.value = function (...args: any[]) {
    console.log(`Method ${propertyKey} called with arguments: ${args}`);
    return originalMethod.apply(this, args);
  };
}

class Calculator {
  @Log
  add(a: number, b: number): number {
    return a + b;
  }
}

const calc = new Calculator();
console.log(calc.add(5, 3)); // Logs the method call and its arguments
```

---

### **5. Accessor Decorators**

An accessor decorator is applied to a class's getter or setter methods.

#### **Example:**
```typescript
function Capitalize(target: Object, propertyKey: string, descriptor: PropertyDescriptor) {
  const originalGetter = descriptor.get;

  descriptor.get = function () {
    const result = originalGetter?.apply(this);
    return typeof result === "string" ? result.toUpperCase() : result;
  };
}

class User {
  private _name: string;

  constructor(name: string) {
    this._name = name;
  }

  @Capitalize
  get name(): string {
    return this._name;
  }
}

const user = new User("john");
console.log(user.name); // Output: JOHN
```

---

### **6. Property Decorators**

A property decorator is applied to a class property. It can be used to observe or modify the property.

#### **Example:**
```typescript
function DefaultValue(value: any) {
  return function (target: Object, propertyKey: string) {
    let _value = value;

    Object.defineProperty(target, propertyKey, {
      get: () => _value,
      set: (newValue) => {
        console.log(`Setting ${propertyKey} to ${newValue}`);
        _value = newValue;
      },
    });
  };
}

class Product {
  @DefaultValue("Unnamed")
  name: string;
}

const product = new Product();
console.log(product.name); // Output: Unnamed
product.name = "Laptop"; // Logs: Setting name to Laptop
```

---

### **7. Parameter Decorators**

A parameter decorator is applied to the parameters of a class method or constructor.

#### **Example:**
```typescript
function LogParam(target: Object, propertyKey: string, parameterIndex: number) {
  console.log(`Parameter at index ${parameterIndex} in method ${propertyKey} is being decorated.`);
}

class Demo {
  greet(@LogParam message: string) {
    console.log(message);
  }
}

const demo = new Demo();
demo.greet("Hello!"); // Logs parameter decoration details
```

---

### **8. Combining Multiple Decorators**

You can stack multiple decorators on a single element. They are executed in reverse order (bottom to top).

#### **Example:**
```typescript
function First() {
  console.log("First decorator");
  return function (target: any, propertyKey?: string, descriptor?: PropertyDescriptor) {};
}

function Second() {
  console.log("Second decorator");
  return function (target: any, propertyKey?: string, descriptor?: PropertyDescriptor) {};
}

class Example {
  @First()
  @Second()
  method() {
    console.log("Method called");
  }
}

const example = new Example();
example.method();
```

**Output:**
```
Second decorator
First decorator
Method called
```

---

### **9. Practical Use Cases**

1. **Logging**: Automatically log method calls or property access.
2. **Validation**: Add validation rules to class properties or method parameters.
3. **Metadata**: Annotate classes or methods with additional metadata (e.g., for dependency injection).
4. **Frameworks**: Used in Angular, NestJS, and others to define components, controllers, or services.

---

### **10. Summary**

Decorators in TypeScript provide a clean and reusable way to modify or annotate code elements. They are particularly useful for adding metadata and extending functionality without altering the core implementation. While decorators are still experimental, they have become a staple in TypeScript for building scalable and organized applications.
